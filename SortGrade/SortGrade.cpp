#define _CRT_SECURE_NO_WARNINGS //struct function loop2loop expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PERSON {
	char name[50];
	int score;
	char grade;
	int pos;//Position
	char tempName[50]; 
};
int main() {
	struct PERSON* persons;
	int n,choice; //choice 1 = sort by name ,choice 2 = sort by score 
	int i, j, temp,compare;
	printf("Grade calculator");
	printf("How many students you have ? \n");
	scanf("%d", &n);
	persons = (struct PERSON*)malloc(n * sizeof(struct PERSON));
	for (int i = 0;i < n;i++) {
		printf("Enter name  %d : ",i+1);
		scanf("%s", persons[i].name);
		printf("Enter score %d : ",i+1);
		scanf("%d", &persons[i].score);
	}
	for (int k = 0;k < n;k++) {
		if (persons[k].score > 79 && persons[k].score < 101) {
			persons[k].grade = 'A';
		}
		else if (persons[k].score > 69 && persons[k].score < 80) {
			persons[k].grade = 'B';
		}
		else if (persons[k].score > 59 && persons[k].score < 70) {
			persons[k].grade = 'C';
		}
		else if (persons[k].score > 49 && persons[k].score < 60) {
			persons[k].grade = 'D';
		}
		else if (persons[k].score < 50 && persons[k].score >= 0 ) {
			persons[k].grade = 'F';
		}
		else {
			persons[k].grade = 'X'; // this person doesn't have grade
		}

	}
jumper:
	printf("\nchoice 1 = sort by name ,choice 2 = sort by score ");
	scanf("%d", &choice);
	if (choice == 1) {
		for (i = 0;i < n;i++) {
			for (j = i + 1;j < n;j++) {
				compare = strcmp(persons[i].name, persons[j].name);
				if (compare > 0 ) {
					strcpy(persons[i].tempName, persons[i].name);
					strcpy(persons[i].name, persons[j].name);
					strcpy(persons[j].name, persons[i].tempName);
					temp = persons[i].score;
					persons[i].score = persons[j].score;
					persons[j].score = temp;
				}
			}
		}
		for (int k = 0;k < n;k++) {
			printf("%s score : %d Grade : %c\n", persons[k].name, persons[k].score, persons[k].grade);
		}
	}
	else if(choice ==2) {
		for (i = 0;i < n;i++) {
			for (j = i + 1;j < n;j++) {
				if (persons[i].score > persons[j].score) {
					temp = persons[i].score;
					persons[i].score = persons[j].score;
					persons[j].score = temp;
					strcpy(persons[i].tempName, persons[i].name);
					strcpy(persons[i].name, persons[j].name);
					strcpy(persons[j].name, persons[i].tempName);
				}
			}
		}
		for (int k = 0;k < n;k++) {
			printf("\n%s \tScore : %d \tGrade : %c", persons[k].name, persons[k].score,persons[k].grade);
			
		}
	
	}
	else {
		goto jumper;
	}
	return 0;
}