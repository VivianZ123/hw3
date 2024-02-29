#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack() : std::vector<T>() {}
    //~Stack();
    size_t size() const {
        return std::vector<T>::size();
    }
    bool empty() const {
        return std::vector<T>::empty();
    }
    void push(const T& item) {
        std::vector<T>::push_back(item);
    }
    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }
        std::vector<T>::pop_back();
    }  // throws std::underflow_error if empty
    T const & top() const {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }
        return std::vector<T>::back();
    } // throws std::underflow_error if empty
    // Add other members only if necessary
};


#endif