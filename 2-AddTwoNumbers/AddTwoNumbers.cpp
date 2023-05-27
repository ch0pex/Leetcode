#include <iostream>
#include <vector> 

struct ListNode {
    int val; 
    ListNode *next; 
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr ) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};


/* First Solution:
    - Runtime 45ms 
    - Memory: 71.4MB 
    - Complexity: O(max(n, m))
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *sol = new ListNode(); 
        ListNode *sol_ptr = sol; 
        int tmp_l1, tmp_l2, tmp_sol; 
        do
        {   tmp_sol = 0; 
            tmp_l1 = l1 ? l1->val : 0; 
            tmp_l2 = l2 ? l2->val : 0; 
            tmp_sol= sol_ptr->val + tmp_l1 + tmp_l2; 
            sol_ptr->val = tmp_sol % 10; 

            
            if (l1) l1 = l1->next; 
            if(l2) l2 = l2->next; 

            
            if (tmp_sol > 9) sol_ptr->next = new ListNode(1);
            else if (l1 || l2) sol_ptr->next = new ListNode();

            sol_ptr = sol_ptr->next; 

        } while(l1|| l2); 
        return sol; 
    }
};
