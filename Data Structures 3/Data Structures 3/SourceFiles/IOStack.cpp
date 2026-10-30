#include <iostream>

#include "Stack.h"
#include "IOStack.h"
#include "ValueValidator.h"

void StackInterface()
{
	Stack* stack = new Stack();

	bool isRun = true;
	int choice = -1;
	
	while (isRun)
	{
		std::cout << std::endl;
		std::cout << "=== Stack Menu ===" << std::endl
			<< "1. Push" << std::endl
			<< "2. Pop" << std::endl
			<< "3. Clear" << std::endl
			<< "4. Back to Main Menu" << std::endl;

		std::cout << "Choice: ";
		
		int choice;

		while (!(std::cin >> choice) || !isValidChoice(choice, 1, 4))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid choice. Please try again." << std::endl;
		}

		switch (choice)
		{
			case 1:
			{
				std::cout << "Enter a value: ";

				int value;
				std::cin >> value;

				stack->Push(value);

				break;
			}

			case 2:
			{
				try
				{
					int poppedValue = stack->Pop();

					std::cout << "From stack popped a value " << poppedValue << std::endl;
				}
				catch (std::out_of_range)
				{
					std::cout << "Stack is empty" << std::endl;
				}

				break;
			}

			case 3:
			{
				stack->ClearStack();

				break;
			}

			case 4:
			{
				delete stack;

				isRun = false;

				break;
			}
		}
	}
}