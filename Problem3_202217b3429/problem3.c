#include<stdio.h>

int stack[100];  // Stack array with maximum size of 100
int top = -1;    // Variable to track the top of the stack
int n;           // Variable to store the size of the stack

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main()
{
    printf("\n Enter the size of STACK[MAX=100]: ");
    scanf("%d", &n);

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    int choice;
    do
    {
        printf("\n Enter the Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT\n");
                break;
            default:
                printf ("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    } while(choice != 4);

    return 0;
}

void push()
{
    int x;
    if(top >= n-1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top <= -1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped element is %d", stack[top]);
        top--;
    }
}

void display()
{
    if(top >= 0)
    {
        printf("\n The elements in STACK \n");
        for(int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
