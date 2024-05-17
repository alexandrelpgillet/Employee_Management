#include "struct+func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscar_funcionario(Funcionario *Dados)
{
    //Variaveis usadas na função
    char busca[60];
    int i ;
    int ID;
    int flag_busca_vazia=0;


    //Verificar se existe funcionario no sistema para realizar busca
    if(quantidade_funcionarios>0)
    {   

        
         printf("DIGITE O NOME DO FUNCIONARIO QUE DESEJA ENCONTRAR OU O DEPARTAMENTO CUJO OS FUNCIONARIOS VOCÊ DESEJA BUSCAR OU O CARGO DOS FUNCIONARIOS QUE VOCÊ DESEJA BUSCAR\n");

         fgets(busca, 60 , stdin);
        
         
         //REUTILIZAR A FUNÇÃO STRING_CADASTRO_VALIDATION PARA REALIZAR O TRATAMENTO (remover \n final) E A VALIDAÇÃO DA STRING "busca"
         string_cadastro_validation(busca , "NOME OU DEPARTAMENTO OU CARGO DO FUNCIONARIO(s)",60);

         
         system("cls");


         printf("---------LISTA DE FUNCIONARIO(s) ENCONTRADOS A PARTIR DA BUSCA-------------\n");
        



         //Listar os registros cujo os Dados+i->nome , departamento ou cargo sejam iguais a string "busca"

         for(i=0 , ID=1; i<quantidade_funcionarios ; i++ , ID++)
         {
             if(strcmp(busca , (Dados+i)->nome) == 0 || strcmp(busca , (Dados+i)->departamento) == 0 || strcmp(busca , (Dados+i)->cargo) ==0)
             {

                 printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO = %s | SALARIO = R$ %.2f \n" , ID , (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo , (Dados+i)->salario);

                 flag_busca_vazia++;

             }
         }
        

         //Caso não seja encontrado de um registro que possua a mesma string de "busca"

         if(flag_busca_vazia==0)
         {
            printf("\n\nNENHUM DADO ENCONTRADO DURANTE A BUSCA NO SISTEMA\n");
            return -1;
         }



        

    }
    else
    {
        printf("ERROR- LISTA DE FUNCIONARIOS VAZIA\n");
    }
    




    
 return 0;
}
