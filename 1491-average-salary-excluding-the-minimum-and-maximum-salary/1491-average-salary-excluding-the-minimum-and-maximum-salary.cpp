class Solution {
public:
    double average(vector<int>& salary) {
        double res = 0;
        
        sort(salary.begin(), salary.end());
        
        for (int i = 1; i < salary.size() - 1; i++) {
            res += salary[i];
        }
        
        return res / (salary.size() - 2);
    }
};