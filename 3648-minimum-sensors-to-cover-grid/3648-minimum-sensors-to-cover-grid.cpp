class Solution {
public:
    int minSensors(int n, int m, int k) {
        return (ceil((n*1.0)/(2*k+1))* ceil((m*1.0)/(2*k+1)));
    }
};