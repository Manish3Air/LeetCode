class Solution {
public:
    void GP(vector<string>& ans, string s, int OB, int CB) {
        if (OB == 0 && CB == 0) {
            ans.push_back(s);
            return;
        }

        if (OB == CB) {
            string op1 = s;
            op1.push_back('(');
            GP(ans, op1, OB - 1, CB);
        } else if (OB == 0) {
            string op1 = s;
            op1.push_back(')');
            GP(ans, op1, OB, CB-1);
        } else {
            string op1 = s;
            string op2 = s;
            op1.push_back('(');
            op2.push_back(')');
            GP(ans, op1, OB - 1, CB);
            GP(ans, op2, OB, CB - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        GP(ans, s, n, n);
        return ans;
    }
};