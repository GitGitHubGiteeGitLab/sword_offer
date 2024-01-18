class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param input int整型vector 
     * @param k int整型 
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // write code here
        vector<int> ans;
        if(input.empty() || k == 0){
            return ans;
        }
        for(int i = 0; i < input.size(); i++){
            if(ans.size() < k){
                ans.push_back(input[i]);
                AdjustUp(ans);
            }else{
                if(ans[0] > input[i]){
                    ans[0] = input[i];
                    AdjustDown(ans);
                }
            }
        }
        return ans;
    }

    void AdjustUp(vector<int>& ans){
        if(ans.size() <= 1){
            return;
        }
        int child = ans.size() - 1;
        int parent = (child - 1) / 2;
        while(child > 0){
            if(ans[child] > ans[parent]){
                swap(ans[child], ans[parent]);
                child = parent;
                parent = (parent - 1) / 2;
            }else{
                break;
            }
        }
        return;
    }

    void AdjustDown(vector<int>& ans){
        int parent = 0;
        int child = 2 * parent + 1;
        while(child < ans.size()){
            //把最大浮上去
            if(child + 1 < ans.size() && ans[child] < ans[child + 1]){
                child++;
            }
            if(ans[child] > ans[parent]){
                swap(ans[parent], ans[child]);
                parent = child;
                child = 2 * child + 1;
            }else{
                break;
            }
        }
        return;
    }
};