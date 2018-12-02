#include "stdafx.h"
#include "Stack.h"
#include "StopWatch.h"
#include <array>
#include <stdlib.h>
#include <iostream>

using namespace std;


template<class Type>
class ArrayStackConst:AbstractStack<Type>
{
private:
	int n = 300000;
	Type * data;
	int count;
public:
	ArrayStackConst() {
		count = 0;
		data = new Type[n];
	}
	~ArrayStackConst() {
		cout << "The array has been deleted.";
	}
	bool isEmpty() {
		if (count == 0)
			return true;
		return false;
	}
	int size() {
		if (count > 0) {
			return count;
		}
		else
			return 0;
	}
	Type top() {

		if (count > 0) {
			return data[count];
		}
		else {
			throw "Empty stack!";
		}

	}
	Type pop() {
		if (count > 0) {
			Type temp = data[count];
			count--;
			return temp;
		}
	}
	void push(Type e) {
		if (count+1 == n) {
			
			Type* temp = new Type[count + 150]; //make a temp array for the data that is 150 elements bigger than the previous one
			for (int i = 0; i < n; i++) {
				temp[i] = data[i]; //transfer data to temp
			}
			data = temp; //data is now equal to the temp array and can use the same functions as the rest of the stack
			delete[] temp;
			temp = NULL;
			n = n + 150;
			data[count] = e;
			count++;



		}
		else {


			data[count] = e;
			count++;
		}
	}



};



template<class Type>
class ArrayStackDouble :AbstractStack<Type>
{
private:
	int n = 300;
	Type * data;
	int count;
public:
	ArrayStackDouble() {
		count = 0;
		data = new Type[n];
	}
	~ArrayStackDouble() {
		cout << "The array has been deleted.";
	}
	bool isEmpty() {
		if (count == 0)
			return true;
		return false;
	}
	int size() {
		if (count > 0) {
			return count;
		}
		else
			return 0;
	}
	Type top() {

		if (count > 0) {
			return data[count];
		}
		else {
			throw "Empty stack!";
		}

	}
	Type pop() {
		if (count > 0) {
			Type temp = data[count];
			count--;
			return temp;
		}
	}
	void push(Type e) {
		if (count + 1 == n) {

			Type* temp = new Type[count*2]; //make a temp array for the data that is twice as big as the previous one
			for (int i = 0; i < n; i++) {
				temp[i] = data[i]; //transfer data to temp
			}
			data = temp; //data is now equal to the temp array and can use the same functions as the rest of the stack
			delete[] temp;
			n = n*2;
			data[count] = e;
			count++;



		}
		else {


			data[count] = e;
			count++;
		}
	}



};

template<class Type>
class LinkedList :AbstractStack<Type> {
private:
	struct node {
		Type data;
		node *next;
	};
	node *head;
	node *tail;
	int count = 0;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;

	}
	~LinkedList() {
		cout << "Linked list is being destructed.";
	}
	bool isEmpty() {
		return (head == NULL);
	}
	int size() {
		return count;
	}
	Type top() {
		if (head == NULL) {
			throw "Empty stack!";
		}
		else
			return head->data;

	}
	Type pop() {
		if (!isEmpty()) {
			node *temp = head;
			head = head->next;
			count--;
			return temp->data;
		}
		else
			throw "Empty stack!";
	}
	void push(Type e) {
		node *curr = new node;
		curr->data = e;
		curr->next = head;
		head = curr;
		count++;
	}
};


int main() {
	try {
		StopWatch t;
		ArrayStackConst<int>stack;
		ArrayStackDouble<int>stack2;
		LinkedList<int>stack3;
		t.start();
		for (int i = 0; i < 1000000; i++) {
			stack2.push(i);
			
			if (i % 10000 == 0) {

				cout << t.ms() << endl;
			}
			
		}
		
		t.stop();
		
		cout << stack2.size()<<endl;
		system("pause");
		
		
	}
	catch (const char* e) {
		cout << e << endl;
	}



}
