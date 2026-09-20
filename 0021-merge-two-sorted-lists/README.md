# Intuition
Hai danh sach da duoc sap xep tang dan, nen ta chi can so sanh phan tu dau cua moi danh sach va noi node nho hon vao danh sach ket qua.

# Approach
1. Neu mot trong hai danh sach rong, tra ve danh sach con lai.
2. Chon node dau tien nho hon de lam `tail`.
3. Dung hai con tro `ptr1` va `ptr2` de duyet hai danh sach.
4. Moi lan so sanh `ptr1->val` va `ptr2->val`, noi node nho hon vao sau `tail`.
5. Khi mot danh sach het node, noi phan con lai cua danh sach kia vao ket qua.

# Complexity
- Time complexity: `O(m + n)`
- Space complexity: `O(1)`

# Code
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr ) return list2;
        if (list2 == nullptr ) return list1;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        ListNode* tail = nullptr;
        if (ptr1->val <= ptr2->val){
            tail= ptr1;
            ptr1 = ptr1->next;
        }else{
            tail = ptr2;
            ptr2 = ptr2->next;
        }
        ListNode* dummy = new ListNode();
        dummy->next = tail;
        while (ptr1 != nullptr && ptr2!= nullptr){
            if(ptr1->val <= ptr2->val){
                tail->next = ptr1;
                ptr1 = ptr1->next;
            }else{
                tail->next = ptr2;
                ptr2 = ptr2->next;
            }
            tail = tail->next;
        }

        if (ptr1 != nullptr) tail->next = ptr1;
        else tail->next = ptr2;
        return dummy->next;
    }
};
```

# Results
- **Test cases:** 208/208 passed
- **Runtime:** 0 ms (beats 100% of C++ submissions)
- **Memory Usage:** 19.5 MB (beats 27.13% of C++ submissions)
