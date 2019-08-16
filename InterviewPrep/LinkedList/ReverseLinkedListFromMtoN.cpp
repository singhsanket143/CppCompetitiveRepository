#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

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

Node *head = NULL;

/*
    * Input Parameters: tail: tail of the linked list in which a new node is to
    * be inserted. data: the data value of the node which is to be inserted.
    *
    * Return Value: tail of the linked list in which the node is inserted
*/

Node *insert(Node *tail, int data)
{
    if (tail == NULL)
    {
        return new Node(data, NULL);
    }
    else
    {
        tail->next = new Node(data, NULL);
        return tail->next;
    }
}

/*
    * Input Parameters: head: head of the linked list in which is to be
    * displayed.
    *
    * Return Value: null
*/

void display(Node *head)
{
    for (Node *node = head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of the linked list, m and n.
// It should return the head of the modified list.

Node *reverseBetween(Node *head, int m, int n)
{
    // write your code here
    if (head == NULL or head->next == NULL) return head;
    Node *start = head, *start_prev = NULL, *end = head, *end_next = head->next;
    for (int i = 1; i < m; i++) {
        start_prev = start;
        start = start->next;
    }
    for (int i = 1; i < n; i++) {
        end = end_next;
        end_next = end_next->next;
    }
    // reverse logic

    Node *curr = start, *prev = start_prev, *next = curr->next;
    int count = n - m + 1;
    while (count--) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start->next = end_next;
    if (start_prev != NULL)
        start_prev->next = prev;
    else if (end_next == NULL) {
        head = end;
    } else {
        start->next = end_next;
        head = end;
    }

    return head;
}
// -----------------------------------------------------

int main()
{
    int s;
    cin >> s;
    int a;
    cin >> a;
    head = insert(NULL, a);
    Node *cur = head;
    for (int i = 1; i < s; i++)
    {
        int temp;
        cin >> temp;
        cur = insert(cur, temp);
    }

    int m, n;
    cin >> m >> n;

    Node *sol = reverseBetween(head, m, n);
    display(sol);
}