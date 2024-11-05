class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        return quickselect(arr, 0, arr.size() - 1, arr.size() - k);
    }
private:
    int k;
    vector<int> arr;
    
    int partition(vector<int>& arr, int left, int right) {
        int pivotIdx = left + rand() % (right - left + 1);
        int pivotVal = arr[pivotIdx];
        swap(arr[pivotIdx], arr[right]);
        
        int storeIdx = left;
        for (int i = left; i < right; i++) {
            if (arr[i] < pivotVal) {
                swap(arr[i], arr[storeIdx]);
                storeIdx++;
            }
        }
        swap(arr[storeIdx], arr[right]);
        return storeIdx;
    }
    
    int quickselect(vector<int>& arr, int left, int right, int k) {
        if (left == right) return arr[left];
        int pivotIdx = partition(arr, left, right);
        if (k == pivotIdx) return arr[k];
        else if (k < pivotIdx) return quickselect(arr, left, pivotIdx - 1, k);
        else return quickselect(arr, pivotIdx + 1, right, k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */