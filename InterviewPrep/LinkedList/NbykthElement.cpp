#include<iostream>
#include<math.h>
using namespace std;

// Class declaration for a Node of the Linked List
class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node* head1;

/*
 * Input Parameters: head: head of the linked list in which a new node is to
 * be inserted. data: the data value of the node which is to be inserted.
 *
 * Return Value: head of the linked list in which the node is inserted
 */
Node* insert(Node* head, int data) {

  if (head == NULL) {
    Node* nn = new Node(data);
    return nn;
  }

  head->next = insert(head->next, data);
  return head;
}

void display(Node* head) {
  for (Node* node = head; node != NULL; node = node->next) {
    cout << node->data << " ";
  }
}

// -----------------------------------------------------
// This is a functional problem. You have to complete this function.
// This function takes as input the head of the linked list and k.
// It should return the data of n/k th node.
int nknode(Node* head, int k) {
  // write your code here.
  int i = 0;
  Node *fractional = NULL;
  for(Node *temp = head;temp!=NULL;temp = temp->next) {
    if(i%k == 0) {
      if(fractional == NULL) {
        fractional = head;
      } else {
        fractional = fractional->next;
      }
    }
    i++;
  }
  return fractional;
}

// -----------------------------------------------------

int main(int argc, char** argv) {
  int n1;
  cin >> n1;

  for (int i = 0; i < n1; i++) {
    int a;
    cin >> a;
    head1 = insert(head1, a);
  }

  int k;
  cin >> k;
  cout << nknode(head1, k);

}