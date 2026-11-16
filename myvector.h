#pragma once
#ifndef PAYE_MYVECTOR_H
#define PAYE_MYVECTOR_H

#include <cstddef>
#include <stdexcept>

template<typename T>
class MyVector
{
	private:
		T* element;
		//how many elements are actually stored in vector // size()
		std::size_t array_size;

		//how many elements we have alocated space for // reserve()
		std::size_t space;
	public:
		//constructor
		MyVector()
		{
			//start clean by default
			element = nullptr;
			array_size = 0;
			space = 0;
		}

		//destructor
		~MyVector()
		{
			//runs automatically when vector goes out of scope
			delete[] element;
		}

		//prevent copying // prevent undefined behavior/memory leak
		MyVector(const MyVector&) = delete;
		MyVector& operator=(const MyVector&) = delete;

		//return number of elements in container
		std::size_t size() const
		{
			return array_size;
		}

		//return allocated memory capacity
		std::size_t capacity() const 
		{
			return space;
		}

		//allocate more space
		void reserve(std::size_t new_capacity)
		{
			if(new_capacity <= space)
			{
				return; // big enough already
			}

			//allocate new space for vector
			T* new_element = new T[new_capacity];

			//move old vector into new bigger vector
			try
			{
				for(std::size_t i = 0; i < array_size; i++)
				{
					new_element[i] = element[i];
				}
			}
			catch (...)
			{
				//if error then clean up failed memory and throw exception
				delete[] new_element;
				throw;
			}

			//release old vector spaceafter successful copy and switch to new aray;
			delete[] element;
			element = new_element;
			space = new_capacity;
		}

		void push_back(const T& value)
		{
			if(array_size == space) // if full
			{
				if(space == 0) // if first element
				{
					reserve(1);
				}
				else
				{
					reserve(space * 2);//double allocated space//faster on average
				}
			}

			element[array_size] = value;
			array_size++;
		}

		T& at(std::size_t index)
		{
			if(index >= array_size)
			{
				throw std::out_of_range("Index out of range!");
			}

			return element[index];
		}
};

#endif
