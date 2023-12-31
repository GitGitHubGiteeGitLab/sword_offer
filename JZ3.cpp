class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
       //位置重排：把数字放到数组中以该数字为下标的位置上
       for(int i = 0, size = numbers.size(); i < size; i++){
            if(numbers[i] == i){
                continue;
            }else{
                //数字numbers[i]与以该数字为下标位置上的数字重复了
                if(numbers[i] == numbers[numbers[i]]){
                    return numbers[i];
                }else{
                    swap(numbers[i], numbers[numbers[i]]);
                    //这时不知道numbers[i]位置上的数字是否是i
                    //故i--,留到下次判断
                    i--;
                }
            }
       }
       return -1;
    }
};