#include<iostream>
#include<queue>
#include<cmath>
#include <stack>
#include <map>
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

int count(node*root){
	if(root==NULL){
		return 0;
	}
	int c1 = count(root->left);
	int c2 = count(root->right);
	return 1 + c1 + c2;
}

int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2) + 1;
}

void printAtLevelK(node*root,int k){
	//Base Case
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
	}

	//Rec Case
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
}

//Tree Sum
int sum(node*root){

	if(root==NULL){
		return 0;
	}
	return root->data + sum(root->left) + sum(root->right);

}

//Replace Sum
int replaceChildSum(node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}

	int leftSum = replaceChildSum(root->left);
	int rightSum = replaceChildSum(root->right);

	int temp = root->data;
	root->data = leftSum  + rightSum;
	//	*(root).data = 
	return temp+root->data;
}

void printLevelOrder(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();

		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}

		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}

	}

}

void printLevelOrder1(node*root){

	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* f = q.front();
		cout<<f->data<<" ";
		q.pop();
		if(f->left) {
			q.push(f->left);
		}
		if(f->right) {
			q.push(f->right);
		}

	}

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


void mirror(node* root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

pair<int,bool> isBalanced(node*root){
	pair<int,bool> p,left,right;

	if(root==NULL){
		p.first = 0;
		p.second = true;
		return p;
	}

	//Rec Case
	left = isBalanced(root->left);
	right = isBalanced(root->right);

	int h = max(left.first,right.first) + 1;

	if(abs(left.first-right.first)<=1 and left.second and right.second){
		return make_pair(h,true);
	}
	return make_pair(h,false);

}

void InorderIterative(node *root) {
	stack<node *> s;
	node *curr = root;
	while(curr != NULL or s.empty()==false) {
		while(curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout<<curr->data<<" ";
		curr = curr->right;
	}
}
void PreorderIterative(node *root) {
	stack<node *> s;
	s.push(root);
	while(s.empty()==false) {
		
		node *curr = s.top();
		s.pop();
		cout<<curr->data<<" ";
		if(curr->right)
			s.push(curr->right);
		if(curr->left)
			s.push(curr->left);
	}
}

void PostorderIterative(node *root) { // Using Two Stacks
	stack<node *> s1;
	stack<node *> s2;
	s1.push(root);
	while(s1.empty()==false) {
		
		node *curr = s1.top();
		s1.pop();
		s2.push(curr);
		
		
		if(curr->left)
			s1.push(curr->left);
		if(curr->right)
			s1.push(curr->right);
		while(s2.empty()==false) {
			node *curr1 = s2.top();
			s2.pop();
			cout<<curr1->data<<" ";
		}
	}
}

void PostorderIterative1(node *root) { // Using One Stack
	
	stack<node *> stack;
	while(true) { 
            while(root != NULL) { 
                stack.push(root); 
                stack.push(root); 
                root = root->left; 
            } 
              
            // Check for empty stack 
            if(stack.empty()) return; 
            root = stack.top(); 
            stack.pop();
              
            if(!stack.empty() && stack.top() == root) 
            	root = root->right; 
              
            else { 
                  
                cout<<root->data<<" "; root = NULL; 
            } 
        } 
}

int diameter(node *root) {
	if(root == NULL) {
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1+h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1, max(op2, op3));
}

// Class for diameter btr

class Pair {
public:
	int height;
	int diameter;
};
Pair diameterBtr(node *root) {
	Pair p;
	if(root==NULL) {
		p.height = p.diameter = 0;
		return p;
	}
	Pair left = diameterBtr(root->left);
	Pair right = diameterBtr(root->right);

	p.height = max(left.height, right.height)+1;
	p.diameter = max(left.height, max(right.height, left.height+right.height));
	return p;
}

void levelOrderZigZag(node *root) {
	stack<node *> s1;
	stack<node *> s2;
	bool leftOrRight = true;
	s1.push(root);
	while(!s1.empty() or !s2.empty()) {
		int row = 0;
		if(s1.size() > s2.size()) {
			row = s1.size();
		} else {
			row = s2.size();
		}
		while(row--) {
			if(leftOrRight) {
				node *curr = s1.top();
				s1.pop();
				cout<<curr->data<<" ";
				if(curr->left)
					s2.push(curr->left);
				if(curr->right)
					s2.push(curr->right);
			} else {
				node *curr = s2.top();
				s2.pop();
				cout<<curr->data<<" ";
				if(curr->right)
					s1.push(curr->right);
				if(curr->left)
					s1.push(curr->left);
			}
		}
		leftOrRight = !leftOrRight;
	}
}

int subTreesWithSumX(node *root, int &count, int X) {
	if(root == NULL) {
		return 0;
	}

	int rs = subTreesWithSumX(root->right, count, X);
	int ls = subTreesWithSumX(root->left, count, X);
	int sum = ls+rs+root->data;
	if(sum == X) {
		count++;
	}
	return sum;
}
bool find(node* root, int val){
    if (!root)
    	return false;
    if (root->data == val)
        return true;
    if ((root->left && find(root->left, val)) || 
        (root->right && find(root->right, val)))
        return true;
    return false;
}
node* LCA(node *root, int n1, int n2) {
	if(root == NULL) {
		return NULL;
	}
	if(root->data == n1 or root->data == n2) {
		return root;
	}
	node *leftLCA = LCA(root->left, n1, n2);
	node *rightLCA = LCA(root->right, n1, n2);
	if(leftLCA!=NULL and rightLCA!=NULL) {
		return root;
	} else if(leftLCA!=NULL) {
		return leftLCA;
	} else {
		return rightLCA;
	}
}

void rightViewHelper(node *root, int level, int &max_level) {
	if(root == NULL) {
		return;
	}
	if(max_level<level) {
		cout<<root->data<<" ";
		max_level = level;
	}
	rightViewHelper(root->right, level+1, max_level);
	rightViewHelper(root->left, level+1, max_level);
}

void rightView(node *root) {
	int max_level = 0;
	rightViewHelper(root, 1, max_level);
}

void leftViewHelper(node *root, int level, int &max_level) {
	if(root == NULL) {
		return;
	}
	if(max_level<level) {
		cout<<root->data<<" ";
		max_level = level;
	}
	leftViewHelper(root->left, level+1, max_level);
	leftViewHelper(root->right, level+1, max_level);
}

void leftView(node *root) {
	int max_level = 0;
	leftViewHelper(root, 1, max_level);
}

void bottomView1(node *root, int level, int dist, map<int, pair<int, int> > &mp) {
	if(root == NULL) {
		return;
	}
	if(mp.find(dist) == mp.end() or level>=mp[dist].second) {
		mp[dist] = {root->data, level};
	}
	bottomView1(root->left, level+1, dist-1, mp);
	bottomView1(root->right, level+1, dist+1, mp);
}
void bottomView(node *root)
{
   map<int, pair<int, int> >mp;
   bottomView1(root, 0, 0, mp);
   for(auto val:mp){
       cout<<val.second.first<<" ";
   }
}

void topView1(node *root, int level, int dist, map<int, pair<int, int> > &mp) {
	if(root == NULL) {
		return;
	}
	if(mp.find(dist) == mp.end() or level<mp[dist].second) {
		mp[dist] = {root->data, level};
	}
	topView1(root->left, level+1, dist-1, mp);
	topView1(root->right, level+1, dist+1, mp);
}
void topView(node *root)
{
   map<int, pair<int, int> >mp;
   topView1(root, 0, 0, mp);
   for(auto val:mp){
       cout<<val.second.first<<" ";
   }
}

void topViewIterative(node *root) {
	queue<pair<node *, int>> qu;
	qu.push({root, 0});
	map<int, int>mp;
	while(!qu.empty()) {
		node* temp = qu.front().first;
		int dist = qu.front().second;
		qu.pop();
		if(mp.find(dist) == mp.end()) {
			cout<<temp->data<<" ";
			mp[dist] = temp->data;
		}
		if(temp->left) {
			qu.push({temp->left, dist-1});
		}
		if(temp->right) {
			qu.push({temp->right, dist+1});
		}
	}
}

int treePathsSumHelper(node *root, int val) { 
    if (root == NULL)  
    	return 0; 
    val = (val*10 + root->data);

    if (root->left==NULL && root->right==NULL) 
       return val; 

    return treePathsSumHelper(root->left, val) + treePathsSumHelper(root->right, val); 
} 
  
int treePathsSum(node *root) { 
    return treePathsSumHelper(root, 0); 
} 

int areTreesIdentical(node *root1, node *root2) {
	if(root1==NULL and root2==NULL) {
		return 1;
	}
	if(root1!=NULL and root2!=NULL) {
		int leftAns = areTreesIdentical(root1->left, root2->left);
		int rightAns = areTreesIdentical(root1->right, root2->right);
		return (root1->data and root2->data) and leftAns and rightAns;
	}
	return 0;
}

int areTreesStructurallyIdentical(node *root1, node *root2) {
	if(root1==NULL and root2==NULL) {
		return 1;
	}
	if(root1!=NULL and root2!=NULL) {
		int leftAns = areTreesStructurallyIdentical(root1->left, root2->left);
		int rightAns = areTreesStructurallyIdentical(root1->right, root2->right);
		return leftAns and rightAns;
	}
	return 0;
}

int sumAtLevelK(node *root, int k) {
	if(root==NULL) {
		return 0;
	}
	if(k<=0) {
		return root->data;
	}
	int leftAns = sumAtLevelK(root->left, k-1);
	int rightAns = sumAtLevelK(root->right, k-1);
	return leftAns+rightAns;
}

int main(){
	node*root = buildLevelOrder();//buildRec();
	// printPre(root);
	// cout<<endl;
	// cout<<count(root)<<endl;
	// cout<<height(root)<<endl;
	//printAtLevelK(root,2);

	//replaceChildSum(root);
	//printPre(root);
	// printLevelOrder(root);
	// levelOrderZigZag(root);
	topView(root);


	return 0;
}