#pragma once

//! \brief Структура узла для двусвязного списка.
class Node
{
private:
	//! \brief Данные.
	int _data;

	//! \brief Указатель на следующий узел.
	Node* _nextNode = nullptr;

	//! \brief Указатель на предыдущий узел.
	Node* _previousNode = nullptr;
public:
	Node(int value)
	{
		SetData(value);
	}

	//! \brief Возвращает данные.
	//! \return Данные.
	int GetData();

	//! \brief Устанавливает данные.
	//! \param data Данные.
	void SetData(int data);

	//! \brief Возвращает указатель следующего узла.
	//! \return Указатель на следующий узел.
	Node* GetNextNode();

	//! \brief Устанавливает указатель на следующий узел.
	//! \param node Указатель на следующий узел.
	void SetNextNode(Node* node);

	//! \brief Возвращает указатель на предыдущий узел.
	//! \return Указатель на предыдущий узел.
	Node* GetPreviousNode();

	//! \brief Устанавливает указатель на предыдущий узел.
	//! \return node Указатель на предыдущий узел.
	void SetPreviousNode(Node* node);
};