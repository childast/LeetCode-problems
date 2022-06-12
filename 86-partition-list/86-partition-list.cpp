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
    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead = nullptr;
        ListNode* it = nullptr;
        ListNode* secondHead = nullptr;
        ListNode* it2 = nullptr;
        if(head == nullptr) return head;
        while(head != nullptr){
            if(head->val < x){
                if(newHead == nullptr){
                    newHead = head;
                    head = head -> next;
                    newHead->next = nullptr;
                    it = newHead;
                }else{
                    it->next = head;
                    it = it -> next;
                    head = head -> next;
                    it -> next = nullptr;
                }
            }else{
                if(secondHead == nullptr){
                    secondHead = head;
                    head = head -> next;
                    secondHead->next = nullptr;
                    it2 = secondHead;
                }else{
                    it2 -> next = head;
                    it2 = it2 -> next;
                    head = head -> next;
                    it2 -> next = nullptr;
                }
            }
        }
        if(it != nullptr){
            it->next = secondHead;
            return newHead;
        }
        return secondHead;
    }
};