class MyCalendar {
private:
    bool isOverlap(int start1,int end1,int start2,int end2){
        return max(start1,start2)<min(end1,end2);
    }

    pair<int,int>getOverlap(int start1,int end1,int start2,int end2){
        return {max(start1,start2),min(end1,end2)};
    }
public:
    vector<pair<int,int>>singleBookings;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(pair<int,int>bookings: singleBookings){
            if(isOverlap(bookings.first,bookings.second,startTime,endTime)){
                return false;
            }
        }

        singleBookings.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */