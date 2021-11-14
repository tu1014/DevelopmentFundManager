#include "MyList.h"
#include <iostream>
using namespace std;


/*==================== Node ====================*/

template< template <typename, typename> class T,
	typename V, typename K>
Node<T, V, K>::Node() {

	// circular dummy head constructor
	cout << "더미 헤드 생성자 호출" << endl;
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

	cout << "Node 삭제" << endl;
	delete ptr_item;
	// prev, next도 지워야 할까?
	// 아닌거같은데
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

	// 이 포인터가 가리키는 노드의 next에 insert한다
	Node* insertPointer = dummyHead&;
	Node* searchPointer = dummyHead&;

	// 중복 체크, insert 위치 지정
	for (int i = 0; i < size; i++) {

		// 먼저 중복 체크 후 키 중복이 있다면 insert 하지 않고 false 리턴
		


		// 중복이 없다면 정렬 키 비교후 insertPointer 수정 이후 다음 루프 실행


	}

	// insert 


}