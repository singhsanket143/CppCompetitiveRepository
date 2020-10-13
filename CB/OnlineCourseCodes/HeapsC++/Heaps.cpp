#include<iostream>
#include<vector>
using namespace std;
// Max Heap
void upheapify(vector<int> &heap, int idx) {
	if(idx == 0) {
		return;
	}
	int parentIdx = (idx - 1)/2;
	if(heap[parentIdx] < heap[idx]) {
		// Swap
		int temp = heap[parentIdx];
		heap[parentIdx] = heap[idx];
		heap[idx] = temp;
		upheapify(heap, parentIdx);
	} else {
		return;
	}
}

void downHeapify(vector<int> &heap, int idx) {
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= heap.size() and rightIdx >= heap.size()) {
		return;
	}
	int largestIdx = idx;
	if(leftIdx < heap.size() and heap[leftIdx] > heap[largestIdx]) {
		largestIdx = leftIdx;
	}
	if(rightIdx < heap.size() and heap[rightIdx] > heap[largestIdx]) {
		largestIdx = rightIdx;
	}
	if(largestIdx == idx) return;
	swap(heap[idx], heap[largestIdx]);
	downHeapify(heap, largestIdx);
}

void deletePeek(vector<int> &heap) {
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	downHeapify(heap, 0);
}

void insert(vector<int> &heap, int key) {
	heap.push_back(key);
	upheapify(heap, heap.size() - 1);
}

void buildHeap(vector<int> &heap) {
	for(int i = 0; i < heap.size(); i++) {
		upheapify(heap, i);
	}
}

void buildHeapOptimized(vector<int> &heap) {
	for(int  i = heap.size() - 1; i >= 0; i--) {
		downHeapify(heap, i);
	}
}

void display(vector<int> &heap) {
	for(int i = 0; i < heap.size(); i++) {
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

void downHeapifyHelper(vector<int> &heap, int idx, int heapSize) {
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= heapSize and rightIdx >= heapSize) {
		return;
	}
	int largestIdx = idx;
	if(leftIdx < heapSize and heap[leftIdx] > heap[largestIdx]) {
		largestIdx = leftIdx;
	}
	if(rightIdx < heapSize and heap[rightIdx] > heap[largestIdx]) {
		largestIdx = rightIdx;
	}
	if(largestIdx == idx) return;
	swap(heap[idx], heap[largestIdx]);
	downHeapifyHelper(heap, largestIdx, heapSize);
}
void heapSort(vector<int> &arr) {
	int heapSize = arr.size();
	buildHeapOptimized(arr);
	for(int i = arr.size() - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapSize-=1;
		downHeapifyHelper(arr, 0, heapSize);
	}
}


int main(int argc, char const *argv[])
{
	vector<int> arr;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		int x;
		cin>>x;
		arr.push_back(x);
		upheapify(arr, i);
	}
	//buildHeapOptimized(arr);
	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}