use std::collections::HashMap;

impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let (n, mut sum, mut res) = (nums.len(), 0, 0);
        let mut mp: HashMap<i32, i32> = HashMap::new();
        mp.insert(0, -1);
        for i in 0..n {
            if nums[i] == 1 {
                sum += 1;
            } else {
                sum -= 1;
            }
            if let Some(&idx) = mp.get(&sum) {
                res = res.max(i as i32 - idx);
            } else {
                mp.insert(sum, i as i32);
            }
        }
        res
    }
}