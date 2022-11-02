class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>(); // using set so that it'd be easy to detect duplicates. If there are duplicates it means that it can never be a happy number.
        while (n != 1 && !set.contains(n)) {
            set.add(n);
            n = getSumOfSquaresOfDigits(n);
        }
        return n == 1;
    }
    
    private int getSumOfSquaresOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int temp = n %10;
            n /= 10;
            sum += temp * temp;
        }
        return sum;
    }
}