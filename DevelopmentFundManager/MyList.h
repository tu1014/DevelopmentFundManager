#pragma once
using namespace std;


//template < typename T >
//class MyList;
//
//template<typename T>
//class Node;

template < typename T >
class MyList
{

public:

	MyList();
	// ~MyList();

	bool insert(T& ptr_item);
	void print() const;




private:

	class Node {

	public:

		Node(T& ptr_item);
		Node();
		~Node();

		Node& getNext() const;
		Node& getPrev() const;
		void setNext(Node& nextNode);
		void setPrev(Node& prevNode);

		void insertNext(Node& node);

		T& getItem();

	private:

		T* ptr_item;

		Node* ptr_prev;
		Node* ptr_next;

		// 굳이 선언해야 할까?
		// friend class MyList<T>;

	};

	Node dummyHead;
	int size;



};

