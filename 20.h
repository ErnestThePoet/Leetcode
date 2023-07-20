#pragma once
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;

        unordered_map<char, char> left_bracket = { {')','('},{']','['},{'}','{'} };

        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                brackets.push(c);
                break;
            case ')':
            case ']':
            case '}':
                if (brackets.empty()||brackets.top() != left_bracket[c])
                {
                    return false;
                }
                brackets.pop();
                break;
            }
        }

        return brackets.size() == 0;
    }
};