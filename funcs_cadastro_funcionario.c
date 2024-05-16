#include "struct+func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//FLUSH_IN ()= LIMPEZA DO BUFFER STDIN

void flush_in()
{
    int ch;

    do
    {
       ch=fgetc(stdin);
    }
    while(ch!='\n' && ch!=EOF);
}


//STRING_REMOVE_LINE_BREAK ()= REMOVER '\n' das strings aux_nome , aux_departamento , aux_cargo

void string_remove_line_break(char string[60] )
{
    
    int i  =0 ;

    while(string[i]!='\0')
    {
       
        
        if(string[i]=='\n')
        {
            string[i]='\0';
        }

         i++;
    }


    

}



//STRING_CADASTRO_VALIDATION () = VALIDAÇÃO das string aux_nome , aux_departamento , aux_cargo
void string_cadastro_validation(char string[60] , char *label, int char_size)
{
    int size;

    string_remove_line_break(string);

    

    size =  strlen(string);

   

    while(size==0)
    {   
        
        printf("OBRIGATORIO O PREENCHIMENTO DO %s\n" , label);
        printf("DIGITE O %s :" , label);
        fgets(string , char_size , stdin);
        string_remove_line_break(string);
        size = strlen(string);
        

    }



}



//CADASTRO_FUNCIONARIO () = CADASTRO DO FUNCIONARIO A PARTIR DAS STRINGS aux_nome , aux_departamento , aux_cargo e FLOAT aux_salario

void cadastro_funcionario(Funcionario *Dados)
{
    
    //Variaveis auxiliares para armazenar dados do funcionario durante o cadastro
    char aux_nome[60];
    char  aux_departamento[20];
    char aux_cargo[20];
    float aux_salario;

    //Varivel de controle do menu com as opções de editar cadastro   
    int menu_editar_cadastro=1;
     
    //Variavel com as opções de edição do cadastro 
    char editar_cadastro;

    //Variavel para confirmação do cadastro 
    char confirmacao_cadastro;



    //Leitura do aux_nome + validação
    printf("DIGITE O NOME COMPLETO DO FUNCIONARIO:");
    fgets(aux_nome , 60 , stdin);
    string_cadastro_validation(aux_nome , "NOME COMPLETO DO FUNCIONARIO" , 60);

    
    //Leitura do aux_departamento + validação
    printf("\nDIGITE O DEPARTAMENTO DO FUNCIONARIO:");
    fgets(aux_departamento , 20 , stdin);
    string_cadastro_validation(aux_departamento , "DEPARTAMENTO DO FUNCIONARIO" , 20);
    

    //Leitura do aux_cargo+validação
    printf("\nDIGITE O CARGO DO FUNCIONARIO:");
    fgets(aux_cargo , 20 , stdin);
    string_cadastro_validation(aux_cargo , "CARGO DO FUNCIONARIO", 20);
    

    //Leitura do aux_salario+validação
    printf("\nDIGITE O VALOR DO SALARIO DO FUNCIONARIO:");
    scanf("%f" , &aux_salario);
    
    while(aux_salario<=0)
    {
        printf("ERROR- VALOR DE SALARIO INVALIDO\n");
        printf("DIGITE O VALOR DO SALARIO DO FUNCIONARIO:");
        scanf("%f" , &aux_salario);
    }


    //Limpezado do Buffer 
    flush_in();


    //Menu de opções de edição
    while(menu_editar_cadastro)
    {
      
        system("cls");
      

        printf("-----DADOS A SEREM CADASTRADOS DO NOVO FUNCIONARIO-----\n");
        printf("|                                                     \n");
        printf("|1)NOME = %s                                          \n" , aux_nome);
        printf("|2)DEPARTAMENTO = %s                                  \n" , aux_departamento);
        printf("|3)CARGO = %s                                         \n" , aux_cargo);
        printf("|4)SALARIO = R$ %.2f                                   \n" , aux_salario);
        printf("|                                                     \n");
        printf("|-----------------------------------------------------\n");
        printf("\n");
    
    
    
    
    
        printf("CASO QUEIRA EDITAR ALGUMA INFORMAÇÃO DIGITE O NUMERO CORRESPONDENTE A NUMERAÇÃO DOS ITENS(1-NOME , 2-DEPARTAMENTO , 3 - CARGO , 4 - SALARIO) , CASO NAO QUEIRA EDITAR DIGITE ENTER\n");
      
      
        scanf("%c",&editar_cadastro );

         
        //Opções do menu de opções
      

        //CASE 1= NOVO NOME | CASE 2 = NOVO DEPARTAMENTO | CASE 3 = NOVO CARGO | CASE 4 = NOVO SALARIO
        switch(editar_cadastro)
        {  
         

           case '1':

             system("cls");
             
             printf("DIGITE O NOVO NOME DO FUNCIONARIO:\n");
             
             flush_in();
             
             fgets(aux_nome , 60 , stdin);
             
             string_cadastro_validation(aux_nome , "NOVO NOME DO FUNCIONARIO" , 60);
         
           break;
         
           case '2':
             
             system("cls");
             
             printf("DIGITE O NOVO DEPARTAMENTE DO FUNCIONARIO:\n");
             
             flush_in();
             
             fgets(aux_departamento , 20 , stdin);
             
             string_cadastro_validation(aux_departamento ,"NOVO DEPARTAMENTO DO FUNCIONARIO" , 20);
        
           break;

           case '3':
             
             system("cls");
             
             printf("DIGITE O NOVO CARGO DO FUNCIONARIO:\n");
             
             flush_in();
             
             fgets(aux_cargo, 20 , stdin);
             
             string_cadastro_validation(aux_cargo , "NOVO CARGO DO FUNCIONARIO" , 20);
         
           break; 

           case '4':
             
             system("cls");
             
             printf("DIGITE O NOVO SALARIO DO FUNCIONARIO:\n");
             
             scanf("%f" ,&aux_salario);
         
             while(aux_salario<=0)
             {
               
               printf("ERROR - VALOR DE SALARIO INVALIDO\n");
               
               printf("DIGITE UM NOVO VALOR VALIDO DE SALARIO\n");
               
               scanf("%f" , &aux_salario);
             
             }

             flush_in();

             system("cls");
           
           break;

           case '\n':
             
             menu_editar_cadastro=0;
             
             system("cls");

           break;

           default:
             
             printf("ERROR-RESPOSTA INVALIDA\n");
             
             system("pause");
             
             system("cls");
           
           break;

      }

    }

    //CONFIRMACAO DO CADASTRO
     printf("-----DADOS A SEREM CADASTRADOS DO NOVO FUNCIONARIO-----\n");
     printf("|                                                     \n");
     printf("|1)NOME = %s                                          \n" , aux_nome);
     printf("|2)DEPARTAMENTO = %s                                  \n" , aux_departamento);
     printf("|3)CARGO = %s                                         \n" , aux_cargo);
     printf("|4)SALARIO = R$ %.2f                                  \n" , aux_salario);
     printf("|                                                     \n");
     printf("|-----------------------------------------------------\n");
     printf("\n");
     


     printf("DIGITE 'Y' PARA REALIZAR CADASTRO OU DIGITE 'N' PARA CANCELAR CADASTRO\n");
     
     confirmacao_cadastro = getchar();
     
     flush_in();



     //VALIDAÇÂO CADASTRO
     while(confirmacao_cadastro!='Y' && confirmacao_cadastro!='N')
     {
         printf("ERROR - RESPOSTA INVALIDA\n");
         
         printf("DIGITE 'Y' PARA REALIZAR CADASTRO OU DIGITE 'N' PARA CANCELAR CADASTRO\n");
         
         confirmacao_cadastro = getchar();
         
         flush_in();
     }

     

     //CASE 'N' = CANCELAR CADASTRO E VOLTAR PARA O MENU | CASE 'Y' = CONFIRMAR CADASTRO , COPIAR DADOS PARA O REGISTRO *Dados e INCREMENTAR quantidade_funcionarios++

     switch(confirmacao_cadastro)
     {
        case 'N':
          system("CLS");
          printf("OPERCAO CANCELADA COM SUCESSO\n");
          system("pause");
          system("cls");
        break;

        case 'Y':
          system("CLS");
          printf("OPERACAO DE CADASTRO REALIZADA COM SUCESSO\n");

        
          strcpy((Dados+quantidade_funcionarios)->nome, aux_nome);
          strcpy((Dados+quantidade_funcionarios)->departamento , aux_departamento);
          strcpy((Dados+quantidade_funcionarios)->cargo , aux_cargo);
          ((Dados+quantidade_funcionarios)->salario)=aux_salario;
          quantidade_funcionarios++;

        


          system("pause");
          system("cls");
        
        break;

        default:
        
        break;

     }
     

    



}