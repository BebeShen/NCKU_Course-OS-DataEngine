// #include <iostream>
// #include <unistd.h>
// #include <sys/types.h>

// int main()
// {
// 	FILE *pp = popen("dir", "r"); // build pipe
// 	if (!pp)
// 		return 1;

// 	// collect cmd execute result
// 	char tmp[1024];
// 	while (fgets(tmp, sizeof(tmp), pp) != NULL)
// 		std::cout << tmp << std::endl; // can join each line as string
// 	pclose(pp);

// 	return 0;
// }

// #include <cstdlib>
// int main()
// {   
//     system("ps -ef| grep myprocess");

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[]){
    string path1 = argv[1];
    string path2 = argv[2];
    string s1,s2;
    fstream input1(path1,ios_base::in);
    fstream input2(path2,ios_base::in);
    int line = 0;
    while(!input1.eof() || !input2.eof()){
        line++;
        getline(input1,s1);
        getline(input2,s2);
        // cout<<line<<":\n"<<s1<<"\n"<<s2<<"\n";
        if(s1.compare(s2)!=0){
            cout<<line<<"\n";
            break;
        }
    }
    cout<<line<<"\n";
    return 0;
}