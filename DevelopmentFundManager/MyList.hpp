#include "MyList.h"
#include <iostream>
using namespace std;

template<typename T>
Node<T>::Node() {

	// circular dummy head constructor
	ptr_item = NULL;
	ptr_prev = this;
	ptr_next = this;

}

template<typename T>
Node<T>::Node(T* element) {

	ptr_item = element;
	ptr_prev = NULL;
	ptr_next = NULL;

}

template<typename T>
Node<T>::~Node() {

	cout << "Node 삭제" << endl;

	(*ptr_prev).setNext(ptr_next);
	(*ptr_next).setPrev(ptr_prev);

	delete ptr_item;
	// prev, next도 지워야 할까?
	// 아닌거같은데
	// delete prev;
	// delete next;

}

template<typename T>
Node<T>* Node<T>::getNext() const { return ptr_next; }

template<typename T>
Node<T>* Node<T>::getPrev() const { return ptr_prev; }

template<typename T>
void Node<T>::setNext(Node<T>* node) {

	ptr_next = node;

}

template<typename T>
void Node<T>::setPrev(Node<T>* node) {

	ptr_prev = node;

}

template<typename T>
T* Node<T>::getItem() { return ptr_item; }

template<typename T>
void Node<T>::insertNext(Node<T>* node) {

	(*node).setPrev(this);
	(*node).setNext(ptr_next);
	(*ptr_next).setPrev(node);
	ptr_next = node;

}


////////////////////////////////////////////////////////////

template<typename T>
MyList<T>::MyList() {

	size = 0;

}

// 제거자 정의 필요

template<typename T>
bool MyList<T>::insert(T* newItem) {

	// 비어 있으면 맨 앞에 삽입

	// 처음부터 끝까지 돌면서 중복 체크
	// 루프 돌면서 삽입해야 할 인덱스 기억
	// 루프 돌다 중복 발견하면 false 리턴

	Node<T>* newNode = new Node<T>(newItem);

	if (size == 0) {

		size++;
		dummyHead.insertNext(newNode);
		// cout << "삽입 성공" << endl;
		return true;

	}

	Node<T>* tmpNode = &dummyHead;
	Node<T>* insertIndex = dummyHead.getNext();
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = (*tmpNode).getNext();
		item = (*tmpNode).getItem();

		if (*newItem == *item) {

			// cout << "중복 발생" << endl;
			(*newNode).ptr_item = NULL;
			delete newNode;
			// new Item은 어디서 지우나?
			return false;

		}

		if ((*item) > (*newItem)) insertIndex = tmpNode;

	}

	(*insertIndex).insertNext(newNode);

	// cout << "삽입 성공" << endl;
	size++;

	return true;

}

// Iterator 사용하여 다른 클래스에서 수행하자
template<typename T>
void MyList<T>::print() const {

	if (size == 0) return;

	Node<T>* node = dummyHead.getNext();
	for (int i = 0; i < size; i++) {

		cout << *((*node).getItem()) << endl;
		node = (*node).getNext();

	}
}

template<typename T>
Node<T>* MyList<T>::search(const string& key) {

	Node<T>* tmpNode = &dummyHead;
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = (*tmpNode).getNext();
		item = (*tmpNode).getItem();

		if (*item == key) {

			// cout << "중복 발생" << endl;
			return tmpNode;

		}
	}

	return NULL;

}

template<typename T>
int MyList<T>::getSize() const { return size; }

template<typename T>
T* MyList<T>::getItemWithKey(const string& key) {

	Node<T>* node = search(key);
	
	if (node == NULL) return NULL;

	return (*node).getItem();

}

template<typename T>
T* MyList<T>::deleteWithKey(const string& key) {

	Node<T>* node = search(key);

	if (node == NULL) return NULL;

	T* target = (*node).getItem();
	(*node).ptr_item = NULL;
	delete node;
	size--;

	return target;

}