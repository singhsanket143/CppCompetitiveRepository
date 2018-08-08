#include "iostream"
using namespace std;

int linearSearch(int arr[], int n, int key) {
    int result = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            result = i;
            break;
        }
    }
    return result;
}

int main(int argc, char* argv[])
{

    
    return 0;
}
