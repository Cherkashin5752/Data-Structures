#include <stdexcept>

#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity)
{
	_capacity = capacity;
	_array = new int[_capacity];
}

RingBuffer::~RingBuffer()
{
	delete[] _array;
}

void RingBuffer::AddElement(int data)
{
	_tailIndex++;

	if (_tailIndex == _capacity)
	{
		_tailIndex = 0;
	}

	if (_size == _capacity)
	{
		_headIndex++;

		if (_headIndex == _capacity)
		{
			_headIndex = 0;
		}

		_size--;
	}

	_array[_tailIndex] = data;
	_size++;
}

int RingBuffer::GetElement()
{
	if (_size == 0)
	{
		throw std::out_of_range("RingBuffer is empty");
	}

	_headIndex++;

	if (_headIndex == _capacity)
	{
		_headIndex = 0;
	}

	int headData = _array[_headIndex];
	_array[_headIndex] = 0;
	_size--;

	return headData;
}

void RingBuffer::Resize()
{
	int newCapacity = _capacity * _growthFactor;
	int* newArray = new int[newCapacity];

	int readIndex = _headIndex + 1;

	for (int i = 0; i < _size; i++)
	{
		if (readIndex == _capacity)
		{
			readIndex = 0;
		}

		newArray[i] = _array[readIndex];
		readIndex++;
	}

	delete[] _array;

	_array = newArray;
	_capacity = newCapacity;

	_headIndex = -1;

	if (_size == 0)
	{
		_tailIndex = -1;
	}
	else
	{
		_tailIndex = _size - 1;
	}
}

void RingBuffer::ClearRingBuf()
{
	for (int i = 0; i < _capacity; i++)
	{
		_array[i] = 0;
	}

	_size = 0;
	_headIndex = -1;
	_tailIndex = -1;
}

int* RingBuffer::GetArray()
{
	return _array;
}

int RingBuffer::GetFreeSpace()
{
	return _capacity - _size;
}

int RingBuffer::GetSize()
{
	return _size;
}