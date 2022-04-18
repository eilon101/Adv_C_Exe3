#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>
void main()
{
	printf("////////************////// Now Check of Stack //////////*********//////////////\n");

	////////////////////////////////////////////Checking Stack.c//////////////////////////////////////
	char str[6];
	Stack* s1 = (Stack*)malloc(sizeof(Stack));
	initStack(s1);
	isEmptyStack(s1);
	//////////////////////Checking Push And POP
	push(s1, 'A');
	push(s1, 'B');
	push(s1, 'C');
	push(s1, 'D');
	push(s1, 'E');
	for (int i = 0; i < 5; i++)
	{
		str[i] = pop(s1);
	}
	str[5] = '\0';
	printf("The Stack data was %s and Now the Stack is Empty\n", str);
	//////////////////////Checking flipBetweenHashes
	printf("the string was *ab#dc#ef* and now: ");
	flipBetweenHashes("ab#dc#ef");
	printf("\n");
	///////////////////Checking isPAlindrome
	push(s1, 'A');
	push(s1, 'B');
	push(s1, 'B');
	push(s1, 'A');
	isPalindrome(s1);

	push(s1, 'A');
	push(s1, 'B');
	push(s1, 'C');
	push(s1, 'D');
	isPalindrome(s1);
	//////////////////Checking rotateStack
	push(s1, 'E');
	push(s1, 'D');
	push(s1, 'C');
	push(s1, 'B');
	push(s1, 'A');
	rotateStack(s1, 2); //rotating stack from ABCDE to DEABC
	destroyStack(s1);


	printf("////////************////// Now Check of Queue //////////*********//////////////\n");
	////////////////////////////////////////////////Checking Queue.c//////////////////////////////////////
	int arr[8];
	
	Queue* q1 = (Queue*)malloc(sizeof(Queue));
	initQueue(q1);
	isEmptyQueue(q1);
	enqueue(q1, 1);
	enqueue(q1, 5);
	enqueue(q1, 4);
	enqueue(q1, 3);
	enqueue(q1, 6);
	enqueue(q1, 2);
	for (int i = 0; i < 6; i++)
	{
		arr[i] = dequeue(q1);
	}
	/////////////////Checking Cut And Replace///////////////////
	enqueue(q1, 6);
	enqueue(q1, 1);
	enqueue(q1, 5);
	enqueue(q1, 2);
	enqueue(q1, 3);
	enqueue(q1, 1);
	enqueue(q1, 9);
	printf("The Queue After Cut And replace Will be : \n");
	cutAndReplace(q1);//**The Queue Will be 3,9,1,3,6,1,5,2 **//
	printf("\n");
	/////////////////Checking rotate Queue/////////////////////////
	rotateQueue(q1);//** The Queue Will be 2,3,9,1,3,6,1,5 **//
	for (int i = 0; i < 8; i++)
	{
		arr[i] = dequeue(q1);
	}
	printf("The Rotated Queue is:\n");

	for (int i = 0; i < 8; i++)
{
		printf("%d ", arr[i]);
}
	printf("\n");
	/////////////////Checking sortKidsFirst///////////////////
	enqueue(q1, 6);
	enqueue(q1, 1);
	enqueue(q1, 3);
	enqueue(q1, 5);
	enqueue(q1, 4);
	enqueue(q1, 2);
	
	sortKidsFirst(q1);
	printf("The Sorted Queue is:\n");
	for (int i = 0; i < 6; i++)
	{
		arr[i] = dequeue(q1);
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	/////////////////Checking destroQueue///////////////////
	enqueue(q1, 6);
	enqueue(q1, 1);
	enqueue(q1, 3);
	destroyQueue(q1);

}