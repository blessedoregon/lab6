#pragma once
#include "AbstractQueue.h"

template <typename T>
class Queue : AbstractQueue<T>
{
private:
	int count, pos;
	T* p; // ������������ ������
public:
	Queue(){  count = 0; } //������� ������
	Queue(const Queue& other);
	~Queue();

	void Push(T item) override;
	T Pop() override;
	T Get() override;
	void clear();
	int GetItem() override;
	int GetN() override;
	bool IsEmpty();
	int getSize() override;
	void printQueue(const char* objName);

    // ����������� ������� operator=(),
    // ��������� ������������ �������� ���� Queue
    Queue& operator=(const Queue& obj)
    {
        T* p2; // ��������� �� �������������� ������

           // ������� �������� ����� ������� ������ ��� p2
            p2 = new T[obj.count];

            // ���� ������ �������� �������,
            // ����� ����������� �������������� ���������� ������ ��� p
            if (count > 0)
                delete[] p;

            // ����������� obj � ������� ������
            p = p2; // ������������� p �� p2
            count = obj.count;

            // ��������� ����������
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        return *this; // ������� ������� ������
    }
};
