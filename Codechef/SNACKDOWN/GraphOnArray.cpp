#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int countcomponents(int **edges, int n) {
	bool visited[n];
	list<int> queue;
	vector<vector<int> > result;
	for(int j=0;j<n;j++) {
		if(visited[j])
			continue;
		queue.push_back(j);
		visited[j]=true;
		vector<int> a;
		while(!queue.empty()) {
			int currentVertex = queue.front();
			queue.pop_front();
			a.push_back(currentVertex);
			for(int i=0;i<n;i++) {
				if(i==currentVertex)
					continue;
				if(edges[currentVertex][i] == 1 and !visited[i]){
					queue.push_back(i);
					visited[i]=true;
				}
			}
		}
		result.push_back(a);
		if(result.size()>3)
			break;
	}
	// for(int i=0;i<result.size();i++) {
	// 	for(int j=0;j<result[i].size();j++) {
	// 		cout<<result[i][j]<<",";
	// 	}
	// 	cout<<endl;
	// }
	return result.size();
}

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

bool coprime(int a, int b) 
{    
    return (gcd(a, b) == 1); 
} 

bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

bool checkequal(int arr[], int n) {
	int first = arr[0];
	for(int i=1;i<n;i++) {
		if(arr[i]!=first) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		int **edges = new int*[n];
		for(int i=0;i<n;i++) {
			edges[i] = new int[n];
		}
		
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		if(n==1) {
			printf("0\n%d\n", arr[0]);
			continue;
		}
		if(n==2) {
			if(coprime(arr[0], arr[1])) {
				printf("0\n%d %d\n", arr[0], arr[1]);
				// cout<<"0\n"<<arr[0]<<" "<<arr[1]<<endl;
				continue;
			}
		}
		int count=0;
		
		if(checkequal(arr, n)) {
			if(arr[0] != 47) {
				arr[0] = 47;
			} else if(arr[0] != 2) {
				arr[0] = 2;
			}
			count++;
			printf("%d\n", count);
			for(int i=0;i<n;i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			continue;
		}
		set<int> s;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(coprime(arr[i], arr[j])) {
					// edges[i][j] = 1;
					// edges[j][i] = 1;
					set.push_back(arr[i]);
					break;
				}
			}
		}
		if(1) {
			// cout<<"IN"<<endl;
			printf("0\n");
			for(int i=0;i<n;i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		} else {
			arr[0] = 47;
			printf("1\n");
			for(int i=0;i<n;i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		
	}
	return 0;
}
