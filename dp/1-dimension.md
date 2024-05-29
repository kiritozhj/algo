```cpp
int knapsackDPComp(vector<int> &wgt, vector<int> &val, int cap)
{
    int n = wgt.size();
    // 初始化 dp 表
    vector<int> dp(cap + 1, 0);
    // 状态转移
    for (int i = 1; i <= n; i++)
    {
        // 倒序遍历
        for (int c = cap; c >= 1; c--)
        {
            if (wgt[i - 1] <= c)
            {
                // 不选和选物品 i 这两种方案的较大值
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}
```
滚动数组，每次都有上一行数组得到，但是由于每个数都由左上方的数和正上方的数中获得，所以内层循环需要倒序以防止覆盖