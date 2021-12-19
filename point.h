#ifndef RECONSTRUCTION_3D_PROYECTO3_POINT_H
#define RECONSTRUCTION_3D_PROYECTO3_POINT_H
/*********************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <GL/freeglut.h>
/*********************************************/
#include "CImg.h"
#include "vector_1.h"
/*********************************************/
using namespace cimg_library;
using namespace std;
/*********************************************/
#define FOR(i,a,b) for(int i=(a);i<b;i++)
/*********************************************/
class Point {
private:
protected:
public:
    vector<CImg <char>> picture_;
    vector<vector <vec3f>> point_;
    int num_picture_=0, height, wide;

    CImg <char> barrido_vector(CImg<float> &picturee, int cominezo) const;
    void verPicture(const string& road_picture, int cominezo);
    void point_out(float distance_IMG);
    void guardar_point(const string& camino);
    void load_file(const string& camino_Point);
};


#endif //RECONSTRUCTION_3D_PROYECTO3_POINT_H
