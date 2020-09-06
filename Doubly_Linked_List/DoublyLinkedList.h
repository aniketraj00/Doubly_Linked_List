#pragma once
#include "Node.h"

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int length;

	Node* getNode(int index);
	void swapNode(Node* &n1, Node* &n2);
public:
	DoublyLinkedList();
	int push(int value);
	int pop();
	int unshift(int value);
	int shift();
	int get(int index);
	int set(int index, int value);
	int insert(int index, int value);
	int remove(int index);
	int* toArray(int* existingArr = nullptr);
	int size();
	void reverse();
};

