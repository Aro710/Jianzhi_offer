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
    // 循环法
    ListNode* Merge_(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode* newHead ,*p1=pHead1 ,*p2= pHead2;
        
        if((p1->val<p2->val)) {
            newHead=p1;
            p1=p1->next;
        }
        else {
            newHead=p2;
            p2=p2->next;
        }
        ListNode* p = newHead;
        
        while(p1!=NULL&&p2!=NULL){
            if(p1->val<p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2=p2->next;
            }
            p = p->next;
        }
        
        if(p1==NULL) p->next = p2;
        else p->next = p1;
        return newHead;
    }
    
    //递归法
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        
        ListNode* p ;

        if(pHead1->val<pHead2->val){
            p = pHead1;
            p->next = Merge(pHead1->next,pHead2);
            
        }
        else{
            p = pHead2;
            p->next = Merge(pHead1,pHead2->next);
        }
        return p;
        
    }
};
