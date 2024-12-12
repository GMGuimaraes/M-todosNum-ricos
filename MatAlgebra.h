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
	
	void inicializaMatriz(float ** matriz, int n, int m, int v){
		for (int i=0;i<n;i++)
			inicializaVetor(matriz[i], m, v);
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

	//Lê os dados de uma matriz de um arquivo texto
	void leDados(float **A, const char* fileName) {
		int n,m;
		
		std::ifstream inFile(fileName);
		//reading A
		inFile >> n;
		inFile >> m;
		
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				inFile >> A[i][j];
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
	//Retorna verdadeiro caso o erro relativo entre os dois vetores 
	//seja menor que a precisão err. E falso caso contrário.
	bool testErroRelativo(float *x0, float *x1, int n, float err){
		
		float maiorElemX1 = 0; 
		float maiorDiff = 0; 
		for (int i=0;i<n;i++){
			float diff = fabs(x0[i]-x1[i]);
			//Calcula a maior diferença absoluta entre os vetores x0 e x1
			maiorDiff = fmax(maiorDiff, diff);
			//Calcula o maior elemento de x1
			maiorElemX1 = fmax(maiorElemX1, fabs(x1[i]));
		}
		
		if(maiorDiff/maiorElemX1 < err)
			return true;
		
		return false;
	}	
	
	//multiplica duas matrizes quadradas de dimensão n
	float** multiplica(float** A, float** B, int n){
		float** C = criaMatriz(n, n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				float s = 0;
				for(int k=0; k<n; k++){
					s += A[i][k]*B[k][j];
				}
				C[i][j] = s;
			}
		}
		return C;
	}	
};


