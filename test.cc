#include "dinarr.h"
#include "dinarr.cc"
#include "stack.h"
#include "stack.cc"
#include "queque.h"
#include "queque.cc"
#include <iostream>
int main(){
    std::cout << "TEST DINARR" << std::endl;
    D<float> arr(10);
    for (int i =1;i<11;++i){
        arr.pushback(i);
    }
    arr.pushfront(11);
    arr.printdata();
    std::cout << "MIN " << arr.min() << std::endl;
    std::cout << "MAX "<< arr.max() << std::endl;
    std::cout << "SUM "<< arr.sum() << std::endl;
    std::cout << "FRONT "<< arr.front() << std::endl;
    std::cout << "BACK " << arr.back() << std::endl;
    std::cout << "[0] "<< arr[0] << std::endl;
    arr.insert(3,12);
    std::cout << "AFTER INSERT3" << std::endl;
    arr.printdata();
    arr.del(3);
    std::cout << "AFTER DEL3" << std::endl;
    arr.printdata();
    arr.eraseafter(5);
    std::cout << "AFTER ERASEAFTER5" << std::endl;
    arr.printdata();
    arr.decreaseCap(3);
    std::cout << "AFTER DECREASECAP3" << std::endl;
    arr.printdata();
    arr.increaseCap(10);
    std::cout << "PRINTCAP10AFTERINCREASE"<< std::endl;
    arr.printcap();
    std::cout << "TEST STACK" << std::endl;
    st<char> stack(10);
    stack.push('A');
    stack.push('B');
    stack.push('C');
    stack.push('D');
    stack.printst();
    std::cout << "SIZE " << stack.size() << std::endl;
    std::cout << "TOP " << stack.top() << std::endl;
    stack.push('K');
    std::cout << "TOPAFTERADDK " << stack.top() << std::endl;
    std::cout << "DO POP(): " << stack.pop() <<std::endl;
    stack.printst();
    std::cout << "[2] "<< stack[2] << std::endl;
    std::cout << "TEST QUEUE" << std::endl;
    Q<int> q(6);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printque();
    std::cout << "SIZE " << q.size() << std::endl;
    std::cout << "DEQUEUE10 " << q.dequeue() << std::endl;
    std::cout << "DEQUEUE20 "<< q.dequeue() <<std::endl ;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    std::cout << "AFTERAD405060 "<<std::endl ;
    q.printque();



return 0;}