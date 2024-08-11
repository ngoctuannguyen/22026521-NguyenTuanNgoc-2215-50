#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};


SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode* temp = NULL;
    SinglyLinkedListNode* mergeList = NULL;
    SinglyLinkedListNode* newNode = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            newNode = new SinglyLinkedListNode(head1->data);
            head1 = head1->next;
        }
        else {
            newNode = new SinglyLinkedListNode(head2->data);
            head2 = head2->next;
        }
        if (mergeList == NULL) {
            mergeList = newNode;
            temp = mergeList;
        }
        else {     
            mergeList->next = newNode;
            mergeList = mergeList->next;
        }
    }
    
    while (head1) {
        newNode = new SinglyLinkedListNode(head1->data);
        if (mergeList == NULL) {
            mergeList = newNode;
            temp = mergeList;
        }
        else {     
            mergeList->next = newNode;
            mergeList = mergeList->next;
        }
        head1 = head1->next;
    }
    
    while (head2) {
        newNode = new SinglyLinkedListNode(head2->data);
        if (mergeList == NULL) {
            mergeList = newNode;
            temp = mergeList;
        }
        else {     
            mergeList->next = newNode;
            mergeList = mergeList->next;
        }
        head2 = head2->next;
    }
    return temp;
}

void printList(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data << endl;
        node = node->next;
    }
}

int main() {
    
    SinglyLinkedListNode* head1 = NULL;
    SinglyLinkedListNode* head2 = NULL;
    SinglyLinkedListNode* mergeList1 = NULL, *mergeList2 = NULL;
    SinglyLinkedListNode* temp1, *temp2;

    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int data;
        cin >> data;
        if (head1 == NULL) {
            head1 = new SinglyLinkedListNode(data);
            mergeList1 = head1;
            temp1 = mergeList1;
        }
        else {
            mergeList1->next = new SinglyLinkedListNode(data);
            mergeList1 = mergeList1->next;
        }
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int data;
        cin >> data;
        if (head2 == NULL) {
            head2 = new SinglyLinkedListNode(data);
            mergeList2 = head2;
            temp2 = mergeList2;
        }
        else {
            mergeList2->next = new SinglyLinkedListNode(data);
            mergeList2 = mergeList2->next;
        }
    }
    SinglyLinkedListNode* mergeList = mergeLists(temp1, temp2);
    printList(mergeList);

    return 0;
}