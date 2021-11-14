#pragma once
using namespace std;

template< template <typename, typename> class T,
	      typename V, typename K>
class MyList
{

public:

	MyList();
	~MyList();

	bool insert(T<V, K> item);
	void addFirst(T<V, K> item); // test��
	void print() const;


private:

	Node dummyHead;
	int size;



};

template< template <typename, typename> class T,
	typename V, typename K>
class Node {

public:

	Node(T<V, K> element);
	Node();
	~Node();

	const T<V, K>& getItem() const;
	const Node& getNext() const;
	const Node& getPrev() const;
	void setNext(Node& nextNode);
	void setPrev(Node& prevNode);


private:

	T<V, K>* ptr_item;

	Node* ptr_prev;
	Node* ptr_next;

	// ���� �����ؾ� �ұ�?
	// friend class MyList;

};
