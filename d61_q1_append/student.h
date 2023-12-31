#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
       stack<T> tmp1, tmp2;
       while(!s.empty()) {
        tmp1.push(s.top());
        s.pop();
       }
       while(!empty()) {
        tmp2.push(top());
        pop();
       }
       while(!tmp1.empty()) {
        push(tmp1.top());
        tmp1.pop();
       }
       while(!tmp2.empty()) {
        push(tmp2.top());
        tmp2.pop();
       }
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> s1, s2;
        while(!empty()) {
        s1.push(top());
        pop();
       }
       while(!q.empty()) {
        s2.push(q.front());
        q.pop();
       }
       while(!s2.empty()) {
        push(s2.top());
        s2.pop();
       }
       while(!s1.empty()) {
        push(s1.top());
        s1.pop();
       }
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
       while(!s.empty()) {
        push(s.top());
        s.pop();
       } 
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
       while(!q.empty()) {
        push(q.front());
        q.pop();
       } 
    }
}
