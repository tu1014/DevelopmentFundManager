#pragma once
#include <string>
using namespace std;


template < typename T >
class MyList;

template<typename T>
class Node;

template<typename T>
class Iterator;

template<typename T>
class Node {

public:

	Node(T* ptr_item);
	Node();
	~Node();

	void insertNext(Node* node);

	T* getItem() const;

private:

	T* ptr_item;

	Node* ptr_prev;
	Node* ptr_next;

	friend class MyList<T>;

};

template < typename T >
class MyList
{

public:

	class Iterator {

	public:

		Iterator(Node<T>* node);
		const T& operator*();
		friend ostream& operator<<(ostream& outputStream, const Iterator& iterator);
		bool operator!=(const Iterator& iterator) const;
		void operator++();

	private:

		Node<T>* pointer;
	};

	MyList();
	~MyList();
	Iterator begin() const;
	Iterator end() const;

	bool insert(T* item);
	int getSize() const;
	T* getItemWithKey(const string& key) const;
	T* deleteWithKey(const string& key);


private:

	Node<T> dummyHead;
	int size;

	Node<T>* search(const string& key);
	// Node<T>* targetNode;



};

