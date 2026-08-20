class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>a;
        vector<int>b;
        queue<int>q;
        for(int i = 0; i< n;i++)q.push(nums[i]);
        a.push_back(q.front());
        q.pop();
        b.push_back(q.front());
        q.pop();
        int ai = 0;
        int bi = 0;
        while(!q.empty()){
            if(a[ai] > b[bi]){
                a.push_back(q.front());
                ai++;
                q.pop();
            }
            else{
                b.push_back(q.front());
                bi++;
                q.pop();
            }
        }
        for(int i =0; i < b.size(); i++){
            a.push_back(b[i]);
        }
        return a;
    }
};