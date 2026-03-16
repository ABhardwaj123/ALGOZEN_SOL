#include<stdio.h>
#include<iostream>
#include<vector>
#include<climits>

//finding critical connections
//TC : O(V + E) -> dfs with modification

using namespace std;
int timer = 1;

void dfs(int node , int parent , vector<int>& firstTime , vector<int>& bestTime , vector<vector<int>>& adjList , vector<vector<int>>& bridges, vector<int>& visited){

    firstTime[node] = timer;
    bestTime[node] = timer;

    visited[node] = 1;

    for(auto it : adjList[node]){

        if(it == parent){
            continue;
        }

        if(visited[it] == 1){
            bestTime[node] = min(bestTime[node] , bestTime[it]);
        }else{

            dfs(it , node , firstTime , bestTime , adjList , bridges , visited);
            
            bestTime[node] = min(bestTime[node] , bestTime[it]);
            if(bestTime[it] > firstTime[node]){
                bridges.push_back({it , node});
            }
        }
    }

}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

    vector<int> firstTime(n);
    vector<int> bestTime(n);

    vector<int> visited(n ,0);

    vector<vector<int>> adjList(n);
    for(int i = 0 ; i < connections.size() ; i++){
        int u = connections[i][0];
        int v = connections[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    vector<vector<int>> bridges;

    dfs(0 , -1 , firstTime , bestTime , adjList , bridges , visited);

    return bridges;
}
