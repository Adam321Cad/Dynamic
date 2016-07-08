
class DNObject;


struct varSet{
    string name;
    DNObject* object;
};

vector<varSet> vars;

class DNObjectProperty{
    
public:
    string property;
    string value;
    
    DNObjectProperty (string prop,string val) {
        property=prop;
        value=val;
    }
   
};

class DNObject{
  
    public:

        vector<DNObjectProperty> Properties;
    
        DNObject(){
            
        }
    
        string parseProperty(string property){
            string value="NIL";
            if(property.substr(0,1)=="\""){
                value=property.substr(1,property.length()-2);
            }else if(property.substr(0,1)=="@"){
                string varName=property.substr(1,property.length()-1);
                for(int i=0;i<vars.size();i++){
                    if(vars[i].name==varName){
                        DNObject* h=vars[i].object;
                        value=h->getProperty("value");
                        break;
                    }
                }
            }else if(property=="true"||property=="false"){
                return property;
            }else if(substring(property,0,1)=="("){
                
            
            }else{
                cout << "[Dynamic Console Error]: Could not parse argument '" <<property << "'"<<endl;
            }
            return value;
        }
    
        void addProperty(string property,string value){
            

            DNObjectProperty h=DNObjectProperty(property,value);
            Properties.push_back(h);
        }
    


        string getProperty(string property){
            for(int i=0;i<Properties.size();i++){
                
               //cout << Properties.at(i).property <<endl;
                
                if(Properties.at(i).property==property){
                    return parseProperty(Properties.at(i).value);
                }
            }
            return "could not get variable "+property;
        }
    
        string getRawProperty(string property){
            for(int i=0;i<Properties.size();i++){
                
                //cout << Properties[i].property <<endl;
                
                if(Properties.at(i).property==property){
                    return Properties.at(i).value;
                }
            }
            return "could not get variable "+property;
        }
  
};

