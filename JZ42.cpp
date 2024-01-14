class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型
     */
    /**
        dp[i]:以nums[i]为结尾的连续子数组最大的和
        关系式: dp[i] = max(dp[i - 1] + nums[i], num[i])
        max_sum = max(max_sum, dp[i])
        dp[i]
        dp[0] = nums[0]

        优化: dp[] -> dp
    */ 
    int FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here

        int dp = array[0];
        int max_sum = array[0];
        for(int i = 1; i < array.size(); i++){
            dp = max(array[i], dp + array[i]);
            max_sum = max(dp, max_sum);
        }
        return max_sum;
    }
};