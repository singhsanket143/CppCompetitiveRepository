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

Node* arrangeVowelsAndConsonants(Node* head)
{
    Node *vowels = head;
    if (vowels->data == 'a' or vowels->data == 'e' or vowels->data == 'i' or vowels->data == 'o' or vowels->data == 'u') {
        // Nothing
    } else {
        Node *first_vowel = head;
        while (first_vowel->next != NULL and !(first_vowel->next->data == 'a' or first_vowel->next->data == 'e' or first_vowel->next->data == 'i' or first_vowel->next->data == 'o' or first_vowel->next->data == 'u')) {
            first_vowel = first_vowel->next;
        }
        if(first_vowel->next == NULL and !(first_vowel->data == 'a' or first_vowel->data == 'e' or first_vowel->data == 'i' or first_vowel->data == 'o' or first_vowel->data == 'u')) {
            return head;
        }
        Node *to_be_added = first_vowel->next;
        first_vowel->next = first_vowel->next->next;
        to_be_added->next = head;
        head = to_be_added;
    }
    vowels = head;
    while (vowels->next != NULL) {
        if (vowels->next->data == 'a' or vowels->next->data == 'e' or vowels->next->data == 'i' or vowels->next->data == 'o' or vowels->next->data == 'u')
            vowels = vowels->next;
        else
            break;
    }
    Node *temp = vowels;
    while (temp->next != NULL) {
        if (temp->next->data == 'a' or temp->next->data == 'e' or temp->next->data == 'i' or temp->next->data == 'o' or temp->next->data == 'u') {
            Node *to_be_added = temp->next;
            temp->next = temp->next->next;
            to_be_added->next = vowels->next;
            vowels->next = to_be_added;
            vowels = vowels->next;
        } else
            temp = temp->next;
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