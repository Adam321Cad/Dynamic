class Statement{

    public:
        string command="";
        //string innerCode="";
        DNObject objArray;
    
    
        Statement(string command_,string code,string innerCode_="NIL"){
            
            //Move this to a new DNObject called DNCodeStruct or something, and take contructor to do most of this
            //cout << code <<endl;
            
            command=command_;
            vector<string> values = vector<string>();
            
            bool inQuote=false;
            string part="";
            for(char& c : code) {
                
                if(c==' '){
                   // continue;
                }else if(c=='"'){
                    if(!inQuote){
                        inQuote=true;
                    }else{
                        inQuote=false;
                    }
                    //continue;
                }else if(c==','&&!inQuote){
                    values.push_back(part);
                    part="";
                    continue;
                }
                part+=c;
            }
            values.push_back(part);
            objArray=DNObject();
            for(int i=0;i<values.size();i++){
                objArray.addProperty(to_string(i), values[i]);
            }
            objArray.addProperty("length", to_string(values.size()));
            
            if(innerCode_!="NIL"){
             //   cout << innerCode_;
                objArray.addProperty("innerCode", innerCode_);
            }
            //if(cout << f.find("{")<<endl;
              // cout << string::npos <<endl;)
            
            
        }
    

    
};