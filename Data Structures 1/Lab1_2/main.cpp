#include <iostream>

#include "DynamicArray.h"

bool CorrectInput(int select)
{
	if (select >= 0 && select < 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	DynamicArray array;

	bool isRun = true;

	int select;

	while (isRun)
	{
		std::cout << "Current Array: " << std::endl;
	
		for (int i = 0; i < array.GetSize(); i++)
		{
			std::cout << array.GetElement(i) << '\t';
		}
		std::cout << std::endl;

		std::cout << "Select the action you want to do:" << std::endl
			<< "1. Remove an element by index from an array" << std::endl
			<< "2. Remove an element by value from an array" << std::endl
			<< "3. Insert an element at the begining" << std::endl
			<< "4. Insert an element at the end" << std::endl
			<< "5. Insert after a certain element" << std::endl
			<< "6. Sort array" << std::endl
			<< "7. Linear search for an element in an array" << std::endl
			<< "8. Binary search for an element in an array" << std::endl
			<< "0. To close program" << std::endl;

		std::cout << std::endl;

		std::cout << "Your input: ";
		std::cin >> select;

		if (!CorrectInput(select))
		{
			std::cout << "Unknown command. Try entering the command again" << std::endl;
			continue;
		}

		switch (select)
		{
			case 1:
			{
				std::cout << "Enter index: ";
				
				int index;
				std::cin >> index;

				if (array.RemoveByIndex(index) == -1)
				{
					std::cout << "There's no such index in array" << std::endl;
				}

				continue;
			}
			case 2:
			{
				std::cout << "Enter value: ";
				
				int value;
				std::cin >> value;

				array.RemoveByValue(value);
				
				continue;
			}
			case 3:
			{
				std::cout << "Enter value: ";
				
				int value;
				std::cin >> value;

				array.PrependElement(value);
			
				continue;
			}
			case 4:
			{
				std::cout << "Enter value: ";
				
				int value;
				std::cin >> value;

				array.AppendElement(value);
			
				continue;
			}
			case 5:
			{
				std::cout << "Enter index: ";
				
				int index;
				std::cin >> index;

				std::cout << "Enter value: ";
				
				int value;
				std::cin >> value;

				if (array.AddElementAt(index, value) == -1)
				{
					std::cout << "There's no such index in array" << std::endl;
				}
			
				continue;
			}
			case 6:
			{
				array.SortArray();

				std::cout << "Array was sort" << std::endl;
			
				continue;
			}
			case 7:
			{
				std::cout << "Enter searching value: ";
				int searchingValue;
				std::cin >> searchingValue;

				int searchingValueIndex = array.LinearSearch(searchingValue);

				if (searchingValueIndex == -1)
				{
					std::cout << "There's no such value in array" << std::endl;
					continue;
				}

				std::cout << "The number " << searchingValue << "has the index: " << array.LinearSearch(searchingValue) << std::endl;
			
				continue;
			}
			case 8:
			{
				std::cout << "Enter searching value: ";
				int searchingValue;
				std::cin >> searchingValue;

				int searchingValueIndex = array.LinearSearch(searchingValue);

				if (searchingValueIndex == -1)
				{
					std::cout << "There's no such value in array" << std::endl;
					continue;
				}

				std::cout << "The number " << searchingValue << " has the index: " << array.BinarySearch(searchingValue) << std::endl;
			
				continue;
			}
			case 0:
			{
				isRun = false;
			
				continue;
			}
		}
	}

	return 0;
}