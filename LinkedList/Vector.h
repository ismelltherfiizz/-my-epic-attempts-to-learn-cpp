#pragma once
#include <iostream>

template <class T>
class Vector
{
public:
	typedef T* Iterator;

	Vector();
	~Vector();
	Vector(int size);

	int  getCapacity() const;
	int getSize() const;
	bool isEmpty() const;

	T& front();
	T& back();

	void pushBack(const T& value); //
	void popBack();
	
	void reserve(int newCapacity);
	void resize(int newSize);

	
	void clear();
	T& operator[](int index);
	Vector<T>& operator*();
	Vector<T>& operator=(const Vector<T>& v);

	Iterator begin();
	Iterator end();

private:
	T* buffer;
	int capacity;
	int size;


};

template <class T>
Vector<T>& Vector<T>::operator*()
{
	return this;
}


template <class T>
Vector<T>::Vector()
{
	capacity = 0;
	size = 0;
	buffer = 0;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] buffer;
}

template<class T>
Vector<T>::Vector(int newSize)
{
	size = newSize;
	capacity = newSize;
	buffer = new T[newSize];
}



template<class T>
T& Vector<T>::operator[](int index)
{
	return buffer[index];
}


template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	delete[] buffer;
	size = v.size;
	capacity = v.capacity;
	buffer = new T[size];

}

template<class T>
typename Vector<T>::Iterator Vector<T>::begin()
{
	return buffer;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::end()
{
	return buffer+getSize();
}


template <class T>
void Vector<T>::clear()
{
	capacity = 0;
	size = 0;
	buffer = nullptr;
}



template<class T>
void Vector<T>::popBack()
{
	size--;
}

template<class T>
void Vector<T>::reserve(int newCapacity)
{
	T* newBuffer = new T[newCapacity];
	for (int i = 0; i < size; i++)
	{
		newBuffer[i] = buffer[i];
	}
	capacity = newCapacity;
	delete[] buffer;
	buffer = newBuffer;
}

template <class T>
void Vector<T>::resize(int newSize)
{
	reserve(newSize);
	size = newSize;
}


template <class T>
void Vector<T>::pushBack(const T& value)
{
	if (size >= capacity)
	{
		reserve(capacity + 1);
	}
	buffer[size++] = value;
}


template <class T>
bool Vector<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
T& Vector<T>::front()
{
	return buffer[0];
}

template<class T>
T& Vector<T>::back()
{
	return buffer[size - 1];
}

template<class T>
int Vector<T>::getCapacity() const
{
	return capacity;
}

template <class T>
int Vector<T>::getSize() const
{
	return size;
}