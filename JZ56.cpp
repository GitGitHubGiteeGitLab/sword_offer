class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector
     */

    //异或运算的性质：a ^ 0 = a  a ^ a = 0 a ^ b ^ c = a ^ c ^ b 
    //整体处理+分组处理(分组的标准: 某1位异或为1，说明这两个数在这一位相异，相异即可形成划分)
    vector<int> FindNumsAppearOnce(vector<int>& nums) {
        // write code here
        vector<int> ans;
        int sum = 0;
        int small = 0;
        int big = 0;
        int sz = nums.size();

        for(int i = 0; i < sz; i++){
            sum ^= nums[i];
        }

        int i = 1;
        while((sum & i) == 0){
            i  <<= 1;
        }

        for(int j = 0; j < sz; j++){
            if(nums[j] & i){
                small ^= nums[j];
            }else{
                big ^= nums[j];
            }
        }

        if(small > big){
            swap(small, big);
        }
        ans.push_back(small);
        ans.push_back(big);
        return ans;
    }
};