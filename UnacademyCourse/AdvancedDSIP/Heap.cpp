#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void upheapify(vi &heap, int i) {
	if(i == 0) return;
	int pi = (i-1)/2;
	if(heap[pi] < heap[i]) {
		swap(heap[pi], heap[i]);
		upheapify(heap, pi);
	} else {
		return;
	}
}

void downheapify(vi &heap, int i) {
	int lc = 2*i+1;
	int rc = 2*i+2;
	if(lc >= heap.size() and rc >= heap.size()) return;
	int largest = i;
	if(lc < heap.size() and heap[lc] > heap[largest]) 
		largest = lc;
	if(rc < heap.size() and heap[rc] > heap[largest]) 
		largest = rc;

	if(largest == i) return;
	swap(heap[i], heap[largest]);
	downheapify(heap, largest);
}

void push(vi &heap, int x) {
	heap.push_back(x);
	upheapify(heap, heap.size()-1);
}

void pop(vi &heap) {
	swap(heap[0], heap[heap.size()-1]);
	heap.pop_back();
	downheapify(heap, 0);
}

int top(vi &heap) {
	if(heap.size() <= 0) {
		cout<<"Empty heap\n";
		return INT_MAX;
	}
	return heap[0];
}

void downheapifyHeapsortHelper(vi &heap, int i, int heapSize) {
	int lc = 2*i+1;
	int rc = 2*i+2;
	if(lc >= heapSize and rc >= heapSize) return;
	int largest = i;
	if(lc < heapSize and heap[lc] > heap[largest]) 
		largest = lc;
	if(rc < heapSize and heap[rc] > heap[largest]) 
		largest = rc;

	if(largest == i) return;
	swap(heap[i], heap[largest]);
	downheapifyHeapsortHelper(heap, largest, heapSize);
}

void builheap(vi &heap) {
	for(int i = heap.size() - 1; i >= 0; i--) {
		downheapify(heap, i);
	}
}

void heapsort(vi &heap) {
	int heapSize = heap.size();
	builheap(heap);
	for(int i = heap.size() - 1; i>= 0; i--) {
		swap(heap[0], heap[i]);
		heapSize-=1;
		downheapifyHeapsortHelper(heap, 0, heapSize);
	}
}

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


int main(int argc, char const *argv[])
{
	file_i_o();
	// vi heap;
	// int n;
	// cin>>n;
	// for(int i = 0; i < n; i++) {
	// 	int x;
	// 	cin>>x;
	// 	push(heap, x);
	// }
	// for(int i = 0; i < heap.size(); i++) {
	// 	cout<<heap[i]<<" ";
	// }
	// cout<<endl;
	int n;
	cin>>n;
	vi arr(n);
	for(int i =0; i < n; i++) cin>>arr[i];
	heapsort(arr);
	for(int i =0; i < n; i++) cout<<arr[i]<<" ";
	return 0;
}
