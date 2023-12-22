#include <iostream>
#include "List.h"
List split(const string&);
bool priorityCheck(string&, string&);
List postfixMaker(List&);
float calculator(List&);
int main() {
    List myList;
    float result;
    string input;
    getline(cin,input);
    myList = split(input);
    myList = postfixMaker(myList);
    myList.print();
    result = calculator(myList);
    cout<<"Result = "<<result<<" .\n";
}
List split(const string& input){
    List split;
    for(int i=0 , j=0; input[i] ; i++){
        if(input[i]==' ') {
            if(i==j)
                split.append(input[i]);
            else {
                string temp;
                for (j; j < i; j++)
                    temp += input[j];
                split.append(temp);
            }
            j++;
        }
        if (!input[i+1]){
            string temp;
            for(j;j<=i;j++){
                temp += input[j];
            }
            split.append(temp);
        }
    }
    return split;
}
bool priorityCheck(const string& a,const string& b){
    if (b == "(" || b == ")")
        return false;
    if (a == "+" || a == "-") {
        return true;
    }
    if (a == "*" || a == "/") {
        if (b == "+" || b == "-" )
            return false;
        return true;
    }
    if(a=="^"&&b=="sin"||b=="cos")
        return true;

    return false;
}
List postfixMaker(List& input){
    List operators;
    List result;
    while(!input.isEmpty()) {
        if (input.pickFromDown() == "(")
            operators.append(input.pfd());
        else if(input.pickFromDown() == "+"|| input.pickFromDown() == "-" || input.pickFromDown() == "sin"||input.pickFromDown() == "cos"||
                input.pickFromDown() == "*" || input.pickFromDown() == "/" || input.pickFromDown() == "^" )  {
            while (!operators.isEmpty()&&priorityCheck(input.pickFromDown(),operators.pick())){
                result.append(operators.pop());
            }
            operators.append(input.pfd());
        }
        else if(input.pickFromDown() == ")"){
            while (operators.pick()!="("){
                result.append(operators.pop());
            }
            operators.pop();
            input.pfd();
        }
        else
            result.append(input.pfd());
    }
    while (!operators.isEmpty())
        result.append(operators.pop());
    return result;
}
float calculator(List& input){
    float result;
    List cal;
    while(!input.isEmpty()){
        if(input.pickFromDown()=="+") {
            float b = stof(cal.pop());
            float a = stof(cal.pop());
            string r = to_string(a+b);
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="-") {
            float b = stof(cal.pop());
            float a = stof(cal.pop());
            string r = to_string(a-b);
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="*") {
            float b = stof(cal.pop());
            float a = stof(cal.pop());
            string r = to_string(a*b);
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="/") {
            float b = stof(cal.pop());
            float a = stof(cal.pop());
            string r = to_string(a/b);
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="^") {
            float b = stof(cal.pop());
            float a = stof(cal.pop());
            string r = to_string(powf(a,b));
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="sin") {
            float a = stof(cal.pop());
            string r = to_string(sin(a/57));
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="cos") {
            float a = stof(cal.pop());
            string r = to_string(cos(a/57));
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="tan") {
            float a = stof(cal.pop());
            string r = to_string(tan(a/57));
            cal.append(r);
            input.pfd();
        }
        else if(input.pickFromDown()=="cot") {
            float a = stof(cal.pop());
            string r = to_string(1.0/(tan(a/57)));
            cal.append(r);
            input.pfd();
        }
        else{
            cal.append(input.pfd());
        }
    }
    result = stof(cal.pop());
    return result;
}