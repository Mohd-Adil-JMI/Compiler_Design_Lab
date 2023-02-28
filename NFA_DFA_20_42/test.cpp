#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "11,21,31,41,51,61";

    vector<int> v;

    // Get the string to be taken
    // as input in stringstream
    stringstream ss(str);

    // Parse the string
    for (int i; ss >> i;)
    {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    // Print the words
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}