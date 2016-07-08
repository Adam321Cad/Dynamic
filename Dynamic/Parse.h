//
//  Parse.h
//  Dynamic
//
//  Created by Marcus Fervil on 7/4/16.
//  Copyright © 2016 fourteenfourhundredstudios. All rights reserved.



class Parse{
    
public:
    string code;
    
    
    Parse (string c) {
        code=c;
    }
    
    string getResult(){
        string result;
        string statement;
        bool inBraces=false;
        for(char& c : code) {
            if(c==';'&&!inBraces){
                string h=statement.substr(0,statement.find("("));
                string f=statement.substr(statement.find("(")+1,statement.find(")")-(statement.find("(")+1));
                
                if(statement.find("{")!=string::npos){
                    parseStatement(Statement(h,f,substring(statement, statement.find("{")+1, statement.length()-1)));
                }else{
                    parseStatement(Statement(h,f));
                }
                    
                statement="";
                continue;
            }else if(c=='{'){
                inBraces=true;
            }else if(c=='}'){
                inBraces=false;
            }else if(c=='\t'){
                continue;
            }
            statement+=c;
            
            
        }
        return result;
    }
    
    void parseStatement(Statement statement){
        
        if(statement.command=="print"){
            cout << "[Dynamic Console]: " << statement.objArray.getProperty("0") <<endl;
        }else if(statement.command=="set"){
            
            DNObject* h=new DNObject();
            h->addProperty("value", statement.objArray.getRawProperty("1"));
            varSet k;
            k.name=statement.objArray.getProperty("0");
            k.object=h;
            
            vars.push_back(k);
            //cout <<h.getProperty("value")<<endl;
        }else if(statement.command=="if"){
           // cout << statement.objArray.getProperty("0");
            if(statement.objArray.getProperty("0")=="true"){
                
                //cout << statement.objArray.getRawProperty("innerCode")<<endl;
                
                Parse parse= Parse(statement.objArray.getRawProperty("innerCode"));
                parse.getResult();
            }
           
        }
    }
    
};
