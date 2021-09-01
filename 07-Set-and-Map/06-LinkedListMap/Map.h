#ifndef MAP_H
#define MAP_H

template<typename K, typename V>
class Map{
public:
    void add(K key, V value);
    V remove(K key);
    bool contains(K key);
    V get(K key);
    void set(K key, V newValue);
    bool isEmpty();
};

#endif