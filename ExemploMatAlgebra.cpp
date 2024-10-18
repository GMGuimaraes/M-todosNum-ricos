
#include "MatAlgebra.h"

float* JacobiRichardson(float** A, float* b, int n);

int main(){

	int n = 4;
	MatAlgebra g; //Criando um objeto para usar os m�todos do MatAlgebra
	
	float** A = g.criaMatriz(n,n); // Cria uma matriz n x n
	float* b = g.criaVetor(n); // Cria um vetor de tamanho n

	g.leDados(A, b, "ExemploSistemaLinear.in"); //L� os dados do sistema linear (A e b) de um arquivo
	
	g.imprimeMatriz("Matriz A", A, n, n);
	g.imprimeVetor("Vetor b", b, n);
	
	float* x = JacobiRichardson(A, b, n);
	g.imprimeVetor("X:", x, n); //Imprime a solu��o encontrada
	
	g.deletaMatriz(A, n);
	g.deletaVetor(b);
}

// Calcula e Retorna a solu��o do sistema linear Ax=b, de dimens�o n
float* JacobiRichardson(float** A, float* b, int n){
	
	MatAlgebra g; //Criando um objeto para usar os m�todos do MatAlgebra
	
	float* xk  = g.criaVetor(n); // � a solu��o no passo k
	float* xk1 = g.criaVetor(n); // � a solu��o no passo k+1
	
	//Chute Inicial
	g.copiarVetor(xk, b, n);
	
	for(int k=0; k<20; k++){ //n�mero m�ximo de itera��es
		for(int r=0; r<n; r++){ //para cada equa��o do sistema (linha da matriz)
			xk1[r] = b[r];
			for(int j=0; j<n; j++){ //para cada coluna
				if(r!=j) 
					xk1[r] = xk1[r] - A[r][j]*xk[j];	 
			}
			xk1[r] = xk1[r]/A[r][r];
		}
		g.imprimeVetor("xk", xk1, n);
		g.copiarVetor(xk, xk1, n); //copiar xk1 para xk para ir para o pr�ximo passo
	}
	return xk;
}
