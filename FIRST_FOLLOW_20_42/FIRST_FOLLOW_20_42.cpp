#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    fstream fio;
    fio.open("CFG.txt");
    vector<vector<char>> CFG;
    while (getline(fio, line))
    {
        stringstream ss(line);
        char c;
        vector<char> temp;
        while (ss >> c)
        {
            temp.push_back(c);
        }
        CFG.push_back(temp);
    }
    unordered_map<char, pair<unordered_set<int>, unordered_set<int>>> mp;
    for (auto v : CFG)
    {
        cout << v[0] << " -> ";
        pair<unordered_set<int>, unordered_set<int>> p;
        mp[v[0]] = p;
        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << endl;
    }
    for (int i = 0; i < CFG.size(); i++)
    {
        mp[CFG[i][0]].first.insert(i);
        for (int j = 1; j < CFG[i].size(); j++)
        {
            if (isupper(CFG[i][j]))
                mp[CFG[i][j]].second.insert(i);
        }
    }
    cout << "\tLHS\tRHS" << endl;
    for (auto p : mp)
    {
        cout << p.first << "\t";
        for (int x : p.second.first)
            cout << x << ",";
        cout << "\t";
        for (int x : p.second.second)
            cout << x << ",";
        cout << endl;
    }
    return 0;
}