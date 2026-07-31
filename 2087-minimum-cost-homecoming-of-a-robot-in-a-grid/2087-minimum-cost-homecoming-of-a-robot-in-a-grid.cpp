class Solution {
public:
    int minCost(vector<int>& startpos, vector<int>& homepos,vector<int>& rowcost, vector<int>& colcost) {
        int r1 = startpos[0];
        int c1 = startpos[1];
        int r2 = homepos[0];
        int c2 = homepos[1];
        int maxcost = 0;
        // move in row
        if(r2 >= r1){
            for(int i = r1+1; i <=  r2; i++) maxcost += rowcost[i];
        }
        else for(int i = r1-1 ;i >= r2;i-- ) maxcost += rowcost[i];


        if(c2 >= c1){
            for(int i = c1+1; i<=  c2; i++) maxcost += colcost[i];
        }
        else for(int i = c1-1 ;i >= c2;i-- ) maxcost += colcost[i];
        


        // if (sr <= hr)
        
        //     for (int i = sr; i < hr; i++)
        //         mincost += rowcost[i];
        // else if (sr >= hr)
        //     for (int i = sc; i > hc; i--)
        //         mincost += rowcost[i-1];

        // if (sc <= hc)
        //     for (int i = sc +1; i <= hc; i++)
        //         mincost += colcost[i];
        // else if (sc >= hc)
        //     for (int i = sc-1; i >= hc; i--)
        //         mincost += colcost[i];
        return maxcost;
    }
};