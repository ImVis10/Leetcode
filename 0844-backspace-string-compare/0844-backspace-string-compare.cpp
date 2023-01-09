// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> stack1;
//         stack<char> stack2;
        
//         pushToStack(s, stack1);
//         pushToStack(t, stack2);
        
//         return getStringFromStack(stack1) == getStringFromStack(stack2);
//     }

// private:
//     void pushToStack(string s, stack<char> &stack) {
//         for(char ch : s) {
//             if (!stack.empty() && ch == '#') {
//                 stack.pop();
//             } else if (ch != '#') {
//                 stack.push(ch);
//             }
//         }
//     }
    
//     string getStringFromStack(stack<char> &stack) {
//         string str;
//         while (!stack.empty()) {
//             char ch = stack.top();
//             str += ch;
//             stack.pop();
//         }
//         return str;
//     }
// };

// SOLVING FOLLOW-UP USING O(1) EXTRA SPACE
// Got this from the solution section

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1; // iterate throught the string in reverse.
        int skipS = 0, skipT = 0; // if we arrive at a backspace, the next non-backspace character is skipped.
        
        // If a character isn't skipped, it is a part of the final result
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            if ((i >= 0) != (j >= 0)) { // if the result is not of the same length
                return false;
            }
            
            if (i >= 0 && j >= 0 && s[i] != t[j]) { // if the contents of the result are different
                return false;
            }
            
            i--;
            j--;
        }
        return true;
    }
};