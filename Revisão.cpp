#include<stdio.h>
#include<limits>

int main(){
	//Quantidade de Bytes do Tipo int
	printf("Bytes: %d", sizeof(short));
	//Número mínimo do tipo int
	printf("\n Min: %d", std::numeric_limits<short>::min());
	//Número máximo do tipo int
	printf("\n Max: %d", std::numeric_limits<short>::max());

	int a = 5000000;
	short b = a;
	
	printf("\n\nb = %d",b);

	int idade, peso;
	float altura;
	
	printf("\nDigite a idade, a altura e o peso, separados por um espaço em branco.\n");
	scanf("%d%f%d", &idade, &altura, &peso);

	printf("\nIdade: %d", idade);
	printf("\nAltura: %.2f", altura);
	printf("\nPeso: %d", peso);
}
















	
//	int idade;
//	printf("\nDigite a idade: ");
//	scanf("%d", &idade);
	
	
//	int a = 5;
//	int b = ++a;
	
	
	
	
	
//}

//https://dontpad.com/MNC
