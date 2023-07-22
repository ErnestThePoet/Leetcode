#pragma once
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        istringstream iss(s);

        string current;
        iss >> current;

        string result=current;

        while (iss >> current)
        {
            result = current + " " + result;
        }

        return result;
    }
};