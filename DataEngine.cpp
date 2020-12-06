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
// .exe [inputfile]
int main(int argc,char *argv[]){
    // Set ENV
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    double start_time = clock();
    string tmpfile_path = "/storage";
    int number_file = 0;
    string outputfile_path = "1.output";
    string inputfile_path = "";
    inputfile_path.append(argv[1]);
    // outputfile_path.append(outputfile_path);
    fstream inputFile(inputfile_path,ios_base::in);
    fstream outputFile(outputfile_path,ios_base::out);
    cout<<"inputFile: "<<inputfile_path<<"\noutputFile: "<<outputfile_path<<endl;
    /* Code start here */
    // read command from inputfile
    if(!inputFile){
        cout<<"File doesn't exist.";
        exit(1);
    }
    string instr;
    while(!inputFile.eof()){
        getline(inputFile,instr);
        const char* delim = " ";
        // extract command from instruction
        int command_pos = instr.find_first_of(delim,0);
        string command = instr.substr(0,command_pos);
        instr = instr.substr(command_pos+1,instr.length());
        cout<<command<<"|";
        if(command == "PUT"){
            // extract key from instruction
            int key_pos = instr.find_first_of(delim,0);
            long long int key = stoll(instr.substr(0,key_pos));
            instr = instr.substr(key_pos+1,instr.length());
            cout<<key<<"|";
            // extract value from instruction
            int value_pos = instr.find_first_of(delim,0);
            string value = instr.substr(0,value_pos);
            cout<<value<<"\n";
        }
        else if(command == "GET"){
            // extract key from instruction
            int key_pos = instr.find_first_of(delim,0);
            long long int key = stoll(instr.substr(0,key_pos));
            instr = instr.substr(key_pos+1,instr.length());
            cout<<key<<"|\n";
        }
        else if(command == "SCAN"){
            // extract key1 from instruction
            int key_pos = instr.find_first_of(delim,0);
            long long int key_1 = stoll(instr.substr(0,key_pos));
            instr = instr.substr(key_pos+1,instr.length());
            cout<<key_1<<"|";
            // extract key2 from instruction
            key_pos = instr.find_first_of(delim,0);
            long long int key_2 = stoll(instr.substr(0,key_pos));
            instr = instr.substr(key_pos+1,instr.length());
            cout<<key_2<<"|\n";
        }

    }

    inputFile.close();
    outputFile.close();
    /* End here */
    double end_time = clock();
    cout<<"\nExecution time:"<< (end_time - start_time) / CLOCKS_PER_SEC << "(s)\n";
    return 0;
}
