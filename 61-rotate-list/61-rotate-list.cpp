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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* tail = head;
        int nb = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            nb++;
        }
        k %= nb;
        tail->next = head;
        k = nb - k;
        while(k--){
            tail = head;
            head = head->next;
        }
        tail->next = nullptr;
        return head;
    }
};