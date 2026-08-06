class Solution {
public:
    int smallestNumber(long long n, int t) {
        while(true){
            long long num = n;
            int p = 1;
            while( num> 0){
                p = p*(num%10);
                num = num/10;
            }
            if(p%t==0){
                return n;
                break;
               
            }
            n++;
       
        }
        return -1;
      
    }
};