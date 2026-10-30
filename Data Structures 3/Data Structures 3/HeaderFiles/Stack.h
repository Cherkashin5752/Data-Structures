#pragma once

#include "Node.h"

//! \brief Класс стек
class Stack
{
private:
	//! \brief Верхний элемент стека.
	Node* _top;

public:
	//! \brief Создаёт класс стек.
	Stack();

	//! \brief Освобождает память.
	~Stack();

	//! \brief Возвращаеи верхний элемент стека.
	//! \return Верхний элемент стека.
	Node* Peek();

	//! \brief Добавляет данные в стек.
	//! \param data Данные.
	void Push(int data);

	//! \brief Достаёт данные из стека.
	//! \return Последние добавленные данные в стеке.
	int Pop();

	//! \brief Очищает стек.
	void ClearStack();
};