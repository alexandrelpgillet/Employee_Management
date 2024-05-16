#include "struct+func.h"
#include <stdio.h>
#include <stdlib.h>



void listar_funcionarios(Funcionario *Dados)
{

    int i;
    int ID;
    
    if(quantidade_funcionarios>0)
    {
        printf("-----------LISTA DE TODOS OS FUNCIONARIOS DA EMPRESA-----------\n");
        
    }
    else
    {
        printf("ERROR- LISTA DE FUNCIONARIOS VAZIA \n");
        

    }



    for(i=0 , ID=1 ; i<quantidade_funcionarios ; i++ , ID++)
    {

        printf("%d)NOME = %s | DEPARTAMENTO = %s | CARGO = %s | SALARIO = R$ %.2f\n\n" , ID , (Dados+i)->nome , (Dados+i)->departamento , (Dados+i)->cargo , (Dados+i)->salario);
        
    }

    printf("\nPRRESIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
    
    getchar();
    
    system("cls");

}

