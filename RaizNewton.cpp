#include<stdio.h> //Funções scanf e printf
#include<math.h>

int main(){
	
	//Leitura do valor do teclado
	double y;
	printf("Digite um número real: ");
	scanf("%lf", &y); //Valor lido é armazenado em y
		
	double x0 = y/2; //primeira aprox. Newton
	double x1;
	
	double tol = 0.0000001; //tolerância - precisão desejada
	int max_it = 50; //número máximo de iterações
	int it = 1; //iteração atual
	//Repetir até atingir o número máximo de iterações
	while(it <= max_it){
		x1 = (x0*x0 + y) / (x0*2); //aprox. Newton
		double eRel = fabs(x1-x0)/x1;
		printf("\nValor %d: %.15f %.15f", it, x1, eRel);
		//teste para avaliar o erro e a tolerância
		if(eRel < tol){
			break; //sair do laço imediatamente
		}
		x0 = x1;
		it++; //it = it + 1;
	}
	printf("\nRaiz Quadrada de %f é %.15f", y, x1);
}


//double prec = 0.001;
	
//double diff = x1-x0;
//if(diff < prec && diff > -prec){
//			break; //chegou na precisão solicitada
//		}
