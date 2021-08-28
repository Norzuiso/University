#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int j = 0;
long int folio = 100001;

int menu();
void gotoxy(int x, int y);
void factura();
void dibujo_principal();
void logo();
void marco_fact();
void formatoFact(int dia, int mes, int years);
int buscarFolio(long int clave);
void mostrarFact();
void animacion();
void tablaProductos();
int buscarProductos(long int clave);

struct ImpresionFotoAudio
{
    long int folio;
    char descripcion[100];
    float precio;
}productoServicio[25];

struct ImpresionFotoAudio productoServicio[] = {{45121503, "Camaras desechables", 550.75}, {45121504, "Camaras digitales", 1500.99},
                                                {45121505, "Camaras cinematograficas", 550900.90}, {45121506, "Camaras de video conferencia", 2100.50},
                                                {45121510, "Camaras aereas", 800999.99}, {45121511, "Camaras de alta velocidad", 800753.52},
                                                {45121520, "Camaras de web", 650.40}, {45121521, "Camaras de inspeccion", 4750.60},
                                                {45121522, "Camaras infrarrojas", 17290.30}, {45121523, "Camaras astronomicas", 1496.80},
                                                {45121601, "Flashes o iluminacion para camaras", 750.50},
                                                {45121602, "Tripodes para camaras (Tripies para camara)", 250.99}, {45121603, "Lentes para camaras", 690.20},
                                                {45121604, "Oclusores para camaras", 340.80}, {45121622, "Limpiadores para lentes de camara", 159.99},
                                                {82131601, "Servicios de fotografia aerea", 3579.99}, {82131602, "Cinematografia", 1350500},
                                                {82131603, "Servicios de produccion de videos", 3629.99},
                                                {82131604, "Servicios de estudio fotografico o fotos fijas", 452.40},
                                                {82131501, "Elaboracion o reproduccion de pelicula fija", 1800000},
                                                {82131502, "Elaboracion o reproduccion de peliculas de cine", 3900750},
                                                {82131503, "Servicios de microficha", 250.70}, {82131504, "Separacion de colores", 560.50},
                                                {82131505, "Servicio de posproduccion de peliculas", 6875.10}};

struct Usuarios
{
    char usuario[20];
    char password[15];
    char name[50];
    char PCorporativo[50];
}Usuario[5];

struct Usuarios Usuario[] = {{"Carlos", "Carlos_08", "Escobar Ibarra Carlos Roberto", "VICEPRESIDENTE"},
                             {"SamuelJA", "Samuel_J02", "Jimenez Abrica Samuel Enrique", "GERENTE DE MARKETING"},
                             {"Emilio", "EM10_", "Giacomo Quintero Emilio Josafat", "GERENTE DE OPERACIONES"},
                             {"j", "jaja", "SAM", "Puto jefe"}};

struct serviciosYproductos
{
    long int claveSP;
    char descripcion[50];
    int cantidad;
    float costo;
    float importe;
}SP[30];

struct factura
{
    int dia, mes, year;
    char cert[32], nombre_empresa[30], rfc[13], calle[50], colonia[50], ciudad[50], estado[50], pais[50], numero[10];
    char folio[3], regimen[30];
    long int Folio;
    int c_postal, claveRegimen, cantS_P;
    struct serviciosYproductos SP[30];
    float subtotal;
    float IVA;
    float total;

}datos[100];

struct ClaveRegimenPersonaFisica
{
    int clave;
    char descripcion[50];
}clavesFIS[11];

struct ClaveRegimenPersonaFisica clavesFIS[] = {{605, "Sueldos y Salarios e Ingresos Asimilados a Salarios."},
                                                {606, "Arrendamiento"}, {608, "Demas ingresos."},{611, "Ingresos por Dividendos."},
                                                {612, "Persona fisica con actividades empresariales y profesionales."},
                                                {614, "Ingresos por intereses."}, {615, "Ingresos por obtencion de premios."},
                                                {616, "Sin obligaciones fiscales."}, {621, "Incorporacion fiscal."},
                                                {622, "Actividades agricolas, ganaderas, silvicolas y pesqueras."},
                                                {629, "Preferentes y de empresas multinacionales."},
                                                {630, "Enajenacion de acciones en bolsa de valores."}};

struct ClaveRegimenPersonaMoral
{
    int clave;
    char descripcion[50];
}clavesMOR[8];

struct ClaveRegimenPersonaMoral clavesMOR[] = {{601, "General de Ley Personas Morales."}, {603, "Personas Morales con Fines no Lucrativos."},
                                               {607, "Enajenación o Adquisición de Bienes"}, {609, "Consolidacion."},
                                               {620, "Sociedades Cooperativas de Producción que optan por Diferir sus Ingresos"}, {622, "Actividades Agrícolas, Ganaderas, Silvícolas y Pesqueras."},
                                               {623, "Opcional para Grupos de Sociedades."}, {624, "Coordinados."}, {628, "Hidrocarburos."}};




int main()
{
    char usuario[20];
    char caracter, resp;
    char Miclave[15];
    int i, error = 0, aux, posicion, opcion;

    do
    {
        do
        {
            system("CLS");
            dibujo_principal();
            i = 0;
            gotoxy(47, 23);
            printf("Usuario: ");
            fflush(stdin);
            gets(usuario);
            gotoxy(47, 24);
            printf("Contrase%ca: ",164);
            while(caracter = getch())
            {
                if(caracter == 13)
                {
                    Miclave[i] = '\0';
                    break;
                }
                else if (caracter == 8)
                {
                    if (i > 0)
                    {
                        i--;
                        printf("\b \b");
                    }
                }
                else
                {
                    printf("*");
                    Miclave[i] = caracter;
                    i++;
                }

            }
            aux = 0;
            for(i = 0; i < 5; i++)
            {
                if(strcmp(Usuario[i].usuario, usuario) == 0 && (strcmp(Usuario[i].password, Miclave)== 0))
                {
                    aux = 1;
                    posicion = i;
                }
            }
            if(aux != 1)
            {
                gotoxy(33, 20);
                printf("Usuario o contrase%ca incorrecta, intento de nuevo. ", 164);
                error++;
                getch();
            }

            if(aux == 1)
            {
                gotoxy(33, 20);
                printf("Bienvenido al sistema ");
                puts(Usuario[posicion].name);
                gotoxy(50, 27);
                puts(Usuario[posicion].PCorporativo);
                error = 4;
                getch();
            }
        }
        while(error < 3);
        if(error == 3)
            exit(0);
        do
        {
            opcion = menu();
            switch(opcion)
            {
                case 1:
                    system("CLS");
                    logo();
                    factura();
                    break;
                case 2:
                    system("CLS");
                    mostrarFact();
                    break;
                case 3:
                    animacion();
                    break;
                case 5:
                    exit(0);
                    break;
            }
            printf("\nDesea realizar otra operacion s(Si) o n(No)\n");
            fflush(stdin);
            scanf("%c",&resp);
        }
        while(resp=='s' ||resp=='S');
        printf("\nDesea realizar otra operacion s(Si) o n(No)\n");
        fflush(stdin);
        scanf("%c",&resp);
    }
    while(resp=='s' ||resp=='S');
    return 0;
}

int menu()
{
    system("CLS");
    int opc;
    gotoxy(0, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    gotoxy(0, 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(0, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    gotoxy(50, 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(50, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    gotoxy(50, 2);
    printf("%cMen%c principal%c\n", 186,163,186);
    gotoxy(49, 5);
    printf("1.-Crear Factura.\n");
    gotoxy(49, 6);
    printf("2.-Mostrar Factura.\n");
    gotoxy(49, 7);
    printf("3.-Enviar Factura.\n");
    gotoxy(49, 8);
    printf("4.-Eliminar Factura.\n");
    gotoxy(49, 9);
    printf("5.-Salir.");
    gotoxy(49, 10);
    printf("Seleccion: ");
    scanf("%d",&opc);
    return opc;
}

void factura()
{
    int aux, dia, mes, years, i, k, posicion, aux2 = 0, cant, resp, x, a, b;
    long int busqueda;

    srand(time(NULL));
    datos[j].dia = (rand()% 31) + 1;
    datos[j].mes = (rand()% 12) + 1;
    datos[j].year = 2020;
    datos[j].Folio = folio;
    strcpy(datos[j].folio, "A -");

    dia = datos[j].dia;
    mes = datos[j].mes;
    years = datos[j].year;

    formatoFact(dia, mes, years);

    gotoxy(1,16);
    printf("Nombre de la empresa: ");
    fflush(stdin);
    gets(datos[j].nombre_empresa);
    do
    {
        gotoxy(1,17);
        printf("RFC: ");
        fflush(stdin);
        gets(datos[j].rfc);
        if(strlen(datos[j].rfc) == 13)
        {
            do
            {
                system("CLS");
                formatoFact(dia, mes, years);
                gotoxy(1,16);
                printf("Nombre de la empresa: ");
                puts(datos[j].nombre_empresa);
                gotoxy(1,17);
                printf("RFC: ");
                puts(datos[j].rfc);
                gotoxy(20,17);
                printf("Clave de R%cgimen Fiscal: ",130);
                scanf("%d", &datos[j].claveRegimen);
                for(i = 0; i < 100; i++)
                {
                    if(datos[j].claveRegimen == clavesFIS[i].clave)
                    {
                        gotoxy(50,17);
                        printf("R%cgimen: ", 130);
                        posicion = i;
                        strcpy(datos[j].regimen, clavesFIS[posicion].descripcion);
                        puts(clavesFIS[posicion].descripcion);
                        aux2 = 1;
                        aux = 0;
                    }
                }
                if(aux2 != 1)
                {
                    system("CLS");
                    formatoFact(dia, mes, years);
                    gotoxy(1,16);
                    printf("Nombre de la empresa: ");
                    puts(datos[j].nombre_empresa);
                    gotoxy(1,17);
                    printf("RFC: ");
                    puts(datos[j].rfc);
                    gotoxy(1,20);
                    printf("Clave incorrecta.");
                }
            }
            while(aux2 != 1);
        }
        else if(strlen(datos[j].rfc) == 12)
        {
            do
            {
                system("CLS");
                formatoFact(dia, mes, years);
                gotoxy(1,16);
                printf("Nombre de la empresa: ");
                puts(datos[j].nombre_empresa);
                gotoxy(1,17);
                printf("RFC: ");
                puts(datos[j].rfc);
                gotoxy(20,17);
                printf("Clave de R%cgimen Fiscal: ",130);
                scanf("%d", &datos[j].claveRegimen);
                for(i = 0; i < 100; i++)
                {
                    if(datos[j].claveRegimen == clavesMOR[i].clave)
                    {
                        gotoxy(50,17);
                        printf("R%cgimen: ", 130);
                        posicion = i;
                        strcpy(datos[j].regimen, clavesFIS[posicion].descripcion);
                        puts(clavesMOR[posicion].descripcion);
                        aux2 = 1;
                        aux = 0;
                    }
                }
                if(aux2 != 1)
                {
                    system("CLS");
                    formatoFact(dia, mes, years);
                    gotoxy(1,16);
                    printf("Nombre de la empresa: ");
                    puts(datos[j].nombre_empresa);
                    gotoxy(1,17);
                    printf("RFC: ");
                    puts(datos[j].rfc);
                    gotoxy(1,20);
                    printf("Clave incorrecta.");
                }
            }
            while(aux2 != 1);
        }
        else
        {
            system("CLS");
            formatoFact(dia, mes, years);
            gotoxy(1,16);
            printf("Nombre de la empresa: ");
            puts(datos[j].nombre_empresa);
            gotoxy(1,18);
            printf("RFC no valido.\n");
            aux = 1;
        }
    }
    while(aux == 1);

    gotoxy(1,18);
    printf("Domicilio fiscal: ");
    gotoxy(5,19);
    printf("Calle: ");
    fflush(stdin);
    gets(datos[j].calle);
    gotoxy(5,20);
    printf("N%cmero: ",163);
    fflush(stdin);
    gets(datos[j].numero);
    gotoxy(35,19);
    printf("Colonia: ");
    fflush(stdin);
    gets(datos[j].colonia);
    gotoxy(35,20);
    printf("C%cdigo postal: ",162);
    scanf("%d", &datos[j].c_postal);
    gotoxy(70,19);
    printf("Ciudad: ");
    fflush(stdin);
    gets(datos[j].ciudad);
    gotoxy(70,20);
    printf("Estado: ");
    fflush(stdin);
    gets(datos[j].estado);
    gotoxy(100,19);
    printf("Pa%cs: ", 161);
    fflush(stdin);
    gets(datos[j].pais);
    tablaProductos();
    gotoxy(29,22);
    printf("%cCu%cntos productos o servicios facturar%c%c: ", 168, 160, 160,63);
    scanf("%d", &datos[j].cantS_P);
    a = 27;
    datos[j].subtotal = 0.00;
    for(i = 0; i < datos[j].cantS_P; i++)
    {
        do
        {
            gotoxy(1,a);
            printf(" ");
            scanf("%d", &busqueda);
            x = buscarProductos(busqueda);
            if(x > 25)
            {

                printf("Clave de producto o servicio incorrecta, ingrese una clave correcta.");
            }
        }
        while(x >= 25);

        if(x >= 0 && x < 25)
        {
            datos[j].SP[i].claveSP = productoServicio[x].folio;
            strcpy(datos[j].SP[i].descripcion, productoServicio[x].descripcion);
            gotoxy(25,a);
            puts(datos[j].SP[i].descripcion);
            datos[j].SP[i].costo = productoServicio[x].precio;
            gotoxy(75,a);
            printf("%.2f", datos[j].SP[i].costo);
            gotoxy(19,a);
            printf("");
            scanf("%d",&datos[j].SP[i].cantidad);
            datos[j].SP[i].importe = datos[j].SP[i].costo * datos[j].SP[i].cantidad;
            gotoxy(100,a);
            printf("%.2f", datos[j].SP[i].importe);
            datos[j].subtotal += datos[j].SP[i].importe;
        }
        a++;
    }

    gotoxy(75, a + 1);
    printf("Subotal");
    gotoxy(100, a + 1);
    printf("%.2f", datos[j].subtotal);
    datos[j].IVA = datos[j].subtotal * 0.16;
    datos[j].total = datos[j].subtotal + datos[j].IVA;
    gotoxy(75, a + 2);
    printf("I.V.A (16%)");
    gotoxy(100, a + 2);
    printf("%.2f", datos[j].IVA);
    gotoxy(75, a + 3);
    printf("TOTAL");
    gotoxy(100, a + 3);
    printf("%.2f", datos[aux].total);
    gotoxy(50, a + 5);
    printf("%cFactura creada exitosamente%c", 173,33);

    j++;
    folio++;
}

int buscarFolio(long int clave)
{
    int i;
    for(i = 0; i < 100; i++)
    {
        if(clave == datos[i].Folio)
            return(i);
        else
            return(-1);
    }
}

void mostrarFact()
{
    int i, aux, a, b;
    long int foli;
    char resp;
    printf("Mostrar FACTURA\n");
    printf("%ld", datos[0].Folio);
    do
    {
        printf("Introduce el folio de la factura que deseas mostrar(solo los %cltimos seis n%cmeros): ", 163,162);
        scanf("%ld", &foli);
        aux = buscarFolio(foli);
        if(aux >= 0)
        {
            printf("%d", aux);
            printf("FACTURA ENCONTRADA");
            marco_fact();
            formatoFact(datos[aux].dia, datos[aux].mes, datos[aux].year);
            gotoxy(100,6);
            printf("Folio: ");
            puts(datos[aux].folio);
            gotoxy(111,6);
            printf("%ld", foli);
            gotoxy(1,16);
            printf("Nombre de la empresa: ", puts(datos[aux].nombre_empresa));
            gotoxy(1,17);
            printf("RFC: %s", datos[aux].rfc);
            gotoxy(20,17);
            printf("Clave de R%cgimen Fiscal: %d - ", 130, datos[aux].claveRegimen);
            puts(datos[aux].regimen);
            gotoxy(1,18);
            printf("Domicilio fiscal: ");
            puts(datos[aux].calle);
            puts(datos[aux].numero);
            puts(datos[aux].colonia);
            printf("%d", datos[aux].c_postal);
            puts(datos[aux].ciudad);
            puts(datos[aux].estado);
            puts(datos[aux].pais);

            tablaProductos();
            a = 27;
            for(i = 0; i < datos[aux].cantS_P; i++)
            {
                gotoxy(1,a);
                printf("%d", datos[aux].SP[i].claveSP);
                gotoxy(19,a);
                printf("%d", datos[aux].SP[i].cantidad);
                gotoxy(25,a);
                puts(datos[aux].SP[i].descripcion);
                gotoxy(75,a);
                printf("%.2f", datos[aux].SP[i].costo);
                gotoxy(100,a);
                printf("%.2f", datos[aux].SP[i].importe);
                a++;
            }
            gotoxy(75, a + 1);
            printf("Subotal");
            gotoxy(100, a + 1);
            printf("%.2f", datos[aux].subtotal);
            gotoxy(75, a + 2);
            printf("I.V.A (16%)");
            gotoxy(100, a + 2);
            printf("%.2f", datos[aux].IVA);
            gotoxy(75, a + 3);
            printf("TOTAL");
            gotoxy(100, a + 3);
            printf("%.2f", datos[aux].total);
        }
        else
        {
            printf("El folio ingresado no corresponde a ninguna factura.");
        }
        printf("\nDesea realizar otra operacion s(Si) o n(No)\n");
        fflush(stdin);
        scanf("%c",&resp);
    }
    while(resp=='s' || resp=='S');
}

int buscarProductos(long int clave)
{
    int i, no = 1;
    for(i = 0; i < 30; i++)
    {
        if(clave == productoServicio[i].folio)
        {
            return (i);
            no = 2;
        }
    }
    if(no != 2)
        return(40);
}

void tablaProductos()
{
    int i, a = 1, b = 1;
    gotoxy(0,24);
    printf("%c",201);
    for(i = 0; i < 118; i++)
    {
        gotoxy(a,24);
        printf("%c", 205);
        a++;
    }
    gotoxy(118,24);
    printf("%c",187);
    gotoxy(0,26);
    printf("%c",200);
    for(i = 0; i < 118; i++)
    {
        gotoxy(b,26);
        printf("%c", 205);
        b++;
    }
    gotoxy(118,26);
    printf("%c",188);
    gotoxy(1,25);
    printf("CLAVE");
    gotoxy(15,25);
    printf("CANTIDAD");
    gotoxy(35,25);
    printf("DESCRIPCI%cN", 224);
    gotoxy(75,25);
    printf("PRECIO UNITARIO");
    gotoxy(100,25);
    printf("IMPORTE");
}

void logo()
{
    gotoxy(2, 3);
    printf("________%c%c%c%c%c________\n",220, 220, 220, 220, 220);
    gotoxy(2, 4);
    printf("______%c%c%c%c%c%c%c%c%c______\n",219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(2, 5);
    printf("______%c%c%c%c%c%c%c%c%c______\n",219, 176, 178, 178, 178, 178, 178, 176, 219);
    gotoxy(2, 6);
    printf("______%c%c%c%c%c%c%c%c%c______\n",219, 176, 205, 205, 205, 205, 205, 176, 219);
    gotoxy(2, 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 219, 219, 219, 219, 219, 219, 176, 32, 32, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(2, 8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 176, 220, 254, 254, 254, 220, 176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 176, 219, 32, 32, 32, 219, 176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 176, 219, 220, 220, 220, 219, 176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 220, 220, 220, 220, 220, 219, 219, 220,220, 220, 220, 220, 219, 219, 220, 220, 220,220, 220, 219);
    gotoxy(2, 13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 219);
}

void marco_fact()
{
    gotoxy(0, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    gotoxy(0, 15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    gotoxy(0, 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(0, 40);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}

void dibujo_principal()
{
    gotoxy(1, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Izquierda short 1
    gotoxy(1, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Izquierda short 2
    gotoxy(1, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Larga
    gotoxy(1, 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //printf("¦¦__¦_¦¦¦_\n_¯¯¯¯¦___¦¯¯¯¯_\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¦¦¦¦¦¯___¯¦¦¦¦¦\n¯_____________%c¯: ", 220);
    //Derecha short 0
    gotoxy(79, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Derecha short 1
    gotoxy(89, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Derecha short 2
    gotoxy(89, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //DATOS U & C
    //D Superior
    gotoxy(46, 21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",220, 220, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 220);
    //D Inferior
    gotoxy(46, 26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 220, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 219);
    //D Centro
    gotoxy(46, 22);
    printf("%c",219);
    //gotoxy(67, 22);
    //printf("%c",219);
    gotoxy(67, 22);
    printf("%c",219);
    //Relleno centro
    //1111111
    gotoxy(47, 22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176);
    //2222222
    gotoxy(47, 25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176);
    //Superior
    gotoxy(0, 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    //Recta Izquierda
    //gotoxy(0, 0);
    printf("\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n", 186, 186, 186, 186, 186, 219, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
    //Recta derecha
    //gotoxy(1, 30);
    //printf("\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n", 186, 186, 186, 186, 186, 219, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
    //Linea Inferior
    gotoxy(0, 28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    //Segunda Inferior
    gotoxy(0, 29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Primer Cuadro
    gotoxy(35, 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(35, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    gotoxy(35, 2);
    printf("%cSistema De Facturacion  LA PINTOREZCA 2021%c\n ", 186, 186);
    //Segundo Cuadro
    gotoxy(23, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(23, 5);
    printf("%c", 186);
    gotoxy(88, 5);
    printf("%c", 186);
    gotoxy(23, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    gotoxy(24, 5);
    printf("Equipos y Suministros para Impresion, Fotografia y Audiovisuales\n ");
    gotoxy(47, 8);
    printf("________%c%c%c%c%c________\n",220, 220, 220, 220, 220);
    gotoxy(47, 9);
    printf("______%c%c%c%c%c%c%c%c%c______\n",219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(47, 10);
    printf("______%c%c%c%c%c%c%c%c%c______\n",219, 176, 178, 178, 178, 178, 178, 176, 219);
    gotoxy(47, 11);
    printf("______%c%c%c%c%c%c%c%c%c______\n",219, 176, 205, 205, 205, 205, 205, 176, 219);
    gotoxy(47, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 219, 219, 219, 219, 219, 219, 176, 32, 32, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(47, 13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 176, 220, 254, 254, 254, 220, 176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 176, 219, 32, 32, 32, 219, 176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 176, 32, 32, 32, 176, 219, 176, 219, 220, 220, 220, 219, 176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 220, 220, 220, 220, 220, 219, 219, 220,220, 220, 220, 220, 219, 219, 220, 220, 220,220, 220, 219);
    gotoxy(47, 18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 220, 220, 220, 220, 220, 220, 220,220, 220, 219);
}

void formatoFact(int day, int month, int year)
{
    gotoxy(75,8);
    printf("Cert CSD: SEJA2178643190000000000000000000");
    gotoxy(89,7);
    printf("Fecha de emision:\n");
    if(day >= 10 && month >= 10)
    {
        gotoxy(107,7);
        printf("%d/%d/%d", day, month, year);
    }

    if(day < 10 && month >= 10)
    {
        gotoxy(107,7);
        printf("0%d/%d/%d", day, month, year);
    }

    if(day >= 10 && month < 10)
    {
        gotoxy(107,7);
        printf("%d/0%d/%d", day, month, year);
    }

    if(day < 10 && month < 10)
    {
        gotoxy(107,7);
        printf("0%d/0%d/%d", day, month, year);
    }

    gotoxy(100,6);
    printf("Folio: ");
    puts(datos[j].folio);
    gotoxy(111,6);
    printf("%ld", datos[j].Folio);

    marco_fact();
    logo();
    gotoxy(45,4);
    printf("F A C T U R A C I %c N     E L E C T R %c N I C A", 224,224);
    gotoxy(25,7);
    printf("Nombre de la empresa: La Pintorezca %c", 169);
    gotoxy(25,8);
    printf("RFC: JIAS021111RQ6");
    gotoxy(25,10);
    printf("Domicilio fiscal: Calle Consituci%cn #36  Colonia: Centro 46540, San Marcos, Jalisco, M%cxico.",162,130);
    gotoxy(25,11);
    printf("Persona Fis%cca | R%cgimen Fiscal: 601 - R%cgimen General", 161, 130,130);
}

void animacion()
{
    system("CLS");
    printf("\t\t\t\t\t\t Recuperando factura.\n");
    printf("\t\t\t\t\t __________\n");
    printf("\t\t\t\t\t | %c    / |\n", 92);
    printf("\t\t\t\t\t |  %c  /  |\n", 92);
    printf("\t\t\t\t\t |____V___|\n");
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Recuperando factura..\n");
    printf("\t\t\t\t\t _____________\n");
    printf("\t\t\t\t\t |  %c     /  |   \n", 92);
    printf("\t\t\t\t\t |   %c   /   |   \n", 92);
    printf("\t\t\t\t\t |_____V_____|    \n");
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Rescuperando factura...\n");
    printf("\t\t\t\t\t _______________\n");
    printf("\t\t\t\t\t |  %c       /  |\n", 92);
    printf("\t\t\t\t\t |   %c     /   | \n", 92);
    printf("\t\t\t\t\t |    %c   /    | \n", 92);
    printf("\t\t\t\t\t |______V______| \n", 92);
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Preparando para enviar\n");
    printf("\t\t\t\t\t _______________\n");
    printf("\t\t\t\t\t |  %c       /  |   ___________|%c\n", 92, 92);
    printf("\t\t\t\t\t |   %c     /   |  |             %c\n", 92, 92);
    printf("\t\t\t\t\t |    %c   /    |  |___________  /\n", 92);
    printf("\t\t\t\t\t |______V______|              |/ \n", 92);
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Preparando para enviar.\n");
    printf("\t\t\t\t\t _____________\n");
    printf("\t\t\t\t\t |  %c       /   ________|%c\n", 92, 92);
    printf("\t\t\t\t\t |   %c     /   |          %c\n", 92, 92);
    printf("\t\t\t\t\t |    %c   /    |________  /\n", 92, 92);
    printf("\t\t\t\t\t |______V___            |/\n");
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Preparando para enviar..\n");
    printf("\t\t\t\t\t _________\n");
    printf("\t\t\t\t\t |  %c     ________|%c\n", 92, 92);
    printf("\t\t\t\t\t |   %c   |          %c \n", 92, 92);
    printf("\t\t\t\t\t |    %c  |________  / \n", 92, 92);
    printf("\t\t\t\t\t |______V_        |/ \n");
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Preparando para enviar...\n");
    printf("\t\t\t\t\t __\n");
    printf("\t\t\t\t\t |   ________|%c\n", 92);
    printf("\t\t\t\t\t |  |          %c\n", 92);
    printf("\t\t\t\t\t |  |________  /\n");
    printf("\t\t\t\t\t |__         |/\n");
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Enviando factura.\n");
    printf("\n");
    printf("\t\t\t\t\t  __________|%c\n", 92);
    printf("\t\t\t\t\t |            %c\n", 92);
    printf("\t\t\t\t\t |__________  /\n", 92);
    printf("\t\t\t\t\t            |/\n", 92);
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Enviando factura..\n");
    printf("\t\t\t\t\t                   _______ \n");
    printf("\t\t\t\t\t  __________|%c        /  | \n", 92, 92);
    printf("\t\t\t\t\t |            %c      /   | \n", 92);
    printf("\t\t\t\t\t |__________  /     /    | \n", 92);
    printf("\t\t\t\t\t            |/    V______| \n", 92);
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t Enviando factura...\n");
    printf("\t\t\t\t\t                  _______________\n");
    printf("\t\t\t\t\t  __________|%c    |  %c       /  |\n", 92, 92);
    printf("\t\t\t\t\t |            %c   |   %c     /   |\n", 92, 92);
    printf("\t\t\t\t\t |__________  /   |    %c   /    |\n", 92);
    printf("\t\t\t\t\t            |/    |______V______|\n", 92);
    sleep(1);
    system("CLS");
    printf("\t\t\t\t\t\t         __\n");
    printf("\t\t\t\t\t\t        / /\n");
    printf("\t\t\t\t\t\t       / /\n");
    printf("\t\t\t\t\t\t__    / / \n");
    printf("\t\t\t\t\t\t%c %c  / / \n", 92, 92);
    printf("\t\t\t\t\t\t %c %c/ / \n", 92, 92);
    printf("\t\t\t\t\t\t  %c__/ \n", 92);
    printf("\t\t\t\t    Factura enviada correctamente!\n");
}

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //Adquirir el control de la consola

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
