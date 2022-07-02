#pragma once

#include "Vehicle.h"
const size_t DEFAULT_CAPACITY_CONTAINER = 4;

class Container{

	public:
		Container();
		Container(const Container &);
		Container(Container &&);
		Container &operator=(const Container&);
		Container &operator=(Container &&);
		~Container();

		size_t getSize() const;
		size_t getCapacity() const;

		void pushBack(const Vehicle *);
		void pushAt(const Vehicle *, const size_t);
		Vehicle *popBack();
		Vehicle *popAt(const size_t);
		Vehicle *operator[](const size_t);
		const Vehicle *operator[](const size_t) const;
		bool empty() const;
		void clear();

	private:
		Vehicle** data;
		size_t size;
		size_t capacity;

		void copy(const Container &);
		void free();
		void move(Container &&);

		size_t calculateCapacity(const size_t) const;
		void resize(const size_t);

};