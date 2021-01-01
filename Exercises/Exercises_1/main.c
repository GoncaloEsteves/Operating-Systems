#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guiao00.h"

int main(){
	Person joao = new_person("Joao", 16);
	printf("idade anterior Joao %d\n", joao.age);

	person_change_age(&joao, 27);
	printf("idade modificada andre %d\n", joao.age);

	Person new_joao = clone_person(&joao);

	person_change_age(&new_joao, 45);
	printf("idade joao %d\n", joao.age);
	printf("idade new_joao %d\n", new_joao.age);

	destroy_person(&new_joao);
	destroy_person(&joao);
}