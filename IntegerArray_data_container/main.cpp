#include <iostream>
#include "IntegerArray.h"
#include<exception>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	try
	{

		IntegerArray array(10); // Объявляем массив из 10 элементов


		for (int i{ 0 }; i < 10; ++i) // Заполнить массив числами от 1 до 10
			try
		{
			array[i] = i + 1;
		}
		catch (const std::exception& exep)
		{
			cout << exep.what() << endl;
		}
		try
		{
			cout << "Исходный массив: ";
			for (int i{ 0 }; i < array.getLength(); ++i) // Вывести все числа массива
				cout << array[i] << ' ';
			cout << endl;
		}
		catch (const std::exception& exep)
		{
			cout << exep.what() << endl;
		}
		IntegerArray array_copy{ array }; // Копируем исходный массив в массив "array_copy"
		array_copy = array;
		array_copy = array_copy;
		array = array;
		try
		{
			array.get_value_by_index(array, sizeof(array) / sizeof(array[0])); // Получить значение элемента массива по индексу

			array.get_index_by_value(array, sizeof(array) / sizeof(array[0])); // Получить индекс элемента массива по значению
		}
		catch (const std::exception& exep)
		{
			cout << exep.what() << endl;
		}
		array.resize(5); // Изменить размер массива
		try
		{
			array.insertBefore(3, 4); // Вставка элемента в массив
		}
		catch (const std::exception& er)
		{
			cout << er.what() << endl;
		}
		try
		{
			array.remove(3); // Удаление элемента из массива
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << " (Невозможно удалить указанный элемент)" << endl;
		}
		array.insertAtBeginning(333); // Вставка в начало массива

		array.insertAtEnd(999); // Вставка в конец массива


		cout << "Копия исходного массива: ";
		for (int i{ 0 }; i < array_copy.getLength(); ++i) // Вывести все числа массива
			cout << array_copy[i] << ' ';
		cout << endl;

		cout << "Массив после преобразований: ";
		for (int i{ 0 }; i < array.getLength(); ++i) // Вывести все числа массива
			cout << array[i] << ' ';
		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...) // Ловим все необработанные исключения
	{
		cout << "Проверьте правильность введенных данных" << endl;
	}
	return 0;

}
