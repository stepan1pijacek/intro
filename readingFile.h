#pragma once
struct list 
{ 
	char* string; 
	struct list* next; 
};
typedef struct list LIST;

struct listOfAnswears
{
	char* string;
	struct listOfAnswears* next;
};
typedef struct listOfAnswears ListOfAnswears;

int findQuestion(int index, const char* answear);
