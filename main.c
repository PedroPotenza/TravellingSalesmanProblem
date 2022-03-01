/*
    Codigo Referencia: https://justtechreview.com/travelling-salesman-problem-in-c-and-c/
    Créditos da implementação a Sean Fleming.
*/

#include <stdio.h>

int matrizDeCustos[20][20], completadas[20], numeroDeCidadesTotais, custoTotal = 0, cidadeDeInicio;

void Input() {

    printf("\n\nNumero de cidades a serem visitadas pelo caixeiro viajante: ");
    scanf("%d", &numeroDeCidadesTotais);

    printf("\nO caixeiro comeca sua viagem por qual cidade? (1 a %d)\n", numeroDeCidadesTotais);
    scanf("%d", &cidadeDeInicio);
    cidadeDeInicio--;

    printf("\n=============================================\n");
    printf("Matriz de custos de viagem entre cada cidade:\n ");

    for (int i = 0; i < numeroDeCidadesTotais; i++)
    {
       printf("\nCusto de viagem da cidade %d para as outras: ", i+1);

        for (int j = 0; j < numeroDeCidadesTotais; j++)
        {
            if(i == j) {
                matrizDeCustos[i][j] == 0;
            } else {
                printf("\n%d ----> %d\nCusto: ", i+1, j+1);
                scanf("\t%d", &matrizDeCustos[i][j]);
            }
            
            completadas[i] = 0;
        }
       
    }

    printf("\n\n Matriz de custos completa:");

        for (int i = 0; i < numeroDeCidadesTotais; i++)
        {
            printf("\n");

            for (int j = 0; j < numeroDeCidadesTotais; j++)
                printf("\t%d", matrizDeCustos[i][j]);  
        }

}

// least
int CalculaMinimo(int cidade) { 

    int numeroCidade = 9999;
    int minimo = 9999, minimoCustoDaCidade;

    for (int i = 0; i < numeroDeCidadesTotais; i++)
    {
        if(matrizDeCustos[cidade][i] != 0 && completadas[i] == 0){
            if(matrizDeCustos[cidade][i] + matrizDeCustos[i][cidadeDeInicio] < minimo)
            {
                minimo = matrizDeCustos[i][cidadeDeInicio] + matrizDeCustos [cidade][i];
                minimoCustoDaCidade = matrizDeCustos[cidade][i];
                numeroCidade = i;
            }
        }
    }

    if(minimo != 9999)
        custoTotal += minimoCustoDaCidade;

    return numeroCidade;
    
}


void custoMinimoDaCidade(int cidade) {

    int nCidade;

    completadas[cidade] = 1;

    printf("%d ---> ", cidade+1);
    nCidade = CalculaMinimo(cidade);

    if(nCidade == 9999)
    {
        nCidade = cidadeDeInicio;
        printf("%d", nCidade+1);
        custoTotal += matrizDeCustos[cidade][nCidade];

        return;
    }

    custoMinimoDaCidade(nCidade);

}

int main(int argc, char const *argv[])
{
    Input();

    printf("\n\nO caminho do caixeiro eh:\n");
    custoMinimoDaCidade(cidadeDeInicio); 

    printf("\n\nCusto minimo da viagem: %d\n", custoTotal);

    return 0;
}
