// http://rb.gy/4yhlh

#include <algorithm>

class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> p;
public:


    Kthlargest(int k, vector<int> &arr) {
        for(int i=0; i<arr.size(); i++){
            p.push(arr[i]);
        }
    }

    int add(int num) {
        if(num > p.top()){
            p.pop();
            p.push(num);
        }
        return p.top();
    }

};
