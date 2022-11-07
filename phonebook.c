#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
	char number[20];
	char name[20];
	char surname[20];
	char mail[50];
	struct person *sort;

};
typedef struct person list;

list *doPerson(char[], char[],char[], char[]);
void printlist();
void search(char[]);
void delete(int);
list *newperson = NULL;
list *oldperson = NULL;
list *firstperson= NULL;


int main(){
	int a = 0;
	int func;
	while(a != 1)
	{
		system("cls");

	printf("##########################################################\n");
	printf("#                 WELCOME TO THE PHONEBOOK               #\n");
	printf("##########################################################\n");
	printf("\n1.Add\t\t\t2.List\t\t\t 3.Exit \n");
	printf("\n\t  4.Search\t\t\t5.Delete\t\t\t \n");	
		scanf("%d", &func);

		switch (func)
		{
		case 1:
				printf("----------------------------------------------------------\n");
				fflush(stdin) ;
				char gname[20];
				printf("Please enter your name\n");
				fgets(gname, 20, stdin);

				char gsurname[20];
				printf("Please enter your surname\n");
				fgets(gsurname, 20, stdin);

				char mail[50];
				printf("please enter your mail adress\n");
				fgets(mail, 50, stdin);

				char number[20];
				printf("Please enter your phonenumber\n");
				fgets(number, 50, stdin);

				newperson = doPerson(gsurname, gname, mail, number);
				if (firstperson == NULL)
				{
					oldperson = newperson;
					firstperson = newperson;
					newperson -> sort = firstperson;
				}
				else
				{
					oldperson->sort = newperson;
					newperson -> sort = firstperson;
				}
				oldperson = newperson;
				break;

			case 2:
				printlist();
				break;

			case 3:
				a = 1;
				break;

			case 4:
				printf("----------------------------------------------------------\n");
			
				fflush(stdin) ;
				printf("Enter the name of the person you want to find\n");
				char item[50];
				fgets(item, 50, stdin);
				search(item);
				break;

			case 5:
				printf("Enter the name of the person you want to delete\n");
				int location;
				scanf("%d", &location );
				delete(location);
				break;

			default:
				printf("Please select value from 1-5\n");
				break;	
		}	
		if (a==0)
		{
			fflush(stdin) ;		
		printf("Press enter to back main menu");
		char go = getchar();
		}
		func = 0;
	}
	return 0;
}

list *doPerson(char surnamec[], char namec[],char mailc[],char numberc[20]){
	list *newperson = (list*)malloc(sizeof(list));
	strcpy(newperson->surname,surnamec);
    strcpy(newperson->name,namec);
	strcpy(newperson->mail,mailc);
	strcpy(newperson -> number , numberc);
	
	return newperson;
}
void printlist(){
	list *temp = firstperson;

	if (temp== NULL)
	{
		printf("bu telefon defteri boş\n");
	}
	else{
	do{
		printf("----------------------------------------------------------\n");
		printf(" %s %s %s %s \n ", temp -> name , temp ->surname, temp->mail, temp->number);
		temp = temp -> sort;
	}while(temp != firstperson);
	}
}

void search(char aranan[]){
	list *temp = firstperson;
	int sheep = 1;     //Bence komik
	do{
		int balance;
		const char *cp1 = aranan;
  		const char *cp2 = temp->name;
		balance = !strcmp(cp1, cp2);

		if(balance == 1){
			printf("%d.person :  %s  \n",sheep, aranan);
			return;
		}
		temp = temp -> sort;
		sheep++;
	}while(temp != firstperson);
	printf("this person does not exist: %s\n", aranan);
}

void delete(int location){
	int i = 1;  

	list *runner = firstperson;
	list *pin1 ;
	list *pin2 = firstperson;
	do{
		if (location==1)
		{
			while(runner -> sort != pin2)
			runner = runner -> sort;
			runner -> sort = pin2 -> sort;
			firstperson = pin2 -> sort;
			free(pin2);
		}
		else if (i==location-1)
		{

			pin1 = runner -> sort -> sort;
			runner->sort = pin1;
			runner = pin1;
			
		}
		else{
			runner = runner -> sort;
			
		}
		i++;
	}while(runner->sort!=firstperson);
}
