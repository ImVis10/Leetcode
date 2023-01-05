class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // int n = temperatures.size();
        // vector<int> res(n, 0);
        // for(int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if(temperatures[i] < temperatures[j]) {
        //             res[i] = j - i;
        //             break;
        //         }
        //     }
        // }
        // return res;
        // Getting TLE with bruteforce. So need a efficient way to solve the problem wrt time. This problem is similar to next higher element which can be solved using monotonic stack.
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> monotonicStack;
        for (int currDay = 0; currDay < n; currDay++) {
            while (!monotonicStack.empty() && temperatures[currDay] > temperatures[monotonicStack.top()]) {
                int prevDay = monotonicStack.top(); 
                monotonicStack.pop();// pop when the current temperature is greater than the temperature on the top of the stack
                res[prevDay] = currDay - prevDay;
            }
            monotonicStack.push(currDay); // push each day to stack
        }
        return res;
    }
};