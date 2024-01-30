class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> vec,int sum) {
        int begin = 0, end = vec.size() - 1; 
        vector<int> ans;
        while(begin < end)
        {
            if(vec[begin] + vec[end] == sum){
                ans.push_back(vec[begin]);
                ans.push_back(vec[end]);
                break;
            }else if( vec[begin] + vec[end] < sum){
                begin++;
            }else{
                end--;
            }
        }
        return ans;
    }
};