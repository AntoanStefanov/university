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
		explicit Node(int value) : value(value), previous(nullptr), next(nullptr) {}

		Node* getPrevious() {
			return previous;
		}

		Node* getNext() {
			return previous;
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

	Node* addNode(int value) {
		Node* node = new Node(value);
		if (isEmpty()) {
			head = tail = node;
		}

		return node;
	}

	Node* addNode(int value, Node* previous, Node* next) {
		Node* node = new Node(value);
		head = tail = node;
		return node;
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
}