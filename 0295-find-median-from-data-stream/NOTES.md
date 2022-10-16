​# Start Writing Here
Algorithm: findMedianOfEachSubArray
Data: Array A
Result: Array of median of each sub array b.
maxHeap maxHeapForSmallerElements, minHeap minHeapForLargerElements
For each element ele in A Do
    i <- index of ele
    insertElementIntoAppropriateHeap(ele, maxHeapForSmallerElements, minHeapForLargerElements) // insert the element as it arrives in the array i.e. in each sub-array.
    balanceHeapsAccordingToTheirSize(maxHeapForSmallerElements, minHeapForLargerElements) // to keep the median at the top of the heap.
    // top of maxHeapForSmallerElements is the median if the sub-array is even sized.
    // top of minHeapForLargerElements is the median if the sub-array is odd sized.
    b[i] <- getTopOfTheHeap(maxHeapForSmallerElements, minHeapForLargerElements) 
Endfor
Return b

# Start Writing Here
Algorithm: insertNumberIntoAppropriateHeap
Data: Element ele, maxHeap maxHeapForSmallerElements, minHeap minHeapForLargerElements
Result: Element ele must be inserted into either maxHeap heapForSmallerElements or minHeap minHeapForLargerElements
If maxHeapForSmallerElements.size()  == 0 || ele < heapForSmallerElements.get_top() // get_top similar to extract_min in the slides, only difference is element is not removed from the heap i.e. top is returned but not removed.
    maxHeapForSmallerElements.insert(ele) // as smaller numbers should go into maxHeapForSmallerElements.
Endif
Else
    minHeapForLargerElements.insert(ele) // as larger numbers should go into minHeapForLargerElements.
Endelse

# Start Writing Here
Algorithm: balanceHeapsAccordingToTheirSize
Data: maxHeap maxHeapForSmallerElements, minHeap minHeapForLargerElements
Result: Balanced heaps according to their size. // Difference between size of the heaps should only be a maximum of 1.
If maxHeapForSmallerElements.size() > minHeapForLargerElements.size() + 1
    elementToTransferToMinHeapForLargerElements = maxHeapForSmallerElements.get_top()
    minHeapForLargerElements.insert(elementToTransferToMinHeapForLargerElements) // as larger numbers should go into minHeapForLargerElements.
    maxHeapForSmallerElements.extract_max() // as this is a max heap.
Endif
ElseIf minHeapForLargerElements.size() > heapForSmallerElements.size() + 1
    elementToTransferToMaxHeapForSmallerElements = minHeapForLargerElements.get_top()
    maxHeapForSmallerElements.insert(elementToTransferToMaxHeapForSmallerElements) // as smaller numbers should go into maxHeapForSmallerElements.
    minHeapForLargerElements.extract_min() // as this is a min heap.
Endelse

# Start Writing Here
Algorithm: getTopOfTheHeap
Data: maxHeap maxHeapForSmallerElements, minHeap minHeapForLargerElements
Result: median of each sub-array i.e. top of either of the heaps depending upon the case.
If maxHeapForSmallerElements.size() == minHeapForLargerElements.size() // sub-array is even sized.
    medianOfTheSubArray <- maxHeapForSmallerElements.get_top() // so top of maxHeapForSmallerElements would be the median.
Endif
Else // sub-array is odd sized.
    medianOfTheSubArray <- minHeapForLargerElements.get_top() // so top of minHeapForLargerElements would be the median
Endelse
Return medianOfTheSubArray
