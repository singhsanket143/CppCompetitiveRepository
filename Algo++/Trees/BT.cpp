#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
//------------Node Class
class node{
public:
	int data;
	node* left;
	node* right;


	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//------------Binary Tree 


 node *buildRec(){
 	//Read the input
 	int d;
 	cin>>d;

 	//Base Case
 	if(d==-1){
 		return NULL;
 	}
 	//Recursive Case
 	node* root = new node(d);
 	root->left = buildRec();
 	root->right = buildRec();
 	return root;
 }

void printPre(node *root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		printPre(root->left);
		printPre(root->right);
}
void printIn(node *root){
		if(root==NULL){
			return;
		}
		
		printIn(root->left);
		cout<<root->data<<" ";
		printIn(root->right);
}
void printPost(node *root){
		if(root==NULL){
			return;
		}
		
		printPost(root->left);
		printPost(root->right);
		cout<<root->data<<" ";
}


node* buildLevelOrder(){

	node*root;
	int d;
	cin>>d;

	root = new node(d);
	queue<node*> q;

	q.push(root);

	while(!q.empty()){

		node* f = q.front();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left  = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
		q.pop();
	}
	return root;
}


int main(){
	node*root = buildLevelOrder();//buildRec();
	printPre(root);
	cout<<endl;
	printLevelOrder(root);


	return 0;
}