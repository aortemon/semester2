#pragma once
#include <iostream>
using namespace std;

template<typename Type>
class TContainer {
private:
	Type* elements;
	int max_size;
	int size;
	int step;
	void realloc();

public:
	//TContainer();
	TContainer(int max_size=10, int step=5);
	~TContainer();
	int get_size() const;
	Type& operator[](int index);
	void push_back(Type& addition);
	void insert(int pos, Type& addition);
	void push_forward(Type& addition);
	Type& find(Type& elem);
	void remove(int i);
};


template<typename Type>
TContainer<Type>::TContainer(int max_size, int step) {
	this->max_size = max_size;
	this->size = 0;
	this->step = step;
	this->elements = new Type[max_size];
}


template<typename Type>
TContainer<Type>::~TContainer() {
	delete[] elements;
}


template <typename Type>
int TContainer<Type>::get_size() const {
	return this->size;
}


template<typename Type>
Type& TContainer<Type>::operator[](int index) {
	return elements[index];
}



template<typename Type>
void TContainer<Type>::realloc() {
	Type* new_elements = new Type[max_size + step];
	for (int i = 0; i < this->max_size; i++) {
		new_elements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = new_elements;
	this->max_size += this->step;
}

/*template <typename Type>
void TContainer<Type>::push_back(Type& addition) {
	if (this->size >= this->max_size) this->realloc();
	elements[this->size++] = addition;
}*/

template <typename Type>
void TContainer<Type>::push_back(Type& element)
{
	if (max_size == size)
	{
		max_size += step;
		Type* new_arr = new Type[max_size];
		std::copy(elements, &elements[size], new_arr);
		delete[] elements;
		elements = new_arr;
	}
	elements[size++] = element;
}

template <typename Type>
void TContainer<Type>::push_forward(Type& addition) {
	if (size >= max_size) this->realloc();
	size++;
	for (int i = size - 2; i >= 0; i--) {
		elements[i + 1] = elements[i];
	}
	elements[0] = addition;
}

template<typename Type>
void TContainer<Type>::insert(int pos, Type& addition) {
	if (size >= max_size) this->realloc();
	size++;
	for (int i = size - 2; i > pos; i--) {
		elements[i + 1] = elements[i];
	}
	elements[pos] = addition;
}


template<typename Type>
void TContainer<Type>::remove(int index) {
	for (int i = index + 1; i < this->size; i++)
		this->elements[i - 1] = this->elements[i];
	size--;
}