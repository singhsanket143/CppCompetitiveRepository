#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater <int> > min_heap;
priority_queue<int> max_heap;
void add(int a)
{
    if( max_heap.size() && a >= max_heap.top())
        min_heap.push(a);
    else
        max_heap.push(a);

    if(fabs(max_heap.size() - min_heap.size()) > 1)
    {
        if(max_heap.size() > min_heap.size())
        {
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
        else
        {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
    }
}

double get_median()
{
    int total = min_heap.size() + max_heap.size();
    double ret;
    if(total%2 == 1)
    {
        if(max_heap.size() > min_heap.size())
            ret = max_heap.top();
        else
            ret = min_heap.top();
    }
    else
    {
        ret = 0;
        if(max_heap.empty() == false)
            ret += max_heap.top();
        if(min_heap.empty() == false)
            ret += min_heap.top();
        ret/=2;
    }
    return ret;
}

int main()
{
    cout << setprecision(1) << fixed;
    int n;
    cin >> n;
    while(n!=0)
    {
        // cin >> a;
        if(n!=-1)
            add(n);
        else
            cout << get_median() << endl;
        cin>>n;
    }
}