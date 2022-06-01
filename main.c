#include "studenci.h"
#include "2.c"

int main()
{


student_t *student1 = wypelnij();


printf("Imie studenta : %s\nNazwisko studenta : %s\nNr albumu studenta : %s\n",
student1->tab_imie,student1->tab_nazwisko,student1->tab_album);

wyswietl_pamiec(student1);
zwolnij_pamiec(student1);


  return 0;
}
