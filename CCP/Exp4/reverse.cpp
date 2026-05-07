#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    int count = 0;

    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int k = 2;
    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}