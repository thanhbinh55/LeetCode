/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* node = head;

        while (node->next != nullptr) {
            ListNode* next = node->next;

            while (next != nullptr && node->val == next->val) {
                ListNode* next_node = next->next;
                next = next_node;
            }

            node->next = next;
            if (next == nullptr) break;
            node = next;
        }

        return head;
    }
};
// @lc code=end

