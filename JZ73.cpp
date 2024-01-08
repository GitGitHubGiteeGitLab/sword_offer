class Solution {
public:
    /**
        先整体翻转，再翻转单词
        或是用栈
    */
    void reverse(string& str, int begin, int end){
        for(int i = begin, j = end; i < j; i++, j--){
            swap(str[i], str[j]);
        }
    }
    string ReverseSentence(string str) {
        reverse(str, 0, str.size() - 1);
        int i = 0, j = 0;
        while(i <= str.size()){
            while(isblank(str[i]) || str[i] == '\0'){
                if(i > j){
                    reverse(str, j, i - 1);
                }
                i++;
                j = i;
            }
            i++;
        }
        return str;
    }
};