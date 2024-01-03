/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
     //双指针
     //要考虑到一个为空一个不为空
     //注意其与合并两个有序数组的不同:
        //while + 2 * if(链表是用指针保持元素的先后关系，只需要修改指针的指向即可)
        //while * 3(数组用空间的连续性保持元素的先后关系)
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        // if(!pHead1)return pHead2;
        // if(!pHead2)return pHead1;
        ListNode *newhead = nullptr, *tail = nullptr;
        ListNode *list1 = pHead1;
        ListNode *list2 = pHead2;
        while(list1 && list2){
            if(list1->val < list2->val){
                if(!newhead){
                    newhead = tail = list1;
                    list1 = list1->next;
                }else{
                    tail->next = list1;
                    tail = list1;
                    list1 = list1->next;
                }
            }else{
                if(!newhead){
                    newhead = tail = list2;
                    list2 = list2->next;
                }else{
                    tail->next = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }
        }
        if(list1){
            if(!newhead){
                newhead = list1;
            }else{
                tail->next = list1;
            }
        }
        if(list2){
            if(!newhead){
                newhead = list2;
            }else{
                tail->next = list2;
            }
        }
        return newhead;
    }
};