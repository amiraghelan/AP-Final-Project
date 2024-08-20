#include <iostream>
#include <stdexcept>

template <typename T>
class CustomVectorPointer
{
private:
    T **arr;
    int mSize = 0;

public:
    // creates an empty vector
    CustomVectorPointer() {}

    // creates an empty vector with given size
    CustomVectorPointer(int size)
    {
        resize(size);
    }

    // creates an vector with given size and fill it with given value
    CustomVectorPointer(int size, T defaultValue)
    {
        arr = new T *[size];
        mSize = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = new T(defaultValue);
        }
    }

    ~CustomVectorPointer()
    {
        for (int i = 0; i < mSize; i++)
            delete arr[i];
        
        // delete[] arr;
    }

    // returns the length of the vector
    int size()
    {
        return mSize;
    }

    void resize(int newSize)
    {
        if (newSize < 0)
        {

            throw std::invalid_argument("new size msut be greater than 0");
        }
        else if (newSize > mSize)
        {
            T **newArr = new T *[newSize];
            for (int i = 0; i < mSize; i++)
                newArr[i] = arr[i];

            delete[] arr;
            arr = newArr;
            mSize = newSize;
        }
        else if (newSize < mSize)
        {

            T **newArr = new T *[newSize];

            for (int i = 0; i < newSize; i++)
            {
                newArr[i] = arr[i];
            }

            for (int i = newSize; i < mSize; i++)
                delete arr[i];

            delete[] arr;
            arr = newArr;
            mSize = newSize;
        }
    }

    void pushBack(T el)
    {
        resize(mSize + 1);
        arr[mSize-1] = new T(el);
    }

    // insert the new value in the given index
    void insert(int index, T value)
    {
        if (index > mSize || index < 0)
            throw std::invalid_argument("index out of bound or <0");

        resize(mSize + 1);

        for (int i = mSize - 1; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = new T(value);
    }

    // removes the element at the given index
    void remove(int index)
    {
        if (index > mSize || index < 0)
            throw std::invalid_argument("index out of bound or <0");

        delete arr[index];
        print();
        for (int i = index; i < mSize-1; i++)
            arr[i] = arr[i+1];
        mSize -=1;

    }

    int &get(int index)
    {
        if (index >= mSize)
            throw std::invalid_argument("index out of range");
        else if (index < 0)
            throw std::invalid_argument("index must be greater than 0");
        else
            return *arr[index];
    }

    int &operator[](int index)
    {
        return get(index);
    }

    void print()
    {
        if (mSize == 0)
        {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";

        for (int i = 0; i < mSize - 1; i++)
            std::cout << *arr[i] << ", ";

        std::cout << *arr[mSize - 1] << "]" << std::endl;
    }
};