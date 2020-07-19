/* I uploaded this after the semester got over.
I had solved this problem on LeetCode and I had realised that the code that was 
taught in class was crappy code.

So, I hope you get the idea by reading this code. It's like sewing and attaching both the lists.
This approach comes handy when you solve the question K sorted Lists (Hard LeetCode)
*/



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *start = new ListNode(-1);
        // Use this as a starting point
        ListNode* curr; // for reference
        curr = start; // Traverse using this over the two lists and attach them together based on values.
        
        // We will add onto start 
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                curr->next = l1; // Attach curr-> next to l1.
                curr = curr->next; // Move one step forward to new position.
                l1 = l1->next; // Move forward.
            }
            else
            {
                curr->next = l2; // Attach curr->next to l2
                curr = curr->next; // Move one step forward.
                l2 = l2->next; // Move one step forward
            }
        }
        if(l1)
        {
            curr->next = l1; // If l2 ended already, curr is stuck at end of l2. Attach l1.
        }
        else if(l2)
        {
            curr->next = l2;
        }
        return start->next; // We had used start to save that initial position.
        
    }
};
