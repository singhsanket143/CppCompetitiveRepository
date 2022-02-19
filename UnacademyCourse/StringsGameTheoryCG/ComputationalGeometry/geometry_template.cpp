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
};

int dot(Point &a, Point &b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z + b.z);
}

Point cross(Point a, Point b) {
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

long long int signed_area_of_parallelogram(Point a, Point b, Point c) {
    return cross(b-a, c-b).z;
}

double area_of_triangle(Point a, Point b, Point c) {
    return abs(signed_area_of_parallelogram(a, b, c)/2.0);
}

int direction(Point a, Point b, Point c) {
    long long int t = signed_area_of_parallelogram(a, b, c);
    if(t < 0) return -1;
    else if(t > 0) return 1;
    else return 0;
}

double area_of_polygon(Point a[], int n) {
    double area = 0;
    for(int i = 0; i < n; i++) {
        area -= (a[(i+1)%n].x - a[i].x) * (a[(i+1)%n].y + a[i].y);
    }
    area /= 2;
    return abs(area);
}

bool is_point_inside_polygon(Point a[], int n, Point p) {
    int l = 1, r = n-2;
    while(l <= r) {
        int mid = (l+r)/2;
        if(direction(a[0], a[mid+1], p) == 1) {
            l = mid+1;
        } else if(direction(a[0], a[mid], p) == -1) {
            r = mid - 1;
        } else {
            l = r = mid;
        }
    }
    if(area_of_triangle(a[0], a[l], a[l+1]) == area_of_triangle(a[0], a[l], p) + area_of_triangle(a[l], a[l+1], p) + area_of_triangle(a[0], p, a[l+1])) return true;
    else return false;
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
