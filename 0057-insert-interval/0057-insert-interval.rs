impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut intervals = intervals.clone();
        intervals.push(new_interval);
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut res: Vec<Vec<i32>> = Vec::new();
        for interval in intervals.iter() {
            if res.is_empty() || res.last().unwrap()[1] < interval[0] {
                res.push(interval.clone());
            } else {
                let last = res.last_mut().unwrap();
                last[1] = std::cmp::max(last[1], interval[1])
            }
        }
        res
    }
}