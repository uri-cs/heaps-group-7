#include "MinHeap.hpp"

MinHeap::MinHeap(unsigned int cap){
    array = new int[cap];
    capacity = cap-1;
    size = 0;
}

MinHeap::~MinHeap(){
    delete[] array;
}


void MinHeap::push(int data){
    if(size == capacity){
        int array2[capacity*2];
        for(int i = 1; i<=size;i++){
            array2[i] = array[i];
        }
        capacity *= 2;
        delete[] array;
        array = array2;
    }
    size++;
    array[size] = data;
    swim();

}

int MinHeap::count(){ 
    return size;
}

int MinHeap::pop(){
    return 0;
}

int MinHeap::peek(){
    if (size == 0){
        throw "Nothing there!";
    }
    return array[1];
}

bool MinHeap::search(int data){
    for(int i = 1; i < size; ++i){
        if(data == array[i]){
            return true;
        }
    }
    return false;
}

int MinHeap::remove(int i){
    return 0;
}

void MinHeap::erase(int data){

}

void MinHeap::print(std::ostream &oss){
}

void swap(int* y, int* x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

void MinHeap::swim(){ 
    int temp = size;
    while(array[temp] < array[temp/2] && temp !=1){
        swap(&array[temp], &array[temp/2]);
        temp = temp / 2;
    }
}
void sink(int i){

}

bool search(int i, int data){
    return true;
}

void erase(int i, int data){

}
