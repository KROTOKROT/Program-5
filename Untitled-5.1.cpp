#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Vect {
private:
    T* arr;
    size_t capacity;
    size_t current;

public:
    Vect() : arr(new T[1]), capacity(1), current(0) {}

    void push(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];

            for (size_t i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[current] = data;
        current++;
    }

    void pop() {
        if (current == 0) {
            throw std::out_of_range("Vect is empty");
        }
        current--;
    }

    T get(size_t index) const {
        if (index < current) {
            return arr[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    size_t size() const {
        return current;
    }

    ~Vect() {
        delete[] arr;
    }
};

template <typename T>
class Stack {
private:
    Vect<T> vect;

public:
    void push(const T& element) {
        vect.push(element);
    }

    void pop() {
        vect.pop();
    }

    T top() const {
        if (vect.size() == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return vect.get(vect.size() - 1);
    }

    bool empty() const {
        return vect.size() == 0;
    }
};

int main() {
    try {
        Stack<int> intStack;
        intStack.push(1);
        intStack.push(2);
        std::cout << "Top element: " << intStack.top() << std::endl;
        intStack.pop();
        intStack.pop();
        intStack.pop();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}