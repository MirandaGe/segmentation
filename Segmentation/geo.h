#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <fstream>
#include <time.h>
#include <io.h>
#include <vector>

#ifdef _DEBUG
#pragma comment(lib, "opencv_core249d.lib")
#pragma comment(lib, "opencv_highgui249d.lib")
#pragma comment(lib, "opencv_imgproc249d.lib")
#else
#pragma comment(lib, "opencv_core249.lib")
#pragma comment(lib, "opencv_highgui249.lib")	
#pragma comment(lib, "opencv_imgproc249.lib")
#endif

using namespace std;
using namespace cv;

void fast_marching(Mat& img, Mat& fmseeds, Mat& geos);