/**
 * 電気系工学専攻2010年度,第11問解答
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>

#define VALUE 0
#define PLUS 1

typedef struct node{
	int k;
	int val;
	struct node *left;
	struct node *right;
	char name;
} Node;

int count = 0;

int calc(Node *t){
	printf("%c -> ", t->name);
	int v1, v2, r;
	switch(t->k){
		case VALUE:
			r = t->val;
			break;
		case PLUS:
			v1 = calc(t->left);
			v2 = calc(t->right);
			t->k = VALUE;
			printf("(change at %c)", t->name);
			t->val = v1 + v2;
			count++;
			r = t->val;
			break;
	}
	return r;
}

int main(int argc, char *argv[]){
	Node *A, *B, *C, *D, *E, *F, *G;
	A = (Node *)malloc(sizeof(Node));
	B = (Node *)malloc(sizeof(Node));
	C = (Node *)malloc(sizeof(Node));
	D = (Node *)malloc(sizeof(Node));
	E = (Node *)malloc(sizeof(Node));
	F = (Node *)malloc(sizeof(Node));
	G = (Node *)malloc(sizeof(Node));

	A->k = PLUS;
	A->left = C;
	A->right = B;
	A->name = 'a';

	B->k = PLUS;
	B->left = C;
	B->right = D;
	B->name = 'b';

	C->k = PLUS;
	C->left = E;
	C->right = D;
	C->name = 'c';

	D->k = PLUS;
	D->left = F;
	D->right = G;
	D->name = 'd';

	E->k = VALUE;
	E->val = 3;
	E->name = 'e';

	F->k = PLUS;
	F->left = G;
	F->right = E;
	F->name = 'f';

	G->k = VALUE;
	G->val = 4;
	G->name = 'g';

	int r = calc(A);
	printf("\nresult = %d\n", r);
	printf("count = %d\n", count);
	return 0;
}