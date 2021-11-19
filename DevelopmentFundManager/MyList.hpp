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

	ptr_item = element;
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
const Node<T>& Node<T>::getNext() const { return ptr_next; }

template<typename T>
const Node<T>& Node<T>::getPrev() const { return ptr_prev; }

template<typename T>
void Node<T>::setNext(Node& nextNode) {

	(*nextNode).setPrev(this);
	(*nextNode).setNext(ptr_next);
	ptr_next = nextNode;

}

template<typename T>
void Node<T>::setPrev(Node& prevNode) {

	(*prevNode).setPrev(ptr_prev);
	(*prevNode).setNext(this);
	ptr_prev = prevNode;

}

template<typename T>
const T& Node<T>::getItem() const { return ptr_item; }


////////////////////////////////////////////////////////////

template<typename T>
MyList<T>::MyList() {

	size = 0;

}

template<typename T>
bool MyList<T>::insert(const T& newItem) {

	// ��� ������ �� �տ� ����

	// ó������ ������ ���鼭 �ߺ� üũ
	// ���� ���鼭 �����ؾ� �� �ε��� ���
	// ���� ���� �ߺ� �߰��ϸ� false ����

	Node<T>* newNode = new Node<T>(newItem);

	if (size == 0) {

		size++;
		(*newNode).setPrev(dummyHead);
		(*newNode).setNext(dummyHead);
		dummyHead.setPrev(newNode);
		dummyHead.setNext(newNode);
		cout << "���� ����" << endl;
		return true;

	}

	Node<T>* tmpNode = dummyHead;
	Node<T>* insertIndex = dummyHead.getNext();
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = (*tmpNode).getNext();
		item = (*tmpNode).getItem();

		if (newItem == *item) {

			cout << "�ߺ� �߻�" << endl;
			delete newNode;
			return false;

		}

		if ((*item) < (newItem)) insertIndex = tmpNode;

	}

	(*newNode).setPrev(insertIndex);
	(*newNode).setNext((*insertIndex).getNext());
	(*(*insertIndex).getNext()).setPrev(newNode);
	(*insertIndex).setNext(newNode);

	cout << "���� ����" << endl;
	size++;

	return true;

}

template<typename T>
void MyList<T>::print() const {

	cout << "���" << endl;

	if (size == 0) return;

	Node<T>* node = dummyHead.getNext();
	for (int i = 0; i < size; i++) {

		cout << (*(*node).getItem) << endl;
		node = (*node).getNext();

	}

	cout << "��� ��" << endl;


}