#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char nomeG[30][1000], emailG[15][1000], sexoG[15][1000], enderecoG[30][1000], vacinadoG[4][1000];
char Rest_nomeG[30][1000], Rest_emailG[15][1000], Rest_sexoG[15][1000], Rest_enderecoG[30][1000];
int j=0, idG[1000], vacinaG[1000], cont=0, sair;
int Rest_vacinaG[1000], Rest_idG[1000];
double alturaG[1000], Rest_alturaG[1000];

int main(void) {
  void Menu();
  void imprimirUsuario();
  void BuscarID();
  void buscarEmail();
  void editarUsuario();
  void restaurarDados();
  void excluirUsuario();
  char nome[30], email[15], sexo[15], endereco[30],vacinado[4];
  char repetir,repetir2,repetir3,repetir4, repetir5,fem[]="Feminino", mas[]="Masculino", nd[]="Nao declarar",nao[]="Nao",sim[]="Sim";
  double altura;
  int opcao, i=1, id[1000], idFixo, tamanhoEmail, vacina;

  do {
    Menu();
    scanf("%i", &opcao);
    system("cls");
    fflush(stdin);
    switch (opcao) {
      case 1:
      id[i] = rand() % 1000;
      idFixo=id[i];
      printf("Usuario: %i\n", id[i]);
      printf("Digite o nome:\n");
      gets(nome);
      do {
        printf("Digite o email:\n");
        gets(email);
        tamanhoEmail=strlen(email);
        for (i = 0; i < tamanhoEmail; i++) {
          switch (email[i]) {
            case '@':
            repetir='N';
          }
        }
        if (repetir!='N')
          printf("Email deve conter @!!\n");
      } while(repetir!='N');
      repetir='S';
      do {
        printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n");
        gets(sexo);
        if ((strcmp(sexo,fem)==0) || (strcmp(sexo,mas)==0) || (strcmp(sexo,nd)==0))
          break;
        else{
          printf("Sexo Incorreto!!\n");
            repetir2='S';
        }
      } while(repetir2=='S');
      printf("Digite o endereco:\n");
      gets(endereco);
      do {
        printf("Digite a altura:\n");
        scanf("%lf", &altura);
        if ((altura>1)&&(altura<2)) {
          break;
        }
        else{
          printf("Altura Incorreta\n");
          repetir3='S';
        }
      } while(repetir3=='S');
      do {
        printf("Ja vacinou? (Sim/ Nao)\n");
        fflush(stdin);
        gets(vacinado);
        if ((strcmp(vacinado, sim)==0)||(strcmp(vacinado,nao)==0))
          repetir4='N';
        else
          printf("Digite Sim ou Nao!\n");
      } while(repetir4!='N');
      _Bool vacina = strcmp(sim, vacinado)==0;
      system("cls");
      printf("# Apos o cadastro escolha 7 para salvar!\n");
      break;
      case 2:
      editarUsuario();
      break;
      case 3:
      excluirUsuario();
      break;
      case 4:
      BuscarID();
      break;
      case 5:
      buscarEmail();
      break;
      case 6:
      imprimirUsuario(); // As vezes strings de nome dão erro!?
      break;
      case 7:
      if (idG[0] < 0) {
        fflush(stdin);
        strcpy(nomeG[0], nome);
        strcpy(emailG[0], email);
        strcpy(sexoG[0], sexo);
        strcpy(enderecoG[0], endereco);
        alturaG[0]=altura;
        vacinaG[0]=vacina;
        idG[0]=idFixo;
      }
      else{
        fflush(stdin);
        strcpy(nomeG[j], nome);
        strcpy(emailG[j], email);
        strcpy(sexoG[j], sexo);
        strcpy(enderecoG[j], endereco);
        alturaG[j]=altura;
        vacinaG[j]=vacina;
        idG[j]=idFixo;
        // Salva para restaurar
        strcpy(Rest_nomeG[j], nome);
        strcpy(Rest_emailG[j], email);
        strcpy(Rest_sexoG[j], sexo);
        strcpy(Rest_enderecoG[j], endereco);
        Rest_alturaG[j]=altura;
        Rest_vacinaG[j]=vacina;
        Rest_idG[j]=idFixo;
        j++;
        cont++;
      }
      break;
      case 8:
      restaurarDados();
      break;
    }
  } while(cont < 1000);
  return 0;
}

void Menu(){
  printf("1-Incluir usuario;\n");
  printf("2-Editar usuario;\n");
  printf("3-Excluir usuario;\n");
  printf("4-Buscar usuario pelo ID;\n");
  printf("5-Buscar usuario pelo email;\n");
  printf("6-Imprimir todos usuarios;\n");
  printf("7-Fazer backup de usuarios cadastrados;\n");
  printf("8-Restaurar dados;\n");
  printf("\nEscolha uma opcao:\n ");
}

void imprimirUsuario() {
  char sair;
  for (j=0; j<cont; j++){
    if (idG[j] > 0){
      printf("Usuario: %i\n", idG[j]);
      printf("Nome: %s\n", nomeG[j]);
      printf("Email: %s\n", emailG[j]);
      printf("Sexo: %s\n", sexoG[j]);
      printf("Altura: %.2f\n", alturaG[j]);
      printf("Endereco: %s\n", enderecoG[j]);
      printf("Vacinou: ");
      switch (vacinaG[j]) {
        case 1:
        printf("Sim\n");
        break;
        case 0:
        printf("Nao\n");
      }
      printf("\n");
    }
  }
  printf("\nDigite 1 para sair!\n");
  scanf("%c", &sair);
  system("cls");
}

void BuscarID(){
  int esquerda, direita, meio, idBusca, j, i, aux;
  char repetir, auxS[30], sair;
  esquerda=0;
  direita=cont;

  for (j = 0; j < cont-1; j++){
    for (i = 0; i < cont-1; i++){
      if (idG[i] > idG[i+1]){
        aux = idG[i];
        idG[i] = idG[i+1];
        idG[i+1] = aux;

        strcpy(auxS,nomeG[i]);
        strcpy(nomeG[i],nomeG[i+1]);
        strcpy(nomeG[i+1],auxS);

        strcpy(auxS,emailG[i]);
        strcpy(emailG[i],emailG[i+1]);
        strcpy(emailG[i+1],auxS);

        strcpy(auxS,sexoG[i]);
        strcpy(sexoG[i],sexoG[i+1]);
        strcpy(sexoG[i+1],auxS);

        strcpy(auxS,enderecoG[i]);
        strcpy(enderecoG[i],enderecoG[i+1]);
        strcpy(enderecoG[i+1],auxS);

        aux = alturaG[i];
        alturaG[i] = alturaG[i+1];
        alturaG[i+1] = aux;

        aux = vacinaG[i];
        vacinaG[i] = vacinaG[i+1];
        vacinaG[i+1] = aux;
      }
    }
  }
  printf("Digite o ID: \n");
  scanf("%i", &idBusca);
  do {
   meio=(esquerda+direita)/2;

   if(idG[meio]==idBusca){
     fflush(stdin);
     printf("Usuario: %i\n", idG[meio]);
     printf("Nome: %s\n", nomeG[meio]);
     printf("Email: %s\n", emailG[meio]);
     printf("Sexo: %s\n", sexoG[meio]);
     printf("Endereco: %s\n", enderecoG[meio]);
     printf("Altura: %.2f\n", alturaG[meio]);
     printf("Vacinou: ");
     switch (vacinaG[meio]) {
       case 1:
       printf("Sim\n");
       break;
       case 2:
       printf("Nao\n");
       break;
     }
     printf("\n\nDigite 1 para sair!\n");
     scanf("%c", &sair);
     system("cls");
     repetir='N';
   }
   if(idG[meio]>idBusca){
     direita=meio-1;
   }
   else{
     esquerda=meio+1;
   }
 }while(esquerda<=direita);
  if (repetir!='N') {
    printf("ID nao encotrado!\n");
    printf("Digite 1 para sair!\n");
    scanf("%i", &sair);
  }
}

void buscarEmail() {
  char emailBusca[30],i=0;
  char repetir,sair;
  printf("Digite o email: \n");
  gets(emailBusca);
  do {
    if (strcmp(emailBusca,emailG[i])==0) {
      printf("\n");
      fflush(stdin);
      printf("Usuario: %i\n", idG[i]);
      printf("Nome: %s\n", nomeG[i]);
      printf("Email: %s\n", emailG[i]);
      printf("Sexo: %s\n", sexoG[i]);
      printf("Endereco: %s\n", enderecoG[i]);
      printf("Altura: %.2f\n", alturaG[i]);
      printf("Vacinou: \n");
      switch (vacinaG[i]) {
        case 1:
        printf("Sim\n");
        break;
        case 2:
        printf("Nao\n");
        break;
      }
      repetir='N';
    }
    if ((i==cont)&&(repetir!='N'))
      printf("Email invalido");
    i++;
  } while((repetir!='N')&&(i<=cont));
  printf("\n\nDigite 1 para sair!\n");
  scanf("%c", &sair);
  system("cls");
}

void editarUsuario(){
  int idBusca, i=0, j, tamanhoEmail, sair, idValido;
  char nome[30], email[15], sexo[15], endereco[30],vacinado[4],verificar;
  char repetir,repetir2,repetir3,repetir4,fem[]="Feminino", mas[]="Masculino", nd[]="Nao declarar",nao[]="Nao",sim[]="Sim";
  double altura;

  printf("Digite o ID do usuario a ser editado:\n");
  scanf("%i", &idBusca);
  do {
    if (idBusca==idG[i]) {
      fflush(stdin);
      printf("Digite o nome:\n");
      gets(nomeG[i]);
      do {
        printf("Digite o email:\n");
        gets(email);
        strcpy(emailG[i], email);
        tamanhoEmail=strlen(email);
        for (j = 0; j < tamanhoEmail; j++) {
          switch (email[j]) {
            case '@':
            repetir='N';
          }
        }
        if (repetir!='N')
          printf("Email deve conter @!!\n");
      } while(repetir!='N');
      repetir='S';
      do {
        printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n");
        gets(sexoG[i]);
        if ((strcmp(sexoG[i],fem)==0) || (strcmp(sexoG[i],mas)==0) || (strcmp(sexoG[i],nd)==0))
          break;
        else{
          printf("Sexo Incorreto!!\n");
            repetir2='S';
        }
      } while(repetir2=='S');
      printf("Digite o endereco:\n");
      gets(enderecoG[i]);
      do {
        printf("Digite a altura:\n");
        scanf("%lf", &alturaG[i]);
        if ((alturaG[i]>1)&&(alturaG[i]<2)) {
          break;
        }
        else{
          printf("Altura Incorreta\n");
          repetir3='S';
        }
      } while(repetir3=='S');
      do {
        printf("Ja vacinou? (Sim/ Nao)\n");
        fflush(stdin);
        gets(vacinado);
        if ((strcmp(vacinado, sim)==0)||(strcmp(vacinado,nao)==0))
          repetir4='N';
        else
          printf("Digite Sim ou Nao!\n");
      } while(repetir4!='N');
      _Bool vacina = strcmp(sim, vacinado)==0;
      fflush(stdin);
      vacinaG[i]=vacina;
      idValido=1;
    }
    i++;
  } while((idValido!=1)||(i<cont));
  if (idValido!=1) {
    printf("ID Invalido\n");
  }
  printf("\nDigite 1 para sair!");
  scanf("%i", &sair);
  system("cls");
}

void restaurarDados(){
  int i;
  for(i=0; i<cont; i++){
    idG[i]=Rest_idG[i];
    strcpy(nomeG[i],Rest_nomeG[i]);
    strcpy(emailG[i],Rest_emailG[i]);
    strcpy(sexoG[i],Rest_sexoG[i]);
    strcpy(enderecoG[i],Rest_enderecoG[i]);
    alturaG[i]=Rest_alturaG[i];
    vacinaG[i]=Rest_vacinaG[i];
  }
}

void excluirUsuario(){
  int i, j, l=0, idBusca, aux, sair, excluidos=-1;
  char repetir,auxS[30];
  printf("Digite o ID:\n");
  scanf("%i", &idBusca);
  do {
    if (idBusca==idG[l]) {
      idG[l]=excluidos;
      for (j = 0; j < cont-1; j++){
        for (i = 0; i < cont-1; i++){
          if (idG[i] > idG[i+1]){
            aux = idG[i];
            idG[i] = idG[i+1];
            idG[i+1] = aux;

            strcpy(auxS,nomeG[i]);
            strcpy(nomeG[i],nomeG[i+1]);
            strcpy(nomeG[i+1],auxS);

            strcpy(auxS,emailG[i]);
            strcpy(emailG[i],emailG[i+1]);
            strcpy(emailG[i+1],auxS);

            strcpy(auxS,sexoG[i]);
            strcpy(sexoG[i],sexoG[i+1]);
            strcpy(sexoG[i+1],auxS);

            strcpy(auxS,enderecoG[i]);
            strcpy(enderecoG[i],enderecoG[i+1]);
            strcpy(enderecoG[i+1],auxS);

            aux = alturaG[i];
            alturaG[i] = alturaG[i+1];
            alturaG[i+1] = aux;

            aux = vacinaG[i];
            vacinaG[i] = vacinaG[i+1];
            vacinaG[i+1] = aux;
          }
        }
      }
      excluidos--;
      repetir='N';
      system("cls");
      break;
    }
    l++;
  } while((repetir!='N')&&(l<cont));
  if (repetir!='N') {
    printf("ID Invalido\n");
    printf("\nDigite 1 para sair!");
    scanf("%i", &sair);
    system("cls");
  }
}
