#include <stdexcept>

#include "Stack.h"

Stack::Stack()
{
	_top = nullptr;
}

Stack::~Stack()
{
	ClearStack();
}

Node* Stack::Peek()
{
	return _top;
}

void Stack::Push(int data)
{
	Node* newNode = new Node(data);

	newNode->SetNext(_top);
	
	_top = newNode;
}

int Stack::Pop()
{
	if (_top == nullptr)
	{
		throw std::out_of_range("Stack is empty");
	}

	int topData = _top->GetData();

	Node* oldTopNode = _top;

	_top = _top->GetNext();

	delete oldTopNode;

	return topData;
}

void Stack::ClearStack()
{
	while (_top != nullptr)
	{
		Node* oldTopNode = _top;

		_top = _top->GetNext();

		delete oldTopNode;
	}
}