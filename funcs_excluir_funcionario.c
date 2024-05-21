#include "struct+func.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void excluir_funcionario(Funcionario *Dados)
{
    
    char resposta_tipo;
    char resposta_tipo_digitar;
    char aux_nome[60];
    char aux_departamento[20];
    char aux_cargo[20];
    int i ;
    int ID;
    int ID_delete;
    
    
    if(quantidade_funcionarios ==0)
    {
        printf("NENHUM FUNCIONARIO CADASTRADO\n");
        return;
    }
    printf("DIGITE 'L' PARA LISTAR TODOS OS FUNCIONARIOS OU DIGITE 'D' PARA DIGITAR NOME/DEPARTAMENTO/CARGOn\n");
    resposta_tipo= getchar();

    //LISTAR  TODOS OS FUNCIONARIOS = L
    //DIGITAR NOME , DEPARTAMENTO , CARGO = D

    while(resposta_tipo!='L' && resposta_tipo!='D')
    {   

         
        flush_in();
        printf("ERROR-RESPOSTA INVALIDA\n");
        printf("DIGITE 'L' PARA LISTAR TODOS OS FUNCIONARIOS OU DIGITE 'D' PARA DIGITAR NOME/DEPARTAMENTO/CARGOn\n");


        resposta_tipo=getchar();
    }

    if(resposta_tipo=='D')
    {   
        system("cls");

        printf("1)BUSCAR PELO NOME DO FUNCIONARIO\n");
        printf("2)BUSCAR PELO DEPARTAMENTO DO FUNCIONARIO\n");
        printf("3)BUSCAR PELO CARGO DO FUNCIONARIO\n");
        printf("4)CANCELAR");
        printf("\n\n");
        printf("DIGITE O NUMERO DA OPCAO DESEJADA(1 a 4)\n");
        
        flush_in();
        scanf("%c" , &resposta_tipo_digitar);
        
        while(resposta_tipo_digitar<49 || resposta_tipo_digitar>52)
        {
             
             flush_in();

             printf("ERROR- RESPOSTA INVALIDA\n");
            
             printf("DIGITE OPÇÃO ENTRE 1 a 4\n");
             
             scanf("%c" , &resposta_tipo_digitar);

            

           

        }


        

        flush_in();

        switch(resposta_tipo_digitar)
        {
            case '1':

            printf("DIGITE O NOME DO FUNCIONARIO");
            fgets(aux_nome , 60 , stdin);
            string_remove_line_break(aux_nome);

            for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
            {
                if(strcmp(aux_nome , (Dados+i)->nome)==0)
                {
                printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO %s" , ID, (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo);
                }
            }

            break;
        




            case '2':

            printf("DIGITE O DEPARTAMENTO DO FUNCIONARIO");
            fgets(aux_departamento , 60 , stdin);
            string_remove_line_break(aux_nome);

            for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
            {
                if(strcmp(aux_departamento , (Dados+i)->departamento)==0)
                {
                printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO %s" , ID, (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo);
                }
            }


            break;

            case '3':

            printf("DIGITE O CARGO DO FUNCIONARIO");
            fgets(aux_cargo , 60 , stdin);
            string_remove_line_break(aux_nome);

            for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
            {
                if(strcmp(aux_cargo , (Dados+i)->cargo)==0)
                {
                printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO %s" , ID, (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo);
                }
            }

            break;

            case '4':
            return;

            break;

            default :
           
            break;

        }

        printf("\n\nDIGITE O ID A SER EXCLUIDO OU DIGITE 0 PARA CANCELAR\n");
        scanf("%d" , &ID_delete);

        while(ID_delete<0 && ID_delete>ID)
        {
            printf("ERROR - ID INVALIDO\n");
            printf("\n\nDIGITE O ID A SER EXCLUIDO OU DIGITE 0 PARA CANCELAR\n");
        }

        if(ID_delete>0)
        {

            for(i= ID_delete-1 ; i<quantidade_funcionarios-1 ; i++)
            {

                strcpy((Dados+i)->nome , (Dados+i+1)->nome);
                strcpy((Dados+i)->departamento, (Dados+i+1)->departamento);
                strcpy((Dados+i)->cargo , (Dados+i+1)->cargo);
                (Dados+i)->salario = (Dados+i+1)->salario;

            }

            quantidade_funcionarios--;

            printf("FUNCIONARIO EXCLUIDO, PRESSIONE QUALQUER TECLA\n");
            getchar();
            

        }
        


    }








}