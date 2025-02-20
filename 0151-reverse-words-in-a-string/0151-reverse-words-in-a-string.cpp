class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string p = "";
        stack<string> stt;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && p != "") {
                stt.push(p);
                p = "";
            } else {
                if (s[i] != ' ')
                    p += s[i];
            }
        }
        if (p != "")
            stt.push(p);

        while (stt.size() != 1) {
            ans += stt.top();
            ans += " ";
            stt.pop();
        }
        ans += stt.top();

        return ans;
    }
};