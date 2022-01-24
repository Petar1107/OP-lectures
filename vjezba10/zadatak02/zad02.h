#ifndef ZADATAK02_H
#define ZADATAK02_H
#include <iostream>

template<class T>
class Stack {
	T* arr;
	size_t capacity;
	size_t size;
public:
	Stack(size_t size);
	~Stack() { delete[] arr; }
	void push(const T& num);
	void pop();
	bool CheckEmpty();
	void print();
};
template <class T>
Stack<T>::Stack(size_t newSize)
{
	arr = new T[newSize];
	size = 0;
	capacity = newSize;
}

template <class T>
void Stack<T>::push(const T& num) 
{
	if (size == capacity)
	{
		capacity *= 2;
		T* newArr = new T[capacity];
		for (int i = 0; i < capacity - 1; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
	}
	arr[size] = num;
	size++;
}

template <class T>
void Stack<T>::pop() 
{
	size--;
}

template <class T>
bool Stack<T>::CheckEmpty() 
{
	return size;
}

template <class T>
void Stack<T>::print() 
{
	for (int i = 0; i < size; i++)
		(i == size - 1) ? std::cout << arr[i] : std::cout << arr[i] << ", ";
}
#endif // !ZADATAK02_H

