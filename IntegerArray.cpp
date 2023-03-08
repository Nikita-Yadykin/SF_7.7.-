#include"IntegerArray.h"
#include <iostream>
#include<exception>

using namespace std;

class bad_length : public exception // ���������� ��������� exception � ��� �������������� ������������ ����� �������
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: ������� ������������ ����� �������!";
	}
};

class bad_range : public exception // ���������� ��������� exception � ��� ������ �� ������� �������
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: ����� �� ������� �������!";
	}
};

IntegerArray::IntegerArray(int length) : m_length{ length } // �����������
{
	if (length <= 0)
	{
		throw bad_length(); // ��� ������� ������� ������ ������� ��� ������������� ������ ������������� ����������
	}

	if (length > 0)
	{
		m_data = new int[length] {};
	}
}

IntegerArray::~IntegerArray()  // ����������
{
	delete[] m_data;
}

int& IntegerArray::operator[](int index) // ���������� ���������, ��� ������� � ��������� �������
{
	{
		if (index <= 0 && index > m_length)
		{
			throw exception("������ � �������� ������� ����������");
		}

		return m_data[index];
	}
}

int IntegerArray::getLength() const // ������ ����� �������
{
	return m_length;
}

void IntegerArray::erase() // ������� ������ ������
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::reallocate(int newLength) // �������� ������ ������� 
{
	erase();
	if (newLength <= 0)
		return;
	m_data = new int[newLength];
	m_length = newLength;
}

IntegerArray::IntegerArray(const IntegerArray& a) // ����������� �����������
{
	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a) // �������� ������������
{
	if (&a == this)
		return *this;

	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];

	return *this;
}

void IntegerArray::get_value_by_index(IntegerArray array, int size) // �������� �������� �������� ������� �� �������
{
	setlocale(LC_ALL, "");
	int num;
	for (int i{ 0 }; i < size; ++i)
		array[i] = i + 1;

	cout << "\n������� ������ ��������  ";
	cin >> num;
	if (!(num >= 0 && num < m_length))// ������ 
	{
		throw exception("������ �� �������� ���� ������"); // ���������� ������������� ��� ������� ������� � ��������������� ������� �������
	}
	cout << "�������� �������� �� ������� �������: " << array[num] << endl;

}

void IntegerArray::get_index_by_value(IntegerArray array, int size) // �������� ������ �������� ������� �� ��������
{

	int ans[10]; // ������ ��� ������ ���� ��������
	int h = 0;
	int key;

	cout << "������� �������� �������� �������: "; cin >> key;

	if (!(key > 0 && key <= m_length))
	{
		throw exception("������ �� �������� ���� �������");
	}
	for (int i = 0; i <= m_length; i++) {
		if (array[i] == key) {
			ans[h++] = i;
		}
	}
	if (h != 0) { // ��������� ���� �� ����������
		for (int i = 0; i < h; i++) {
			cout << "������� " << key << " ��������� � ������ � �������� " << ans[i] << endl; //������� ��� �������
		}
	}
}

void IntegerArray::resize(int newLength) // �������� ������ �������
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

void IntegerArray::insertBefore(int value, int index)  // ������� �������� � ������
{
	if (!(index >= 0 && index <= m_length))
	{
		throw bad_range(); // ���������� ������������� ��� �������� ��������������� ������� �������
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

void IntegerArray::remove(int index) // �������� �������� �� �������
{
	if (!(index >= 0 && index < m_length))
	{
		throw bad_range(); // ���������� ������������� ��� �������� ��������������� ������� ������� 
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

void IntegerArray::insertAtBeginning(int value) { insertBefore(value, 0); } // ������� � ������ �������
void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_length); } // ������� � ����� �������