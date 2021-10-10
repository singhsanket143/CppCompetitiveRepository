#include<iostream>

void print(int n, int m, int **arr) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

const int M = 4;
const int N = 3;
void print1(int arr[][M]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    // <type> <name> [no_of_rows][no_of_cols];
    // int arr[][M] = {{1,2,3,4}, {1,2,3,4}, {1,2,3,4}};

    // set the value of any cell ->  the rows and cols are 0 based indexed
    // arr[0][0] = 10;
    // std::cout<<arr[0][0];

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         std::cin>>arr[i][j];
    //     }
    // }

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         std::cout<<arr[i][j]<<" ";
    //     }
    //     std::cout<<"\n";
    // }

    // int** p = new int*[3]; // will only create your primary array

    // for(int i = 0; i < 3; i++) {
    //     p[i] = new int[4]();
    // }

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         std::cin>>arr[i][j];
    //     }
    // }


    int arr[3][4];
    print1(arr);
    

    return 0;
}
