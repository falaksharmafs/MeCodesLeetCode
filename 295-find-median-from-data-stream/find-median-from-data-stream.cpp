class MedianFinder {
public:
    priority_queue<int> lmheap;
    priority_queue<int , vector<int>, greater<int>> rmheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lmheap.empty()||num < lmheap.top()){
            lmheap.push(num);
        }else{
            rmheap.push(num);
        }

        if(abs((int)lmheap.size() -(int) rmheap.size()) >1){
            rmheap.push(lmheap.top());
            lmheap.pop();
        }else if( lmheap.size() < rmheap.size()){
            lmheap.push(rmheap.top());
            rmheap.pop();
        }


        
    }
    
    double findMedian() {
        if(lmheap.size()==rmheap.size()){
            double mean = (lmheap.top() + rmheap.top())/2.0;

            return mean;
        }

        return lmheap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */