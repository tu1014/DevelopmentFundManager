#pragma once
#include <string>
using namespace std;


template < typename T >
class MyList;

template<typename T>
class Node;

template<typename T>
class Node {

public:

	Node(T* ptr_item);
	Node();
	~Node();

	Node* getNext() const;
	Node* getPrev() const;
	void setNext(Node* nextNode);
	void setPrev(Node* prevNode);

	void insertNext(Node* node);

	T* getItem();

private:

	T* ptr_item;

	Node* ptr_prev;
	Node* ptr_next;

	// 굳이 선언해야 할까?
	friend class MyList<T>;

};

template < typename T >
class MyList
{

public:

	MyList();
	// ~MyList();

	bool insert(T* item);
	void print() const;
	int getSize() const;
	T* getItemWithKey(const string& key);
	T* deleteWithKey(const string& key);



private:

	Node<T> dummyHead;
	int size;

	Node<T>* search(const string& key);
	// Node<T>* targetNode;



};

