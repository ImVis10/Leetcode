class Solution {
public:
    int minLength(string s) {
        // editorial solution
        int write = 0;
        string temp = s;
        for (int read = 0; read < s.length(); read++) {
            temp[write] = temp[read];
            if (write > 0 and (temp[write - 1] == 'A' or temp[write - 1] == 'C') and temp[write] == temp[write - 1] + 1) {
                write--;
            } else {
                write++;
            }
        }
        return write;
    }
};