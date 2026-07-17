class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        
        int n = nums.size();
        int m = nums[0].size();
        vector<int>row;
        vector<int>col;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(nums[i][j] == 0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int i = 0; i < row.size(); i++){
            for(int  j = 0; j < m;j++){
                nums[row[i]][j] = 0;
            }
        }
        for(int j = 0; j < col.size(); j++){
            for(int i = 0; i < n;i++){
                nums[i][col[j]] = 0;
            }
        }

    }
};