#include <iostream>
#include <chrono>
#include <vector>
#include <windows.h>

#include "DynamicArray.h"
#include "List.h"
#include "Node.h"

void DynamicArrayRemoveByIndex(DynamicArray* arr, int index, const int size, const int iterations)
{
	int targetIndex = index;
	for (int i = 0; i < 5; i++)
	{
		arr->AppendElement(5);
		arr->RemoveByIndex(0);
	}

	for (int i = 0; i < size; i++)
	{
		arr->AppendElement(999);
	}

	auto start = std::chrono::high_resolution_clock::now();

	if (index == 0)
	{
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			arr->RemoveByIndex(index);
		}
	}
	else
	{
		if (index == size)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < iterations; i++)
			{
				arr->RemoveByIndex(targetIndex);
				targetIndex = arr->GetSize();
			}
		}
		else
		{
			if (index == size / 2)
			{
				start = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < iterations; i++)
				{
					arr->RemoveByIndex(targetIndex);
					targetIndex = arr->GetSize() / 2;
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_per_operation = static_cast<double>(duration.count()) / iterations;

	std::cout << "[DynamicArray] Size: " << size
		<< " | Index: " << index
		<< " | Average time to remove: " << time_per_operation << " mcs\n";
}

void DynamicArrayAddByIndex(DynamicArray* arr, int index, const int size, const int iterations)
{
	int targetIndex = index;
	for (int i = 0; i < 5; i++)
	{
		arr->AppendElement(5);
		arr->RemoveByIndex(0);
	}

	for (int i = 0; i < size; i++)
	{
		arr->AppendElement(999);
	}

	auto start = std::chrono::high_resolution_clock::now();

	if (index == 0)
	{
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			arr->AddElementAt(index, 999);
		}
	}
	else
	{
		if (index == size)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < iterations; i++)
			{
				arr->AddElementAt(targetIndex, 999);
				targetIndex = arr->GetSize();
			}
		}
		else
		{
			if (index == size / 2)
			{
				start = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < iterations; i++)
				{
					arr->AddElementAt(targetIndex, 999);
					targetIndex = arr->GetSize() / 2;
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_per_operation = static_cast<double>(duration.count()) / iterations;

	std::cout << "[DynamicArray] Size: " << size
		<< " | Index: " << index
		<< " | Average time to add: " << time_per_operation << " mcs\n";
}

void ListRemoveByIndex(List* list, int index, const int size, const int iterations)
{
	int targetIndex = index;
	for (int i = 0; i < 5; i++)
	{
		Node* node = new Node();
		node->SetData(999);
		list->AddNode(node, 0);
		list->RemoveNodeByIndex(0);
	}

	for (int i = 0; i < size; i++)
	{
		Node* node = new Node();
		list->AddNode(node, 0);
	}

	auto start = std::chrono::high_resolution_clock::now();

	if (index == 0)
	{
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			list->RemoveNodeByIndex(index);
		}
	}
	else
	{
		if (index == size)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < iterations; i++)
			{
				list->RemoveNodeByIndex(targetIndex);
				targetIndex = list->GetSize();
			}
		}
		else
		{
			if (index == size / 2)
			{
				start = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < iterations; i++)
				{
					list->RemoveNodeByIndex(targetIndex);
					targetIndex = list->GetSize() / 2;
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_per_operation = static_cast<double>(duration.count()) / iterations;

	std::cout << "[List] Size: " << size
		<< " | Index: " << index
		<< " | Average time to remove: " << time_per_operation << " mcs\n";
}

void ListAddByIndex(List* list, int index, const int size, const int iterations)
{
	int targetIndex = index;
	for (int i = 0; i < 5; i++)
	{
		Node* node = new Node();
		node->SetData(999);
		list->AddNode(node, 0);
		list->RemoveNodeByIndex(0);
	}

	for (int i = 0; i < size; i++)
	{
		Node* node = new Node();
		list->AddNode(node, 0);
	}

	auto start = std::chrono::high_resolution_clock::now();

	if (index == 0)
	{
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			Node* node = new Node();
			list->AddNode(node, index);
		}
	}
	else
	{
		if (index == size)
		{
			start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < iterations; i++)
			{
				Node* node = new Node();
				list->AddNode(node, targetIndex);
				targetIndex = list->GetSize();
			}
		}
		else
		{
			if (index == size / 2)
			{
				start = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < iterations; i++)
				{
					Node* node = new Node();
					list->AddNode(node, targetIndex);
					targetIndex = list->GetSize() / 2;
				}
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_per_operation = static_cast<double>(duration.count()) / iterations;

	std::cout << "[List] Size: " << size
		<< " | Index: " << index
		<< " | Average time to add: " << time_per_operation << " mcs\n";
}

void main()
{
	DynamicArray* arr;

	int sizes[4] = {1000, 10000, 50000, 100000};

	for (int size : sizes)
	{
		arr = new DynamicArray();
		DynamicArrayRemoveByIndex(arr, 0, size, 50);
		delete arr;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		arr = new DynamicArray();
		DynamicArrayRemoveByIndex(arr, size, size, 50);
		delete arr;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		arr = new DynamicArray();
		DynamicArrayRemoveByIndex(arr, size / 2, size, 50);
		delete arr;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		arr = new DynamicArray();
		DynamicArrayAddByIndex(arr, 0, size, 50);
		delete arr;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		arr = new DynamicArray();
		DynamicArrayAddByIndex(arr, size, size, 50);
		delete arr;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		arr = new DynamicArray();
		DynamicArrayAddByIndex(arr, size / 2, size, 50);
		delete arr;
	}

	std::cout << std::endl;

	List* list = new List();

	for (int size : sizes)
	{
		list = new List();
		ListRemoveByIndex(list, 0, size, 50);
		delete list;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		list = new List();
		ListRemoveByIndex(list, size, size, 50);
		delete list;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		list = new List();
		ListRemoveByIndex(list, size / 2, size, 50);
		delete list;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		list = new List();
		ListAddByIndex(list, 0, size, 50);
		delete list;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		list = new List();
		ListAddByIndex(list, size, size, 50);
		delete list;
	}

	std::cout << std::endl;

	for (int size : sizes)
	{
		list = new List();
		ListAddByIndex(list, size / 2, size, 50);
		delete list;
	}
}