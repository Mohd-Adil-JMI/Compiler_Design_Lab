#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream fio;
    fio.open("LLTable.txt");
    string line;
    vector<char> terminals;
    getline(fio, line);
    for (char c : line)
    {
        if (c != ' ' && c != '\t' && c != '\n')
            terminals.push_back(c);
    }
    for (char c : terminals)
        cout << c << " ";
    cout << endl;
    unordered_map<char, unordered_map<char, string>> table;
    while (getline(fio, line))
    {
        // cout << line << endl;
        char variable = line[0];
        unordered_map<char, string> transitions;
        int terminal_idx = 0;
        for (int i = 2; i < line.length();)
        {
            string transition = "";
            while (i < line.length() and line[i] != '|')
            {
                if (line[i] != ' ' and line[i] != '\t' and line[i] != '\n')
                    transition += line[i];
                i++;
            }
            transitions[terminals[terminal_idx]] = transition;
            terminal_idx++;
            i++;
        }
        table[variable] = transitions;
    }
    fio.close();
    for (auto transitions : table)
    {
        cout << transitions.first << " ";
        for (auto transition : transitions.second)
        {
            cout << transition.first << " " << transition.second << " ";
        }
        cout << endl;
    }
    string input;
    while (cout << "Enter string " and cin >> input)
    {
        stack<char> st;
        st.push('$');
        st.push('S');
        int idx = 0;
        input += '$';
        while (st.top() != '$')
        {
            char top = st.top();
            st.pop();
            if (top == input[idx])
            {
                idx++;
            }
            else
            {
                string transition = table[top][input[idx]];
                if (transition == "@")
                {
                    // cout << "String not accepted" << endl;
                    break;
                }
                for (int i = transition.length() - 1; i >= 1; i--)
                {
                    st.push(transition[i]);
                }
            }
        }
        if (st.top() == '$' and input[idx] == '$')
            cout << "String accepted" << endl;
        else
            cout << "String not accepted" << endl;
    }

    return 0;
}