#pragma once

//class MyList;
//class Node;

class MyList
{

public:

	MyList();
	~MyList();

	bool insert(int& ptr_item);
	void print() const;




private:

	class Node {

	public:

		Node(int& ptr_item);
		Node();
		~Node();

		Node& getNext() const;
		Node& getPrev() const;
		void setNext(Node& node);
		void setPrev(Node& node);

		void insertNext(Node& node);

		int& getItem();

	private:

		int* ptr_item;

		Node* ptr_prev;
		Node* ptr_next;

		// 굳이 선언해야 할까?
		friend class MyList;

	};

	Node dummyHead;
	int size;



};
