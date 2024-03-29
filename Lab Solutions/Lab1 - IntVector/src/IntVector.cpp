/* Lab I: Vector of Integers
 * Due: 19.01.17
 * Class: Gagnaskipan 2017
 * Solution by: Edda Steinunn/eddasr15
 * IntVector.cpp file
 */

#include <cmath>
#include "IntVector.h"

using namespace std;

IntVector::IntVector()
{
    // Empty dynamic array of initial capacity created
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    count = 0;
}

IntVector::IntVector(int size, int value)
{
    // If size is negative an empty vector is initialized
    // Calling constructor from another constructor does not work
    // Code is therefore repeated from IntVector()
    if (size < 0)
    {
        capacity = INITIAL_CAPACITY;
        array = new int[capacity];
        count = 0;
    }
    // If size is above 0 and within initial capacity, a new dynamic array is created with user determined
    // size, with size-times copies of value as its' elements
    else
    {
        if (size <= INITIAL_CAPACITY){
            capacity = INITIAL_CAPACITY;
        }
        else{
            capacity = size;
        }
        array = new int[capacity];
        count = size;
        for (int i = 0; i < size; i++){
           array[i] = value;
        }
    }
}

// Copy constructor
IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count)
{
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}

// A destructor
IntVector::~IntVector()
{
    delete[]array;
    array = NULL;
}

// Public member functions

void IntVector::push_back(int elem)
{
    // Expands capacity if needed if count has reached limits
    if (count == capacity)
    {
        // Capacity doubled
        capacity = capacity * 2;
        // Current elements stored in a temporary array
        int *tempArr = new int[capacity];
        for (int i = 0; i < count; i++){
                tempArr[i] = array[i];
        }
        // Array deleted, then redefined at double capacity
        delete[] array;
        array = NULL;
        array = tempArr;
        // tempArr deleted
        tempArr = NULL;
        delete[] tempArr;
    }
    array[count] = elem;
    count++;
}

void IntVector::insert(int index, int elem)
{
    if (index <= count && index >= 0)
    {
        if (count == capacity)
        {
            // Capacity doubled
            capacity = capacity * 2;
            // Current elements stored in a temporary array
            int *tempArr = new int[capacity];
            for (int i = 0; i < count; i++){
                    tempArr[i] = array[i];
            }
            // Array deleted, then redefined at double capacity
            delete[] array;
            array = NULL;
            array = tempArr;
            // tempArr deleted
            tempArr = NULL;
            delete[] tempArr;
        }
        int temp = count;
        // Right shifts index-th element and elements above by one
        for (; temp > index ; temp--){
            array[temp] = array[temp - 1];
        }
        // count increases,then set index-th element to elem
        count++;
        array[index] = elem;
    }
    // Throws exception if index is out of range
    else
    {
        throw IndexOutOfRangeException();
    }
}

int IntVector::at(int index) const
{
    // Checks if index is within range,
    // returns element at position index
    if (index < count && index >= 0 && !empty())
    {
        int element;
        element = array[index];
        return element;
    }
    // Throws exception if index is out of range
    else
    {
        throw IndexOutOfRangeException();
    }

    return 0;
}

void IntVector::set_value_at(int index, int elem)
{
    // Changes index-th element to elem
    if (index < count && index >= 0 && !empty())
    {
        array[index] = elem;
    }
    // Throws exception if index is out of range
    else
    {
        throw IndexOutOfRangeException();
    }

}

int IntVector::size() const
{
    // Count determines IntVector size
    return count;
}

bool IntVector::empty() const
{
    // If count is 0 vector is empty and true is returned, else false
    if(count == 0){
        return true;
    }
    else{
        return false;
    }
}

void IntVector::remove_at(int index)
{
    if (index < count && index >= 0 && !empty())
    {
        // Left shift index element and elements above by one
        // causing index element to be "deleted"
        for (; index < (count-1) ; index++){
            array[index] = array[index + 1];
        }
        // Lower count because array size now reduced by one
        count--;
    }
    // Throws exception if index is out of range
    else
    {
        throw IndexOutOfRangeException();
    }
}

int IntVector::pop_back()
{
    // Throws exception if vector is empty
    if (empty())
    {
        throw EmptyException();
    }
    // Else stores last element in a variable, then sets it to zero in array
    // and reduces vectors size by one. Last element then returned
    else
    {
        count--;
        int lastElem = array[count];
        array[count] = 0;

        return lastElem;
    }
}

// Removes all the elements from the list
void IntVector::clear()
{
    for (int i = 0; i < count; i++){
        array[i] = 0;
    }
    count = 0;
}

//Overloaded operators

void IntVector::operator=(const IntVector& vec)
{
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index)
{
    // Returns element at index-th position
    if (index < count && index >= 0 && !empty())
    {
        return array[index];
    }
    // Throws exception if index is out of range
    else
    {
        throw IndexOutOfRangeException();
    }
}

ostream& operator<< (ostream& out, const IntVector& rhs)
{
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs.at(i);
    }
    return out;
}
