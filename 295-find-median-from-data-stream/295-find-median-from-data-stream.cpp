class MedianFinder {
public:
    priority_queue<int> mn, mx;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.size() > mn.size()){
            mn.push(num);
        }else{
            mx.push(-num);
        }
        if(!mx.empty() && !mn.empty()){
            if(mn.top() > -mx.top()){
                mn.push(-mx.top());
                mx.pop();
                mx.push(-mn.top());
                mn.pop();
            }
        }
    }
    
    double findMedian() {
        if(mx.size() > mn.size()){
            return (double)(-mx.top());
        }else{
            return (double)(mn.top()-mx.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */