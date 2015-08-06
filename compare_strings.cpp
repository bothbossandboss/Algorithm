#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>

#define MAX_STUDENT_COUNT 1000
#define MAX_TURN 1000

using namespace std;

void makeTable(char *pattern, int *table){
	int i, j, k;
	int m = strlen(pattern);
	table[0] = table[1] = 1;
	for(i=2;i<m;i++){
		for(j=1;j<i;j++){
			for(k=j;k<i;k++){
				if(pattern[k] != pattern[k-j]) break; //パターン中のk番目の文字と、そこから何文字前が同じかどうか調べる。
			}
			if(k == i) break;//j文字の同じ文字列がパターン中に連続している場合
		}
		table[i] = j;
	}
}

void printTable(char *pattern, int *table, int length){
	for(int i=0;i<length;i++){
		printf("%d ", i);
	}
	printf("\n");
	for(int i=0;i<length;i++){
		printf("%c ", pattern[i]);
	}
	printf("\n");
	for(int i=0;i<length;++i){
		printf("%d ", table[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	char *p = argv[1];
	int l = strlen(p);
	int t[l];
	makeTable(p, t);
	printTable(p, t, l);
	return 0;
}