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

Node* mergeSortedLists(Node* first, Node* second) {
	if (first == NULL) {
		return second;
	}

	if (second == NULL) {
		return first;
	}

	Node* head = NULL;
	if (first->data <= second->data) {
		head = first;
		first = first->next;
	} else {
		head = second;
		second = second->next;
	}

	Node* tail = head;

	while (first != NULL && second != NULL) {
		if (first->data <= second->data) {
			tail->next = first;
			first = first->next;
		} else {
			tail->next = second;
			second = second->next;
		}

		tail = tail->next;
	}

	tail->next = (first != NULL) ? first : second;
	return head;
}

void printList(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* first = new Node(1);
	first->next = new Node(3);
	first->next->next = new Node(5);

	Node* second = new Node(2);
	second->next = new Node(4);
	second->next->next = new Node(6);

	Node* merged = mergeSortedLists(first, second);

	cout << "Merged sorted list: ";
	printList(merged);

	return 0;
}
