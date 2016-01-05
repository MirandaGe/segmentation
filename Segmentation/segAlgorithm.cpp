#include "segAlgorithm.h"

const int K = 10;
const int step = 2;
const int lambda = 5;

double *exp_table = NULL;
int scale = 100000;
int midColor = 128;
double alpha = 0.8;
double beta = 0.5;
double theta = 0.6;//RGB

segAlgorithm::segAlgorithm() {

}

segAlgorithm::~segAlgorithm() {
	delete[] exp_table;
	exp_table = NULL;
}

void segAlgorithm::setSeedImage(Mat &img) {
	seedImage = Mat(img.size(), CV_8UC1);
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			int p = i*img.cols + j;
			seedImage.data[p] = img.data[3 * p];
		}
	}
}

void segAlgorithm::setParaForMethod() {
	if (methodType == "mgc") {
		scale = 50000;
		theta = 1;
		alpha = 0;
		beta = 0;
	}
	else if (methodType == "gdd") {
		scale = INT_MAX;
		theta = 0;
		alpha = 1;
		beta = 1;
	}
	else if (methodType == "gg") {
		scale = INT_MAX;
		theta = 0.6;
		alpha = 0.8;
		beta = 0.5;
	}
	else if (methodType == "hgg") {
		scale = 50000;
		theta = 0.6;
		alpha = 0.8;
		beta = 0.5;
	}
	else if (methodType == "rgbd") {
		scale = INT_MAX;
		alpha = 0.5;
		beta = 0.5;
		theta = 0.5;
	}/*
	else if (methodType == "gc") {
		alpha = 0;
		beta = 0;
		lambda = 5;
		theta = 1;
	}*/
}

/*-------------------------- hist of RGB color space ----------------------------*/
void segAlgorithm::hist(Mat& img, Mat& seeds, int* fgModel, int* bgModel) {
	memset(fgModel, 0, sizeof(int)*K*K*K);
	memset(bgModel, 0, sizeof(int)*K*K*K);

	for (int i = 0; i<img.rows; ++i)
		for (int j = 0; j<img.cols; ++j)
		{
			int p = i*img.cols + j;
			if (seeds.data[p] == 255)	//labeled as object
			{
				int x = K*img.data[3 * p] / 256 * K*K + K*img.data[3 * p + 1] / 256 * K + K*img.data[3 * p + 2] / 256;//index
				++fgModel[x];
			}
			else if (seeds.data[p] == 0)		//labeled as background
			{
				int x = K*img.data[3 * p] / 256 * K*K + K*img.data[3 * p + 1] / 256 * K + K*img.data[3 * p + 2] / 256;//index
				++bgModel[x];
			}
		}
}

void segAlgorithm::depHist(Mat &dep, Mat &seed, int *fgModel, int *bgModel) {
	memset(fgModel, 0, sizeof(int)*K);
	memset(bgModel, 0, sizeof(int)*K);

	for (int i = 0; i < dep.rows; ++i) {
		for (int j = 0; j < dep.cols; ++j) {
			int p = i*dep.cols + j;
			if (seed.data[p] == 255) {
				int x = K*dep.data[p] / 256;
				++fgModel[x];
			}
			else if (seed.data[p] == 0) {
				int x = K*dep.data[p] / 256;
				++bgModel[x];
			}
		}
	}
}

/*-------------------------- initialize exp table ----------------------------*/
void segAlgorithm::ini_exp_table(int num) {
	/*------------------------- pre-process -----------------------------*/
	if (exp_table == NULL) {
		exp_table = new double[num];
		for (int i = 0; i<num; ++i)
			exp_table[i] = 35 * exp(-0.0075*i);
	}
}

/*-------------------------- split seed to foreground seed and background seed ----------------------------*/
void segAlgorithm::splitSeed(Mat &seed, Mat &fseed, Mat &bseed) {
	fseed = Mat(seed.size(), CV_8UC1);
	bseed = Mat(seed.size(), CV_8UC1);

	for (int i = 0; i < seed.rows * seed.cols; ++i) {
		fseed.data[i] = (seed.data[i] == 255) ? 255 : 0;
		bseed.data[i] = (seed.data[i] == 0) ? 255 : 0;
	}

	//imshow("fseed", fseed);
	//imshow("bseed", bseed);
	//waitKey(0);
}

/*------------------------- graphcut on the heighest level -----------------------------*/
void segAlgorithm::heighestGraphcut(Mat& img, Mat &dep, Mat& seed, Mat &seg) {
	int* fgModel = new int[K*K*K];
	int* bgModel = new int[K*K*K];
	if (bgModel == NULL) {
		//cout << "new failed" << endl;
	}

	//imshow("seed", seed);
	//waitKey(0);

	Mat fseed, bseed;
	Mat bgeos = Mat(seed.size(), CV_8UC1);
	Mat fgeos = Mat(seed.size(), CV_8UC1);

	hist(img, seed, fgModel, bgModel);

	if (methodType != "mgc") {
		splitSeed(seed, fseed, bseed);
		fast_marching(dep, fseed, fgeos);
		fast_marching(dep, bseed, bgeos);
	}
	
	int numNodes = img.rows*img.cols;
	int numEdges = 4 * numNodes - img.rows - img.cols;
	GraphType *graph = new GraphType(numNodes, numEdges);
	graph->add_node(numNodes);

	for (int i = 0; i<img.rows; ++i) {
		for (int j = 0; j<img.cols; ++j)
		{
			int p = i*img.cols + j;
			//t-link
			if (seed.data[p] == 255)		//object
			{
				graph->add_tweights(p, 10000, 0);//add_tweights(node_id i, tcaptype cap_source, tcaptype cap_sink)
			}
			else if (seed.data[p] == 0)		//background
			{
				graph->add_tweights(p, 0, 10000);
			}
			else
			{
				//int K = 10;
				int x = K*img.data[3 * p] / 256 * K*K + K*img.data[3 * p + 1] / 256 * K + K*img.data[3 * p + 2] / 256;
				int csum = fgModel[x] + bgModel[x];
				int dsum = fgeos.data[p] + bgeos.data[p];
				if (!csum && !dsum)
					graph->add_tweights(p, 50, 50);
				else if (!dsum){
					graph->add_tweights(p, 25 + lambda*theta*fgModel[x] / csum, 25 + lambda*theta*bgModel[x] / csum);
				}
				else if (!csum) {
					graph->add_tweights(p, 25 + lambda*alpha*bgeos.data[p] / dsum, 25 + lambda*alpha*fgeos.data[p] / dsum);
				}
				else
					graph->add_tweights(p, lambda*(theta*fgModel[x] / csum + alpha*bgeos.data[p] / dsum), lambda*(theta*bgModel[x] / csum + alpha*fgeos.data[p] / dsum));
			}

			//n-link
			if (!(j >= img.cols - 1))	//not last column
			{
				int index = theta*EuclideanDis(img.data[3 * p] - img.data[3 * p + 3], img.data[3 * p + 1] - img.data[3 * p + 4], img.data[3 * p + 2] - img.data[3 * p + 5]) + beta*abs(dep.data[p] - dep.data[p + 1]);
				if (index <= 500)
					graph->add_edge(p, p + 1, exp_table[index], exp_table[index]);
			}
			if (!(i >= img.rows - 1))	//not last row
			{
				int index = theta*EuclideanDis(img.data[3 * p] - img.data[3 * (p + img.cols)], img.data[3 * p + 1] - img.data[3 * (p + img.cols) + 1], img.data[3 * p + 2] - img.data[3 * (p + img.cols) + 2]) + beta*abs(dep.data[p] - dep.data[p + dep.cols]);
				if (index <= 500)
					graph->add_edge(p, p + img.cols, exp_table[index], exp_table[index]);
			}
		}
	}

	double flow = graph->maxflow();

	for (int i = 0; i<img.rows*img.cols; ++i)
	{
		if (seed.data[i] == 255)
		{
			seg.data[i] = 255;
		}
		else if (seed.data[i] == 0)
			seg.data[i] = 0;
		else
		{
			if (graph->what_segment(i) == GraphType::SOURCE)
				seg.data[i] = 255;
			else
				seg.data[i] = 0;
		}
	}

	delete[] fgModel;
	delete[] bgModel;
	delete graph;
}

/*------------------------- create new graphcut -----------------------------*/
void segAlgorithm::middleGraphcut(Mat& img, Mat &dep, Mat& seed, Mat &seg) {
	int numNodes = img.rows*img.cols;
	int numEdges = 4 * numNodes - img.rows - img.cols;
	GraphType *graph = new GraphType(numNodes, numEdges);
	int count = 0;

	int *nodes = new int[numNodes];

	//t-link
	for (int i = 0; i<img.rows; ++i)
	{
		for (int j = 0; j<img.cols; ++j)
		{
			int p = i*img.cols + j;

			nodes[p] = -1;

			if (seed.data[p] != 255 && seed.data[p] != 0)
			{
				graph->add_node();
				nodes[p] = count;

				if (j != 0 && seed.data[p - 1] != midColor)
				{
					(seed.data[p - 1] == 0) ? graph->add_tweights(count, 0, 10000) : graph->add_tweights(count, 10000, 0);
				}
				else if (j != img.cols - 1 && seed.data[p + 1] != midColor)
				{
					(seed.data[p + 1] == 0) ? graph->add_tweights(count, 0, 10000) : graph->add_tweights(count, 10000, 0);
				}
				else if (i != 0 && seed.data[p - img.cols] != midColor)
				{
					(seed.data[p - img.cols] == 0) ? graph->add_tweights(count, 0, 10000) : graph->add_tweights(count, 10000, 0);
				}
				else if (i != img.rows - 1 && seed.data[p + img.cols] != midColor)
				{
					(seed.data[p + img.cols] == 0) ? graph->add_tweights(count, 0, 10000) : graph->add_tweights(count, 10000, 0);
				}
				++count;
			}
		}
	}

	//n-link
	for (int i = 0; i<img.rows; ++i)
	{
		for (int j = 0; j<img.cols; ++j)
		{
			int p = i*img.cols + j;

			if (nodes[p] != -1)
			{
				//not last column
				if (j != img.cols - 1 && nodes[p + 1] != -1)
				{
					int index = theta*EuclideanDis(img.data[3 * p] - img.data[3 * p + 3], img.data[3 * p + 1] - img.data[3 * p + 4], img.data[3 * p + 2] - img.data[3 * p + 5]) + beta*abs(dep.data[p] - dep.data[p + 1]);
					if (index <= 500)
						graph->add_edge(nodes[p], nodes[p + 1], exp_table[index], exp_table[index]);
				}
				//not last row
				if (i != img.rows - 1 && nodes[p + img.cols] != -1)
				{
					int index = theta*EuclideanDis(img.data[3 * p] - img.data[3 * (p + img.cols)], img.data[3 * p + 1] - img.data[3 * (p + img.cols) + 1], img.data[3 * p + 2] - img.data[3 * (p + img.cols) + 2]) + beta*abs(dep.data[p] - dep.data[p + dep.cols]);
					if (index <= 500)
						graph->add_edge(nodes[p], nodes[p + img.cols], exp_table[index], exp_table[index]);
				}
			}
		}
	}

	double flow = graph->maxflow();

	for (int i = 0; i<img.rows*img.cols; ++i)
	{
		seg.data[i] = seed.data[i];
		if (nodes[i] != -1)
		{
			if (graph->what_segment(nodes[i]) == GraphType::SOURCE)
				seg.data[i] = 255;
			else if (graph->what_segment(nodes[i]) == GraphType::SINK)
				seg.data[i] = 0;
		}
	}

	delete[]nodes;
	delete graph;
}

/*------------------------- developed color graphcut -----------------------------*/
double segAlgorithm::gdGraphcut(string &imgPath, string &depPath, Mat &seed) {
	LARGE_INTEGER nFreq;
	LARGE_INTEGER start, end;
	QueryPerformanceFrequency(&nFreq);
	Mat img = imread(imgPath), dep;
	if (methodType != "mgc")
		dep = imread(depPath, 0);
	else
		dep = Mat(img.size(), 0);
	Mat seeds = seed.clone();

	for (int i = 0; i != img.cols*img.rows; ++i)
	{
		if (seeds.data[i] < 50)
			seeds.data[i] = 0;
		else if (seeds.data[i] > 200)
			seeds.data[i] = 255;
		else
			seeds.data[i] = midColor;
	}
	segImage = Mat(img.size(), CV_8UC1);
	/*------------------------- multiscale level initialization -----------------------------*/

	int levelNum = 0;

	int pixels = img.cols*img.rows;
	while (pixels > scale)
	{
		pixels /= step*step;
		++levelNum;
	}
	//cout << "level = " << levelNum << endl;

	/*------------------------- original graphcut on highest level -----------------------------*/

	if (levelNum == 0)
	{
		QueryPerformanceCounter(&start);
		heighestGraphcut(img, dep, seeds, segImage);
		QueryPerformanceCounter(&end);
		morphologyEx(segImage, segImage, cv::MORPH_OPEN, Mat());
		morphologyEx(segImage, segImage, cv::MORPH_OPEN, Mat());
		return (double)(end.QuadPart - start.QuadPart) / (double)nFreq.QuadPart;
	}

	QueryPerformanceCounter(&start);
	int temp = 1;
	for (int i = 0; i != levelNum; ++i)
		temp *= step;

	Size hSize = Size(img.cols / temp, img.rows / temp);
	Mat curImg, curSeed, curDep;
	Mat hSeg = Mat(hSize, CV_8UC1);
	resize(img, curImg, hSize);
	resize(seeds, curSeed, hSize);
	resize(dep, curDep, hSize);

	heighestGraphcut(curImg, curDep, curSeed, hSeg);

	morphologyEx(hSeg, hSeg, cv::MORPH_CLOSE, Mat());
	morphologyEx(hSeg, hSeg, cv::MORPH_OPEN, Mat());

	/*------------------------- refined graphcut on middle level -----------------------------*/
	for (int l = levelNum - 1; l != 0; --l)
	{
		Size curSize = Size(hSize.width*step, hSize.height*step);
		Mat eSeg, dSeg;
		Mat curSeg = Mat(curSize, CV_8UC1);

		Mat element(levelNum - l + 2, levelNum - l + 2, CV_8U, Scalar(1));
		erode(hSeg, eSeg, element);
		dilate(hSeg, dSeg, element);

		resize(eSeg, eSeg, curSize);
		resize(dSeg, dSeg, curSize);

		resize(img, curImg, curSize);
		resize(seeds, curSeed, curSize);
		resize(dep, curDep, curSize);
		//new graphcut
		for (int i = 0; i<curSize.height*curSize.width; ++i)
		{
			if (eSeg.data[i] == 255)
				curSeed.data[i] = 255;
			else if (dSeg.data[i] == 0)
				curSeed.data[i] = 0;
		}

		middleGraphcut(curImg, curDep, curSeed, curSeg);
		morphologyEx(curSeg, curSeg, cv::MORPH_OPEN, Mat());

		hSeg = curSeg;
		hSize = curSize;
	}

	/*------------------------- graphcut on level 0 -----------------------------*/
	Mat eSeg = Mat(img.size(), CV_8UC1);
	Mat dSeg = Mat(img.size(), CV_8UC1);

	Mat element(levelNum + 2, levelNum + 2, CV_8U, Scalar(1));
	erode(hSeg, eSeg, element);
	dilate(hSeg, dSeg, element);

	resize(eSeg, eSeg, img.size());
	resize(dSeg, dSeg, img.size());

	//new graphcut
	for (int i = 0; i<img.cols*img.rows; ++i)
	{
		if (eSeg.data[i] == 255)
			seeds.data[i] = 255;
		if (dSeg.data[i] == 0)
			seeds.data[i] = 0;
	}

	middleGraphcut(img, dep, seeds, segImage);

	QueryPerformanceCounter(&end);
	morphologyEx(segImage, segImage, cv::MORPH_CLOSE, Mat());
	morphologyEx(segImage, segImage, cv::MORPH_OPEN, Mat());

	return (double)(end.QuadPart - start.QuadPart) / (double)nFreq.QuadPart;
}

void segAlgorithm::segmentation() {
	if (methodType == "gb")
		segTime = grabcut(imgPath, seedImage);
	else if (methodType == "gc")
		segTime = graphcut(imgPath, seedImage);
	else {
		ini_exp_table(500);
		setParaForMethod();
		if (methodType == "rgbd")
			segTime = rgbdGraphcut(imgPath, depthPath, seedImage);
		else
			segTime = gdGraphcut(imgPath, depthPath, seedImage);
	}
	//cout << "RGBD Segmentation takes " << segTime << " seconds." << endl;

	Mat colorSeed = grey2color(seedImage);
	Mat colorSeg = grey2color(segImage);
	showImage = Mat(colorSeed.size(), CV_8UC3);
	addWeighted(imread(imgPath), 0.7, colorSeg, 0.3, 0.0, showImage);
	grey2color(seedImage, showImage);
}

Mat segAlgorithm::grey2color(Mat &img) {
	Mat image = Mat(img.size(), CV_8UC3);
	for (int i = 0; i < img.cols*img.rows; ++i)
	{
		if (img.data[i] == 255) {
			image.data[3 * i] = 0;
			image.data[3 * i + 1] = 0;
			image.data[3 * i + 2] = 255;
		}
		else if (img.data[i] == 0) {
			image.data[3 * i] = 255;
			image.data[3 * i + 1] = 0;
			image.data[3 * i + 2] = 0;
		}
		else {
			image.data[3 * i] = midColor;
			image.data[3 * i + 1] = midColor;
			image.data[3 * i + 2] = midColor;
		}
	}
	return image;
}

void segAlgorithm::grey2color(Mat &img, Mat &dst) {
	for (int i = 0; i < img.cols*img.rows; ++i) {
		if (img.data[i] == 255) {
			dst.data[3 * i] = 0;
			dst.data[3 * i + 1] = 0;
			dst.data[3 * i + 2] = 255;
		}
		else if (img.data[i] == 0) {
			dst.data[3 * i] = 255;
			dst.data[3 * i + 1] = 0;
			dst.data[3 * i + 2] = 0;
		}
	}
}

double segAlgorithm::grabcut(String &imgPath, Mat &seed) {
	LARGE_INTEGER nFreq;
	LARGE_INTEGER start, end;
	QueryPerformanceFrequency(&nFreq);

	Mat img = imread(imgPath);
	segImage = seed.clone();

	for (int i = 0; i < segImage.rows*segImage.cols; ++i) {
		if (segImage.data[i] == 255)
			segImage.data[i] = GC_FGD;
		else if (segImage.data[i] == 0)
			segImage.data[i] = GC_BGD;
		else
			segImage.data[i] = GC_PR_BGD;
	}

	Mat bgdModel, fgdModel;
	QueryPerformanceCounter(&start);

	grabCut(img, segImage, Rect(10, 10, 10, 10), bgdModel, fgdModel, 1, GC_INIT_WITH_MASK);

	for (int i = 0; i < segImage.rows*segImage.cols; ++i) {
		if (segImage.data[i] == GC_FGD || segImage.data[i] == GC_PR_FGD)
			segImage.data[i] = 255;
		else
			segImage.data[i] = 0;
	}

	QueryPerformanceCounter(&end);

	return (double)(end.QuadPart - start.QuadPart) / (double)nFreq.QuadPart;
}

double segAlgorithm::graphcut(string &imgPath, Mat &seed) {
	LARGE_INTEGER nFreq;
	LARGE_INTEGER start, end;
	QueryPerformanceFrequency(&nFreq);

	QueryPerformanceCounter(&start);

	Mat img = imread(imgPath);
	segImage = seed.clone();

	int* fgModel = new int[K*K*K];
	int* bgModel = new int[K*K*K];
	if (bgModel == NULL) {
		//cout << "new failed" << endl;
	}

	hist(img, segImage, fgModel, bgModel);

	int numNodes = img.rows*img.cols;
	int numEdges = 4 * numNodes - img.rows - img.cols;
	GraphType *graph = new GraphType(numNodes, numEdges);
	graph->add_node(numNodes);

	for (int i = 0; i<img.rows; ++i) {
		for (int j = 0; j<img.cols; ++j)
		{
			int p = i*img.cols + j;
			//t-link
			if (segImage.data[p] == 255)		//object
			{
				graph->add_tweights(p, 10000, 0);//add_tweights(node_id i, tcaptype cap_source, tcaptype cap_sink)
			}
			else if (segImage.data[p] == 0)		//background
			{
				graph->add_tweights(p, 0, 10000);
			}
			else
			{
				//int K = 10;
				int x = K*img.data[3 * p] / 256 * K*K + K*img.data[3 * p + 1] / 256 * K + K*img.data[3 * p + 2] / 256;
				if (!(fgModel[x] + bgModel[x]))
					graph->add_tweights(p, 50, 50);
				else
					graph->add_tweights(p, 5 * (fgModel[x]) / (fgModel[x] + bgModel[x]), 5 * (bgModel[x]) / (fgModel[x] + bgModel[x]));
			}

			//n-link
			if (!(j >= img.cols - 1))	//not last column
			{
				double w = 35 * exp(-0.0075*EuclideanDis(img.data[3 * p] - img.data[3 * p + 3], img.data[3 * p + 1] - img.data[3 * p + 4], img.data[3 * p + 2] - img.data[3 * p + 5]));
				graph->add_edge(p, p + 1, w, w);
			}
			if (!(i >= img.rows - 1))	//not last row
			{
				double w = 35 * exp(-0.0075*EuclideanDis(img.data[3 * p] - img.data[3 * (p + img.cols)], img.data[3 * p + 1] - img.data[3 * (p + img.cols) + 1], img.data[3 * p + 2] - img.data[3 * (p + img.cols) + 2]));
				graph->add_edge(p, p + img.cols, w, w);
			}
		}
	}

	double flow = graph->maxflow();

	for (int i = 0; i<img.rows*img.cols; ++i)
	{
		if (segImage.data[i] == 255)
		{
			segImage.data[i] = 255;
		}
		else if (segImage.data[i] == 0)
			segImage.data[i] = 0;
		else
		{
			if (graph->what_segment(i) == GraphType::SOURCE)
				segImage.data[i] = 255;
			else
				segImage.data[i] = 0;
		}
	}

	QueryPerformanceCounter(&end);

	delete[] fgModel;
	delete[] bgModel;
	delete graph;

	return (double)(end.QuadPart - start.QuadPart) / (double)nFreq.QuadPart;
}

double segAlgorithm::rgbdGraphcut(string &imgPath, string &depPath, Mat &seed) {
	LARGE_INTEGER nFreq;
	LARGE_INTEGER start, end;
	QueryPerformanceFrequency(&nFreq);

	QueryPerformanceCounter(&start);

	Mat img = imread(imgPath);
	Mat dep = imread(depPath);
	segImage = seed.clone();

	int* fgModel = new int[K*K*K];
	int* bgModel = new int[K*K*K];
	int *dfg = new int[K];
	int *dbg = new int[K];
	if (bgModel == NULL) {
		//cout << "new failed" << endl;
	}

	hist(img, segImage, fgModel, bgModel);
	depHist(dep, segImage, dfg, dbg);

	int numNodes = img.rows*img.cols;
	int numEdges = 4 * numNodes - img.rows - img.cols;
	GraphType *graph = new GraphType(numNodes, numEdges);
	graph->add_node(numNodes);

	for (int i = 0; i<img.rows; ++i) {
		for (int j = 0; j<img.cols; ++j)
		{
			int p = i*img.cols + j;
			//t-link
			if (segImage.data[p] == 255)		//object
			{
				graph->add_tweights(p, 10000, 0);//add_tweights(node_id i, tcaptype cap_source, tcaptype cap_sink)
			}
			else if (segImage.data[p] == 0)		//background
			{
				graph->add_tweights(p, 0, 10000);
			}
			else
			{
				//int K = 10;
				int x = K*img.data[3 * p] / 256 * K*K + K*img.data[3 * p + 1] / 256 * K + K*img.data[3 * p + 2] / 256;
				int y = K*dep.data[p] / 256;

				int csum = fgModel[x] + bgModel[x];
				int dsum = dfg[y] + dbg[y];

				if (!csum&&!dsum)
					graph->add_tweights(p, 50, 50);
				else if (!dsum)
					graph->add_tweights(p, 25 + lambda*theta*fgModel[x] / csum, 25 + lambda*theta*bgModel[x] / csum);
				else if (!csum)
					graph->add_tweights(p, 25 + lambda*alpha*dfg[y] / dsum, 25 + lambda*dbg[y] / dsum);
				else
					graph->add_tweights(p, lambda*(theta*fgModel[x] / csum + alpha*dfg[y] / dsum), lambda*(theta*bgModel[x] / csum + alpha*dbg[y] / dsum));
			}

			//n-link
			if (!(j >= img.cols - 1))	//not last column
			{
				int index = theta*EuclideanDis(img.data[3 * p] - img.data[3 * p + 3], img.data[3 * p + 1] - img.data[3 * p + 4], img.data[3 * p + 2] - img.data[3 * p + 5]) + beta*square(dep.data[p] - dep.data[p + 1]);
				if (index <= 500)
					graph->add_edge(p, p + 1, exp_table[index], exp_table[index]);
			}
			if (!(i >= img.rows - 1))	//not last row
			{
				int index = theta*EuclideanDis(img.data[3 * p] - img.data[3 * (p + img.cols)], img.data[3 * p + 1] - img.data[3 * (p + img.cols) + 1], img.data[3 * p + 2] - img.data[3 * (p + img.cols) + 2]) + beta*square(dep.data[p] - dep.data[p + dep.cols]);
				if (index <= 500)
					graph->add_edge(p, p + img.cols, exp_table[index], exp_table[index]);
			}
		}
	}

	double flow = graph->maxflow();

	for (int i = 0; i<img.rows*img.cols; ++i)
	{
		if (segImage.data[i] == 255)
		{
			segImage.data[i] = 255;
		}
		else if (segImage.data[i] == 0)
			segImage.data[i] = 0;
		else
		{
			if (graph->what_segment(i) == GraphType::SOURCE)
				segImage.data[i] = 255;
			else
				segImage.data[i] = 0;
		}
	}

	QueryPerformanceCounter(&end);

	delete[] fgModel;
	delete[] bgModel;
	delete[] dfg;
	delete[] dbg;
	delete graph;

	return (double)(end.QuadPart - start.QuadPart) / (double)nFreq.QuadPart;
}