#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x;
   
    while( cin >> x){
        if(x < 3){ printf("-1\n");  continue; }
 
        if(x & 1)  printf("%d %d", (x*x-1)/2, (x*x+1)/2);
        else{
            x /= 2;
            printf("%d %d", x*x-1, x*x+1);
        }
    }
    return 0;
}