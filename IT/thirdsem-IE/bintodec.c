#include<stdio.h>
#include<math.h>

void bin(int value)
{
    int answer = 0;
    for(int i = 0; value != 0; i++)
    {
        if (value % 10 == 1)
            answer += pow(2,i);
        value = value / 10;
    }
    printf("The answer is : %d",answer);
}

void dec(int value)
{
    int answer = 0;
    while (value != 0)
    {
        answer = answer + ((value % 2) *1);
        answer *= 10;
        value /= 2;
    }
    printf("The answer is : %d",answer);
}

int main(void)
{
    int input;
    printf("What do you want to perform\n");
    printf("1.Binary to Decimal\n");
    printf("2.Decimal to Binary\n");
    scanf("%d",&input);

    switch(input)
    {
        case 1:
            printf("Enter the value to be converted\n");
            int value1;
            scanf("%d",&value1);
            bin(value1);
            break;
        
        case 2:
            printf("Enter the value to be converted\n");
            int value2;
            scanf("%d",&value2);
            dec(value2);
            break;

        default:
            printf("Wrong option \n");
    }
}