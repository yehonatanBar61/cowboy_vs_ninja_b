
#ifndef CPP_HW4_POINT_H
#define CPP_HW4_POINT_H

#include <iostream>
using namespace std;

namespace ariel{
    class Point {
        private:
            double x;
            double y;

        public:
            Point();
            Point(double x, double y);
            double getX();
            double getY();
            double distance(Point poi);
            static Point moveTowards(Point source, Point destination, double distance);
            string print();

            // for tests
            bool operator==(const Point &other) const; 
    };
}


#endif //CPP_HW4_POINT_H
