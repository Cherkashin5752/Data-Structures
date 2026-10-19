#pragma once

#include "Node.h"

//! \brief Класс двухсвязного списка.
class List
{
private:
	//! \brief Поле указанного начального узла.
	Node* _head = nullptr;

	//! \brief Поле указанного конечного узла.
	Node* _tail = nullptr;

	//! \brief Поле количества элементов в списке.
	int _size = 0;

	//! \breaif Удаляет узел по указателю.
	//! \param указатель на узел.
	bool RemoveNode(Node* node);
public:
	//! \brief Дестректар класса
	~List();

	//! \brief Возвращает указатель на начальный узел.
	//! \return Указатель на начальный узел.
	Node* GetHead();

	//! \brief Возвращает указатель на конечный узел.
	//! \return Указатель на конечный узел.
	Node* GetTail();

	//! \brief Возвращает еоличество элементов в списке.
	int GetSize();

	//! \brief Возвращает узел по указанному индексу.
	//! \param index Индекс, по которому нужно получить узел.
	//! \return Узел.
	Node* GetNodeByIndex(int index);

	//! \brief Добавляет новый узел в список.
	//! \param index Индекс узла.
	//! \return Возвращает true, если удалось добавить элемент, или возвращает false, если индекс выходит за диапазоны списка.
	bool AddNode(Node* node, int index);

	//! \brief Удаляет узел по индексу.
	//! \param index Индекс узла.
	//! \return Возвращает true, если удалось удалить элемент, или возвращает false, если индекс выходит за диапазоны списка.
	bool RemoveNodeByIndex(int index);

	//! \brief Удаляет узел по значению.
	//! \param index Значение узла.
	//! \return Возвращает true, если удалось удалить элемент, или возвращает false, если индекс выходит за диапазоны списка.
	bool RemoveNodeByValue(int value);

	//! \brief Сортирует двусвязный список.
	void Sort();

	//! \brief находит узел по указанному значению.
	//! \param value Значение, по которому ищется узел.
	//! \return Найденный узел или nullptr.
	Node* FindNodeByValue(int value);

	//! \brief Очищает список от всех элементов.
	void Clear();
};