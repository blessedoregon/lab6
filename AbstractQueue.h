#pragma once

template <typename T>
class AbstractQueue
{
public:
	virtual void Push(T item) = 0;
	virtual T Pop() = 0;
	virtual T Get() = 0;
	virtual int getSize() = 0;
	virtual int GetItem() = 0;
	virtual int GetN() = 0;
};