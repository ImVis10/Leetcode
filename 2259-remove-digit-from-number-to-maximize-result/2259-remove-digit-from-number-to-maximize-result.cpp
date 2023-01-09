class Solution {
public:
    string removeDigit(string number, char digit) { // Took from discuss section. My approach would take too much time
        // Just remove that occurrence of the digit, if it is followed by a higher number
        // if not, remove the right most occurrence of the digit
        
        for (int i = 0; i < number.length() - 1; i++) {
            if (number[i] == digit && number[i] < number[i + 1]) {
                return number.substr(0, i) + number.substr(i + 1);
            }        
        }
        
        int lastOccurrenceOfDigitAt = number.rfind(digit);
        return number.substr(0, lastOccurrenceOfDigitAt) + number.substr(lastOccurrenceOfDigitAt + 1);
     }
};