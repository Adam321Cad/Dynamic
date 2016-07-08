using namespace std;


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>

string readFile(string s){
    //vector<string> codeLines;
    string lines="";
    string line;

    ifstream myfile (s);
    if (myfile.is_open()){
        while (! myfile.eof() ){
            getline (myfile,line);
            lines=lines+line;
        }
        myfile.close();
    }
    return lines;
}

string substring(string str,int start,int end){
    return str.substr(start,end-start);
}

#include "DNObject.h"



#include "Statement.h"
