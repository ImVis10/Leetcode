class MedianFinder {
    // As far as I remember Priority queue implements heap data structure (min heap) underneath.
    PriorityQueue<Integer> maxHeapForSmallerElements = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> minHeapForLargerElements = new PriorityQueue<>();

    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        maxHeapForSmallerElements.offer(num);
        minHeapForLargerElements.offer(maxHeapForSmallerElements.poll());
        // To balance the heaps based on their sizes
        if (minHeapForLargerElements.size() > maxHeapForSmallerElements.size()) {
            maxHeapForSmallerElements.offer(minHeapForLargerElements.poll());
        }
        // if (maxHeapForSmallerElements.size() == 0 || num < minHeapForLargerElements.peek()) {
        //     maxHeapForSmallerElements.add(num);
        // } else {
        //     minHeapForLargerElements.add(num);
        // }
    }
    
    public double findMedian() {
        if (maxHeapForSmallerElements.size() == minHeapForLargerElements.size()) {
            return (maxHeapForSmallerElements.peek() + minHeapForLargerElements.peek()) / 2.0d;
        } 
        return maxHeapForSmallerElements.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */