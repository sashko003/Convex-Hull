#include <QCoreApplication>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Point A(1,1), B(5,0), C(-1,-1), D(0, 0), E(-5,0), F(0,-3), G(0,4), H(3,3), I(2, -4);
    list<Point> points;
    points.push_back(A); points.push_back(B); points.push_back(C); points.push_back(D);points.push_back(E);points.push_back(F);points.push_back(G);points.push_back(H);points.push_back(I);

    Shell shell;
    shell.setShell(points);

    list<Point> list(shell.getShell());
    std::ostream_iterator<Point> ostr(cout, " ");
    std::copy(list.begin(), list.end(), ostr);

    std::cout << "Base point:";
    std::cout<<shell.findBase()<<std::endl;

    shell.sort();
    list = shell.getShell();
    std::cout << "Sorted points:" <<std::endl;
    std::copy(list.begin(), list.end(), ostr);



    list = shell.erase();
    std::cout << "Convex shell:" <<std::endl;
    std::copy(list.begin(), list.end(), ostr);

    cout<<"Enter x and y: ";
    int x, y; std::cin >> x >> y;
    Point test(x,y);
    cout<<shell.belongShell(test);

    cout<<"Add point: ";
    std::cin >> x >> y;
    Point test2(x,y);

    shell.addPoint(test2);
    list = shell.getShell();
    std::cout << "\nConvex shell(add):" << std::endl;
    std::copy(list.begin(), list.end(), ostr);

    return a.exec();
}
