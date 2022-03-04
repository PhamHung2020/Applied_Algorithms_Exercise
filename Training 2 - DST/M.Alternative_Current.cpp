#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.length(); ++i){
        if(!st.empty()){
            if(st.top() == s[i]){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }

    if(st.empty()){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}