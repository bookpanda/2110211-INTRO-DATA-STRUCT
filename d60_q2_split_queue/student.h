#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    // code here
    int idx=0;
    while(!this->empty()) {
        qs[idx].push(this->front());
        idx++;
        idx %= k;
        this->pop();
    }
    return qs;
}

#endif
