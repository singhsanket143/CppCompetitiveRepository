#include<bits/stdc++.h>
using namespace std;

class Cpoint
{
    public:
        long long x,y,z;
    Cpoint(long long tmp_x=0, long long tmp_y=0, long long tmp_z=0)
    {
        x=tmp_x;
        y=tmp_y;
        z=tmp_z;
    }

    Cpoint operator+(Cpoint b)
    {
        return Cpoint(this->x+b.x, this->y+b.y, this->z+b.z);
    }
    Cpoint operator-(Cpoint b)
    {
        return Cpoint(this->x-b.x, this->y-b.y, this->z-b.z);
    }
    Cpoint operator*(long long val)
    {
        return Cpoint(this->x*val, this->y*val, this->z*val);
    }
    Cpoint operator/(long long val)
    {
        return Cpoint(this->x/val, this->y/val, this->z/val);
    }

    Cpoint& operator=(Cpoint b)
    {
        this->x=b.x;
        this->y=b.y;
        this->z=b.z;
        return *this;
    }
    Cpoint& operator+=(Cpoint b)
    {
        *this=*this+b;
        return *this;
    }
    Cpoint& operator-=(Cpoint b)
    {
        *this=*this-b;
        return *this;
    }
    Cpoint& operator*=(long long val)
    {
        (*this)=(*this)*val;
        return *this;
    }
    Cpoint& operator/=(long long val)
    {
        (*this)=(*this)/val;
        return *this;
    }

    bool operator==(Cpoint b)
    {
        if(this->x==b.x && this->y==b.y && this->z==b.z) return true;
        else return false;
    }
};

long long dot(Cpoint a,Cpoint b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

Cpoint cross(Cpoint a,Cpoint b)
{
    return Cpoint(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
}

double ang(Cpoint a,Cpoint b)
{
    return acos(dot(a,b)/sqrt(dot(a,a)*dot(b,b)));
}

double rad_to_deg(double val)
{
    return val*180/M_PI;
}
double deg_to_rad(double val)
{
    return val*M_PI/180;
}

long long signed_area_of_parallelogram(Cpoint a,Cpoint b,Cpoint c)
{
    return cross(b-a,c-b).z;
}

double area_of_triangle(Cpoint a,Cpoint b,Cpoint c)
{
    return abs(signed_area_of_parallelogram(a,b,c)/2.0);
}

int direction(Cpoint a,Cpoint b,Cpoint c)
{
    long long t=signed_area_of_parallelogram(a,b,c);

    if(t<0) return -1;
    else if(t>0) return 1;
    else return 0;
}

double area_of_polygon(Cpoint a[],int n)
{
    double area=0;

    for(int i=0;i<n;i++)
    {
        area -= (a[(i+1)%n].x-a[i].x) * (a[(i+1)%n].y+a[i].y);

        // i= n-1, a(0)->a(n-1)
    }

    area/=2;

    return abs(area);
}

bool check_point_in_polygon(Cpoint a[], int n, Cpoint p)
{
    int l=1,r=n-2;

    while(l<r)
    {
        int x=(l+r)/2;

        if(direction(a[0],a[x+1],p)==1)
        {
            l=x+1;
        }
        else if(direction(a[0],a[x],p)==-1)
        {
            r=x-1;
        }
        else
        {
            l=r=x;
        }
    }

    if(area_of_triangle(a[0],a[l],a[l+1])==area_of_triangle(a[0],a[l],p)+area_of_triangle(a[l],a[l+1],p)+area_of_triangle(a[l+1],a[0],p)) return true;
    else return false;
}

vector<Cpoint> minkowski_sum(vector<Cpoint> a,vector<Cpoint> b)
{
    int n=a.size(),m=b.size();

    int l=0;
    for(int i=0;i<n;i++)
    {
        if( a[i].x<a[l].x || ( a[i].x==a[l].x && a[i].y<a[l].y ))
        {
            l=i;
        }
    }

    int r=0;
    for(int i=0;i<m;i++)
    {
        if( b[i].x<b[r].x || ( b[i].x==b[r].x && b[i].y<b[r].y ))
        {
            r=i;
        }
    }

    vector<Cpoint> v;

    for(int i=0;i<n+m;i++)
    {
        v.push_back(a[l]+b[r]);

        if( cross( a[(l+1)%n]-a[l] , b[(r+1)%m]-b[r] ).z >= 0 )
        {
            l=(l+1)%n;
        }
        else
        {
            r=(r+1)%n;
        }
    }

    return v;
}

int max_points_in_circle(vector<Cpoint> v,double r)
{
    int n=v.size();
    int ans=1;
    for(int i=0;i<n;i++)
    {
        vector<pair<double,pair<bool,int>>> ang_enex_ind;

        int cur=1;

        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            else
            {
                double d=sqrt((double)dot(v[j]-v[i],v[j]-v[i]));
                if(d>(2*r)) continue;

                double ang1=atan(((double)(v[j]-v[i]).y)/((double)(v[j]-v[i]).x));
                if((v[j]-v[i]).x<0) ang1+=M_PI;

                double ang2=acos(d/(2*r));

                double angen=(8*M_PI+ang1-ang2);
                angen-=2*M_PI*floor(angen/(2*M_PI));
                
                double angex=(8*M_PI+ang1+ang2);
                angex-=2*M_PI*floor(angex/(2*M_PI));

                if(angen>angex) cur++;

                ang_enex_ind.push_back(make_pair(angen,make_pair(false,j)));
                ang_enex_ind.push_back(make_pair(angex,make_pair(true,j)));
            }
        }

        sort(ang_enex_ind.begin(),ang_enex_ind.end());

        for(auto it:ang_enex_ind)
        {
            ans=max(ans,cur);
            if(it.second.first==false) cur++;
            else cur--;
            ans=max(ans,cur);
        }
    }

    return ans;
}

vector<Cpoint> convex_hull_jarvis_march(vector<Cpoint> a)
{
    int n=a.size();

    int strt=0;
    for(int i=1;i<n;i++)
    {
        if((a[i].x<a[strt].x) || (a[i].x==a[strt].x && a[i].y<a[strt].y))
        {
            strt=i;
        }
    }

    vector<Cpoint> ans;
    ans.push_back(a[strt]);

    while(true)
    {
        int pt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==ans.back()) continue;

            if((direction(ans.back(),a[pt],a[i])==-1) || 
            (direction(ans.back(),a[pt],a[i])==0 && 
            dot(a[i]-ans.back(),a[i]-ans.back())>dot(a[pt]-ans.back(),a[pt]-ans.back()) ) )
            {
                pt=i;
            }
        }

        if(a[pt]==ans.front()) break;
        else ans.push_back(a[pt]);
    }

    return ans;
}

static Cpoint polar_angle_point;
bool comp(Cpoint a, Cpoint b)
{
    if(direction(polar_angle_point,a,b)==1) return true;
    else if(direction(polar_angle_point,a,b)==-1) return false;
    else return dot(polar_angle_point-a,polar_angle_point-a)<dot(polar_angle_point-b,polar_angle_point-b);
}

vector<Cpoint> convex_hull_graham_scan(vector<Cpoint> a)
{
    int n=a.size();

    if(n<=2) return a;

    for(int i=1;i<n;i++)
    {
        if((a[i].x<a[0].x) || (a[i].x==a[0].x && a[i].y<a[0].y))
        {
            swap(a[0],a[i]);
        }
    }

    polar_angle_point=a[0];
    sort(a.begin()+1,a.end(),comp);

    vector<Cpoint> ans;
    ans.push_back(a[0]);
    ans.push_back(a[1]);

    for(int i=2;i<n;i++)
    {
        while(direction(ans[((int)ans.size())-2],ans[((int)ans.size())-1],a[i])==-1) ans.pop_back();

        ans.push_back(a[i]);
    }

    return ans;
}

double diameter_of_convex_polygon(vector<Cpoint> v)
{
    int n=v.size();

    int pt1=0;
    int pt2=1;

    while(cross(v[(pt1+1)%n]-v[pt1],v[(pt2+1)%n]-v[pt2]).z>0)
    {
        pt2++;
        pt2%=n;
    }

    long long ans=dot(v[pt2]-v[pt1],v[pt2]-v[pt1]);

    int st1=pt1;
    int st2=pt2;

    do{
        if(cross(v[(pt1+1)%n]-v[pt1],v[(pt2+1)%n]-v[pt2]).z>0)
        {
            pt2++;
            pt2%=n;
        }
        else
        {
            pt1++;
            pt1%=n;
        }

        ans=max(ans,dot(v[pt2]-v[pt1],v[pt2]-v[pt1]));
    }
    while(st1!=pt1||st2!=pt2);

    return sqrt((double)ans);
}

long long powM(long long x,long long y,long long m)
{
    long long ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
}

bool comp2(pair<Cpoint,bool> a,pair<Cpoint,bool> b)
{
    if(a.first.y>=0&&b.first.y<0) return true;
    else if(a.first.y<0&&b.first.y>=0) return false;
    else if(a.first.y==0&&b.first.y==0) return a.first.x>b.first.x;
    else if(direction(Cpoint(0,0),a.first,b.first)==1) return true;
    else return false;
}

int main()
{
    int n;
    cin>>n;
    vector<Cpoint> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }

    a=convex_hull_jarvis_march(a);

    for(auto it:a) cout<<it.x<<' '<<it.y<<'\n';


    return 0;
}