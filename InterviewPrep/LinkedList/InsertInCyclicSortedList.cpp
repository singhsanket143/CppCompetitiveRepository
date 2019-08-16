#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Class declaration for a Node of the Linked List
class Node
{
public:
  int data;
  Node *next;

  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

bool checkSortedCyclicAndSize(Node *head, unordered_map<int, int> &maporig)
{
  unordered_map<int, int> mapsol;
  if (head == NULL)
  {
    return true;
  }

  Node *curr = head;

  while (curr->next != NULL && curr->next != head)
  {
    if (curr->data > curr->next->data)
    {
      return false;
    }
    mapsol[curr->data]++;
    curr = curr->next;
  }
  mapsol[curr->data]++;
  if (curr->next != head)
  {
    return false;
  }

  for (auto itr = maporig.begin(); itr != maporig.end(); itr++)
  {
    if (mapsol[itr->first] != itr->second)
    {
      return false;
    }
  }

  return true;
}

Node *head1 = NULL;

/*
    * Input Parameters: head: head of the linked list in which a new node is to
    * be inserted. data: the data value of the node which is to be inserted.
    *
    * Return Value: head of the linked list in which the node is inserted
*/
Node *addLast(Node *head, Node *tail, int data)
{
  if (head == NULL)
  {
    Node *nn = new Node(data, NULL);
    nn->next = nn;
    return nn;
  }
  // add new node to next to tail and make new node's
  // next as head to maintain cyclic nature of linked list
  tail->next = new Node(data, head);
  return tail->next;
}

/*
    * Input Parameters: head: head of the cyclic linked list in which is to be
    * displayed.
    *
    * Return Value: NULL
*/
void display(Node *head)
{

  if (head == NULL)
  {
    return;
  }

  Node *curr = head;
  cout << curr->data << " ";
  curr = curr->next;

  while (curr != head)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }

  cout << endl;
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of the linked list and X.
// It should return the head of the modified list.

Node *insert(Node *head, int insertdata)
{
  // write your code here.
  Node *temp = head;
  bool done = false;
  while (temp->next != head) {
    if (insertdata >= temp->data and insertdata <= temp->next->data) {
      Node *new_node = new Node(insertdata, NULL);
      new_node->next = temp->next;
      temp->next = new_node;
      done = true;
      break;
    }
    temp = temp->next;
  }
  if (!done) {
    if (insertdata >= temp->data) {
      Node *new_node = new Node(insertdata, NULL);
      new_node->next = temp->next;
      temp->next = new_node;
      done = true;
    }
  }
  return head;

}

// -----------------------------------------------------

int main()
{
  unordered_map<int, int> map;

  int n1 = 0;
  int a1 = 0;
  cin >> n1 >> a1;
  map[a1]++;
  head1 = addLast(NULL, NULL, a1);
  Node *tail = head1;

  for (int i = 1; i < n1; i++)
  {
    int a = 0;
    cin >> a;
    map[a]++;
    tail = addLast(head1, tail, a);
  }

  int dataToInsert = 0;
  cin >> dataToInsert;
  map[dataToInsert]++;

  head1 = insert(head1, dataToInsert);

  if (checkSortedCyclicAndSize(head1, map))
  {
    cout << 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}