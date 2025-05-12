#include "LinkedList.h"
#include <assert.h>
#include <iostream>

using namespace std;

chati::Node::Node()
{
	value = 0;
	next = 0;
}

chati::Node::Node(int val)
{
	value = val;
	next = 0;
}

chati::LinkedList::LinkedList(void)
{
	head = tail = 0;
	count = 0;
}

int chati::LinkedList::Length()
{
	return count;
}

void chati::LinkedList::push_back(int val)
{
	Node* newNode = new Node(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

void chati::LinkedList::push_front(int val)
{
	Node* newNode = new Node(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}
	count++;
}



int chati::LinkedList::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}


void chati::LinkedList::Delete(int element)
{
	Node* tmp = head;

	if (head->value == element)
	{
		Node* del = head;
		head = head->next;
		delete del;
		count--;
		return;
	}


	while (tmp != nullptr && tmp->next->value != element)
	{
		tmp = tmp->next;
	}
	Node* del = tmp->next;
	tmp->next = del->next;
	delete del;

	count--;
}


void chati::LinkedList::updateMessagesSeen(unordered_map<int, Message>& messages, User* currentUser) {
	Node* tmp = head;
	while (tmp != nullptr && tmp != lastSeenMessage) {
		if(messages[tmp->value].getSenderPhone() != currentUser->getMobileNumber()) {
			messages[tmp->value].setIsRead(true);
		}
		tmp = tmp->next;
	}
	lastSeenMessage = head;
}

void chati::LinkedList::clear() {
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	lastSeenMessage = nullptr;
	count = 0;
}



bool chati::LinkedList::empty() const {
	return head == nullptr;
}

chati::LinkedList::~LinkedList(void)
{

}
