#include "geo.h"

#define HOLE 1
#define INTMAX ((unsigned)(-1) >> 1)

struct fmpoint
{
	int inset;
	int p;
	int x;
	int y;
	int bucket_id;
	int queue_id;
	int time;
};

struct fifo
{
	int valid;
	int id;
};

struct qlnode
{
	int num;
	int capacity;
	fifo* queue;
};

enum stype { KNOWN, UNKNOWN, TRIAL };

class bucket
{
public:
	qlnode* queueList;				//queue list pointer, pointed to the queue pointer table, each queueList[i] points to the 
	int quants;
	int min_bucket;
	int numPositive;
	int increment;

	bucket()
	{
		queueList = NULL;
		quants = 0;
		min_bucket = 0;
		numPositive = 0;
		increment = 100;
	}
	bucket(int level, int qlength, int inc)
	{
		queueList = new qlnode[level];
		for (int i = 0; i<level; ++i)
		{
			queueList[i].num = 0;
			queueList[i].capacity = qlength;
			queueList[i].queue = new fifo[qlength];
		}
		quants = level;
		min_bucket = 0;
		numPositive = 0;
		increment = inc;
	}
	~bucket()
	{
		for (int i = 0; i<quants; ++i)
			delete queueList[i].queue;
		delete queueList;
	}

	void push(fmpoint* point_set, int p, int new_time, int i, int j)
	{
		if (point_set[p].inset == TRIAL)		//update
		{
			if (new_time<point_set[p].time)
			{
				//delete old record
				if (queueList[point_set[p].bucket_id].queue[point_set[p].queue_id].id == p)
					queueList[point_set[p].bucket_id].queue[point_set[p].queue_id].valid = 0;
				//add new record
				point_set[p].bucket_id = new_time%quants;
				if (queueList[point_set[p].bucket_id].num == 0)								//empty bucket
					++numPositive;
				if (queueList[point_set[p].bucket_id].num >= queueList[point_set[p].bucket_id].capacity)						//memory overflow
				{
					fifo* tmp = new fifo[queueList[point_set[p].bucket_id].num + increment];
					queueList[point_set[p].bucket_id].capacity = queueList[point_set[p].bucket_id].num + increment;
					memcpy(tmp, queueList[point_set[p].bucket_id].queue, sizeof(fifo)*queueList[point_set[p].bucket_id].num);
					delete queueList[point_set[p].bucket_id].queue;
					queueList[point_set[p].bucket_id].queue = tmp;
				}
				point_set[p].queue_id = queueList[point_set[p].bucket_id].num;
				queueList[point_set[p].bucket_id].queue[point_set[p].queue_id].valid = 1;
				queueList[point_set[p].bucket_id].queue[point_set[p].queue_id].id = p;
				++queueList[point_set[p].bucket_id].num;
				point_set[p].time = new_time;
			}
		}
		else								//add a new trial
		{
			point_set[p].inset = TRIAL;
			point_set[p].bucket_id = new_time%quants;
			if (queueList[point_set[p].bucket_id].num == 0)					//empty bucket
				++numPositive;
			if (queueList[point_set[p].bucket_id].num >= queueList[point_set[p].bucket_id].capacity)						//memory overflow
			{
				fifo* tmp = new fifo[queueList[point_set[p].bucket_id].num + increment];
				queueList[point_set[p].bucket_id].capacity = queueList[point_set[p].bucket_id].num + increment;
				memcpy(tmp, queueList[point_set[p].bucket_id].queue, sizeof(fifo)*queueList[point_set[p].bucket_id].num);
				delete queueList[point_set[p].bucket_id].queue;
				queueList[point_set[p].bucket_id].queue = tmp;
			}
			point_set[p].queue_id = queueList[point_set[p].bucket_id].num;
			queueList[point_set[p].bucket_id].queue[point_set[p].queue_id].valid = 1;
			queueList[point_set[p].bucket_id].queue[point_set[p].queue_id].id = p;
			++queueList[point_set[p].bucket_id].num;
			point_set[p].time = new_time;
		}
	}

	void copyTo(Mat& timeMat, fmpoint* point_set, int num)
	{

		int max_time = 0;
		for (int i = 0; i<num; ++i)
		{
			if (point_set[i].inset == KNOWN&&point_set[i].time>max_time)
				max_time = point_set[i].time;
		}

		for (int i = 0; i<num; ++i)
		{
			if (point_set[i].inset == KNOWN)
			{
				if (max_time == 0)
					timeMat.data[i] = 0;
				else
					timeMat.data[i] = 255 * point_set[i].time / max_time;
			}
			else
				timeMat.data[i] = 255;
		}
	}

protected:
private:

};

inline int travel(int dp, int dq)
{
	// 	if (dp<HOLE&&dq>=HOLE)
	// 		return dq;
	// 	else if (dp<HOLE&&dq<HOLE)
	// 		return 0;
	// 	else if (dp>=HOLE&&dq<HOLE)
	// 		return 0;
	// 	else
	return dp - dq>0 ? dp - dq : dq - dp;
}


void seek_adjacent(bucket& snbucket, fmpoint* point_set, uchar* dm, int p, int rows, int cols)
{
#define TRAVEL(p,q) int(dm[p])-dm[q]>0?int(dm[p])-dm[q]:int(dm[q])-dm[p]
	if (point_set[p].x>0 && point_set[p].y>0 && point_set[p - cols - 1].inset != KNOWN)											//upper left neighbor
		snbucket.push(point_set, p - cols - 1, point_set[p].time + 1.4142*travel(dm[p], dm[p - cols - 1]), point_set[p].x - 1, point_set[p].y - 1);
	if (point_set[p].x>0 && point_set[p - cols].inset != KNOWN)																//upper neighbor
		snbucket.push(point_set, p - cols, point_set[p].time + travel(dm[p], dm[p - cols]), point_set[p].x - 1, point_set[p].y);
	if (point_set[p].x>0 && point_set[p].y<cols - 1 && point_set[p - cols + 1].inset != KNOWN)										//upper right neighbor
		snbucket.push(point_set, p - cols + 1, point_set[p].time + 1.4142*travel(dm[p], dm[p - cols + 1]), point_set[p].x - 1, point_set[p].y + 1);
	if (point_set[p].y>0 && point_set[p - 1].inset != KNOWN)															//left neighbor
		snbucket.push(point_set, p - 1, point_set[p].time + travel(dm[p], dm[p - 1]), point_set[p].x, point_set[p].y - 1);
	if (point_set[p].y<cols - 1 && point_set[p + 1].inset != KNOWN)																//right neighbor
		snbucket.push(point_set, p + 1, point_set[p].time + travel(dm[p], dm[p + 1]), point_set[p].x, point_set[p].y + 1);
	if (point_set[p].x<rows - 1 && point_set[p].y>0 && point_set[p + cols - 1].inset != KNOWN)										//lower left neighbor
		snbucket.push(point_set, p + cols - 1, point_set[p].time + 1.4142*travel(dm[p], dm[p + cols - 1]), point_set[p].x + 1, point_set[p].y - 1);
	if (point_set[p].x<rows - 1 && point_set[p + cols].inset != KNOWN)															//lower neighbor
		snbucket.push(point_set, p + cols, point_set[p].time + travel(dm[p], dm[p + cols]), point_set[p].x + 1, point_set[p].y);
	if (point_set[p].x<rows - 1 && point_set[p].y<cols - 1 && point_set[p + cols + 1].inset != KNOWN)									//lower right neighbor
		snbucket.push(point_set, p + cols + 1, point_set[p].time + 1.4142*travel(dm[p], dm[p + cols + 1]), point_set[p].x + 1, point_set[p].y + 1);
}

void fast_marching(Mat& img, Mat& fmseeds, Mat& geos)
{
	Mat inimg = img.clone();
	Mat inseeds = fmseeds.clone();

	int tnum = inimg.rows*inimg.cols;
	int numK = 0, numT = 0;
	fmpoint* point_set = new fmpoint[tnum];
	memset(point_set, 0xff, sizeof(fmpoint)*tnum);
	bucket nbucket = bucket(256, 500, 500);

	int p = 0;
	for (int i = 0; i<inimg.rows; ++i)
		for (int j = 0; j<inimg.cols; ++j)
		{
			if (inseeds.data[p])					//this is a seed point
			{
				point_set[p].inset = KNOWN;
				point_set[p].p = p;
				point_set[p].x = i;
				point_set[p].y = j;
				point_set[p].time = 0;

				++numK;
			}
			else
			{
				if (point_set[p].inset != TRIAL)
				{
					point_set[p].inset = UNKNOWN;
					point_set[p].p = p;
					point_set[p].x = i;
					point_set[p].y = j;
					point_set[p].time = INTMAX;
				}
			}
			++p;
		}

	p = 0;
	for (int i = 0; i<inimg.rows; ++i)
		for (int j = 0; j<inimg.cols; ++j)
		{
			if (inseeds.data[p])					//this is a seed point
				seek_adjacent(nbucket, point_set, inimg.data, p, inseeds.rows, inseeds.cols);
			++p;
		}

	while (nbucket.numPositive>0)
	{
		int i = 0;
		if (nbucket.queueList[nbucket.min_bucket].num)
			--nbucket.numPositive;
		while (i<nbucket.queueList[nbucket.min_bucket].num)
		{
			if (nbucket.queueList[nbucket.min_bucket].queue[i].valid)			//a valid element
			{
				point_set[nbucket.queueList[nbucket.min_bucket].queue[i].id].inset = KNOWN;
				seek_adjacent(nbucket, point_set, inimg.data, nbucket.queueList[nbucket.min_bucket].queue[i].id, inseeds.rows, inseeds.cols);
			}
			++i;
		}
		nbucket.queueList[nbucket.min_bucket].num = 0;
		++nbucket.min_bucket;
		nbucket.min_bucket = nbucket.min_bucket % 256;


		// 		Mat showMat = Mat(inimg.rows, inimg.cols, CV_8UC1);
		// 		nbucket.copyTo(showMat, point_set, img.cols*img.rows);
		// 		imshow("time",showMat);
		// 		waitKey(70);
	}
	nbucket.copyTo(geos, point_set, inimg.cols*inimg.rows);
	//	imwrite("l.png",showMat);
	// 	imshow("time", geos);
	// 	waitKey(0);

	delete point_set;
	inimg.release();
	inseeds.release();
}
