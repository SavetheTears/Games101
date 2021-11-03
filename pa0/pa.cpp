#define _USE_MATH_DEFINES //include this line to eliminate the false bug report of M_PI
#include <cmath>
#include "../eigen-3.4.0/Eigen/Core" //change this to your relative path
#include "../eigen-3.4.0/Eigen/Dense"
#include <iostream>

double DegreeToRadian(double degree);

//do use homogeneous coordinate so that all the operation can be treated as linear transformation

int main(){
    //P(2,1) create as point so the last entry is 1
    Eigen::Vector3f v(2.0,1.0,1.0);
    std::cout << v <<std::endl;

    //create rotation matrix and translate matrix which are also 3d
    Eigen::Matrix3f rotation, translation;
    double rt = DegreeToRadian(45);

    rotation << cos(rt), -sin(rt), 0, sin(rt), cos(rt),0 ,0 ,0,1;
    translation << 1,0,1,0,1,2,0,0,1;

    //you can combine them by calculating matrix multiplication and use only one transformer
    std::cout << translation*rotation<<std::endl;
    //store the result
    Eigen::Vector3f result = translation*rotation*v;
    std::cout << result <<std::endl;
    return 0;
}

double DegreeToRadian(double degree){
    return degree/180 * M_PI;
}