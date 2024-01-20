class Solution {
public:
    int Sum_Solution(int n) {
        //&& 模拟 if
        //递归 模拟 while
        int ans = n;
        (n > 0) && (ans += Sum_Solution(n - 1));
        return ans;
    }
};