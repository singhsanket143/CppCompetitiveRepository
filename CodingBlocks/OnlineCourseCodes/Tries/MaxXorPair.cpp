#include<iostream>
#include<math.h>
using namespace std;

class trieNode {
public:
	trieNode *left; // Represents 0
	trieNode *right;// Represents 1
};

void insert(int n, trieNode *head) {
	trieNode *curr = head;
	for(int i = 31; i >=0; i--) {
		int bit = (n >> i) & 1;
		if(bit == 0) {
			if(curr->left == NULL) {
				curr->left = new trieNode();
			}
			curr = curr->left;
		} else {
			if(curr->right == NULL) {
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

int findMaxXorPair(trieNode *head, int *arr, int n, int el) {
	int max_xor = INT_MIN;
	trieNode *curr = head;
	int value = el;
	int curr_xor = 0;
	for(int j = 31; j >= 0; j--) {
		int b = (value >> j) & 1;
		if(b == 0) {
			// current bit is 0
			if(curr->right != NULL) {
				curr = curr->right;
				curr_xor += (int)pow(2, j);
			} else {
				curr = curr->left;
			}
		} else {
			// current bit is 1
			if(curr->left != NULL) {
				curr = curr->left;
				curr_xor += (int)pow(2, j);
			} else {
				curr = curr->right;
			}
		}
	}
	if(curr_xor > max_xor) max_xor = curr_xor;
	return max_xor;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* arr = new int[n]();
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	trieNode *head = new trieNode();
	int result = INT_MIN;
	for (int i = 0; i < n; i++) {
		insert(arr[i], head);
		int x = findMaxXorPair(head, arr, n, arr[i]);
		result = (result < x)?x:result;
	}
	cout<<result<<endl;
	return 0;
}