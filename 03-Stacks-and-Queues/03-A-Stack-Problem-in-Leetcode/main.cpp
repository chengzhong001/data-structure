/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 02:06:54
 */
#include <iostream>
#include "Solution.h"

int main(int argc, char const *argv[])
{   
    Solution solution = Solution();
    std::cout << std::boolalpha << Solution().isValid("{(){}}") << std::endl;
    
    return 0;
}
