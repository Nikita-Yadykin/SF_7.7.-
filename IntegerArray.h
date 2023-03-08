#pragma once
class IntegerArray
{
private:

	int m_length{};
	int* m_data{};

public:
	
	IntegerArray() = default; // Конструктор, создает пустой массив
	IntegerArray(int length);  // Конструктор, создает массив заданного размера       
	~IntegerArray(); // Деструктор
	int& operator[](int index); // перегрузка оператора, для доступа к элементам массива
	int getLength() const; // Узнать длину массива
	void erase(); // Функция удаяет массив    
	void reallocate(int newLength); // Создание нового массива   
	IntegerArray(const IntegerArray& a); // Конструктор копирования    
	IntegerArray& operator=(const IntegerArray& a); // Оператор присваивания
	void get_value_by_index(IntegerArray array, int size); // получить значение элемента массива по индексу
	void get_index_by_value(IntegerArray array, int size); // получить индекс элемента массива по значению
	void resize(int newLength); // Изменить длину массива с сохранением уже существующих значений
	void insertBefore(int value, int index);  // Вставка элемента в массив   
	void remove(int index); // Удаление элемента из массива
	void insertAtBeginning(int value); // Вставка в начало массива
	void insertAtEnd(int value); // Вставка в конец массива
};