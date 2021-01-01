#include <stdio.h>
#include "guiao00.h"
#include <stdlib.h>
#include <string.h>

Person new_person(char* name, int age){
	size_t n = strlen(name) + 1;
	char* s = malloc(sizeof(char[n]));
	memcpy(s, name, n);
	return (Person){
		.name = s;
		.age = age;
	}
}

Person clone_person(Person* p){
	Person aux = malloc(sizeof(struct person));
	aux.name = strdup(p->name);
	aux.age = p->age;
	return aux;
}

void destroy_person(Person* p){
	free(p->name); //unica memoria allocada
}

int person_age(Person *p){
	return (p->age);
}

void person_change_age(Person* p, int age){
	p->age = age;
}