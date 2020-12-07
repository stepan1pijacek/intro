#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "readingFile.h";

/*Tato funkce vybira otazku ze seznamu podle indexu radku ktery ma*/
char* GetNthQuestion(LIST* head, int index) {
	LIST* current = head;
	int count = 0;
	while (current != NULL)
	{
		if (count == index) {
			return(current->string);
		}
		count++;
		current = current->next;
	}
	assert(0);
}
/*Tato funkce vybira odpoved na zaklade indexu ktery ma otazka ze seznamu*/
char* GetNthAnswears(ListOfAnswears* head, int index) {
	ListOfAnswears* current = head;
	int count = 0;
	while (current != NULL)
	{
		if (count == index) {
			return(current->string);
		}
		count++;
		current = current->next;
	}

	assert(0);
}

/*Tato funkce nacte soubor a rovnou ho prepise do linkedlistu. Presneji do LISTu pro otazky*/
char* loadQuestions(const char * filenameOfQuestions) {
	FILE* stream;
	char line[1024];
	char* buffer = NULL;
	LIST* current, * head;
	head = current = NULL;
	errno_t err = fopen_s(&stream, filenameOfQuestions, "r");
	while (fgets(line, sizeof(line), stream))
	{
		LIST* node = NULL;
		node = (LIST*)malloc(sizeof(LIST));
		node->string = _strdup(line);
		node->next = NULL;

		if (head == NULL) {
			current = head = node;
		}
		else{
			current = current->next = node;
		}
	}

	free(buffer);
	buffer = NULL;
	fclose(stream);

	return buffer;
}
/*Tato funkce nacte soubor s odpovedmi a prepise ho do lindelistu*/
char* loadAnswears(const char* filenameOfAnswears) {
	FILE* stream;
	char line[1024];
	char* buffer = NULL;
	ListOfAnswears* current, * head;
	head = current = NULL;
	errno_t err = fopen_s(&stream, filenameOfAnswears, "r");
	while (fgets(line, sizeof(line), stream)) {
		ListOfAnswears* node = NULL;
		node = (ListOfAnswears*)malloc(sizeof(ListOfAnswears));
		node->string = _strdup(line);
		node->next = NULL;

		if (head == NULL) {
			current = head = node;
		}
		else {
			current = current->next = node;
		}
	}

	free(buffer);
	buffer = NULL;
	fclose(stream);

	return buffer;
}

/*Hlavni funkce celeho readingFiles*/
int findQuestion(int index, const char* answear) {
	system("clr");
	char* stringQuestions = loadQuestions("questions.txt");
	char* stringAnswears = loadAnswears("answears.txt");
	int succes = 0;
	LIST* headQuest = NULL;
	ListOfAnswears* headAns = NULL;
	
	printf_s("Otazka zni: %s", GetNthQuestion(headQuest,index));
	
	if (strstr(answear, GetNthAnswears(headAns, index))) {
		printf_s("Spravna odpoved! Postupujete dale");
		succes = 1;
	}
	else {
		printf_s("Nespravna odpoved! zkuste to znovu");
	}
	

	return succes;
}