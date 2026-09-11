#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int available[10] = {0};
        for (int d : digits) {
            available[d]++;
        }
        
        int ans = 0;
        
        for (int num = 100; num < 1000; num += 2) {
            int h = num / 100;         
            int t = (num / 10) % 10;    
            int u = num % 10;          
            
            int required[10] = {0};
            required[h]++;
            required[t]++;
            required[u]++;
            
            if (available[h] >= required[h] && 
                available[t] >= required[t] && 
                available[u] >= required[u]) {
                ans++;
            }
        }
        
        return ans;
    }
};
