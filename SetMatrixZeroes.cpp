/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(col){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if(row){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }
};
