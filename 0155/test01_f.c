/*
    155. Min Stack
        Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
        Implement the MinStack class:
            MinStack() initializes the stack object.
            void push(int val) pushes the element val onto the stack.
            void pop() removes the element on the top of the stack.
            int top() gets the top element of the stack.
            int getMin() retrieves the minimum element in the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30000

typedef struct
{
    int top;
    int minData[MAXSIZE];
    int data[MAXSIZE];
} MinStack;

MinStack *minStackCreate()
{
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    //初始栈为空
    stack->top = 0;
    return stack;
}

void minStackPush(MinStack *obj, int val)
{
    if (obj->top == 0)
    {
        obj->minData[obj->top] = val;
    }
    else
    {
        obj->minData[obj->top] = val < obj->minData[obj->top - 1] ? val : obj->minData[obj->top - 1];
    }
    obj->data[obj->top] = val;
    obj->top += 1;
    return;
}

void minStackPop(MinStack *obj)
{
    obj->top -= 1;
    return;
}

int minStackTop(MinStack *obj)
{
    return obj->data[obj->top - 1];
}

int minStackGetMin(MinStack *obj)
{
    return obj->minData[obj->top - 1];
}

void minStackFree(MinStack *obj)
{
    free(obj);
}