#pragma once

template <class T>
class Vector
{
public:
	typedef T* Iterator;


	Vector()
		: buffer(new T[defaultVectorCapacity]),
		capacity(defaultVectorCapacity),
		size(0), 
		defaultInsertable(0)
	{ }

	Vector(int n) 
		: buffer(new T[n]),
		capacity(n),
		size(0),
		defaultInsertable(0)
	{ }
	Vector(int n, T defaultInsertable)
		: buffer(new T[n]),
		capacity(n),
		size(0),
		defaultInsertable(defaultInsertable)
	{ }
	
	~Vector()
	{
		clear();
	}

	Vector(const Vector& source);

	Vector<T>& operator=(const Vector<T>& source);

	void assign(int newSize, const T& value);
	void assign(Iterator first, Iterator last);

	//Element access
	T& front() const;
	T& back() const;
	T& operator[](int index);
	const T& operator[](int index) const;
	T& at(int index);
	T* data() noexcept;

	//Capacity
	void reserve(int newCapacity);
	void shrinkToFit();
	int  getCapacity() const;
	int getSize() const;
	bool isEmpty() const;
	int maxSize();

	//Modifiers
	void clear();
	void pushBack(const T& value);
	void popBack();
	Iterator insert(Iterator pos, const T& value);
	Iterator erase(Iterator pos);
	void resize(int newSize);
	void swap(Vector& other);


	//Iterators
	Iterator begin();
	Iterator end();
	const Iterator begin() const;
	const Iterator end() const;
	Iterator rBegin();
	Iterator rEnd();
	const Iterator rBegin() const;
	const Iterator rEnd() const;

private:
	T* buffer = nullptr;
	int capacity;
	int size;
	T defaultInsertable;
	static int defaultVectorCapacity;
};

template <class T>
int Vector<T>::maxSize()
{
	return std::numeric_limits<int>::max();
}

template <class T>
int Vector<T>::defaultVectorCapacity = 0;

template <class T>
T* Vector<T>::data() noexcept
{
	return buffer;
}

template <class T>
T& Vector<T>::at(int index)
{
	if (index < size)
	{
		return buffer[index];
	}
	else
	{
		throw "index is out of range!";
	}
}

template <class T>
typename Vector<T>::Iterator Vector<T>::insert(Iterator pos, const T& value)
{
	if (pos >= end())
	{
		return end();
	}
	if (pos < begin())
	{
		return begin();
	}
	T* newBuffer = new T[size + 1];
	int i = 0;
	for (i; buffer + i != pos; i++)
	{
		*(newBuffer + i) = *(buffer + i);
	}
	*(newBuffer + i) = value;
	size++;
 	for (i; i <= size; i++) 
	{
		*(newBuffer + (i+1)) = *(buffer+i);
	}
	delete[] buffer;
	buffer = newBuffer;
	return pos;
}

template <class T>
void Vector<T>::shrinkToFit()
{
	if (capacity > size)
	{
		T* newBuffer = new T[size];
		for (int i = 0; i < size; i++)
		{
			newBuffer[i] = buffer[i];
		}
		capacity = size;
		delete[] buffer;
		buffer = newBuffer;
	}
}

template <class T>
void Vector<T>::assign(Iterator first, Iterator last)
{
	T* newBuffer = new T[last - first + 1];
	resize(last - first + 1);
	for (int i = 0; i <= last - first; i++)
	{
		*(newBuffer + i) = *(first + i);
	}
	delete[] buffer;
	buffer = newBuffer;
}

template <class T>
void Vector<T>::assign(int newSize, const T& value)
{
	resize(newSize);
	for (int i = 0; i < size; i++)
	{
		buffer[i] = value;
	}
}

template <class T>
typename Vector<T>::Iterator Vector<T>::erase(Iterator pos)
{
	if (pos >= end())
	{
		return end();
	}
	if (pos < begin())
	{
		return begin();
	}
	T* newBuffer = new T[size-1];
	int i = 0;
	for (i; buffer+i != pos; i++)
	{
		*(newBuffer + i) = *(buffer + i);
	}
	for (i; i < size; i++)
	{
		*(newBuffer+i) = *(buffer + (i+1));
	}
	delete[] buffer;
	buffer = newBuffer;
	size--;
	return pos;
}


template <class T>
const T& Vector<T>::operator[](int index) const
{
	return buffer[index];
}

template <class T>
void Vector<T>::swap(Vector& other)
{
	std::swap(*this, other);
}

template <class T>
Vector<T>::Vector(const Vector& source)
{
	*this = source;
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

template<class T>
typename const Vector<T>::Iterator Vector<T>::begin() const
{
	return buffer;
}

template<class T>
typename const Vector<T>::Iterator Vector<T>::end() const
{
	return buffer + getSize();
}

template<class T>
typename Vector<T>::Iterator Vector<T>::rBegin()
{
	return Iterator(end());
}

template<class T>
typename const Vector<T>::Iterator Vector<T>::rBegin() const
{
	return Iterator(end());
}

template<class T>
typename Vector<T>::Iterator Vector<T>::rEnd()
{
	return Iterator(begin());
}

template<class T>
typename const Vector<T>::Iterator Vector<T>::rEnd() const
{
	return Iterator(begin());
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
	T* newBuffer = new T[--size];

	for (int i = 0; i < size; i++)
	{
		newBuffer[i] = buffer[i];
	}

	delete[] buffer;
	buffer = newBuffer;
}

template<class T>
void Vector<T>::reserve(int newCapacity)
{
	if (newCapacity>capacity)
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
	if(size>newSize)
	{
		size = newSize;
	}
	else
	{
		for (size; size < newSize; size++)
		{
			buffer[size] = defaultInsertable;
		}
	}
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