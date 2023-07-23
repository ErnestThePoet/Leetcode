#pragma once
#include <vector>
#include <stack>
#include <functional>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> operands;

        unordered_map<string, function<int(int, int)>> operators{
            {"+", [](int x, int y) { return x + y; }},
            {"-", [](int x, int y) { return x - y; }},
            {"*", [](int x, int y) { return x * y; }},
            {"/", [](int x, int y) { return x / y; }}
        };

        for (auto& s : tokens)
        {
            if (operators.find(s) != operators.cend())
            {
                int x = operands.top();
                operands.pop();
                int y = operands.top();
                operands.pop();

                operands.push(operators[s](y, x));
            }
            else
            {
                operands.push(stoi(s));
            }
        }

        return operands.top();
    }
};