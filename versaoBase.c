#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

void EX1(){
    int jogo[10];
    int resultado[6];
    int complementar = 0;
    int cont1 = 0;
    int cont2 = 0;
    int acertos = 0;
    bool estaNoVetor = false;
    srand ( time(NULL) );

    for(cont1 = 0; cont1 < sizeof(jogo)/sizeof(int);cont1++){
        jogo[cont1] = 0;
        if(cont1 < sizeof(resultado)/sizeof(int)){
            resultado[cont1] = 0;
        }
    }

    printf("Digite os numeros que voce ira apostar!(numeros validos emtre 1 e 60)\n");
    for(cont1 = 0; cont1 < sizeof(jogo)/sizeof(int);cont1++){
        do{
            estaNoVetor = false;
            do{
                printf("%d) ",cont1+1);
                scanf(" %d",&complementar);
            }while((complementar < 0)||(complementar > 61));

            for(cont2 = 0; cont2 < sizeof(jogo)/sizeof(int); cont2++){
                if(complementar == jogo[cont2]){
                    estaNoVetor = true;
                }
            }
        }while(estaNoVetor == true);
        jogo[cont1] = complementar;

        if(cont1 < sizeof(resultado)/sizeof(int)){
            do{
                estaNoVetor = false;
                complementar = rand()%61;


                for(cont2 = 0; cont2 < sizeof(resultado)/sizeof(int);cont2++){
                    if(complementar == resultado[cont2]){

                        estaNoVetor = true;
                    }
                }
            }while((estaNoVetor == true)||(complementar == 0));
            resultado[cont1] = complementar;
        }
    }


    printf("\n\nO resultado do sorteio foi: ");
    for(cont1 = 0; cont1 < sizeof(resultado)/sizeof(int); cont1++){
        printf("%d|",resultado[cont1]);
    }

    printf("\n\nOs numeros que voce escolheu:  ");
    for(cont1 = 0; cont1 < sizeof(jogo)/sizeof(int); cont1++){
        printf("%d|",jogo[cont1]);
    }



    printf("\n\nSendo assim, voce acertou os seguintes numeros:");
    for(cont1 = 0; cont1 < sizeof(jogo)/sizeof(int);cont1++){
        for(cont2 = 0; cont2 < sizeof(resultado)/sizeof(int);cont2++){
            if(jogo[cont1] == resultado[cont2]){
                printf("%d|",jogo[cont1]);
                acertos++;
            }
        }
    }
    printf("\ntotabilizando um total de %d acertos!\n",acertos);
    switch(acertos){
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

