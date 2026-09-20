# Intuition

Since the linked list is sorted, duplicate values always appear consecutively. We can traverse the list and skip nodes with the same value by updating the `next` pointers.

# Approach

1. If `head` is `nullptr`, return `head`.
2. Initialize a pointer `node` to `head`.
3. Traverse the list while `node->next` is not `nullptr`.
4. Let `next` point to `node->next`.
5. Move `next` forward while it has the same value as `node`.
6. Update `node->next` to `next`, effectively skipping duplicate nodes.
7. Move `node` to `next` and continue until the end of the list.

# Complexity

* Time complexity: `O(n)`
* Space complexity: `O(1)`

# Code

```cpp
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
```
# Results

- **Runtime:** 0 ms (beats 100 % of C++ submissions)
- **Memory Usage:** 16.1 MB (beats 67.74 %  of C++ submissions)