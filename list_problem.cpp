/**
 * 学際情報学府2010年度,問A3解答
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>

typedef struct list{
	int v;
	struct list * next;
} List;

void printList(List *first){
	List *p = first;
	do{
		printf("%d -> ", p->v);
	}while((p=p->next) != NULL);
	printf("end\n");
}

List *reverse(List *list){
	List *q, *pre;
	pre = (List*)malloc(sizeof(List*));
	pre->v = list->v;
	pre->next = NULL;
	q = list;
	while((q = q->next) != NULL){
		List *now = (List*)malloc(sizeof(List*));
		now->v = q->v;
		now->next = pre;
		pre = now;
	}
	return pre;
}

int main(int argc, char *argv[]){
	List *first, *second, *third;
	first = (List *)malloc(sizeof(List));
	second = (List *)malloc(sizeof(List));
	third = (List *)malloc(sizeof(List));
	first->v = 1;
	first->next = second;
	second->v = 3;
	second->next = third;
	third->v = 2;
	third->next = NULL;
	printList(first);
	List *result = reverse(first);
	printList(result);
	return 0;
}