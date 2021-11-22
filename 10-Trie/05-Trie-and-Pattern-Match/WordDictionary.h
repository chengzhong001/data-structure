#include <iostream>
#include <map>

using namespace std;

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *cur = root;

        for (char c : word)
        {
            if (cur->next.find(c) == cur->next.end())
                cur->next.insert(std::make_pair(c, Node()));
            cur = &cur->next.find(c)->second;
        }
        if (!cur->isWord)
        {
            cur->isWord = true;
            size++;
        }
    }

    bool search(string word)
    {
        return match(root, word, 0);
    }

    ~WordDictionary()
    {
        delete root;
    }

private:
    class Node
    {
    private:
        bool isWord;
        std::map<char, Node> next;
        friend WordDictionary;

    public:
        Node(bool isWord) : isWord(isWord) {}
        Node() : isWord(false) {}
    };
    Node *root;
    int size;
    bool match(Node *node, string word, int index)
    {
        if (index == word.length())
            return node->isWord;
        char c = word[index];
        if (c != '.')
        {
            if (node->next.find(c) == node->next.end())
                return false;
            return match(&node->next.find(c)->second, word, index + 1);
        }
        else
        {
            for (auto iter = node->next.begin(); iter != node->next.end(); iter++)
            {
                if (match(&node->next.find(iter->first)->second, word, index + 1))
                    return true;
            }
            return false;
        }
    }
};
