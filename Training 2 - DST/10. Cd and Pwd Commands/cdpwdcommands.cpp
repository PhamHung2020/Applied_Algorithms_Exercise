#include <iostream>
#include <string>
#include <vector>

using namespace std;

string command;
string parameter;
vector<string> path;

int main()
{
    int n;
    cin >> n;

    getchar();
    int length;
    path.push_back("");
    for (int i = 0; i < n; ++i)
    {
        cin >> command;
        if (command == "pwd")
        {
            length = (int)path.size();
            for (int i = 0; i < length; ++i)
                cout << path[i] << '/';
            cout << '\n';
            continue;
        }

        getchar();
        getline(cin, parameter);
        if (parameter[0] == '/')
            path.clear();
        string dir = "";
        length = (int)parameter.size();
        for (int j = 0; j < length; ++j)
        {
            if (parameter[j] != '/')
                dir += parameter[j];
            else
            {
                if (dir != "..")
                    path.push_back(dir);
                else
                    path.pop_back();
                dir = "";
            }
        }
        if (dir != "..")
            path.push_back(dir);
        else
            path.pop_back();
    }

    // cin >> command;
    // cout << command << "!\n";
    // getline(cin, parameter);
    // cout << parameter << '!';

    return 0;
}