#include <iostream>
#include <fstream>
#include <cmath>

class MatAlgebra
{
public:
	
	MatAlgebra() { } //construtor
	~MatAlgebra() { } //destrutor
	
	//Cria e retorna uma matriz de dimensão n x m
	float** criaMatriz(int n, int m) {
		float **matriz = new float *[n];
		for (int i = 0; i < n; i++) {
			matriz[i] = new float[m];
		}
		return matriz;
	}
	
	//Libera da memória uma matriz de n linhas
	void deletaMatriz(float **matriz, int n) {
		for (int i = 0; i < n; i++)
			delete(matriz[i]);
		delete(matriz);
	}
	
	//Cria e retorna um vetor de dimensão n
	float* criaVetor(int n) {
		return new float[n];
	}
	
	//Libera da memória um vetor de n posições
	void deletaVetor(float *vetor) {
		delete(vetor);
	}

	void inicializaVetor(float *vetor, int n, int v){
		for (int i=0;i<n;i++)
			vetor[i] = v;
	}

	void copiarVetor(float *vetorDest, float *vetorOrig, int n){
		for (int i=0;i<n;i++)
			vetorDest[i] = vetorOrig[i];
	}
	
	//Lê os dados de uma matriz e um vetor de um arquivo texto
	void leDados(float **A, float *b, const char* fileName) {
		int n,m;
		
		std::ifstream inFile(fileName);
		//reading A
		inFile >> n;
		inFile >> m;
		
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				inFile >> A[i][j];
		//reading b
		inFile >> n;
		for (int i=0;i<n;i++)
			inFile >> b[i];
		inFile.close();
	}
	
	//Lê os dados de duas matrizes de um arquivo texto
	void leDados(float **A, float **B, const char* fileName) {
		int n,m;
		std::ifstream inFile(fileName);
		//reading A
		inFile >> n;
		inFile >> m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				inFile >> A[i][j];
		//reading B
		inFile >> n;
		inFile >> m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				inFile >> B[i][j];
		inFile.close();
	}
	
	void imprimeMatriz(const char* nome, float** matriz, int n, int m) {
		printf("\n%s:\n", nome);
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++)
				printf("%.4f ", matriz[i][j]);
			printf("\n");
		}
	}

	void imprimeVetor(const char* nome, float* vetor, int n) {
		printf("\n%s:\n", nome);
		for (int i=0;i<n;i++)
			printf("%.8f ", vetor[i]);
	}
	
	
};


