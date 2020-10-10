#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	// construtor
	Node(int val) {
		this->data = val;
		this->next = NULL;
	}
};
////
void insertAtHead(Node *&head, int data) {
	Node* new_node = new Node(data);
	new_node->next = head;
	head = new_node;
}

void insertAtTail(Node *&head, int data) {
	Node *tail = head;
	while(tail->next!=NULL) {
		tail = tail->next;
	}
	Node* new_node = new Node(data);
	tail->next = new_node;
	return;
}

void insertAtPos(Node *&head, int data, int pos) {
	if(pos == 0) {
		insertAtHead(head, data);
		return;
	}
	int i = 0;
	Node *temp = head;
	while(i<pos-1) {
		temp = temp->next;
		i++;
	}
	Node *new_node = new Node(data);
	new_node->next = temp->next;
	temp->next = new_node;
}

void deleteAtHead(Node *&head) {
	Node *temp = head;
	head = head->next;
	temp->next = NULL;
	delete temp;
}

void deleteAtTail(Node *&head) {
	Node *tail = head;
	while(tail->next->next!=NULL) {
		tail = tail->next;
	}
	Node *temp = tail->next;
	tail->next = NULL;
	delete temp;
	return;
}

void deleteAtPos(Node *&head, int pos) {
	if(pos == 0) {
		deleteAtHead(head);
		return;
	}
	int i = 0;
	Node *temp = head;
	while(i<pos-1) {
		temp = temp->next;
		i++;
	}
	Node *to_be_del = temp->next;
	temp->next = temp->next->next;
	to_be_del->next = NULL;
	delete to_be_del;
	return;

}

Node* midNode(Node *head) {
	Node *slow = head;
	Node *fast = head;
	while(fast->next!=NULL and fast->next->next!=NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
} 

void display(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout<<"\n";
}

void reversePI(Node *&head) {
	Node *prev = NULL;
	Node *curr = head;
	Node *Next;
	while(curr!=NULL) {
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}
	head = prev;
	return;
}

Node* reversePR(Node *head) {
	if(head->next == NULL) {
		return head;
	}
	Node *smallHead = reversePR(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
} 

void reverseDR1(Node *&head, Node *tail, bool &flag) {
	if(flag == true) {
		return;
	}
	if(tail == NULL) {
		return;
	}
	reverseDR1(head, tail->next, flag);
	if(flag == false and head!=tail and head->next!=tail) {
		int temp = head->data;
		head->data = tail->data;
		tail->data = temp;
		head = head->next;
	} else if((head==tail or head->next == tail) and flag == false) {
		int temp = head->data;
		head->data = tail->data;
		tail->data = temp;
		flag = true;
	} 
} 

int main(int argc, char const *argv[])
{
	/* code */
	Node *head;
	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);
	insertAtHead(head, 60);
	insertAtHead(head, 70);
	insertAtHead(head, 80);
	display(head);
	reversePI(head);
	display(head);
	head = reversePR(head);
	display(head);
	Node *temp = head;
	bool flag = false;
	Node *heapmover = head;
	reverseDR1(heapmover, head, flag);
	display(head);
	return 0;
}