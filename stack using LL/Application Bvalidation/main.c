/*
                AUTHOR : 2125_ANKIT
                PROGRAM: BRACKET VALIDATION PROGRAM USING STACK LINKEDLIST IMPLIMENTATION
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include<stdio.h>
#include"stack.h"
#include<stdlib.h>
#include<stdbool.h>
//This Function is for checking closing and opening bracket
bool isMatchingPair(char pop_chr, char push_chr)
{
    if (pop_chr == '(' && push_chr == ')')
        return 1;
    else if (pop_chr == '{' && push_chr == '}')
         return 1;
    else if (pop_chr == '[' && push_chr == ']')
        return 1;
    else
        return 0;
}
// this function do all work like creating stack, pushing the opening brackets,
// using the matching pair function it popped the pushed ele  
bool bracketBalanced(char exp[])
{
    int i=0;
    stackType s = createStack();
    while(exp[i]!='\0')
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i],&s);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (s.top == NULL)
                return 0; 
            //for unBalanced brackets like ({)},((]) etc. then it is missmatch  
            else if (!isMatchingPair( pop(&s),exp[i]))
                return 0;
        }
        i++;
    }
    if(s.top==NULL)
        return 1;
    else
        return 0;
}
int main()
{
     char exp[100];
     printf("\nPlease provide expressions\n");
     scanf("%s",exp);

    // Function call
    if (bracketBalanced(exp)==1)
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
