#pragma once
using namespace std;

template<typename T>
class MyList
{

public:

	MyList();
	~MyList();




private:

	Node dummyHead;
	int size;



};

template<typename T>
class Node {

public:

	Node(T element);
	Node();
	~Node();

	const Node& getNext() const;
	const Node& getPrev() const;
	void setNext(Node& nextNode);
	void setPrev(Node& prevNode);


private:

	T* ptr_element;

	Node* prev;
	Node* next;

	// ���� �����ؾ� �ұ�?
	friend class MyList<T>;

};
