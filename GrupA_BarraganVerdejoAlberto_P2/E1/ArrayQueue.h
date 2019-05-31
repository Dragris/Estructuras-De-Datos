/* 
 * File:   ArrayQueue.h
 * Author: dragr
 *
 * Created on 26 de febrero de 2019, 11:25
 */

#ifndef ARRAYQUEUE_H
#define	ARRAYQUEUE_H

#include <vector>

class ArrayQueue {
public:
    ArrayQueue();
    ArrayQueue(const ArrayQueue& orig);
    virtual ~ArrayQueue();
    
    ArrayQueue(const int a);
    void enqueue(int key);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void print();
    int getFront();
private:
    int MAX_Size;
    //int size;
    std::vector<int> data;
};

#endif	/* ARRAYQUEUE_H */

