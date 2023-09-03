#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int distance(const int a, const int b)
    {
        return abs(a - b);
    }

    int distance(const vector<int>& interval)
    {
        return distance(interval[0], interval[1]);
    }

    bool hasOverlap(const vector<int>& intervalA, const vector<int>& intervalB)
    {
        return (intervalA[0] == intervalB[0])
            || (intervalA[0] < intervalB[0]
                ? (distance(intervalA) >= distance(intervalA[0], intervalB[0]))
                : (distance(intervalB) >= distance(intervalA[0], intervalB[0])));
    }

    vector<int> mergeOverlap(const vector<int>& intervalA, const vector<int>& intervalB)
    {
        return { min(intervalA[0],intervalB[0]),max(intervalA[1],intervalB[1]) };
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),
            intervals.end(),
            [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> result;

        vector<int> head = intervals[0];

        for (auto i = intervals.cbegin() + 1; i != intervals.cend(); ++i)
        {
            if (hasOverlap(head, *i))
            {
                head = mergeOverlap(head, *i);
            }
            else
            {
                result.push_back(head);
                head = *i;
            }
        }

        result.push_back(head);

        return result;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        intervals.push_back(newInterval);

        return merge(intervals);
    }
};