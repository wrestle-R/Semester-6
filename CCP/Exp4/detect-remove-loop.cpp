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

void detectAndRemoveLoop(Node* head) {
    if (head == NULL) return;

    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists) return;

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* loopStart = slow;

    Node* temp = loopStart;
    while (temp->next != loopStart) {
        temp = temp->next;
    }

    temp->next = NULL;
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

    Node* loopStart = head->next->next;
    head->next->next->next->next->next = loopStart;

    detectAndRemoveLoop(head);

    cout << "List after removing loop: ";
    printList(head);

    return 0;
}
