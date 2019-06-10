#include <iostream>
 #include <vector>
 
 using namespace std;
 
 class Node
 {
 public:
     char data;
     Node *next;
 
     Node(char data, Node *next)
     {
         this->data = data;
         this->next = next;
     }
 };
 
 Node *head = NULL;
 Node *tail = NULL;
 int size = 0;
 
 void insert(char data)
 {
 
     Node *nn = new Node(data, NULL);
     if (head == NULL)
     {
         head = nn;
         tail = nn;
     }
     else
     {
         tail->next = nn;
         tail = nn;
     }
     size++;
 }
 void display(Node* head)
 {
     for (Node *node = head; node != NULL; node = node->next)
     {
         cout << node->data << " ";
     }
 }
 // this a function based problem 
 // do write code in this function only
 
 bool isVowel(Node *temp) {
     if(temp->data=='a' or temp->data=='e' or temp->data=='i' or temp->data=='o' or temp->data=='u') {
             return true;
     }
     return false;
 }
 
 void removeNode(Node *temp) {
     if(temp->next == NULL) {
         temp=NULL;
         return;
     } else if(temp->next->next==NULL) {
         temp->next=NULL;
     } else {
         Node *remove = temp->next;
         temp->next = temp->next->next;
         delete remove;
         return;
     }
 }
 
 Node* arrangeVowelsAndConsonants(Node* head)
 {
    if(head->next==NULL) return head;
    Node *vowel;
    if(isVowel(head)) {
        vowel = head;
    } else {
        Node *temp = head;
        while(temp->next!=NULL) {
            if(isVowel(temp->next)) {
                vowel = temp->next;
                break;
            }
            temp=temp->next;
        }
        if(temp->next == NULL) return head;
        Node *new_node = new Node(vowel->data, head);
        head = new_node;
        temp->next = temp->next->next;
    }
    vowel = head;
    // cout<<vowel->next->data;
    Node *start = head;
    while(start!= NULL and start->next!=NULL) {
        // cout<<start->data<<endl;;
        if(isVowel(start->next)) {
            if(vowel->next==start->next){
                vowel=vowel->next;
                start=start->next;
                continue;
            } 
            Node *new_node = new Node(start->next->data, NULL);
            start->next = start->next->next;

            new_node->next = vowel->next;
            vowel->next = new_node;
            vowel = vowel->next;
            // start = start->next;
        } else {
            start = start->next;
        }
    }
    return head;

 }
 
 int main(int argc, char *argv[])
 {
     // Input of the Linked List
     int n = 0;
     cin >> n;
     for (int i = 0; i < n; i++)
     {
         char ch;
         cin >> ch;
         insert(ch);
     }
 
     // call to the fiunction which return the rearranged list head 
     Node* arragnedHead = arrangeVowelsAndConsonants(head);
     
     //output display
     display(arragnedHead);
 
     return 0;
 }