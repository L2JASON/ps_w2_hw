#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct.h"
extern char kname[2][10];
// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list
void saveAllClasses(struct st_class* c[], int csize); // Save all class list