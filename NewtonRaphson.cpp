#include<stdio.h> //Funções scanf e printf
#include<math.h>

double f(double x){
	return 2*x*x*x + 3*x*x - 7*x + 5;
}

double der_f(double x){
	return 6*x*x + 6*x - 7;
}

int main(){

	double x0 = -2; //chute inicial
	double x1 = 0;
	double tol = 0.000001; //tolerância - precisão desejada

	printf("f(%.6f) = %.6f \n", x0, f(x0));
		
	for(int i=0; i<50; i++){
		
		//Fórmula de Newton-Raphson
		x1 = x0 - (f(x0) / der_f(x0));
			
		printf("f(%.6f) = %.6f \n", x1, f(x1));
		
		double eRel = fabs((x1-x0)/x1);
		if(eRel < tol){
			break; //sair do laço imediatamente
		}
		x0 = x1;
	}
	printf("A raiz aproximada eh: %.6f", x1);
}
