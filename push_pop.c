#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
}stack;

//[Signature]
void init(stack *p, int size);
int isfull(stack *p);
int push (stack *p, int item);
int isempty(stack *p);
int pop(stack *p);
void display(stack *p);

int main()
{
    stack user_ip;
    int size;
    int mcq, item; 
    int popped;
    printf("Enter the size: ");
    scanf("%d", &size);
    init(&user_ip, size);
    system("cls");
    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &mcq);
        printf("\n");
        switch (mcq)
        {
            case 1:
                {
                    printf("Enter the element [Except- 0]: ");
                    scanf("%d", &item);
                    if(push(&user_ip, item))
                    {
                        printf("The stack is overflowing.\n");
                    }
                }
                    break;
            case 2:
                {   
                    popped = pop(&user_ip);
                    if(popped==0)
                    {
                        printf("The stack is Underflowing.\n");
                    }
                    else
                    {
                        printf("%d is popped.\n", popped);
                    }
                }
                    break;
            case 3:
                {
                   display(&user_ip);
                }
                    break;
            case 4:
                {
                    break;
                }
            default:
                {
                    printf("Sorry wrong choice. Please try again.\n");
                    
                }
                break;
        }
    } while(mcq!= 4 );

    return 0;
}

//[Initialising]
void init(stack *p, int size)
{
    p->top=-1;
    p->size=size;
    p->arr=(int*)malloc(size*sizeof(int));
}

//[if Overflow]
int isfull(stack *p)
{
    return(p->top==p->size-1);
}

//[To Push the element]
int push (stack *p, int item)
{
    if(isfull(p))
    {
        return 1;
    }
    else
    {
        p->arr[++p->top]=item;
        return 0;
    }
}

//[If Underflow]
int isempty(stack *p)
{
    return(p->top==-1);
}

//[To Pop an elemnt]
int pop(stack *p)
{
    if(isempty(p))
    {
        return 0;
    }
    else
    {
        return (p->arr[p->top--]);
    }
}

void display(stack *p)
{
    if(p->top==-1)
    {
        printf("There is nothing in your stack!!\n");
    }
    else
    {
        for(int i=p->top; i>-1; i--)
        {
            printf("%d\n", p->arr[i]);
        }
    }
    
}