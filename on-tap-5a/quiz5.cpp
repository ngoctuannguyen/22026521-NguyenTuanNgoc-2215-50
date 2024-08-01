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

void printLast(Node* head, int k) {
    Node* temp = head;
    int llistSize = 0;
    while (temp != NULL) {
        temp = temp->next;
        llistSize++;
    }
    
    int indexLeft = 0;
    while (head != NULL) {
        if (llistSize - indexLeft == k) {
            break;
        }
        indexLeft++;
        head = head->next;
    }
    
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
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
    Node* head = NULL;
    head->next = new Node();
    head->next->next = new Node();
    head->next->next->next = new Node();
    head->next->next->next->next = new Node();
    printLast(head, 4);
    print(head);
    return 0;
}