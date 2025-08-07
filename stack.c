#include<stdio.h>
#define size 5

void main()
{
    int stack[size];
    int top=-1;
    int choice,value;

		void push (int stack[] ,int *top ,int value);
		void pop (int stack[],int *top);
		void peep(int stack[],int *top);
		void display(int stack[],int *top);
		
    while(1)
    {
        printf("\n stack operation...\n");
        printf("1.PUSH\n2.POP\n3.PIP\n4.DISPLAY\n");
        printf("enter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value To Push:");
                scanf("%d",& value);
                push(stack,&top,value);
            	break;

            case 2:
                pop(stack,&top);
            	break;

			case 3:
            	peep(stack,&top);
            	break;
            	
            case 4:
	            display(stack,&top);
            	break;

            default :
                printf("Invalid Choice ! Please Try Again\n");
                break;
        }
    }
}

void push (int stack[], int *top,int value)
{
	if(*top>=size-1)
    {
        printf("stack is overloaad,can not push more items");
    }
    else{
	    (*top)=(*top)+1;
	    stack[(*top)]=value;
	    printf("Pushed %d on to the stack.\n",value);
	}
}
void pop (int stack[],int *top)
{
	int popedvalue;
	if(*top==-1)
    {
    	printf("Stack underflow,No items to top\n");
    }
    else{
		popedvalue=stack[(*top)];
		(*top)=(*top)-1;
		printf("Poped value %d from stack \n",popedvalue);
	}
}
void peep(int stack[],int *top){
	printf("Top Number is : %d",stack[(*top)]);
}
void display(int stack[],int *top) 
{	int i;
    if(*top==-1)
    {
        printf("Stack is Empty.\n");
    }
    else{
        printf("stack elements(top to bottom)\n");
	
        for(i=0;i<=(*top);i++)
        {
            printf("%d\n",stack[i]);
        }
    }

}
