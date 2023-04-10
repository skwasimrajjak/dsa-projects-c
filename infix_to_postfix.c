#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
}stack;

void init(stack *p, int size);
char *infix_to_postfix(char *inf, stack *p);
int isfull(stack *p);
void push(stack *p, char item);
int isempty(stack *p);
char pop(stack *p);
int isoperator(char ch);
int precedence(char ch);
char peek(stack *p);

int main()
{
	stack store; //stack to store the operations
	char infix[100];
	system("cls"); //use "clear" if "cls" isn't detected
	
	init(&store,100);
	printf("Enter the Infix Expression: ");
	fgets(infix, 100, stdin);
	char *postfix = infix_to_postfix(infix,&store);
	printf("The Postfix Expression: %s\n",postfix);
	
    return 0;
}

//Initialisation
void init(stack *p,int size)
{
	p->top=-1;
	p->size=size;
	p->arr=(char*)malloc(size*sizeof(char));
}

//Infix to Postfix
char *infix_to_postfix(char *inf,stack *p)
{
	int i,j;
	int len=strlen(inf);
	char *pf=(char*)malloc(len*sizeof(char));

	for(i=0,j=0;i<len;i++)
	{
		if(inf[i]==' '||inf[i]=='\t')
		{
			continue;		
		}
		else if(isalnum(inf[i]))
		{
			pf[j++]=inf[i];
		}
		else if(inf[i]=='(')
		{
			push(p,inf[i]);
		}
		else if(inf[i]==')')
		{
			while(peek(p)!='(' && p->top>-1)
			{
				pf[j++]=pop(p);
			}
			if(p->top==-1) //opening bracket not present
			{
			    return("Invalid Expression\n");
			}
			else
			{
				p->top--; //deletion of the opening bracket
			}
		}
		else if(isoperator(inf[i]))
		{
			while(precedence(inf[i])<=precedence(peek(p)) && p->top>-1)
			{
				pf[j++]=pop(p);
			}
			push(p,inf[i]);
		}
	}
	while(p->top>-1)
	{
		if(peek(p)=='(')
		{
			return "Invalid Expression";
		}		
		else
		{
			pf[j++]=pop(p);
		}
	}
	pf[j]='\0';
	return (pf);
}

// If full
int isfull(stack *p)
{
	return(p->top==p->size-1);
}

// Push a character
void push(stack *p, char item)
{
	int full=isfull(p);
	if(full==0)
	{
		p->arr[++p->top]=item;
	}               
}

// If Empty
int isempty(stack *p)
{
	return(p->top==-1);
}

// Pop the top-most character
char pop(stack *p)
{
	int empty=isempty(p);
	if(empty==0)
	return(p->arr[p->top--]);
}

// If operator
int isoperator(char ch)
{
	return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%');
}

// Stating the precedence
int precedence(char ch)
{
	if(ch=='^')
	return (3);
	else if(ch=='*'||ch=='/'||ch=='%')
	return (2);
	else if(ch=='+'||ch=='-')
	return (1);
	else
	return (0);
}

// Peek top-most character
char peek(stack *p)
{
	return(p->arr[p->top]);
}