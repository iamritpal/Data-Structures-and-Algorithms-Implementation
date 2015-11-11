//******************************************************************
//	Filename - FIFOCircularBuffer.c
//	Software Engineer - Amritpal Singh
//	Description - Simple implementation of FIFO queue on a circular
//				  buffer in C programming language.
//				  It is same as Array Based FIFO Queue implementation.
//	Date - 11/06/2015
//******************************************************************

#include <stdio.h>
#include <stdlib.h>

#define cbuff_size 20

int nmbItems=0;

int cbuff_pix = 0;		// Circular buffer put index
int cbuff_gix = 0;		// Circular buffer get index

int circularBuffer[cbuff_size];		// Simple integers circular buffer

int put_in_que(int value);		// Put a value into queue if space is available
int get_from_que(int* ptr);		// Get next value from queue if it exists

int main(void)
{
	int i;
	int value=0;

	// Try to insert 25 values
	for (i=0;i<=25;i++)
	{
		if (put_in_que(i) != 0)
			printf("Successfully added %d to queue.\n", i);
		else
			printf("Error, queue full, couldn't add %d to queue.\n", i);
	}

	// Get inserted values from queue
	for (i=0;i<=100;i++)
	{
		if (get_from_que(&value) != 0)
			printf("%d ", value);
	}
	return 0;
}

//************************************************
//	Puts a new value into queue.
//	Argument: 
//		@value - Number you want to add to queue
//	Returns:
//		0 = Couldn't added value to queue
//		1 = Successfully added value to queue
//************************************************

int put_in_que (int value)
{
	if (nmbItems != cbuff_size)		// Circular buffer is not full
	{
		cbuff_pix++;
		if (cbuff_pix >= cbuff_size)
			cbuff_pix = 0;
		circularBuffer[cbuff_pix] = value;
		nmbItems++;
		return(1);
	}
	return(0);
}

//************************************************
//	Gets a value from queue.
//	Argument:
//		@ptr - Integer pointer points to integer 
//			   variable which gets set to value dequeued
//	Returns:
//		0 = Circular buffer is empty
//		1 = Successfully dequeued a value from 
//		    circular buffer
//
//************************************************

int get_from_que (int* ptr)
{
	if (nmbItems != 0)				// Circular buffer is not empty
	{
		cbuff_gix++;
		if (cbuff_gix >= cbuff_size)
			cbuff_gix = 0;
		*ptr = circularBuffer[cbuff_gix];
		nmbItems--;
		return(1);
	}
	return(0);
}

