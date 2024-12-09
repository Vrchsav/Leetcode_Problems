class MyCalendarTwo {
public:
    map<int, int> mpp;
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
       
        
        mpp[startTime]++;
        mpp[endTime]--;
        int sum = 0;
        int maxp = -1; 
        auto it = mpp.begin();
        while (it != mpp.end()) {
            sum += it->second;
            maxp = max(maxp, sum);
            it++;
        }
        if (maxp > 2) {
            mpp[startTime]--;
            mpp[endTime]++;
             if (mpp[startTime] == 0) mpp.erase(startTime);
                if (mpp[endTime] == 0) mpp.erase(endTime);
            return false;
        }
        return true;
    }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */