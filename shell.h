#ifndef SHELL_H
#define SHELL_H
#include "header.h"
//#include "point2.h"

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
    friend bool operator>(const Point &firstP, const Point &secondP); // by the left angle
    friend bool operator<(const Point &firstP, const Point &secondP); // by the polar angle (doesn't work)

    friend bool operator>=(const Point &firstP, const Point &secondP);
    friend std::ostream& operator<<(std::ostream& oStream, const Point &point);
    friend bool operator==(const Point &point1, const Point &point2);

   // friend bool isOnLeftSide(const Point &firstP, const Point &secondP);
    friend double length(const Point& point1, const Point& point2);
    friend double polarAngle(const Point& point1, const Point& point2);
protected:
        int X, Y;
};

class Shell
{
    //friend class Point;
public:
    Shell();
    Shell(const list<Point> _points);
    Shell(const Shell &_shell);
    virtual ~Shell();

    virtual void setShell(const list<Point> &_shell);
    virtual list<Point> getShell() const;
    static void setBasePoint(const Point &_base);
    static Point getBasePoint();

    virtual Point findBase();
    virtual list<Point> sort();
    virtual list<Point> erase();
    virtual list<Point>::iterator findPlace(const Point& _point);
    virtual bool belongShell(const Point& _point);
    virtual bool addPoint(const Point &_point);
protected:
    static Point basePoint;
    list<Point> lsPoints;

};

#endif // SHELL_H
