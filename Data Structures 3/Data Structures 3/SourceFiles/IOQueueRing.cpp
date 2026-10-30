#include <iostream>

#include "QueueRing.h"
#include "IOQueueRing.h"
#include "ValueValidator.h"

void QueueRingBufferInterface()
{
	QueueRing* queueRing = new QueueRing();

	bool isRun = true;

	while (isRun)
	{
		std::cout << std::endl;
		std::cout << "=== Queue (Circular Buffer) Menu ===" << std::endl
			<< "1. Enqueue" << std::endl
			<< "2. Dequeue" << std::endl
			<< "3. Back to Main Menu" << std::endl;

		std::cout << "Choice: ";

		int choice;

		while (!(std::cin >> choice) || !isValidChoice(choice, 1, 3))
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

				queueRing->Enqueue(value);
				break;
			}

			case 2:
			{
				try
				{
					int poppedValue = queueRing->Dequeue();

					std::cout << "From queue (circular buffer) popped a value " << poppedValue << std::endl;
				}
				catch (std::out_of_range)
				{
					std::cout << "Queue is empty" << std::endl;
				}

				break;
			}

			case 3:
			{
				delete queueRing;

				isRun = false;

				break;
			}
		}
	}
}