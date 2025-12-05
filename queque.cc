#include "queque.h"
#include <stdexcept>
#include <cstdint>
#include <iostream>
template <typename T>
Q<T>::Q(std::int64_t msize) : inst(msize), outst(msize), msize(msize){
    if (msize<1){
        throw std::invalid_argument("Max size<1");
    }
}
template <typename T>
Q<T>::~Q(){}
template <typename T>
Q<T>::Q(Q<T>& other){
    this->inst=other.inst;
    this->outst=other.outst;
    this->msize=other.msize;
}
template <typename T>
bool Q<T>::isEmpty(){
    return this->inst.isEmpty() && this->outst.isEmpty();
}
template <typename T>
std::int64_t Q<T>::size() const{
    return this->inst.size()+this->outst.size();
}
template <typename T>
void Q<T>::sh(){
    while(!this->inst.isEmpty()){
        this->outst.push(this->inst.pop());
    }
}
template <typename T>
void Q<T>::enqueue(T x){
    if(size()+1>this->msize){
        throw std::overflow_error("Cannot be added.Queue has reached its maximum size.");
    }
    this->inst.push(x);
}
template <typename T>
T Q<T>::dequeue(){
    if(isEmpty()){
        throw std::underflow_error("Queue is empty");
    }
    if(this->outst.isEmpty()){
        sh();
    }
    return this->outst.pop();
}
template <typename T>
void Q<T>::printque(){
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
  }
    for (int i = this->outst.size()-1;i>-1; --i) {
        std::cout << this->outst[i] << " ";
  }
    for (int i = 0; i < this->inst.size(); ++i) {
    std::cout << this->inst[i] << " ";
  }
  std::cout << std::endl;
}