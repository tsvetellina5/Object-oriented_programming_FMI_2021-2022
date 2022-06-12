#pragma once

template <typename T>
class VectorC
{
	T* arr;
	size_t size;
	size_t capacity;

	void copy(const VectorC<T>& other)
	{
		arr = new T[other.capacity];
		for (int i = 0; i < other.capacity; i++) {
			arr[i] = other.arr[i];
		}
		size = other.size;
		capacity = other.capacity;
	}

	void free()
	{
		delete[] arr;
	}

public:
	VectorC()
	{
		arr = new T[1];
		capacity = 1;
		size = 0;
	}

	VectorC(const VectorC<T>& other)
	{
		copy(other);
	}

	VectorC(VectorC<T>&& other)
	{
		arr = other.arr;
		size = other.size;
		capacity = other.capacity;
		other.arr = nullptr;
	}

	VectorC<T>& operator=(const VectorC<T>& other)
	{
		if (this != &other)
		{
			free();
			copy(other);
		}
		return *this;
	}

	VectorC<T>& operator=(VectorC<T>&& other)
	{
		if (this != &other)
		{
			free();
			arr = other.arr;
			size = other.size;
			capacity = other.capacity;
			other.arr = nullptr;
		}
		return *this;
	}


	~VectorC()
	{
		free();
	}

	size_t getSize() const
	{
		return size;
	}

	void push(const T& el)
	{
		if (size == capacity) {
			T* temp = new T[2 * capacity];

			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}

			delete[] arr;
			capacity *= 2;
			arr = temp;
		}

		arr[size] = el;
		size++;
	}

	void push(const T& el, const size_t& position)
	{
		if (position == capacity)
			push(el);
		else
			arr[position] = el;
	}

	T getElement(size_t position) const
	{
		if (position < size)
			return arr[position];
		else
		{
			//exception
		}

		return arr[0];
	}

	void setElement(size_t position, const T& type)
	{
		if (position >= size)
		{
			return;
		}

		arr[position] = type;
	}

	void deleteLast()
	{
		size--;
	}

	void replace(size_t position, const T& el)
	{
		if (position >= size)
		{
			return;
		}

		arr[position] = el;
	}
};