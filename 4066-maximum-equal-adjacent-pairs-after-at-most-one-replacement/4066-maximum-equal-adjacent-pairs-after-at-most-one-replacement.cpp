class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>, int> mp;  
        int ext = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i+1]) {
                ans++;
                continue;
            }
            auto key = minmax(nums[i], nums[i+1]); 
            mp[key]++;
            ext = max(mp[key], ext);
        }

        return ans + ext;
    }
};
// ===== BUGS IN ORIGINAL CODE =====

// 1. unordered_map<pair<int,int>, int> mp;
//    ERROR: std::pair has no default hash function, so unordered_map
//    cannot use it as a key -- this fails to compile.
//    FIX: use map<pair<int,int>, int> instead (ordered map supports
//    pairs natively via operator<), or provide a custom hash function.

// 2. mp[nums[i], nums[i+1]]++;
//    BUG: inside [], "nums[i], nums[i+1]" is the COMMA OPERATOR, not a
//    pair. It evaluates both and keeps only the last value, so this
//    line actually becomes mp[nums[i+1]] -- a single int, not a pair key.
//    FIX: wrap in braces to actually construct a pair: mp[{nums[i], nums[i+1]}]

// 3. ext = max(mp[nums[i], nums[i+1]], ext);
//    SAME BUG as above, repeated here -- comma operator again, so this
//    wasn't even reading from the key you intended.

// 4. // vector<vector<int>> mp;
//    Leftover dead code from an earlier approach -- harmless but should
//    be removed for cleanliness.

// 5. DESIGN ISSUE (not a compile bug): directionality of pairs.
//    (a, b) and (b, a) were treated as different map keys. If changing
//    all a's to b's should fix BOTH a->b and b->a mismatches, these
//    two should share a count. Use minmax(nums[i], nums[i+1]) to
//    normalize key order if that's the intended behavior.