

#include "DoubleNode.hpp"
#include <iostream>
#include <string> 

using namespace std;


template<typename ItemType>
DoubleNode<ItemType>::DoubleNode() {
}

template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& an_item) : item(an_item) {

}

template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& an_item, DoubleNode<ItemType>* next_node_ptr) {

}


template<typename ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& an_item) {
	item = an_item; 
}

template<typename ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* next_node_ptr) {
	next_ = next_node_ptr; 
}

template<typename ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType>* prev_node_ptr) {
	previous_ = prev_node_ptr; 
}

template<typename ItemType>
ItemType DoubleNode<ItemType> ::getItem() const {
	return item;
}

template<typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const {
	return next_;
}

template<typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const {
	return previous_;
}



