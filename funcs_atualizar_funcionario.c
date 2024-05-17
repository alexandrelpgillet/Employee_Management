#include "struct+func.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



long int  id_conversion()
{
    
    char resposta_ID[11]; // ID escolhido pelo usuário

    char *final_id; // variavel para validação da função strtol

    long int ID; // variavel para armazenar o lont int gerado na conversão do char resposta_ID[11] para long int pela função strtol

    
     
    scanf("%s" , resposta_ID);
    
    // long int = strtol (string , ponteiro para armazenar o final da string a ser convertida para inteiro para verificar se a conversão foi realizada com sucesso , base do numero a ser convertido , no caso base decimal)

    ID =strtol(resposta_ID , &final_id , 10);
    

    //Verificação se a conversão do strtol foi realizada com sucesso

    if(*final_id != '\0')
    {
        printf("ERROR DE CONVERSAO (STRING -> LONG INT)\n");
        exit(1);
    
    }

    //Verificação se o ID escolhido é valido ou não para a lista impressa de registros que estão alocados dinamicamente em Funcionario

    while(ID<1 || ID>quantidade_funcionarios)
    {
        flush_in();

        printf("ID INVALIDO - DIGITE NOVAMENTE UM ID VALIDO DE 1 ATE %d\n" , quantidade_funcionarios);
        scanf("%s" , resposta_ID);

        ID = strtol(resposta_ID , &final_id , 10);

        if(*final_id !='\0')
        {
            printf("ERRO DE CONVERSÃO (STRING -> LONG INT)\n");
            exit(1);
        }

       
    }
    
    //Função id_conversion() retorna o long int ID que sera usado como indice controle de Funcionadio (Dados+ID)
    return ID;
    

    




}


void atualizar_funcionario(Funcionario *Dados)
{
    
    
    
    
    //ID = ID DO FUNCIONARIO QUE TERA AS INFROMAÇÔES ALTERADAS
    long int ID;
    
    //Variavel caso não seja encontrado o funcionario durante a busca de nome
    int funcionario_nao_encontrado;
    

    //Varivel controle do loop do menu de atualização do contato
    int  menu_edicao = 1;
    
    //Variavel controle das opções de edicao dos dados do funcionario
    char editar_cadastro;
    
    
    //Variaveis auxiliares do Registro funcionaario Dados->Nome , Dados->Departamento , Dados->Cargo, Dados->Salario
    char aux_nome[60];
    char aux_departamento[20];
    char aux_cargo[20];
    float aux_salario;
    

    //Varivel do label (NEW) caso haja altração em determinada varivael do Registro Dados (podendo ser o Dados->Nome , Dados->Departamento , Dados->Cargo , Dados -> Salario)
    char *new_nome;  
    char *new_departamento;
    char *new_cargo ;
    char *new_salario;
    
    //Os labels (NEW) inicam vazio sendo somente moficados quando houver alteração
    new_nome=" ";
    new_departamento=" ";
    new_cargo=" ";
    new_salario=" ";

    
    //Flag controle de alteracao , caso nao ocorra nenhuma alteração a flag permanece == 0 e retorna ao menu direto sem perguntar se usuario confirmas as alterções

    int flag_alteracao=0;
    
    //Flag do tipo char para confirmar alterações das informações de Registro do funcionario ou cancelar a operação de modificação das informações

    char confirmacao_alteracao;
    

    //Se não houver funcionarios cadastrado no sistema , o msm retorna ao MENU
    if(quantidade_funcionarios==0)
    {
        printf("ERROR - NENHUM FUNCIONARIO CADASTRADO NO SISTEMA\n");
        printf("PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        getchar();
        getchar();
        
        return;
    }
     

    //Reaproveitamento da função buscar , caso seja encontrado registro(s) com informções iguais a da busca a função buscar_funcionar() retrona 0 , caso não seja encontra ele retorna -1 

    funcionario_nao_encontrado = buscar_funcionario(Dados);

    
    
    //Caso nao seja encontra retornar ao MENU
    if(funcionario_nao_encontrado == -1)
    {
       
        printf("PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        getchar();

        return;
    }
    
    
    
    //Chamando a função id_conversion() , a mesma irá retorna a varivel ID do tipo long int o valor do ID do registro  Funcionario *Dados+ID a ser editado
    printf("\nDIGITE O ID DO FUNCIONARIO QUE VOCE DESEJA EDITAR\n");
    
    
    
    ID = id_conversion() -1 ;

    //ID é decremetando em um uma vez que o ID é +=1 em relação a variavel quantidade_funcionarios
    flush_in();
    
    //Copiando os Dados do Registro escolhido para variaveis auxiliares aux_nome , aux_departamento , aux_cargo

    strcpy(aux_nome, (Dados+ID)->nome);
    strcpy(aux_departamento, (Dados+ID)->departamento);
    strcpy(aux_cargo , (Dados+ID)->cargo);
    aux_salario = (Dados+ID)->salario;

    

    //MENU COM AS OPCOES DE EDIÇÂO DAS VARIAVEIS DO REGISTRO DO FUNCIONARIO
    while(menu_edicao)
    {

         system("cls");
      

         printf("-----DADOS ATUAIS DO FUNCIONARIO-----\n");
         printf("|                                                     \n");
         printf("|1)NOME = %s %s                                        \n" , aux_nome , new_nome);
         printf("|2)DEPARTAMENTO = %s %s                                  \n" , aux_departamento, new_departamento);
         printf("|3)CARGO = %s %s                                         \n" , aux_cargo , new_cargo);
         printf("|4)SALARIO = R$ %.2f %s                                   \n" , aux_salario , new_salario);
         printf("|                                                     \n");
         printf("|-----------------------------------------------------\n");
         printf("\n");
    
    
    
    
    
         printf("CASO QUEIRA EDITAR ALGUMA INFORMAÇÃO DIGITE O NUMERO CORRESPONDENTE A NUMERAÇÃO DOS ITENS(1-NOME , 2-DEPARTAMENTO , 3 - CARGO , 4 - SALARIO) , CASO NAO QUEIRA EDITAR DIGITE ENTER\n");
      
      
         scanf("%c",&editar_cadastro );

         
         //Opções do menu de opções
      

         //CASE 1= NOVO NOME | CASE 2 = NOVO DEPARTAMENTO | CASE 3 = NOVO CARGO | CASE 4 = NOVO SALARIO | CASE '\n' = FECHAR MENU DE EDICAO
         switch(editar_cadastro)
         {  
         

           case '1':

             system("cls");
             
             printf("DIGITE O NOVO NOME DO FUNCIONARIO:\n");
             
             flush_in();
             
             fgets(aux_nome , 60 , stdin);
             
             string_cadastro_validation(aux_nome , "NOVO NOME DO FUNCIONARIO" , 60);

             new_nome="(New)";

             flag_alteracao++;
         
           break;
         
           case '2':
             
             system("cls");
             
             printf("DIGITE O NOVO DEPARTAMENTE DO FUNCIONARIO:\n");
             
             flush_in();
             
             fgets(aux_departamento , 20 , stdin);
             
             string_cadastro_validation(aux_departamento ,"NOVO DEPARTAMENTO DO FUNCIONARIO" , 20);

             new_departamento = "(New)";

             flag_alteracao++;

        
           break;

           case '3':
             
             system("cls");
             
             printf("DIGITE O NOVO CARGO DO FUNCIONARIO:\n");
             
             flush_in();
             
             fgets(aux_cargo, 20 , stdin);
             
             string_cadastro_validation(aux_cargo , "NOVO CARGO DO FUNCIONARIO" , 20);

             new_cargo = "(New)";

             flag_alteracao++;
         
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

             new_salario="(New)";

             flush_in();

             flag_alteracao++;

             system("cls");


           
           break;

           case '\n':
             
             menu_edicao=0;
             
             system("cls");

           break;

           default:
             
             printf("ERROR-RESPOSTA INVALIDA\n");
             
             system("pause");
             
             system("cls");
           
           break;

        }



        
    }

    //Se ocorreu alguma alteração a flag_alteracao ser >0

    if(flag_alteracao>0)
    {
         printf("-----DADOS A SEREM ALTERADOS DO FUNCIONARIO-----\n");
         printf("|                                                     \n");
         printf("|1)NOME = %s %s                                        \n" , aux_nome , new_nome);
         printf("|2)DEPARTAMENTO = %s %s                                  \n" , aux_departamento , new_departamento);
         printf("|3)CARGO = %s %s                                         \n" , aux_cargo , new_cargo);
         printf("|4)SALARIO = R$ %.2f %s                                   \n" , aux_salario , new_salario);
         printf("|                                                     \n");
         printf("|-----------------------------------------------------\n");
         printf("\n");

         printf("DIGITE 'Y' - PARA CONFIRMAR ALTERACAO | DIGITE 'N' - PARA CANCELAR ALTERACAO\n");
         
         confirmacao_alteracao = getchar();
         flush_in();
         
         
         //Validação da variavel confirmacao_alteracao

         while(confirmacao_alteracao!= 'Y' && confirmacao_alteracao != 'N')
         {

            printf("ERROR- RESPOSTA INVALIDA\n\n");
            printf("DIGITE 'Y' - PARA CONFIRMAR ALTERACAO | DIGITE 'N' - PARA CANCELAR ALTERACAO\n");
            confirmacao_alteracao = getchar();
            flush_in();
            
         }

         if(confirmacao_alteracao == 'N')
         {
            printf("OPERACAO CANCELADA , PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
            getchar();

         }
         else 
         {
            if(confirmacao_alteracao=='Y')
            {   


                strcpy((Dados+ID)->nome , aux_nome);
                strcpy((Dados+ID)->departamento, aux_departamento);
                strcpy((Dados+ID)->cargo , aux_cargo);
                (Dados+ID)->salario = aux_salario;

                printf("OPERACAO DE ATUALIZAÇÃO DOS DADOS DO FUNCIONARIO REALIZADA COM SUCESSO\n\n");
                printf("PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
                getchar();
            }
         }


    }

    







}