#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

template <class Type>
class AbstractStack
{
private:
	// data goes here

public:
	AbstractStack(void) {}

	~AbstractStack(void) {}

	bool isEmpty(void) {}

	int size(void) {}

	Type top() {}

	Type pop() {}

	void push(Type e) {}
};

#endif