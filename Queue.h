#pragma once
#include "AbstractQueue.h"

template <typename T>
class Queue : AbstractQueue<T>
{
private:
	int count, pos;
	T* p; // динамический массив
public:
	Queue(){  count = 0; } //очередь пустая
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

    // операторная функция operator=(),
    // реализует присваивание объектов типа Queue
    Queue& operator=(const Queue& obj)
    {
        T* p2; // указатель на дополнительную память

           // попытка выделить новый участок памяти для p2
            p2 = new T[obj.count];

            // если память выделена успешно,
            // можно освобождать предварительно выделенную память для p
            if (count > 0)
                delete[] p;

            // скопировать obj в текущий объект
            p = p2; // перенаправить p на p2
            count = obj.count;

            // заполнить значениями
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        return *this; // вернуть текущий объект
    }
};
