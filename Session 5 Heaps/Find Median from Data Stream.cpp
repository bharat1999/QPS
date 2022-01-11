//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> rightHeap; //Min heap
    priority_queue<int> leftHeap; // Max Heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(leftHeap.size()==0)
        {
            leftHeap.push(num);
        }
        else
        {
            double mid = findMedian();
            if(leftHeap.size() > rightHeap.size()) // we need to push in right
            {
                if(num < mid) // so shift left top to right than push
                    // num in left
                {
                    rightHeap.push(leftHeap.top());
                    leftHeap.pop();
                    leftHeap.push(num);
                }
                else
                {
                    rightHeap.push(num);
                }
            }
            else if(leftHeap.size() < rightHeap.size()) // we need to push in left
            {
                if(num > mid) // first shift right top to left than push
                {
                    leftHeap.push(rightHeap.top());
                    rightHeap.pop();
                    rightHeap.push(num);
                }
                else
                {
                    leftHeap.push(num);
                }
            }
            else // when left and right are equal
            {
                if(num < mid)
                {
                    leftHeap.push(num);
                }
                else
                {
                    rightHeap.push(num);
                }
            }
        }
        
    }
    
    double findMedian() {
        
        int l = leftHeap.size();
        int r = rightHeap.size();
        
        if(l>r)
        {
            return double(leftHeap.top());
        }
        else if(r>l)
        {
            return double(rightHeap.top());
        }
        else
        {
            return (double(rightHeap.top()) + double(leftHeap.top()))/2;
        }
        
    }
};