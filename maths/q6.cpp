#include<iostream>
#include<vector>
using namespace std;

//checking if a line is straight or not
//approach : matching slope
//TC : O(N)
//SC : O(1)


bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = 0;
        bool infi = false;

        if(coordinates[1][0] - coordinates[0][0] == 0){
            infi = true;
        }else{
            slope = (double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);
        }
        
        
        for(int i = 1 ; i < coordinates.size() - 1 ; i++){
            double numerator = coordinates[i+1][1] - coordinates[i][1];
            double denominator = coordinates[i+1][0] - coordinates[i][0];

            if(infi && denominator != 0){
                return false;
            }

            double curr_slope = numerator / denominator;

            if(!infi && curr_slope != slope){
                return false;
            }
        }

        return true;
    }