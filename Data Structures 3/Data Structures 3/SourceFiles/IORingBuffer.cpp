#include <iostream>

#include "RingBuffer.h"
#include "IORingBuffer.h"
#include "ValueValidator.h"

void RingBufferInterface()
{
	RingBuffer* ringBuffer = new RingBuffer(32);

	bool isRun = true;
	int choice = -1;

	while (isRun)
	{
		std::cout << std::endl;
		std::cout << "=== Circular Buffer Menu ===" << std::endl
			<< "1. Push" << std::endl
			<< "2. Pop" << std::endl
			<< "3. Free Space" << std::endl
			<< "4. Occupied Space" << std::endl
			<< "5. Resize" << std::endl
			<< "6. Back to Main Menu" << std::endl;

		std::cout << "Choice: ";
		
		int choice;

		while (!(std::cin >> choice) || !isValidChoice(choice, 1, 6))
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
			
				ringBuffer->AddElement(value);

				break;
			}

			case 2:
			{
				try
				{
					int poppedValue = ringBuffer->GetElement();

					std::cout << "From Circular Buffer popped a value: " << poppedValue << std::endl;
				}
				catch (std::out_of_range)
				{
					std::cout << "Circular Buffer in Empty" << std::endl;
				}

				break;
			}

			case 3:
			{
				std::cout << "Free Space in Circular Buffer: " << ringBuffer->GetFreeSpace() << std::endl;
				
				break;
			}

			case 4:
			{
				std::cout << "Occupied Space in Circular Buffer: " << ringBuffer->GetSize() << std::endl;
			
				break;
			}

			case 5:
			{
				ringBuffer->Resize();

				std::cout << "Circular Buffer capacity increased" << std::endl;
			
				break;
			}

			case 6:
			{
				delete ringBuffer;

				isRun = false;

				break;
			}
		}
	}
}