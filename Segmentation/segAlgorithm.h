#pragma once

#include "geo.h"
#include "graph.h"
#include <omp.h>
#include <math.h>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
typedef Graph<int, int, int> GraphType;

class segAlgorithm
{
public:
	segAlgorithm();
	~segAlgorithm();

	void setMethodType(string &method) { methodType = method; }
	void setImgPath(string &path) { imgPath = path; }
	void setDepthPath(string &path) { depthPath = path; }
	void setSeedImage(Mat &img);
	double getSegTime() { return segTime; }
	Mat getSegImage() { return segImage; }
	Mat getShowImage() { return showImage; }
	void segmentation();

private:
	string imgPath;
	string depthPath;
	string methodType;
	Mat seedImage;
	Mat segImage;
	Mat showImage;
	double segTime;

	void setParaForMethod();
	void hist(Mat& img, Mat& seeds, int* fgModel, int* bgModel);
	void depHist(Mat &dep, Mat &seed, int *fgModel, int *bgModel);
	void ini_exp_table(int num);
	void splitSeed(Mat &seed, Mat &fseed, Mat &bseed);
	int EuclideanDis(int a, int b, int c) { return a*a + b*b + c*c; }
	int square(int a) { return a*a; }
	void heighestGraphcut(Mat& img, Mat &dep, Mat& seed, Mat &seg);
	void middleGraphcut(Mat& img, Mat &dep, Mat& seed, Mat &seg);
	double gdGraphcut(string &imgPath, string &depPath, Mat &seeds);
	Mat mergeResult(Mat &img1, Mat &img2);
	Mat grey2color(Mat &img);
	void grey2color(Mat &img, Mat &dst);
	double grabcut(string &imgPath, Mat &seed);
	double rgbdGraphcut(string &imgPath, string &depPath, Mat &seed);
	double graphcut(string &imgPath, Mat &seed);
};