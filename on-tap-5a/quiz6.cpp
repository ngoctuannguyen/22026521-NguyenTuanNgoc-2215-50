#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int value_) {
        value = value_;
        next = NULL;
    }
};

void printReverse(Node* head, int k) {
    Node* temp1 = head;
    Node* temp2;
    Node* prev = NULL;

    if (head == NULL || k == 0) {
        return;
    }

    while (k--) {
        temp2 = new Node();
        temp2->value = temp1->value;
        temp2->next = prev;
        prev = temp2;
        temp1 = temp1->next;
    }
    
    while (temp2) {
        cout << temp2->value << " ";
        temp2 = temp2->next;
    }
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    printReverse(head, 1);
    cout << endl;
    printReverse(head, 5);
    cout << endl;
    printReverse(head, 10);
    cout << endl;
    printReverse(head, 0);
    
    // cout << "YES";
    // print(head);
    return 0;
}