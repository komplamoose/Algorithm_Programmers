#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) { 
    for (int i=0; i < new_id.length(); i++) {
        new_id[i]=tolower(new_id[i]);
    }
    new_id=regex_replace(new_id, regex("[^a-z0-9-._]"), "");
    new_id=regex_replace(new_id, regex("\\.+"), ".");
    new_id=regex_replace(new_id, regex("^\\."), "");
    new_id=regex_replace(new_id, regex("\\.$"), "");
    
    if (new_id=="") new_id+="a";
    if (new_id.length()>15) new_id=new_id.substr(0, 15);
    new_id=regex_replace(new_id, regex("\\.$"), "");
    if (new_id.length()<=2){
        while(new_id.length()!=3)
            new_id+=new_id[new_id.length()-1];
    }
    
    return new_id;
}