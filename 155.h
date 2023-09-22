#pragma once
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> s_;
    stack<int> min_;
public:
    MinStack()
    {

    }

    void push(int val)
    {
        s_.push(val);
        if (!min_.empty())
        {
            min_.push(min(min_.top(), val));
        }
        else
        {
            min_.push(val);
        }
    }

    void pop()
    {
        s_.pop();
        min_.pop();
    }

    int top()
    {
        return s_.top();
    }

    int getMin()
    {
        return min_.top();
    }
};