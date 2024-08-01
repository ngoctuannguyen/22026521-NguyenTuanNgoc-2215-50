#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }
};

Node* insertHead(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    head = newNode;
    
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    head = insertHead(head, 1);
    head = insertHead(head, 2);
    head = insertHead(head, 3);
    print(head);
    return 0;
}