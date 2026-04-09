#include <stdio.h>
#include <string.h>

//RESOLVER ISSO

/* Escreva um algoritmo que solicite Nome, Sexo, idade e tres notas de N alunos em uma turma e ao final apresente: 
    b) controle de resposta ................................................. feito
   	1) Total de Alunos cadastrados........................................... feito
   	2) A media das idades dos alunos da turma................................ feito
   	3) Quantidade de alunos aprovados........................................ feito
	3.1) Quantidade reprovados............................................... feito
   	4) Percentual de aprovacao por sexo (Masculinos e Femininos) ............ feito
	5) Relatorio de alunos aprovados e reprovados............................ feito
	6) Permitir ao usuario configurar Quantidade de provas e Media aprovacao. feito
	5) Media por idade ......................................................
	5.1) idade a ser analisada ..............................................
	6) Adicionar menu .......................................................
	7) Fazer graficos .......................................................
	8) banco de dados base ..................................................
	9) colocar em funcoes ...................................................
*/

struct Aluno //struct para organização dos dados
{
    char nome[50];
    char sexo;
    int idade;
    float notas[10];
    float mediaAluno;
    bool aprovacao;
};


int main() {
    //VARIÁVEIS
    Aluno turma[100];
    int qtdAlunos, qtdProvas, qtdAprovados = 0, qtdReprovados = 0; //vars de controle
    float media;
    int totIdades = 0, alunasAprovadas = 0, alunosAprovados = 0, alunos = 0, alunas = 0; // somas para calculo de medias, e totais
    float percAprovFem, percAprovMasc;

    do { //variavel de controle para preenchimento da turma
        printf("Quantos alunos na turma: ");
        scanf("%d", &qtdAlunos);
        if(qtdAlunos <= 0 || qtdAlunos > 100){
            printf("\e[0;31mDigite um numero maior que zero e menor que 100\e[0m\n"); //mensagem de erro
        }
    } while(qtdAlunos <= 0 || qtdAlunos > 100);

    do { //variavel de controle para preenchimento de notas
    printf("Quantas avaliacoes na turma: ");
    scanf("%d", &qtdProvas);
    if(qtdProvas <= 0 || qtdProvas > 11){
        printf("\e[0;31mDigite um numero maior que zero e menor que 11\e[0m\n"); //mensagem de erro
    }
    } while(qtdProvas <= 0 || qtdProvas > 11);

    do { //variavel de controle para definiçao da média
    printf("Qual a media: ");
    scanf("%f", &media);
    if(media <= 0){
        printf("\e[0;31mDigite um numero maior que zero\e[0m\n"); //mensagem de erro
    }
    } while(media <= 0);

    getchar(); //pega o enter
    printf("\n"); //inicio dos registros.
    
    for(int i = 1; i <= qtdAlunos; i++){ // for para preenchimento dos dados
        float totNotas = 0;
        //input do nome
        printf("Digite o nome do %d aluno: ", i); 
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        turma[i].nome[strlen(turma[i].nome) - 1] = '\0';

        //input do genero
        do{
            printf("Digite o genero de %s: ", turma[i].nome);
            scanf("%c", &turma[i].sexo);
            getchar(); // limpa o '\n' do buffer
            if(turma[i].sexo != 'f' && turma[i].sexo != 'm' && turma[i].sexo != 'F' && turma[i].sexo != 'M'){
                printf("\e[0;31mPor favor insira M ou F\e[0m\n");//mensagem de erro
            }
            if(turma[i].sexo == 'f' || turma[i].sexo == 'F'){
                alunas += 1;
            }
            if(turma[i].sexo == 'm' || turma[i].sexo == 'M'){
                alunos += 1;
            }
            
        }while(turma[i].sexo != 'f' && turma[i].sexo != 'm' && turma[i].sexo != 'F' && turma[i].sexo != 'M'); //checar o livro logica de programação. SE FALSO REPETE

        //input de idade
        do{
            printf("Digite a idade de %s: ", turma[i].nome);
            scanf("%d", &turma[i].idade);
            totIdades += turma[i].idade;
            getchar();
            if(turma[i].idade <= 0 || turma[i].idade > 120){
                printf("\e[0;31mPor favor insira uma idade positiva e menor que 120\e[0m\n"); //mensagem de erro
            }
        }while(turma[i].idade <= 0 || turma[i].idade > 120);

        //input de notas e calculo da media
        for(int j = 1;j <= qtdProvas; j++){
            printf("Digite a %d nota: ", j);
            scanf("%f", &turma[i].notas[j]);
            totNotas += turma[i].notas[j];
            turma[i].mediaAluno = (totNotas / qtdProvas); //calculo da media individual
            getchar();
        }

        //resultado de aprovação
        if(turma[i].mediaAluno >= media){
            turma[i].aprovacao = true;
            qtdAprovados += 1; 
            if(turma[i].sexo == 'f' || turma[i].sexo == 'F'){
                alunasAprovadas += 1;
            }
            if(turma[i].sexo == 'm' || turma[i].sexo == 'M'){
                alunosAprovados += 1;
            }
        }
        else if (turma[i].mediaAluno < media){
            turma[i].aprovacao = false;
            qtdReprovados += 1;
        }

        printf("\n"); // inicio de um novo registro
    }//fim do for
    
    //RESOLVER ISSO
    percAprovFem = alunasAprovadas / alunas * 100; //porcentagem de aprov Masc
    percAprovMasc = alunosAprovados / alunos * 100; //porcentagem de aprov Fem

    //print dos resultados gerais
    printf("\e[0;34m\n---RESULTADOS---\e[0m\n\n");
    printf("Total de alunos: %d\n", qtdAlunos);
    printf("Media das idades: %d\n", (totIdades / qtdAlunos)); // uso unico entao nao vou fazer outra var.
    printf("Total de aprovados: %d\n", qtdAprovados);
    printf("Total de reprovados: %d\n", qtdReprovados);
    printf("Porcentagem de alunos aprovados: %.2f\n", percAprovMasc);
    printf("Porcentagem de alunas aprovadas: %.2f\n", percAprovFem);

    //relatorio de aprovados
    printf("\e[0;34m\n---APROVADOS---\e[0m\n\n");
    for(int i = 1; i <= qtdAlunos; i++){
        if(turma[i].aprovacao == true){
            int numerador = 1;
            printf("%d: %s\n",numerador, turma[i].nome);
            numerador++;
        }
    }

    //relatorio de reprovados
    printf("\e[0;34m\n---REPROVADOS---\e[0m\n\n");
    for(int i = 1; i <= qtdAlunos; i++){
        if(turma[i].aprovacao == false){
            int numerador = 1;
            printf("%d: %s\n",numerador, turma[i].nome);
            numerador++;
        }
    }
}
