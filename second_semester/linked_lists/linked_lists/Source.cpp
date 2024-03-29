#include <iostream>
#include <format>
#include <cstdlib> // for delete operator (deleting pointer)


using std::string;
using std::cout;
using std::endl;
using std::format;


// https://youtu.be/RBSGKlAvoiM?list=PLxfRCInfTk3Wk-IKiCWLIkBtVKrDv-2QG&t=2103
// Singly and doubly linked lists.
// Two of the most useful data structures

// what is a linked list?
// a linked list is a sequential list of nodes
// that hold data which point to other nodes
// which also are containing data.

// 1. every node contains data,
// 2. every node has a reference to another node(s)
//	-- last node refers to null, which means, there are no more nodes.

// Linked list are used the most in the implemenation of Abstract Data Type,
// examples: list, queues, stacks.

// 
// head: first node of the linked list
// tail: last node of the linked list
// pointer: reference to the next node
// node: an object containing data and pointer(s).

// the node itself is usually represented as a struct or a class,
// when actually implemented.


// singly vs doubly linked list:
// 
// Singly linked list, each node only hold a reference to the next node.
// 
// Doubly linked list, each node hold a reference to the next and the previous node.
//  
// In the implementation you always keep a reference to the head and the tail,
// for a quick adding/removing from both ends of the linked list.
// 
//					  Pros						|				Cons
// singly linked list: uses less memory			|	Cannot easily access previous elements.
//					   simpler implementation	|
//
// doubly linked list: can be traversed backwards|	takes 2x memory.



// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class SinglyLinkedListNode {
private:
	int val;
	SinglyLinkedListNode* next;
public:
	SinglyLinkedListNode() : val(0), next(nullptr) {}
	SinglyLinkedListNode(int x) : val(x), next(nullptr) {}
	SinglyLinkedListNode(int x, SinglyLinkedListNode* next) : val(x), next(next) {}

	void removeNode() {
		cout << "a";
		// remove n2, so n1 points to n3
	}
};

// [1, 2, 3, 4, 5]
// [5, 4, 3, 2, 1]

class Solution {
public:
	// https://leetcode.com/problems/reverse-linked-list/
	ListNode* reverseList(ListNode* head) {
		ListNode* current;
		ListNode* next;
		ListNode* save;

		current = head; // 1

		// []
		if (current == nullptr) {
			return head;
		}

		next = current->next; // 2

		while (next) {
			save = next->next; // 3

			next->next = current; // 2->1, 3->2

			current = next; // 2, 3
			next = save; // 3, 4
		}

		head->next = nullptr;
		head = current;
		return head;
	}

	void insertAt(ListNode* head, ListNode* insertionNode, int index) {
		int currentIndex = 0;
		ListNode* currentNode = head;

		if (index == 0) {
			// at index 0. 7 -> 1 -> 2 (7 becomes head)
			insertionNode->next = currentNode;
			return;
		}

		while (currentIndex < index) {
			if (currentIndex == index - 1) {
				// at index 2. 2 -> 7 -> 3.
				// at index 1. 1 -> 7 -> 2.

				insertionNode->next = currentNode->next;
				currentNode->next = insertionNode;
				break;
			}
			currentNode = currentNode->next;
			currentIndex++;
		}
	}

	void removeNode(ListNode* head, ListNode* nodeToRemove) {
		// DELETE NODE! MEMORY LEAK.
		// https://stackoverflow.com/questions/655065/when-should-i-use-the-new-keyword-in-c
		ListNode* currentNode = head;

		while (currentNode) {
			if (currentNode->next == nodeToRemove) {
				// Remove Node 2. 1 -> 3 
				currentNode->next = nodeToRemove->next;

				// https://stackoverflow.com/questions/13223399/deleting-a-pointer-in-c
				*nodeToRemove = NULL;
				break;
			}
			currentNode = currentNode->next;
		}
	}
};

int main() {
	Solution sol;

	ListNode n5 = ListNode(5); // node 5, value 5, null
	ListNode n4 = ListNode(4, &n5); // node 4, value 5, node's adress 5
	ListNode n3 = ListNode(3, &n4); // node 3, value 3, node's adress 4
	ListNode n2 = ListNode(2, &n3); // node 2, value 2, node's adress 3
	ListNode n1 = ListNode(1, &n2); // node 1, value 2, node's adress 2
	ListNode z;

	//sol.reverseList(&n1);
	sol.reverseList(&z);

	ListNode n7 = ListNode(7);
	sol.insertAt(&n1, &n7, 0);
	sol.removeNode(&n7, &n2);

	SinglyLinkedListNode node5 = SinglyLinkedListNode(5);
	SinglyLinkedListNode node4 = SinglyLinkedListNode(4, &node5);
	SinglyLinkedListNode node3 = SinglyLinkedListNode(3, &node4);
	SinglyLinkedListNode node2 = SinglyLinkedListNode(2, &node3);
	SinglyLinkedListNode node1 = SinglyLinkedListNode(1, &node2);




}


// https://youtu.be/RBSGKlAvoiM?list=PLxfRCInfTk3Wk-IKiCWLIkBtVKrDv-2QG&t=2429




