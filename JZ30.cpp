class Solution {
public:
    stack<int> s;//normal stack
    stack<int> stack_min;//min stack
    void push(int value) {
        s.push(value);
        if(!stack_min.empty() && stack_min.top() < value){
            stack_min.push(stack_min.top());
        }else{
            stack_min.push(value);
        }
    }
    void pop() {
        s.pop();
        stack_min.pop();
    }
    int top() {
        return s.top();      
    }
    int min() {
        return stack_min.top();
    }
};