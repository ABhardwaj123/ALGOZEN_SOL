#include<vector>
#include<iostream>
#include<queue>
using namespace std;

//flood fill

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        if(image[sr][sc] == color) return image;
        //nothing to change
        //else we are given a particular index to start from

        int starting_color = image[sr][sc];

        queue<pair<int,int>> q; //row , col
        image[sr][sc] = color;
        q.push({sr , sc});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(c-1 >= 0 && image[r][c-1] == starting_color){
                image[r][c-1] = color;
                q.push({r , c-1});
            }

            if(c+1 < cols && image[r][c+1] == starting_color){
                image[r][c+1] = color;
                q.push({r , c+1});
            }

            if(r-1 >= 0 && image[r-1][c] == starting_color){
                image[r-1][c] = color;
                q.push({r-1 , c});
            }

            if(r+1 < rows && image[r+1][c] == starting_color){
                image[r+1][c] = color;
                q.push({r+1 , c});
            }
            
        }

        return image;
        
    }