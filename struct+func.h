#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED



//VARIAVEL GLOBAL DE CONTROLE DE QUANTIDADE DE USUÁRIOS DA EMPRESA
int quantidade_funcionarios=0;



//REGISTRO QUE ARMAZENA OS DADOS DOS FUNCIONARIOS 

typedef struct 
{
    char nome[60];
    char departamento[20];
    char cargo[20];
    float salario;

}Funcionario;





//FUNÇÕES USADAS NA func_cadastro_funcionario.c PARA REALIZAR CADASTRO DO FUNCIONARIO NO SISTEMA


void flush_in();

void string_remove_line_break(char string[60]);

void string_cadastro_validation(char string[60], char *label , int char_size);

void cadastro_funcionario(Funcionario *Dados);



//OUTRAS FUNÇÕES A SEREM IMPLEMENTADAS ....




#endif