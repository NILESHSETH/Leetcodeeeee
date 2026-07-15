class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(auto it : nums)st.insert(it);
        nums.clear();
        for(auto it : st) nums.push_back(it);
        return st.size();

        
    }
};