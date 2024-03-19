class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for (int task : tasks) {
            freq[task - 'A']++;
        }
        
        sort(freq.begin(), freq.end());
        
        int maxFreq = freq[25];
        
        int idleTime = n * (maxFreq - 1); // schedule the tasks with most freq first
        
        for (int i = freq.size() - 2; i >= 0; i--) {
            idleTime -= min(freq[i], maxFreq - 1); // min(freq[i], maxFreq - 1) as there can be multiple tasks can have same maxFreq
        }
        
        idleTime = max(idleTime, 0); // as idleTime can go to negative but it shouldn't be negative
        
        int leastTimeToCompleteTasks = tasks.size() + idleTime;
        
        return leastTimeToCompleteTasks;
    }
};