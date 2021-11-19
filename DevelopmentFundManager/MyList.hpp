#include "MyList.h"
#include <iostream>
using namespace std;


MyList::Node::Node() {

	// circular dummy head constructor
	ptr_item = NULL;
	ptr_prev = this;
	ptr_next = this;

}


// const 붙이면 안된다???
MyList::Node::Node(int& element) {

	ptr_item = &element;
	ptr_prev = NULL;
	ptr_next = NULL;

}


MyList::Node::~Node() {

	std::cout << "Node 삭제" << endl;
	delete ptr_item;
	// prev, next도 지워야 할까?
	// 아닌거같은데
	// delete prev;
	// delete next;

}

MyList::Node& MyList::Node::getNext() const { return *ptr_next; }

MyList::Node& MyList::Node::getPrev() const { return *ptr_prev; }

void MyList::Node::setNext(Node& node) {

	/*nextNode.setPrev(*this);
	nextNode.setNext(*ptr_next);
	ptr_next = &nextNode;*/

	/*node.setPrev(*this);
	node.setNext(*ptr_next);

	ptr_next = &node;
	(*ptr_next).setPrev(node);*/

	ptr_next = &node;


}

void MyList::Node::setPrev(Node& node) {


	ptr_prev = &node;

	/*node.setPrev(*ptr_prev);
	node.setNext(*this);

	ptr_prev = &node;
	(*ptr_prev).setNext(node);*/


	/*prevNode.setPrev(*ptr_prev);
	prevNode.setNext(*this);
	ptr_prev = &prevNode;*/

}

int& MyList::Node::getItem() { return *ptr_item; }


void MyList::Node::insertNext(Node& node) {

	node.setPrev(*this);
	node.setNext(*ptr_next);
	(*ptr_next).setPrev(node);
	ptr_next = &node;

	/*(*newNode).setPrev(*insertIndex);
	(*newNode).setNext((*insertIndex).getNext());
	(*insertIndex).getNext().setPrev(*newNode);
	(*insertIndex).setNext(*newNode);*/

}

////////////////////////////////////////////////////////////

MyList::MyList() {

	size = 0;

}

MyList::~MyList() {

	cout << "MyList 삭제" << endl;
	// 노드 따라가며 삭제 필요

}

bool MyList::insert(int& newItem) {

	// 비어 있으면 맨 앞에 삽입

	// 처음부터 끝까지 돌면서 중복 체크
	// 루프 돌면서 삽입해야 할 인덱스 기억
	// 루프 돌다 중복 발견하면 false 리턴

	Node* newNode = new Node(newItem);

	if (size == 0) {

		size++;
		/*(*newNode).setPrev(dummyHead);
		(*newNode).setNext(dummyHead);
		dummyHead.setPrev(*newNode);
		dummyHead.setNext(*newNode);*/

		dummyHead.insertNext(*newNode);

		cout << "삽입 성공" << endl;
		return true;

	}

	Node* tmpNode = &dummyHead;
	Node* insertIndex = &(dummyHead.getNext());
	int* ptr_item;
	for (int i = 0; i < size; i++) {

		tmpNode = &((*tmpNode).getNext());
		ptr_item = &((*tmpNode).getItem());

		if (newItem == *ptr_item) {

			cout << "중복 발생" << endl;
			delete newNode;
			return false;

		}

		if ((*ptr_item) < (newItem)) insertIndex = tmpNode;

	}

	/*(*newNode).setPrev(*insertIndex);
	(*newNode).setNext((*insertIndex).getNext());
	(*insertIndex).getNext().setPrev(*newNode);
	(*insertIndex).setNext(*newNode);*/

	(*insertIndex).insertNext(*newNode);


	cout << "삽입 성공" << endl;
	size++;

	return true;

}

void MyList::print() const {

	cout << "출력" << endl;

	if (size == 0) return;

	Node* node = &(dummyHead.getNext());
	for (int i = 0; i < size; i++) {

		cout << (*node).getItem() << endl;
		node = &((*node).getNext());

	}

	cout << "출력 끝" << endl;


}