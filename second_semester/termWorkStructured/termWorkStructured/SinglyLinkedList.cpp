#include "semiconductor.h"
#include "singlyLinkedList.h"

#include <iostream>
using std::string;
using std::cout;
using std::endl;

void SinglyLinkedList::append(Semiconductor* device) {
	Node* newTail = new Node(device);
	if (tail == nullptr) {
		tail = newTail;
		head = newTail;
		return;
	}
	tail->next = newTail;
	tail = newTail;
}

void SinglyLinkedList::print() const {
	Node* node = head;
	while (node != nullptr) {
		cout << "Singly Linked List Node: " << endl;
		node->device->showInfo();
		node = node->next;
	}
}

void SinglyLinkedList::deleteList() {
	Node* node = head;
	while (node != nullptr) {
		Node* delNode = node;
		node = node->next;
		delete delNode;
	}
}