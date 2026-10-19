#include <iostream>
#include <chrono>
#include <vector>
#include <windows.h>

#include "DynamicArray.h"
#include "List.h"
#include "Node.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	std::vector<int> sizes = { 1000, 10000, 50000, 100000 };
	int iterations = 100;

	std::cout << "Операция вставки в начало" << std::endl;
	std::cout << "Динамический массив \t Двухсвязный список" << std::endl;

	for (int n : sizes)
	{
		DynamicArray arr;
		for (int i = 0; i < n; i++)
		{
			arr.AppendElement(i);
		}
		for (int i = 0; i < 5; i++)
		{
			arr.AddElementAt(0, 999);
			arr.RemoveByIndex(0);
		}

		auto startArr = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			arr.AddElementAt(0, 999);
			arr.RemoveByIndex(0);
		}
		
		auto endArr = std::chrono::high_resolution_clock::now();
		double timeArr = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endArr - startArr).count()) / iterations;
	
		List list;
		for (int i = 0; i < n; i++)
		{
			Node* nd = new Node();
			nd->SetData(i);
			list.AddNode(nd, list.GetSize());
		}

		for (int i = 0; i < 5; i++)
		{
			Node* temp = new Node();
			list.AddNode(temp, 0);
			list.RemoveNodeByIndex(0);
		}

		auto startList = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			Node* newNode = new Node();
			newNode->SetData(999);
			list.AddNode(newNode, 0);
			list.RemoveNodeByIndex(0);
		}
		auto endList = std::chrono::high_resolution_clock::now();
		double timeList = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endList - startList).count()) / iterations;
	
		std::cout << timeArr << "\t\t\t " << timeList << std::endl << std::endl;
	}

	std::cout << "Операция вставки в конец" << std::endl;
	std::cout << "Динамический массив \t Двухсвязный список" << std::endl;

	for (int n : sizes)
	{
		DynamicArray arr;
		
		for (int i = 0; i < n; i++)
		{
			arr.AppendElement(i);
		}
		for (int i = 0; i < 5; i++)
		{
			arr.AddElementAt(arr.GetSize(), 999);
			arr.RemoveByIndex(arr.GetSize() - 1);
		}

		auto startArr = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			arr.AddElementAt(arr.GetSize(), 999);
			arr.RemoveByIndex(arr.GetSize() - 1);
		}

		auto endArr = std::chrono::high_resolution_clock::now();
		double timeArr = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endArr - startArr).count()) / iterations;

		List list;
		for (int i = 0; i < n; i++)
		{
			Node* nd = new Node();
			nd->SetData(i);
			list.AddNode(nd, list.GetSize());
		}

		for (int i = 0; i < 5; i++)
		{
			Node* temp = new Node();
			list.AddNode(temp, list.GetSize());
			list.RemoveNodeByIndex(list.GetSize() - 1);
		}

		auto startList = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			Node* newNode = new Node();
			newNode->SetData(999);
			list.AddNode(newNode, list.GetSize());
			list.RemoveNodeByIndex(list.GetSize() - 1);
		}
		auto endList = std::chrono::high_resolution_clock::now();
		double timeList = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endList - startList).count()) / iterations;

		std::cout << timeArr << "\t\t\t " << timeList << std::endl << std::endl;
	}

	std::cout << "Операция вставки в середину" << std::endl;
	std::cout << "Динамический массив \t Двухсвязный список" << std::endl;

	for (int n : sizes)
	{
		DynamicArray arr;

		for (int i = 0; i < n; i++)
		{
			arr.AppendElement(i);
		}
		for (int i = 0; i < 5; i++)
		{
			arr.AddElementAt(arr.GetSize() / 2, 999);
			arr.RemoveByIndex(arr.GetSize() / 2);
		}

		auto startArr = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			arr.AddElementAt(arr.GetSize() / 2, 999);
			arr.RemoveByIndex(arr.GetSize() / 2);
		}

		auto endArr = std::chrono::high_resolution_clock::now();
		double timeArr = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endArr - startArr).count()) / iterations;

		List list;
		for (int i = 0; i < n; i++)
		{
			Node* nd = new Node();
			nd->SetData(i);
			list.AddNode(nd, list.GetSize());
		}

		for (int i = 0; i < 5; i++)
		{
			Node* temp = new Node();
			list.AddNode(temp, list.GetSize() / 2);
			list.RemoveNodeByIndex(list.GetSize() / 2);
		}

		auto startList = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			Node* newNode = new Node();
			newNode->SetData(999);
			list.AddNode(newNode, list.GetSize() / 2);
			list.RemoveNodeByIndex(list.GetSize() / 2);
		}
		auto endList = std::chrono::high_resolution_clock::now();
		double timeList = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endList - startList).count()) / iterations;

		std::cout << timeArr << "\t\t\t " << timeList << std::endl << std::endl;
	}

	std::cout << "Операция удаления из начала" << std::endl;
	std::cout << "Динамический массив \t Двухсвязный список" << std::endl;

	for (int n : sizes)
	{
		DynamicArray arr;

		for (int i = 0; i < n; i++)
		{
			arr.AppendElement(i);
		}
		for (int i = 0; i < 5; i++)
		{
			arr.RemoveByIndex(arr.GetSize() / 2);
			arr.AddElementAt(arr.GetSize() / 2, 999);
		}

		auto startArr = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			arr.AddElementAt(arr.GetSize() / 2, 999);
			arr.RemoveByIndex(arr.GetSize() / 2);
		}

		auto endArr = std::chrono::high_resolution_clock::now();
		double timeArr = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endArr - startArr).count()) / iterations;

		List list;
		for (int i = 0; i < n; i++)
		{
			Node* nd = new Node();
			nd->SetData(i);
			list.AddNode(nd, list.GetSize());
		}

		for (int i = 0; i < 5; i++)
		{
			Node* temp = new Node();
			list.AddNode(temp, list.GetSize() / 2);
			list.RemoveNodeByIndex(list.GetSize() / 2);
		}

		auto startList = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < iterations; i++)
		{
			Node* newNode = new Node();
			newNode->SetData(999);
			list.AddNode(newNode, list.GetSize() / 2);
			list.RemoveNodeByIndex(list.GetSize() / 2);
		}
		auto endList = std::chrono::high_resolution_clock::now();
		double timeList = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(endList - startList).count()) / iterations;

		std::cout << timeArr << "\t\t\t " << timeList << std::endl << std::endl;
	}

	return 0;
}