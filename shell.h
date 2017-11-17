#ifndef SHELL_H
#define SHELL_H
#include "header.h"

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
