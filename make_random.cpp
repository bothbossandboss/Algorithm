#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define OUTPUT "result/exponential_random.dat"
#define MAX_TURN 10000
unsigned int M = 2147483647;

using namespace std;
/**
 * 一様分布(出力確率が全て1)で0〜1の乱数を出力
 */
double uniformRand(){
	return ( (double)rand() + 1.0 ) / ( (double)RAND_MAX + 2.0 );
}
/**
 * 平均mu、標準偏差sigmaの正規分布に従って乱数を出力
 * cos型、sin型両方用意したが、どちらを使っても構わない。
 */
double gaussRandCos(double mu, double sigma){
	double z1 = sqrt( -2.0 * log(uniformRand()) ) * cos( 2.0 * M_PI * uniformRand() );
	return sigma * z1 + mu;
}

double gaussRandSin(double mu, double sigma){
	double z2 = sqrt( -2.0 * log(uniformRand()) ) * sin( 2.0 * M_PI * uniformRand() );
	return sigma * z2 + mu;
}

/**
 * 線形合同法(Linear Congruential Generator)を用いた方法
 * x:乱数の初期値、N:データ数、m:データ範囲。0〜m-1の整数乱数を発生させる。
 */
void linearRandom(int x, int m, unsigned int data[], int N){
	int a = 1103515245;
	int b = 12345;
	data[0] = (x * a + b) % m;
	for(int i=1;i<N;i++){
		data[i] = (data[i-1] * a + b) % m;
	}
}

double exponentialRandom(double lamda){
	return log(lamda / uniformRand()) / lamda;
}

int dice(){
	return (int)(uniformRand() * 1000.0) % 6 + 1;
}

int main(int argc, char *argv[]){
	int i;
	FILE *output;
	if( (output = fopen(OUTPUT, "w")) == NULL ){
		perror("open output file");
		return -1;
	}
	srand((unsigned int)time(NULL));
	for(i=0;i<MAX_TURN;i++){
		double x = exponentialRandom(1.0);
		double y = exponentialRandom(1.0);
		fprintf(output, "%f %f\n", x, y);
	}
	return 0;
}