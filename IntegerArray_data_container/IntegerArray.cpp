#include"IntegerArray.h"
#include <iostream>
#include<exception>

using namespace std;

class bad_length : public exception // Исключение наследник exception — для предоставления неправильной длины массиву
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Указана неправильная длина массива!";
	}
};

class bad_range : public exception // Исключение наследник exception — для выхода за пределы массива
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Выход за пределы массива!";
	}
};

IntegerArray::IntegerArray(int length) : m_length{ length } // Конструктор
{
	if (length <= 0)
	{
		throw bad_length(); // При попытке создать массив нулевой или отрицательной длинны выбрасывается исключение
	}

	if (length > 0)
	{
		m_data = new int[length] {};
	}
}

IntegerArray::~IntegerArray()  // Деструктор
{
	delete[] m_data;
}

int& IntegerArray::operator[](int index) // Перегрузка оператора, для доступа к элементам массива
{
	{
		if (index <= 0 && index > m_length)
		{
			throw exception("Доступ к элементу массива невозможен");
		}

		return m_data[index];
	}
}

int IntegerArray::getLength() const // Узнать длину массива
{
	return m_length;
}

void IntegerArray::erase() // Функция удаяет массив
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::reallocate(int newLength) // Создание нового массива 
{
	erase();
	if (newLength <= 0)
		return;
	m_data = new int[newLength];
	m_length = newLength;
}

IntegerArray::IntegerArray(const IntegerArray& a) // Конструктор копирования
{
	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a) // Оператор присваивания
{
	if (&a == this)
		return *this;

	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];

	return *this;
}

void IntegerArray::get_value_by_index(IntegerArray array, int size) // получить значение элемента массива по индексу
{
	setlocale(LC_ALL, "");
	int num;
	for (int i{ 0 }; i < size; ++i)
		array[i] = i + 1;

	cout << "\nВведите индекс элемента  ";
	cin >> num;
	if (!(num >= 0 && num < m_length))// ошибка 
	{
		throw exception("Массив не содержит этот индекс"); // Исключение выбрасывается при попытке доступа к несуществующему индексу массива
	}
	cout << "Значение элемента по данному индексу: " << array[num] << endl;

}

void IntegerArray::get_index_by_value(IntegerArray array, int size) // получить индекс элемента массива по значению
{

	int ans[10]; // Массив для записи всех индексов
	int h = 0;
	int key;

	cout << "Введите значение элемента массива: "; cin >> key;

	if (!(key > 0 && key <= m_length))
	{
		throw exception("Массив не содержит этот элемент");
	}
	for (int i = 0; i <= m_length; i++) {
		if (array[i] == key) {
			ans[h++] = i;
		}
	}
	if (h != 0) { // проверяем были ли совпадения
		for (int i = 0; i < h; i++) {
			cout << "Элемент " << key << " находится в ячейке с индексом " << ans[i] << endl; //выводим все индексы
		}
	}
}

void IntegerArray::resize(int newLength) // Изменить размер массива
{
	if (newLength == m_length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data{ new int[newLength] };

	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}

	delete[] m_data;
	m_data = data;
	m_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)  // Вставка элемента в массив
{
	if (!(index >= 0 && index <= m_length))
	{
		throw bad_range(); // Исключение выбрасывается при указании несуществующего индекса массива
	}
	int* data{ new int[m_length + 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	data[index] = value;

	for (int after{ index }; after < m_length; ++after)
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntegerArray::remove(int index) // Удаление элемента из массива
{
	if (!(index >= 0 && index < m_length))
	{
		throw bad_range(); // Исключение выбрасывается при указании несуществующего индекса массива 
	}
	if (m_length == 1)
	{
		erase();
		return;
	}

	int* data{ new int[m_length - 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	for (int after{ index + 1 }; after < m_length; ++after)
		data[after - 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntegerArray::insertAtBeginning(int value) { insertBefore(value, 0); } // Вставка в начало массива
void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_length); } // Вставка в конец массива