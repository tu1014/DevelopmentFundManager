#include "MyList.h"
#include <iostream>
using namespace std;

/*==============Node===================*/

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

	if (ptr_prev != NULL) ptr_prev->ptr_next = ptr_next;
	if (ptr_next != NULL) ptr_next->ptr_prev = ptr_prev;

	delete ptr_item;
}

template<typename T>
T* Node<T>::getItem() const { return ptr_item; }

template<typename T>
void Node<T>::insertNext(Node<T>* node) {

	node->ptr_prev = this;
	node->ptr_next = ptr_next;
	ptr_next->ptr_prev = node;
	ptr_next = node;
}


/*==============MyList===================*/

template<typename T>
MyList<T>::MyList() {

	size = 0;

}

template<typename T>
MyList<T>::~MyList() {

	for (int i = 0; i < size; i++) {

		Node<T>* node = dummyHead.ptr_next;
		delete node;
	}
}

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
		return true;
	}  

	Node<T>* tmpNode = &dummyHead;
	Node<T>* insertIndex = &dummyHead;
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = (*tmpNode).ptr_next;
		item = (*tmpNode).getItem();

		if (*newItem == *item) {

			(*newNode).ptr_item = NULL;
			delete newNode;
			return false;
		}

		if ((*item) > (*newItem)) insertIndex = tmpNode;
	}

	(*insertIndex).insertNext(newNode);

	size++;

	return true;

}

template<typename T>
Node<T>* MyList<T>::search(const string& key) {

	Node<T>* tmpNode = &dummyHead;
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = (*tmpNode).ptr_next;
		item = (*tmpNode).getItem();

		if (*item == key) {

			return tmpNode;
		}
	}

	return NULL;
}

template<typename T>
int MyList<T>::getSize() const { return size; }

template<typename T>
T* MyList<T>::getItemWithKey(const string& key) const {

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

template<typename T>
typename MyList<T>::Iterator MyList<T>::begin() const {
	Iterator iterator(dummyHead.ptr_next);
	return iterator;
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::end() const {
	Iterator iterator(dummyHead.ptr_prev->ptr_next);
	return iterator;
}


/*==============Iterator===================*/

template<typename T>
MyList<T>::Iterator::Iterator(Node<T>* node) {
	pointer = node;
}

template<typename T>
const T& MyList<T>::Iterator::operator*() {
	return *((*pointer).getItem());
}

template<typename T>
ostream& operator<<(ostream& outputStream, const Iterator<T>& iterator) {

	outputStream << *((*(iterator.pointer)).getItem());
	return outputStream;
}

template<typename T>
void MyList<T>::Iterator::operator++() {
	pointer = pointer->ptr_next;
}

template<typename T>
bool MyList<T>::Iterator::operator!=(const Iterator& iterator) const {
	return (pointer != iterator.pointer);
}