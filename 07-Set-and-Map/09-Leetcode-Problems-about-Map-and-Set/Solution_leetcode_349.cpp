#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        // vector<int> res;
        set<int> numset1;
        set<int> numset2;
        for (int num : nums1)
        {
            numset1.insert(num);
        }

        for(int num: nums2){
            if(numset1.count(num))
                numset2.insert(num);
        }

        vector<int> res(numset2.begin(),numset2.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums1 = {1, 2, 2, 3, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res = Solution().intersection(nums1, nums2);

    for(int num: res){
        std::cout << num << "\n";
    }
    

    return 0;
}
