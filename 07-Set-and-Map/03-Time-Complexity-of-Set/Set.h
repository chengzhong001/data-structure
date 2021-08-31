#ifndef SET_SET_H
#define SET_SET_H
template<typename T>
class Set{
public:
    void add(T e);
    void remove(T e);
    bool contains(T e);
    int getSize();
    bool isEmpty();
};

#endif