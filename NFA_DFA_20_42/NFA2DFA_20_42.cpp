#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<set<int>>> NFA)
{
    for (auto vv : NFA)
    {
        for (auto v : vv)
        {
            if (v.size() > 1)
                return true;
        }
    }
    return false;
}
int main()
{
    string line;
    fstream fio;
    fio.open("NFA.txt");
    int init;
    fio >> init;
    cout << init << endl;
    fio.ignore();
    getline(fio, line);
    stringstream ss(line);
    vector<int> final;
    int state;
    while (ss >> state)
    {
        final.push_back(state);
    }
    for (int x : final)
    {
        cout << x << " ";
    }
    vector<vector<set<int>>> NFA;
    while (getline(fio, line))
    {
        vector<set<int>> transitions;
        stringstream ss(line);
        string states;
        while (ss >> states)
        {
            set<int> temp;
            stringstream ss(states);
            for (int i; ss >> i;)
            {
                temp.insert(i);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            transitions.push_back(temp);
        }
        NFA.push_back(transitions);
    }
    cout << endl;
    int i = 0;
    cout << "<---NFA---->" << endl;
    for (auto vv : NFA)
    {
        cout << "q" << i << "-> ";
        for (auto v : vv)
        {
            cout << "{";
            for (int x : v)
            {
                cout << x << ",";
            }
            cout << "} ";
        }
        cout << endl;
        i++;
    }
    queue<set<int>> q;
    set<set<int>> mp;
    for (auto &vv : NFA)
    {
        for (auto &s : vv)
        {
            if (s.size() > 1)
            {
                q.push(s);
                mp.insert(s);
            }
        }
    }
    while (!q.empty())
    {
        set<int> s = q.front();
        q.pop();
        vector<set<int>> transitions(NFA[0].size());
        for (int x : s)
        {
            for (int i = 0; i < NFA[0].size(); i++)
            {
                transitions[i].insert(NFA[x][i].begin(), NFA[x][i].end());
                if (transitions[i].find(-1) != transitions[i].end())
                {
                    transitions[i].erase(-1);
                }
                if (transitions[i].size() == 0)
                    transitions[i].insert(-1);
            }
        }
        for (int i = 0; i < transitions.size(); i++)
        {
            if (transitions[i].size() > 1 and mp.find(transitions[i]) == mp.end())
            {
                // cout << "Pushing-> ";
                // for (int x : transitions[i])
                //     cout << x << " ";
                // cout << endl;
                q.push(transitions[i]);
                mp.insert(transitions[i]);
            }
        }
        NFA.push_back(transitions);
    }
    cout << "<---DFA---->" << endl;
    i = 0;
    for (auto vv : NFA)
    {
        cout << "q" << i << "-> ";
        for (auto v : vv)
        {
            cout << "{";
            for (int x : v)
            {
                cout << x << ",";
            }
            cout << "} ";
        }
        cout << endl;
        i++;
    }
    return 0;
}