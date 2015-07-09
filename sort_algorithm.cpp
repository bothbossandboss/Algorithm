#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>

#define MAX_STUDENT_COUNT 100

using namespace std;

void makeData(int data[]){
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		data[i] = rand() % MAX_STUDENT_COUNT;
	}
}

void printData(int data[]){
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}

void mySwap(int data[], int a, int b){
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

void bubbleSort(int Data[], int n){
	int beginPlace, comparePlace;
	// 比較を始める位置を最初から n-1 まで変えていく
	for(beginPlace = 0;beginPlace < n;beginPlace++){
		//n - beginPlace まで比較する
		for(comparePlace = 1;comparePlace < n - beginPlace;comparePlace++){
			// 右のほうが小さかったら交換する
			if(Data[comparePlace - 1] > Data[comparePlace]){
				mySwap(Data, comparePlace-1, comparePlace);
			}
		}
	}
	return;
}

void selectionSort(int Data[], int n){
	int min;
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		min = i;
		for(int j=i+1;j<MAX_STUDENT_COUNT;j++){
			if(Data[min] > Data[j]) min = j;
		}
		mySwap(Data, min, i);
	}
	return;
}

int main(int argc, char *argv[]){
	srand((unsigned)time(NULL));
	int data[MAX_STUDENT_COUNT];
	int another[MAX_STUDENT_COUNT];
	makeData(data);
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		another[i] = data[i];
	}
	bubbleSort(data, MAX_STUDENT_COUNT);
	printData(data);
	selectionSort(another, MAX_STUDENT_COUNT);
	printData(another);
	return 0;
}