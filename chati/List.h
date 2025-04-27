#pragma once
template <class T>
class Node
{
public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};

template <class T>
ref class List
{
	int count;
	Node<T>* head;
public:
	List();
	int Length();
	T At(int);
	void push(T);
	void Delete(int);
	~List(void);
};
