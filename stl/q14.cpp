#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include <algorithm>
using namespace std;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string> sorted = strs;

        for(int i = 0 ; i < sorted.size() ; i++){
            sort(sorted[i].begin() , sorted[i].end());
        }

        priority_queue<pair<string , int>> pq;
        for(int i = 0 ; i < sorted.size() ; i++){
            pq.push({sorted[i] , i});
        }

        vector<vector<string>> result;

        while(!pq.empty()){

            auto it = pq.top();
            string st = it.first;
            int idx = it.second;

            vector<int> indices;
            indices.push_back(idx);
            pq.pop();

            while(!pq.empty()){
                auto it = pq.top();
                string str = it.first;

                if(str == st){
                    indices.push_back(it.second);
                    pq.pop();
                }else{
                    break;
                }
            }

            vector<string> answer;

            for(int i = 0 ; i<indices.size() ; i++){
                answer.push_back(strs[indices[i]]);
            }

            result.push_back(answer);
        }

        return result;
    }