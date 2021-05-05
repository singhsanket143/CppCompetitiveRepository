#include<bits/stdc++.h>
#include <memory>
using namespace std;
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

struct Player {
    
	int x, y;
    void display() {
        cout<<x<<" "<<y<<endl;
    }
	~Player() {
		cout<<"Player destructed"<<endl;
	}
};

int main(int argc, char const *argv[]) {
	file_i_o();
	// Write your code here....

	{
    	unique_ptr<Player> ptr1 = make_unique<Player>(); // created in heap
    // 	cout<<ptr1.use_count()<<endl;
        // Player* ptr1 = new Player; // created in heap
    	ptr1->x = 10;
    	ptr1->y = 20;
    	ptr1->display();
    // 	unique_ptr<Player> ptr2 = ptr1; doesn't work
        shared_ptr<Player> ptr2 = make_shared<Player>();
        cout<<ptr2.use_count()<<endl;
        shared_ptr<Player> ptr3 = ptr2;
        cout<<ptr2.use_count()<<endl;
        cout<<ptr3.use_count()<<endl;
        weak_ptr<Player> ptw(ptr3); // we can create using another shared or a weak
        cout<<ptw.use_count()<<endl;
        cout<<ptw.expired()<<endl;
    }
    struct Player p1;
	return 0;
}
