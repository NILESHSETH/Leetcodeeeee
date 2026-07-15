class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right =(long long )sqrt(c);
        while(left <= right){
            long long num = left*left + right*right;
            if(num == c) {
              return true;
              break;
            }
            if(num < c){
                left++;
            }
            else if(num > c) right--;
        }
        return false;
    }
};