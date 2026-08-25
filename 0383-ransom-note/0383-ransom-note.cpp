class Solution {
public:
    bool canConstruct(string nums, string nums2) {
        // unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        // for (auto it : nums)
        //     mp[it]++;
        for (auto it : nums2)
            mp2[it]++;
        for (auto i : nums) {
        
            if (mp2.find(i) == mp2.end())
                return false;
            mp2[i]--;
            if(mp2[i] == 0){
                mp2.erase(i);
            }
        }
        return true;
    }
};