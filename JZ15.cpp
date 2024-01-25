//有一个性质：n&(n−1)，会将n的二进制中最低位由1变成0
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int NumberOf1(int n) {
        // write code here
        int ans = 0;
        while(n)
        {
            n &= n-1;
            ans++;
        }
        return ans;
    }
};