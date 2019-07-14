
/*
思路：将胃口g数组排序，尺寸s排序，依次判断，如果尺寸满足胃口，将尺寸分配给对于的小孩，否则看看下个饼干尺寸是否满足小孩。
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gi = 0, si = 0;
        int ans = 0;
        // 时间复杂度O(n*logn)
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        // 时间复杂度O(n)
        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                ans++;
                gi++;
                si++;
            } else {
                si++;
            }            
        }
        return ans;
    }
};
