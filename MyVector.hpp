/*
 * MyVector.hpp
 *
 *  Created on: Nov 29, 2023
 *      Author: jerrbearr
 */

#ifndef MYVECTOR_HPP_
#define MYVECTOR_HPP_
#include <iostream>
#include <string>
using namespace std;

template <typename T> class MyVector {
private:
	int bufferSize;
	T* buffer;
public:
	MyVector();
	MyVector(int);
	MyVector(const MyVector&);
	virtual ~MyVector();
	void add(T item);
	T back() const;
	int find(T item);
	T front() const;
	void remove(T item);
	void reset();
	int size() const;

	// operator overloads
	MyVector<T>& operator=(const MyVector&);
	T& operator[](int) const;

	class VectorError {
		private:
			string e;
		public:
			VectorError() : e("")
			{ };
			VectorError(string s) : e(s)
			{ };
			string what() const {
				return e;
			};
	};
};

template<typename T>
 MyVector<T>::MyVector() : bufferSize(0), buffer(new T[bufferSize])
{ }

template<typename T>
 MyVector<T>::MyVector(int a) : bufferSize(a), buffer(new T[bufferSize]) {
	for (int i = 0; i < a; i++) {
		buffer[i] = 0;
	}
}

template<typename T>
MyVector<T>::MyVector(const MyVector &copyObj) {
    bufferSize = copyObj.bufferSize;
    buffer = new T[bufferSize];
    for (int i = 0; i < bufferSize; ++i) {
        buffer[i] = copyObj.buffer[i];
    }
}

template<typename T>
 MyVector<T>::~MyVector() {
	if (bufferSize != 0) {
	delete[] buffer;
	}
}

template<typename T>
void MyVector<T>::add(T item) {
    int newBufferSize = bufferSize + 1;
    T* newBuffer = new T[newBufferSize];
    for (int i = 0; i < bufferSize; i++) {
        newBuffer[i] = buffer[i];
    }
    delete[] buffer;
    newBuffer[newBufferSize - 1] = item;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

template<typename T>
 T MyVector<T>::back() const {
		if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot call back() method!");
		}
	return buffer[bufferSize - 1];
}

template<typename T>
int MyVector<T>::find(T item) {
    if (bufferSize == 0) {
        throw VectorError("Vector is empty, cannot call find(T) method!");
    }
    int index = -1;
    for (int i = 0; i < bufferSize; i++) {
        if (item == buffer[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        throw VectorError("Given item cannot be found in find(T) method!");
    }
    return index;
}

template<typename T>
 T MyVector<T>::front() const {
		if (bufferSize == 0) {
			throw VectorError("Vector is empty, cannot call front() method!");
	}
		return buffer[0];
}

template<typename T>
void MyVector<T>::remove(T item) {
    if (bufferSize == 0 || buffer == nullptr) {
        throw VectorError("Vector is empty, cannot call remove(T) method!");
    }
    else {
        int indexToRemove = -1;
        for (int i = 0; i < bufferSize; i++) {
            if (buffer[i] == item) {
                indexToRemove = i;
                break;
            }
        }
        if (indexToRemove != -1) {
            T* newBuffer = new T[bufferSize - 1];
            int newIndex = 0;
            for (int i = 0; i < bufferSize; i++) {
                if (i != indexToRemove) {
                    newBuffer[newIndex++] = buffer[i];
                }
            }
            delete[] buffer;
            buffer = newBuffer;
            bufferSize--;
        } else {
            throw VectorError("Item not found in vector!");
        }
    }
}

template<typename T>
 void MyVector<T>::reset() {
	delete[] buffer;
	bufferSize = 0;
}

template<typename T>
 int MyVector<T>::size() const {
	return bufferSize;
}

template<typename T>
MyVector<T>& MyVector<T>::operator =(const MyVector &otherObj) {
    if (this != &otherObj) {
        delete[] buffer;
        bufferSize = otherObj.bufferSize;
        buffer = new T[bufferSize];
        for (int i = 0; i < bufferSize; ++i) {
            buffer[i] = otherObj.buffer[i];
        }
    }
    return *this;
}

template<typename T>
 T& MyVector<T>::operator [](int index) const {
	if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot use [] operator!");
	}
	else if (index >= bufferSize) {
		throw VectorError("Given index is out of range!");
	}
	else return buffer[index];
}

#endif /* MYVECTOR_HPP_ */
