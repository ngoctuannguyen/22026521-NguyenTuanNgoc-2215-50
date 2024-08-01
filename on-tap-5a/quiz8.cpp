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

Node* deleteDuplicates(Node* head) {
    bool appear[10001] = {false};
    if (head == NULL) {
        return NULL;
    }
    Node* newNode;
    Node* temp = head;
    Node* nonDuplicateList = temp;
    appear[head->value] = 1;
    while (head) {
        if (appear[head->value] == 0) {
            newNode = new Node();
            newNode->value = head->value;
            temp->next = newNode;
            temp = temp->next;
            appear[head->value] = 1;
        }
        head = head->next;
    }
    
    return nonDuplicateList;
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