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
	int sum = 0;
	for(int i=0;i<MAX_STUDENT_COUNT;i++){
		min = i;
		for(int j=i+1;j<MAX_STUDENT_COUNT;j++){
			sum++;
			if(Data[min] > Data[j]) min = j;
		}
		if(min != i) mySwap(Data, min, i);
	}
	printf("sum = %d\n", sum);
	return;
}

void insertionSort(int Data[], int n){
	int beginPlace, comparePlace;
	// 比較を始める位置を 1 から順番に n - 1 まで動かしていく
	for(beginPlace = 1;beginPlace < n;beginPlace++){
		int x = Data[beginPlace];
		//以下のループをスルーする間はソート済みである。
		for(comparePlace = beginPlace - 1;comparePlace >= 0 && x < Data[comparePlace];comparePlace--){
			//挿入位置が見つかるまで配列をずらす。
			Data[comparePlace+1] = Data[comparePlace];
		}
		if(comparePlace != beginPlace -1){
			//挿入しソート済み部分を更新
			Data[comparePlace+1] = x;
		}
	}
}

void check(int data1[], int data2[], int n){
	int c = 0;
	for(int i=0;i<n;i++){
		if(data1[i] == data2[i]) c++;
	}
	if(c == n){
		printf("equal\n");
	}else{
		printf("not equal\n");
	}
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
//	printData(data);
	//selectionSort(another, MAX_STUDENT_COUNT);
	insertionSort(another, MAX_STUDENT_COUNT);
//	printData(another);
	check(data, another, MAX_STUDENT_COUNT);
	return 0;
}