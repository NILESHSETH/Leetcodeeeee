class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        vector<int>vis(n,-1);
        // sort(fruits.begin(), fruits.end());
        // sort(nums.begin(), nums.end());
        for(int i = 0; i <n;i++){
            for(int j = 0; j < n;j++){
                if(fruits[i] <= nums[j] && vis[j] == -1){
                    vis[j] = fruits[i];
                    break;

                }
            }
        }
        for(int i = 0; i < n;i++){
            if(vis[i] == -1) cnt++;
        }
        return cnt;
     
    }
};