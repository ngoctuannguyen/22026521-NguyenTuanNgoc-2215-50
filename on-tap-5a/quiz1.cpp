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
    print(head);
    return 0;
}