#include <iostream>
using namespace std;

int test(char *str) {

	int start=1, max_current = 0, length=0, max_length=0, max_position=0, max_length_position=0;
	int  current = 0;
	char temp;
	for(long long i=0;str[i]!='\0';i++) {
		temp = str[i];
		if(temp == '[' or temp == '{' or temp=='(') {
			current++;
			length++;
			if(current > max_current) {
				max_current = current;
				max_position = i+1;
			}
		} else if(temp==']' or temp=='}' or temp==')') {
			current--;
			length++;
			if(current==0) {
				if(length > max_length) {
					max_length = length;
					max_length_position = start;
				}
				length = 0;
				start = i+2;
			}
		}
	}
	return max_current;
}
