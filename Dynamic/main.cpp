//
//  main.cpp
//  Dynamic
//
//  Created by Marcus Fervil on 6/26/16.
//  Copyright © 2016 fourteenfourhundredstudios. All rights reserved.
//




#include <iostream>
#include "Functions.h"
#include "Parse.h"

int main(int argc, const char * argv[]) {
    
    //cout << "ddwdw" << "\n";
    
    
    
    string file = readFile("/Users/Marc/Documents/code/Dynamic/Dynamic/test.dyn");
    
     //s;
    
    
    Parse parse= Parse(file);
    cout << parse.getResult() << "\n";
    
    return 0;
}
