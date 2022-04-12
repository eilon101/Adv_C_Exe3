#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//**************// Added Functions signatures //****************//
void selectionSort(int arr[], int n);

////////////////////Added functions/////////////////////////

void selectionSort(int arr[], int n)
{
	int i, j, min_idx, temp;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++) 
	{

		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
				temp = arr[min_idx];
				arr[min_idx] = arr[i];
				arr[i] = temp;
				min_idx =i;

			}
		}
	}


	}
/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	
	q->head = NULL;
	q->tail= NULL;
}

void destroyQueue(Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
	{
		printf("can't destroy an empty list\n");
		return;
	}
	intNode* toDestroy = q->head;
	intNode* next;
	while (toDestroy != NULL)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next; //updating new head
	}
	printf("The Queue was Destroyed\n");

}

void enqueue(Queue* q, unsigned int data)
{
	
	//description - add element to queue
   // input - q: pointer to queue, data: a value to add
	intNode* p = (intNode*)malloc(sizeof(intNode));
	if (p == NULL)
	{
		printf("Allocation Error\n");
		exit(0);
	}
	p->data = data; // set element data
	p->next = NULL; //end of Queue
	if (!isEmptyQueue(q)) q->tail->next = p; // if Queue not Empty
	//Add after last:
	else q->head = p; // if Queue is Empty
	//first
	q->tail = p; // update queue tail

}

unsigned int dequeue(Queue* q)
{
	// this function delete the head and return his data
	if (isEmptyQueue(q)==1)
	{
		printf("Cannot dequeue an empty queue!");
		return 0;
	}
	else
	{
		int temp = q->head->data;
		intNode* p = q->head;
		q->head = q->head->next;
		if (q->head == NULL) //if queue gets empty
			q->tail = NULL;//both front and rear NULL
		free(p);
		return temp;
	}
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
	{
		printf("The Queue is Empty\n");
		return 1;
	}
	else
	{
		return 0;

	}
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	int arr[50]; 
	int queue_size = 0;
	int i = 0;
	while (q->head != NULL)
	{
		arr[i] = dequeue(q); //example: arr[4]={1,2,3,4}
		i++;
		
	}
	//queue is empty
	queue_size = i; //size of arr
	enqueue(q, arr[queue_size - 1]); //last element will be first at the queue
	for (int i = 0; i <= queue_size - 2; i++)
	{
		enqueue(q, arr[i]);
	}
	//queue is full
}

void cutAndReplace(Queue* q)
{
	int sum = 0;
	int arr[50]; //default size
	int queue_size = 0;
	int i = 0;
	while (q->head != NULL)
	{
		arr[i] = dequeue(q); //example: arr[4]={1,2,3,4}
		i++;

	}
	//queue is empty
	queue_size = i; //size of arr
	if (queue_size % 2 !=0) /// Odd size
	{
		for (int i = 0; i < queue_size; i++)
		{
			sum = sum + arr[i];
		}
		int avg = sum / queue_size;
		arr[queue_size] = avg; // now the size is equal
		queue_size++;
    }
	////////////Equal Size ////////////////////
	int* temp_arr = (int*)malloc(queue_size * sizeof(int)); // Temporrary arr for Equal queue_size
	int j = 0;
	for (int i = queue_size - 1; i >= (queue_size / 2); i--) //// filling second half reverse arr
	{
		temp_arr[j] = arr[i];
		j++;
	}
	for (int i = 0; i < (queue_size / 2); i++) /// filling first half regullar arr
	{
		temp_arr[j] = arr[i];
		j++;
	}
	for (i = 0; i < queue_size; i++)
	{
		enqueue(q, temp_arr[i]); /// insert The arr into the Queue
	}
	for (int i = 0; i < queue_size; i++)
	{
		printf("%d ", temp_arr[i]);
	}
}

void sortKidsFirst(Queue* q)
{
	int arr[50]; //default size
	int queue_size = 0;
	int i = 0;
	while (q->head != NULL)
	{
		arr[i] = dequeue(q); //example: arr[4]={1,2,3,4}
		i++;

	}
	//queue is empty
	queue_size = i; //size of arr
	selectionSort(arr, queue_size); //sorting arr from low to high for inserting to the queue
	for (i = 0; i < queue_size; i++)
	{
		enqueue(q, arr[i]); /// insert The sorted arr into the Queue
	}


}