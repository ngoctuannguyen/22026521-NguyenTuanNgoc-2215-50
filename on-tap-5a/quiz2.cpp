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

Node* insertTail(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    Node* temp = head;

    if (head == NULL) {
        return newNode;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    head = insertTail(head, 1);
    head = insertTail(head, 2);
    head = insertTail(head, 3);
    head = insertTail(head, 4);
    print(head);
    return 0;
}