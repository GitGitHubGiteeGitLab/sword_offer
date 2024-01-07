/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    /*
        插入节点法：
        pass1: insert;
        pass2: copy;
        pass3: split linkedlist
    */
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead){
            return nullptr;
        }
        typedef RandomListNode ListNode;
        ListNode *newhead = nullptr;
        ListNode *tail = nullptr;
        ListNode *cur = pHead;
        while(cur){
            ListNode *node = new ListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = pHead;
        while(cur){
            ListNode *copy = cur->next;
            copy->random = cur->random ? cur->random->next : nullptr;
            cur = copy->next;
        }
        cur = pHead;
        while(cur){
            if(!newhead){
                newhead = tail = cur->next;
            }else{
                tail->next = cur->next;
                tail = tail->next;
            }
            cur->next = tail->next;
            tail->next = nullptr;
            cur = cur->next;
        }
        return newhead;
    }
};