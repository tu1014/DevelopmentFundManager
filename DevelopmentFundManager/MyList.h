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

	Node(T& item);
	Node();
	~Node();

	const Node& getNext() const;
	const Node& getPrev() const;
	void setNext(Node& nextNode);
	void setPrev(Node& prevNode);


private:

	T* ptr_item;

	Node* ptr_prev;
	Node* ptr_next;

	// 굳이 선언해야 할까?
	friend class MyList<T>;

};
