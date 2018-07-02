#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    int n, key;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cin>>key;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            std::cout << i << "\n";
            break;
        }
    }
    return 0;
}
