class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        // DOING IN JAVA AS IT HAS BETTER PQ SUPPORT
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int val : hand) {
            pq.add(val);
        }
        while (!pq.isEmpty()) {
            int root = pq.peek();
            for (int i = 0; i < groupSize; i++) {
                if (!pq.contains(root + i)) {
                    return false;
                } else {
                    pq.remove(root + i);
                }
            }
        }
        return true;
    }
}