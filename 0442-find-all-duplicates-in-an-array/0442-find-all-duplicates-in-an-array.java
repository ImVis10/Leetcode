class Solution {
    /**Element is more important here than the index of the element as we have elements ranging from 1 to n where n is the size of the array, based on the element we can go to the same index if the elemt is present twice and if the element is already negative we add that element to the list**/
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for(int num :  nums) {
            int i = Math.abs(num);
            int index = i - 1;
            if(nums[index] < 0) {
                res.add(i);
            }
            nums[index] = -nums[index];
        }
        return res;
    }
}