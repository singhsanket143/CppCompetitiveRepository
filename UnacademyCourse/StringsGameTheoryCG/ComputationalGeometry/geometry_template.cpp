#include<bits/stdc++.h>
#define PI 3.14159265
class Point {
public:
    int x, y, z;
    Point(int x, int y, int z = 0) : x(x), y(y), z(z) {}
    Point operator+(const Point &b) {
        return Point(this->x + b.x, this->y + b.y, this->z + b.z);
    } 
    Point operator-(const Point &b) {
        return Point(this->x - b.x, this->y - b.y, this->z - b.z);
    } 
    Point& operator+=(const Point &b) {
        this->x += b.x;
        this->y += b.y;
        this->z += b.z;
        return *this;
    }
    Point& operator-=(const Point &b) {
        this->x -= b.x;
        this->y -= b.y;
        this->z -= b.z;
        return *this;
    }
};

class Line {
public:
    int a, b, c;
    Line(int a, int b, int c) : a(a), b(b), c(c) {}
}

int dot(Point &a, Point &b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z + b.z);
}

Point cross(Point &a, Point &b) {
    return Point(a.y*b.z - b.y*a.z, b.x*a.z  - a.x*b.z, a.x*b.y - a.y*b.x);
}

float radianToDegree(float ang) {
    return ang*180.0 / PI;
}

float angle(Point &a, Point &b) {
    return acos((dot(a, b)/sqrt(dot(a,a)))/sqrt(dot(b,b)));
}

Point intersectionOfTwoLines(Line &x, Line &y) {
    return Point((x.b*y.c - y.b*x.c)/(x.a*y.b - y.a*x.b), (x.c*y.a - y.c*x.a)/(x.a*y.b - y.a*x.b));
}

int main(int argc, char const *argv[])
{
    int x1, y1, x2, y2;
    std::cin>>x1>>y1>>x2>>y2;
    Point a(x1, y1);
    Point b(x2, y2);

    Point c = a + b;
    std::cout<<c.x<<" "<<c.y<<" ";
    std::cout<<angle(a, b)<<"\n";
    std::cout<<radianToDegree(angle(a, b))<<"\n";
    return 0;
}
