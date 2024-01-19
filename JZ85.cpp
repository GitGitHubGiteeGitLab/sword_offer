class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        vector<int> ans;
        if(array.empty()){
            return ans;
        }
        int maxsum = array[0];
        //dp(i)
        int dp;
        //tmp<->dp(i - 1)
        int tmp = array[0];
        //滑动窗口
        int left = 0, right = left;
        //记录最长的区间
        int ans_left = 0, ans_right = ans_left;
        for(int i = 1; i < array.size(); i++){
            right++;
            //状态转移
            dp = max(array[i], tmp + array[i]);
            //区间新起点
            if(array[i] > array[i] + tmp){
                left = right;  
            }
            //更新最大值和区间
            if(dp > maxsum || (dp == maxsum && (right - left + 1 ) > (ans_right - ans_left + 1))){
                maxsum = dp;
                ans_left = left;
                ans_right = right;
            }
            //更新tmp的状态
            tmp = dp;
        }
        for(int i = ans_left; i <= ans_right; i++){
            ans.push_back(array[i]);
        }
        return ans;

    }
};