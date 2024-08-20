#include <iostream>
#include <stdexcept>


template <typename T>
class CustomVector
{
private:

    T *arr = nullptr;
    int mSize = 0;

public:

    //creates an empty vector
    CustomVector() {}

    //creates an empty vector with given size
    CustomVector(int size){
        resize(size);
    }

    //creates an vector with given size and fill it with given value
    CustomVector(int size, T defaultValue){
        resize(size, defaultValue);
    }

    //returns the length of the vector
    int size(){
        return mSize;
    }

    //takes a new a size and change the length of the vector
    //if the new size is biger than before, fills the new indexes with fill value
    void resize(int newSize, T fillValue){
        if (newSize < 0)
        {

            throw std::invalid_argument("new size msut be greater than 0");
        }
        else if (newSize > mSize)
        {

            T *newArr = new T[newSize];

            for (int i = 0; i < mSize; i++)
            {
                newArr[i] = arr[i];
            }

            for (int i = mSize; i < newSize; i++)
            {
                newArr[i] = fillValue;
            }

            delete[] arr;
            arr = newArr;
            mSize = newSize;
        }
        else if (newSize < mSize)
        {

            T *newArr = new T[newSize];

            for (int i = 0; i < newSize; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
            mSize = newSize;
        }
    }

    void resize(int newSize)
    {
        T h;
        resize(newSize, h);
    }

    void pushBack(T el)
    {
        resize(mSize + 1, el);
    }

    //insert the new value in the given index
    void insert(int index, T value)
    {
        if(index>mSize || index<0)
            throw std::invalid_argument("index out of bound or <0");
        
        resize(mSize+1);

        for(int i=mSize-1; i>index; i--)
            arr[i] = arr[i-1];

        arr[index] = value;
    }

    //removes the element at the given index
    void remove(int index)
    {
        if(index>mSize || index<0)
            throw std::invalid_argument("index out of bound or <0");
        
        for(int i=index+1; i<mSize; i++)
            arr[i-1] = arr[i];
        resize(mSize-1);
    }

    int &get(int index)
    {
        if (index >= mSize)
            throw std::invalid_argument("index out of range");
        else if (index < 0)
            throw std::invalid_argument("index must be greater than 0");
        else
            return arr[index];
    }

    int &operator[](int index)
    {
        return get(index);
    }

    void print()
    {   
        if(mSize==0){
            std::cout<<"[]"<<std::endl;
            return;
        }
        std::cout << "[";

        for (int i = 0; i < mSize - 1; i++)
            std::cout << arr[i] << ", ";

        std::cout << arr[mSize - 1] << "]" << std::endl;
    }

    ~CustomVector(){
        delete[] arr;
    }
};