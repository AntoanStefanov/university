#include <iostream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::format;

class DoublyLinkedList {
private:
	class Node {
	private:
		int value;
		Node* previous;
		Node* next;

	public:
		Node(int value, Node* previous, Node* next) : value(value), previous(previous), next(next) {}
	};
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	Node* getHead() {
		return head;
	}

	Node* getTail() {
		return tail;
	}

	int getSize() const {
		return size;
	}

	Node* addNode() {

	}
};


int main() {
	DoublyLinkedList DLL;
	DLL.getHead();
	DLL.getSize();
	DLL.getTail();
}