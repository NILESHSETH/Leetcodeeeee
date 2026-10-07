class Solution {
public:
    bool check(unordered_map<int,int>mp){
        for(auto it : mp){
            if(it.second > 1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n;i++) mp[nums[i]]++;
        bool flag = true;
        int cnt = 0;
        int k = 0;
        while(true){
            if(check(mp)) break;
            int i = k+3;
            cnt++;
            mp.clear();
            for(i ; i  < n;i++){
                mp[nums[i]]++;
            }
            k += 3;
        }
    return cnt;
        
    }
};