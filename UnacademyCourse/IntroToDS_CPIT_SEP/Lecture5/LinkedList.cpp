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

Node* merge(Node *a, Node *b) {
    if(a == NULL) return b;
    else if(b == NULL) return a;
    Node *c;
    if(a->data < b->data) { // a = 1->2->3,  b = 2->3->4 c = 1-> merge(2->3, 2->3->4)
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

    Node *mid = midNode(head);
    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    Node *c = merge(a, b);
    return c;
}

bool detectCycle(Node *&head) {
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}

Node* originOfCycle(Node *&head) {
    Node *slow = head;
    Node *fast = head;
    bool flag = false;
    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            flag = true;
            break;
        }
    }
    if(!flag)
        return NULL;
    
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
} 

void reversePointerIterative(Node *&head) {
    Node *curr = head;
    Node *prev = NULL;
    while(curr != NULL) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

Node *reversePointerRecursive(Node *head) {
    if(head == NULL or head->next == NULL) return head;
    Node *newHead = reversePointerRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
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
    insertAt(head, 105, 2);
    display(head);
    // deleteAtHead(head);
    // display(head);
    Node *mid = midNode(head);
    std::cout<<mid->data<<"\n";

    head = mergeSort(head);
    display(head);
    std::cout<<detectCycle(head)<<"\n";

    Node *h1 = NULL;
    insertAtHead(h1,10);
    insertAtHead(h1,20);
    insertAtTail(h1,30);
    insertAtTail(h1,40);
    insertAtTail(h1,50);
    insertAtTail(h1,60);
    Node* t1 = h1;
    while(t1->next != NULL) {
        t1 = t1->next;
    }
    t1->next = h1->next->next;
    std::cout<<detectCycle(h1)<<"\n";
    Node *n = originOfCycle(h1);
    std::cout<<n->data<<"\n";


    reversePointerIterative(head);
    display(head);
    head = reversePointerRecursive(head);
    display(head);
    return 0;
}

// 20->10->30->40->
