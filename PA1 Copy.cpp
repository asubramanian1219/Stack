#include "stdafx.h"
#include "Stack.h"
#include "ArrayStackConst.cpp"
#include <iostream>


using namespace std;
int main() {
	try {
		ArrayStackConst<int>stack;
		stack.push(1);
		cout << stack.top();
		system("pause");
	}
	catch (const char* e) {
		cout << e << endl;
	}



}
