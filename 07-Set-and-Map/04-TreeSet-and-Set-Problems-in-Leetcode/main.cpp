#include <vector>
#include <iostream>
#include <set>
using namespace std;

// 804. 唯一摩尔斯密码词
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string moscodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> moswords;
        for (string word : words)
        {
            string res = "";
            for (size_t i = 0; i < word.size(); i++)
            {
                res += moscodes[word[i] - 'a'];
            }
            moswords.insert(res);
        }
        return moswords.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> words = {"gin", "zen", "gig", "msg"};

    cout << Solution().uniqueMorseRepresentations(words) << endl;
    return 0;
}
