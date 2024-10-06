class MedianFinder {
public:
    vector<int> list;  // Stores the added numbers
    
    MedianFinder() {}

    // Add a number to the list
    void addNum(int num) {
        list.push_back(num);
    }

    // Function to return the signum of two integers (for heap size comparison)
    int signum(int a, int b) {
        if (a == b) {
            return 0;
        } else if (a > b) {
            return 1;
        } else {
            return -1;
        }
    }

    // Function to adjust heaps and calculate the median dynamically
    void check_med(int ele, double &median, priority_queue<int>& maxheap, priority_queue<int, vector<int>, greater<int>>& minheap) {
        // Adjust heaps based on their size difference
        switch (signum(maxheap.size(), minheap.size())) {
            case 0:  // If both heaps are of equal size
                if (ele < median) {
                    maxheap.push(ele);
                    median = maxheap.top();  // Update median to top of maxheap
                } else {
                    minheap.push(ele);
                    median = minheap.top();  // Update median to top of minheap
                }
                break;

            case 1:  // If maxheap has more elements than minheap
                if (ele < median) {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(ele);
                } else {
                    minheap.push(ele);
                }
                median = (minheap.top() + maxheap.top()) / 2.0;  // Average of tops
                break;

            case -1:  // If minheap has more elements than maxheap
                if (ele < median) {
                    maxheap.push(ele);
                } else {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(ele);
                }
                median = (minheap.top() + maxheap.top()) / 2.0;  // Average of tops
                break;
        }
    }

    // Find and return the median
    double findMedian() {
        if (list.empty()) {
            return 0;  // Return 0 if no elements have been added
        }

        double median = list[0];  // Initialize median with the first element
        priority_queue<int> maxheap;  // Maxheap for the lower half of elements
        priority_queue<int, vector<int>, greater<int>> minheap;  // Minheap for the upper half
        
        for (int i = 0; i < list.size(); i++) {
            check_med(list[i], median, maxheap, minheap);  // Dynamically calculate the median as elements are added
        }
        return median;  // Return the final median after all elements are processed
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
