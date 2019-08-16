#include <iostream>
using namespace std;

int row[] = {0, -1, 1, 0, 0};
int col[] = {0, 0, 0, -1, 1};

int getCountDP(char keypad[][3],int n) {
	if(keypad == NULL or n <= 0) return 0;
	if(n == 1) return 10;
	int count[10][n+1];
	for(int i=0;i<10;i++) {
		count[i][0] = 0;
		count[i][1] = 1;
	}
	for(int k=2;k<=n;k++) {
		for(int i=0;i<4;i++) {
			for(int j=0;j<3;j++) {
				if(keypad[i][j]!='*' and keypad[i][j]!='#') {
					int num = keypad[i][j] - '0';
					count[num][k]=0;
					for(int move=0;move<5;move++) {
						int ro = i+row[move];
						int co = j+col[move];
						if(ro>=0 and ro<=3 and co>=0 and co<=2 and keypad[ro][co]!='*' and keypad[i][j]!='#') {
							int newNum = keypad[ro][co] - '0';
							count[num][k] += count[newNum][k-1];
						}
					}
				}
			}
		}
	}
	int total= 0;
	for(int i=0;i<=9;i++) {
		total+=count[i][n];
	}
	return total;
}


int getCountUtil(char keypad[][3], int i, int j, int n) {
	if(keypad == NULL or n<=0) {
		return 0;
	}
	if(n==1) return 1;
	int move = 0, ro = 0, co = 0, totalCount = 0;
	for(move = 0; move < 5;  move++) {
		ro = i + row[move];
		co = j + col[move];
		if(ro >= 0 and ro <= 3 and co >=0 and co <= 2 and keypad[ro][co]!='*' and keypad[ro][co]!='#') {
			totalCount += getCountUtil(keypad, ro, co, n-1);
		}
	}
	return totalCount;
}

int getCount(char keypad[][3], int n) {
	if(keypad == NULL or n<=0) return 0;
	if(n==1) return 10;
	int totalCount = 0;
	for(int i=0;i<=3;i++) {
		for(int j=0;j<=2;j++) {
			if(keypad[i][j] != '*' and keypad[i][j] != '#') {
				totalCount += getCountUtil(keypad, i, j, n);
			}
		}
	}
	return totalCount;
}

int main(int argc, char const *argv[])
{
	char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 

    cout<<getCount(keypad, 3)<<endl;
    cout<<getCountDP(keypad, 3);
	return 0;
}
