#include "MinHeap.hpp"

MinHeap::MinHeap(unsigned int cap){
    array = new int[cap];
    capacity = cap-1;
    size = cap-1;
}

MinHeap::~MinHeap(){
    delete[] array;
}

void doubleSpace(int capacity){
    capacity= capacity * 2;
    int array2[capacity];
    for(int i = 1; i< capacity; ++i){
        array2[i] = array[i];
    }
}

void MinHeap::push(int data){
    if(size == capacity){
        doubleSpace(capacity);
    }



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

void swim(){
    for()
    
}
void sink(int i){

}

bool search(int i, int data){
    return true;
}

void erase(int i, int data){

}
