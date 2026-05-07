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

void reorderList(Node* head) {
	if (head == NULL || head->next == NULL) {
		return;
	}

	Node* slow = head;
	Node* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	Node* second = slow->next;
	slow->next = NULL;

	Node* prev = NULL;
	while (second != NULL) {
		Node* nextNode = second->next;
		second->next = prev;
		prev = second;
		second = nextNode;
	}

	second = prev;
	Node* first = head;

	while (second != NULL) {
		Node* firstNext = first->next;
		Node* secondNext = second->next;

		first->next = second;
		second->next = firstNext;

		first = firstNext;
		second = secondNext;
	}
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

	reorderList(head);

	cout << "Reordered list: ";
	printList(head);

	return 0;
}
