#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int L = 100;                                                  // Tamanho das matrizes


int main(void){

    clock_t begin  = clock();
    srand(time(0));
    int i,j,k;
    int soma = 0;
    int menor;
    int diagonal[L];
    int matriz_A[L][L],
        matriz_B[L][L],
        matriz_C[L][L],
        matriz_R[L][L];
    double tempo_gasto = 0.0;

    
    for(i=0;i<L;i++)                                        // Preencher as matrizes A,B e C com valores aleatórios de 0 a 10
    {
        for(j=0;j<L;j++)
        {
            matriz_A[i][j] = (rand()%5);                      
            matriz_B[i][j] = (rand()%5);
            matriz_C[i][j] = (rand()%5);
        }
    }

    printf("----------- Matriz A ---------------\n\n");

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            printf("%.2d ",matriz_A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("----------- Matriz B ---------------\n\n");

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            printf("%.2d ",matriz_B[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("----------- Matriz C ---------------\n\n");

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            printf("%.2d ",matriz_C[i][j]);
        }
        printf("\n");
    }

    // Fazendo as multiplicações:


    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            for(k=0;k<L;k++)
            {
                soma += matriz_A[i][k] * matriz_B[k][j];
            }
            matriz_R[i][j] = soma;
            soma = 0;
        }
    }

    // Matriz_R agora tem o resultado da multiplicação de A por B

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            matriz_A[i][j] = matriz_R[i][j];
        }
    }

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            for(k=0;k<L;k++)
            {
                soma += matriz_A[i][k] * matriz_C[k][j];
            }
            matriz_R[i][j] = soma;
            soma = 0;
        }
    }

    // Matriz_R agora tem o resultado da multiplicação de A x B x C


    printf("\n");
    printf("----------- Matriz R ---------------\n\n");

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            printf("%.4d ",matriz_R[i][j]);
        }
        printf("\n");
    }

     printf("\n");
      printf("\n");


    // Vetor "diagonal" recebe a diagonal da matriz resultado

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            if(i==j)
            {
                diagonal[i] = matriz_R[i][j];
            }
        }
    }

    menor = diagonal[0];

    for(i=0;i<L;i++)
    {
        if(menor > diagonal[i])
            menor = diagonal[i];
    }

    printf("\n --> Diagonal principal \n");
    for(i=0;i<L;i++)
    {
        printf("%d ",diagonal[i]) ;
    }

    printf("\n");
    printf("\n --> Menor Elemento: ");
    printf("%d\n",menor);

    clock_t end  = clock();
    tempo_gasto += (double)(end-begin)/CLOCKS_PER_SEC;

    printf("\nTempo gasto: %lf segundos" ,tempo_gasto);
}


