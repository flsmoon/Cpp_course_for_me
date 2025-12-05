#include "dinarr.h"
#include <iostream>
#include <stdexcept>
#include <cstdint>
# include <limits>
template <typename T>
D<T>::D(std::int64_t cap){
    if (cap<1){
        throw std::invalid_argument("Capacity<1");
    }
    this->capacity=cap;
    this->data=new T[this->capacity]();
}
template <typename T>
D<T>::D(D<T>& other){
    this->size=other.size;
    this->capacity=other.capacity;
    this-> data=new T[this->capacity];
    for (int i = 0; i < this->size; ++i) {
    this->data[i] = other.data[i];
    }
}
template <typename T>
D<T>::~D(){
    if (this->data){
        delete[] this->data;
    }
}
template <typename T>
void D<T>::clear(){
    if (this->data){
        delete[] this->data;
        this->data=nullptr;
    }
    this->size=0;
    this->capacity=0;
}
template <typename T>
void D<T>::increaseCap(std::int64_t cap){
    if (cap<=this->capacity){
        throw std::invalid_argument("New capacity <= current capacity");
    }
    T* ndata=new T[cap];
    std::int64_t nsize=this->size;
    for (std::int64_t i=0;i<this->size;++i){
        ndata[i]=this->data[i];
    }
    D<T>::clear();
    this->size=nsize;
    this->capacity=cap;
    this->data=ndata;
}
template <typename T>
void D<T>::decreaseCap(std::int64_t cap){
    if (cap>=this->capacity){
        throw std::invalid_argument("New capacity >= current capacity");
    }
    T* ndata=new T[cap];
    std::int64_t minr=(this->size>=cap? cap : this->size);
    for (std::int64_t i=0;i< minr;++i){
        ndata[i]=this->data[i];
    }
    D<T>::clear();
    this->size=minr;
    this->capacity=cap;
    this->data=ndata;
}
template <typename T>
void D<T>::pushback(T x){
    if (this->size+1>=this->capacity){
        D<T>::increaseCap(2*this->capacity);
    }
    this->data[this->size++]=x;  
}
template <typename T>
void D<T>::pushfront(T x){
    if (this->size+1>=this->capacity){
        D<T>::increaseCap(2*this->capacity);
    }
     for (std::int64_t i=this->size;i>0;--i){
        this->data[i]=this->data[i-1];
    }
    this->data[0]=x; 
    this->size++; 
}
template <typename T>
T D<T>::max(){
        if (isEmpty()){
            throw std::invalid_argument("Empty array");
        }
        T cm =std::numeric_limits<T>::lowest();
        for (int i = 0; i < this->size; ++i){
            if (this->data[i]>=cm){
                cm=this->data[i];
            }
        }
        return cm;
}
template <typename T>
T D<T>::min(){
        if (isEmpty()){
            throw std::invalid_argument("Empty array");
        }
        T cm =std::numeric_limits<T>::max();
        for (int i = 0; i < this->size; ++i){
            if (this->data[i]<=cm){
                cm=this->data[i];
            }
        }
        return cm;
}
template <typename T>
T D<T>::sum(){
    T s=0;
    for (int i =0; i < this->size;++i){
        s+=this->data[i];
    }
    return s;
}
template <typename T>
T D<T>::front(){
     if (isEmpty()){
            throw std::invalid_argument("Empty array");
        }
    return this->data[0];
}
template <typename T>
T D<T>::back(){
     if (isEmpty()){
            throw std::invalid_argument("Empty array");
        }
    return this->data[this->size-1];
}
template <typename T>
std::int64_t D<T>::gsize() const{
    return this->size;
}
template <typename T>
void D<T>::insert(std::int64_t idx, T x){
    if (idx<0 ||idx>=this->size){ 
        throw std::out_of_range("The index is outside the array");
    }
    if (this->capacity==this->size){
        D<T>::increaseCap(2*this->capacity);
    }
    for (std::int64_t i=this->size;i>idx;--i){
        this->data[i]=this->data[i-1];
    }
    data[idx]=x;
    ++this->size;
}
template <typename T>
void D<T>::del(std::int64_t idx){
    if (idx<0 || idx>=this->size){
        throw std::out_of_range("The index is outside the array");
    }
    for (std::int64_t i=idx;i<this->size-1;++i){
        this->data[i]=this->data[i+1];
    }
    --this->size;
}
template <typename T>
void D<T>::eraseafter(std::int64_t idx){
     if (idx<0 || idx>=this->size){
        throw std::out_of_range("The index is outside the array");
    }
    // for (std::int64_t i=this->size-1;i>idx;--i){
    //     data[i]=data[i+1];
    // }
    this->size=++idx;
}
template <typename T>
void D<T>::printdata() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  for (int i = 0; i < this-> size; ++i) {
    std::cout << this->data[i] << " ";
  }
  std::cout << std::endl;
}
template <typename T>
T& D<T>::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx >= this-> size) {
    throw std::invalid_argument("Out of range");
  }
  return this-> data[idx];     
}
template <typename T>
void D<T>::printcap() const{
    std::cout<<this->capacity<< std::endl;
}
