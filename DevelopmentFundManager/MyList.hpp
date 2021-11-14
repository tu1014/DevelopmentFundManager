#include "MyList.h"
#include <iostream>
using namespace std;

template<typename T>
Node<T>::Node() {

	// circular dummy head constructor
	ptr_item = null;
	ptr_prev = this;
	ptr_next = this;

}

template<typename T>
Node<T>::Node(T& element) {

	ptr_item = element;
	ptr_prev = null;
	ptr_next = null;

}

template<typename T>
Node<T>::~Node() {

	cout << "Node 삭제" << endl;
	delete ptr_item;
	// prev, next도 지워야 할까?
	// 아닌거같은데
	// delete prev;
	// delete next;

}

template<typename T>
const Node<T>& Node<T>::getNext() const { return ptr_next; }

template<typename T>
const Node<T>& Node<T>::getPrev() const { return ptr_prev; }

template<typename T>
void Node<T>::setNext(Node& nextNode) {

	nextNode.setPrev(this);
	nextNode.setNext(ptr_next);
	ptr_next = nextNode;

}

template<typename T>
void Node<T>::setPrev(Node& prevNode) {

	prevNode.setPrev(ptr_prev);
	prevNode.setNext(this);
	ptr_prev = prevNode;

}


////////////////////////////////////////////////////////////

template<typename T>
MyList<T>::MyList() {



}