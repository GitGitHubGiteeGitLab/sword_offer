class Solution {
public:
    /**
        先找到右子树的根节点，看右子树根节点与树的根节点之间有无比根节点小的节点,若有返回false
    */

    bool _verify(vector<int>& sequence, int begin, int end){
        if(begin >= end){
            return true;
        }
        int pos = 0;
        while(sequence[pos] < sequence[end]){
            pos++;
        }
        for(int i = pos + 1; i < end; i++){
            if(sequence[i] < sequence[end]){
                return false;
            }
        }
        return _verify(sequence, begin, pos - 1) && _verify(sequence, pos, end - 1);//end - 1去掉根节点
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()){
            return false;
        }
        
        return _verify(sequence, 0, sequence.size() - 1);
    }
};