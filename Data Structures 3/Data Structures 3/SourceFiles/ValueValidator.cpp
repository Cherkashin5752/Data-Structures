#include "ValueValidator.h"

bool isValidChoice(int choice, int min, int max)
{
	return choice >= min && choice <= max;
}