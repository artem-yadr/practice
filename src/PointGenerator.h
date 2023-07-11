#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

typedef struct Point{
    double lat, lng;
} Point;

class PointGenerator{
    protected:
    std::vector<Point> points;
    int count;

    public:
    PointGenerator(int count);
    void saveToFile(std::string filename);
    int generatePoints();
};