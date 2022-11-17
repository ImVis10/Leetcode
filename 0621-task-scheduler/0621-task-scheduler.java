class Solution {
    public int leastInterval(char[] tasks, int n) {
        // Greedy.. pick up the task with most frequency first and schedule them accordingly (as per cooling down period)
        int[] freqs = new int[26];
        
        for (int task : tasks) { // tasks[i] is an upper case english alphabet always.
            freqs[task - 'A']++;
        }
        
        Arrays.sort(freqs);
        
        int maxFreq = freqs[25]; // max frequency is at the last as we have sorted freqs array in increasing order
        int idleTime = n * (maxFreq - 1); // putting cooling down period between two instances of same task
        
        for (int i = freqs.length - 2; i >= 0; i--) { // as we're already done scheduling last task i.e. task with most frequency, so starting from freqs.length - 2
            idleTime -= Math.min(freqs[i], maxFreq - 1); // taking the min between two because what if there are two/many tasks with the same maxFreq. They need to be scheduled just like first maxFreq task is scheduled.
        }
        
        idleTime = Math.max(idleTime, 0);
        
        int leastTimeToCompleteTasks = tasks.length + idleTime;
        
        return leastTimeToCompleteTasks; 
    }
}