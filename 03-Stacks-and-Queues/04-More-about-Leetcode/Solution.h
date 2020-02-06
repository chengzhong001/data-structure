/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 04:55:40
 */

#include <cassert>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        ArrayStack<char> *stack = new ArrayStack<char>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            if (c == '(' || c == '[' || c == '{') {
                stack->push(c);
            } else {
                if (stack->isEmpty()) {
                    return false;
                }
                char topChar = stack->pop();
                if (c == ')' && topChar != '(') {
                    return false;
                }
                if (c == ']' && topChar != '[') {
                    return false;
                }
                if (c == '}' && topChar != '{') {
                    return false;
                }
                // stack->pop();
            }
        }
        return stack->isEmpty();
    }

private:
    template <class T>
    class Array {
       private:
        T *data;
        int size;
        int capacity;

        void resize(int newCapacity) {
            T *newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            data = newData;
            capacity = newCapacity;
            newData = NULL;
        }

       public:
        Array(int capacity) {
            data = new T[capacity];
            size = 0;
            this->capacity = capacity;
        }

        Array() {
            data = new T[10];
            size = 0;
            capacity = 10;
        }

        int getCapacity() { return capacity; }

        int getSize() { return size; }

        bool isEmpty() { return size == 0; }

        void add(int index, T e) {
            assert(index >= 0 && index <= size);
            if (size == capacity) {
                resize(capacity * 2);
            }
            for (int i = size - 1; i >= index; --i) {
                data[i + 1] = data[i];
            }
            data[index] = e;
            size++;
        }

        void addFirst(T e) { add(0, e); }

        void addLast(T e) { add(size, e); }

        T get(int index) {
            assert(index >= 0 && index < size);
            return data[index];
        }

        T getLast() { return get(size - 1); }

        T getFirst() { return get(0); }

        void set(int index, T e) {
            assert(index >= 0 && index < size);
            data[index] = e;
        }

        bool contains(T e) {
            for (int i = 0; i < size; ++i) {
                if (data[i] == e) {
                    return true;
                }
            }
            return false;
        }

        int find(T e) {
            for (int i = 0; i < size; ++i) {
                if (data[i] == e) {
                    return i;
                }
            }
            return -1;
        }

        T remove(int index) {
            assert(index >= 0 && index < size);
            T ret = data[index];
            for (int i = index + 1; i < size; ++i) {
                data[i - 1] = data[i];
            }
            size--;
            if (size == capacity / 4 && capacity != 0) {
                resize(capacity / 2);
            }
            return ret;
        }

        int removeFirst() { return remove(0); }

        T removeLast() { return remove(size - 1); }

        void removeElement(T e) {
            int index = find(e);
            if (index != -1) {
                remove(index);
            }
        }

        /**
         * 打印数组的所有元素
         */
        void print() {
            std::cout << "Array: size = " << size
                      << ", capacity = " << getCapacity() << std::endl;
            toPrint();
            std::cout << std::endl;
        }

        void toPrint() {
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                std::cout << data[i];
                if (i != size - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]";
        }

        std::string toString() {
            std::string res = "Array: size = " + std::to_string(size) +
                              ", capacity = " + std::to_string(capacity) + "\n";
            res += "[";
            for (int i = 0; i < size; i++) {
                res += std::to_string(data[i]);
                if (i != size - 1) {
                    res += ", ";
                }
            }
            res += "]";
            return res;
        }
    };

    template <class T>
    class Stack {
       public:
        int getSize();

        bool isEmpty();

        void push(T e);

        T pop();

        T peek();
    };

    template <class T>
    class ArrayStack : public Stack<T> {
       private:
        Array<T> *array;

       public:
        ArrayStack(int capacity) { array = new Array<T>(capacity); }

        ArrayStack() { array = new Array<T>(); }

        ~ArrayStack() {
            delete[] array;
            array = nullptr;
        }

        int getSize() { return array->getSize(); }

        bool isEmpty() { return array->isEmpty(); }

        void push(T e) { return array->addLast(e); }

        T pop() { return array->removeLast(); }

        T peek() { return array->getLast(); }

        void print() {
            std::cout << "Stack: [";
            for (int i = 0; i < array->getSize(); i++) {
                std::cout << array->get(i);
                if (i != array->getSize() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "] Top" << std::endl;
        }
    };
};