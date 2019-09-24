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
 
    layout(); // vai para a função layout e executa
    setlocale(LC_ALL,"portuguese");
    int op; // variável do menu
    char palavrasecreta[30]; // guarda a palavra digitada pelo usuário
    char letra; // letra digitada pelo adversário
    char tema[20]; // guarda o tema digitado pelo usuário
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
                        printf("\n\t\tO jogo começa em 3 segundos , prepare-se \n\n ");
                        Sleep(3000);
                        system("cls");
                        printf("\n\t\t\tTema : %s\n\t",tema);// printa o tema
                        printf("\t\tA palavra possui >> \n ");
                               
                        for(int i=0;i<strlen(palavrasecreta)-1;i++){ // laço para mostrar quantas letras tem a palavra
                            printf(" _ "); // -1 para tirar o \0
                        }
                     
                        printf("\n"); // só para pular a linha
                           
                        if(1){ // if sempre verdadeiro **TRUE** == 1 para poder declarar variaveis dentro do switch
                               
                            int pos[strlen(palavrasecreta)] = {}; // variavel pos com o tamanho da string , para guardar as posições preenchidas
                           
                           do{
						   
                                int contespaco = 0,contletra = 0;// variaveis contadoras;
                       			
                                printf("\t\nDigite uma letra : \n"); // interação com o usuário
                                scanf("%c", &letra); //leitura de letra
                                setbuf(stdin,NULL);
                                           
                                for(int j=0;j<strlen(palavrasecreta)-1;j++){ //laço para comparar se a letra digitada pelo usuário , pertence a alguma posição na palavra
                                     if(toupper(letra) == toupper(palavrasecreta[j])){ //toupper para deixar todas as letras iguais
                                        contletra++; // se a letra digitada for igual a letra guardada no vetor da palavrasecreta
                                        // conta a letra
                                        pos[j] = letra; // atribui a letra ao vetor pos na posição j;
                                    }
                                }
                                   
                                for(int i=0;i<strlen(palavrasecreta)-1;i++){
                                    if(pos[i] != 0){ // se a pos[i] for diferente de 0 , ou seja , se ja tiver uma letra preenchida , ela printa a letra
                                        printf(" %c ", pos[i]);
                                    }else{
                                        contespaco++; // se não houver uma letra na posição , por exemplo pos[0] , ela printa o espaço ( _ )
                                        printf(" _ ");
                                    }
                                }  
     
                                if (contletra ==  0 ){// se contletra for igual a 0 , é por que a letra digitada não tem na palavra
                                //ele não entrou no if de comparação
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
                               
                                   
                                if(contespaco == 0 ){ // se contespaço for igual a 0 , é porque não tem mais espaços sem letras
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
                    printf("\t1 - O desafiante deverá digitar uma palavra para o desafiadon\n ");
                    printf("\t2 - Existirá um tema para facilitar a vida do oponente\n");
                    printf("\t3 - O oponente terá as chances necessárias , ou até ser enforcado\n\n\n");
                     main();
                case 3 : printf("Finalizando o jogo \n");
                    Sleep(600);
                    printf("Finish!\n");
                    break;
                default :
                 printf("Opção invalida\n");
        }  
    }while(op!=3);
    system("pause");
return 0;
}
void layout  (){
 
    printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
    printf("\n\t²             ²");
    printf("\n\t²  JOGO DA FORCA      ²");
    printf("\n\t²  [1] - JOGAR            ²");
    printf("\n\t²  [2] - REGRAS               ²");
    printf("\n\t²  [3] - SAIR         ²");
    printf("\n\t²             ²");
    printf("\n\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n\t");
 
}
void desenho(){ // desenha a forca e controla as tentativas do adversário
   
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
