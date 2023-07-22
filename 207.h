#pragma once
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for (auto& i : prerequisites)
        {
            indegree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }

        // stack<int> topo_stack;
        queue<int> topo_queue;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                //topo_stack.push(i);
                topo_queue.push(i);
            }
        }

        int visited_node_count = 0;

        while (!topo_queue.empty())
        {
            //int current_node = topo_stack.top();
            int current_node = topo_queue.front();
            topo_queue.pop();

            visited_node_count++;

            for (auto j : graph[current_node])
            {
                indegree[j]--;
                if (indegree[j] == 0)
                {
                    //topo_stack.push(j);
                    topo_queue.push(j);
                }
            }
        }

        return visited_node_count == numCourses;
    }
};