#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    float num = 365;
    float denom = 365;
    float p = 1;
    int num_of_persons = 0;
    while(p>0.5) { // For 50 % probability for 90% change 0.5 to 0.1
        p = p*(num/denom);
        num--;
        num_of_persons++;
    }
    cout<<num_of_persons<<endl;

    return 0;
}
