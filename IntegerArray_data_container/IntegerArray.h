#pragma once
class IntegerArray
{
private:

	int m_length{};
	int* m_data{};

public:
	
	IntegerArray() = default; // �����������, ������� ������ ������
	IntegerArray(int length);  // �����������, ������� ������ ��������� �������       
	~IntegerArray(); // ����������
	int& operator[](int index); // ���������� ���������, ��� ������� � ��������� �������
	int getLength() const; // ������ ����� �������
	void erase(); // ������� ������ ������    
	void reallocate(int newLength); // �������� ������ �������   
	IntegerArray(const IntegerArray& a); // ����������� �����������    
	IntegerArray& operator=(const IntegerArray& a); // �������� ������������
	void get_value_by_index(IntegerArray array, int size); // �������� �������� �������� ������� �� �������
	void get_index_by_value(IntegerArray array, int size); // �������� ������ �������� ������� �� ��������
	void resize(int newLength); // �������� ����� ������� � ����������� ��� ������������ ��������
	void insertBefore(int value, int index);  // ������� �������� � ������   
	void remove(int index); // �������� �������� �� �������
	void insertAtBeginning(int value); // ������� � ������ �������
	void insertAtEnd(int value); // ������� � ����� �������
};