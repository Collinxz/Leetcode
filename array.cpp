#include "stc++.h"

using namespace std;

/* 42. Trapping Rain Water */
int trap(vector<int> &height)
{
    int lmax = 0, rmax = 0;
    vector<int> l, r;
    for (int i = 0; i < height.size(); ++i)
    {
        if (height[i] > lmax)
            lmax = height[i];
        l.push_back(lmax);
        if (height[height.size() - i - 1] > rmax)
            rmax = height[height.size() - i - 1];
        r.push_back(rmax);
    }
    int res = 0;
    for (int i = 0; i < height.size(); ++i)
    {
        res += min(l[i], r[height.size() - i - 1]) - height[i];
    }
    return res;
}

/* 567. Permutation in String */
bool checkInclusion(string s1, string s2)
{
    bool res = false;
    int count = 0;
    int len1 = s1.length();
    vector<int> ind(26, 0);
    for (char s : s1)
        ind[s - 'a'] += 1;
    for (int x : ind)
        if (x)
            count += 1;
    for (int i = 0; i < s2.length(); ++i)
    {
        if (i >= len1)
        {
            if (ind[s2[i - len1] - 'a'] == 0)
                count++;
            ind[s2[i - len1] - 'a']++;
            if (ind[s2[i - len1] - 'a'] == 0)
                count--;
        }
        if (ind[s2[i] - 'a'] == 0)
            count++;
        ind[s2[i] - 'a']--;
        if (ind[s2[i] - 'a'] == 0)
            count--;
        if (count == 0)
            return true;
    }
    return res;
}

/* 648. Replace Words */
string replaceWords(vector<string> &dictionary, string sentence)
{
    map<string, bool> dicts;
    for (string dict : dictionary)
    {
        dicts[dict] = true;
    }
    string res = "";
    string root = "";
    bool flag = true;
    for (auto ch : sentence)
    {
        if (ch == ' ')
        {
            res += root;
            res += " ";
            flag = true;
            root = "";
        }
        else
        {
            if (flag)
            {
                root += ch;
                if (dicts.find(root) != dicts.end())
                {
                    flag = false;
                }
            }
        }
    }
    res += root;
    return res;
}

/* 1004. Max Consecutive Ones III */
int longestOnes(vector<int> &A, int K)
{
    int res = 0;
    int tmp = 0;
    int i = 0, j = 0;
    while (j < A.size())
    {
        if (A[j] == 1)
            tmp++;
        else
        {
            if (K > 0)
            {
                K--;
                tmp++;
            }
            else
            {
                while (A[i] != 0 && i <= j)
                {
                    i++;
                    tmp--;
                }
                if (A[i] == 0)
                    i++;
            }
        }
        j++;
        res = max(res, tmp);
    }
    return res;
}

/* 57. Insert Interval */
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    bool flag = true;
    for (auto interval : intervals)
    {
        if (interval[0] > newInterval[1])
        {
            if (flag)
            {
                res.push_back(newInterval);
                flag = false;
            }
            res.push_back(interval);
        }
        if (interval[1] < newInterval[0])
            res.push_back(interval);
        else
        {
            if (interval[0] < newInterval[0])
            {
                newInterval[0] = interval[0];
            }
            if (interval[1] >= newInterval[1])
            {
                newInterval[1] = interval[1];
            }
        }
    }
    if (flag)
    {
        res.push_back(newInterval);
        flag = false;
    }
    return res;
}