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

Node* deleteNode(Node* head, int pos) {
    Node* temp = head;
    if (pos == 0) {
        return head->next;
    }
    while (pos != 1) {
        temp = temp->next;
        pos--;
    }
    temp->next = temp->next->next;
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
    head->next = new Node();
    head->next->next = new Node();
    head->next->next->next = new Node();
    head->next->next->next->next = new Node();
    head = deleteNode(head, 0);
    print(head);
    return 0;
}