#include "MyList.h"
#include <iostream>
using namespace std;


/*==================== Node ====================*/

template< template <typename, typename> class T,
	typename V, typename K>
Node<T, V, K>::Node() {

	// circular dummy head constructor
	cout << "���� ��� ������ ȣ��" << endl;
	ptr_item = null;
	ptr_prev = this;
	ptr_next = this;

}

template< template <typename, typename> class T,
	typename V, typename K>
Node<T, V, K>::Node(T<V, K> element) {

	ptr_item = element&;
	ptr_prev = null;
	ptr_next = null;

}

template< template <typename, typename> class T,
	typename V, typename K>
Node<T, V, K>::~Node() {

	cout << "Node ����" << endl;
	delete ptr_item;
	// prev, next�� ������ �ұ�?
	// �ƴѰŰ�����
	// delete prev;
	// delete next;

}

template< template <typename, typename> class T,
	typename V, typename K>
const Node<T, V, K>& Node<T, V, K>::getNext() const { return ptr_next; }

template< template <typename, typename> class T,
	typename V, typename K>
const Node<T, V, K>& Node<T, V, K>::getPrev() const { return ptr_prev; }

template< template <typename, typename> class T,
	typename V, typename K>
void Node<T, V, K>::setNext(Node<T, V, K>& nextNode) {

	nextNode.setPrev(this);
	nextNode.setNext(ptr_next);
	ptr_next = nextNode;

}

template< template <typename, typename> class T,
	typename V, typename K>
void Node<T, V, K>::setPrev(Node<T, V, K>& prevNode) {

	prevNode.setPrev(ptr_prev);
	prevNode.setNext(this);
	ptr_prev = prevNode;

}

template< template <typename, typename> class T,
	typename V, typename K>
const T<V, K>& Node<T, V, K>::getItem() const { return ptr_item; }



/*==================== MyList ====================*/


template< template <typename, typename> class T,
	typename V, typename K>
MyList<T, V, K>::MyList() {

	dummyHead();
	size = 0;

}

template< template <typename, typename> class T,
	typename V, typename K>
MyList<T, V, K>::~MyList() {


}

template< template <typename, typename> class T,
	typename V, typename K>
bool MyList<T, V, K>::insert(T<V, K> item) {

	// �� �����Ͱ� ����Ű�� ����� next�� insert�Ѵ�
	Node<T, V, K>* insertPointer = dummyHead&;
	Node<T, V, K>* searchPointer = dummyHead&;

	// �ߺ� üũ, insert ��ġ ����
	for (int i = 0; i < size; i++) {

		searchPointer = searchPointer.getNext();

		T<V, K> nodeItem = searchPointer.getItem();

		// ���� �ߺ� üũ �� Ű �ߺ��� �ִٸ� insert ���� �ʰ� false ����
		if ()


		// �ߺ��� ���ٸ� ���� Ű ���� insertPointer ���� ���� ���� ���� ����


	}

	// insert 


}