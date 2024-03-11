use std::collections::HashMap;

impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let mut res = String::new();
        let mut mp: HashMap<char, i32> = HashMap::new();
        
        for ch in s.chars() {
            *mp.entry(ch).or_insert(0) += 1;
        }
        
        for ch in order.chars () {
            if let Some(cnt) = mp.get_mut(&ch) {
                while *cnt > 0 {
                    res.push(ch);
                    *cnt -= 1;
                }
             }
        }
        
        for (ch, cnt) in mp {
            for _ in 0..cnt {
                res.push(ch);
            }
        }
        res
    }
}