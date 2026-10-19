#include "Node.h"

int Node::GetData()
{
	return _data;
}

void Node::SetData(int data)
{
	_data = data;
}

Node* Node::GetNextNode()
{
	return _nextNode;
}

void Node::SetNextNode(Node* node)
{
	_nextNode = node;
}

Node* Node::GetPreviousNode()
{
	return _previousNode;
}

void Node::SetPreviousNode(Node* node)
{
	_previousNode = node;
}