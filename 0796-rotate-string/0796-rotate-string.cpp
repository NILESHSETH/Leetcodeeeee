// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size() != goal.size()) return false;

//         int n = s.size();
//         int idx = 0; 
//         for(int i = 0; i< n;i++){
//             if(s[0] == goal[i]){
//                 idx = i;
//                 break;
//             }
//         }
//         for(int i = 0; i < n;i++){
//             if(s[i] != goal[(idx+i)%n]) return false;
//         }
//         return true;






























//     }
// };


// // class Solution {
// // public:
// //     bool rotateString(string s, string goal) {

// //         // if(s.size() != goal.size()) return false;
// //         // stack<char>st;
// //         // int n = s.size();
// //         // int ind = -1;
// //         // int i = 0;
// //         // int j = 0;
// //         // while(i < n){
// //         //     if(s[i] == goal[j]){
// //         //         i++;
// //         //         j++;
// //         //     }
// //         //     else {
// //         //         st.push(s[i]);
// //         //         i++;
// //         //     }
// //         // }
// //         // if(j==n) return true;
// //         // string rem = "";
// //         // while(!st.empty()){
// //         //     rem += st.top();
// //         //     st.pop();
// //         // }
// //         // reverse(rem.begin(), rem.end());
// //         // string sub = goal.substr(j+1);
// //         // return sub == rem;
        
// //     }
// // };
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size()!=goal.size())
            return false;

        return (s+s).find(goal)!=string::npos;
    }
};