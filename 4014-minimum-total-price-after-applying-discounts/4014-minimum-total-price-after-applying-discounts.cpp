class Solution {
public:
    double minPrice(vector<int>& v, vector<int>& d) {
        sort(v.begin(), v.end(), greater<int>());
        sort(d.begin(), d.end(), greater<int>());
        int n = v.size();
        int m = d.size();
        int i = 0;
        int j = 0;
        vector<double>ans;
        for(auto i : v)ans.push_back(i);
        while(i < n && j < m){
            ans[i] = (float)1.0*v[i]*(100-d[j])/100.0;
            i++;
            j++;
        }
        double sum = 0;
        for(auto it : ans) sum += it;
        return sum;
       
    }
};