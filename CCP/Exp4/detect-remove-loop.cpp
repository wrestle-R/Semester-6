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
