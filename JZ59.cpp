class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param num int整型vector 
     * @param size int整型 
     * @return int整型vector
     */

    /**
        为什么用队列表示滑动窗口： 利用队列先进先出的特性
        维护什么的队列：单调递减（值），但队列存储的是下标，队列的最左端是最大的元素
    */ 
    vector<int> maxInWindows(vector<int>& num, int size) {
        vector<int> ans;
        deque<int> dq;
        if(size != 0 && num.size() >= size) {
            for(int i = 0; i < num.size(); i++){
                //头：处理超期元素
                if(!dq.empty() && dq.front() < (i + 1 - size)){
                    dq.pop_front();
                }
                //尾：维护单调队列的单调性
                while(!dq.empty() && num[dq.back()] < num[i]){
                    dq.pop_back();
                }
                //尾：新元素下标i队尾入队
                dq.push_back(i);
                //头：返回以队首元素为数组下标表示的值
                if(i >= size - 1){
                    ans.push_back(num[dq.front()]);
                }
            }
            
        }
        return ans;
        
    }
};