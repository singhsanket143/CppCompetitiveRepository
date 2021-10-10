#include<iostream>

void waveprint(int **arr, int n, int m) {
    for(int col = 0; col < m; col++) {
        if(col%2 == 0) {
            // even
            for(int row = 0; row < n; row++) {
                std::cout<<arr[row][col]<< " ";
            }
        } else {
            // odd
            for(int row = n-1; row >= 0; row--) {
                std::cout<<arr[row][col]<< " ";
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    std::cin>>n>>m;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin>>arr[i][j];
        }
    }
    waveprint(arr, n, m);
    return 0;
}
