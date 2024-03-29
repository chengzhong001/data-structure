#include <vector>
using namespace std;

// leetcode 303
class NumArray
{
public:
	NumArray(vector<int> nums)
	{
		sum = new int[nums.size() + 1];
		sum[0] = 0;
		for (int i = 1; i < nums.size() + 1; i++)
		{
			sum[i] = sum[i - 1] + nums[i - 1];
		}
	}

	int sumRange(int i, int j)
	{
		return sum[j + 1] - sum[i];
	}

private:
	int *sum;
};
