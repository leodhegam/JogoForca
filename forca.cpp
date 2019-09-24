#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
int cont = 0;
void desenho();
void trofeu();
void layout ();
 
int main (){
 
    layout(); // vai para a fun��o layout e executa
    setlocale(LC_ALL,"portuguese");
    int op; // vari�vel do menu
    char palavrasecreta[30]; // guarda a palavra digitada pelo usu�rio
    char letra; // letra digitada pelo advers�rio
    char tema[20]; // guarda o tema digitado pelo usu�rio
    int contvitoria=0;
    char dica1[20];
    scanf( "%d",&op);
    setbuf(stdin,NULL);
    do{
   
     switch(op){
           
                case 1 :
                        printf("\t\t Desafiante > \n\n");
                        printf("Informe um tema (ex.: fruta,nome) >> \n\t"); // desafiante informa um tema **dica
                        fgets(tema,20,stdin); // leitura
                        setbuf(stdin,NULL); // limpa o \0
                        printf("Digite uma palavra para o oponente >> \n\t"); // desafiante digita a palavra a ser advinhada
                        fgets(palavrasecreta,30,stdin); // leitura da palavra
                        printf("Informe uma dica >> \n");
                        gets(dica1);
                        system("cls"); // limpa a tela
                    //  setbuf(stdin,NULL); // limpa o buffer
                        printf("\n\t\tO jogo come�a em 3 segundos , prepare-se \n\n ");
                        Sleep(3000);
                        system("cls");
                        printf("\n\t\t\tTema : %s\n\t",tema);// printa o tema
                        printf("\t\tA palavra possui >> \n ");
                               
                        for(int i=0;i<strlen(palavrasecreta)-1;i++){ // la�o para mostrar quantas letras tem a palavra
                            printf(" _ "); // -1 para tirar o \0
                        }
                     
                        printf("\n"); // s� para pular a linha
                           
                        if(1){ // if sempre verdadeiro **TRUE** == 1 para poder declarar variaveis dentro do switch
                               
                            int pos[strlen(palavrasecreta)] = {}; // variavel pos com o tamanho da string , para guardar as posi��es preenchidas
                           
                           do{
						   
                                int contespaco = 0,contletra = 0;// variaveis contadoras;
                       			
                                printf("\t\nDigite uma letra : \n"); // intera��o com o usu�rio
                                scanf("%c", &letra); //leitura de letra
                                setbuf(stdin,NULL);
                                           
                                for(int j=0;j<strlen(palavrasecreta)-1;j++){ //la�o para comparar se a letra digitada pelo usu�rio , pertence a alguma posi��o na palavra
                                     if(toupper(letra) == toupper(palavrasecreta[j])){ //toupper para deixar todas as letras iguais
                                        contletra++; // se a letra digitada for igual a letra guardada no vetor da palavrasecreta
                                        // conta a letra
                                        pos[j] = letra; // atribui a letra ao vetor pos na posi��o j;
                                    }
                                }
                                   
                                for(int i=0;i<strlen(palavrasecreta)-1;i++){
                                    if(pos[i] != 0){ // se a pos[i] for diferente de 0 , ou seja , se ja tiver uma letra preenchida , ela printa a letra
                                        printf(" %c ", pos[i]);
                                    }else{
                                        contespaco++; // se n�o houver uma letra na posi��o , por exemplo pos[0] , ela printa o espa�o ( _ )
                                        printf(" _ ");
                                    }
                                }  
     
                                if (contletra ==  0 ){// se contletra for igual a 0 , � por que a letra digitada n�o tem na palavra
                                //ele n�o entrou no if de compara��o
                                    cont++; // controla o desenho , se chegar a 4 erros, o jogador perde
                                     printf("\nletra incorreta\n");
                                    desenho();
                               
                                }
                                    if(cont==4){ // o jogador perdeu , pois excedeu as tentativas
                                        printf("Voce perdeu\n");
                                        cont=0;
                                        system("pause");
                                        system("cls");
                                        main();
                                       
                                    }
                               
                                   
                                if(contespaco == 0 ){ // se contespa�o for igual a 0 , � porque n�o tem mais espa�os sem letras
                                contvitoria = 1;
                                    printf("\n\t\t Parabens !!!  \n "); // o jogador ganha
                                    trofeu();
                                    Sleep(500);
                                    cont=0;
                                    system("pause");
                                    system("cls");
                                    main();// volta para o inicio do jogo
                                }//fecha o ultimo if
                            }while(contvitoria!=1); //fecha o while
                        }//fecha o if(1)   
                                 
                    break;
           
                case 2:
                system("cls");
                    printf("\n\t\tREGRAS\n >>\n");
                    printf("\t1 - O desafiante dever� digitar uma palavra para o desafiadon\n ");
                    printf("\t2 - Existir� um tema para facilitar a vida do oponente\n");
                    printf("\t3 - O oponente ter� as chances necess�rias , ou at� ser enforcado\n\n\n");
                     main();
                case 3 : printf("Finalizando o jogo \n");
                    Sleep(600);
                    printf("Finish!\n");
                    break;
                default :
                 printf("Op��o invalida\n");
        }  
    }while(op!=3);
    system("pause");
return 0;
}
void layout  (){
 
    printf("\t����������������������������");
    printf("\n\t�             �");
    printf("\n\t�  JOGO DA FORCA      �");
    printf("\n\t�  [1] - JOGAR            �");
    printf("\n\t�  [2] - REGRAS               �");
    printf("\n\t�  [3] - SAIR         �");
    printf("\n\t�             �");
    printf("\n\t����������������������������\n\n\t");
 
}
void desenho(){ // desenha a forca e controla as tentativas do advers�rio
   
    printf("  ________       \n");
    printf(" |/       |      \n");
    printf(" |      %c%c%c  \n", (cont>=1?'(':' '), (cont>=1?'_':' '), (cont>=1?')':' '));
    printf(" |      %c%c%c  \n", (cont>=3?'\\':' '), (cont>=2?'|':' '), (cont>=3?'/': ' '));
    printf(" |       %c     \n", (cont>=2?'|':' '));
    printf(" |      %c %c   \n", (cont==4?'/':' '), (cont==4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
}
 
 
void trofeu(){
       
        printf(" \t     _ _ _ _  \n");
        printf(" \t    |       |    \n");
        printf(" \t    |       |   \n");
        printf(" \t    |   1   |   \n");
        printf("\t    \\       /     \n ");
        printf("\t    \\       /     \n ");
        printf("\t      )_ _(      \n");
        printf("\t     _______     \n");
}
