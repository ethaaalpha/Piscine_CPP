#pragma once
#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	unsigned int 	_size;
	T* 				_items;
public:
	Array (void) {
		_items = new T[0];
		_size = 0;
	}

	Array (unsigned int n) {
		_items = new T[n];
		_size = n;
	}
	
	Array (const Array& parent) {
		_items = new T[parent._size];
		_size = parent._size;
		for (unsigned int i = 0; i < parent._size; i++)
			_items[i] = parent._items[i];
	}

	Array& operator=(const Array& parent){
		delete [] _items;
		_items = new T[parent._size];
		_size = parent._size;
		for (unsigned int i = 0; i < parent._size; i++)
			_items[i] = parent._items[i];
		return (*this);
	}

	T& operator[](unsigned int n){
		if (n >= _size)
			throw (Array::OutOfArrayException());
		else
			return (_items[n]);
	}

	const T operator[](unsigned int n) const{
		if (n >= _size)
			throw (Array::OutOfArrayException());
		else
			return (_items[n]);
	}

	unsigned int size(void) const {
		return (_size);
	}

	~Array() {
		delete [] _items;
	}

	class OutOfArrayException : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Index out of array size !");
		}
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		os << array[i];
	return (os);
} 