#include "iostream"
#include "map"
#include "iterator"
using namespace std;

void findDifference(int arr[], int n, int diff) {
    map<int, int> hashmap;

    for(int i=0;i<n;i++) {
        hashmap.insert(pair<int, int> (arr[i], 1));
    }
    for(int i=0;i<n;i++) {
        if(hashmap.find(abs(diff-arr[i]))!=hashmap.end()) {
            cout<<diff-arr[i]<<" and "<<arr[i]<<endl;
            return;
        }
    }
    cout<<"No such pair";
}
int main(int argc, char* argv[])
{
    int arr[] = {5, 20, 3, 2, 50, 80};
    int diff = 78;

    findDifference(arr, 6, diff);

    int arr2[] = {90, 70, 20, 80, 50};
    diff = 45;
    findDifference(arr2, 5, diff);
    return 0;
}
