#ifndef POINT_CPP
#define POINT_CPP
#include "point.h"

Point::Point() : X(0), Y(0)
{

}

Point::Point(const int _x, const int _y) : X(_x), Y(_y)
{

}

Point::Point(const Point &_point)
{
    this->X = _point.X;
    this->Y = _point.Y;
}

Point::~Point()
{

}


void Point::setCoordinates(const int _x, const int _y)
{
    this->X = _x;
    this->Y = _y;
}

int Point::getX() const
{
    return X;
}

int Point::getY() const
{
    return Y;
}

bool operator<(const Point &firstP, const Point &secondP)
{
    bool isLeft = false;
    if (turn(Shell::getBasePoint(), firstP, secondP) > 0)
        isLeft =  true;
    else
        isLeft =  false;
    return isLeft;
}
// for method findBasePoint() in class ConvexHull
bool operator>(const Point &firstP, const Point &secondP)
{
    if(firstP.Y == secondP.Y)
        return firstP.X > secondP.X;
    return firstP.Y > secondP.Y;
}

Point& Point::operator=(const Point& _point)
{
    this->X = _point.X;
    this->Y = _point.Y;
    return *this;
}

Point &Point::operator=(const int _value)
{
    this->setCoordinates(_value, _value);
}


// Function calculates the turn of thirdPoint regarding vector (firstPoint;secondPoint).
// If turn is left, function returns positive value (true), if turn is right, function returns negative value (false).
int turn(const Point &basePoint, const Point &firstPoint, const Point &secondPoint)
{
    return (firstPoint.X - basePoint.X)*(secondPoint.Y - firstPoint.Y) - (firstPoint.Y - basePoint.Y)*(secondPoint.X - firstPoint.X);
}

std::ostream& operator<<(std::ostream& oStream, const Point &point)
{
    oStream << "X: " << point.X << "  Y: " << point.Y << std::endl;
    return oStream;
}

bool operator==(const Point &point1, const Point &point2)
{
    return (point1.X == point2.X) && (point1.Y == point2.Y);
}

#endif // !POINT_CPP
