#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int value_) {
        value = value_;
        next = NULL;
    }

    int getValue() {
        
    }
};

Node* insertSorted(Node* head, Node* newNode) {
    if (head == NULL || newNode->getValue() <= head->getValue()) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode; 
    } 
    else {
        Node* current = head;
        while (current->next != NULL && current->next->getValue() < newNode->getValue()) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
        return head;
    }
}

Node* sort(Node* head) {
    Node* sortedHead = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;
        current->prev = current->next = NULL;
        sortedHead = insertSorted(sortedHead, current);
        current = nextNode;
    }

    return sortedHead;
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