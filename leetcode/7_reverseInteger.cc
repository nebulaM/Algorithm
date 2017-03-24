/**
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

class Solution {
public:
    int reverse(int x) {
        int digit=getDigit(x);
        if(getBit(x)>31){
            return 0;
        }
        //cout<<digit<<endl;
        int localX=abs(x);
        int newX=0;
        int tmp=digit;
        while(tmp>0){
            newX+=pushNumTo(getNumAt(localX,tmp),digit-tmp);
            tmp--;
        }
        //checksum to see if overflow
        for(int i=0;i<digit;i++){
            if(getNumAt(localX,i+1)!=getNumAt(newX,digit-i)){
                return 0;
            }
        }
        return x>0?newX:(-newX);
    }
	
    /**
     * @return base 10 digit of the number
     */
    int getDigit(int num){
        int thisNum=abs(num);
        int digit=1;
        while(thisNum>=10){
            thisNum/=10;
            digit++;
        }
        return digit;
    }
    /**
     * @return base 2 digit of the number
     */
    int getBit(int num){
		//boundary case: abs(-2147483649) returns -2147483649 when using int
        unsigned int thisNum=(unsigned int)abs(num);
        //cout<<thisNum<<endl;
        if(thisNum==0){
            return 1;
        }
        int bit=0;
        while(thisNum>0){
            thisNum>>=1;
            bit++;
        }
        //cout<<bit<<endl;
        return bit;
    }
    /**
     * @param num must >0
     * @param numPosition position of the number
     */
    int getNumAt(int num, int numPosition){
        while(numPosition>1){
            num/=10;
            numPosition--;
        }
        return num%10;
    }
    
    /**
     * @param num must >0
     * @param numPosition position of the number
     */
    int pushNumTo(int num, int numPosition){
        while(numPosition>0){
            num*=10;
            numPosition--;
        }
        return num;
    }
    
};