#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
public:
	int data;
	Node *next;

	// Constructor
	Node(int d) {
		data = d;
		next = NULL;
	}
};

int length(Node *head) {
	int len = 0;
	while(head != NULL) {
		head = head->next;
		len += 1;
	}
	return len;
}

// Passing a pointer variable by reference
void insertAtHead(Node *&head, int data) {
	Node *n = new Node(data);
	n->next = head;
	head = n;
}

void insertAtTail(Node *&head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	Node *tail = head;
	while(tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new Node(data);
	return;
}

void insertAtMiddle(Node*&head, int data, int pos) {
	if(head == NULL or pos == 0) {
		insertAtHead(head, data);
		return;
	} else if(pos > length(head)) {
		insertAtTail(head, data);
		return;
	} else {
		// Insert in the middle
		// Take P-1 Jumps
		int jump = 1;
		Node *temp = head;
		while(jump <= pos-1) {
			temp = temp->next;
			jump += 1;
		}
		Node *n = new Node(data);
		n->next = temp->next;
		temp->next = n;
		return;
	}
}

void deleteAtHead(Node *&head) {
	if(head == NULL) {
		return;
	}
	Node *temp = head;
	head = head->next;
	delete temp;
	return;
}

void deleteAtTail(Node *&head) {
	Node *temp = head;
	Node *prev = NULL;
	while(temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
	return;
}

void deleteAtMiddle(Node *&head, int pos) {
	if(head == NULL) {
		return;
	}
	if(pos == 0) {
		deleteAtHead(head);
	}
	if(pos > length(head)) {
		deleteAtTail(head);
	}
	int jump = 1;
	Node *temp = head;
	Node *prev = NULL;
	while(jump <= pos-1) {
		prev = temp;
		temp = temp->next;
		jump += 1;
	}
	prev->next = temp->next;
	delete temp;
	return;
}

bool searchRecursive(Node *head, int key) {
	if(head == NULL) {
		return false;
	}
	if(head->data == key) {
		return true;
	} else {
		return searchRecursive(head->next, key);
	}
}

bool searchIterative(Node *head, int key) {
	while(head != NULL) {
		if(head->data == key) {
			return true;
		}
		head = head->next;
	}
	return false;
}

void reversePointerIterative(Node *&head) {
	Node *curr = head;
	Node *prev = NULL;
	Node *N;
	while(curr != NULL) {
		N = curr->next;
		curr->next = prev;
		prev = curr;
		curr = N;
	}
	head = prev;
}

Node* reversePointerRecursive(Node *head) {
	if(head == NULL or head->next == NULL) {
		return head;
	} 
	Node *smallHead = reversePointerRecursive(head->next);
	Node *c = head;
	head->next->next = head;
	head->next = NULL;
	return smallHead;
}

Node* midPoint(Node *head) {
	if(head == NULL or head->next ==  NULL) {
		return head;
	}
	Node *slow = head;
	Node *fast = head->next;
	while(fast!=NULL and fast->next!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void removeDuplicates(Node *&head) {

	Node* prev = NULL;
	Node* curr = head;
	unordered_set<int> seen;
	while(curr != NULL) {
		if(seen.find(curr->data) != seen.end()) {
			prev->next = curr->next;
			delete curr;
		} else {
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
	}
}

void deleteNodeWithGreaterValueOnRight(Node *&head) {
	reversePointerIterative(head);
	int max = head->data;
	int pos = 2;
	Node* curr = head->next;
	Node* prev = head;
	while(curr!= NULL) {
		if(curr->data < max) {
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
			curr = prev->next;
		} else {
			prev = curr;
			max = curr->data;
			curr = curr->next;
		}
	}
	reversePointerIterative(head);
}

Node* sameSizeLLSum(Node* head1, Node* head2, int* carry) {
	if(head1 == NULL or head2 == NULL) {
		return NULL;
	}
	int sum;
	Node* result = new Node(0);
	result->next = sameSizeLLSum(head1->next, head2->next, carry);
	sum = head1->data + head2->data + *carry;
	*carry = sum/10;
	sum = sum%10;
	result->data = sum;
	return result;
}

Node* getTail(Node *head) {
	while(head != NULL and head->next != NULL) head = head->next;
	return head;
}

Node* partition(Node* head, Node* end, Node *&newHead, Node *&newTail) {
	Node *pivot = end;
	Node *prev = NULL, *curr = head, *tail = pivot;
	while(curr != pivot) {
		if(curr->data <= pivot->data) {
			if(newHead == NULL) {
				newHead = curr;
			}
			prev = curr;
			curr = curr->next;
		} else {
			if(prev) {
				prev->next = curr->next;
			}
			Node *temp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = temp;
		}
	}
	if(newHead == NULL) {
		newHead = pivot;
	}
	newTail = tail;
	return pivot;
}

Node* quicksortRecur(Node *head, Node *end) {
	if(not head or head == end) {
		return head;
	}
	Node *newHead = NULL, *newTail = NULL;
	Node *pivot = partition(head, end, newHead, newTail);
	if(newHead != pivot) {
		Node *temp = head;
		while(temp->next != pivot) {
			temp = temp->next;
		}
		temp->next = NULL;
		newHead = quicksortRecur(newHead, temp);
		temp = getTail(newHead);
		temp->next = pivot;
	}
	pivot->next = quicksortRecur(pivot->next, newTail);
	return newHead;
}

void quicksort(Node *&head) {
	head = quicksortRecur(head, getTail(head));
	return;
}

void rearrangeInplace(Node *&head) {
	Node* mid = midPoint(head);
	Node* head1 = head;
	Node* head2 = mid->next;
	mid->next = NULL;
	reversePointerIterative(head2);
	head = new Node(0);
	Node *curr = head;
	while(head1 or head2) {
		if(head1) {
			curr->next = head1;
			curr = curr->next;
			head1 = head1->next;
		}
		if(head2) {
			curr->next = head2;
			curr = curr->next;
			head2 = head2->next;
		}
	}
	head = head->next;
}

void zigzag(Node *&head) {
	bool flag = true;
	Node* current = head;
	while(current->next != NULL) {
		if(flag) {
			if(current->data > current->next->data) {
				swap(current->data, current->next->data);
			}
		} else {
			if(current->data < current->next->data) {
				swap(current->data, current->next->data);
			}
		}
		current = current->next;
		flag = !flag;
	}
}

void sortList(Node *&head) {
	Node *prev = head;
	Node *curr = head->next;
	while(curr != NULL) {
		if(curr->data < prev->data) {
			prev->next = curr->next;
			curr->next = head;
			head = curr;
			curr = prev;
		} else {
			prev = curr;
		}
		curr = curr->next;
	}
}

Node* merge(Node *a, Node *b) {
	if(a == NULL) {
		return b;
	} else if(b == NULL) {
		return a;
	}

	Node *c;
	if(a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	} else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

Node* mergeSort(Node *head) {
	if(head == NULL or head->next == NULL) {
		return head;
	}
	Node* mid = midPoint(head);
	Node* a = head;
	Node* b = mid->next;
	mid->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);
	Node* c = merge(a, b);
	return c;
}

bool detectCycle(Node *head) {
	Node *slow = head;
	Node *fast = head;
	while(fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) {
			return true;
		}
	}
	return false;

}
// Here head is passed by value so a copy is made and the original head is not disturbed
void print(Node *head) {
	while(head != NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
}

void buildList(Node *&head) {
	int data;
	cin>>data;
	while(data!=-1) {
		insertAtTail(head, data);
		cin>>data;
	}
}

istream& operator>>(istream &is, Node *&head) {
	buildList(head);
	return is;
}

ostream& operator<<(ostream &os, Node *&head) {
	print(head);
	return os;
}

int main(int argc, char const *argv[])
{
	Node *head = NULL;
	cin>>head;
	cout<<head<<endl;
	sortList(head);
	cout<<head<<endl;
	return 0;
}
