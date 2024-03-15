impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let (mut prodLeft, mut prodRight) = (1, 1);
        let mut res = vec![1; n];
        
        for i in 1..n {
            prodLeft *= nums[i - 1];
            res[i] = prodLeft;
        }
        
        for i in (0..n - 1).rev() {
            prodRight *= nums[i + 1];;
            res[i] *= prodRight;
        }
        res
    }
}