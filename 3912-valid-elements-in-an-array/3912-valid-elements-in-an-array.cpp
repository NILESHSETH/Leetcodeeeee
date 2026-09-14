class Solution {
public:
    // t.c: O(2n)...
    // s.c: O(2n)...
    vector<int> findValidElements(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n);
        vector<int> post(n);
        int prefix = 0, postfix = 0;

        for(int i=0;i<n;i++){
            prefix = max(prefix,a[i]);
            postfix = max(postfix,a[n-i-1]);
            pre[i] = prefix;
            post[n-i-1] = postfix;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i == 0 || i == n-1){
                ans.push_back(a[i]);
                continue;
            }

            if(pre[i-1] < a[i]) ans.push_back(a[i]);
            else if(post[i+1] < a[i]) ans.push_back(a[i]);
        }

        return ans;
    }
};