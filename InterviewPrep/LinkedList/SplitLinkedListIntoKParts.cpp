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
    cout << endl;
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of the linked list and k and the size of list.
// It should return the an array of heads of the linked list parts.
vector<Node *> splitListToParts(Node *root, int k, int size)
{
    // write your code here
    Node *curr = root;
    int n = 0;
    vector<Node*> ans(k);
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }
    curr = root;
    int width = n / k, rem = n % k;
    for (int i = 0; i < k; i++) {
        Node *head = curr;
        for (int j = 0; j < width + (i < rem ? 1 : 0) - 1; j++) {
            if (curr != NULL) curr = curr->next;
        }
        if (curr != NULL) {
            Node *prev = curr;
            curr = curr->next;
            prev->next = NULL;
        }
        ans[i] = head;
    }
    return ans;
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

    int k;
    cin >> k;

    vector<Node *> heads = splitListToParts(head, k, s);

    for (int i = 0;  i < heads.size(); i++)
    {
        display(heads[i]);
    }
}