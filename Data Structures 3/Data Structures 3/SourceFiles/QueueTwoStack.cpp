#include <stdexcept>

#include "QueueTwoStack.h"

QueueTwoStack::QueueTwoStack()
{
	_inStack = new Stack();
	_outStack = new Stack();
}

QueueTwoStack::~QueueTwoStack()
{
	delete _inStack;
	delete _outStack;
}

void QueueTwoStack::ClearQueue()
{
	_inStack->ClearStack();
	_outStack->ClearStack();
}

void QueueTwoStack::Enqueue(int data)
{
	_inStack->Push(data);
}

int QueueTwoStack::Dequeue()
{
	if (_outStack->Peek() == nullptr)
	{
		if (_inStack->Peek() == nullptr)
		{
			throw std::out_of_range("Queue is empty");
		}

		while (_inStack->Peek() != nullptr)
		{
			_outStack->Push(_inStack->Pop());
		}
	}

	return _outStack->Pop();
}