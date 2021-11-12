#include "MyList.h"
#include <iostream>
using namespace std;

template<typename T>
Node<T>::Node() {

	// circular dummy head constructor
	ptr_element = null;
	prev = this;
	next = this;

}

template<typename T>
Node<T>::Node(T element) {

	ptr_element = element&;
	prev = null;
	next = null;

}

template<typename T>
Node<T>::~Node() {

	cout << "Node 삭제" << endl;
	delete ptr_element;
	// prev, next도 지워야 할까?
	// 아닌거같은데
	// delete prev;
	// delete next;

}

template<typename T>
const Node<T>& Node<T>::getNext() const { return next; }

template<typename T>
const Node<T>& Node<T>::getPrev() const { return prev; }

template<typename T>
void Node<T>::setNext(Node& nextNode) {

	nextNode.setPrev(this);
	nextNode.setNext(next);
	next = nextNode;

}

template<typename T>
void Node<T>::setPrev(Node& prevNode) {

	prevNode.setPrev(prev);
	prevNode.setNext(this);
	prev = prevNode;

}


template<typename T>
MyList<T>::MyList() {



}