#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string sa;
    ifstream myfile;
    myfile.open("DFA.txt");
    do
    {
        getline(myfile, sa);
        cout << sa << endl;
        /* code */
    } while (!myfile.eof());
    
    return 0;
}