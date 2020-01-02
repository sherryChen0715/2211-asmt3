#include <stdio.h>
#include <stdlib.h>
float get_num();
char get_op();
float m_exp(float sub_exp, char op);
float s_exp(float sub_exp,char op);

int main() {
    float num;
    char op;
    char loop = 'Y';
    char skip;
    while(loop == 'Y') { //create a loop while input equals to Y
        printf("please enter an expression:\n");//ask for a input expression
        num = get_num(); //get a float number from get_num() function
        op = get_op(); //get a operation from get_op() function
        printf("the result is: %f", s_exp(num, op)); //use s_exp() function to get the result
        printf("\nY for continuing, N for quit:");
        scanf("%c%c", &loop,&skip);
    }
}

float get_num(){ //create a function to get number
    float f;
    scanf(" %f",&f);
    return f;
}
char get_op(){  //create a function to get operation, while character equals to \n, return 0 to know we are get to the end.
    char c;
    scanf("%c", &c);// chn
    while(c == ' '){
        scanf("%c", &c);
    }
    if(c=='\n'){
        return '0';
    }
    return c;
}

float m_exp(float sub_exp, char op){
    if(op!='+'&&op!='-'&&op!='/'&&op!='*'&&op!='0'){
        printf("incorrect operator");
        exit(EXIT_FAILURE); // while enter a invalid input like "%" will print a message
    }

    if(op == '*'){ //multiple 
        float a,f = get_num();
        char o = get_op();
        a = m_exp(sub_exp*f, o); 
        return a;

    }
    if(op == '/'){ //divide
        float a,f = get_num();
        char o = get_op();
        a = m_exp(sub_exp/f,o );
        return a;
    }

    else {
        ungetc(op,stdin); //return + and - to stdin
        return sub_exp;
    }


}
float s_exp(float sub_exp,char op) {
    float current_n, next_n;
    char current_c, next_c;
    current_n = m_exp(sub_exp, op);// get number from m_exp
    current_c = get_op();
    if(op!='+'&&op!='-'&&op!='/'&&op!='*'&&op!='0'){ // print a message when user enter invalid input
        printf("incorrect operator");
        exit(EXIT_FAILURE);
    }
    if (current_c == '0') { //we have get to the end, return current number
        return current_n;
    }
    if (current_c == '+') { //plus 
        next_n = get_num();
        next_c = get_op();
        return current_n + s_exp(next_n, next_c);
    }
    if (current_c == '-') { //minus
        next_n = get_num();
        next_c = get_op();
        if (next_n >= 0) { //when next number is larger than 0, return current number - next number
            if (next_c == '+' || next_c == '-') {
                return s_exp(current_n - next_n, next_c);
            }

        }
        if (next_n < 0) { //when next number is less than 0, we should change the - to +

            return current_n + s_exp(-next_n, next_c);
        }


        if (next_c == '*' || next_c == '/' || next_c == '0') { //next number is * or /, just minus them
            return current_n - s_exp(next_n, next_c);
        }
    }
}
