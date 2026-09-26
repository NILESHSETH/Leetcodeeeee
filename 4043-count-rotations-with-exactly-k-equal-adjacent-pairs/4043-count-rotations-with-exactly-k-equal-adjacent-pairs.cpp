class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        // if(s[0] ==s[n-1]) cnt++;
        // for(int i = 0; i < n-1;i++){
        //     if(s[i] == s[i+1])cnt++;
        // }
        // return cnt;
        int  l = n;
        while(l--){
            int count = 0;
            for(int i = 0; i < n;i++){
                if(s[i] == s[i+1]) count++;
            }
            if(count == k) cnt++;
            int c = s[0];
            s.erase(0,1);
            s+= c;
            
        }
        return cnt;
    }
};