class Solution{
public:
    void Insert(int num)
    {
        //先根据value大小进行push, 再根据两个堆的大小进行调整 
        if(maxHeap.empty() || maxHeap.top() >= num)
        {
            maxHeap.push(num);
            if(maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else
        {
            minHeap.push(num);
            //维持maxHeap.size() == minHeap.size() || maxHeap.size() == minHeap.size(), 不能出现minHeap.size() > maxHeap.size()
            if(minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    double GetMedian()
    {
        //if(maxHeap.size() == minHeap.size() + 1)
        if(maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        //( int + int ) / 2.0 --> double
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
private:
   priority_queue<int> maxHeap; 
   priority_queue<int, vector<int>, greater<int>> minHeap; 

};
