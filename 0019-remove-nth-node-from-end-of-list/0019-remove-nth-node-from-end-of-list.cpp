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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp  = head;
        ListNode* prevv=nullptr;
        while(temp)
        {
            int cnt =0 ; 
            ListNode* temp2  = temp;
            while(temp2)
            {
                cnt++;
                temp2 = temp2->next;
            }
            
            if(cnt==n)
            {
                if(prevv == nullptr)
                {
                    ListNode* x = head;
                    head = head->next;
                    delete x;
                    break;
                }
                else{
                prevv->next= temp->next;
                delete temp;
                break;
                }
            }
            prevv = temp;
            temp =temp->next;
        }
        return head;
    }
};