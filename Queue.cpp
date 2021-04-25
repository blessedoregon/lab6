#include <stdio.h>
#include "Queue.h"
#include <iostream>

using namespace std;

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	count = other.count;

	try {
		// попытка выделить пам€ть дл€ p
		p = new T[count];
		// заполнить значени€ми
		for (int i = 0; i < count; i++)
			p[i] = other.p[i];
	}
	catch (bad_alloc e)
	{
		// если пам€ть не выделена, то вывести текст ошибки
		cout << e.what() << endl;
		count = 0; // создать пустую очередь
	}
}

template <typename T>
Queue<T>::~Queue()
{
	if (count > 0)
		delete[] p;
}

template <typename T>
void Queue<T>::Push(T item)
{
	T* p2;
	p2 = p;
	try {
		p = new T[count + 1];
		for (int i = 0; i < count; i++)
			p[i] = p2[i];
		p[count] = item;
		count++;
		if (count > 1)
			delete[] p2;
	}
	catch (bad_alloc e)
	{
		// если пам€ть не выделена
		cout << e.what() << endl; // вывести сообщение об ошибке
		p = p2;
	}
}

template <typename T>
T Queue<T>::Pop()
{
	if (count == 0)
		return 0;
	// заполнить элемент, который выт€гиваетс€ из очереди
	T item;
	item = p[0];
	// сформировать новый участок пам€ти, который на 1 меньше
	try {
		T* p2;
		// попытка выделить пам'€ть
		p2 = new T[count - 1];
		count--; // уменьшить количество элементов в очереди
		// p=>p2
		for (int i = 0; i < count; i++)
			p2[i] = p[i + 1]; // копируютс€ все кроме первого элемента
		  // освободить участок, на который указывает p
		if (count > 0)
			delete[] p;
		// перенаправить p на p2
		p = p2;
		// вернуть item
		return item;
	}
	catch (bad_alloc e)
	{
		// если пам€ть не выделилась, то вернуть 0
		cout << e.what() << endl;
		return 0;
	}
}

template <typename T>
void Queue<T>::clear()
{
	if (count > 0)
	{
		delete[] p;
		count = 0;
	}
}

// проверка существовани€ элементов в очереди
template <typename T>
bool Queue<T>::IsEmpty()
{
	return count == 0;
}

// количество элементов в очереди
template <typename T>
int Queue<T>::GetN()
{
	return count;
}

template <typename T>
int Queue<T>::GetItem()
{
	if (count > 0)
		return p[0];
	else
		return 0;
}

template <typename T>
 T Queue<T>::Get()
{
	if (count > 0)
		return p[0];
	else
		return 0;
}

template <typename T>
int Queue<T>::getSize() { return count; }

template <typename T>
void Queue<T>::printQueue(const char* objName)
{
	cout << "ќчередь: " << objName << endl;
	for (int i = 0; i < count; i++)
		cout << p[i] << "\t";
	cout << endl;

}