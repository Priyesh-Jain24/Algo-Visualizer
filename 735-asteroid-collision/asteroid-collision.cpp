class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for (int i = 0; i < ast.size(); i++) {
            int curr = ast[i];

            // Collision happens only when stack top > 0 and curr < 0
            while (!st.empty() && st.top() > 0 && curr < 0) {

                if (abs(st.top()) < abs(curr)) {
                    // stack asteroid explodes
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(curr)) {
                    // both explode
                    st.pop();
                }
                // current asteroid explodes
                curr = 0;
                break;
            }

            if (curr != 0)
                st.push(curr);
        }

        // Convert stack to vector
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
