class Solution {
public:
    string qw[10]={"","M","MM","MMM"};
    string bw[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string sw[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string gw[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string intToRoman(int num) {
        return qw[num/1000]+bw[(num/100)%10]+sw[(num/10)%10]+gw[num%10];
    }
};