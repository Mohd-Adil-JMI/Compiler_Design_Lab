#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    string line;
    fstream fio;
    fio.open("DFA.txt");
    int init;
    getline(fio, line);
    stringstream ss(line);
    ss >> init;
    cout << init << endl;
    vector<vector<pair<int, string>>> table;
    int state;
    string output;
    while (getline(fio, line))
    {
        vector<pair<int, string>> row;
        stringstream ss(line);
        ss >> state;
        ss >> output;
        row.push_back(make_pair(state, output));
        ss >> state;
        ss >> output;
        row.push_back(make_pair(state, output));
        table.push_back(row);
    }
    fio.close();
    for (auto v : table)
    {
        for (auto p : v)
        {
            cout << p.first << " " << p.second << " ";
        }
        cout << endl;
    }
    while (getline(cin, line))
    {
        fio.open("output.in", ios::trunc | ios::out | ios::in);
        int curr = init;
        for (auto c : line)
        {
            if (curr == -1)
            {
                break;
            }
            else
            {
                fio << table[curr][atoi(&c)].second;
                curr = table[curr][atoi(&c)].first;
            }
        }
        fio << endl;
        fio.close();
    }
    return 0;
}