#include <iostream>
using namespace std;

void toh(string sT, string dT, string hT, int num) {
	if(num == 0) {
		return;
	}
	toh(sT, hT, dT, num - 1);
	//printf("Move %dth disc from %s to %s \n", num, sT.c_str(), dT.c_str());
	cout<<"Move "<<num<<"th disc from "<<sT<<" to "<<dT<<"\n";
	toh(hT, dT, sT, num - 1);
}
int main(int argc, char const *argv[])
{
	/* code */
	toh("T1", "T2", "T3", 4);
	return 0;
}
