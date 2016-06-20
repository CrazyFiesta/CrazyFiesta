#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

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


int main(int argc,char* argv[])
{
    FILE *usuarios;
    FILE *fiestas;
    FILE *usuarioFiesta;
    FILE *IDactualFiesta;
    struct usuario u;
    struct fiesta f;
    struct fiesta fie;
    struct usuariofiesta uf,uparty;
    int opcion;

    char t[15];
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[15];
    strftime(output,15,"%d/%m/%y",tlocal);
    strcpy(t,output);


   /* //idactual creando
    IDactualFiesta= fopen("idfiestas","wb");
    int contadordeID= 3;
    fwrite(&contadordeID,sizeof (int),1,IDactualFiesta);
    fclose(IDactualFiesta);

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

    //otra fiesta
    strcpy(fie.descripcion, "fiesta carnaval");
    strcpy(fie.nombre, "fiesta con mucha comida");
    strcpy(fie.fechainicio, "18/09/14");
    strcpy(fie.fechafin, "18/11/14");
    fie.idfiesta= 2;
    fwrite(&fie,sizeof(struct fiesta),1,fiestas);
    fclose(fiestas);

    //registro de USUARIOFIESTA
    usuarioFiesta = fopen ("usuarioFiesta", "wb");
    uf.idfiesta=1;
    strcpy(uf.mail,u.mail);
    uparty.idfiesta=2;
    strcpy(uparty.mail,u.mail);
    fwrite(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    fwrite(&uparty,sizeof(struct usuariofiesta),1,usuarioFiesta);
    fclose(usuarioFiesta);*/
    opcion= 4;
    while (opcion !=0){

    printf("         CrazyFiesta            \n");
    SetColor(3);
    printf("######################################\n");
    SetColor(15);
    printf(" 1.- Registrar un usuario\n");
    printf(" 2.- Listado de Fiestas\n");
    printf(" 3.- Modificar contraseña\n");
    printf(" 4.- Listado de Usuarios\n");
    printf(" 5.- Dar de baja un usuario\n");
    printf(" 6.- Dar de Alta Fiesta\n");
    printf(" 7.- Dar de Baja Fiesta\n");
    printf(" 8.- Modificar Fiesta\n");
    printf(" 0.- Salir\n");
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
            fclose(usuarios);
            fclose(usuarioFiesta);
            break;
        case 6:
            fiestas = fopen ("fiestas","rb+");
            usuarioFiesta = fopen("usuarioFiesta", "rb+");
            IDactualFiesta= fopen("idfiestas","rb+");
            AltaFiesta(IDactualFiesta, fiestas,usuarioFiesta,u);
            fclose(IDactualFiesta);
            fclose(fiestas);
            fclose(usuarioFiesta);
            break;
        case 7:
            fiestas = fopen("fiestas", "rb+");
            usuarios = fopen("usuarios", "rb");
            usuarioFiesta = fopen("usuarioFiesta", "rb+");
            BajaFiesta(u, f, fiestas, usuarios,usuarioFiesta,t);
            fclose(fiestas);
            fclose(usuarios);
            fclose(usuarioFiesta);
            break;
        case 8:
            fiestas = fopen("fiestas", "rb+");
            ModificarFiesta(f, fiestas);
            fclose(fiestas);
            break;
    }
}
    return 0;
}

void listadoFiesta(struct usuario u, FILE *usuarioFiesta, FILE *Fiestas);
int verificarPermiso(int idf,struct usuario u,FILE *usuarioFiesta);
void mostrarFiestas(struct fiesta f);
int verificarMail (char mail[], FILE *usuarioFiesta,int);
int verificadorContrasena(char contra[], FILE *usuarios, struct usuario u);
void listadoUsuarios(struct usuario, FILE *usuarioFiesta,FILE *fiestas);
void cambiarContrasena(struct usuario u, FILE *usuarios);
void AltaFiesta (FILE* IDactualFiesta,FILE *fiestas,FILE *usuarioFiesta, struct usuario u);
void BajaFiesta(struct usuario u, struct fiesta f, FILE *fiestas, FILE *usuarios,FILE *usuarioFiesta, char tiempo[]);
int EsAdministrador(struct usuario u, FILE *usuarios);
void dardebaja(struct usuario u,FILE *usuarios, FILE *usuarioFiesta);
int fiestaActiva(char tiempo[],int idf,FILE *fiestas);
void ModificarFiesta(struct fiesta f, FILE *fiestas);
void SetColor(int);
void registrarUsuario(struct usuario, FILE *usuarios,FILE *usuarioFiesta, FILE *fiestas);
int verificarf(int,FILE *fiestas);
int verificartuc(char []);

void ModificarFiesta(struct fiesta f, FILE *fiestas){
struct fiesta fie;
int idf;
char nombre[100];
char descripcion[300];
char fechainicio[15];
char fechafin[15];
int x;
int aux;
aux=0;
int opcion;
//if es administrador...//
printf("Ingrese el ID de la fiesta que desea modificar: ");
scanf("%d", &idf);
rewind(fiestas);
opcion=4;
fread(&fie, sizeof(struct fiesta),1, fiestas);
while(!feof(fiestas)){
    if(fie.idfiesta==idf){
        aux=1;
        printf("El nombre de la fiesta que desea modificar es %s.\n", fie.nombre);
        SetColor(14);
        printf("Seguro que desea modificar esta fiesta? \nPresione 1 para confirmar o cualquier otra tecla para cancelar\n");
        SetColor(15);
        scanf("%d", &x);
        if(x==1){
            while(opcion !=0){
                printf("           Modificar Fiesta           \n");
                printf("__________________________________________\n");
                printf(" 1.- Modificar nombre\n");
                printf(" 2.- Modificar fecha inicio\n");
                printf(" 3.- Modificar fecha fin\n");
                printf(" 4.- Modificar descripcion\n");
                printf(" 0.- Salir\n");
                scanf("%d", &opcion);
                switch(opcion){
                case 0:
                    return ;

                 case 1:
                     printf("        Modificar nombre           \n");
                     printf("________________________________________\n");
                     printf("Ingrese el nuevo nombre de la fiesta: \n");
                     fflush(stdin);
                     gets(nombre);
                     strcpy(fie.nombre, nombre);
                     fseek(fiestas, -1*sizeof(struct fiesta), SEEK_CUR);
                     fwrite(&fie, sizeof(struct fiesta),1, fiestas);
                     printf("La modificacion del nombre se ha realizado correctamente.\n");

                     break;

                 case 2:
                    printf("          Modificar fecha inicio           \n");
                    printf("______________________________________________\n");
                    printf("Ingrese la nueva fecha de inicio en formato dd/mm/aa: \n");
                    scanf("%s", fechainicio);
                    strcpy(fie.fechainicio, fechainicio);
                    fseek(fiestas, -1*sizeof(struct fiesta), SEEK_CUR);
                    fwrite(&fie, sizeof(struct fiesta),1, fiestas);
                    printf("La modificacion de la fecha de inicio se ha realizado correctamente.\n");

                    break;

                 case 3:
                    printf("         Modificar fecha fin               \n");
                    printf("______________________________________________\n");
                    printf("Ingrese la nueva fecha de fin en formato dd/mm/aa: \n");
                    scanf("%s", &fechafin);
                    strcpy(fie.fechafin, fechafin);
                    fseek(fiestas, -1*sizeof(struct fiesta), SEEK_CUR);
                    fwrite(&fie, sizeof(struct fiesta), 1, fiestas);
                    printf("La modificacion de la fecha de inicio se ha realizado correctamente.\n");

                    break;

                 case 4:
                    printf("         Modificar descripcion              \n");
                    printf("_______________________________________________\n");
                    printf("Ingrese la nueva descripcion: \n");
                    fflush(stdin);
                    gets(descripcion);
                    strcpy(fie.descripcion, descripcion);
                    fseek(fiestas, -1*sizeof(struct fiesta), SEEK_CUR);
                    fwrite(&fie, sizeof(struct fiesta), 1, fiestas);
                    printf("La modificacion de la descripcion se ha realizado correctamente.\n");

                    break;
                    }

            }
        }
        else return;
    }
    fread(&fie, sizeof(struct fiesta),1, fiestas);
}
if(aux==0){
    SetColor(4);
    printf("La fiesta no existe");
    SetColor(15);
}

return;
}

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
    SetColor(4);
    printf("El usuario que ha ingresado es administrador y no puede darle de baja \n");
    SetColor(15);
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
    	SetColor(4);
        printf("Usted no es un usuario administrador y no puede dar de baja un usuario\n");
        SetColor(15);
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

    }
}}

void BajaFiesta(struct usuario u, struct fiesta f, FILE *fiestas, FILE *usuarios,FILE *usuarioFiesta, char tiempo[]){
    struct fiesta fie;
    struct usuariofiesta uf,uf1;
    int idf;
    int x;
    int aux;
    aux=0;
    char marca [21];
    strcpy(marca,"(FIESTA ELIMINADA)");
    //if (EsAdministrador(u, usuarios)==1){
        printf("Ingrese el ID de la fiesta que desea dar de baja: ");
        scanf("%d", &idf);
        if (fiestaActiva(tiempo,idf,fiestas)==0){
        rewind(fiestas);
        fread(&fie, sizeof(struct fiesta), 1, fiestas);
        while(!feof(fiestas)){
                if(fie.idfiesta==idf){
                aux=1;
                printf("El nombre de la fiesta que desea eliminar es %s y su numero de ID es %d \n", fie.nombre, fie.idfiesta);
                SetColor(14);
                printf("Seguro que desea dar de baja esta fiesta? \nPresione 1 para confirmar o cualquier otra tecla para cancelar ");
                SetColor(15);
                scanf("%d", &x);
                    if (x == 1){
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
        if (aux==0){
        	SetColor(4);
            printf("La fiesta no existe \n");
            SetColor(15);
        }
}
    else {
    	SetColor(14);
    	printf("La fiesta todavia sigue activa \n");
    	SetColor(15);
    }}
    //else printf("Usted no posee los permisos suficientes para llevar acabo esta accion \n");
    //}

int fiestaActiva(char tiempo[],int idf,FILE *fiestas){
    struct fiesta fie;
    fread(&fie, sizeof(struct fiesta), 1, fiestas);
    while (!feof(fiestas)){
        if (fie.idfiesta== idf){
            if (strcmp(tiempo,fie.fechafin)==1)
                return 1;
        }
    fread(&fie, sizeof(struct fiesta), 1, fiestas);
    }
    return 0;
 }

int EsAdministrador(struct usuario u, FILE *usuarios){
if(strcmp(u.tipousuario, "administrador")==0){
    return 1;
}
else
        return 0;
}

void AltaFiesta (FILE *IDactualFiesta,FILE *fiestas,FILE *usuarioFiesta, struct usuario u){
    struct fiesta f;
    struct usuariofiesta uf;
    int con;
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
    fread(&con,sizeof(int),1,IDactualFiesta);
    con= con+1;
    fseek(IDactualFiesta,-1*sizeof(int),SEEK_CUR);
    fwrite(&con,sizeof (int),1,IDactualFiesta);
    f.idfiesta=  con;
    uf.idfiesta= f.idfiesta;
    strcpy(uf.mail, u.mail);
    fseek(fiestas, 0,SEEK_END);
    fseek(usuarioFiesta,0,SEEK_END);
    fwrite(&f,sizeof(struct fiesta),1, fiestas);
    fwrite(&uf,sizeof(struct usuariofiesta),1, usuarioFiesta);
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
    	SetColor(4);
        printf("Usted no es administrador de esta fiesta y no puede ver el listado \n");
        SetColor(15);
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

void registrarUsuario(struct usuario u, FILE *usuarios,FILE *usuarioFiesta,FILE *fiestas){
    struct usuario usu;
    struct usuariofiesta uf,uf2;
    int idf,aux = 0;
    printf("Ingrese una id de una fiesta que quiera dar de alta al usuario.\n");
    printf("(Puede pedir el listado de fiestas para obtener el id):\n ");
    scanf("%d", &idf);
    if (verificarf(idf,fiestas)==0){
            printf("La fiesta ingresada no existe \n");
            return;
    }
    else {
    	   //if  (verificarPermiso(idf,u,usuarioFiesta)== 0){

    	printf("Ingrese mail: ");
        scanf("%s",usu.mail);
        if (verificarMail(usu.mail,usuarioFiesta,idf)== 0){
            printf("ingrese dni: ");
            scanf("%d", &usu.dni);
            printf("ingrese contraseña: ");
            scanf("%s", &usu.contrasena);
            printf("ingrese nombre: ");
            scanf("%s", &usu.nombre);
            printf("ingrese apellido: ");
            scanf("%s", &usu.apellido);
            printf("ingrese tipousuario: 'administrador' o 'vendedor': ");
            scanf("%s", &usu.tipousuario);
             if (verificartuc(usu.tipousuario)==1){

            uf.idfiesta= idf;
            strcpy(uf.mail,usu.mail);
            fseek(usuarios,0,SEEK_END);
            fseek(usuarioFiesta,0,SEEK_END);
            fwrite(&usu, sizeof(struct usuario), 1, usuarios);
            fwrite(&uf, sizeof(struct usuariofiesta), 1, usuarioFiesta);
             }
            else {
        	SetColor(4);
            printf("El tipo de usuario ingresado es incorrecto. \n");
               	SetColor(15);
            return;
            }
        }
    else {
    	SetColor(4);
    	printf("Error. El mail ya se encuentra registrado en esa fiesta\n");
    	SetColor(15);
    }
    }}
    
    //else {
    //	SetColor(4);
    //	printf("Error, usted no tiene permisos para esa fiesta\n");
    //	SetColor(15);
  //  }
//}


//Para verificar si el tipo de usuario ingresado es correcto
int verificartuc(char tu []){

if (((strcmp(tu,"vendedor"))==0) || ((strcmp(tu,"administrador"))==0) || ((strcmp(tu,"Vendedor"))==0) || ((strcmp(tu,"Administrador"))==0)) {
                return 1;
    }

                else return 0;

}

//Para verificar si la fiesta existe 
int verificarf(int idf, FILE *fiestas){
struct fiesta f;
rewind(fiestas);
fread(&f,sizeof(struct fiesta),1,fiestas);
while (!feof(fiestas)){
    if (f.idfiesta == idf){
        return 1;
    }
    fread(&f,sizeof(struct fiesta),1,fiestas);

}
return 0;
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

int verificarMail (char mail[], FILE *usuarioFiesta,int idf){
    rewind(usuarioFiesta);
    struct usuariofiesta uf;
    fread(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    while (!feof(usuarioFiesta)){
       if (strcmp(uf.mail,mail)==0){
        if (idf == uf.idfiesta){

        return 1;
        }
       }
       fread(&uf,sizeof(struct usuariofiesta),1,usuarioFiesta);
    }
    return 0;
}

void modificarContrasena (struct usuario u,FILE *usuarios){
    char contra[50], contraV[50];
    printf("Escriba la contraseña actual:");
    scanf("%s",&contra);
    if (verificadorContrasena(contra,usuarios,u)==0){
        printf("Escriba la nueva contraseña:");
        scanf("%s", &contra);
        printf ("Vuelva a escribir la nueva contraseña:");
        scanf("%s", &contraV);
        if (strcmp(contra,contraV)== 0){
            strcpy(u.contrasena,contra);
            cambiarContrasena(u,usuarios);
        }
    }
    else {
    	SetColor(4);
    	printf("La contraseña que escribio no es la actual vuelva a intentarlo\n\n");
    	SetColor(15);
}}

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
            printf ("Esta es la contraseña nueva: %s\n", u.contrasena);
            break;
        }
       fread(&usu,sizeof(struct usuario),1,usuarios);
    }
}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
