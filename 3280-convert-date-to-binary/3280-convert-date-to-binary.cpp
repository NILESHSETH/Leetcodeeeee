class Solution {
public:
    string convertDateToBinary(string date) {
        string s;
        string ans;
        for (int i = 0; i < date.size(); i++) {
            string k;
            while (i < date.size() && date[i] != '-') {
                k += date[i];
                i++;
            }
            string s = bitset<32>(stoi(k)).to_string();
            s.erase(0, s.find('1'));
            ans += s;
            if(i < date.size())ans+= '-';

            
        }
        return ans;
    }
};