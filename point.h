#ifndef POINT_H
#define POINT_H
#include "header.h"

class Point
{
public:
    Point();
    Point(const int _x, const int _y);
    Point(const Point &_point);
    virtual ~Point();
    Point& operator=(const Point& _point);
    Point& operator=(const int _value);

    void setCoordinates(const int _x, const int _y);
    int getX() const;
    int getY() const;
    friend int turn(const Point &firstPoint, const Point &secondPoint, const Point &thirdPoint);
    friend bool operator<(const Point &firstP, const Point &secondP);
    friend bool operator>(const Point &firstP, const Point &secondP);
    friend std::ostream& operator<<(std::ostream& oStream, const Point &point);
    friend bool operator==(const Point &point1, const Point &point2);
protected:
        int X, Y;
};

#endif // POINT_H
