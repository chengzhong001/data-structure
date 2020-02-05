/*
 * @Description:
 * @Author: zhengchengzhong
 * @Date: 2020-02-06 02:16:28
 * leetcode: 20. 有效的括号
 * https://leetcode-cn.com/problems/valid-parentheses/
 */

#include <iostream>
#include <stack>
#include <string>

class Solution {
  public:
    bool isValid(std::string s) {
        std::stack<char> *stack = new std::stack<char>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            if (c == '(' || c == '[' || c == '{') {
                stack->push(c);
            } else {
                if (stack->empty()) {
                    return false;
                }
                char topChar = stack->top();
                if (c == ')' && topChar != '(') {
                    return false;
                }
                if (c == ']' && topChar != '[') {
                    return false;
                }
                if (c == '}' && topChar != '{') {
                    return false;
                }
                stack->pop();
            }
        }
        return stack->empty();
    }
};
