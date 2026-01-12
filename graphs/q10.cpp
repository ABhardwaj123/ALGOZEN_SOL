#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//course schedule
//TC: O(V + E) {same as that of normal bfs}
//SC: O(V + E) {V for indegree vector , V for queue , V + E for adjacency list}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);

        //indegree vector
        for(int i = 0 ; i < prerequisites.size() ;i++){
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        //adjMatrix
        vector<vector<int>> adjList(numCourses);

        for(int i = 0 ; i < prerequisites.size() ; i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        //filling our queue
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topoSort;
        //filling our topo sort vector
        while(!q.empty()){
            int v = q.front();
            q.pop();

            topoSort.push_back(v);

            for(int i = 0 ; i < adjList[v].size() ; i++){
                indegree[adjList[v][i]]--;

                if(indegree[adjList[v][i]] == 0){
                    q.push(adjList[v][i]);
                }
            }
        }

        return topoSort.size()== numCourses ? true : false;
    }