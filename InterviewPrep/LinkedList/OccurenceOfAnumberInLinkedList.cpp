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
 // This function takes as input the head of the linked list and key search.
 // It should return the count of occurences.
 int frequency(Node *node, int search)
 {
     // write your code here
    Node *temp = node;
    int result = 0;
    while(temp!=NULL) {
        if(temp->data == search) {
            result++;
        }
        temp = temp->next;

    }
    return result;
 }
 
 // -----------------------------------------------------
 
 int main()
 {
     int s;
     cin >> s;
     int a;
     cin >> a;
     head = insert(NULL, a);
     Node *tail = head;
     for (int i = 1; i < s; i++)
     {
         int temp;
         cin >> temp;
         tail = insert(tail, temp);
     }
 
     int k;
     cin >> k;
 
     cout << frequency(head, k) << endl;
 }