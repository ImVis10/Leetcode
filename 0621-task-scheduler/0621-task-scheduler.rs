use std::collections::HashMap;

impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        let mut freq = HashMap::new();
        for &task in &tasks {
            *freq.entry(task).or_insert(0) += 1;
        }
        let mut counts:Vec<_> = freq.values().cloned().collect();
        counts.sort_unstable();
        
        let &max_freq = counts.last().unwrap_or(&0);
        
        let mut idle_time = n * (max_freq - 1);
        
        for &count in counts.iter().rev().skip(1) {
            idle_time -= std::cmp::min(count, max_freq - 1);
        }
        
        idle_time = std::cmp::max(0, idle_time);
        
        (tasks.len() as i32) + idle_time
    }
}