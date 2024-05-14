#include <stdio.h>


void flush_in()
{
    int ch;

    do
    {
       ch=fgetc(stdin);
    }
    while(ch!='\n' && ch!=EOF);
}


int main()
{
   
    int flag_menu=1;
    char resposta_menu;

    while (flag_menu)
    {
        printf("|-------------------------------|\n");
        printf("|            MENU               |\n");
        printf("|                               |\n");
        printf("|1)Adicionar Funcionario        |\n");
        printf("|2)Listar Funcionarios          |\n");
        printf("|3)Pesquisar Funcionarios       |\n");
        printf("|4)Atualizar Funcionarios       |\n");
        printf("|5)Excluir FUnionario           |\n");
        printf("|                               |\n");
        printf("|-------------------------------|\n");

        printf("DIGITE O NUMERO DA OPCAO QUE DESEJA ACESSAR:");
        resposta_menu = getchar();
        

        while(resposta_menu<49 || resposta_menu>53)
        {
            printf("ERROR - NUMERO DE OPCAO INVALIDA , DIGITE VALORES DE 1 A 5\n");
            printf("DIGITE O NUMERO DA OPCAO QUE DESEJA ACESSAR:");
            flush_in();
            resposta_menu = getchar();


        }

        flag_menu = 0;

    } 




}