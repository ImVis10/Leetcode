class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        // Greedy
        // strategy - take the box type with maximum units per box
        // so first sort the boxTypes according to the numberOfUnitsPerBox (descending)
        Arrays.sort(boxTypes, (a, b) -> Integer.compare(b[1], a[1]));
        int numUnits = 0;
        for (int[] boxType : boxTypes) {
            if (boxType[0] < truckSize) {
                numUnits += boxType[0] * boxType[1];
                truckSize -= boxType[0]; 
            } else { // numBoxes > truckSize
                numUnits += truckSize * boxType[1]; // take from the remaining space left in truck
                return numUnits;
            }
        }
        return numUnits;
    }
}