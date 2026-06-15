/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* sp=head;
        ListNode* fp=head;
        ListNode* prev=head;
        while(fp!=nullptr && fp->next!=nullptr){
            prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        prev->next =sp->next;
        delete sp;
        return head;

    }
};