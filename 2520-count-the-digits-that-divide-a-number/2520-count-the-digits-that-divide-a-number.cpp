class Solution {
public:
    int countDigits(int num) {
        vector<int>n;
        int k = num;
        while(k > 0){
            n.push_back(k%10);
            k = k/10;
        }
        int cnt = 0;
        for(int i = 0; i < n.size(); i++){
            if(num%n[i]==0) cnt++;
        }
        return cnt;
    }
};