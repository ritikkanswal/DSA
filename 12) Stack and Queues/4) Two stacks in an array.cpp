// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1/#

//Function to push an integer into the stack1.
int size=100;
int st[100];
int top1=0,top2=99;
void twoStacks :: push1(int x)
{
    st[top1++]=x;
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    st[top2--]=x;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if((top1)==-1) return -1;
    return st[--top1];
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if((top2)==size) return -1;
    return st[++top2];
}