class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> last(26); // Store last occurrence of each character

        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        
        vector<bool> visited(26, false); // Check if character is already in answer
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];            
            if(visited[ch - 'a']) // Skip if already present
                continue;

            // Remove larger characters if they appear later
            while(!st.empty() &&
                  st.top() > ch &&
                  last[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);  // Add current character
            visited[ch - 'a'] = true;
        }

        string ans = ""; // Convert stack to string

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};