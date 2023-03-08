#include <iostream>
#include "IntegerArray.h"
#include<exception>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	try
	{

		IntegerArray array(10); // ��������� ������ �� 10 ���������


		for (int i{ 0 }; i < 10; ++i) // ��������� ������ ������� �� 1 �� 10
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
			cout << "�������� ������: ";
			for (int i{ 0 }; i < array.getLength(); ++i) // ������� ��� ����� �������
				cout << array[i] << ' ';
			cout << endl;
		}
		catch (const std::exception& exep)
		{
			cout << exep.what() << endl;
		}
		IntegerArray array_copy{ array }; // �������� �������� ������ � ������ "array_copy"
		array_copy = array;
		array_copy = array_copy;
		array = array;
		try
		{
			array.get_value_by_index(array, sizeof(array) / sizeof(array[0])); // �������� �������� �������� ������� �� �������

			array.get_index_by_value(array, sizeof(array) / sizeof(array[0])); // �������� ������ �������� ������� �� ��������
		}
		catch (const std::exception& exep)
		{
			cout << exep.what() << endl;
		}
		array.resize(5); // �������� ������ �������
		try
		{
			array.insertBefore(3, 4); // ������� �������� � ������
		}
		catch (const std::exception& er)
		{
			cout << er.what() << endl;
		}
		try
		{
			array.remove(3); // �������� �������� �� �������
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << " (���������� ������� ��������� �������)" << endl;
		}
		array.insertAtBeginning(333); // ������� � ������ �������

		array.insertAtEnd(999); // ������� � ����� �������


		cout << "����� ��������� �������: ";
		for (int i{ 0 }; i < array_copy.getLength(); ++i) // ������� ��� ����� �������
			cout << array_copy[i] << ' ';
		cout << endl;

		cout << "������ ����� ��������������: ";
		for (int i{ 0 }; i < array.getLength(); ++i) // ������� ��� ����� �������
			cout << array[i] << ' ';
		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...) // ����� ��� �������������� ����������
	{
		cout << "��������� ������������ ��������� ������" << endl;
	}
	return 0;

}
