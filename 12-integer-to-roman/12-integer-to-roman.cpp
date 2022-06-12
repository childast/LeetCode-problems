class Solution {
public:
    string intToRoman(int num) {
        string romanNb = "";
        while(num >= 1000){
            romanNb += "M";
            num -= 1000;
        }
        if(num >= 900){
            romanNb += "CM";
            num -= 900;
        }else if(num >= 400 && num < 500){
            romanNb += "CD";
            num -= 400;
        }else if(num >= 100){
            if(num >= 500){
                romanNb += "D";
                num -= 500;
            }
            while(num >= 100){
                romanNb += "C";
                num -= 100;
            }
        }
        if(num >= 90){
            romanNb += "XC";
            num -= 90;
        }else if(num >= 40 && num < 50){
            romanNb += "XL";
            num -= 40;
        }else if(num >= 10){
            if(num >= 50){
                romanNb += "L";
                num -= 50;
            }
            while(num >= 10){
                romanNb += "X";
                num -= 10;
            }
        }
        if(num >= 9){
            romanNb += "IX";
            num -= 9;
        }else if(num >= 4 && num < 5){
            romanNb += "IV";
            num -= 4;
        }else if(num >= 1){
            if(num >= 5){
                romanNb += "V";
                num -= 5;
            }
            while(num >= 1){
                romanNb += "I";
                num -= 1;
            }
        }
        return romanNb;
    }
};