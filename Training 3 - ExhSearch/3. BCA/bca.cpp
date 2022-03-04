#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int courses[35];
vector<vector<int>> listOfCouses;
vector<vector<int>> listOfConflictingCourses;
int loadOfTeacher[35];
int loadMax = 0;
int minLoad = 2147483647;

bool checkCourse(int course, int teacher)
{
    bool canTeach = false;
    for (int i = 0; i < listOfCouses[teacher].size(); ++i)
        if (listOfCouses[teacher][i] == course)
        {
            canTeach = true;
            break;
        }
    if (!canTeach)
        return false;

    for (int i = 0; i < listOfConflictingCourses[course].size(); ++i)
        if (listOfConflictingCourses[course][i] < course && courses[listOfConflictingCourses[course][i]] == teacher)
            return false;
    return true;
}

void Try(int course)
{
    for (int i = 0; i < m; ++i)
    {
        if (checkCourse(course, i))
        {
            courses[course] = i;
            loadOfTeacher[i]++;
            int pre = loadMax;
            loadMax = max(loadMax, loadOfTeacher[i]);

            if (course + 1 == n)
                minLoad = min(minLoad, loadMax);
            else if (loadMax < minLoad)
                Try(course + 1);

            --loadOfTeacher[i];
            loadMax = pre;
        }
    }
}

int main()
{
    int k;
    cin >> m >> n;
    listOfCouses.resize(m + 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int temp;
            cin >> temp;
            listOfCouses[i].push_back(temp);
        }
    }

    cin >> k;
    listOfConflictingCourses.resize(n + 1);
    for (int i = 0; i < k; ++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        listOfConflictingCourses[temp1].push_back(temp2);
        listOfConflictingCourses[temp2].push_back(temp1);
    }

    Try(1);
    cout << minLoad;
    return 0;
}