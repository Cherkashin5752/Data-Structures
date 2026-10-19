#pragma once

//! \brief Класс динамического массива 
class DynamicArray
{
private:
	//! \brief Размер массива.
	int _size = 0;

	//! \brief Вместимость массива.
	int _capacity = 1;

	//! \brief Массив.
	int* _array = new int[_capacity];

	//! \brief Показатель роста.
	int _growthFactor = 2;

	//! \brief Сравнивает текущую вместимость и размер массива и увеличивает или уменьшает его при необходимости.
	void CheckCapacity();

	//! \brief увеличивает вместимость массива.
	void ExpendCapacity();

	//! \brief уменьшает вместимость массива.
	void ShrinkCapasity();
public:
	//! \brief Oчищает память, занятую массивом, при уничтожении объекта.
	~DynamicArray();

	//! \brief Возвращает размер массива.
	//! \return Размер массива.
	int GetSize();

	//! \brief Возвращает вместительность массива.
	//! \return Вместимость массива.
	int GetCapacity();

	//! \brief Возвращает массив.
	//! \return Массив.
	int* GetArray();

	void MakeNewArray(int Capacity);

	//! \brief Добавляет новый элемент в конец массива.
	//! \param value Значение эелемента.
	void AppendElement(int value);

	//! \brief Добавляет новый элемент в начало массива.
	//! \param value Значение эелемента.
	void PrependElement(int value);

	//! \brief Добавляет новый элемент по указанному индексу.
	//! \param index Индекс элемента, куда нужно добавить элемент.
	//! \param value Значение элемента. 
	//! \return -1, если index введён не верно. 0, если index введён верно.
	int AddElementAt(int index, int value);

	//! \brief Удаляет элемент массива по передаваемому индексу.
	//! \param index Индекс элемента, который нужно удалить.
	//! \return -1, если index введён не верно. 0, если index введён верно.
	int RemoveByIndex(int index);

	//! \brief Удаляет первое вхождение значение элемента по его передаваемому значению.
	//! \param value Значение элемента.
	void RemoveByValue(int value);

	//! \brief Возвращает значение элемента в массива по передаваемому индексу.
	//! \param index Индекс элемента, который нужно получить.
	//! \return -1, если index введён не верно. 0, если index введён верно.
	int GetElement(int index);

	//! \brief Сортирует массив.
	void SortArray();

	//! \brief Линейный поиск индекса элемента по передаваемому значению.
	//! \param value Значение, индекс которого нужно найти.
	int LinearSearch(int value);

	//! \brief Бинарный поиск индекса элемента по передаваемому значению.
	//! \param value Значение, индекс которого нужно найти.
	int BinarySearch(int value);
};