#include <iostream>
using namespace std;

// ListNode struct from leetcode: needed to build LinkedLists
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

// Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // both list are empty
        if (!list1 && !list2)
        {
            return nullptr;
        }
        // list1 is empty
        if (!list1) {
            return list2;
        }
        // list2 is empty
        if (!list2)
        {
            return list1;
        }

        ListNode* list;

        // if list1 val is less than list2 val, add it to list
        if (list1->val < list2->val)
        {
            list = list1;
            // move to the next node in list1
            list1 = list1->next;
        }
        // if list2 val is less than list1 val, add it to list
        else 
        {
            list = list2;
            // move to the next node in list2
            list2 = list2->next;
        }

        // Now we have our Head node to be returned
        ListNode* ret = list;

        // while there are still nodes left in list1 and list2
        // continue to add to list to build the merged list
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                list->next = list1;
                list1 = list1->next;
            }

            else
            {
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }

        // if the lists are not the same size
        // or
        // if there are more remaining nodes in either list1 or list2
        // add them to list
        if (list1)
        {
            list->next = list1;
        }
        else
        {
            list->next = list2;
        }

        // return head
        return ret;
    }
};

int main()
{
    ListNode node_c(4);
    ListNode node_b(2, &node_c);
    ListNode node_a(1, &node_b);
    
    ListNode node_f(4);
    ListNode node_e(3, &node_f);
    ListNode node_d(1, &node_e);
    
    Solution sol;
    ListNode* answer = sol.mergeTwoLists(&node_a, &node_d);

    // print out order
    while (answer)
    {
        cout << answer->val << endl;
        answer = answer->next;
    }
	
	return 0;
}
