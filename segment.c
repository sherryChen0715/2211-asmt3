#include <stdio.h>
#include <stdlib.h>
    int converter(char x);
    int segment();
    int converter(char x){ //this function convert char into integer
        return x-'0';
    }
    int segment () { //this function create a array to save 10 numbers in segment ways
        char x = 'c'; //to initial the x, this step is reaaaally important
        int b[100];
        char a[10][3][3] =
                {
                        {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},//0
                        {{' ', ' ', ' '}, {' ', '|', ' '}, {' ', '|', ' '}},//1
                        {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},//2
                        {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},//3
                        {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},//4
                        {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},//5
                        {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},//6
                        {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},//7
                        {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},//8
                        {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}//9


                };
        printf("please enter the number(0-9):"); 
        int count = 0, i = 0; //this function is to create a array to save the user input as character
        while (x != '\n') { //create a loop to append elements into the array
            scanf("%c", &x);
            if (x == '\n') {
                break;
            }
            b[i] = converter(x); // use converter to get the integer number
            count++;
            i++;
        }

        for (int t = 0 ; t < 3; t++) { //create a loop to print every number in dimensional
            for (int q = 0; q < count; q++) {
                for (int j = 0; j < 3; j++) {
                    printf("%c", a[b[q]][t][j]);
                }
            }
            printf("\n");
        }


        }
        int main(){ 
            segment();
            char n,skip;
            printf("Y for continuing, N for quit:");
            scanf("%c%c",&n,&skip);
            while(n == 'Y'){ //create a loop, when n equals to "N", this loop exit
                segment();
                printf("Y for continuing, N for quit:");
                scanf("%c%c",&n,&skip);
                while(n!='Y'&&n!='N'){ //create a loop, when input is not equal to Y or N, ask for a new input
                    printf("invalid input, enter again:");
                    scanf("%c%c", &n,&skip);
                }

        }


    }

