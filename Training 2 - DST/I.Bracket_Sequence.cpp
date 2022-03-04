#include <iostream>
#include <stack>
#include <utility>

using namespace std;

string s;
stack<pair<char, int> > st1;
stack<pair<int, int> > st2;

void emptyst1(){
    while(!st1.empty()) st1.pop();
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    st2.push({-2,-3});

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(' || s[i] == '[') {
            st1.push({s[i],i});
            continue;
        }
        if(s[i] == ')' || s[i] == ']'){
            if(st1.empty()) {
                continue;
            }
            if(s[i] == ')' && st1.top().first != '('){
                emptyst1();
                continue;
            }
            if(s[i] == ']' && st1.top().first != '['){
                emptyst1();
                continue;
            }
            pair<int,int> t = {st1.top().second,i};
            st1.pop();
            while(st2.top().first > t.first && st2.top().second < t.second){
                st2.pop();
            }
            st2.push(t);
         }
    }

    pair< int,int> res = st2.top(),t = st2.top();
    st2.pop();
    int demres = 0;
    for(int i = t.first; i <= t.second; ++i){
        if(s[i] == '[') ++demres;
    }

    while(!st2.empty()){
        pair<int,int> temp = st2.top();
        st2.pop();

        if(temp.second+1 == t.first){
            t = {temp.first,t.second};
            continue;
        }
        int dem = 0;
        for(int i = t.first; i <= t.second;++i)
            if(s[i] == '[') ++dem;
        if(dem > demres){
            res = t;
            demres = dem;
        }

        t = temp;
    }

    cout << demres << '\n';
    for(int i = res.first; i <= res.second; ++i){
        cout << s[i];
    }

    return 0;
}