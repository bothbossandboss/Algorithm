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
int nowStudentNum = 0;

StudentData refer_data(int i){
	assert(i >= 0 && i < nowStudentNum);
	return studentArray[i];
}

void insert_data(int position, StudentData data){
	assert(nowStudentNum < MAX_STUDENT_COUNT);
	//1つずつ後ろへずらす
	for(int i=nowStudentNum;i>position;i--){
		studentArray[i] = studentArray[i-1];
	}
	studentArray[position] = data;
	nowStudentNum++;
}

int main(int argc, char *argv[]){
	srand((unsigned)time(NULL));
	nowStudentNum = rand() % MAX_STUDENT_COUNT + 1;
	printf("first : %d\n", nowStudentNum);
	for(int i=0;i<nowStudentNum;i++){
		char c = 65 + i;
		studentArray[i].id = i;
		studentArray[i].name = &c;
		studentArray[i].score = rand() % 100;
	}
	StudentData s = refer_data(rand() % nowStudentNum);
	printf("%d, %s => %d\n\nbefore insert\n", s.id, s.name, s.score);
	int position = rand() % nowStudentNum;
	for(int i= position-1;i<position+2;i++){
		printf("%d, %c => %d\n", studentArray[i].id, studentArray[i].name, studentArray[i].score);
	}
	StudentData sample;
	sample.id = 1000;
	sample.name = "yasuhito";
	sample.score = 100;
	printf("\nafter insert\n");
	insert_data(position, sample);
	for(int i= position-1;i<position+2;i++){
		printf("%d, %c => %d\n", studentArray[i].id, studentArray[i].name, studentArray[i].score);
	}
	return 0;
}