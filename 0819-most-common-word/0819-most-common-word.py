class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        string_with_no_punctuations = ''.join([ch.lower() if ch.isalnum() else ' ' for ch in paragraph])
        print(string_with_no_punctuations)
        words = string_with_no_punctuations.split()
        
        for i in range(len(words)):
            words[i] = words[i].strip()
            
        dic = dict(Counter(words))
        sorted_dic = sorted(dic.items(), key=lambda x:x[1], reverse=True) # sort based on the count of words in descending order
        
        for word, count in sorted_dic:
            if word not in banned:
                return word
            
        