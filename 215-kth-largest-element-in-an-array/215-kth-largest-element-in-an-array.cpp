class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto r : nums){
            pq.push(r);
        }
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};