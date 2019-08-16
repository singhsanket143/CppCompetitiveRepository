#include<iostream>
#include<vector>
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
// This is a functional problem. Only this function has to be written.
// This takes as input the head of the linked list

void linksort(Node* n) {
  //write your code here
  int zc = 0, oc = 0, tc = 0;
  Node *temp = n;
  while (temp != NULL) {
    if (temp->data == 0) {
      zc++;
    } else if (temp->data == 1) {
      oc++;
    } else {
      tc++;
    }
    temp = temp->next;
  }
  temp = n;
  while (zc--) {
    temp->data = 0;
    temp = temp->next;
  }
  while (oc--) {
    temp->data = 1;
    temp = temp->next;
  }
  while (tc--) {
    temp->data = 2;
    temp = temp->next;
  }


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

  linksort(head1);
  display(head1);

}
