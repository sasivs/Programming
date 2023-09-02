#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowLoc, colLoc;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j]==0){
                    rowLoc.insert(i);
                    colLoc.insert(j);
                }
            }
        }
        for(auto& ele: rowLoc){
            for (int i=0; i<matrix[0].size(); i++){
                matrix[ele][i] = 0;
            }
        }
        for(auto& ele: colLoc){
            for (int i=0; i<matrix.size(); i++){
                matrix[i][ele] = 0;
            }
        }
    }
};