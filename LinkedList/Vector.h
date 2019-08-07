#pragma once
#include <iostream>
const int defaultVectorSize = 4;

template <class T>
class Vector
{
public:
	typedef T* Iterator;

	Vector()
		: buffer(new T[defaultVectorSize]),
		capacity(defaultVectorSize),
		size(0)
	{ }

	Vector(int n) 
		: buffer(new T[n]),
		capacity(n),
		size(0)
	{ }

	Vector(const Vector& source);


	int  getCapacity() const;
	int getSize() const;
	bool isEmpty() const;

	T& front() const;
	T& back() const;

	void pushBack(const T& value); //
	void popBack();
	
	void reserve(int newCapacity);
	void resize(int newSize);

	
	void clear();
	T& operator[](int index);
	Vector<T>& operator*();
	Vector<T>& operator=(const Vector<T>& source);

	Iterator begin();
	Iterator end();

private:
	T* buffer;
	int capacity;
	int size;


};

template <class T>
Vector<T>::Vector(const Vector& source)
{
	*this = source;
}

template <class T>
Vector<T>& Vector<T>::operator*()
{
	return *this;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return buffer[index];
}


template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& source)
{
	if (this == &source)
	{
		return *this;
	}
	delete[] buffer;
	size = source.size;
	capacity = source.capacity;
	buffer = new T[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = source.buffer[i];
	}
	return *this;
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
	delete[] buffer;
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
	if (newCapacity>=capacity)
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
	if (size + 1 >= capacity)
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
T& Vector<T>::front() const
{
	return buffer[0];
}

template<class T>
T& Vector<T>::back() const
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