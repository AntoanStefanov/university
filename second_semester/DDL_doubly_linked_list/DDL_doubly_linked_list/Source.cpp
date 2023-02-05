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
		Node* previous = nullptr;
		Node* next = nullptr;

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
			Node* node = new Node(value, nullptr, nullptr);
			head = tail = node;
		}
		else {
			Node* next = new Node(value, tail, nullptr);
			tail->setNext(next);
			if (isEmpty()) {
				tail->setPrevious(head);
				head->setNext(tail);
			}
			tail = next;
		}
		size++;
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
	DLL.getHead();
}