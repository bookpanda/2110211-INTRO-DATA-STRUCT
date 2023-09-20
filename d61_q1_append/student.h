#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        stack<T> temp, temp2;
        while(!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        while(!this->empty()) {
            temp2.push(this->top());
            this->pop();
        }
        while(!temp.empty()) {
            this->push(temp.top());
            temp.pop();
        }
        while(!temp2.empty()) {
            this->push(temp2.top());
            temp2.pop();
        }    
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> temp2;
        stack<T> temp;

        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        while(!this->empty()) {
            temp2.push(this->top());
            this->pop();
        }
        while(!temp.empty()) {
            this->push(temp.top());
            temp.pop();
        }
        while(!temp2.empty()) {
            this->push(temp2.top());
            temp2.pop();
        }
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while(!s.empty()) {
            this->push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        queue<T> temp;
         while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()) {
            this->push(temp.front());
            temp.pop();
        }
    }
}
