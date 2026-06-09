class MyQueue {
public:
    stack<int> s1; // Incoming elements
    stack<int> s2; // Outgoing elements

    MyQueue() {
    }

    void push(int x) {
        // Always push into s1
        s1.push(x);
    }

    int pop() {

        // If s2 is empty, transfer all elements
        // from s1 to s2 to reverse the order
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Front element of queue
        int val = s2.top();
        s2.pop();

        return val;
    }

    int peek() {

        // Transfer only when needed
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Return front element
        return s2.top();
    }

    bool empty() {

        // Queue is empty only if both stacks are empty
        return s1.empty() && s2.empty();
    }
};