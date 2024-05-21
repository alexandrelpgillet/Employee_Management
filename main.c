#include "struct+func.h"
#include "funcs_cadastro_funcionario.c"
#include "funcs_listar_funcionario.c"
#include "funcs_buscar_funcionario.c"
#include "funcs_atualizar_funcionario.c"
#include "funcs_excluir_funcionario.c"
#include <stdio.h>
#include <stdlib.h>





int main()
{
   
    int flag_menu=1; // Variavel controle do menu
    char resposta_menu; //Opção a ser escolhida no menu


    //Alocando memoria dinamicamente para armenzar todos os registros de funcionarios durante a execução do programa
    Funcionario *Dados;
    Dados = malloc(sizeof(Funcionario)*1000);

    //Verificando se a alocação dinamica foi realizada com sucesso
    if(Dados == NULL)
    {
        printf("ERROR-  NAO FOI POSSIVEL ALOCACAR DINAMICAMENTE MEMORIA P/APLICAÇAO");

        exit(1);
    }

     

    //Abrindo o arquivo backup.bin em modo de leitura
    FILE *arquivo_funcionarios;
    arquivo_funcionarios= fopen("backup.bin" , "rb");
    


    //Caso arquivo_funcionario retorne NULL significa que não existe um arquivo backup.bin , logo o programa deve criar um arquivno backup.bin
    //Caso já exista um arquivo backup.bin , usaremos fread para ler todo o arquivo e passar todos os registros do arquivo.bin para a alocação dinamica da main

    if(arquivo_funcionarios ==NULL)
    {
        arquivo_funcionarios=fopen("backup.bin" , "ab");
        
    }
    else
    {   

        //Usar fread para ler o registro alocado dinamicamente de cada funcionario de todo o arquivo binário backup.bin
        while(fread((Dados+quantidade_funcionarios), sizeof(Funcionario) , 1 , arquivo_funcionarios))
        {

            quantidade_funcionarios++;
           
        }
        
        fclose(arquivo_funcionarios);

    }

    




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
        printf("|5)Excluir Funcionario          |\n");
        printf("|                               |\n");
        printf("|-------------------------------|\n");
        
        //Escolha de qual opção do menu acessar 

        printf("DIGITE O NUMERO DA OPCAO QUE DESEJA ACESSAR:");
        
        
        resposta_menu= getchar();
        flush_in();
        
        
        


        
        //Validação da opção escolhida pelo usuario
        
        //Usado a tabela ASCII (49 = char '1' , 50 = char '2' , 51 = char '3' , 52 = char '4' , 53 = char '5')
        
        while(resposta_menu<49 || resposta_menu>53)
        {
            printf("ERROR - NUMERO DE OPCAO INVALIDA , DIGITE VALORES DE 1 A 5\n");
            printf("DIGITE O NUMERO DA OPCAO QUE DESEJA ACESSAR:");
           
            resposta_menu = getchar();
            flush_in();


        }


        //CASE 1 = CADASTRO_FUNCIONARIO() , CASE 2 = LISTAR_FUNCIONARIOS() , CASE 3 = BUSCAR_FUNCIONARIO()
        switch(resposta_menu)
        {  
           case '1':
           
           system("cls");
           cadastro_funcionario(Dados);

           break;
           
           case '2':

           system("cls");
           listar_funcionarios(Dados);
           
           printf("\nPRRESIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
    
           getchar();
    
           system("cls");

           break;
           
           case '3':
           
           system("cls");

           buscar_funcionario(Dados);

           printf("\nPRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU INICIAL\n");
    
           getchar();
    
           system("cls");
           

           
           break;

           case '4':
           system("cls");

           atualizar_funcionario(Dados);

           system("cls");
           
           
           break;
           
           case '5':
           excluir_funcionario(Dados);
           flush_in();

           system("cls");

           
           break;
           
           default:
           break;
        }

        

    } 




}