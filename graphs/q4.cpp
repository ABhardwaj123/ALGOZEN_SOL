#include<iostream>
#include<vector>
#include <queue>
using namespace std;

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);

        for(int start = 0; start < n; start++) {

            if(color[start] != -1) continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()) {

                int ele = q.front();
                q.pop();

                for(int nbr : graph[ele]) {

                    if(color[nbr] == -1) {
                        color[nbr] = !color[ele];
                        q.push(nbr);
                    }
                    else if(color[nbr] == color[ele]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }