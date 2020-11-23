#include<iostream>
#include<string.h>  
#include<fstream>
#include<sstream>  
#include <ctime>
using namespace std;
string IntToString(int num){
    stringstream ss;
    string s;
    ss<<num;
    ss>>s;
    return s;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    double start_time = clock();
    string outputfile_path = "/storage/";
    string inputfile_path = "/storage/";
    int number_file = 0;
    inputfile_path.append(IntToString(number_file));
    outputfile_path.append(IntToString(number_file));
    fstream inputFile(inputfile_path,ios_base::in);
    fstream outputFile(outputfile_path,ios_base::out);
    cout<<"input: "<<inputfile_path<<"\noutput: "<<outputfile_path<<endl;
    double end_time = clock();
    cout<<"\nExecution time:"<< (end_time - start_time) / CLOCKS_PER_SEC << "(s)\n";
    return 0;
}
