#include "Node.h"
#include "List.h"

List::~List()
{
	Clear();
}

Node* List::GetHead()
{
	return _head;
}

Node* List::GetTail()
{
	return _tail;
}

int List::GetSize()
{
	return _size;
}


Node* List::GetNodeByIndex(int index)
{
	if (index >= _size || index < 0) return nullptr;

	Node* node = _head;

	for (int i = 0; i < index; i++)
	{
		node = node->GetNextNode();
	}

	return node;
}

bool List::AddNode(Node* node, int index)
{
	if (index > _size || index < 0) return false;

	// Если новый узел добавляется в начало списка.
	if (index == 0)
	{
		node->SetPreviousNode(nullptr);

		if (_head != nullptr)
		{
			_head->SetPreviousNode(node);
			node->SetNextNode(_head);
		}

		if (_size == 0)
		{
			node->SetNextNode(nullptr);
			_tail = node;
		}

		_head = node;
	}
	else
	{
		// Если узел добавляется в конец списка.
		if (index == _size)
		{
			node->SetNextNode(nullptr);

			if (_tail != nullptr)
			{
				_tail->SetNextNode(node);
				node->SetPreviousNode(_tail);
			}

			_tail = node;
		}
		// Если узел добавляется в середину списка.
		else
		{
			Node* previousNode;
			Node* nextNode;

			previousNode = GetNodeByIndex(index - 1);
			nextNode = previousNode->GetNextNode();

			previousNode->SetNextNode(node);
			node->SetNextNode(nextNode);

			nextNode->SetPreviousNode(node);
			node->SetPreviousNode(previousNode);
		}
	}

	_size++;

	return true;
}

bool List::RemoveNode(Node* node)
{
	Node* previousNode = node->GetPreviousNode();
	Node* nextNode = node->GetNextNode();

	// Если удаляется головной узел.
	if (previousNode == nullptr)
	{
		_head = nextNode;
	}
	// Если удаляется хвостовой узел.
	if (nextNode == nullptr)
	{
		_tail = previousNode;
	}

	delete node;

	if (previousNode != nullptr)
	{
		previousNode->SetNextNode(nextNode);
	}
	if (nextNode != nullptr)
	{
		nextNode->SetPreviousNode(previousNode);
	}

	_size--;

	return true;
}

bool List::RemoveNodeByIndex(int index)
{
	if (index >= _size || index < 0 || _size == 0) return false;

	Node* currentNode = GetNodeByIndex(index);

	return RemoveNode(currentNode);
}

bool List::RemoveNodeByValue(int value)
{
	Node* currentNode = _head;
	bool isDeleted = false;

	for (Node* i = _head; i != nullptr; i = i->GetNextNode())
	{
		if (i->GetData() == value)
		{
			return RemoveNode(i);
		}
	}

	return false;
}

void List::Sort()
{
	if (_head == nullptr || _size <= 1) return;

	for (Node* i = _head; i != nullptr; i = i->GetNextNode())
	{
		for (Node* j = i->GetNextNode(); j != nullptr; j = j->GetNextNode())
		{
			if (i->GetData() > j->GetData())
			{
				int temp = i->GetData();
				i->SetData(j->GetData());
				j->SetData(temp);
			}
		}
	}
}

Node* List::FindNodeByValue(int value)
{
	for (Node* i = _head; i != nullptr; i = i->GetNextNode())
	{
		if (i->GetData() == value)
		{
			return i;
		}
	}

	return nullptr;
}

void List::Clear()
{
	Node* currentNode = _head;

	while (currentNode != nullptr)
	{
		Node* nextNode = currentNode->GetNextNode();

		delete currentNode;

		currentNode = nextNode;
	}
}