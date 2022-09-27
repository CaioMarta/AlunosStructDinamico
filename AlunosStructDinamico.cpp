#include "stdio.h"
#include "stdlib.h"

struct Alunos
{
	char nome[30];
	float nP1, nP2, nT, media;
};

void mediaAlunos (struct Alunos *f, int qtdeAlunos);
void mostrar (struct Alunos *f, int i);
void lerDados (struct Alunos *f, int redim, int qtdeAlunos, int i);

int main()
{
	struct Alunos *f;
	int qtdeAlunos, i, redim;
	char op;
	
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &qtdeAlunos);
	
	f = (struct Alunos *) malloc(qtdeAlunos * sizeof(struct Alunos));
	if(f == NULL){
		printf("Memoria insulficiente ");
		exit(1);
	} 
	else{
		for(i = 0; i < qtdeAlunos; i++)
		{
			printf("\n DADOS DO ALUNO %d", i + 1);
			
 			printf("\n Digite o nome do aluno: ");
    		scanf("%s", f[i].nome);
        	
        	printf("\n Digite a nota da P1: ");
        	scanf("%f", &f[i].nP1);
        	
        	printf("\n Digite a nota da P2: ");
        	scanf("%f", &f[i].nP2);
        	
        	printf("\n Digite a nota de trabalho: ");
        	scanf("%f", &f[i].nT);
		}	
	}
	
	mediaAlunos(f, qtdeAlunos);
	
	printf("\n Deseja alterar a quantidade de alunos? (s/n) ");
	scanf(" %c", &op);
	
	if(op == 's' || op == 'S')
	{
		lerDados(f, redim, qtdeAlunos, i);
	}

	return 0;
}

void mediaAlunos (struct Alunos *f, int qtdeAlunos){
	for(int i = 0; i < qtdeAlunos; i++){
		f[i].media = ((f[i].nP1 * 2) + (f[i].nP2 * 3) + f[i].nT) / 6;
		mostrar(f,i);
	}
}

void mostrar (struct Alunos *f, int i){
		
	if(f[i].media >= 7){
		printf("\n %s foi aprovado com media = %.2f \n", f[i].nome, f[i].media);
	}
	else
	{
		printf("\n %s foi reprovado com media = %.2f \n", f[i].nome, f[i].media);
	}
}

void lerDados (struct Alunos *f, int redim, int qtdeAlunos, int i)
{
	printf("\n Digite um nro positivo OU negativo para a nova quantidade de alunos que deseja incluir OU excluir ");
		scanf("%d", &redim);
		if(qtdeAlunos + redim == 0)
		{
			printf(" Nao sobrou aluno na turma! ");
			exit(1);
		}
		else if(qtdeAlunos + redim < 0)
		{
			printf(" ERRO ");
		}
		else // Redimensionar o vetor
		{
			f = (struct Alunos *) realloc(f, (qtdeAlunos + redim) * sizeof(struct Alunos));
			if(redim > 0)
			{
				// Incluir dados dos Alunos que serão adicionados ao vetor
				for(i = qtdeAlunos; i < (qtdeAlunos + redim); i++)
				{
						printf("\n DADOS DO ALUNO %d", i + 1);
			
 						printf("\n Digite o nome do aluno: ");
 						scanf("%s", f[i].nome);
        	
        				printf("\n Digite a nota da P1: ");
        				scanf("%f", &f[i].nP1);
        	
  					    printf("\n Digite a nota da P2: ");
        	   	   		scanf("%f", &f[i].nP2);
        	
        				printf("\n Digite a nota de trabalho: ");
        				scanf("%f", &f[i].nT);
        				
  						f[i].media = ((f[i].nP1 * 2) + (f[i].nP2 * 3) + f[i].nT) / 6;
  						
						mostrar(f,i);
				}
			}
		}
		
}
