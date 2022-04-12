#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//**************// Added Functions signatures //****************//

charNode* addToHead(charNode* head, charNode* toAdd);
void removeItem(charNode** head);
void revstr(char* str1);
/*************/ /*Added Functions *//**************/
charNode* addToHead(charNode* head, charNode* toAdd)
{
	toAdd->next = head;
	head = toAdd;
	return head;
}
void removeItem(charNode** head)
{
	if (*head == NULL) return; // if stack empty
	charNode* tmp = *head; //temporary variable for the old head
	*head = (*head)->next;
	free(tmp);	
}
void revstr(char* str1)
{
	// declare variable  
	int i, len, temp;
	len = strlen(str1); // use strlen() to get the length of str string  

	// use for loop to iterate the string   
	for (i = 0; i < len / 2; i++)
	{
		// temp variable use to temporary hold the string  
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
	}
}

/***************** Stack ADT Implementation *****************/


void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	while (s->head != NULL)
	{
		removeItem(&(s->head));
    }
	printf("The Stack was destroyed\n");
}
void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL)
	{
		printf("push Memmory Allocation Error\n");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);
}

char pop(Stack* s)
{
	char res;
	if (s->head == NULL)
	{
		printf("\nSTACK IS EMPTY"); 
		return 0;
	}
	res = s->head->data;
	removeItem(&(s->head)); //pop it from the stack
	return res;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
	{
		printf("The Stack is Empty\n");
		return 1;
	}
	else
	{
		printf("The Stack is'nt Empty\n");

		return 0;
	}	
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* help_stack = (Stack*)malloc(sizeof(Stack));
	initStack(help_stack);
	int j = 1;
	int pop_cnt = 0;
	for (int i = 0; sentence[i] != '\0'; i++)
	{

		if (sentence[i] == '#')
		{
			while (sentence[i+j] != '#')
			{
				push(help_stack, sentence[i + j]);
				j++;
			}

			pop_cnt = j - 1; //num of pushes to pop
			i = i + j + 1;// update i to print characters after $
			for (j = pop_cnt; j > 0; j--)
			{
				int res = pop(help_stack);
				printf("%c", res);
			}

		}
		

		printf("%c", sentence[i]);

	}
}

int isPalindrome(Stack* s)
{
	char temp_str[50];
	char reverse_temp_str[50];
	int i = 0;
	int size = 0;
	if ( isEmptyStack(s) == 1 )
	{
		printf("The Stack is Empty -> Palindrome\n");
		return 1; //empty stack is palindrome
	}
	while(s->head!=NULL)
	{
		temp_str[i] = pop(s); //pop all stack to string
			i++;
	}
	size = i; //for '\0'
	temp_str[i] = '\0'; // for exa: "ABC"
	for (int i = 0; i < size; i++) //pushing back to stack
	{
		push(s, temp_str[i]); //reverse pushing
	}
	for (int i = 0; i < size; i++)
	{
		reverse_temp_str[i] = pop(s); //pop all stack to  reverse string
	}
	reverse_temp_str[i] = '\0'; // for exa: "CBA"

	if (strcmp(temp_str, reverse_temp_str) == 0)
	{
		printf("The Stack is Palindrome\n");
		return 1; //palindrome
	}
	printf("The Stack is'nt Palindrome\n");
	return 0; //not palindrome
}




void rotateStack(Stack* s, int n)
{
	char temp_str[50];
	int i = 0;
	int size;
	if (n < 0)
	{
		return; // if n illegal out of the function
    }

	while (s->head != NULL)
	{
		temp_str[i] = pop(s); //pop all stack to string
		i++;
	}
	temp_str[i] = '\0'; // for exa: "ABCDE"
	 size = i; // number of elements in the stack

		    //////////// Check If n > number of Elements ////////// out of function
	if (n > size)
	{
		return;
	}
	else //////////////// If n<= to number of elements   ///////////////////// countinue
	{
		revstr(temp_str); /// reverse the string  for example: "EDCBA"
		for (int i = 0; i < size; i++) //pushing back to stack in the original order
		{
			push(s, temp_str[i]); //pushing back to original stack
		}
		int bottomlen = size - n;
		char* topstr = (char*)malloc(n * sizeof(char) + 1); /// the string that goes to top of the stack ( n characters)
		char* bottomstr = (char*)malloc(bottomlen * sizeof(char) + 1); /// the string that goes to bottom of the stack ( size-n characters)
		if (topstr == NULL || bottomstr == NULL)
		{
			printf("Allocation Error in one of the strings");
			exit(0);
		}
		for (i = 0; i < bottomlen; i++) /// fill the string that will go to the bottom of the new stack
		{
			bottomstr[i] = pop(s); 
		}
		bottomstr[i] = '\0'; // "ABC"
		for (i = 0; i < n; i++)
		{
			topstr[i] = pop(s); //  "DE"
		}
		topstr[i] = '\0';
		revstr(topstr); /// reversing the string to push in the correct order // "ED"
		revstr(bottomstr); // reversing the string to push in the correct order// "CBA"
		for (i = 0; i < bottomlen; i++)
		{
			push(s,bottomstr[i]);
		}
		for (i = 0; i < n; i++)
		{
			push(s,topstr[i]);
		}
		/*printf("%s\n", topstr);
		printf("%s\n", bottomstr);*/

	}

}
