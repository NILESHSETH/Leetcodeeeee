// class Solution {
// public:
//     vector<int> lastVisitedCell(vector<vector<char>>& nums) {
//         int n = nums[0].size();
//         int m = nums.size();
//         bool flag = true;
//         vector<vector<int>>vis(m , vector<int>(n,-1));
//         int i= 0;
//         int j = 0;
//         vector<int>v(2);
//         while(true){
//             if(i >= m || vis[i][j] != -1){
//                 flag = false;
//                 v[0] = i;
//                 v[1] = j;
//                 break;
//             }
//             else if (j >= n || vis[i][j] != -1){
//                 flag = false;
//                 v[0] = i;
//                 v[1] = j;
//                 break;
//             }
//             vis[i][j] = 1;
//             if(nums[i][j] == 'L') j--;
//             if(nums[i][j] == 'R') j++;
//             if(nums[i][j] == 'D') i++;
//             if(nums[i][j] == 'U') i--;
            
//         }
//         return v;
        
//     }
// };
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        int i = 0, j = 0;

        while (true) {
            vis[i][j] = 1;

            int ni = i, nj = j;

            if (nums[i][j] == 'L') nj--;
            else if (nums[i][j] == 'R') nj++;
            else if (nums[i][j] == 'D') ni++;
            else if (nums[i][j] == 'U') ni--;

            if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                return {i, j};
            }

            if (vis[ni][nj] != -1) {
                return {i, j};
            }

            i = ni;
            j = nj;
        }
    }
};