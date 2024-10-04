#include<stdio.h> //Fun��es scanf e printf
#include<math.h>

int main(){
	
	//Leitura do valor do teclado
	double y;
	printf("Digite um n�mero real: ");
	scanf("%lf", &y); //Valor lido � armazenado em y
		
	double x0 = y/2; //primeira aprox. Newton
	double x1;
	
	double tol = 0.0000001; //toler�ncia - precis�o desejada
	int max_it = 50; //n�mero m�ximo de itera��es
	int it = 1; //itera��o atual
	//Repetir at� atingir o n�mero m�ximo de itera��es
	while(it <= max_it){
		x1 = (x0*x0 + y) / (x0*2); //aprox. Newton
		double eRel = fabs(x1-x0)/x1;
		printf("\nValor %d: %.15f %.15f", it, x1, eRel);
		//teste para avaliar o erro e a toler�ncia
		if(eRel < tol){
			break; //sair do la�o imediatamente
		}
		x0 = x1;
		it++; //it = it + 1;
	}
	printf("\nRaiz Quadrada de %f � %.15f", y, x1);
}


//double prec = 0.001;
	
//double diff = x1-x0;
//if(diff < prec && diff > -prec){
//			break; //chegou na precis�o solicitada
//		}
