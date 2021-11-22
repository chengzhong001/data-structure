#include <string>
#include <map>
using namespace std;

class MapSum
{
public:
    MapSum()
    {
        root = new Node();
    }

    void insert(string key, int val)
    {
        Node *cur = root;

        for (char c : key)
        {
            if (cur->next.find(c) == cur->next.end())
                cur->next.insert(std::make_pair(c, Node()));
            cur = &cur->next.find(c)->second;
        }
        cur->value = val;
    }

    int sum(string prefix)
    {
        Node *cur = root;
        for (char c : prefix)
        {
            if (cur->next.find(c) == cur->next.end())
                return 0;
            cur = &cur->next.find(c)->second;
        }
        return sum(cur);
    }

private:
    class Node
    {
    private:
        // bool isWord;
        int value;
        std::map<char, Node> next;
        friend MapSum;

    public:
        Node(int value) : value(value) {}
        Node() : value(0) {}
    };
    Node *root;

    int sum(Node *node)
    {
        if(node->next.size() == 0){
            return node->value; 
        }
        int res = node->value;
        for (auto iter = node->next.begin(); iter != node->next.end(); iter++)
        {
            res += sum(&node->next.find(iter->first)->second);
        }
        return res;
    }
};