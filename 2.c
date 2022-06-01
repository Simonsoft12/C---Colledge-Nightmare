#include "studenci.h"

student_t* wypelnij()
{
	student_t* student = malloc(sizeof(student_t));
	
	printf("Imie studenta: ");
	scanf("%s",student->tab_imie);
	
	printf("Nazwisko studenta: ");
	scanf("%s",student->tab_nazwisko);
	
	printf("Numer albumu studenta: ");
	scanf("%s",student->tab_album);
	
	return student;
}

void wyswietl_pamiec(student_t *student){
printf("%ld\n",sizeof(student));

}
void zwolnij_pamiec(student_t *student){
  free(student);
}


