#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using std::string;

class SinglyLinkedList {
private:
	class Node {
	public:
		Node(Semiconductor* device) : device(device) {}
		Node(Semiconductor* device, Node* next) : device(device), next(next) {}
		Semiconductor* device = nullptr;
		Node* next = nullptr;
	};
	Node* tail = nullptr;
	Node* head = nullptr;

public:
	void append(Semiconductor*);
	void print() const;
	void deleteList();
};

#endif