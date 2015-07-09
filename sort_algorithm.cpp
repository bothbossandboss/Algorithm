#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>

#define MAX_STUDENT_COUNT 100

using namespace std;

void Swap(int data[], int a, int b){
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

void BubbleSort(int Data[], int n){
	int BeginPlace, ComparePlace;
	// 比較を始める位置を最初から n-1 まで変えていく
	for(BeginPlace = 0;BeginPlace < n;BeginPlace++){
		//n - BeginPlace まで比較する
		for(ComparePlace = 1;ComparePlace < n - BeginPlace;ComparePlace++){
			// 右のほうが小さかったら交換する
			if(Data[ComparePlace - 1] > Data[ComparePlace]){
				Swap(Data, ComparePlace-1, ComparePlace);
			}
		}
	}
	return;
}

int main(int argc, char *argv[]){
	srand((unsigned)time(NULL));
	int data[MAX_STUDENT_COUNT];
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		data[i] = rand() % MAX_STUDENT_COUNT;
	}
	BubbleSort(data, MAX_STUDENT_COUNT);
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}