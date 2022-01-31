/*
                AUTHOR : 2125_ANKIT
				ROLL_No:2125
                PROGRAM: PostFix programm
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2125_stack.h"
int main()
{
	char exp[3]; //taking maximum 3 in expression
	eleType a,b,c,choice,i=0;
	float ans;
	stackType s = createStack();
		printf("Enter the expression to be pushed like 1st digit, 2nd digit and then arithematic expression :");
		scanf("%s",&exp); //not able to do validate input
		while(exp[i]!='\0')
		{
			if((exp[i]>='0')&&(exp[i]<='9')) 
			{
				c=exp[i]-'0';
				push(c,&s);
			}
			else
			{
				a=pop(&s); //popping top elements and storing in both a and b. 
				b=pop(&s);	
				switch(exp[i])
				{ // taking case for switching from expression
					case '+' : 
						ans=a+b; //adding
						push(ans,&s);
						break;
					case '-' : 
						ans=b-a; //subtracting
						push(ans,&s);
						break;
					case '*' :
						ans=a*b; //multipling
						push(ans,&s);
						break;
					case '/' : 
						ans=b/a; // division
						push(ans,&s); 
						break;
				}
				
			}
			i++;
		}
		ans=pop(&s);
		printf("The Postfix Expression Is = %.2f \n",ans);
		destroyStack(&s);
		printf("\n %d", s.top); //
		return 0;
}
