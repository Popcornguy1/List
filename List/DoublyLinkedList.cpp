#include "DoublyLinkedList.hpp"
#include <iostream>
#include <string>
using namespace std;

template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : head(nullptr), tail(nullptr), item_count(0) {

}

template <typename ItemType> // copy constrctor 
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& a_list) { 
	item_count = a_list.item_count;
	DoubleNode<ItemType>* orig_chain_ptr = a_list.head;//Points to nodes in original chain
	if (orig_chain_ptr == nullptr)
		head = nullptr; // Original bag is empty
	else
	{// Copy first node
		head = new DoubleNode <ItemType>();
		head->setItem(orig_chain_ptr->getItem());
		// Copy remaining nodes
		DoubleNode<ItemType>* new_chain_ptr = head;//Points to last node in new chain
		orig_chain_ptr = orig_chain_ptr->getNext();//Advance original-chain pointer
		while (orig_chain_ptr != nullptr)
		{ // Get next item from original chain
			ItemType next_item = orig_chain_ptr->getItem();
			// Create a new node containing the next item
			DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(next_item);
			// Link new node to end of new chain
			new_chain_ptr->setNext(new_node_ptr);
			// Advance pointer to new last node
			new_chain_ptr = new_chain_ptr->getNext();
			// Advance original-chain pointer
			orig_chain_ptr = orig_chain_ptr->getNext();
		} // end while
		new_chain_ptr->setNext(nullptr); // Flag end of chain
	} // end if

}

template<typename ItemType>
DoublyLinkedList<ItemType>:: ~DoublyLinkedList() {
	clear(); 

}

template<typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position) {
		//Create a new node containing the new entry and get a pointer to position
		DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(item);
		DoubleNode<ItemType>* pos_ptr = getAtPos(position);
		if (head == nullptr)
		{
			// Insert first node
			new_node_ptr->setNext(nullptr);
			new_node_ptr->setPrevious(nullptr);
			head = new_node_ptr;
			tail = new_node_ptr;
		}
// Attach new node to chain
else if (pos_ptr == head) {
// Insert new node at head of chain
new_node_ptr->setNext(head);
new_node_ptr->setPrevious(nullptr);
head->setPrevious(new_node_ptr);
head = new_node_ptr;
}
else if (pos_ptr == nullptr) {
//insert at end of list
new_node_ptr->setNext(nullptr);
new_node_ptr->setPrevious(tail);
tail->setNext(new_node_ptr);
tail = new_node_ptr;
}
else {
// Insert new node before node to which position points
new_node_ptr->setNext(pos_ptr);
new_node_ptr->setPrevious(pos_ptr->getPrevious());
pos_ptr->getPrevious()->setNext(new_node_ptr);
pos_ptr->setPrevious(new_node_ptr);
}//end if
item_count++; // Increase count of entries
return true;
	}//end insert

template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position) {
	DoubleNode<ItemType>* pos_ptr = getAtPos(position);
	if (pos_ptr == nullptr) { // no node at position
		return false;
	}
	else {
		// Remove node from chain
		if (pos_ptr == head) {
			if (pos_ptr->getNext() != NULL)
			{
				head = pos_ptr->getNext();
				head->setPrevious(NULL);
				pos_ptr->setNext(nullptr);
			}
			else
			{
				head = nullptr;
			}
			delete pos_ptr;
			pos_ptr = nullptr;
		}
		else if (pos_ptr == tail) {
			//remove last_ node
			tail = pos_ptr->getPrevious();
			tail->setNext(nullptr);
			// Return node to the system
			pos_ptr->setPrevious(nullptr);
			delete pos_ptr;
			pos_ptr = nullptr;
		}
		else {
			//Remove from the middle
			pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
			pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());
			// Return node to the system
			pos_ptr->setNext(nullptr);
			pos_ptr->setPrevious(nullptr);
			delete pos_ptr;
			pos_ptr = nullptr;
		}
		item_count--;
		return true;
	}
}

template<typename ItemType>
int DoublyLinkedList<ItemType> ::getSize() const {
	return item_count; 

}

template<typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const {
	return (item_count == 0);

}
template<typename ItemType>
void DoublyLinkedList<ItemType>::clear() {
	DoubleNode<ItemType>* delete_node = head;
	while (head != nullptr)
	{
		head = head->getNext();

		// Return node to the system
		delete_node->setNext(nullptr);
		delete_node->setPrevious(nullptr);
		delete delete_node;

		delete_node = head;
	}  // end while
	// head_ptr_ is nullptr; node_to_delete is nullptr
	tail = nullptr;
	item_count = 0;
}
template<typename ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType& item) const {
	
}
template<typename ItemType>
void DoublyLinkedList<ItemType>::display() const {
	DoubleNode<ItemType>* current_ptr = head;
	while (current_ptr != NULL) {
		if (current_ptr->getNext() == NULL) {
			cout << current_ptr->getItem();
		}
		else {
			cout << current_ptr->getItem() << " ";
		}
		current_ptr = current_ptr->getNext();
	}

	cout << endl;


}

template<typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const{
	DoubleNode<ItemType>* now_ptr = head; 
	while (now_ptr->getNext() != NULL) {
		now_ptr = now_ptr->getNext(); 
	}

	while (now_ptr != head) {
		cout << now_ptr->getItem() << " " ; 
		now_ptr = now_ptr->getPrevious(); 

	}
	cout << now_ptr->getItem() << endl; 
}
template<typename ItemType> 
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list) {
	DoublyLinkedList<ItemType> NewList; // create our own list to return
	DoubleNode<ItemType>* first1 = head; // Node to traverse original list
	DoubleNode<ItemType>* second2 = a_list.getHeadPtr();
	double i = 1; 
	while (first1 != NULL || second2 != NULL) {
		if (first1 != NULL) {
			NewList.insert(first1->getItem(), i);
			first1 = first1->getNext();
			i++;
		}

		if (second2 != NULL) {
			NewList.insert(second2->getItem(), i);
			second2 = second2->getNext();
			i++;
		}
	}
	return NewList;
}

template<typename ItemType> 
DoubleNode<ItemType>* DoublyLinkedList<ItemType> ::getHeadPtr() const {
	return head; 

}

template<typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType> ::getAtPos(const int& pos) const {
	// count from begining of chain
	DoubleNode<ItemType>* pos_ptr = head;
	for (int i = 1; i < pos; i++) {
		pos_ptr = pos_ptr->getNext();
	}
	return pos_ptr;

}