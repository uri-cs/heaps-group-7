#include "MinHeap.hpp"

MinHeap::MinHeap(unsigned int cap){
    array = new int[cap];
    capacity = cap-1;
    size = 0;
}

MinHeap::~MinHeap(){
    delete[] array;
}

void swap(int* y, int* x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

void MinHeap::push(int data){
    if(size == capacity){
        int* array2 = new int[capacity*2];
        for(int i = 1; i<=size;i++){
            array2[i] = array[i];
        }
        capacity *= 2;
        delete[] array;
        array = array2;
    }
    array[++size] = data;
    swim();
}

int MinHeap::count(){ 
    return size;
}

int MinHeap::pop(){
    if(size == 0){
        throw "empty!";
    }
    int temp = array[1];
    swap(&array[size], &array[1]);
    size--;
    sink(1);
    return temp;
}

int MinHeap::peek(){
    if (size == 0){
        throw "Nothing there!";
    }
    return array[1];
}

bool MinHeap::search(int data){
    for(int i = 1; i <= size; ++i){
        if(data == array[i]){
            return true;
        }
    }
    return false;
}

bool MinHeap::search(int i, int data){
    if(size == 0){
        throw "nothing to search";
    }
    for(int j = 1; j<=size;j++){
        if(array[j] == i){
            return true;
        }
    }
    return false;
}


int MinHeap::remove(int i){
    if(size == 0 || i>size || i<0){
        throw "bad info";
    }
    int temp = array[i];
    swap(&array[size], &array[i]);
    size--;
    sink(i);
    return temp;
}


void MinHeap::print(std::ostream &oss){
    for(int i = 1; i<=size;i++){
        oss << array[i];
        oss << ", ";
    }
    oss << "\n";
}


void MinHeap::swim(){ 
    int index = size;
    while(index > 1 && array[index] < array[index/2]){
        swap(&array[index], &array[index/2]);
        index = index / 2;
    }
}

void MinHeap::sink(int i){
    while((i<size && (i*2 < size)) && (array[i] > array[i*2] || array[i] > array[(i*2)+1])){
        if(array[i] > array[i*2] && array[i*2] < array[(i*2) +1]){
            swap(&array[i], &array[i*2]);
            i *= 2;
        }
        else if(array[i] > array[(i*2)+1]){
            swap(&array[i], &array[(i*2)+1]);
            i = (i * 2) + 1;
        }
        else{
            break;
        }
    }
}

void MinHeap::erase(int data){
    erase(1, data);
}

void MinHeap::erase(int i, int data){
    if(i <= size){
        if(array[i] == data){
            remove(i);
         }
         else{
             erase(++i,data);
         }
    }
}
