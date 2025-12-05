#include "stack.h"
#include <cstdint>
#include <stdexcept>
template <typename T>
st<T>::st(std::int64_t msize): data(msize), msize(msize){
    if (msize<1){
        throw std::invalid_argument("Max size<1");
    }
}
template <typename T>
st<T>::~st(){}
template <typename T>
st<T>::st(st<T>& other){
    this->data=other.data;
    this->msize=other.msize;
}
template <typename T>
bool st<T>::isEmpty(){
    return this->data.isEmpty();
}
template <typename T>
void st<T>::push(T x){
    if (this->data.gsize()+1>this->msize){
        throw std::overflow_error("Cannot be added.Stack has reached its maximum size.");
    }
    this->data.pushback(x);
}
template <typename T>
T st<T>::top(){
    if (isEmpty()){
        throw std::underflow_error("Stack is empty.");
    }
    return this->data.back();
}
template <typename T>
T st<T>::pop(){
    if (isEmpty()){
        throw std::underflow_error("Stack is empty.");
    }
    T v=this->data.back();
    this->data.del(data.gsize()-1);
    return v;
}
template <typename T>
std::int64_t st<T>::size() const{
    return this->data.gsize();
}
template <typename T>
T& st<T>::operator[](std::int64_t idx){
    return this->data[idx];
}
template <typename T>
void st<T>::printst(){
    this->data.printdata();
}
