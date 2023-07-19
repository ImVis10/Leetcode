class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // if start time of event2 > end time of event1 --> no conflict
        // else conflict
        
        // the main problem here is how to check the above condition as they are strings
        // It seems in C++, I can compare strings just like ints
        // return event2[0] <= event1[1]; // BUT THIS IS NOT RIGHT AS THERE IS NO GUARANTEE THAT EVENT1 WOULD BE THE ONE THAT STARTS FIRST
        
        // I can do 2 things here
        // 1. sort the events based on start time and do whatever I did above, but waste of time I guess
        if (event2[1] < event1[1]) swap(event1, event2);
        return event2[0] <= event1[1];
        
    }
};