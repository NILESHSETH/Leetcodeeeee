class Solution {
public:
int findmaxindex(vector<vector<int>>&nums,int n , int m ,int col){
    int maxvalue = -1;
    int index = -1;
    for(int i = 0;i < n;i++){
        if(nums[i][col] > maxvalue){
            maxvalue = nums[i][col];
            index = i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int lo = 0;
        int hi = m -1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            int maxrowindex= findmaxindex(nums,n,m,mid);
            int left = mid -1 >= 0? nums[maxrowindex][mid-1]:-1;
            int right = mid +1 < m ? nums[maxrowindex][mid+1] : -1;
            if(nums[maxrowindex][mid] > left && nums[maxrowindex][mid] > right){
                return {maxrowindex,mid};
            }
            else if(nums[maxrowindex][mid] < left) hi = mid -1;
            else lo = mid +1;
        }
        return {-1,-1};
    }
};