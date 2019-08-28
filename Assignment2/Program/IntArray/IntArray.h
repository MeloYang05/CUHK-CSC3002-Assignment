#ifndef INTARRAY_H
#define INTARRAY_H
#include <string>

class IntArray {
public:
    //Construct an empty IntArray
    IntArray();

    //Construct an IntArray with size n
    IntArray(int n);

    //Method to get the size of the IntArray
    int size();

    //Method returns the element at position k.If k is out of range, an error will be dilivered.
    int get(int k);

    //Method that assigns value to the element at position k.If k is out of range, an error will be dilivered.
    void put(int k, int value);
    ~IntArray();

private:
    int count;
    int *array;
};

#endif // INTARRAY_H
