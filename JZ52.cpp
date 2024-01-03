/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	/*
		双指针算法
		相互走对方的路
	*/
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if(!pHead1 || !pHead2){
			return nullptr;
		}
		ListNode *l1 = pHead1;
		ListNode *l2 = pHead2;
		while(l1 != l2){
			l1 = l1 ? l1->next : pHead2;
			l2 = l2 ? l2->next : pHead1;
		}
		return l1;
	}
};
