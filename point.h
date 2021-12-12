//
// Created by davla on 12/12/2021.
//

#ifndef RECONSTRUCTION_3D_PROYECTO3_POINT_H
#define RECONSTRUCTION_3D_PROYECTO3_POINT_H

/*********************************************/
#include "Principal.h"
/*********************************************/

class Point {
private:
protected:
public:
    vector<CImg <char>> picture_;
    vector<vector <vec3f>> point_;
    int num_picture_, height, wide;

    CImg <char> barrido_vector(CImg<float> &picturee, int cominezo) const;
    void verPicture(const string& road_picture, int cominezo);
    void point_out();
};


#endif //RECONSTRUCTION_3D_PROYECTO3_POINT_H
