#include<iostream>

struct Player {
    int score;
    std::string name;
    float rating;
};

int main() {
    int i = 10;
    float f = 10.9;
    char ch = 'd';
    bool b = true;
    long long int lli = 2923234;
    std::string str = "This is text";



    std::cout<<i<<" "<<f<<" "<<ch<<" "<<b<<" "<<lli<<"\n";


    Player p1;
    p1.name = "Sanket";
    p1.score = 0;
    p1.rating = 5.0;

    std::cout<<p1.name<<" "<<p1.score<<"\n";
    return 0;
}