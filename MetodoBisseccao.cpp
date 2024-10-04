#include<stdio.h> //Funções scanf e printf
#include<math.h>

double f(double x){
	return 2*x*x*x + 3*x*x - 7*x + 5;
}

int main(){

	//Encontrar um intervalo contendo uma raiz
	for(int x=-10; x<=10; x++){
		printf("f(%d) = %.1f \n", x, f(x));
	}
	
	//intervalo obtido pela análise de resultado de valores acima
	double a = -3;
	double b = -2;
	double x;
	double tol = 0.000001; //tolerância - precisão desejada
		
	printf("  a                     x                        b\n");	
	for(int i=0; i<50; i++){
		
		x = (a+b)/2;

		printf("f(%.6f)=%.6f    f(%.6f)=%.6f    f(%.6f)=%.6f \n", a, f(a), x, f(x), b, f(b));
		
		if(f(x) == 0){ //encontrei a raiz
			break;
		} 
		else if( f(a)*f(x) < 0 ){ //raiz está entre [a, x]
			b = x;
		}
		else if( f(b)*f(x) < 0 ){ //raiz está entre [x, b]
			a = x;
		}
		
		double eRel = fabs((a-b)/b);
		if(eRel < tol){
			break; //sair do laço imediatamente
		}
	}
	printf("A raiz aproximada eh: %.6f", x);
}
