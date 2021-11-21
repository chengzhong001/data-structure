#include <map>
#include <string>

class Trie
{
private:
    class Node
    {
    public:
        bool isWord;
        std::map<char, Node> next;

    public:
        Node(bool isWord) : isWord(isWord) {}
        Node() : isWord(false) {}
    };
    Node *root;
    int size;

public:
    Trie() : root(new Node()){};
    ~Trie() { delete root; };

    void add(std::string word)
    {
        Node *cur = root;

        for (char c : word)
        {
            if (cur->next.find(c) == cur->next.end())
                cur->next.insert(std::make_pair(c, Node()));
            cur = &cur->next.find(c)->second;
        }
        if(!cur->isWord){
            cur->isWord = true;
            size++;
        }
        
    }

    bool contains(std::string word){
        Node *cur = root;
        for(char c: word){
            if(cur->next.find(c) == cur->next.end())
                return false;
            cur = &cur->next.find(c)->second;
        }
        return cur->isWord;
    }

    bool isPrefix(std::string word){
        Node *cur = root;
        for(char c: word){
            if(cur->next.find(c) == cur->next.end())
                return false;
            cur = &cur->next.find(c)->second;
        }
        return true;
    }

};
