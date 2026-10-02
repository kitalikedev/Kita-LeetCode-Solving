class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < s.length(); i++) {
            expand(i, i);     // Đối xứng lẻ (tâm 1 ký tự: "aba")
            expand(i, i + 1); // Đối xứng chẵn (tâm 2 ký tự: "abba")
        }

        return s.substr(start, maxLen);
    }
};
