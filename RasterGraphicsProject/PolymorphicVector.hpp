#pragma once
#include "PolymorphicPtr.hpp"
#include "Vector.hpp"

template<typename T>
class PolymorphicVector {
private:
	Vector<PolymorphicPtr<T>> ptrs;

public:
	void add(T* ptr);
	void execute(size_t index, void(*func)(T*));
	void execute(size_t index, void(*func)(const T*)) const;
};

template<typename T>
void PolymorphicVector<T>::add(T* ptr) {
	ptrs.push_back(ptr);
}

template<typename T>
void PolymorphicVector<T>::execute(size_t index, void(*func)(T*)) {
	func(ptrs[index].get());
}


template<typename T>
void PolymorphicVector<T>::execute(size_t index, void(*func)(const T*)) const {
	func(ptrs[index].get());
}