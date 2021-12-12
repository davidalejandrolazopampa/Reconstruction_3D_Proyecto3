//
// Created by davla on 12/12/2021.
//

#ifndef RECONSTRUCTION_3D_PROYECTO3_VECTOR_H
#define RECONSTRUCTION_3D_PROYECTO3_VECTOR_H
/*********************************************/
#include "Principal.h"
/*********************************************/
//class vector {
class vec3f{
private:
protected:
public:
     float x,y,z ;
    //vec3f() {x=0, y=0, z=0;}
    vec3f(float _x, float _y, float _z):x{_x}, y{_y}, z{_z}{}
};


#endif //RECONSTRUCTION_3D_PROYECTO3_VECTOR_H
