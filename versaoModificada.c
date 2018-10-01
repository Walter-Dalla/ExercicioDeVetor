#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

void EX1(){

    srand ( time(NULL) );

    int jogo[10];
    int resultado[6];
    int complementar = 0;
    int cont1 = 0;
    int cont2 = 0;
    int acertos = 0;
    bool estaNoVetor = false;

    //-----------Ponteiros-----------//

    int* pJogo = jogo;
    int* pResultado = resultado;
    int* pComplementar = &complementar;
    int* pCont1 = &cont1;
    int* pCont2 = &cont2;
    int* pAcertos = &acertos;
    bool* pEstaNoVetor = &estaNoVetor;

    int sizeofJogo = sizeof(jogo)/sizeof(int);
    int sizeofResultado = sizeof(resultado)/sizeof(int);


    for(*pCont1 = 0,pJogo = &jogo,pResultado = &resultado; *pCont1 < sizeofJogo ;*pCont1 += 1, pJogo++, pResultado++){
        *pJogo = 0;
        if(cont1 < sizeofResultado){
            *pResultado = 0;
        }
    }


    printf("\n\n");

    printf("Digite os numeros que voce ira apostar!(numeros validos emtre 1 e 60)\n");
    for(*pCont1 = 0; *pCont1 < sizeofJogo; *pCont1 += 1){
        do{
            *pEstaNoVetor = false;
            do{
                printf("%d) ",*pCont1+1);
                scanf(" %d", pComplementar);
            }while((*pComplementar < 0)||(*pComplementar > 61));

            for(*pCont2 = 0; *pCont2 < sizeofJogo; *pCont2 += 1,pJogo++){
                if(*pComplementar == *pJogo){
                    *pEstaNoVetor = true;

                }
            }
        }while(*pEstaNoVetor == true);
        *pJogo = *pComplementar;



        if(*pCont1 < sizeofResultado){
            do{
                *pEstaNoVetor = false;
                *pComplementar = rand()%61;

                for(*pCont2 = 0; *pCont2 < sizeofResultado;*pCont2 += 1){

                    if(*pComplementar == resultado[*pCont2]){

                        *pEstaNoVetor = true;
                    }
                }

            }while((*pEstaNoVetor == true)||(*pComplementar == 0));
            resultado[*pCont1] = *pComplementar;
        }

    }


    printf("\n\nO resultado do sorteio foi: ");
    for(*pCont1 = 0; *pCont1 < sizeofResultado; *pCont1 += 1){
        printf("%d|",resultado[*pCont1]);
    }

    printf("\n\nOs numeros que voce escolheu:  ");
    for(*pCont1 = 0; *pCont1 < sizeofJogo; *pCont1 += 1,pJogo++){
        printf("%d|",*pJogo);
    }



    printf("\n\nSendo assim, voce acertou os seguintes numeros:");
    for(*pCont1 = 0; *pCont1 < sizeofJogo;*pCont1 += 1,pJogo++){
        for(*pCont2 = 0; *pCont2 < sizeofResultado;*pCont2 += 1){
            if(*pJogo == resultado[*pCont2]){
                printf("%d|",*pJogo);
                *pAcertos += 1;
            }
        }
    }
    printf("\ntotabilizando um total de %d acertos!\n",acertos);
    switch(*pAcertos){
        case 6:
            printf("\nSena\n");
            break;
        case 5:
            printf("\nQuina\n");
            break;
        case 4:
            printf("\nQuadra\n");
            break;
        default:
            printf("\nVoce nao acertou suficiente para ser uma \"Sena\", \"Quina\" ou \"Quadra\"\n");
            break;
    }
}


void EX2(){
    char frase[50];
    int i = 0;
    printf("Digite uma frase com 50 caracteres, letras maiusculas e minusculas sao permitidas!\n");
    printf("                                                  |50 caracteres\n");
    for(i = -1; i < sizeof(frase); i++)
        frase[i] = getchar();

        //poderia utilizar o toupper(frase[i]), porem se utilisase a saida só seria em maiusculas,
        // e se eu colocase o tolower, porem perderia a informaçao dos caracteres maiusculos
        printf("Somente as vogais da frase:");
     for(i = 0; i < sizeof(frase); i++){

        if((frase[i] == 'A')||(frase[i] == 'E')||(frase[i] == 'I')||(frase[i] == 'O')||(frase[i] == 'U')||
           (frase[i] == 'a')||(frase[i] == 'e')||(frase[i] == 'i')||(frase[i] == 'o')||(frase[i] == 'u'))
            printf("%c",frase[i]);
    }
}


void EX3(){

    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int contA = 0;
    int contB = 0;

    for(contA = 0; contA < sizeof(a); contA++){
        for(contB = 0; contB < sizeof(b); contB++){
            if(a[contA] == b[contB])
                printf("%d",a[contA]);
        }
    }
}



void EX4(){

int binario[4] = {1,0,0,1};
int i = 0;
int decimal = 0;
    printf("o binario \"");
    for(i = 0; i < sizeof(binario); i++){
        printf("%d", binario[i]);
    }
    printf("\" em decimal é: ");
    for(i = 0; i < sizeof(binario); i++){
        decimal += binario[i] * pow(2,i);
    }
    printf("%d",decimal);
}


int main(){
    setlocale(LC_ALL,"");
    int opcao = 0;

    printf("1) Mega sena Exercicio 1\n");
    printf("2) Exibir vogais Exercicio 2\n");
    printf("3) Vetores iguais Exercicio 3\n");
    printf("4) Binario para decimal Exercicio 4\n");
    printf("5) Sair\n");

    do{

        printf("Digite sua opçao : ");
        scanf(" %d", &opcao);
    }while((opcao > 5) ||(opcao < 1));
    switch(opcao){

        case 1:
            EX1();
            break;
        case 2:
            EX2();
            break;
        case 3:
            EX3();
            break;
        case 4:
            EX4();
            break;
        case 5:
            printf("Saindo!");
            return 0;

    }

}

