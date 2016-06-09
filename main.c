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
	char nombre[40];
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
    struct usuariofiesta uf,k;
    int opcion;

    //registro de usuario
    strcpy(u.nombre, "juan");
    strcpy(u.mail,"juan@hotmail.com");
    strcpy(u.apellido, "fernandez");
    strcpy(u.tipousuario, "administrador");
    strcpy(u.contrasena, "juan");
    u.dni= 40254875;
    usuarios = fopen("usuarios","wb");
    fwrite(&u,sizeof(struct usuario),1,usuarios);
    fclose(usuarios);

    //registro de una fiesta
    strcpy(f.descripcion, "fiesta del trigo");
    strcpy(f.nombre, "fiesta del trigo");
    strcpy(f.fechainicio, "18/01/14");
    strcpy(f.fechafin, "18/02/14");
    f.idfiesta= 1;
    fiestas = fopen ("fiestas", "wb");
    fwrite(&f,sizeof(struct fiesta),1,fiestas);
    fclose(fiestas);

    //registro de USUARIOFIESTA
    usuarioFiesta = fopen ("usuarioFiesta", "wb");
    uf.idfiesta=1;
    strcpy(uf.mail,u.mail);
    fwrite(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    fread(&k,sizeof(struct usuariofiesta),1,usuarioFiesta);
    printf("%d", k.idfiesta);
    printf("%s", k.mail);
    fclose(usuarioFiesta);
    opcion= 4;
    while (opcion !=0){

    printf("         CrazyFiesta            \n");
    printf("######################################\n");
    printf(" 1.- Registrar un usuario\n");
    printf(" 2.- Listado de Fiestas\n");
    printf(" 3.- Modificar contraseña\n");
    printf(" 4.- Listado de Usuarios\n");
    printf(" 0.- Salir\n");;
    scanf ("%d", &opcion);
    switch(opcion){
        case 1:
            usuarios = fopen("usuarios","rb");
            usuarioFiesta = fopen("usuarioFiesta", "rb");
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
    }
}
    return 0;
}

void listadoFiesta(struct usuario u, FILE *usuarioFiesta, FILE *Fiestas);
int verificarPermiso(int idf,struct usuario u,FILE *usuarioFiesta);
void mostrarFiestas(struct fiesta f);
int verificarMail (char mail[], FILE *usuarios);
int verificadorContrasena(char contra[], FILE *usuarios, struct usuario u);
void cambiarContrasena(struct usuario u, FILE *usuarios);
void listadoUsuarios(struct usuario, FILE *usuarioFiesta,FILE *fiestas);
void registrarUsuario(struct usuario, FILE *usuarios, FILE *usuarioFiesta);

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
        while (!feof(usuarioFiesta)){
            fread(&uf4,sizeof(struct usuariofiesta),1,usuarioFiesta);
            if (uf4.idfiesta == aux){
            printf("\n Mail: %s \n", uf4.mail);
    }}}}
    

void listadoFiesta(struct usuario u, FILE *usuarioFiesta, FILE *fiestas){
    struct usuariofiesta usu;
    struct fiesta fies;
    while (!feof(usuarioFiesta)){
      fread(&usu,sizeof(struct usuariofiesta),1,usuarioFiesta);
      if (strcmp (u.mail,usu.mail)== 0 ){
        rewind(fiestas);
        while ( !feof(fiestas)){
            fread(&fies,sizeof(struct fiesta),1,fiestas);
            if (fies.idfiesta==usu.idfiesta){
                mostrarFiestas(fies);
        }
      }
    }
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
            fwrite(&usu, sizeof(struct usuario), 1, usuarios);
            fwrite(&uf, sizeof(struct usuariofiesta), 1, usuarioFiesta);
    }
    else {printf("error email en uso");}
    }
    else printf("error usted no tiene permisos para esa fiesta");
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
        printf("escriba la nueva contraseña");
        scanf("%s", &contra);
        printf ("vuelva a escribir la nueva contraseña");
        scanf("%s", &contraV);
        if (strcmp(contra,contraV)== 0){
            strcpy(u.contrasena,contra);
            cambiarContrasena(u,usuarios);
        }
    }
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
    int con=1;
    struct usuario usu;
    rewind(usuarios);
    fread(&usu,sizeof(struct usuario),1,usuarios);
    while (!feof(usuarios)){
        if (strcmp(usu.mail,u.mail)==0){
            con=0;
        }
       fread(&usu,sizeof(struct usuario),1,usuarios);
    }
    if (con==0){
        fseek(usuarios,-128,SEEK_CUR);
        fwrite(&u, sizeof(struct usuario), 1, usuarios);
        printf ("esta es la contraseña nueva: %s", u.contrasena);
    }
}
