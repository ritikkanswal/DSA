

//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> Queue)
{
    stack<int> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
    
    return Queue;
}