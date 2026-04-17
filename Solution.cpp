class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map <int, int> Ip;
        int as = INT_MAX;
        auto revNum = [&] (int y) {
            int he = 0;
            while (y > 0) {
                he = he * 10+(y % 10);
                y /= 10;
            }
            return he;
        };
        for (int i=0; i<nums.size();i++) {
            if (Ip.find(nums[i]) != Ip.end()) {
                as = min(as, i - Ip[nums[i]]);
            }
            Ip[revNum(nums[i])] = i;
        }
        return as == INT_MAX ? -1 : as;
    }
};
