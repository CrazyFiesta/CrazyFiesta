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

struct proveedor{
long long int cuil;
char nombreempresa[50];
char mail[50];
};

struct producto{
    int idproducto;
    char nombre[40];
    int stock;
    int stockmax;
    float precio;
};


struct fecha{
    int dia;
    int mes;
    int year;
};
struct hora{
    int hora;
    int minutos;
    int segundos;
};
struct compra{
  int idcompra;
  int idfiesta;
  struct fecha fechacompra;
  struct hora horacompra;
  float preciototal;
  int cantidad;
  char mail [50];
  long long int cuil;
};
struct compraproducto{
int idcompra;
int idproducto;
float preciocompra;

};

struct fiesta{
	int idfiesta;
	char descripcion[300];
	char nombre[100];
	struct fecha fechainicio;
	struct fecha fechafin;
	};


struct usuariofiesta{
	int idfiesta;
	char mail[50];
	};

struct venta{
int idventa;
struct fecha fechaventa;
struct hora horaventa;
float preciototal;
int cantidad;
int idfiesta;
char mail[50];
};

struct productoventa{
int idproducto;
int idventa;
float precioventa;
};

int main(int argc,char* argv[])
{
    FILE *IDactualVenta;
    FILE *ventas;
    FILE *productoVenta;
    FILE *compras;
    FILE *compraProducto;
    FILE *proveedores;
    FILE *usuarios;
    FILE *fiestas;
    FILE *usuarioFiesta;
    FILE *IDactualFiesta;
    FILE *productos;
    FILE *IDactualProducto;
    FILE *IDactualCompra;

    struct venta v;
    struct productoventa pv;
    struct compra c;
    struct compraproducto cp;
    struct proveedor p;
    struct usuario u;
    struct fiesta f;
    struct fiesta fie;
    struct usuariofiesta uf,uparty;
    struct producto prod;
    int opcion, opcion2, opcion3, opcion4,opcion5;

    char dia[15];
    char mes[15];
    char year[15];
    char t[15];
    struct fecha fechaActual;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[15];
    strftime(dia,15,"%d",tlocal);
    strftime(mes,15,"%m",tlocal);
    strftime(year,15,"%y",tlocal);
    fechaActual.dia = atoi(dia);
    fechaActual.mes = atoi(mes);
    fechaActual.year = atoi(year);


    /*strcpy(f.descripcion, "fiesta del trigo");
    strcpy(f.nombre, "fiesta del trigo");
    f.fechainicio.dia = 18;
    f.fechainicio.mes = 06;
    f.fechainicio.year = 16;
    f.fechafin.dia = 21;
    f.fechafin.mes = 06;
    f.fechafin.year = 16;
    f.idfiesta= 1;
   fiestas = fopen ("fiestas", "wb");
    fwrite(&f,sizeof(struct fiesta),1,fiestas);
    fclose (fiestas);

//id actual de la venta creando
IDactualVenta = fopen("idventa","wb");
int contadordev=2;
fwrite(&contadordev, sizeof(int),1,IDactualVenta);
    fclose(IDactualVenta);


    //id actual de la compra creando
    IDactualCompra = fopen("idcompra","wb");
    int contadordeidc= 2;
    fwrite(&contadordeidc, sizeof(int),1,IDactualCompra);
    fclose(IDactualCompra);

    //id actual fiesta creando
    IDactualFiesta= fopen("idfiestas","wb");
    int contadordeID= 2;
    fwrite(&contadordeID,sizeof (int),1,IDactualFiesta);
    fclose(IDactualFiesta);
    //ID actual del producto creando
    IDactualProducto= fopen("idproductos", "wb");
    int contadordeID2= 2;
    fwrite(&contadordeID, sizeof(int),1,IDactualProducto);
    fclose(IDactualProducto);
    //Registro de producto
    prod.idproducto = 1;
    strcpy(prod.nombre, "Gaseosas");
    prod.precio = 15,45;
    prod.stock = 100;
    prod.stockmax = 100;
    productos = fopen("productos", "wb");
    fwrite(&prod, sizeof(struct producto),1,productos);
    fclose(productos);

    //Registro de una venta
    v.cantidad=5;
    v.fechaventa.dia=7;
    v.fechaventa.mes=7;
    v.fechaventa.year=16;
    v.horaventa.hora=01;
    v.horaventa.minutos=00;
    v.horaventa.segundos=45;
    v.idfiesta=1;
    strcpy(v.mail,"juan@hotmail.com");
    v.preciototal=100;
    v.idventa=1;
    ventas = fopen("ventas", "wb");
    fwrite(&v, sizeof(struct venta),1,ventas);
    fclose(ventas);

    //venta producto
    pv.idproducto=1;
    pv.idventa=1;
    pv.precioventa=22,50;
    productoVenta = fopen("producto venta","wb");
    fwrite(&pv, sizeof(struct productoventa),1,productoVenta);
    fclose(productoVenta);

    //registro de compra
    c.idcompra=1;
    c.fechacompra.dia=20;
    c.fechacompra.mes=06;
    c.fechacompra.year=16;
    c.horacompra.hora=10;
    c.horacompra.minutos=10;
    c.horacompra.segundos=20;
    c.preciototal=200;
    c.cantidad=10;
    strcpy(c.mail,"juan@hotmail.com");
    c.cuil = 273829137;
    c.idfiesta=1;
    compras = fopen("compras", "wb");
    fwrite(&c, sizeof(struct compra),1,compras);
    fclose(compras);
    //registro de compraproducto
    cp.idcompra=1;
    cp.idproducto=1;
    cp.preciocompra=20;
    compraProducto = fopen("compraProducto", "wb");
    fwrite(&cp, sizeof(struct compraproducto),1,compraProducto);
    fclose(compraProducto);
    //Registro de proveedor
    p.cuil=27382916137;
    strcpy(p.nombreempresa,"Coca Cola");
    strcpy(p.mail,"juan@hotmail.com");
    proveedores = fopen("proveedores","wb");
    fwrite(&p,sizeof(struct proveedor),1,proveedores);
    fclose(proveedores);
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
    opcion2=4;
    opcion3=4;
    opcion4=4;
    opcion5=4;

    int verificador=0;
    int usuarioincorrecto=1;
    int idf;
    struct usuario usu;
    char contra[15];
    char mail[50];
    int estaEnLaFiesta=0;
    u.dni= -1;
    int elegir=4;
    while (elegir!=0){
    u.dni= -1;
    usuarioincorrecto=1;
    fiestas = fopen ("fiestas","rb");
    SetColor(2);
    printf("        # # # # # # # # # # # # # # # # # \n");
    printf("        #                               # \n");
    printf("        #");
    SetColor(10);
    printf("           CrazyFiesta         ");
    SetColor(2);
    printf("#\n");
    printf("        #                               #\n");
    printf("        # # # # # # # # # # # # # # # # # \n\n");
    SetColor(15);
    printf(" 1.- Iniciar sesion\n");
    printf(" 2.- Listado de Fiestas\n");
    printf(" 0.- Salir\n");;
    scanf ("%d", &elegir);
    switch(elegir){
        case 0:
            return;
        case 2:
            listadoGeneralFiesta(fiestas);
            fclose (fiestas);
            break;
        case 1:
    while (verificador==0){
    while (estaEnLaFiesta==0){
    printf("Ingrese la ID de la fiesta en la que desea iniciar sesion\n");
    SetColor(8);
    printf("(Puede ver el listado de fiestas para buscar la ID):\n");
    SetColor(15);
    scanf("%d", &idf);
    rewind (fiestas);
    fread(&f,sizeof(struct fiesta),1,fiestas);
    while (!feof(fiestas)){
            if (f.idfiesta==idf){
                estaEnLaFiesta=1;
        }
        fread(&f,sizeof(struct fiesta),1,fiestas);
      }
    if (estaEnLaFiesta==0){
        SetColor(4);
        printf("Esa ID de fiesta no existe\n");
        SetColor(15);
    }
      }
    fclose(fiestas);
    printf("Ingrese su email con el que desea iniciar sesion\n");
    scanf ("%s", &mail);
    printf("Ingrese la contrasena de su cuenta\n");
    scanf ("%s", &contra);
    usuarios = fopen("usuarios","rb");
    rewind(usuarios);
    fread(&usu, sizeof(struct usuario),1, usuarios);
    while (!feof(usuarios)){
        if (strcmp(usu.mail,mail)==0 ){
            usuarioincorrecto=0;
            if (strcmp(usu.contrasena,contra)==0){
            strcpy(u.nombre, usu.nombre);
            strcpy(u.mail,usu.mail);
            strcpy(u.apellido, usu.apellido);
            strcpy(u.tipousuario, usu.tipousuario);
            strcpy(u.contrasena, usu.contrasena);
            u.dni= usu.dni;
            usuarioFiesta = fopen ("usuarioFiesta", "rb");
            if (verificarPermiso(idf,u,usuarioFiesta)==0){
            verificador= 1;
            }
            fclose(usuarioFiesta);
            }
        }
        fread(&usu, sizeof(struct usuario),1, usuarios);
    }

    if (usuarioincorrecto==1 && verificador==0){
        SetColor(4);
        printf("Email incorrecto o no existe\n");
    SetColor(15);
    }

    if (u.dni==-1 && usuarioincorrecto==0){
        SetColor(4);
        printf("Contraseña incorrecta\n");
        SetColor(15);
    }

    if (u.dni!=-1 && verificador==0){
        printf ("Su usuario no tiene ningun permiso en la fiesta que ingreso\n");
    }
    }
    if (verificador==1){
    verificador=0;
    estaEnLaFiesta=0;
    usuarioincorrecto=0;
    SetColor(2);
    printf("Se inicio sesion correctamente\n");
    SetColor(15);
    fclose(usuarios);
    if ((strcmp(u.tipousuario,"administrador")==0) || (strcmp(u.tipousuario,"Administrador")==0)){
    opcion =4;
    while (opcion !=0){
    SetColor(3);
    printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n");
    printf("#");
    SetColor(10);
    printf("                                   CrazyFiesta                             ");
    SetColor(3);
    printf("#\n");
    printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n\n");
    SetColor(15);
    printf(" 1.- Usuarios\n");
    printf(" 2.- Fiestas\n");
    printf(" 3.- Productos\n");
    printf(" 4.- Proveedores\n");
    printf(" 5.- Compra\n");
    printf(" 0.- Cerrar sesion\n\n");
    productos = fopen("productos", "rb");
    StockMinimo(prod, productos);
    fclose(productos);
    scanf ("%d", &opcion);
    switch(opcion){
        case 1:
    	    opcion2=4;
            while(opcion2!=0){

                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(2);
                 printf("                             Usuarios                                   \n");
                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(15);
                 printf(" 1.- Registrar un usuario\n");
                 printf(" 2.- Modificar contraseña\n");
                 printf(" 3.- Listado de Usuarios\n");
                 printf(" 4.- Dar de baja un usuario\n");
                 printf(" 0.- Salir\n");
                 scanf("%d", &opcion2);
                 switch(opcion2){
            case 0:
                break;

            case 1:
                usuarios = fopen("usuarios","rb+");
                usuarioFiesta = fopen("usuarioFiesta", "rb+");
                fiestas = fopen("fiestas", "rb");
                registrarUsuario(u,usuarios,usuarioFiesta,fiestas);
                fclose(usuarios);
                fclose(usuarioFiesta);
                break;
            case 2:
                usuarios = fopen("usuarios","rb+");
                modificarContrasena (u,usuarios);
                fclose(usuarios);
                break;
            case 3:
                usuarioFiesta = fopen("usuarioFiesta", "rb");
                usuarios= fopen("usuarios", "rb");
                fiestas = fopen("fiestas","rb");
                listadoUsuarios(u,usuarioFiesta,fiestas,usuarios);
                fclose(usuarioFiesta);
                fclose(usuarios);
                fclose(fiestas);
                break;
            case 4:
                usuarios = fopen("usuarios","rb");
                usuarioFiesta = fopen("usuarioFiesta","rb+");
                dardebaja(u,usuarios,usuarioFiesta);
                fclose(usuarios);
                fclose(usuarioFiesta);
                break;
            }

    }
    break;
        case 2:
        	opcion3=4;
                 while(opcion3!=0){
                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(2);
                 printf("                            Fiestas                                     \n");
                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(15);
                 printf(" 1.- Dar de Alta Fiesta\n");
                 printf(" 2.- Listado de Fiestas\n");
                 printf(" 3.- Modificar Fiesta\n");
                 printf(" 4.- Dar de Baja Fiesta\n");
                 printf(" 0.- Salir\n");
                 scanf("%d", &opcion3);
                 switch(opcion3){

             case 0:
                break;
             case 1:
                fiestas = fopen ("fiestas","rb+");
                usuarioFiesta = fopen("usuarioFiesta", "rb+");
                IDactualFiesta= fopen("idfiestas","rb+");
                AltaFiesta(IDactualFiesta, fiestas,usuarioFiesta,u,fechaActual);
                fclose(IDactualFiesta);
                fclose(fiestas);
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
                fiestas = fopen("fiestas", "rb+");
                ModificarFiesta(f, fiestas);
                fclose(fiestas);
                break;
             case 4:
                fiestas = fopen("fiestas", "rb+");
                usuarios = fopen("usuarios", "rb");
                usuarioFiesta = fopen("usuarioFiesta", "rb+");
                BajaFiesta(u, f, fiestas, usuarios,usuarioFiesta,fechaActual);
                fclose(fiestas);
                fclose(usuarios);
                fclose(usuarioFiesta);
                break;
                 }
                }
                break;
     case 3:
     		opcion4=4;
                while(opcion4!=0){
                    SetColor(3);
                    printf("****************************************************************************\n");
                    SetColor(2);
                    printf("                            Productos                                   \n");
                    SetColor(3);
                    printf("****************************************************************************\n");
                    SetColor(15);
                    printf(" 1.- Dar de Alta Producto\n");
                    printf(" 2.- Listado de Producto\n");
                    printf(" 3.- Modificar Producto\n");
                    printf(" 4.- Dar de Baja Producto\n");
                    printf(" 5.- Ver detalle de un producto\n");
                    printf(" 0.- Salir\n");
                    scanf("%d", &opcion4);
                    switch(opcion4){
            case 5:
                productos=fopen("productos","rb");
                verdetalle(productos);
                fclose(productos);
                break;
                case 0:
                    break;
                case 1:
                    productos = fopen("productos", "rb+");
                    IDactualProducto = fopen("idproductos", "rb+");
                    AltaProducto(productos, IDactualProducto, prod);
                    fclose(productos);
                    fclose(IDactualProducto);
                    break;
                case 2:
                    productos = fopen("productos", "rb");
                    listadoProducto(prod, productos);
                    fclose(productos);
                    break;
                case 3:
                    productos = fopen("productos", "rb+");
                    ModificarProducto(prod, productos);
                    fclose(productos);
                    break;
                case 4:
                    productos = fopen("productos", "rb+");
                    BajaProducto(prod, productos);
                    fclose(productos);
                    break;
                    }
                }
                break;
                case 4:
                	opcion5=4;
                    while(opcion5!=0){
                    SetColor(3);
                    printf("****************************************************************************\n");
                    SetColor(2);
                    printf("                            Proveedores                                 \n");
                    SetColor(3);
                    printf("****************************************************************************\n");
                 SetColor(15);
                 printf(" 1.- Dar de Alta Proveedor\n");
                 printf(" 2.- Listado de Proveedores\n");
                 printf(" 3.- Modificar Proveedor\n");
                 printf(" 4.- Dar de Baja Proveedor\n");
                 printf(" 0.- Salir\n");
                 scanf("%d", &opcion5);
                 switch(opcion5){

             case 0:
                break;
             case 1:
                 proveedores=fopen("proveedores","rb+");
                 usuarios=fopen("usuarios","rb");
                AltaProveedor(proveedores,usuarios);
                fclose(proveedores);
                break;
             case 2:
                proveedores=fopen("proveedores","rb");
                listadoproveedores(proveedores);
                fclose(proveedores);
                break;
             case 3:
                proveedores=fopen("proveedores","rb+");
                modificarProveedor(proveedores);
                fclose(proveedores);
                break;
             case 4:
                proveedores=fopen("proveedores","rb+");
                dardebajaproveedor(proveedores);
                fclose(proveedores);
                break;
                 }

} break;
 case 5:
    	    opcion2=4;
            while(opcion2!=0){
                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(2);
                 printf("                         Compra             \n");
                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(15);
                 printf(" 1.- Registrar una compra\n");
                 printf(" 0.- Salir\n");
                 scanf("%d", &opcion2);
                 switch(opcion2){
                 case 0:
                    break;
                 case 1:
                    compras = fopen("compras","rb+");
                    compraProducto = fopen("compraProducto","rb+");
                    productos = fopen("productos","rb");
                    fiestas = fopen("fiestas","rb");
                    proveedores=fopen("proveedores","rb");
                    IDactualCompra=fopen("idcompra","rb+");
                    realizarcompra(compras,compraProducto,productos,fiestas,proveedores,IDactualCompra,u.mail);

                    fclose(compras);
                    fclose(productos);
                    fclose(compraProducto);
                    fclose(fiestas);
                    fclose(proveedores);
                    fclose(proveedores);
                    fclose(IDactualCompra);
                    break;
    }

    }



    break;
    }
    }

    }
    else if ((strcmp(u.tipousuario,"vendedor")==0) || (strcmp(u.tipousuario,"Vendedor")==0)){
    opcion =4;
       while (opcion !=0){
    SetColor(3);
    printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n");
    printf("#");
    SetColor(10);
    printf("                                   CrazyFiesta                             ");
    SetColor(3);
    printf("#\n");
    printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n\n");
    SetColor(15);
    printf(" 1.- Ventas\n");
    printf(" 2.- Listado de productos\n");
    printf(" 3.- Listado de Fiestas\n");

    printf(" 0.- Cerrar sesion\n");

    scanf ("%d", &opcion);
    switch(opcion){
case 0:
    return;
case 3:
    fiestas = fopen ("fiestas","rb");
    listadoGeneralFiesta(fiestas);
            fclose (fiestas);
            break;

    case 2:
                    productos = fopen("productos", "rb");
                    listadoProducto(prod,productos);
                    fclose(productos);
                    break;
    case 1:
    opcion2=4;
                while(opcion2!=0){

                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(2);
                 printf("                             Ventas                                 \n");
                 SetColor(3);
                 printf("****************************************************************************\n");
                 SetColor(15);
                printf(" 1.- Realizar una venta\n");
                 printf(" 0.- Salir\n");


                 scanf("%d", &opcion2);
                 switch(opcion2){
                case 0:
                break;
                case 1:

                 ventas = fopen("ventas","rb+");
                 productos = fopen("productos","rb");
                 productoVenta = fopen("productoVenta","rb+");
                 fiestas = fopen ("fiestas","rb");
                 IDactualVenta = fopen("idventa","rb+");
                 realizarventa(fiestas,ventas,productos,productoVenta,IDactualVenta,u.mail);
                 fclose(ventas);
                 fclose(IDactualVenta);
                 fclose(productos);
                 fclose(productoVenta);
                 fclose(fiestas);
                    break;
                 }

    }

    break;


    }}
    }}}}}

void dardebajaproveedor(FILE *proveedores);
void modificarProveedor(FILE *proveedores);
void listadoproveedores(FILE *proveedores);
void AltaProveedor(FILE *proveedores,FILE *usuarios);
int verificarexistenciamail(struct proveedor,FILE* usuarios);
void listadoFiesta(struct usuario u, FILE *usuarioFiesta, FILE *Fiestas);
int verificarPermiso(int idf,struct usuario u,FILE *usuarioFiesta);
void mostrarFiestas(struct fiesta f);
int verificarMail (char mail[], FILE *usuarioFiesta,int);
int verificadorContrasena(char contra[], FILE *usuarios, struct usuario u);
void listadoUsuarios(struct usuario, FILE *usuarioFiesta,FILE *fiestas, FILE *usuarios);
void cambiarContrasena(struct usuario u, FILE *usuarios);
void AltaFiesta (FILE* IDactualFiesta,FILE *fiestas,FILE *usuarioFiesta, struct usuario u,struct fecha actual);
void BajaFiesta(struct usuario u, struct fiesta f, FILE *fiestas, FILE *usuarios,FILE *usuarioFiesta, struct fecha);
int EsAdministrador(struct usuario u, FILE *usuarios);
void dardebaja(struct usuario u,FILE *usuarios, FILE *usuarioFiesta);
int fiestaActiva(struct fecha,int idf,FILE *fiestas);
void ModificarFiesta(struct fiesta f, FILE *fiestas);
void SetColor(int);
void registrarUsuario(struct usuario, FILE *usuarios,FILE *usuarioFiesta, FILE *fiestas);
int verificarf(int,FILE *fiestas);
int verificartuc(char []);
void AltaProducto(FILE *productos, FILE *IDactualProducto, struct producto p);
void listadoProducto(struct producto p, FILE *productos);
void mostrarProductos(struct producto p);
void ModificarProducto(struct producto p, FILE *productos);
void BajaProducto(struct producto p, FILE *productos);
void listadoGeneralFiesta(FILE *fiestas);
int mismoNombre (FILE *fiestas,struct fiesta fie,struct fecha actual);
float esNumero();
void realizarcompra(FILE *compras,FILE *compraProducto,FILE *productos,FILE *fiestas,FILE *proveedores,FILE *IDactualCompra,char[50]);
void realizarventa(FILE *fiestas, FILE *ventas, FILE *productos, FILE *productoVenta, FILE *IDactualVenta,char [50]);
void verdetalle(FILE *productos);
void StockMinimo(struct producto p, FILE *productos);

void verdetalle(FILE *productos){
int idp,exisp=0;
struct producto p2;
printf("Ingrese el id del producto que quiere ver el detalle:\n");
printf("(Puede ver el listado de ids de productos)\n");
scanf("%d",&idp);
fread(&p2,sizeof(struct producto),1,productos);
while(!feof(productos)){
    if (p2.idproducto==idp){
        exisp=1;
        break;
    }

    fread(&p2,sizeof(struct producto),1,productos);
}
if (exisp==0){
    printf("El id de producto ingresado no existe\n");
}
else {

printf("Id del producto: %d \n",p2.idproducto);
printf("Nombre del producto: %s \n",p2.nombre);
printf("Precio del producto: %.2f \n",p2.precio);
printf("Stock del producto: %d \n",p2.stock);
    }
}




void realizarventa(FILE *fiestas,FILE *ventas, FILE *productos, FILE *productoVenta, FILE *IDactualVenta,char mail[50]){
struct fiesta f2;
struct usuariofiesta uf2;
float precioventaaux,preciototalaux=0;
struct venta v2;
struct producto prod2;
struct productoventa pv2;
int idf,exisf=0,y=1,exisu=0,idp,exisprod=0,cant,totalcant=0,con,first=0;
printf("Ingrese el id de la fiesta para la que quiere adquirir productos: \n");
scanf("%d",&idf);
fread(&f2,sizeof(struct fiesta),1,fiestas);
while (!feof(fiestas)){
if(f2.idfiesta==idf){
            exisf=1;
    }
    fread(&f2,sizeof(struct fiesta),1,fiestas);

}
if (exisf==0){
        SetColor(4);
    printf("La fiesta ingresada no existe\n");
return;
    SetColor(15);
}
else {

while (y==1){
  first=first+1;
  fflush(stdin);
  exisprod=0;
    rewind(productos);
printf("Ingrese id del producto que quiere vender: \n");
printf("(Puede pedir el listado de productos para ver el id) \n");
scanf("%d",&idp);
 fread(&prod2, sizeof(struct producto),1, productos);
while(!feof(productos)){
    if(prod2.idproducto==idp){
        exisprod=1;
        break;
    }
    fread(&prod2, sizeof(struct producto),1, productos);
}
 if (exisprod==0){
    printf("El id ingresado no existe\n");
}
 else {
     printf("\n");
   printf("Nombre del producto: %s \n",prod2.nombre);
      printf("Precio del producto: %.2f \n",prod2.precio);
    printf("\n");

    printf("Cuanta cantidad desea vender de este producto? \n");
scanf("%d",&cant);

if (cant<=0){
    printf("La cantidad ingresada es incorrecta\n");

}
else { //voy sumando la cantidad de mercaderia comprada
totalcant=totalcant+cant;
precioventaaux = prod2.precio * 1.50;

preciototalaux=preciototalaux+(precioventaaux*(float)cant);
pv2.idproducto=prod2.idproducto;
pv2.precioventa=precioventaaux;
//si es el primer producto perteneciente a la compra aumento el id

if (first==1){
   fread(&con,sizeof(int),1,IDactualVenta);
con= con+1;
fseek(IDactualVenta, -1*sizeof(int), SEEK_CUR);
   fwrite(&con, sizeof(int), 1, IDactualVenta);
}
//si no es el primer producto perteneciente a la compra mantengo el id

else if (first>1){
   fread(&con,sizeof(int),1,IDactualVenta);
}
pv2.idventa=con;
fseek(productoVenta, 0, SEEK_END);
fwrite(&pv2, sizeof(struct productoventa),1, productoVenta);
printf("Quiere vender otro producto? Si su respuesta es si, presione 1, sino presione cualquier otro numero \n");
scanf("%d",&y);
 }
}}

time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char dia[10];
char mes[10];
char year[10];
 strftime(dia,15,"%d",tlocal);
 strftime(mes,15,"%m",tlocal);
 strftime(year,15,"%y",tlocal);

 v2.fechaventa.dia=atoi(dia);
 v2.fechaventa.mes=atoi(mes);
 v2.fechaventa.year=atoi(year);

 char hora[10];
char minutos[10];
char segundos[10];
 strftime(hora,15,"%H",tlocal);
  strftime(minutos,15,"%M",tlocal);
   strftime(segundos,15,"%S",tlocal);

 v2.horaventa.hora=atoi(hora);
 v2.horaventa.minutos=atoi(minutos);
 v2.horaventa.segundos=atoi(segundos);

 v2.cantidad=totalcant;
 v2.idfiesta=idf;
 strcpy(v2.mail,mail);
 v2.preciototal=preciototalaux;
 v2.idventa=con;

 fseek(ventas, 0, SEEK_END);
    fwrite(&v2, sizeof(struct venta),1, ventas);
    SetColor(2);
    printf("La compra se ha registrado correctamente.\n");
    SetColor(15);
first=0;
}
    }
void realizarcompra(FILE *compras,FILE *compraProducto,FILE *productos,FILE *fiestas,FILE *proveedores,FILE *IDactualCompra,char mail[50]){
struct compraproducto cp2;
struct compra c2;
struct fiesta f2;
struct producto prod2;
struct usuariofiesta uf2;
struct proveedor prov2;
int y=1,idf,exisf=0,idp,exisprod,exisu=0,sum=0,existprov=0,con,first=0;
long long int cuil,aux;
float preciototalaux=0;
int cant,totalcant=0;
rewind(IDactualCompra);
fflush(stdin);
printf("Ingrese el id de la fiesta para la que quiere adquirir productos: \n");
scanf("%d",&idf);
fread(&f2, sizeof(struct fiesta),1, fiestas);
while(!feof(fiestas)){
    if(f2.idfiesta==idf){
            exisf=1;
    }
    fread(&f2, sizeof(struct fiesta),1, fiestas);
    }
if (exisf==0){
    SetColor(4);
    printf("La fiesta ingresada no existe\n");
    return;
    SetColor(15);
}
else {
        fflush(stdin);

        printf("Ingrese el cuil del proveedor al cuil le realizo la compra:\n");
        printf("(Ingrese solo numeros, sin el signo '-':\n");
scanf("%lld",&cuil);
fflush(stdin);
aux = cuil;
 while(aux > 0){
        aux=aux/10;
        sum = sum + 1;
    }
if (sum==11){
        fread(&prov2,sizeof(struct proveedor),1,proveedores);
   while(!feof(proveedores)){
       if(prov2.cuil==cuil){
        existprov=1;
       }
            fread(&prov2,sizeof(struct proveedor),1,proveedores);
   }
  if (existprov==0){
    printf("El cuil ingresado no se encuentra registrado en el sistema\n");
    return;
  }
   else{
           while(y==1){
first++;
  fflush(stdin);
        rewind(productos);
printf("Ingrese id del producto que quiere comprar: \n");
printf("(Puede pedir el listado de productos para ver el id) \n");
scanf("%d",&idp);


exisprod=0;
fread(&prod2, sizeof(struct producto),1, productos);
while(!feof(productos)){
    if(prod2.idproducto==idp){
        exisprod=1;
        break;
    }
    fread(&prod2, sizeof(struct producto),1, productos);
}
if (exisprod==0){
    printf("El id ingresado no existe\n");
    return;
}
else{

        printf("\n");
   printf("Nombre del producto: %s \n",prod2.nombre);
      printf("Precio del producto: %2f \n",prod2.precio);
    printf("\n");

printf("Cuanta cantidad desea adquirir de este producto? \n");
scanf("%d",&cant);
if (cant<=0){
    printf("La cantidad ingresada es incorrecta\n");
}

//voy sumando la cantidad de mercaderia comprada
totalcant=totalcant+cant;
//calcule el precio total de ese producto
preciototalaux=preciototalaux+(prod2.precio*(float)cant);

cp2.idproducto=idp;
cp2.preciocompra=prod2.precio;

//si es el primer producto perteneciente a la compra aumento el id
if (first==1){
        fread(&con,sizeof(int),1,IDactualCompra);

        con= con+1;
        fseek(IDactualCompra,-1*sizeof(int),SEEK_CUR);
        fwrite(&con,sizeof (int),1,IDactualCompra);
}
//si no es el primer producto perteneciente a la compra mantengo el id
else if (first>1){
    fread(&con,sizeof(int),1,IDactualCompra);
}
    cp2.idcompra=con;


fseek(compraProducto, 0, SEEK_END);
    fwrite(&cp2, sizeof(struct compraproducto),1, compraProducto);

printf("Quiere adquirir otro producto? Si su respuesta es si, presione 1, sino presione cualquier otro numero \n");
scanf("%d",&y);
}}}
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char dia[10];
char mes[10];
char year[10];
 strftime(dia,15,"%d",tlocal);
 strftime(mes,15,"%m",tlocal);
 strftime(year,15,"%y",tlocal);
c2.fechacompra.dia=atoi(dia);
c2.fechacompra.mes=atoi(mes);
c2.fechacompra.year=atoi(year);
char hora[10];
char minutos[10];
char segundos[10];
 strftime(hora,15,"%H",tlocal);
  strftime(minutos,15,"%M",tlocal);
   strftime(segundos,15,"%S",tlocal);
c2.horacompra.hora=atoi(hora);
c2.horacompra.minutos=atoi(minutos);
c2.horacompra.segundos=atoi(segundos);

c2.cantidad=totalcant;
c2.cuil=cuil;
c2.idcompra=con;
c2.idfiesta=idf;
strcpy(c2.mail,mail);
c2.preciototal=preciototalaux;

fseek(compras, 0, SEEK_END);
    fwrite(&c2, sizeof(struct compra),1, compras);
    SetColor(2);

    printf("La compra se ha registrado correctamente.\n");
    first=0;
    SetColor(15);
}
else {
    SetColor(4);
        printf("Error. El cuil ingresado no tiene 11 digitos \n");

SetColor(15);
return;
}
}
}


void dardebajaproveedor(FILE *proveedores){
int aux=0,x,sum=0;
long long int caux,aux2;
char marca[25];
strcpy(marca, "(Proveedor eliminado)");
struct proveedor p4;

SetColor(8);
printf("Ingrese el cuil del proveedor que desea dar de baja: \n");
printf("(Ingrese solo numeros, sin el signo '-'):\n");
printf("(Puede ver el cuil de los proveedores en el listado de proveedores)\n");
scanf("%lld",&caux);
aux2 = caux;
    while(aux2 > 0){
    aux2=aux2/10;
    sum = sum + 1;
    }
if (sum==11){
fread(&p4,sizeof(struct proveedor),1,proveedores);
while (!feof(proveedores)){
    if (p4.cuil == caux){
        aux = 1;
        printf("El cuil del proveedor que desea eliminar es %lld \n", p4.cuil);
        SetColor(14);
        printf("Seguro que desea dar de baja este proveedor?\nPresione 1 para confirmar o cualquier otro numero para cancelar\n");
        SetColor(15);
        scanf("%d", &x);
        if(x==1){
                p4.cuil= -1*p4.cuil;
            strcpy(p4.nombreempresa, strcat(p4.nombreempresa, marca));
                        fseek(proveedores,-1*sizeof(struct proveedor),SEEK_CUR);
                                    fwrite(&p4,sizeof(struct proveedor),1,proveedores);
          SetColor(2);
            printf("La baja se ha realizado correctamente.\n");
            SetColor(15);

            break;

        }
        else return;
    }
    fread(&p4,sizeof(struct proveedor),1,proveedores);

}}
else {
    SetColor(4);
    printf("Cuil incorrecto. El cuil ingresado no tiene 11 digitos \n");
SetColor(15);
    return;
}

if (aux ==0){
            SetColor(4);

    printf("El cuil ingresado no se encuentra registrado en el sistema \n");
    SetColor(15);

}
return;
}

void modificarProveedor(FILE *proveedores){
int x,opcion =4,aux=0,sum=0;
long long int caux,caux2,aux2,cuilUsado=0;;
struct proveedor p3;
rewind(proveedores);
printf("Ingrese el cuil del proveedor que desea modificar: \n");
printf("(Ingrese solo numeros, sin el signo '-'):\n");
scanf("%lld",&caux);
aux2 = caux;
    while(aux2 > 0){
    aux2=aux2/10;
    sum = sum + 1;
    }
if (sum==11){
fread(&p3,sizeof(struct proveedor),1,proveedores);
while (!feof(proveedores)){
    if (caux==p3.cuil){
        cuilUsado=1;
    }
    fread(&p3,sizeof(struct proveedor),1,proveedores);
}

rewind(proveedores);
fread(&p3,sizeof(struct proveedor),1,proveedores);
while(!feof(proveedores)){
    if (p3.cuil==caux){
            aux=1;
            printf("El cuil del proveedor que desea modificar es: %lld\n", p3.cuil);
            SetColor(14);
            printf("Seguro que desea modificar este proveedor?\nPresione 1 para confirmar o cualquier otro numero para cancelar\n");
            SetColor(15);
            scanf("%d", &x);
            if(x==1){

           while(opcion !=0){
                SetColor(3);
                printf("*******************************************************************\n");
                SetColor(2);
                printf("                       Modificar Proveedor                     \n");
                SetColor(3);
                printf("********************************************************************\n");
                SetColor(15);
                printf(" 1.- Modificar cuil\n");
                printf(" 2.- Modificar nombre de la empresa\n");
                printf(" 0.- Salir\n");
                scanf("%d", &opcion);
                switch(opcion){
                case 0:
                return;
                case 1:
                SetColor(3);
                printf("********************************************************************\n");
                SetColor(2);
                printf("                        Modificar cuil                          \n");
                SetColor(3);
                printf("********************************************************************\n");
                SetColor(15);
                fflush(stdin);

                printf("Ingrese el nuevo cuil: \n");
                scanf("%lld",&caux2);
                aux2 = caux2;
                sum = 0;
               while(aux2 > 0){
               aux2=aux2/10;
               sum = sum + 1;
               }
               if (sum==11){
                    if (cuilUsado==0){
                p3.cuil=caux2;
               fseek(proveedores, -1*sizeof(struct proveedor), SEEK_CUR);
               fwrite(&p3, sizeof(struct proveedor),1,proveedores);
                SetColor(2);
                printf("La modificacion del cuil se ha realizado correctamente.\n");
                SetColor(15);
                break;
                }else {
                    printf("El cuil que ingreso esta en uso\n");
                    break;
                }
                }
               else {
                    SetColor(4);
                    printf("El cuil ingresado no tiene 11 digitos \n");
                    SetColor(15);
               return;
               }
                case 2:
                SetColor(3);
                printf("********************************************************************\n");
                SetColor(2);
                printf("                        Modificar nombre de la empresa          \n");
                SetColor(3);
                printf("********************************************************************\n");
                SetColor(15);
                fflush(stdin);
                printf("Ingrese el nuevo nombre de la empresa: \n");
                gets(p3.nombreempresa);
                fseek(proveedores, -1*sizeof(struct proveedor), SEEK_CUR);
                fwrite(&p3, sizeof(struct proveedor),1,proveedores);
                SetColor(2);
                printf("La modificacion del nombre de la empresa se ha realizado correctamente.\n");
                SetColor(15);
                break;
                }
    }
    }
    else return;
    }
    fread(&p3, sizeof(struct proveedor),1, proveedores);
}}
else {
    SetColor(4);
    printf("El cuil ingresado no tiene 11 digitos \n");
SetColor(15);
    return;
}

if(aux==0){
    SetColor(4);
    printf("El cuil ingresado no se encuentra registrado en el sistema.\n");
    SetColor(15);
}
return;

}


void listadoproveedores(FILE *proveedores){
struct proveedor p2;
SetColor(2);
printf("                 Listado de proveedores registrados en el sistema              \n");
                    SetColor(3);

printf("________________________________________________________________________________\n");
                    SetColor(15);
fread(&p2,sizeof(struct proveedor),1,proveedores);

while (!feof(proveedores)){
    printf("Cuil: %lld            Nombre de la empresa: %s\n",p2.cuil,p2.nombreempresa);
    fread(&p2,sizeof(struct proveedor),1,proveedores);
}
}



void AltaProveedor(FILE *proveedores,FILE *usuarios){
struct proveedor p1,p2;
long long int aux;
int sum = 0,existe=0, yaexiste=0;
printf("Ingrese el cuil del proveedor que desea dar de alta: \n");
printf("(Ingrese solo numeros, sin el signo '-'):\n");
scanf("%lld",&p1.cuil);
fflush(stdin);
aux = p1.cuil;
 while(aux > 0){
        aux=aux/10;
        sum = sum + 1;
    }
if (sum==11){
        rewind(proveedores);
        fread(&p2,sizeof(struct proveedor),1,proveedores);
        while (!feof(proveedores)){
                if (p2.cuil*-1 == p1.cuil){
                    yaexiste=1;
                }
                if (p2.cuil == p1.cuil){
                    existe=1;
                }
                    fread(&p2,sizeof(struct proveedor),1,proveedores);
        }
        if (existe == 1){
            SetColor(4);
            printf("El cuil ingresado ya se encuentra registrado en el sistema \n");
        SetColor(15);
            return;
        }
        else {
         printf("Ingrese el nombre de la empresa de la cual forma parte el proveedor:\n");
         fflush(stdin);
         gets(p1.nombreempresa);
        printf("Ingrese su mail:\n");
         scanf("%s",p1.mail);
        fflush(stdin);
        if (verificarexistenciamail(p1, usuarios)==0) {
            if (yaexiste==0){
                fseek(proveedores, 0, SEEK_END);
                fwrite(&p1, sizeof(struct proveedor),1, proveedores);
                SetColor(2);
                printf("El proveedor se ha dado de alta correctamente\n");
                SetColor(15); }
        else {
            rewind(proveedores);
            fread(&p2,sizeof(struct proveedor),1,proveedores);
            while (!feof(proveedores)&&(p2.cuil*-1!=p1.cuil)){
                fread(&p2,sizeof(struct proveedor),1,proveedores);}
            if (p2.cuil*-1==p1.cuil){
                fseek(proveedores, -1*sizeof(struct proveedor), SEEK_CUR);
                fwrite(&p1, sizeof(struct proveedor),1, proveedores);
                SetColor(2);
                printf("El proveedor se ha dado de alta correctamente\n");
                SetColor(15); }
            }
        }
        else {
        SetColor(4);
        printf("El mail ingresado no es correcto\n");
        SetColor(15);
        return; }
        }
}
else {
    SetColor(4);
        printf("Error. El cuil ingresado no tiene 11 digitos \n");
SetColor(15);
}}

int verificarexistenciamail(struct proveedor p1,FILE* usuarios){
rewind(usuarios);
struct usuario uaux;
fread(&uaux,sizeof(struct usuario),1,usuarios);
while (!feof(usuarios)){
    if (strcmp(uaux.mail,p1.mail)==0){
        return 0;
    }
    fread(&uaux,sizeof(struct usuario),1,usuarios);
}
return 1;
}


void listadoGeneralFiesta(FILE *fiestas){
    struct fiesta fies;
    fread(&fies,sizeof(struct fiesta),1,fiestas);
        while ( !feof(fiestas)){
                if (fies.idfiesta>0){
        mostrarFiestas(fies);}
        fread(&fies,sizeof(struct fiesta),1,fiestas);
}
}

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
        printf("Seguro que desea modificar esta fiesta? \nPresione 1 para confirmar o cualquier otro numero para cancelar\n");
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
                     SetColor(2);
                     printf("La modificacion del nombre se ha realizado correctamente.\n");
                     SetColor(15);

                     break;

                 case 2:
                    printf("          Modificar fecha inicio           \n");
                    printf("______________________________________________\n");
                    printf("Ingrese el dia de inicio de la fiesta en formato dd: ");
                    scanf("%d", &fie.fechainicio.dia);
                    printf("Ingrese el mes de inicio de la fiesta en formato mm: ");
                    scanf("%d", &fie.fechainicio.mes);
                    printf("Ingrese el año de inicio de la fiesta en formato aa:  ");
                    scanf("%d", &fie.fechainicio.year);
                    fseek(fiestas, -1*sizeof(struct fiesta), SEEK_CUR);
                    fwrite(&fie, sizeof(struct fiesta),1, fiestas);
                    SetColor(2);
                    printf("La modificacion de la fecha de inicio se ha realizado correctamente.\n");
                    SetColor(15);

                    break;

                 case 3:
                    printf("         Modificar fecha fin               \n");
                    printf("______________________________________________\n");
                    printf("Ingrese el dia de fin de la fiesta en formato dd: ");
                    scanf("%d", &fie.fechafin.dia);
                    printf("Ingrese el mes de fin de la fiesta en formato mm: ");
                    scanf("%d", &fie.fechafin.mes);
                    printf("Ingrese el año de fin de la fiesta en formato aa:  ");
                    scanf("%d", &fie.fechafin.year);
                    fseek(fiestas, -1*sizeof(struct fiesta), SEEK_CUR);
                    fwrite(&fie, sizeof(struct fiesta), 1, fiestas);
                    SetColor(2);
                    printf("La modificacion de la fecha de fin se ha realizado correctamente.\n");
                    SetColor(15);

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
                    SetColor(2);
                    printf("La modificacion de la descripcion se ha realizado correctamente.\n");
                    SetColor(15);

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
int x;

printf("Ingrese el mail del usuario que quiere dar de baja\n");
SetColor(8);
printf("(Puede ver el listado de usuarios para ver el mail del usuario):\n");
SetColor(15);
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
                SetColor(14);
                printf("Seguro que desea dar a este usuario de baja?\nPresione 1 para continuar o cualquier otro numero para cancelar\n");
                SetColor(15);
                scanf("%d", &x);
                if(x==1){
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

    }
}}

void BajaFiesta(struct usuario u, struct fiesta f, FILE *fiestas, FILE *usuarios,FILE *usuarioFiesta, struct fecha actual){
    struct fiesta fie;
    struct usuariofiesta uf,uf1;
    int idf;
    int x;
    int aux;
    aux=0;
    char marca [21];
    strcpy(marca,"(FIESTA ELIMINADA)");
    //if (EsAdministrador(u, usuarios)==1){
        printf("Ingrese el ID de la fiesta que desea dar de baja\n");
        SetColor(8);
        printf("(Puede ver el listado de fiestas para ver el ID):\n");
        SetColor(15);
        scanf("%d", &idf);
        if (fiestaActiva(actual,idf,fiestas)==0){
        rewind(fiestas);
        fread(&fie, sizeof(struct fiesta), 1, fiestas);
        while(!feof(fiestas)){
                if(fie.idfiesta==idf){
                aux=1;
                printf("El nombre de la fiesta que desea eliminar es %s y su numero de ID es %d \n", fie.nombre, fie.idfiesta);
                SetColor(14);
                printf("Seguro que desea dar de baja esta fiesta? \nPresione 1 para confirmar o cualquier otro numero para cancelar ");
                SetColor(15);
                scanf("%d", &x);
                    if (x == 1){
                            fie.idfiesta= -1*fie.idfiesta;
                            strcpy(fie.descripcion,strcat(fie.descripcion,  marca));
                            fseek(fiestas,-1*sizeof(struct fiesta),SEEK_CUR);
                            fwrite(&fie,sizeof(struct fiesta),1,fiestas);
                            SetColor(2);
                            printf("La baja de fiesta se ha realizado correctamente \n");
                            SetColor(15);
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

int fiestaActiva(struct fecha actual,int idf,FILE *fiestas){
    struct fiesta fie;
    fread(&fie, sizeof(struct fiesta), 1, fiestas);
    while (!feof(fiestas)){
        if (fie.idfiesta== idf){
                if (fie.fechafin.year== actual.year && fie.fechafin.mes>=actual.mes){
                    if (fie.fechafin.mes==actual.mes && fie.fechafin.dia>=actual.dia){
                        return 1;
                    }
                }
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

void AltaFiesta (FILE *IDactualFiesta,FILE *fiestas,FILE *usuarioFiesta, struct usuario u,struct fecha actual){
    struct fiesta f;
    struct usuariofiesta uf;
    int con;
    printf("Escriba el nombre de la fiesta: ");
    fflush(stdin);
    gets(f.nombre);
    printf("Ingrese la fecha de inicio de la fiesta en formato dd/mm/aa: ");
    scanf ("%d/%d/%d",&f.fechainicio.dia, &f.fechainicio.mes,&f.fechainicio.year);
    printf("Ingrese la fecha de fin de la fiesta en formato dd/mm/aa: ");
    scanf ("%d/%d/%d",&f.fechafin.dia, &f.fechafin.mes,&f.fechafin.year);
    printf("Ingrese una breve descripcion de la fiesta: ");
    fflush(stdin);
    gets(f.descripcion);
    if (mismoNombre(fiestas,f,actual)==1){
        fread(&con,sizeof(int),1,IDactualFiesta);
        con= con+1;
        fseek(IDactualFiesta,-1*sizeof(int),SEEK_CUR);
        fwrite(&con,sizeof (int),1,IDactualFiesta);
        f.idfiesta=  con;
        uf.idfiesta= f.idfiesta;
        rewind (fiestas);
        strcpy(uf.mail, u.mail);
        fseek(fiestas, 0,SEEK_END);
        fseek(usuarioFiesta,0,SEEK_END);
        fwrite(&f,sizeof(struct fiesta),1, fiestas);
        fwrite(&uf,sizeof(struct usuariofiesta),1, usuarioFiesta);
        SetColor(2);
        printf("La fiesta se ha creado con exito.\n");
        SetColor(15);
        }else{
        SetColor(4);
        printf ("El nombre de la fiesta que ingreso ya esta en uso y se encuentra activa\n");
        SetColor(15); }
}

int mismoNombre (FILE *fiestas,struct fiesta fie,struct fecha actual){
    struct fiesta f;
    fread(&f,sizeof(struct fiesta),1, fiestas);
    while (!feof(fiestas)){
        if (strcmp(f.nombre,fie.nombre)==0){
                if (f.fechafin.year== actual.year && f.fechafin.mes>=actual.mes && f.fechafin.dia>=actual.dia){
                        return 0;
        }}
        fread(&f,sizeof(struct fiesta),1, fiestas);
    }
    return 1;
}


void listadoUsuarios(struct usuario u, FILE *usuarioFiesta, FILE *fiestas,FILE *usuarios){
    struct usuariofiesta uf3,uf4;
    struct usuario usu;
    int pertenece,aux;
    char mail[50];
    pertenece = 1;
    printf("Ingrese el id de la fiesta de la que quiere obtener los usuarios: \n");
    scanf("%d",&aux);

    fflush(stdin);
    printf("Ingrese su mail: \n");
    scanf("%s",mail);

    while (!feof(usuarioFiesta)){
        fread(&uf3,sizeof(struct usuariofiesta),1,usuarioFiesta);
        if ((uf3.idfiesta == aux) && ((strcmp(uf3.mail,mail))==0)){
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
                     rewind(usuarios);
                     fread(&usu,sizeof(struct usuario),1,usuarios);
                     while (!feof(usuarios)){
                        if (strcmp(uf4.mail,usu.mail)==0){
                            printf("\n Mail: %s \n", usu.mail);
                            printf("\n Nombre: %s \n", usu.nombre);
                            printf("\n Apellido: %s \n", usu.apellido);
                            printf("\n DNI: %d \n", usu.dni);
                            printf("\n Tipo de usuario: %s \n", usu.tipousuario);
                            printf("________________________________________________________________________________\n");
                            }
                        fread(&usu,sizeof(struct usuario),1,usuarios);
                        }
                     }
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
                if(fies.idfiesta>0){
                mostrarFiestas(fies);
                }
        }
        fread(&fies,sizeof(struct fiesta),1,fiestas);
      }
    }
    fread(&usu,sizeof(struct usuariofiesta),1,usuarioFiesta);
}
}

void mostrarFiestas(struct fiesta f){
    printf("fechainicio: %d/%d/%d", f.fechainicio.dia, f.fechainicio.mes, f.fechainicio.year);
    printf("\nfechafin: %d/%d/%d", f.fechafin.dia, f.fechafin.mes, f.fechafin.year);
    printf("\nidfiesta: %d", f.idfiesta);
    printf("\ndescripcion: %s", f.descripcion);
    printf("\nnombre: %s\n\n", f.nombre);
}

void registrarUsuario(struct usuario u, FILE *usuarios,FILE *usuarioFiesta,FILE *fiestas){
    struct usuario usu;
    struct usuariofiesta uf,uf2;
    int idf,aux = 0;
    printf("Ingrese una id de una fiesta que quiera dar de alta al usuario.\n");
    SetColor(8);
    printf("(Puede pedir el listado de fiestas para obtener el id):\n ");
    SetColor(15);
    scanf("%d", &idf);
    if (verificarf(idf,fiestas)==0){
            SetColor(4);
            printf("La fiesta ingresada no existe \n");
    SetColor(15);
            return;
    }
    else {
    	   if  (verificarPermiso(idf,u,usuarioFiesta)== 0){

    	printf("Ingrese mail: ");
        scanf("%s",usu.mail);
        if (verificarMail(usu.mail,usuarioFiesta,idf)== 0){
            printf("ingrese dni: ");
            scanf("%d", &usu.dni);
            printf("ingrese contrasena: ");
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
            SetColor(2);
            printf("El usuario se ha creado correctamente \n");
            SetColor(15);
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
    }

    else {
    SetColor(4);
    	printf("Error, usted no tiene permisos para esa fiesta\n");
    	SetColor(15);
    }
}}


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


void AltaProducto(FILE *productos, FILE *IDactualProducto, struct producto p){
    int con;
    float pre;
    int aux, st, aux2;
    aux=0;
    aux2=0;
    printf("Escriba el nombre del producto: ");
    fflush(stdin);
    gets(p.nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &pre);
    while(aux==0){
    if(pre<=0){
        SetColor(4);
        printf("El precio no es valido.\n");
        SetColor(15);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &pre);
    }
    else aux=1;
    }
    p.precio=pre;
    printf("Ingrese el stock del producto: ");
    scanf("%d", &st);
    while(aux2==0){
        if(st<=0){
            SetColor(4);
            printf("El stock no es valido.\n");
            SetColor(15);
            printf("Ingrese el stock del producto: ");
            scanf("%d", &st);
        }
        else aux2=1;
    }
    p.stock=st;
    p.stockmax=st;
    fread(&con,sizeof(int),1,IDactualProducto);
    con= con+1;
    fseek(IDactualProducto, -1*sizeof(int), SEEK_CUR);
    fwrite(&con, sizeof(int), 1, IDactualProducto);
    p.idproducto= con;
    fseek(productos, 0, SEEK_END);
    fwrite(&p, sizeof(struct producto),1, productos);
    SetColor(2);
    printf("El producto se ha creado con exito.\n");
    SetColor(15);

}

void listadoProducto(struct producto p, FILE *productos){
    struct producto prod;
    SetColor(2);

    printf("                 Listado de productos registrados en el sistema              \n");
                    SetColor(3);

    printf("________________________________________________________________________________\n");
                    SetColor(15);
    rewind(productos);
    fread(&prod,sizeof(struct producto),1,productos);
    while(!feof(productos)){
        mostrarProductos(prod);
        printf("________________________________________________________________________________\n");
        fread(&prod,sizeof(struct producto),1,productos);
    }
}

void mostrarProductos(struct producto p){
    printf("ID del producto: %d", p.idproducto);
    printf("\nNombre: %s", p.nombre);
    printf("\nPrecio: %.2f", p.precio);
    printf("\nStock: %d\n\n", p.stock);
}

void ModificarProducto(struct producto p, FILE *productos){
struct producto prod;
int idf, x, aux, opcion, stock, aux2, aux3;
float pre;
aux=0;
printf("Ingrese el ID del producto que desea modificar: ");
scanf("%d", &idf);
rewind(productos);
opcion=4;
fread(&prod, sizeof(struct producto),1,productos);
while(!feof(productos)){
    if(prod.idproducto==idf){
        aux=1;
        printf("El nombre del producto que desea modificar es %s.\n", prod.nombre);
        SetColor(14);
        printf("Seguro que desea modificar este producto?\nPresione 1 para confirmar o cualquier otro numero para cancelar\n");
        SetColor(15);
        scanf("%d", &x);
        if(x==1){
            while(opcion !=0){
                SetColor(2);
                printf("                       Modificar Producto                     \n");
                SetColor(3);
                printf("_________________________________________________________________\n");
                SetColor(15);
                printf(" 1.- Modificar nombre\n");
                printf(" 2.- Modificar precio\n");
                printf(" 3.- Modificar stock\n");
                printf(" 0.- Salir\n");
                scanf("%d", &opcion);
                switch(opcion){
            case 0:
                return;

            case 1:
                SetColor(2);
                printf("                        Modificar nombre                             \n");
                SetColor(3);
                printf("_______________________________________________________________________\n");
                SetColor(15);
                printf("Ingrese el nuevo nombre del producto: \n");
                fflush(stdin);
                gets(prod.nombre);
                fseek(productos, -1*sizeof(struct producto), SEEK_CUR);
                fwrite(&prod, sizeof(struct producto),1,productos);
                SetColor(2);
                printf("La modificacion del nombre se ha realizado correctamente.\n");
                SetColor(15);

                break;

            case 2:
                SetColor(2);
                printf("                        Modificar precio                                \n");
                SetColor(3);
                printf("__________________________________________________________________________\n");
                SetColor(15);
                aux3=0;
                printf("Ingrese el nuevo precio del producto: \n");
                scanf("%f", &pre);
                while(aux3==0){
                if(pre<=0){
                SetColor(4);
                printf("El precio no es valido.\n");
                SetColor(15);
                printf("Ingrese el precio del producto: ");
                scanf("%f", &pre);
                }
                else aux3=1;
                }
                prod.precio=pre;
                fseek(productos, -1*sizeof(struct producto), SEEK_CUR);
                fwrite(&prod, sizeof(struct producto),1,productos);
                SetColor(2);
                printf("La modificacion del precio se ha realizado correctamente.\n");
                SetColor(15);
                break;

            case 3:
                SetColor(2);
                printf("                         Modificar stock                                  \n");
                SetColor(3);
                printf("_____________________________________________________________________________\n");
                SetColor(15);
                aux2=0;
                printf("Ingrese el nuevo stock del producto: \n");
                scanf("%d", &stock);
                while(aux2==0){
                      if(stock<=0){
                      SetColor(4);
                      printf("El stock no es valido.\n");
                      SetColor(15);
                      printf("Ingrese el stock del producto: ");
                      scanf("%d", &stock);
                      }
                      else aux2=1;
                }
                     prod.stock=stock;
                     prod.stockmax=stock;
                fseek(productos, -1*sizeof(struct producto), SEEK_CUR);
                fwrite(&prod, sizeof(struct producto),1,productos);
                SetColor(2);
                printf("La modificacion del stock se ha realizado correctamente.\n");
                SetColor(15);

                break;
                }


            }
        }
        else return;
    }
    fread(&prod, sizeof(struct producto),1, productos);
}
if(aux==0){
    SetColor(4);
    printf("El producto no existe.\n");
    SetColor(15);
}
return;
}

void BajaProducto(struct producto p, FILE *productos){
struct producto prod;
int idf;
int x,z;
int aux;
aux=0;
char marca[25];
strcpy(marca, "(Producto eliminado)");
printf("Ingrese el ID del producto: \n");
SetColor(8);
printf("(Puede ver el ID de los productos en el listado de productos)\n");
SetColor(15);
scanf("%d", &idf);
rewind(productos);
fread(&prod, sizeof(struct producto),1,productos);
while(!feof(productos)){
    if(prod.idproducto==idf){
        aux=1;
        printf("El nombre del producto que desea eliminar es %s y su numero de ID es %d \n", prod.nombre, prod.idproducto);
        SetColor(14);
        printf("Seguro que desea dar de baja este producto?\nPresione 1 para confirmar o cualquier otro numero para cancelar\n");
        SetColor(15);
        scanf("%d", &x);
        if(x==1){
            prod.idproducto= -1*prod.idproducto;
            strcpy(prod.nombre, strcat(prod.nombre, marca));
            fseek(productos,-1*sizeof(struct producto),SEEK_CUR);
            fwrite(&prod,sizeof(struct producto),1,productos);
            SetColor(2);
            printf("La baja se ha realizado correctamente.\n");
            SetColor(15);

            break;
        }
        else return;
    }
    fread(&prod, sizeof(struct producto),1,productos);

}
if(aux==0){
    SetColor(4);
    printf("El producto no existe \n");
    SetColor(15);
}
}

void StockMinimo(struct producto p, FILE *productos){
struct producto prod;
int minimo, aux;
aux=0;
fread(&prod, sizeof(struct producto),1,productos);
while (!feof(productos)){
    minimo= ((prod.stockmax *10)/100);
    if(prod.stock<=minimo){
        SetColor(14);
        printf("El producto '%s' esta con el stock minimo\n", prod.nombre);
        SetColor(15);
        aux=1;
    }
    fread(&prod, sizeof(struct producto),1,productos);
}
if(aux==0){
    SetColor(7);
    printf("No hay ningun producto con el stock al minimo.\n\n");
    SetColor(15);
}
}

/*int StockMinimoIndividual(struct producto p){
int minimo;
minimo=(p.stockmax*10)/100;
if(p.stock<=minimo){
    return 1;
}
else return 0;
}*/



