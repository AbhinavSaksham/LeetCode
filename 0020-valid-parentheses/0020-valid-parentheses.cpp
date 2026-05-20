class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  //because lifo
        
        for (char c : s) { //for loop for st
            if (c == '(' || c == '{' || c == '[') { // if no opening return false
                st.push(c); //push all opening bracket to stack 
            } else {
                if (st.empty()) return false; 
                
                char top = st.top(); //get top element of the stack 
                st.pop(); //remove top element now 
                
                if (c == ')' && top != '(') return false;  //close is there but not open
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        
        return st.empty(); // if st become empty return true
    }
};