#ifndef NODE_H_
#define NODE_H_
#include <iostream>

template<typename ItemType> 
class DoubleNode {
public:
	DoubleNode();
	DoubleNode(const ItemType& an_item);
	DoubleNode(const ItemType& an_item, DoubleNode<ItemType>* next_node_ptr);
	void setItem(const ItemType& an_item);
	void setNext(DoubleNode<ItemType>* next_node_ptr);
	void setPrevious(DoubleNode<ItemType>* prev_node_ptr);
	ItemType getItem() const;
	DoubleNode<ItemType>* getNext() const;
	DoubleNode<ItemType>* getPrevious() const;
private:
	ItemType item; // A data item
	DoubleNode<ItemType>* next_; // Pointer to next node
	DoubleNode<ItemType>* previous_; // Pointer to previous node
}; 

#include "DoubleNode.cpp"
#endif // NODE_H_