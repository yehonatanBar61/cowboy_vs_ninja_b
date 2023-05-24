#include "Team.hpp"

using namespace std;

namespace ariel{
    Point::Point(double x, double y): x(x), y(y) {}

    double Point::distance(Point p) {
        double a = pow(p.x - this->x, 2);
        double b = pow(p.y - this->y, 2);
        return sqrt(a + b);
    }

    string Point::print(){
        return "(" + to_string(this->x) + "," + to_string(this->y)  + ")";
    }

    Point Point::moveTowards(Point source, Point destination, double dis) {
        if(dis < 0)
            throw invalid_argument("[!] negative");



        double currentDistance = source.distance(destination);

        if (currentDistance <= dis) {
            return destination;
        } else {
            double newX = source.getX() + dis / currentDistance * (destination.getX() - source.getX());
            double newY = source.getY() + dis / currentDistance * (destination.getY() - source.getY());
            return {newX, newY};
        }
    }

    double Point::getX() {
        return this->x;
    }

    double Point::getY() {
        return this->y;
    }

    bool Point::operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }


}

