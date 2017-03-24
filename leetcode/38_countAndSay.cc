/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n<=0){
            return "";
        }else if(n==1){
            return "1";
        }else if(n==2){
            return "11";
        }
        return buildString(n-2,"11");
    }
    
    
private:
    string buildString(int n, string result){
        if(n<=0){
            return result;
        }
        ostringstream out;
        int count=1;
        for(int i=1;i<result.length();i++){
            if(result.at(i-1)== result.at(i)){
                count++;
            }else{
                out<<to_string(count)<<result.at(i-1);
                count=1;
            }
        }
        //last character
        if(count>1){
            out<<count<<result.at(result.length()-1);
        }else{
            out<<"1"<<result.at(result.length()-1);
        }
        return buildString(n-1,out.str());
    }
};