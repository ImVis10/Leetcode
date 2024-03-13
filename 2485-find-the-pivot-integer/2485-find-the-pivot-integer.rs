impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let sum = n * (n + 1) / 2;
        let x = (sum as f64).sqrt() as i32;
        if x * x == sum {
            x
        } else {
            -1
        }
    }
}