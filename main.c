#include "help.h"

int main(){
setlocale(LC_ALL,"PORTUGUESE");
char opc;
char cpf[14];
cliente c;
opc=menu();
do{
    switch (opc)
    {
    case '1':
        system("cls");
        fflush(stdin);
        printf("// ----- // ----- // BUSCA HÓSPEDE // ----- // ----- // \n\n");
        printf("\nDigite o cpf que será buscado: ");
        gets(cpf);
        busca_cliente(&cpf);
    break;

    case '2':
        cadastra_cliente (c);

    break;

    case '3':
        printf("\nChamar função att...\n\n");

    break;

    case '4':
        printf("\nChamar funcao remove...\n\n");

    break;

    case '5':
        imprime_cliente(c);
    break;

    case '6':
        printf("\nChamar funcao relatório...\n\n");
    break;

    case '9':
    break;

    default:
    printf("\nOpção inválida!\n\n");
    break;
  }
  opc=menu();
}while (opc!='9');
return 0;
}


char menu (){
char op;
printf("\n\n// ----- // ----- // CADASTRO HÓSPEDE // ----- // ----- // \n\n[1] - Buscar por cadastro \n[2] - Cadastrar novo\n[3] - Atualizar cadastro\n[4] - Remover cadastro\n[5] - Imprimir todos cadastrados\n[6] - Gerar relatório\n[9] - Finalizar \n-------------------------------\nEntre com a sua opção: ");
scanf("\n%c",&op);
return (op);
}


char busca_cliente(char *cpf){
hos = fopen("hospede.dat", "r");
cliente c;
if (hos == NULL) {
    puts("Nao foi possivel abrir o arquivo!\n");
    exit(1);
}
else
{
    while(fread(&c, sizeof(cliente), 1, hos)==1){
        if(strcmp(cpf, c.cpf)==0)
        {
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            printf("\n\nCadastro existente encontrado\n\n");
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            system("pause");
            system("cls");
            return cpf;
        }
    else
    {
        printf("\n// ----- // ----- //// ----- // ----- // \n");
        printf("\n\nCliente ainda não cadastrado\n\n");
        printf("\n// ----- // ----- //// ----- // ----- // \n");
        system("pause");
        system("cls");
        return NULL;
    };

    };
    fclose(hos);
}
}

void cadastra_cliente(){
system("cls");
printf("// ----- // ----- // CADASTRO HÓSPEDE // ----- // ----- // \n\n");
printf("Digite o CPF:");
cliente c;
scanf("%s", c.cpf);
hos = fopen("hospede.dat", "ab");
int val;
if (hos == NULL) {
    puts("Nao foi possivel abrir o arquivo!\n");
    exit(1);
}
else{
    val=busca_cliente(c.cpf);
    if (val==NULL)
        {
        fflush(stdin);
        printf("Nome: ");
        gets(c.nome);
        printf("Sobrenome: ");
        gets(c.sobrenome);
        printf("Telefone: ");
        gets(c.telefone);
        printf("Sexo: ");
        scanf("%c", &c.sexo);
        printf("Idade:");
        scanf("%d", &c.idade);
        fwrite(&c,sizeof (cliente),1, hos);
        fclose(hos);
        }
        }
system("cls");
}

void imprime_cliente(cliente c){
system("cls");
hos = fopen("hospede.dat", "rb");
if (hos == NULL) {
    puts("Nao foi possivel abrir o arquivo!\n");
    exit(1);
}
else
{
    printf("\n// ----- // ----- // LISTA DE CADASTROS // ----- // ----- // \n");
    while(fread(&c, sizeof(cliente), 1, hos)==1)
    {
        printf("\nCPF: %s \n", c.cpf);
        printf("Nome: %s \n", c.nome);
        printf("Sobrenome: %s \n", c.sobrenome);
        printf("Telefone: %s \n", c.telefone);
        printf("Sexo: %c \n", c.sexo);
        printf("Idade: %d ", c.idade);
        printf("\n// ----- // ----- //// ----- // ----- // \n");
    }
    fclose(hos);
}
system("pause");
system("cls");
}



