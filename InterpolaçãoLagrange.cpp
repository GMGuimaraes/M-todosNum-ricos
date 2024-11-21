#include "MatAlgebra.h"

float poliLagrange(float x, float* px, float* py, int n);
float Li(int i, float x, float* px, int n);

int main(){

	MatAlgebra g; //Criando um objeto para usar os métodos do MatAlgebra
	
	int n = 4;
	float* px = g.criaVetor(n);
	float* py = g.criaVetor(n);
	px[0] = -1;  py[0] = 2;
	px[1] = 0;   py[1] = 3;
	px[2] = 2;   py[2] = -1;
	px[3] = 5;   py[3] = 1;
	
	float x = -5;
	
	//x = [-5,5] de 0.1
	for(int i=0; i<101; i++){
		float p = poliLagrange(x, px, py, n);	
		//printf("P3(%.6f) = %.6f", x, p);
		printf("%.3f ; %.3f\n", x, p);
		x = x + 0.1;
	}
}

float poliLagrange(float x, float* px, float* py, int n){
	float p = 0;
	for(int i=0; i<n; i++){
		p = p + py[i] * Li(i, x, px, n);
	}
	return p;	
}

float Li(int i, float x, float* px, int n){
	float num = 1;
	float den = 1;
	for(int k=0; k<n; k++){
		if(k!=i){
			num = num * (x - px[k]);
			den = den * (px[i] - px[k]);
		}
	}
	return num/den;	
}

