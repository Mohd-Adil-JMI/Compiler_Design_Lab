#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct triple
{
    int state1;
    int state2;
    string output;
    triple() : state1(-1), state2(-1), output("") {}
    triple(int s1, int s2, string o) : state1(s1), state2(s2), output(o) {}
};
triple make_triple(int s1, int s2, string o)
{
    triple t(s1, s2, o);
    return t;
}
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
    vector<triple> table;
    int state1;
    int state2;
    string output;
    while (getline(fio, line))
    {
        stringstream ss(line);
        ss >> state1;
        ss >> state2;
        ss >> output;
        table.push_back(make_triple(state1, state2, output));
    }
    fio.close();
    for (auto v : table)
    {
        cout << v.state1 << " " << v.state2 << " " << v.output << " ";
        cout << endl;
    }
    while (getline(cin, line))
    {
        fio.open("output.in", ios::trunc | ios::out | ios::in);
        // if (line.length() == 0)
        // {
        //     continue;
        // }
        // else
        // {
        int curr = init;
        for (auto c : line)
        {
            if (curr == -1)
            {
                break;
            }
            else
            {
                fio << table[curr].output;
                if (c == '0')
                    curr = table[curr].state1;
                else
                    curr = table[curr].state2;
            }
        }
        if (curr != -1)
        {
            fio << table[curr].output;
        }
        fio << endl;
        fio.close();
        // }
    }
    return 0;
}