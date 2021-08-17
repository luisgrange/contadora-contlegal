#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cedulas[] = {2,5,10,20,50,100,200};     //vetor com as cedulas permitiads
    int cedUsadas[7] = {0};                    //cedulas com a representação final
    int qnt;                                  //quantidade de cedulas utilizadas pelo usuário

    printf("Bem-vindo a contadora de cedulas da CONTLEGAL!!\n");
    printf("Quantas notas deseja utilizar? ");
    scanf("%d", &qnt);

    int cedUsr[qnt];                         //a quantidade de cedulas que ele definiu antes será usada para
                                            //comparação depois

    //atribuindo os valores ao vetor usado para comparação
    for(int i=0; i<qnt; i++){
        printf("Digite o valor da nota: ");
        scanf("%d", &cedUsr[i]);
    }

    config(cedUsr, cedulas, cedUsadas, qnt);
    apresentaConfig(cedulas, cedUsadas);
    //for(int i=0; i<7; i++)
        //printf("Valor de cedUsadas %d\n", cedUsadas[i]);

    return 0;
}

// Função que configura a máquina:
void config(int *ptrUsr, int *ptrCed, int *ptrCedUsadas, int qnt){
    for(int i=0; i<qnt; i++){                   //para I indo de 0 até a quantidade definida pelo usuário
        for(int j=0; j<7; j++){                 //para J indo de 0 até a quantidade de notas possiveis
            if(*(ptrUsr+i) == *(ptrCed+j)){     //se o PTRUSER (ponteiro com elementos que o usuario definiu) na posição I
                *(ptrCedUsadas+j) = 1;              //for igual ao PTRCED (ponteiro com as cedulas) na posição J
            }                                   //atribua 1 ao PTRFINAl na posição J (porque temos 7 elementos e J percorre os 7)
        }
    }
}

//Função que apresenta a posição na memoria e se determinada cedula foi utilizada
void apresentaConfig(int *ptrCed, int *ptrCedUsadas){
    printf("\n-=-=-=-=-=-=TABELA DE CONFIGURACAO=-=-=-=-=-=-=-=-\n");
    printf("\nPOS. MEM\tVALOR\tSELECIONADAS");
    for(int i=0; i<7; i++){
        printf("\n%d\t\t%d\t\t%d", ptrCed+i, *(ptrCed+i), *(ptrCedUsadas+i));
    }
}
