#include "MatAlgebra.h"

float** calcFiniteDiff(float* px, float* py, int n);
float poliNewton(float x, float** d, float* px, int n);

int main(){

	MatAlgebra g; //Criando um objeto para usar os métodos do MatAlgebra
	
	int n = 4;
	float* px = g.criaVetor(n);
	float* py = g.criaVetor(n);
	px[0] = -1;  py[0] = 2;
	px[1] = 0;   py[1] = 3;
	px[2] = 2;   py[2] = -1;
	px[3] = 5;   py[3] = 1;
	
	float** d = calcFiniteDiff(px, py, n);
	g.imprimeMatriz("d", d, n, n);
	
	float x = 2.5;
	float p = poliNewton(x, d, px, n);
	printf("\nf(%.3f) = %.6f", x, p);
	
	x = 3.5;
	p = poliNewton(x, d, px, n);
	printf("\nf(%.3f) = %.6f", x, p);	
}

float** calcFiniteDiff(float* px, float* py, int n){
	MatAlgebra g;
	
	float** d = g.criaMatriz(n,n);
	g.inicializaMatriz(d, n, n, 0);
	
	for(int i=0; i<n; i++){
		d[0][i] = py[i];
	}
	for(int k=1; k<n; k++){//cada linha
		for(int i=0; i<n-k; i++){//cada coluna
			d[k][i] = (d[k-1][i+1] - d[k-1][i]) / (px[i+k] - px[i]);
		}	
	}
	return d;
}

float poliNewton(float x, float** d, float* px, int n){
	float p = d[0][0];
	float t = 1;
	for(int i=1; i<n; i++){
		t = t * (x - px[i-1]);
		p = p + d[i][0] * t;
	}
	return p;
}

