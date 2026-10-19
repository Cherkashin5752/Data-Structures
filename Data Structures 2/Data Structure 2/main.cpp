#include <iostream>
#include <windows.h>

#include "List.h"
#include "Node.h"
// TODO: Разнести по папкам в проводнике
void PrintLinkedList(List* list)
{
	for (Node* i = list->GetHead(); i != nullptr; i = i->GetNextNode())
	{
		std::cout << i->GetData();
		if (i->GetNextNode() != nullptr)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

bool CorrectChoise(int select)
{
	if (select > -1 && select < 8) return true;
	return false;
}

int main()
{
	SetConsoleCP(650001);
	SetConsoleOutputCP(65001);

	List* list = new List();

	std::cout << "Laboratory Work #2 – Doubly Linked List" << std::endl << std::endl;

	bool isRun = true;
	int select = -1;

	while (isRun)
	{
		std::cout << "Current List:" << std::endl;
		PrintLinkedList(list);
		std::cout << std::endl;

		std::cout << "Select the action you want to do:" << std::endl
			<< "1. Remove an element by index from a list" << std::endl
			<< "2. Remove an element by value from a list" << std::endl
			<< "3. Insert an element at the beginning" << std::endl
			<< "4. Insert an element at the end" << std::endl
			<< "5. Insert after a certain element" << std::endl
			<< "6. Sort list" << std::endl
			<< "7. Linear search for an element in a list" << std::endl
			<< "0. Exit" << std::endl;

		std::cout << "Your input: ";


		std::cin >> select;
		
		while (!CorrectChoise(select))
		{
			std::cin >> select;
			std::cout << "There's no such option. Try again" << std::endl;
		}

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (select)
		{
			case 1:
			{
				int index;

				std::cout << "Enter a index of element being deleted: ";
				std::cin >> index;
				if (!(list->RemoveNodeByIndex(index)))
				{
					SetConsoleTextAttribute(hConsole, 12);
					std::cout << "List hasn't element with such index" << std::endl;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
				{
					std::cout << "Element was deleted" << std::endl;
				}
				std::cout << std::endl;
				continue;
			}
			case 2:
			{
				int value;
				
				std::cout << "Enter a value of element being deleted: ";
				std::cin >> value;
				if (!(list->RemoveNodeByValue(value)))
				{
					SetConsoleTextAttribute(hConsole, 12);
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << "List hasn't element with such value" << std::endl;
				}
				else
				{
					std::cout << "Element was deleted" << std::endl;
				}
				std::cout << std::endl;
				continue;
			}
			case 3:
			{
				int value;

				std::cout << "Enter a value of new node: ";
				std::cin >> value;

				Node* newNode = new Node(value);
				list->AddNode(newNode, 0);

				std::cout << std::endl;
				continue;
			}
			case 4:
			{
				int value;

				std::cout << "Enter a value of new node: ";
				std::cin >> value;

				Node* newNode = new Node(value);
				list->AddNode(newNode, list->GetSize());

				std::cout << std::endl;
				continue;
			}
			case 5:
			{
				int value;
				int index;
				
				std::cout << "Enter a value of new node: ";
				std::cin >> value;

				std::cout << "Enter a index of new node: ";
				std::cin >> index;

				Node* newNode = new Node(value);
				if (!(list->AddNode(newNode, index)))
				{
					SetConsoleTextAttribute(hConsole, 12);
					std::cout << "Index was out of range of list" << std::endl;
					SetConsoleTextAttribute(hConsole, 15);
				}

				std::cout << std::endl;
				continue;
			}
			case 6:
			{
				list->Sort();

				std::cout << std::endl;
				continue;
			}
			case 7:
			{
				int searchingValue;

				std::cout << "Enter searching value: ";
				std::cin >> searchingValue;

				Node* searchingNode = list->FindNodeByValue(searchingValue);
				
				// Если нашёлся узел по значению
				if (searchingNode != nullptr)
				{
					// Если этот узел - голова
					if (searchingNode->GetPreviousNode() == nullptr)
					{
						std::cout << "Searching value stands before value "
							<< searchingNode->GetNextNode()->GetData() << std::endl;
					}
					else
					{
						if (searchingNode->GetNextNode() == nullptr)
						{
							std::cout << "Searching value stands after value "
								<< searchingNode->GetPreviousNode()->GetData() << std::endl;
						}
						else
						{
							std::cout << "Searching value " << searchingValue << " stands between values "
								<< searchingNode->GetPreviousNode()->GetData() << " and "
								<< searchingNode->GetNextNode()->GetData() << std::endl;
						}
					}
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 12);
					std::cout << "List hasn't element with such value" << std::endl;
					SetConsoleTextAttribute(hConsole, 15);
				}

				std::cout << std::endl;
				continue;
			}
			case 0:
			{
				isRun = false;

				continue;
			}
		}
	}

	delete list;

	return 0;
}