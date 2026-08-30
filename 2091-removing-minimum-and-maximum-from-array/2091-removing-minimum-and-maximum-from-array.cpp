class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        map<int,int>mp;
        for(int i = 0; i< n;i++) mp[nums[i]] = i+ 1;
        auto first = mp.begin();
        auto last = prev(mp.end());

        int findex = first->second;
        int lindex = last->second;
        // if(findex <= n/2 && lindex >= n/2){
        //     return findex + n - lindex + 1;
        // }
        // else if(findex < n/2 && lindex <  n/2){
        //     return max(findex, lindex);
        // }
        // else if(findex > n/2 && lindex > n/2){
        //     return n - min(lindex, findex) +1;
        // }
        // else return 1;
        int f = max(findex, lindex);
        int b = n - min(findex, lindex)+1;
        int both = min(findex, lindex) + n- max(findex,lindex) + 1 ;
        return min({f,b,both});


    }
};