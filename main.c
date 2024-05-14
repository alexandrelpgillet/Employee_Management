#include <struct.h>
#include <stdio.h>

//Função para limpar o buffer do teclado durante a validação variavel resposta_menu
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
   
    int flag_menu=1; // Variavel controle do menu
    char resposta_menu; //Opção a ser escolhida no menu

    while (flag_menu)
    {
        
        
        //MENU Principal da aplicação

        printf("|-------------------------------|\n");
        printf("|            MENU               |\n");
        printf("|                               |\n");
        printf("|1)Adicionar Funcionario        |\n");
        printf("|2)Listar Funcionarios          |\n");
        printf("|3)Pesquisar Funcionarios       |\n");
        printf("|4)Atualizar Funcionarios       |\n");
        printf("|5)Excluir Funcionario           |\n");
        printf("|                               |\n");
        printf("|-------------------------------|\n");
        
        //Escolha de qual opção do menu acessar 

        printf("DIGITE O NUMERO DA OPCAO QUE DESEJA ACESSAR:");
        resposta_menu = getchar();
        


        
        //Validação da opção escolhida pelo usuario
        
        //Usado a tabela ASCII (49 = char '1' , 50 = char '2' , 51 = char '3' , 52 = char '4' , 53 = char '5')
        
        while(resposta_menu<49 || resposta_menu>53)
        {
            printf("ERROR - NUMERO DE OPCAO INVALIDA , DIGITE VALORES DE 1 A 5\n");
            printf("DIGITE O NUMERO DA OPCAO QUE DESEJA ACESSAR:");
            flush_in();
            resposta_menu = getchar();


        }

        switch(resposta_menu)
        {
           case '1':
           
           break;
           
           case '2':
           
           break;
           
           case '3':
           
           break;

           case '4':
           
           break;
           
           case '5':
           
           break;
           
           default:
           break;
        }

        

    } 




}