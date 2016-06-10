#include <stdio.h>
#include <stdlib.h>


struct usuario{
	char mail[50];
	int dni;
	char contrasena[15];
	char nombre[20];
	char apellido[20];
	char tipousuario[15];
	};

struct fiesta{
	int idfiesta;
	char descripcion[300];
	char nombre[100];
	char fechainicio[15];
	char fechafin[15];
	};

struct usuariofiesta{
	int idfiesta;
	char mail[50];
	};


int main()
{
    FILE *usuarios;
    FILE *fiestas;
    FILE *usuarioFiesta;
    struct usuario u;
    struct fiesta f;
    struct fiesta fie;
    struct usuariofiesta uf,uparty;
    int opcion;
    int contadordeID;
    contadordeID= 2;


    //registro de usuario
    strcpy(u.nombre, "juan");
    strcpy(u.mail,"juan@hotmail.com");
    strcpy(u.apellido, "fernandez");
    strcpy(u.tipousuario, "administrador");
    strcpy(u.contrasena, "juan");
    u.dni= 40254875;
    //usuarios = fopen("usuarios","wb");
    //fwrite(&u,sizeof(struct usuario),1,usuarios);
    //fclose(usuarios);

    //registro de una fiesta
    //strcpy(f.descripcion, "fiesta del trigo");
    //strcpy(f.nombre, "fiesta del trigo");
    //strcpy(f.fechainicio, "18/01/14");
    //strcpy(f.fechafin, "18/02/14");
    //f.idfiesta= 1;
    //fiestas = fopen ("fiestas", "wb");
    //fwrite(&f,sizeof(struct fiesta),1,fiestas);

    //otra fiesta
    //strcpy(fie.descripcion, "fiesta carnaval");
    //strcpy(fie.nombre, "fiesta con mucha comida");
    //strcpy(fie.fechainicio, "18/09/14");
    //strcpy(fie.fechafin, "18/11/14");
    //fie.idfiesta= 2;
    //fwrite(&fie,sizeof(struct fiesta),1,fiestas);
    //fclose(fiestas);

    //registro de USUARIOFIESTA
    //usuarioFiesta = fopen ("usuarioFiesta", "wb");
   // uf.idfiesta=1;
    //strcpy(uf.mail,u.mail);
    //uparty.idfiesta=2;
    //strcpy(uparty.mail,u.mail);
    //fwrite(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    //fwrite(&uparty,sizeof(struct usuariofiesta),1,usuarioFiesta);
    //printf("%d", k.idfiesta);
    //printf("%s", k.mail);
    //fclose(usuarioFiesta);
    opcion= 4;
    while (opcion !=0){

    printf("         CrazyFiesta            \n");
    printf("######################################\n");
    printf(" 1.- Registrar un usuario\n");
    printf(" 2.- Listado de Fiestas\n");
    printf(" 3.- Modificar contraseña\n");
    printf(" 4.- Listado de Usuarios\n");
    printf(" 5.- Dar de baja un usuario\n");
    printf(" 6.- Dar de Alta Fiesta\n");
    printf(" 7.- Dar de Baja Fiesta\n");
    printf(" 0.- Salir\n");;
    scanf ("%d", &opcion);
    switch(opcion){
        case 1:
            usuarios = fopen("usuarios","rb+");
            usuarioFiesta = fopen("usuarioFiesta", "rb+");
            registrarUsuario(u,usuarios,usuarioFiesta);
            fclose(usuarios);
            fclose(usuarioFiesta);
            break;

        case 2:
            usuarioFiesta = fopen("usuarioFiesta", "rb");
            fiestas = fopen ("fiestas", "rb");
            listadoFiesta(u,usuarioFiesta, fiestas);
            fclose(usuarioFiesta);
            fclose(fiestas);
            break;
        case 3:
            usuarios = fopen("usuarios","rb+");
            modificarContrasena (u,usuarios);
            fclose(usuarios);
            break;
        case 4:
            usuarioFiesta = fopen("usuarioFiesta", "rb");
            fiestas = fopen("fiestas","rb");
            listadoUsuarios(u,usuarioFiesta,fiestas);
            fclose(usuarioFiesta);
            fclose(fiestas);
            break;
        case 5:
            usuarios = fopen("usuarios","rb");
            usuarioFiesta = fopen("usuarioFiesta","rb+");
            dardebaja(u,usuarios,usuarioFiesta);
            break;
        case 6:
            fiestas = fopen ("fiestas","rb+");
            usuarioFiesta = fopen("usuarioFiesta", "rb+");
            contadordeID = AltaFiesta(contadordeID, fiestas,usuarioFiesta,u);
            fclose(fiestas);
            fclose(usuarioFiesta);
            break;
        case 7:
            fiestas = fopen("fiestas", "rb+");
            usuarios = fopen("usuarios", "rb");
            usuarioFiesta = fopen("usuarioFiesta", "rb+");
            BajaFiesta(u, f, fiestas, usuarios,usuarioFiesta);
            fclose(fiestas);
            fclose(usuarios);
            fclose(usuarioFiesta);
            break;
    }
}
    return 0;
}

void listadoFiesta(struct usuario u, FILE *usuarioFiesta, FILE *Fiestas);
int verificarPermiso(int idf,struct usuario u,FILE *usuarioFiesta);
void mostrarFiestas(struct fiesta f);
int verificarMail (char mail[], FILE *usuarios);
int verificadorContrasena(char contra[], FILE *usuarios, struct usuario u);
void listadoUsuarios(struct usuario, FILE *usuarioFiesta,FILE *fiestas);
void cambiarContrasena(struct usuario u, FILE *usuarios);
int AltaFiesta (int contadordeID,FILE *fiestas,FILE *usuarioFiesta, struct usuario u);
void BajaFiesta(struct usuario u, struct fiesta f, FILE *fiestas, FILE *usuarios,FILE *usuarioFiesta);
int EsAdministrador(struct usuario u, FILE *usuarios);
void dardebaja(struct usuario u,FILE *usuarios, FILE *usuarioFiesta);

void dardebaja(struct usuario u,FILE *usuarios, FILE *usuarioFiesta){
struct usuario us;
struct usuariofiesta uf;
char mail[30];
char mail2[30];
char aux[]="administrador";
int esven = 0,esadm = 0, coinc=0,idfaux;

printf("Ingrese el mail del usuario que quiere dar de baja: \n");
scanf("%s",mail);
fflush(stdin);

fread(&us,sizeof(struct usuario),1,usuarios);
while (!feof(usuarios)){
    if ((strcmp(us.mail,mail))==0){
        if ((strcmp(us.tipousuario,aux))==0){
         esven = 1;
        }
    }
    fread(&us,sizeof(struct usuario),1,usuarios);
}

if (esven == 1){
    printf("El usuario que ha ingresado es administrador y no puede darle de baja \n");
}

else {
    printf("Ingrese el id de la fiesta de la que quiere dar de baja al usuario: \n");
    scanf("%d",&idfaux);
    fflush(stdin);
    printf("Ingrese su mail:\n");
    scanf("%s",mail2);

    rewind(usuarios);
    fread(&us,sizeof(struct usuario),1,usuarios);
    while (!feof(usuarios)){
        if ((strcmp(us.mail,mail2))==0){
            if ((strcmp(us.tipousuario,aux))==0){
                esadm=1;
                }
        }
    fread(&us,sizeof(struct usuario),1,usuarios);
    }
    if (esadm==0){
        printf("Usted no es un usuario administrador y no puede dar de baja un usuario\n");
    }
    else {
    rewind(usuarioFiesta);
    fread(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    while (!feof(usuarioFiesta)){
              if ((uf.idfiesta==idfaux) && (strcmp(uf.mail,mail)==0)){
                uf.idfiesta = -1*idfaux;
                strcpy(uf.mail, "dadobaja");
                fseek(usuarioFiesta,-1*sizeof(struct usuariofiesta),SEEK_CUR);
                fwrite(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
                printf("La baja de usuario se ha realizado correctamente \n");
                break;
              }
                fread(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);

    }

}}}


void BajaFiesta(struct usuario u, struct fiesta f, FILE *fiestas, FILE *usuarios,FILE *usuarioFiesta){
    struct fiesta fie;
    struct usuariofiesta uf,uf1;
    int idf;
    int x;
    char marca [21];
    strcpy(marca,"(FIESTA ELIMINADA)");
    if (EsAdministrador(u, usuarios)==1){
        printf("Ingrese el ID de la fiesta que desea dar de baja: ");
        scanf("%d", &idf);
        rewind(fiestas);
        fread(&fie, sizeof(struct fiesta), 1, fiestas);
        while(!feof(fiestas)){
                if(fie.idfiesta==idf){
                printf("El nombre de la fiesta que desea eliminar es %s y su numero de ID es %d \n", fie.nombre, fie.idfiesta);
                printf("Seguro que desea dar de baja esta fiesta? \nPresione 1 para confirmar o cualquier otra tecla para cancelar ");
                scanf("%s", &x);
                    if (x=1){
                            fie.idfiesta= -1*fie.idfiesta;
                            strcpy(fie.descripcion,strcat(fie.descripcion,  marca));
                            fseek(fiestas,-1*sizeof(struct fiesta),SEEK_CUR);
                            fwrite(&fie,sizeof(struct fiesta),1,fiestas);
                            printf("La baja de fiesta se ha realizado correctamente \n");
                            fread(&uf, sizeof(struct usuariofiesta), 1, usuarioFiesta);

                            break;
                    }
                    else return;
               }
        fread(&fie, sizeof(struct fiesta), 1, fiestas);
        }
        printf("La fiesta no existe \n");
}
    else printf("Usted no posee los permisos suficientes para llevar acabo esta accion \n");
    }

int EsAdministrador(struct usuario u, FILE *usuarios){
if(strcmp(u.tipousuario, "administrador")==0){
    return 1;
}
else
        return 0;
}

int AltaFiesta (int contadordeID,FILE *fiestas,FILE *usuarioFiesta, struct usuario u){
    struct fiesta f;
    struct usuariofiesta uf;
    printf("Escriba el nombre de la fiesta: ");
    fflush(stdin);
    gets(f.nombre);
    printf("Ingrese la fecha inicio de la fiesta en formato dd/mm/aa: ");
    scanf("%s", &f.fechainicio);
    printf("Ingrese la fecha fin de la fiesta en formato dd/mm/aa: ");
    scanf("%s", &f.fechafin);
    printf("Ingrese una breve descripcion de la fiesta: ");
    fflush(stdin);
    gets(f.descripcion);
    contadordeID= contadordeID+1;
    f.idfiesta=  contadordeID;
    uf.idfiesta= f.idfiesta;
    strcpy(uf.mail, u.mail);
    fseek(fiestas, 0,SEEK_END);
    fseek(usuarioFiesta,0,SEEK_END);
    fwrite(&f,sizeof(struct fiesta),1, fiestas);
    fwrite(&uf,sizeof(struct usuariofiesta),1, usuarioFiesta);
    return contadordeID;
}

void listadoUsuarios(struct usuario u, FILE *usuarioFiesta, FILE *fiestas){
    struct usuariofiesta uf3,uf4;
    int pertenece,aux;
    pertenece = 1;
    printf("Ingrese el id de la fiesta de la que quiere obtener los usuarios: \n");
    scanf("%d",&aux);
    while (!feof(usuarioFiesta)){
        fread(&uf3,sizeof(struct usuariofiesta),1,usuarioFiesta);
        if ((uf3.idfiesta == aux) && ((strcmp(uf3.mail,u.mail))==0)){
                  pertenece=0;
        }}
    if (pertenece==1){
        printf("Usted no es administrador de esta fiesta y no puede ver el listado \n");
    }
    else if (pertenece==0) {
        rewind(usuarioFiesta);
        fread(&uf4,sizeof(struct usuariofiesta),1,usuarioFiesta);
        while (!feof(usuarioFiesta)){
            if (uf4.idfiesta == aux){
            printf("\n Mail: %s \n", uf4.mail);}
            fread(&uf4,sizeof(struct usuariofiesta),1,usuarioFiesta);
    }}}


void listadoFiesta(struct usuario u, FILE *usuarioFiesta, FILE *fiestas){
    struct usuariofiesta usu;
    struct fiesta fies;
    fread(&usu,sizeof(struct usuariofiesta),1,usuarioFiesta);
    while (!feof(usuarioFiesta)){
      if (strcmp (u.mail,usu.mail)== 0 ){
        rewind(fiestas);
        fread(&fies,sizeof(struct fiesta),1,fiestas);
        while ( !feof(fiestas)){
            if (fies.idfiesta==usu.idfiesta){
                mostrarFiestas(fies);
        }
        fread(&fies,sizeof(struct fiesta),1,fiestas);
      }
    }
    fread(&usu,sizeof(struct usuariofiesta),1,usuarioFiesta);
}
}

void mostrarFiestas(struct fiesta f){
    printf("fechainicio %s", f.fechainicio);
    printf("\nfechafin %s", f.fechafin);
    printf("\nidfiesta %d", f.idfiesta);
    printf("\ndescripcion %s", f.descripcion);
    printf("\nnombre %s\n\n", f.nombre);
}

void registrarUsuario(struct usuario u, FILE *usuarios,FILE *usuarioFiesta){
    struct usuario usu;
    struct usuariofiesta uf;
    int idf;
    printf("ingrese una id de una fiesta que quiera dar de alta al usuario: ");
    scanf("%d", &idf);
    if  (verificarPermiso(idf,u,usuarioFiesta)== 0){
        printf("ingrese mail: ");
        scanf("%s", &usu.mail);
        if (verificarMail(usu.mail,usuarios)== 0){
            printf("ingrese dni: ");
            scanf("%d", &usu.dni);
            printf("ingrese contraseña: ");
            scanf("%s", &usu.contrasena);
            printf("ingrese nombre: ");
            scanf("%s", &usu.nombre);
            printf("ingrese apellido: ");
            scanf("%s", &usu.apellido);
            printf("ingrese tipousuario: ");
            scanf("%s", &usu.tipousuario);
            uf.idfiesta= idf;
            strcpy(uf.mail,usu.mail);
            fseek(usuarios,0,SEEK_END);
            fseek(usuarioFiesta,0,SEEK_END);
            fwrite(&usu, sizeof(struct usuario), 1, usuarios);
            fwrite(&uf, sizeof(struct usuariofiesta), 1, usuarioFiesta);
    }
    else {printf("error email en uso\n");}
    }
    else printf("error usted no tiene permisos para esa fiesta\n");
}

int verificarPermiso(int idf,struct usuario u,FILE *usuarioFiesta){

    struct usuariofiesta uf;
    fread(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    while (!feof(usuarioFiesta)){
      if (idf==uf.idfiesta && strcmp(uf.mail,u.mail)==0){
            return 0;
}
        fread(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    }
    return 1;
}

int verificarMail (char mail[], FILE *usuarios){
    rewind(usuarios);
    struct usuario usu;
    fread(&usu,sizeof(struct usuario),1,usuarios);
    while (!feof(usuarios)){
       if (strcmp(usu.mail,mail)==0){
        return 1;
       }
       fread(&usu,sizeof(struct usuario),1,usuarios);
    }
    return 0;
}


void modificarContrasena (struct usuario u,FILE *usuarios){
    char contra[50], contraV[50];
    printf("escriba la contraseña actual:");
    scanf("%s",&contra);
    if (verificadorContrasena(contra,usuarios,u)==0){
        printf("escriba la nueva contraseña:");
        scanf("%s", &contra);
        printf ("vuelva a escribir la nueva contraseña:");
        scanf("%s", &contraV);
        if (strcmp(contra,contraV)== 0){
            strcpy(u.contrasena,contra);
            cambiarContrasena(u,usuarios);
        }
    }
    else printf("la contraseña que escribio no es la actual vuelva a intentarlo\n\n");
}

int verificadorContrasena(char contra[], FILE *usuarios, struct usuario u){
    struct usuario usu;
    rewind(usuarios);
    fread(&usu,sizeof(struct usuario),1,usuarios);
    while (!feof(usuarios)){
       if (strcmp(usu.mail,u.mail)== 0){
           if (strcmp(contra,usu.contrasena)==0){
            return 0;
           }
       }
       fread(&usu,sizeof(struct usuario),1,usuarios);
       }
       return 1;
}



void cambiarContrasena(struct usuario u, FILE *usuarios){
    struct usuario usu;
    rewind(usuarios);
    fread(&usu,sizeof(struct usuario),1,usuarios);
    while (!feof(usuarios)){
        if (strcmp(usu.mail,u.mail)==0){
            fseek(usuarios,-128,SEEK_CUR);
            fwrite(&u, sizeof(struct usuario), 1, usuarios);
            printf ("esta es la contraseña nueva: %s\n", u.contrasena);
            break;
        }
       fread(&usu,sizeof(struct usuario),1,usuarios);
    }
}
