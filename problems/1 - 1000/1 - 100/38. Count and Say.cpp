class Solution {
public:
    std::string countAndSay(int n) {
        if(n == 1) return "1";

        std::queue<char> q0, q1;
        q0.push('1');
        int k = 1;
        
        while(k < n) {
            while(!q0.empty()) {
                char ch = q0.front();
                q0.pop();

                int freq = 1;
                while(q0.size() != 0 && q0.front() == ch) {
                    ++freq;
                    q0.pop();
                }

                std::string s = std::to_string(freq);
                for(char c: s) q1.push(c);
                q1.push(ch);
            }
            while(!q1.empty()) {
                q0.push(q1.front()); q1.pop();
            }
            ++k;
        }

        std::string s = "";
        while(!q0.empty()) {
            s += q0.front(); q0.pop();
        }

        return s;
    }
};
