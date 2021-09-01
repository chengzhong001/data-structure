#ifdef MAP_H
#define MAP_H

template<typename K, typename V>
class map{
public:
    void add(K key, V value);
    V remove(K key);
    bool contains(K key);
    v get(K key);
    void set(K key, V newValue);
    bool isEmpty();
}

#endif