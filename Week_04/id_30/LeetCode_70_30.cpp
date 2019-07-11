/*
思路: 典型的做法是DP，问题化解为：
第i阶楼梯分解为第（i-1）阶+1步 和 第（i-2）阶+2步，则：
dp[i] = dp[i-1] + dp[i-2];
只要确定了第0阶和第1阶的步数，其它的步数都可以由0和1递推。
*/

class Solution {
public:
    // 空间复杂度为O(n), 时间复杂度为O(n)
    int climbStairs(int n) {
        if (n <= 1) return n;
        vector<int> steps(n, 0);
        steps[0] = 1;
        steps[1] = 2;
        for (int i = 2; i < n; ++i) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n-1];
    }
};
