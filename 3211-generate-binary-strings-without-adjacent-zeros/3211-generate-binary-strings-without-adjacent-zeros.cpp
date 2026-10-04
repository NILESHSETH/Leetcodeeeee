class Solution {
public:
    void helper(int i, vector<string>& v, int k, string temp) {
        if(i == k){
            v.push_back(temp); 
            return;
        }

        helper(i + 1, v, k, temp + '0'); 
        helper(i + 1, v, k, temp + '1');
    }

    vector<string> validStrings(int n) {
        vector<string>v;
        string temp = "";

        helper(0, v, n, temp);

        vector<string>ans;

        for(auto i : v){
            bool flag = true;

            for(int j = 1; j < n; j++){ 
                if(i[j] == '0' && i[j-1] == '0'){
                    flag = false;
                    break;
                }
            }

            if(flag) ans.push_back(i); 
        }

        return ans;
    }
};