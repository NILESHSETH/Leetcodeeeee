class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        queue<pair<string,int>>q;
        q.push({bw, 1});
        set<string>st(wl.begin(), wl.end());
        st.erase(bw);
        while(!q.empty()){
            string words = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(words == ew) return steps;
            //word hat
            // N*nords leangth*@^.longn

            for(int i =0; i<words.size(); i++){
                char original = words[i];
                for(char ch = 'a' ; ch <= 'z' ;ch++){
                    words[i] = ch;
                    //it exists in th set
                    if(st.find(words) != st.end()){
                        st.erase(words);
                        q.push({words,steps +1});
                    }
                }
                words[i] = original;
            }
        }
        return 0;
        
    }
};