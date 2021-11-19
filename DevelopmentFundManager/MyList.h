#pragma once
using namespace std;


template < typename T >
class MyList;

template<typename T>
class Node;

template < typename T >
class MyList
{

public:

	MyList();
	// ~MyList();

	bool insert(const T& ptr_item);
	void print() const;




private:

	Node<T> dummyHead;
	int size;



};

template<typename T>
class Node {

public:

	Node(T& ptr_item);
	Node();
	~Node();

	const Node<T>& getNext() const;
	const Node<T>& getPrev() const;
	void setNext(Node<T>& nextNode);
	void setPrev(Node<T>& prevNode);

	const T& getItem() const;

private:

	T* ptr_item;

	Node<T>* ptr_prev;
	Node<T>* ptr_next;

	// 굳이 선언해야 할까?
	friend class MyList<T>;

};
