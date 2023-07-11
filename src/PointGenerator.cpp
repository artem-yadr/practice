#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

#include "PointGenerator.h"

PointGenerator::PointGenerator(int count){
    this->count = count;
    this->points.reserve(count);
};

int PointGenerator::generatePoints(){
    srand((unsigned) time(0));
    double lat, lng;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < this->count; i++){
        lat = ((double) rand() / RAND_MAX)*180 - 90;
        lng = ((double) rand() / RAND_MAX)*360 - 180;
        
        this->points.push_back(Point{lat, lng});
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
};

void PointGenerator::saveToFile(std::string filename){
    std::ofstream myfile;
    myfile.open (filename);
    for (int i = 0; i < this->count; i++){
        myfile << this->points[i].lat;
        myfile << " ";
        myfile << this->points[i].lng;
        myfile << "\n";
    }
    
    myfile.close();

}