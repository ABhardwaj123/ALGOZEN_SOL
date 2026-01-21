#include<iostream>
#include<vector>

using namespace std;

//number of componenets
//TC : O(n^2) as we are given adjacency matrix , we have to traverse every element
//SC : O(N) for the visited array

void dfs(int i , vector<vector<int>>& isConnected , vector<int>& visited){
        visited[i] = 1;

        for(int j = 0 ; j < isConnected.size() ; j++){
            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(j , isConnected , visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //jumping through indirect connections
        int n = isConnected.size();

        vector<int> visited(n , 0);
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , isConnected , visited);
                count++;
            }
        }

        return count;

    }