class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        long long hrst;
        long long sest;
        long long minst;

        long long hret;
        long long seet;
        long long minet;
        vector<int> v;
        string stname = "";
        string etname = "";
        int cnt = 0;

        for (int i = 0; i < st.size(); i++) {

            if (st[i] == ':') continue;

            stname += st[i];
            etname += et[i];
            cnt++;

            if (cnt >= 2) {
                v.push_back(stoi(stname));
                v.push_back(stoi(etname));

                stname = "";
                etname = "";

                cnt = 0;

            }
        }

        hrst = v[0];
        hret = v[1];

        minst = v[2];
        minet = v[3];

        sest = v[4];
        seet = v[5];

        int ans = 0;

        if ((seet - sest) < 0) {
            seet += 60;
            ans += seet - sest;
            minet--;
        } else
            ans += seet - sest;

        if ((minet - minst) < 0) {
            minet += 60;

            ans += 60 * (minet - minst);

            hret--;
        } else {
            ans += 60 * (minet - minst);
        }

        ans += 60 * 60 * (hret - hrst);

        return ans;
    }
};