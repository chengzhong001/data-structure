/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 00:59:54
 */

template<class T>
class Stack {
public:
    int getSize();

    bool isEmpty();

    void push(T e);

    T pop();

    T peek();
};