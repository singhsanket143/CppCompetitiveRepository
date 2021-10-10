#include<iostream>

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

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
    Node *n = new Node(data);
    tail->next = n;
    return;
}

void insertAt(Node *&head, int data, int idx) {
    if(head == NULL or idx == 0) {
        insertAtHead(head, data);
        return;
    } else {
        Node *temp = head;
        int pos = 0;
        while(pos < idx - 1) {
            temp = temp->next;
            pos++;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
        return;
    }
}

void deleteAtHead(Node *&head) {
    if(head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
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
}

void deleteAt(Node *&head, int idx) {
    // to be implemented
}

Node* midNode(Node *head) {
    if(head == NULL or head->next == NULL) return head;
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void display(Node *head) {
    while(head != NULL) {
        std::cout<<head->data<<"=>";
        head = head->next;
    }
    std::cout<<"\n";
    return;
}



int main(int argc, char const *argv[])
{
    Node* head = NULL;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    // insertAt(head, 105, 2);
    display(head);
    // deleteAtHead(head);
    // display(head);
    Node *mid = midNode(head);
    std::cout<<mid->data<<"\n";
    return 0;
}

// 20->10->30->40->
