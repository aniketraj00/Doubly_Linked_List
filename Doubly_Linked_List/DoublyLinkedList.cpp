#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : head{ nullptr }, tail{ nullptr }, length{ 0 } {}

void DoublyLinkedList::swapNode(Node* &n1, Node* &n2) {
	Node* temp = n1;
	n1 = n2;
	n2 = temp;
}

int DoublyLinkedList::push(int value) {
	Node* node = new Node(value);
	if(!this->head) {
		this->head = node;
		this->tail = node;
	} else {
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}
	return ++this->length;
}

int DoublyLinkedList::pop() {
	int removed{ -1 };
	if (!this->head) return removed;
	else {
		if (this->head == this->tail) {
			removed = this->head->val;
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
		} else {
			removed = this->tail->val;
			Node* newTail = this->tail->prev;
			this->tail->prev = nullptr;
			delete this->tail;
			newTail->next = nullptr;
			this->tail = newTail;
		}
		this->length--;
		return removed;
	}
}

int DoublyLinkedList::unshift(int value) {
	if (!this->head) return this->push(value);
	else {
		Node* node = new Node(value);
		this->head->prev = node;
		node->next = this->head;
		this->head = node;
		return ++this->length;
	}
}

int DoublyLinkedList::shift() {
	if (this->head == this->tail) return this->pop();
	else {
		int removed = this->head->val;
		Node* newHead = this->head->next;
		newHead->prev = nullptr;
		this->head->next = nullptr;
		delete this->head;
		this->head = newHead;
		this->length--;
		return removed;
	}
}

Node* DoublyLinkedList::getNode(int index) {
	int count{ 0 };
	Node* cur{ this->head };
	while (cur && count != index) {
		cur = cur->next;
		count++;
	}
	return cur;
}

int DoublyLinkedList::get(int index) {
	if (index < 0) return -1;
	else{
		int count{ 0 };
		Node* cur{ this->head };
		while (cur && count != index) {
			cur = cur->next;
			count++;
		}
		if (cur != nullptr) return cur->val;
		return -1;
	}
}

int DoublyLinkedList::set(int index, int value) {
	if (index >= 0 && index < this->length) {
		Node* target = this->getNode(index);
		int curValue = target->val;
		target->val = value;
		return curValue;
	}
	return -1;
}

int DoublyLinkedList::insert(int index, int value) {
	if (index >= 0 && index <= this->length) {
		if (index == 0) return this->unshift(value);
		else if (index == this->length) return this->push(value);
		else {
			Node* n_next = this->getNode(index);
			Node* n = new Node(value);
			Node* n_prev = n_next->prev;
			n->next = n_next;
			n->prev = n_prev;
			n_prev->next = n;
			n_next->prev = n;
			return ++this->length;
		}
	} else {
		return -1;
	}
}

int* DoublyLinkedList::toArray(int* existingArr) {
	if (existingArr) delete[] existingArr;
	if (this->length == 0) return nullptr;
	int* newArr = new int[this->length];
	Node* cur = this->head;
	int count{ 0 };
	while (cur && count < this->length) {
		newArr[count] = cur->val;
		cur = cur->next;
		count++;
	}
	return newArr;
}

int DoublyLinkedList::remove(int index) {
	int removed{ -1 };
	if (index >= 0 && index < this->length) {
		if (index == 0) return this->shift();
		else if (index == this->length - 1) return this->pop();
		else {
			Node* n = this->getNode(index);
			Node* n_prev = n->prev;
			Node* n_next = n->next;
			removed = n->val;
			n->next = nullptr;
			n->prev = nullptr;
			n_next->prev = n_prev;
			n_prev->next = n_next;
			delete n;
			this->length--;
		}
	}
	return removed;
}

int DoublyLinkedList::size() {
	return this->length;
}

void DoublyLinkedList::reverse() {
	Node* cur = this->head;
	while (cur) {
		swapNode(cur->next, cur->prev);
		cur = cur->prev;
	}
	swapNode(this->head, this->tail);
}