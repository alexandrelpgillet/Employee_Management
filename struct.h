#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED


typedef struct 
{
    char nome[20];
    char sobrenome[40];
    char idade_dia[2];
    char idade_mes[2];
    char idade_ano[4];
    char departamento[20];
    char cargo[20];
    float salario;

}Funcionario;


#endif