//
// Created by Alexander Tampier on 25.05.18.
//

#include <ostream>

#ifndef UEBUNG04_POINT_H
#define UEBUNG04_POINT_H

#endif //UEBUNG04_POINT_H

class Point{
private:
    const double x;
    const double y;
    bool visited;

public:
    Point(double x, double y, bool visited=false) : x(x), y(y), visited(visited) {}

    const double getX() const {
        return x;
    }

    const double getY() const {
        return y;
    }

    bool isVisited() const {
        return visited;
    }

    void setVisited(bool visited) {
        Point::visited = visited;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y << " visited: " << point.visited;
        return os;
    }
};
