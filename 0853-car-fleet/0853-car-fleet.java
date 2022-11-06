class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int len = position.length;
        
        // if only one car is present, return 1 fleet.
        if (len == 1) {
            return 1;
        }
        
        int[][] posAndSpeed = new int[len][2];
        
        for (int i = 0; i < len; i++) {
            posAndSpeed[i][0] = position[i];
            posAndSpeed[i][1] = speed[i];
        }
        
        // sorting as per the position in increasing order.
        Arrays.sort(posAndSpeed, java.util.Comparator.comparingInt(arr -> arr[0]));
        
        // Stack to hold the times (to reach the target)
        Stack<Double> stack = new Stack<>();
        
        // Itertating in reverse order as car at the highest position is taken as the reference.
        for (int i = posAndSpeed.length - 1; i >= 0; i--) {
            double timeToTarget = (double) (target - posAndSpeed[i][0]) / posAndSpeed[i][1];
            if (!stack.isEmpty() && timeToTarget <= stack.peek()) {
                continue;
            } else {
                stack.push(timeToTarget); // push to stack only when timeToTarget is greater than top of the stack. Car with higher speed slows down its speed to match with car of lower speed, once they meet (bumper to bumper)
            }
        }
        
        return stack.size();
    }
}