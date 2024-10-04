#include<stdio.h> //Fun��es scanf e printf
#include<math.h>

double f2(double x){
	return x*x*x + 3*x*x - 4*x + 6;
}

double f(double x){ //Exerc�cio Slide
	return sqrt(x) - 5*exp(-x);
}

int main(){

	double x0 = 1.2; //chute inicial
	double x1 = 1.6; //chute inicial
	double x2 = 0;
	double tol = 0.0001; //toler�ncia - precis�o desejada

	printf("** f(%.6f) = %.6f      \n** f(%.6f) = %.6f \n", x0, f(x0), x1, f(x1));
		
	for(int i=0; i<50; i++){
		
		//F�rmula de Secantes
		x2 = x1 - (f(x1)*(x1-x0)) / (f(x1)-f(x0));
			
		printf("%d: f(%.6f) = %.6f \n", i+2, x2, f(x2));
		
		double eRel = fabs((x2-x1)/x2);
		if(eRel < tol){
			break; //sair do la�o imediatamente
		}
		//Atualizando valores para a pr�xima itera��o
		x0 = x1;
		x1 = x2;
	}
	printf("A raiz aproximada eh: %.6f", x2);
}
