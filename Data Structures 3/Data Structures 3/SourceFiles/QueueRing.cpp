#include "QueueRing.h"

QueueRing::QueueRing()
{
	_buffer = new RingBuffer(32);
}

QueueRing::~QueueRing()
{
	delete _buffer;
}

void QueueRing::ClearQueue()
{
	_buffer->ClearRingBuf();
}

void QueueRing::Enqueue(int data)
{
	_buffer->AddElement(data);
}

int QueueRing::Dequeue()
{
	return _buffer->GetElement();
}