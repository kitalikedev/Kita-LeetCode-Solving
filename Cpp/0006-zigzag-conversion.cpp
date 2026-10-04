class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            // Đổi hướng khi chạm dòng trên cùng hoặc dòng dưới cùng
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};
