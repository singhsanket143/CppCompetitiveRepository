#include "iostream"
#include "algorithm"
using namespace std;

bool myCompare(pair<string, int> p1, pair<string, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main(int argc, char* argv[])
{
    int min_salary, n;
    cin>>min_salary>>n;
    pair<string, int> emp[100005];
    string name;
    int salary;
    for(int i=0;i<n;i++) {
        cin>>name>>salary;
        emp[i].first = name;
        emp[i].second = salary;
    }
    sort(emp, emp+n, myCompare);
    for(int i=0;i<n;i++) {
        if(emp[i].second > min_salary)
            cout<<emp[i].first<<" "<<emp[i].second;
    }
    return 0;
}
