/*
 * CSEN 79 Lab
 * <YOUR NAME HERER>
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "roster.h"
#include "rosterllist.h"

namespace csen79 {
	// STUDENT WORKS
	// IMPLEMENT ALL THESE FUNCTIONS
	
	// Constructor - initializes empty linked list
	RosterLList::RosterLList() : head(nullptr) {}
	
	// Destructor - deletes all nodes in the linked list
	RosterLList::~RosterLList() {
		Node *current = head;
		while (current != nullptr) {
			Node *temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr;
	}
	// Default constructor - initializes next pointer to nullptr
	RosterLList::Node::Node() : data(), next(nullptr) {}
	
	// Parameterized constructor - initializes data with given value and next to nullptr
	RosterLList::Node::Node(T &t) : data(t), next(nullptr) {}
	
	// Destructor - no dynamic memory to clean up in Node itself
	RosterLList::Node::~Node() {}
	
	// begin() - returns iterator pointing to first node in list
	RosterLList::iterator RosterLList::begin() {
		return RosterLList::iterator(head); 
	}
	
	// end() - returns iterator pointing to nullptr (one past last element)
	RosterLList::iterator RosterLList::end() {
		return RosterLList::iterator(nullptr); 
	}
	
	// insert() - inserts a new node at the head of the list
	// Returns true on success, false on allocation failure
	bool RosterLList::insert(T &rec) {
		try {
			// New node with recorded data
			Node *newNode = new Node(rec);
			// New node points to where head currently points
			newNode->next = head;
			// Now head points to new node
			head = newNode;

			return true;

		} catch (const std::bad_alloc &e) {
			// Malloc error
			std::cerr << "Error: Memory allocation failed in insert()" << std::endl;
			return false;
		}
	}

	// erase() - removes the node with given ID from the list
	void RosterLList::erase(Person::ID_t id) {
		if (head == nullptr) {
			return;
		}
		// Head node has given ID
		if (head->data.getID() == id) {
			Node *temp = head;
			head = head->next;
			delete temp;
			return;
		}
		// Search for given ID
		Node *current = head;
		while (current->next != nullptr) {
			if (current->next->data.getID() == id) {
				// Found node to remove
				Node *temp = current->next;
				current->next = temp->next;
				delete temp;
				return;
			}
			current = current->next;
		}
		// ID not found
	}

	// Iterator constructor - initializes ptr to point to given node
	RosterLList::iterator::iterator(Node *t) : ptr(t) {}
	
	// Inequality operator - compares if two iterators point to different nodes
	bool RosterLList::iterator::operator !=(const iterator &rhs) {
		return ptr != rhs.ptr;
	}
	
	// Dereference operator - returns reference to the data in current node
	Roster::T &RosterLList::iterator::operator *() { 
		return ptr->data; 
	}
	
	// Pre-increment operator - advances iterator to next node
	RosterLList::iterator &RosterLList::iterator::operator++() {
		if (ptr != nullptr) {
			ptr = ptr->next;
		}
		return *this;
	}
}
