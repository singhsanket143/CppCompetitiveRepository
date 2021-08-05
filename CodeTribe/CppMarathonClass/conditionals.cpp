#include<iostream>

int main() {
    int x = 10;
    if (100 < 13) {
        // if the conditions is true then this area will be executed
        x++;
    } else if (12 > 6) {
        x *= 2;
    } else if(3 > 1) {
        x /= 2;
    }
    else {
       x--; 
    }
    std::cout<<x<<"\n";
    return 0;
}