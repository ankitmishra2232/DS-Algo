/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: greedy Algo coin problem
                DATE CREATED: DEC 2021
                DATE MODIFIED: DEC 2021
*/

#include<stdio.h>
#define max  100

int ans[max];

int findMinCoins(int coins[], int size,  int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        //take as much from coins[i]
        while(value >= coins[i])
        {
            //after taking the coin, reduce the value.
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;

    }

    return count;
}

int main()
{
	int s;
    printf("Please enter how many coins you want\n");
	scanf("%d",&s);
    int coins[50];
	printf("Enter the coins in desending order \n"); // because it gives priority to the first element 
    for (int i = 0; i < s; ++i)             // can impliment sorting algo for changing into desending order
        scanf("%d", &coins[i]);
    int value, i;
	printf("What value do you want ? \n: - ");
	scanf("%d",&value);
    //find the size of the coins array
    int size = sizeof(coins)/sizeof(coins[0]);

    int MinCount = findMinCoins(coins,size,value);

    printf("Total Coins Needed = %d\n",MinCount);

    printf("Coins are:\t");
    for(i = 0; i < MinCount; i++)
        printf("%d ", ans[i]);

    return 0;
}


