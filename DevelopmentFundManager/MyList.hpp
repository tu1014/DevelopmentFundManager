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

	cout << "Node ����" << endl;

	if(ptr_prev != NULL) (*ptr_prev).setNext(ptr_next);
	if (ptr_next != NULL) (*ptr_next).setPrev(ptr_prev);

	delete ptr_item;

	// prev, next�� ������ �ұ�?
	// �ƴѰŰ�����
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

	// ���� get set �� �ʿ� ���� ����� �ٲ�����
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

// ������ ���� �ʿ�
template<typename T>
MyList<T>::~MyList() {

	cout << "MyList ������ ȣ��" << endl;
	for (int i = 0; i < size; i++) {

		Node<T>* node = dummyHead.getNext();
		cout << *((*node).getItem()) << endl;
		delete node;

	}

}

template<typename T>
bool MyList<T>::insert(T* newItem) {

	// ��� ������ �� �տ� ����

	// ó������ ������ ���鼭 �ߺ� üũ
	// ���� ���鼭 �����ؾ� �� �ε��� ���
	// ���� ���� �ߺ� �߰��ϸ� false ����

	Node<T>* newNode = new Node<T>(newItem);

	if (size == 0) {

		size++;
		dummyHead.insertNext(newNode);
		// cout << "���� ����" << endl;
		return true;

	}

	Node<T>* tmpNode = &dummyHead;
	Node<T>* insertIndex = &dummyHead;
	T* item;
	for (int i = 0; i < size; i++) {

		tmpNode = (*tmpNode).getNext();
		item = (*tmpNode).getItem();

		if (*newItem == *item) {

			// cout << "�ߺ� �߻�" << endl;
			(*newNode).ptr_item = NULL;
			delete newNode;
			// new Item�� ��� ���쳪?
			return false;

		}

		if ((*item) > (*newItem)) insertIndex = tmpNode;

	}

	(*insertIndex).insertNext(newNode);

	// cout << "���� ����" << endl;
	size++;

	return true;

}

// Iterator ����Ͽ� �ٸ� Ŭ�������� ��������
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

			// cout << "�ߺ� �߻�" << endl;
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

template<typename T>
MyList<T>::Iterator MyList<T>::begin() const {
	return MyList<T>::Iterator(dummyHead.getNext());
}

template<typename T>
MyList<T>::Iterator MyList<T>::end() const {
	return MyList<T>::Iterator(dummyHead.getPrev());
}


////////////////////////////////////

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
	pointer = pointer->getNext();
}

template<typename T>
bool MyList<T>::Iterator::operator!=(const Iterator& iterator) const {
	return (pointer != iterator.pointer);
}