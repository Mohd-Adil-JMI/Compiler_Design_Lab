#include <bits/stdc++.h>
using namespace std;

bool isFinal(int curr, vector<int> finals)
{
    for (int final : finals)
    {
        if (final == curr)
            return true;
    }
    return false;
}
int main()
{
    fstream fio;
    fio.open("DFA.txt");
    int init;
    string line;
    fio >> init;
    fio.ignore();
    cout << init << endl;
    vector<int> finals;
    getline(fio, line);
    stringstream ss(line);
    for (int i; ss >> i;)
    {
        finals.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    for (int final : finals)
        cout << final << " ";
    cout << endl;
    vector<vector<int>> DFA;
    while (getline(fio, line))
    {
        stringstream ss(line);
        vector<int> transitions;
        for (int i; ss >> i;)
        {
            transitions.push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        DFA.push_back(transitions);
    }
    for (auto v : DFA)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    fio.close();
    string input;
    while (cout << "Enter input string : " and getline(cin, input))
    {

        int curr = init;
        fio.open("output.in", ios::trunc | ios::out | ios::in);
        fio << "Result : ";
        if (input.length() == 0)
        {
            cout << "Input string is null i.e no output" << endl;
            continue;
        }
        else
        {
            for (char c : input)
            {
                int i = c - 48;
                curr = DFA[curr][i];
                if (curr == -1)
                    break;
            }
            if (curr == -1 or !isFinal(curr, finals))
                fio << "STRING NOT ACCEPTED\n";
            else
                fio << "STRING ACCEPTED\n";
        }
        fio << endl;
        fio.close();
    }
    return 0;
}