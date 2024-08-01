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

Node* insert(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    Node* resultList = head;
    if (head == NULL) {
        return newNode;
    }
    
    if (head->next == NULL) {
        if (head->value >= value) {
            newNode->next = head;
            return newNode;
        }
        else {
            head->next = newNode;
            return head;
        }
    }
    
    bool ascending = (head->value < head->next->value);
    
    if (ascending) {
        if (head->value >= value) {
            newNode->next = head;
            return newNode;
        }
    }
    else {
        if (head->value <= value) {
            newNode->next = head;
            return newNode;
        }
    }
    
    if (ascending) {
        while (head->next && !(head->value <= value && value <= head->next->value)) {
            head = head->next;
        }
        newNode->next = head->next;
        head->next = newNode;
    }
    else {
        while (head->next && !(head->value >= value && value >= head->next->value)) {
            head = head->next;
        }
        newNode->next = head->next;
        head->next = newNode;
    }
    
    return resultList;
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