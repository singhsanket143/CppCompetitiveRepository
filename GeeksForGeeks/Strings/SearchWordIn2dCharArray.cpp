#include "iostream"
using namespace std;
#define R 3
#define C 14

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool search2d(char grid[R][C], int row, int col, string word) {
    if(grid[row][col] != word[0]) {
        return false;
    }
    int len = word.length();
    for(int dir = 0; dir < 8; dir++) {
        int k, rd = row+x[dir], cd = col+y[dir];
        for(k=1;k<len;k++) {
            if(rd >= R or rd < 0 or cd >= C or cd < 0){
                break;
            }
            if(grid[rd][cd] != word[k]){
                break;
            }
            rd += x[dir], cd += y[dir];
        }
        if(k == len) {
            return true;
        }
    }
    return false;
}

void patternSearch(char grid[R][C], string word) {
    for(int row=0;row<R;row++) {
        for(int col=0;col<C;col++) {
            if(search2d(grid, row, col, word)) {
                cout << "Pateern found at" << row << " , " << col <<endl;
            }
        }
    }
}

int main(int argc, char* argv[])
{

    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"
                      };

    patternSearch(grid, "GEEKS");
    cout << endl;
    patternSearch(grid, "EEE");

    return 0;
}
