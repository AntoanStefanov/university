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

		Node* getPrevious() {
			return previous;
		}

		Node* getNext() {
			return next;
		}

		int getValue() const {
			return value;
		}

		void setPrevious(Node* node) {
			previous = node;
		}

		void setNext(Node* node) {
			next = node;
		}

		void setValue(int val) {
			value = val;
		}
	};
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

	void addOnEmpty(int value) {
		Node* node = new Node(value, nullptr, nullptr);
		head = tail = node;
	}
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

	bool isEmpty() const {
		return getSize() == 0;
	}

	void addLast(int value) {
		if (isEmpty()) {
			addOnEmpty(value);
		}
		else {
			// tail == 1
			// new tail, with the old one set as previous.
			Node* newTail = new Node(value, tail, nullptr); //	2 -> 1
			// set current tail next, to the new tail.
			tail->setNext(newTail); // 1 -> 2
			// set the new tail as current.
			tail = newTail; // tail == 2
		}
		size++;
	}

	void deleteLast() {
		// check if empty.
		if (isEmpty()) return;

		// get previous.
		Node* prev = tail->getPrevious();

		// remove tail
		delete tail;

		// set prev as tail.
		prev->setNext(nullptr);
		tail = prev;

		// downsize the list.
		size--;
	}

	void addFirst(int value) {
		if (isEmpty()) {
			addOnEmpty(value);
		}
		else {
			// new head, which next is current head.
			Node* newHead = new Node(value, nullptr, head); // 0 -> 1

			// set current head previous as the new head. 1 -> 0
			head->setPrevious(newHead);

			// set new head as current.
			head = newHead;
		}
		size++;
	}

	void deleteFirst() {
		if (isEmpty()) {
			return;
		}
		// 1. get newHead
		Node* newHead = head->getNext();

		// 2. set newHead prev as null
		newHead->setPrevious(nullptr);

		// 3. delete current head
		delete head;

		// 4. set newHead as head
		head = newHead;

		size--;
	}
};

// https://www.programiz.com/cpp-programming/class-templates
template <class T>
class Number {
private:
	// Variable of type T
	T num;

public:
	explicit Number(T n) : num(n) {}   // constructor

	T getNum() {
		return num;
	}
};

int main() {
	// create object with int type
	Number<int> numberInt = Number(7);
	numberInt.getNum();
	// create object with double type
	Number<double> numberFloat = Number(7.7);
	numberFloat.getNum();


	DoublyLinkedList DLL;
	DLL.getHead();
	DLL.getSize();
	DLL.getTail();

	DLL.addLast(1);
	DLL.addLast(2);
	DLL.addLast(3);
	DLL.addLast(4);
	DLL.getHead();
	DLL.deleteLast();
	DLL.getHead();

	DoublyLinkedList DLL1;
	DLL1.addLast(1);
	DLL1.addLast(2);
	DLL1.deleteLast();
	DLL1.addLast(2);
	DLL1.getHead();
	DLL1.addFirst(0);
	DLL1.getHead();
	DLL1.deleteFirst();
	DLL1.getHead();
}