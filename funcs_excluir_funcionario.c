#include "struct+func.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void excluir_funcionario(Funcionario *Dados)
{
    
    char resposta_tipo;//Listar todos os funcionario ou Digitar Nome/ Departamento / Cargo  para buscar funcionario

    char resposta_tipo_digitar;//Digitar Nome  ou Departamento ou Cargo para busca
    
    char aux_nome[60];//Variavel auxiliar para armazenar resposta de nome do funcionario para busca
    
    char aux_departamento[20]; //Variavel auxiliar para armazenar reposta de departamento do funcionario para busca
    
    char aux_cargo[20]; //Variavel auxiliar para armazenar resposta do cargo do funcionario para busca
    
    int i ;
    
    int ID; 
    
    int ID_delete; // Variavel para armazenar o ID escolhido pelo usuario a ser excluido , caso =0 , cancelar operção de exclusão do funcionario
    
    int flag_busca=0;
    
    if(quantidade_funcionarios ==0)
    {
        printf("NENHUM FUNCIONARIO CADASTRADO, PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        return;
    }



    //LISTAR  TODOS OS FUNCIONARIOS = L
    //DIGITAR NOME , DEPARTAMENTO , CARGO = D
    
    printf("DIGITE 'L' PARA LISTAR TODOS OS FUNCIONARIOS OU DIGITE 'D' PARA DIGITAR NOME/DEPARTAMENTO/CARGOn\n");
    
    resposta_tipo= getchar();

     

    //Validação da variavel char resposta_tipo
    while(resposta_tipo!='L' && resposta_tipo!='D')
    {   

         
        flush_in();

        printf("ERROR-RESPOSTA INVALIDA\n");
        
        printf("DIGITE 'L' PARA LISTAR TODOS OS FUNCIONARIOS OU DIGITE 'D' PARA DIGITAR NOME/DEPARTAMENTO/CARGOn\n");

        resposta_tipo=getchar();
    }


    //Menu de opções de busca para digitar Nome/Departamento/Cargo
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
        
        //Validação da resposta_tipo_digitar de acordo com a tabela ASCII (49 = '1' , 50='2' , 51= '3' , 52 = '4')
        
        while(resposta_tipo_digitar<49 || resposta_tipo_digitar>52)
        {
             
             flush_in();

             printf("ERROR- RESPOSTA INVALIDA\n");
            
             printf("DIGITE OPÇÃO ENTRE 1 a 4\n");
             
             scanf("%c" , &resposta_tipo_digitar);
    

        }


        system("cls");

        flush_in();


        //Case 1 = Busca pelo NOME , Case 2 = Busca pelo Departamento , Case 3 = Busca pelo Cargo , Case 4 = Cancelar operação
        switch(resposta_tipo_digitar)
        {
            case '1':

              printf("DIGITE O NOME DO FUNCIONARIO\n");
            
              fgets(aux_nome , 60 , stdin);
            
              string_remove_line_break(aux_nome);

              for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
              {
                
                  if(strcmp(aux_nome , (Dados+i)->nome)==0)
                  {

                     printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO %s" , ID, (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo);
                     flag_busca=1;
                  }
            
              }

            break;
        


            case '2':

              printf("DIGITE O DEPARTAMENTO DO FUNCIONARIO\n");
            
              fgets(aux_departamento , 60 , stdin);
            
              string_remove_line_break(aux_departamento);

              for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
              {

                if(strcmp(aux_departamento , (Dados+i)->departamento)==0)
                {
                  printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO %s" , ID, (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo);
                  
                  flag_busca =1; 
                
                }
              
              }


            break;

            
            case '3':

              printf("DIGITE O CARGO DO FUNCIONARIO\n");
              fgets(aux_cargo , 60 , stdin);
              string_remove_line_break(aux_cargo);

              for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
              {
                 if(strcmp(aux_cargo , (Dados+i)->cargo)==0)
                 {
                    printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO %s" , ID, (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo);

                    flag_busca =1;
            
                 }
            
               }

            break;


            case '4':
              
              return;
            
            break;

            default :
           
            break;

        }
        
        //Entrada do ID do funcionario a ser excluido sendo armazenada na variavel do tipo int ID_delete
        
        if(flag_busca ==1 )
        {
           printf("\n\nDIGITE O ID A SER EXCLUIDO OU DIGITE 0 PARA CANCELAR\n");
        
           scanf("%d" , &ID_delete);
        

           //Validação da variavel ID_delete  (Não pode ser menor que zero ou maior que ID)
           while(ID_delete<0 || ID_delete>ID)
           {
              printf("ERROR - ID INVALIDO\n");
            
              printf("\n\nDIGITE O ID A SER EXCLUIDO OU DIGITE 0 PARA CANCELAR\n");
            
              scanf("%d" , &ID_delete);
            }

        }
        else
        {
            printf("\n\nNENHUM FUNCIONARIO ENCONTRADO\n\n");
            printf("\nPRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
            
            getchar();

            return;
        }


        system("cls");


        //Exclusão dos dados do funcionario a partir do ID_delete escolhido
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
    else 
    {   

        //Listando todos funcionarios presentes no registro Funcionario *Dados
        listar_funcionarios(Dados);

        //Entrada do ID do funcionario a ser excluido sendo armazenada na variavel do tipo int ID_delete

        printf("\n\nDIGITE O ID A SER EXCLUIDO OU DIGITE 0 PARA CANCELAR\n");
        
        scanf("%d" , &ID_delete);
        
        //Validação da variavel ID_delete  (Não pode ser menor que zero ou maior que a quantidade total de funcionarios)
        while(ID_delete<0 || ID_delete>quantidade_funcionarios)
        {
            printf("ERROR - ID INVALIDO");
            
            printf("\n\nDIGITE O ID A SER EXCLUIDO OU DIGITE 0 PARA CANCELAR\n");
            
            scanf("%d" , &ID_delete);
        }


        //Exclusão dos dados do funcionario a partir do ID_delete escolhido
        if(ID_delete>0)
        {
            for(i = ID_delete - 1 ; i<quantidade_funcionarios-1 ; i++)
            {
                strcpy((Dados+i)->nome , (Dados+i+1)->nome);
                
                strcpy((Dados+i)->departamento , (Dados+i+1)->departamento);
                
                strcpy((Dados+i)->cargo , (Dados+i+1)->cargo);
                
                (Dados+i)->salario = (Dados+i+1)->salario;
                
            }
            quantidade_funcionarios--;
        }




    }








}