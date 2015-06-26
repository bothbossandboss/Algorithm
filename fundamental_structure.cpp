#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>

#define MAX_STUDENT_COUNT 100
using namespace std;

struct student_data{
	int id;
	char *name;
	int score;
};

typedef struct student_data StudentData;

StudentData studentArray[MAX_STUDENT_COUNT];

StudentData refer_data(int i){
	assert(i >= 0 && i < MAX_STUDENT_COUNT);
	return studentArray[i];
}

int main(int argc, char *argv[]){
	srand((unsigned)time(NULL));
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		char c = 65 + i;
		studentArray[i].id = i;
		studentArray[i].name = &c;
		studentArray[i].score = rand() % 100;
	}
	StudentData s = refer_data(rand() % MAX_STUDENT_COUNT);
	printf("%d, %s => %d\n", s.id, s.name, s.score);
	return 0;
}