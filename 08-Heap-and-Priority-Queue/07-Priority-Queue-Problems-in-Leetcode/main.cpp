#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> dic;
        std::vector<int> res;
        for (int v : nums)
        {
            if (dic.count(v) == 0)
                dic[v] = 1;
            else
                dic[v] += 1;
        }
        for (auto i : dic)
        {
            if (i.second >= k)
            {
                res.push_back(i.first);
                // std::cout << i.first << " ";
            }
        }
        return res;
    }
};