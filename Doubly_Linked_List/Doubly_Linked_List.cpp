#include <iostream>
#include "DoublyLinkedList.h"

void printArr(int* arr, int length);

int main() {
	DoublyLinkedList list;

	std::cout << "pushing an element into the list. list size => " << list.push(73) << "\n";
	std::cout << "pushing an element into the list. list size => " << list.push(27) << "\n";
	std::cout << "pushing an element into the list. list size => " << list.push(33) << "\n";
	std::cout << "pushing an element into the list. list size => " << list.push(45) << "\n";
	std::cout << "pushing an element into the list. list size => " << list.push(67) << "\n";
	std::cout << "pushing an element into the list. list size => " << list.push(59) << "\n";
	
	int* arr = list.toArray();
	printArr(arr, list.size());

	std::cout << "popping an el from the list => " << list.pop() << "\n";
	std::cout << "popping an el from the list => " << list.pop() << "\n";
	
	arr = list.toArray(arr);
	printArr(arr, list.size());

	std::cout << "inserting an element (at index = 0). new list size =>" << list.insert(0, -28) << "\n";
	std::cout << "inserting an element (at index = 2). new list size =>" << list.insert(2, 120) << "\n";
	std::cout << "inserting an element (at index = 4). new list size =>" << list.insert(4, 98) << "\n";
	std::cout << "inserting an element (at index = current size). new list size =>" << list.insert(list.size(), -28) << "\n";;
	

	arr = list.toArray(arr);
	printArr(arr, list.size());

	std::cout << "removed (index = 2) => " << list.remove(2) << "\n";

	arr = list.toArray(arr);
	printArr(arr, list.size());

	std::cout << "removed (index = 2) => " << list.remove(2) << "\n";

	arr = list.toArray(arr);
	printArr(arr, list.size());

	std::cout << "removed (index = 0) => " << list.remove(0) << "\n";

	arr = list.toArray(arr);
	printArr(arr, list.size());

	std::cout << "Changing Value (at Index = 1) Currently => " << list.set(1, 88) << "\n";
	
	arr = list.toArray(arr);
	printArr(arr, list.size());

	std::cout << "reversing the list ... \n";
	list.reverse();

	arr = list.toArray(arr);
	printArr(arr, list.size());



	delete[] arr;
}


void printArr(int* arr, int length) {
	std::cout << "list => [";
	for (int i = 0; i < length; i++) {
		i == (length - 1) ? std::cout << arr[i] : std::cout << arr[i] << "  ";
	}
	std::cout << "]\n";
}