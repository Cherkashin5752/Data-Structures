#pragma once

#include "Stack.h"

//! \brief Класс очереди на двух стеках
class QueueTwoStack
{
private:
	//! \brief Основной стек, в который будут добавляться элементы.
	Stack* _inStack;
	
	//! \brief Второстепенный стек, из которого будут возвращаться элементы.
	Stack* _outStack;
public:
	//! \brief Создаёт класс очереди на двух стеках.
	QueueTwoStack();

	//! \brief Освобождает пямять.
	~QueueTwoStack();

	//! \brief Очищает очередь.
	void ClearQueue();

	//! \brief Дабавляет элемент в очередь.
	//! \param data Вносимые данные.
	void Enqueue(int data);

	//! \brief Достаёт элемент из очереди.
	//! \param Элемент из очереди.
	int Dequeue();
};