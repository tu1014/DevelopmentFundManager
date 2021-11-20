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
Node<T>::Node(T& element) {

	ptr_item = &element;
	ptr_prev = NULL;
	ptr_next = NULL;

}

template<typename T>
Node<T>::~Node() {

	cout << "Node ����" << endl;
	delete ptr_item;
	// prev, next�� ������ �ұ�?
	// �ƴѰŰ�����
	// delete prev;
	// delete next;

}

template<typename T>
Node<T>& Node<T>::getNext() const { return *ptr_next; }

template<typename T>
Node<T>& Node<T>::getPrev() const { return *ptr_prev; }

template<typename T>
void Node<T>::setNext(Node<T>& node) {

	ptr_next = &node;

}

template<typename T>
void Node<T>::setPrev(Node<T>& node) {

	ptr_prev = &node;

}

template<typename T>
T& Node<T>::getItem() { return *ptr_item; }

template<typename T>
void Node<T>::insertNext(Node<T>& node) {

	node.setPrev(*this);
	node.setNext(*ptr_next);
	(*ptr_next).setPrev(node);
	ptr_next = &node;

}


////////////////////////////////////////////////////////////

template<typename T>
MyList<T>::MyList() {

	size = 0;

}

// ������ ���� �ʿ�

template<typename T>
bool MyList<T>::insert(T& newItem) {

	// ��� ������ �� �տ� ����

	// ó������ ������ ���鼭 �ߺ� üũ
	// ���� ���鼭 �����ؾ� �� �ε��� ���
	// ���� ���� �ߺ� �߰��ϸ� false ����

	Node<T>* newNode = new Node<T>(newItem);

	if (size == 0) {

		size++;
		dummyHead.insertNext(*newNode);
		// cout << "���� ����" << endl;
		return true;

	}

	Node<T>* tmpNode = &dummyHead;
	Node<T>* insertIndex = &(dummyHead.getNext());
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = &((*tmpNode).getNext());
		item = &((*tmpNode).getItem());

		if (newItem == *item) {

			// cout << "�ߺ� �߻�" << endl;
			(*newNode).ptr_item = NULL;
			delete newNode;
			return false;

		}

		if ((*item) > (newItem)) insertIndex = tmpNode;

	}

	(*insertIndex).insertNext(*newNode);

	// cout << "���� ����" << endl;
	size++;

	return true;

}

template<typename T>
void MyList<T>::print() const {

	if (size == 0) return;

	Node<T>* node = &(dummyHead.getNext());
	for (int i = 0; i < size; i++) {

		cout << (*node).getItem() << endl;
		node = &((*node).getNext());

	}
}

template<typename T>
int MyList<T>::getSize() const { return size; }