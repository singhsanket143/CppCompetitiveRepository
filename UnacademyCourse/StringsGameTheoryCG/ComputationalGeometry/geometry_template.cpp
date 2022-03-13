#include<bits/stdc++.h>
#define PI 3.14159265
void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
class Point {
public:
    int x, y, z;
    Point(int x, int y, int z = 0) : x(x), y(y), z(z) {}
    Point operator+(const Point b) {
        return Point(this->x + b.x, this->y + b.y, this->z + b.z);
    } 
    Point operator-(const Point b) {
        return Point(this->x - b.x, this->y - b.y, this->z - b.z);
    } 
    Point& operator+=(const Point b) {
        this->x += b.x;
        this->y += b.y;
        this->z += b.z;
        return *this;
    }
    Point& operator-=(const Point b) {
        this->x -= b.x;
        this->y -= b.y;
        this->z -= b.z;
        return *this;
    }

    bool operator<(Point b) {
        if(this->x == b.x) return this->y < b.y;
        return this->x < b.x;
    }

    bool operator==(Point b) {
        if(this->x==b.x and this->y==b.y and this->z==b.z) return true;
        else return false;
    }
};

class Line {
public:
    int a, b, c;
    Line(int a, int b, int c) : a(a), b(b), c(c) {}
};

int dot(Point a, Point b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Point cross(Point a, Point b) {
    return Point(a.y*b.z - a.z*b.y, a.z*b.x  - a.x*b.z, a.x*b.y - a.y*b.x);
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
    if(t < -1 or t > 1)
        std::cout<<t<<"\n";
    if(t < 0) return -1; // clockwise
    else if(t > 0) return 1; // anticliockwise
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

std::vector<Point> minkowski_sum(std::vector<Point> a, std::vector<Point> b) { // input in counter clockwise
    int n = a.size(), m = b.size();
    int l = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].x < a[l].x || (a[i].x == a[l].x && a[i].y < a[l].y)) {
            l = i;
        }
    }
    int r = 0;
    for(int i = 0; i < m; i++) {
        if(b[i].x < b[r].x || (b[i].x == b[r].x && b[i].y < b[r].y)) {
            r = i;
        }
    }
    std::vector<Point> result;
    for(int i = 0; i < n+m; i++) {
        result.push_back(a[l]+b[r]);
        if(cross(a[(l+1)%n]-a[l], b[(r+1)%m] - b[r]).z >= 0) {
            l = (l+1)%n;
        } else {
            r = (r+1)%m;
        }
    }
    return result;
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

int max_points_in_a_circle(std::vector<Point> v, double r) {
    int n = v.size();
    int ans = 1;
    for(int i = 0; i < n; i++) {
        std::vector<std::pair<double, std::pair<bool, int>>> ang_enex_ind;
        int cur = 1;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            else {
                double d = std::sqrt((double)dot(v[j]-v[i], v[j]-v[i]));
                if(d > (2*r)) continue;
                double ang1 = atan(((double)(v[j]-v[i]).y)/((double)(v[j]-v[i]).x));
                if((v[j]-v[i]).x < 0) ang1 += M_PI;

                double ang2 = acos(d/(2*r));

                double angen = (ang1 - ang2); 
                // HW to normalise

                double angex = (ang1 + ang2);
                // HW to normalise

                if(angen > angex) cur++;

                ang_enex_ind.push_back({angen, {false, j}});
                ang_enex_ind.push_back({angex, {true, j}});

            }
        }
        std::sort(ang_enex_ind.begin(), ang_enex_ind.end());
        for(auto it : ang_enex_ind) {
            ans = std::max(ans, cur);
            if(it.second.first == false) cur++;
            else cur--;
            ans = std::max(ans, cur);
        }
    }
    return ans;
}

// struct custom_closes_ds {
//     std::set<Point> st;
//     std::priority_queue<Point> hp; // max heap
//     long long int d;

//     bool ins(Point a) {
//         hp.push(Point(-a.x, a.y));
//         st.insert(Point(a.y, a.x));
//         return true;
//     }

//     void del(Point a) {
//         while(!hp.empty() and (-hp.top().x) < a.x-d) {
//             auto it = st.find(Point(hp.top().y, -hp.top().x));
//             st.erase(it);
//             hp.pop();
//         }
//     }
//     std::vector<Point> query(Point a) {
//         auto lb = st.lower_bound(Point(a.y-d, a.x-d));
//         auto ub = st.upper_bound(Point(a.y+d, a.x));
//         std::vector<Point> ans;
//         while(lb != ub) {
//             ans.push_back(Point((*lb).y, (*lb).x));
//             lb++;
//         }
//         return ans;
//     }
// };

std::vector<Point> convex_hull_jarvis_march(std::vector<Point> arr) {
    int n = arr.size();
    int start = 0;
    // get the leftmost point, and if multiple leftmost point then bottom most
    for(int i = 1; i < n; i++) {
        if((arr[i].x < arr[start].x) or (arr[i].x == arr[start].x and arr[i].y < arr[start].y)) {
            start = i;
        }
    }

    std::vector<Point> ans;
    ans.push_back(arr[start]);
    while(true) {
        int curr_pt = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == ans.back()) continue;

            if((direction(ans.back(), arr[curr_pt], arr[i])==-1) or
                (direction(ans.back(), arr[curr_pt], arr[i])==0 and 
                    dot(arr[i]-ans.back(), arr[i]-ans.back()) > dot(arr[curr_pt]-ans.back(), arr[curr_pt]-ans.back())
                )
            ) {
                curr_pt = i;
            }
        }
        if(arr[curr_pt] == ans.front()) break;
        else ans.push_back(arr[curr_pt]);
    }
    return ans;
}

static Point polar_angle_point;

bool cmp(Point a, Point b) {
    if(direction(polar_angle_point, a, b)==1) {
        return true;
    } 
    else if(direction(polar_angle_point, a, b)==-1) {
        return false;
    }
    else return dot(polar_angle_point-a, polar_angle_point-a) < dot(polar_angle_point-b, polar_angle_point-b);
}

std::vector<Point> convex_hull_grahamscan(std::vector<Point> a) {
    int n = a.size();
    if(n <= 2) return a;
    for(int i = 1; i < n; i++) {
        if((a[i].x<a[0].x) or (a[i].x==a[0].x and a[i].y < a[0].y)) {
            std::swap(a[i], a[0]);
        }
    }
    polar_angle_point = a[0];
    std::sort(a.begin()+1, a.end(), cmp);
    std::vector<Point> ans;
    ans.push_back(a[0]);
    ans.push_back(a[1]);
    for(int i = 2; i < n; i++) {

        while(direction(ans[ans.size()-2], ans[ans.size()-1], a[i]) == -1) {
            ans.pop_back();
        }
        ans.push_back(a[i]);
    }
    return ans;
}

// double diameter_of_convex_polygon(std::vector<Point> &a) {
//     int n = a.size();
//     int pt1 = 0;
//     int pt2 = 1;
//     while(cross(a[(pt1+1)%n]-a[pt1], a[(pt2+1)%n]-a[pt2]).z > 0) {
//         pt2++;
//         pt2%=n;
//     }
//     int ans = dot(a[pt2]-a[pt1], a[pt2]-a[pt1]);
//     int st1 = pt1;
//     int st2 = pt2;
//     do {
//         if(cross(a[(pt1+1)%n]-a[pt1], a[(pt2+1)%n]-a[pt2]).z > 0) {
//             pt2++;
//             pt2%=n;
//         } else {
//             pt1++;
//             pt1%=n;
//         }
//         ans = std::max(ans, dot(a[pt2]-a[pt1], a[pt2]-a[pt1]));
//     } while(st1!=pt1 || st2!=pt2);
//     return std::sqrt((double) ans);
// }


int main(int argc, char const *argv[])
{
    // int x1, y1, x2, y2;
    // std::cin>>x1>>y1>>x2>>y2;
    // Point a(x1, y1);
    // Point b(x2, y2);

    // Point c = a + b;
    // std::cout<<c.x<<" "<<c.y<<" ";
    // std::cout<<angle(a, b)<<"\n";
    // std::cout<<radianToDegree(angle(a, b))<<"\n";
    file_i_o();
    int t;
    std::cin>>t;
    for(int j = 1; j <= t; j++) {
        int n;
        std::cin>>n;
        std::vector<Point> arr(n);
        for(int i = 0; i < n; i++) {
            std::cin>>arr[i].x>>arr[i].y;
        }
        std::vector<Point> hull = convex_hull_jarvis_march(arr);
        std::cout<<"Case #"<<j<<"\n";
        for(auto &p:hull) {
            std::cout<<p.x<<" "<<p.y<<"\n";
        }
    }
    return 0;
}
