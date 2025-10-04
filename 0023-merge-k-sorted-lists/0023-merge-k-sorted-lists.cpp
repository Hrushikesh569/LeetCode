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
 # define p pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<p,vector<p>,greater<p>>minheap;
        for(auto i : lists)
        {
            if(i)
            {
                minheap.push({i->val,i});
            }
        }
        ListNode Dummy;
        ListNode* start = &Dummy;
        while(!minheap.empty())
        {
            auto [val,node] = minheap.top();
            minheap.pop();
            start->next = node;
            start = start->next;
            if(node->next)
            {
                minheap.push({node->next->val,node->next});
            }
        }
        return Dummy.next;
        
    }
};