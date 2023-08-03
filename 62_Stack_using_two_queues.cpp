// https://rb.gy/d42sh

class Stack {
	// Define the data members.
    queue<int> a, b;


   public:
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return a.size();
    }

    bool isEmpty() {
        return (a.empty());
    }

    void push(int element) {
        b.push(element);
        while(!a.empty()){
            b.push(a.front());
            a.pop();
        }

        queue<int> temp = a;
        a = b;
        b = temp;
    }

    int pop() {
        if(!a.empty()){
            int num = a.front();
            a.pop();
            return num;
        }
        return -1;
        
    }

    int top() {
        if(!a.empty()){
            return a.front();
        }
        return -1;
        
    }
};
