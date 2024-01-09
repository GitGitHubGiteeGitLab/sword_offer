class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
     

    /**
        辅助栈：
            如果下一个弹出的数字刚好是栈顶元素，那么直接pop
            如果下一个弹出的数字不是栈顶元素，则把压栈序列中还没有入栈的数字压入辅助栈
        直到把下一个需要弹出的数字压入栈顶为止
            如果所有数字都压入栈中仍然还没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列
    */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        bool ans = true;
        stack<int> s;
        int pushi = 0;
        int popi = 0;
        while(pushi < pushV.size() || popi < popV.size()){
            if(s.empty()){
                //s为空时入栈
                s.push(pushV[pushi]);
                pushi++;
            }else{
                
                if(s.top() == popV[popi]){
                    //判断是否是出栈数字
                    s.pop();
                    popi++;
                }else{
                    //压入序列中的数字均已入栈，仍未找到出栈数字，false
                    if(pushi == pushV.size()){
                        ans = false;
                        break;
                    }
                    s.push(pushV[pushi]);
                    pushi++;
                }
            }

        }
        return ans;
    }
    
};