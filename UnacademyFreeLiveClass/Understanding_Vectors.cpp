// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	// Declaring vectors
	// vector<type> variable;
	vector<int> v1; // without default size and default value
	vector<int> v2(10); // with default size but not with default value
	vector<int> v3(10, 2); // with default size = 10 and default value = 2
	vector<int> v4 {10, 20, 30}; // array like inititalization
	vector<int> v5(v4.begin(), v4.end()); // initialize from other vector
	int arr[] = {1,2,3,4,5};
	vector<int> v6(arr, arr + 5);

	// Adding elements to vector

	vector<int> v;
	for(int i = 0; i < 5; i++) {
		v.push_back(i); // O(1) operation
	}
	// for(int i = 0; i < v5.size(); i++) {
	// 	cout<<v5[i]<<" ";
	// }
	cout<<endl;

	for(int i = 0; i < 5; i++) {
		v.emplace_back(i); //O(1) same for inbuilt data type as push back
	}
	for(int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}
	// cout<<endl;
	// emplace_back-> for user defined data type emplace directly creates an object in the vector
	// push_back ->for user defined types push creates a temporary object in memory then makes
	// a copy of it in vector, destroys the temp object and then stops
	// so for user defined types push back is a bit slow
	
	// auto iter = v.insert(v.begin(), 100); // insert accepts position as iterator
	// for(int i = 0; i < v.size(); i++) {
	// 	cout<<v[i]<<" ";
	// }
	cout<<endl;
	v.insert(iter, 10); // adding at custom iterator position
	iter = v.insert(v.begin() + 3, 120);
	for(int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	vector<int> toInsert {-1, -2, -3};
	v.insert(v.begin() + 1, {-1, -2, -3}); // adding a set of elements at a position
	v.insert(v.begin(), 3, 0); // adding 0 three times
	v.insert(v.end(), toInsert.begin(), toInsert.end()); // inserting another vector
	v.emplace(v.begin()+1,200); // works similar to insert with emplace capacity



	// Updating vector elements
	// v[2] = 22;


	// // Deleting vector elements
	// v.erase(v.end() - 1); // deleted last element
	// v.pop_back();


	// // print vector elements
	// for(auto el: v) { // for each kind of loop
	// 	cout<<el<<" ";
	// }
	// // cout<<endl;
	// // for(int i = 0; i < v.size(); i++) {
	// // 	cout<<v[i]<<" ";
	// // }
	cout<<endl;
	cout<<v[2]<<endl;
	cout<<v.at(7)<<endl;
	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	cout<<*(v.data()+1)<<endl; // this returns a pointer to the first element

	// Some more functions on vectors
	v.clear();; // removes all elements
	v.empty(); // checks if the vector is empty;
	v.capacity(); // returns the capacity not the size
	v.size(); // returns the size not the capactiy
	v.max_size(); // Returns the maximum number of elements that the vector can hold.


	// Compare two vectors
	vector<bool> x;
	for(int i = 0; i < 5; i++) {
		x.push_back(true);
	}

	cout<<(x == vector<bool> (5, true)? "true" : "false");

	// HW explore all_of function for c++ vectors

	return 0;
}
