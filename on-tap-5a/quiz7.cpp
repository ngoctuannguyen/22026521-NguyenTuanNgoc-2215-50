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

Node* deleteSingle(Node* head) {
    Node* temp = head;
    if (head->value != head->next->value) {
        return head->next;
    }
    
    bool isSingle = false;
    
    while (head->next && head->next->next) {
        if (head->value != head->next->value
        && head->next->next->value != head->next->value) {
            head->next = head->next->next;
            isSingle = true;
        }
        head = head->next;
    }
    
    if (!isSingle)
        head->next = NULL;

    return temp;
    
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
    
    // cout << "YES";
    // print(head);
    return 0;
}