#include <iostream>

#include "IOStack.h"
#include "IORingBuffer.h"
#include "IOQueueTwoStack.h"
#include "IOQueueRing.h"
#include "ValueValidator.h"

int main()
{
	bool isRun = true;

	while (isRun)
	{
		std::cout << std::endl;
		std::cout << "=== Main Menu ===" << std::endl
			<< "1. Stack" << std::endl
			<< "2. Circular Buffer" << std::endl
			<< "3. Queue (Circular Buffer)" << std::endl
			<< "4. Queue (Two Stacks)" << std::endl
			<< "5. Exit" << std::endl;


		std::cout << "Choice: ";
		int choice;

		while (!(std::cin >> choice) || !isValidChoice(choice, 1, 5))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid choice. Please try again." << std::endl;
		}

		switch (choice)
		{
			case 1:
			{
				StackInterface();
				break;
			}

			case 2:
			{
				RingBufferInterface();
				break;
			}

			case 3:
			{
				QueueTwoStackInterface();
				break;
			}

			case 4:
			{
				QueueRingBufferInterface();
				break;
			}

			case 5:
			{
				isRun = false;
				break;
			}
		}
	}
	return 0;
}