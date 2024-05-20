class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int sz = s.size();

        int i = sz - 1, j = 0;
        while(s[i] == ' ') --i;
        while(i >= 0 && s[i] != ' ') --i, ++j;

        return j;
    }
};
