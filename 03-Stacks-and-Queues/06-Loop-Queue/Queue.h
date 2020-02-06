/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 07:44:25
 */
template <class T>
class Queue {
public:
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
};
