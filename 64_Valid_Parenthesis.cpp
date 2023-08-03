//https://www.codingninjas.com/studio/problems/795104?topList=striver-sde-sheet-problems&leftPanelTab=1

bool isValidParenthesis(string s)
{
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='{' || s[i]=='[' || s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
        
    }
    return true;
}
