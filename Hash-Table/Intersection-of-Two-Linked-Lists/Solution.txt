/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head) {

        int len = 0;

        while(head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA== NULL || headB==NULL){
            return NULL;
        }
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        int diff = abs(lenA-lenB);
        if(lenA>=lenB){
            while(diff--){
                headA=headA->next;
            }
        }else{
            while(diff--){
                headB = headB->next;
            }
        }
        while(headA && headB){
            if(headA==headB)
              return headA;
            headA =headA->next;
            headB = headB->next;

        }

        return NULL;
    }
};