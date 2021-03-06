#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

int j = 0;
int folio = 100001;

int menu();

void gotoxy(int x, int y);

void factura();

void dibujo_principal();

void logo();

void marco_fact();

void formatoFact(int dia, int mes, int years);

int buscarProductos(long int clave);

void mostrar(int j1);

void enviarFactura(int j1);

void animacion();

int buscarFolio(long int clave);

struct ImpresionFotoAudio {
    long int folio;
    char descripcion[50];
    float precio;
} productoServicio[25];

struct ImpresionFotoAudio productoServicio[] = {{45121503, "Camaras desechables",                             550.75},
                                                {45121504, "Camaras digitales",                               1500.99},
                                                {45121505, "Camaras cinematograficas",                        550900.90},
                                                {45121506, "Camaras de video conferencia",                    2100.50},
                                                {45121510, "Camaras aereas",                                  800999.99},
                                                {45121511, "Camaras de alta velocidad",                       800753.52},
                                                {45121520, "Camaras de web",                                  650.40},
                                                {45121521, "Camaras de inspeccion",                           4750.60},
                                                {45121522, "Camaras infrarrojas",                             17290.30},
                                                {45121523, "Camaras astronomicas",                            1496.80},
                                                {45121601, "Flashes o iluminacion para camaras",              750.50},
                                                {45121602, "Tripodes para camaras (Tripies para camara)",     250.99},
                                                {45121603, "Lentes para camaras",                             690.20},
                                                {45121604, "Oclusores para camaras",                          340.80},
                                                {45121622, "Limpiadores para lentes de camara",               159.99},
                                                {82131601, "Servicios de fotografia aerea",                   3579.99},
                                                {82131602, "Cinematografia",                                  1350500},
                                                {82131603, "Servicios de produccion de videos",               3629.99},
                                                {82131604, "Servicios de estudio fotografico o fotos fijas",  452.40},
                                                {82131501, "Elaboracion o reproduccion de pelicula fija",     1800000},
                                                {82131502, "Elaboracion o reproduccion de peliculas de cine", 3900750},
                                                {82131503, "Servicios de microficha",                         250.70},
                                                {82131504, "Separacion de colores",                           560.50},
                                                {82131505, "Servicio de posproduccion de peliculas",          6875.10}};

struct Usuarios {
    char usuario[20];
    char password[15];
    char name[50];
    char PCorporativo[50];
} Usuario[5];

struct Usuarios Usuario[] = {{"Carlos",        "Carlos_08",  "Escobar Ibarra Carlos Roberto",   "Vicepresidente"},
                             {"Sam_jimenez02", "Samuel_J02", "Jimenez Abrica Samuel Enrique"},
                             {"Emilio",        "EM10_",      "Giacomo Quintero Emilio Josafat", "Gerente de operaciones"},
                             {"j",             "jaja",       "SAM",                             "Puto jefe"}};

struct serviciosYproductos {
    long int claveSP;
    char descripcion[50];
    int cantidad;
    float costo;
    float subtotal;
} SP[30];

struct factura {
    int dia, mes, year;
    char cert[32], nombre_empresa[30], rfc[13], calle[50], colonia[50], ciudad[50], estado[50], pais[50], numero[10];
    char folio[3];
    int Folio;
    int c_postal, claveRegimen, cantS_P;
    struct serviciosYproductos SP[30];
    char firmaDigital[70];
    char qr;
} datos[100];

struct ClaveRegimenPersonaFisica {
    int clave;
    char descripcion[50];
} clavesFIS[11];

struct ClaveRegimenPersonaFisica clavesFIS[] = {{605, "Sueldos y Salarios e Ingresos Asimilados a Salarios."},
                                                {606, "Arrendamiento"},
                                                {608, "Demas ingresos."},
                                                {611, "Ingresos por Dividendos."},
                                                {612, "Persona fisica con actividades empresariales y profesionales."},
                                                {614, "Ingresos por intereses."},
                                                {615, "Ingresos por obtencion de premios."},
                                                {616, "Sin obligaciones fiscales."},
                                                {621, "Incorporacion fiscal."},
                                                {622, "Actividades agricolas, ganaderas, silvicolas y pesqueras."},
                                                {629, "Preferentes y de empresas multinacionales."},
                                                {630, "Enajenacion de acciones en bolsa de valores."}};

struct ClaveRegimenPersonaMoral {
    int clave;
    char descripcion[50];
} clavesMOR[8];

struct ClaveRegimenPersonaMoral clavesMOR[] = {{601, "General de Ley Personas Morales."},
                                               {603, "Personas Morales con Fines no Lucrativos."},
                                               {607, "Enajenaci??n o Adquisici??n de Bienes"},
                                               {609, "Consolidacion."},
                                               {620, "Sociedades Cooperativas de Producci??n que optan por Diferir sus Ingresos"},
                                               {622, "Actividades Agr??colas, Ganaderas, Silv??colas y Pesqueras."},
                                               {623, "Opcional para Grupos de Sociedades."},
                                               {624, "Coordinados."},
                                               {628, "Hidrocarburos."}};


int main() {
    char usuario[20];
    char caracter, resp;
    char Miclave[15];
    int i, error = 0, aux, posicion, opcion;

    do {
        do {
            system("CLS");
            dibujo_principal();
            i = 0;
            gotoxy(47, 23);
            printf("Usuario: ");
            fflush(stdin);
            gets(usuario);
            gotoxy(47, 24);
            printf("Contrase%ca: ", 164);
            while (caracter = getch()) {
                if (caracter == 13) {
                    Miclave[i] = '\0';
                    break;
                } else if (caracter == 8) {
                    if (i > 0) {
                        i--;
                        printf("\b \b");
                    }
                } else {
                    printf("*");
                    Miclave[i] = caracter;
                    i++;
                }

            }
            aux = 0;
            for (i = 0; i < 5; i++) {
                if (strcmp(Usuario[i].usuario, usuario) == 0 && (strcmp(Usuario[i].password, Miclave) == 0)) {
                    aux = 1;
                    posicion = i;
                }
            }
            if (aux != 1) {
                gotoxy(32, 27);
                printf("\nUsuario o contrase%ca incorrecta, intento de nuevo.\n", 164);
                error++;
                getch();
            }

            if (aux == 1) {
                gotoxy(32, 27);
                printf("Bienvenido al sistema ");
                puts(Usuario[posicion].name);
                error = 4;
            }
        } while (error < 3);
        if (error == 3)
            exit(0);
        do {
            opcion = menu();
            switch (opcion) {
                case 1:
                    system("CLS");
                    logo();
                    factura();
                    break;
                case 2:
                    printf("*Mostrar FACTURA*\n");
                    int bandera = 1;
                    do {

                        int folioTemp;
                        printf("Introduce el folio de la factura que deseas buscar\n");
                        scanf("%i", &folioTemp);

                        for (int j1 = 0; j1 <= 100; j1++) {
                            if (datos[j1].folio == folioTemp) {
                                printf("*FACTURA ENCONTRADA*\n");
                                mostrar(j1);
                                bandera = 0;
                            }
                        }
                    } while (bandera != 0);
                    break;

                case 3:
                    printf("*Enviar FACTURA*\n");
                    bandera = 1;
                    do {
                        char folioTemp[10];
                        printf("Introduce el folio de la factura que deseas enviar\n");
                        scanf("%s", &folioTemp);

                        for (int j1 = 0; j1 <= 100; j1++) {
                            if (strcmpi(datos[j1].folio, folioTemp) == 0) {
                                enviarFactura(j1);
                                bandera = strcmpi(datos[j1].folio, folioTemp);
                            }
                        }
                    } while (bandera != 0);
                    break;
                case 4:
                    exit(0);
                    break;
            }
            printf("\nDesea realizar otra operacion s(Si) o n(No)\n");
            fflush(stdin);
            scanf("%c", &resp);
        } while (resp == 's' || resp == 'S');
        printf("\nDesea realizar otra operacion s(Si) o n(No)\n");
        fflush(stdin);
        scanf("%c", &resp);
    } while (resp == 's' || resp == 'S');
    return 0;
}

void enviarFactura(int j1) {
    animacion();
    printf("*FACTURA ENVIADA*\n");
    char muestra[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789012345678";
    datos[j1].firmaDigital = muestra;
    mostrar(j1);

}

int menu() {
    system("CLS");
    int opc;
    gotoxy(0, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223);
    gotoxy(0, 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(0, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 188);
    gotoxy(50, 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 187);
    gotoxy(50, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 188);
    gotoxy(50, 2);
    printf("%cMen%c principal%c\n", 186, 163, 186);
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
    scanf("%d", &opc);
    return opc;
}

void mostrar(int j1) {

    printf("Nombre: %s", datos[j1].nombre_empresa);
    printf("\nRFC: %s", datos[j1].rfc);
    printf("\nClave de R%cgimen Fiscal: %d", 130, datos[j1].claveRegimen);

    printf("\n*Domicilio fiscal*: ");
    printf("\nCalle: %s", datos[j1].calle);
    printf("\nN%cmero: %s ", 163, datos[j1].numero);
    printf("\nColonia: %s ", datos[j1].colonia);
    printf("\nC%cdigo postal: %d ", 162, datos[j1].c_postal);
    printf("\nCiudad: %s ", datos[j1].ciudad);
    printf("\nEstado: %s ", datos[j1].estado);
    printf("\nPa%cs: %s ", 161, datos[j1].pais);
    printf("\nFirma Digital: %s", datos[j1].firmaDigital);
    printf("\nQR: %c", datos[j1].qr);

    printf("\n\t*Detalles de productos de la factura*\n");
    printf("Clave\tDescripcion\tCantidad\tCosto\tSubtotal\n");
    /*
    for (int i = 0; i < 30; i++) {
        if (strcmpi(datos[j1].SP[i].claveSP, "") != 0) {
            printf("\n%s\t", datos[j1].SP[i].claveSP);
            printf("%s\t",datos[j1].SP[i].descripcion);
            printf("%d\t", datos[j1].SP[i].cantidad);
            printf("%.2f\t", datos[j1].SP[i].costo);
            printf("%.2f\t", datos[j1].SP[i].subtotal);
        }
    }
     */
}


void factura() {
    int aux, dia, mes, years, i, k, posicion, aux2 = 0, cant, resp, x;
    long int busqueda;

    srand(time(NULL));
    datos[j].dia = (rand() % 31) + 1;
    datos[j].mes = (rand() % 12) + 1;
    datos[j].year = 2020;
    datos[j].Folio = folio;

    dia = datos[j].dia;
    mes = datos[j].mes;
    years = datos[j].year;

    formatoFact(dia, mes, years);

    gotoxy(1, 16);
    printf("Nombre de la empresa: ");
    fflush(stdin);
    gets(datos[j].nombre_empresa);
    do {
        gotoxy(1, 17);
        printf("RFC: ");
        fflush(stdin);
        gets(datos[j].rfc);
        if (strlen(datos[j].rfc) == 13) {
            do {
                gotoxy(1, 18);
                printf("Clave de R%cgimen Fiscal: ", 130);
                scanf("%d", &datos[j].claveRegimen);
                for (i = 0; i < 100; i++) {
                    if (datos[j].claveRegimen == clavesFIS[i].clave) {
                        gotoxy(1, 19);
                        printf("R%cgimen: ", 130);
                        posicion = i;
                        puts(clavesFIS[posicion].descripcion);
                        aux2 = 1;
                        aux = 0;
                    }
                }
                if (aux2 != 1) {
                    formatoFact(dia, mes, years);
                    gotoxy(1, 20);
                    printf("Clave incorrecta.");
                }
            } while (aux2 != 1);
        } else if (strlen(datos[j].rfc) == 12) {
            do {
                gotoxy(1, 18);
                printf("Clave de R%cgimen Fiscal: ", 130);
                scanf("%d", &datos[j].claveRegimen);
                for (i = 0; i < 100; i++) {
                    if (datos[j].claveRegimen == clavesMOR[i].clave) {
                        gotoxy(1, 19);
                        printf("R%cgimen: ", 130);
                        posicion = i;
                        puts(clavesMOR[posicion].descripcion);
                        aux2 = 1;
                        aux = 0;
                    }
                }
                if (aux2 != 1) {
                    formatoFact(dia, mes, years);
                    gotoxy(1, 20);
                    printf("Clave incorrecta.");
                }
            } while (aux2 != 1);
        } else {
            formatoFact(dia, mes, years);
            printf("RFC no valido.\n");
            aux = 1;
        }
    } while (aux == 1);

    gotoxy(20, 17);
    printf("Domicilio fiscal: ");
    gotoxy(40, 17);
    printf("Calle: ");
    fflush(stdin);
    gets(datos[j].calle);
    gotoxy(50, 17);
    printf("N%cmero: ", 163);
    fflush(stdin);
    gets(datos[j].numero);
    gotoxy(60, 17);
    printf("Colonia: ");
    fflush(stdin);
    gets(datos[j].colonia);
    printf("C%cdigo postal: ", 162);
    scanf("%d", &datos[j].c_postal);
    printf("Ciudad: ");
    fflush(stdin);
    gets(datos[j].ciudad);
    printf("Estado: ");
    fflush(stdin);
    gets(datos[j].estado);
    printf("Pa%cs: ", 161);
    fflush(stdin);
    gets(datos[j].pais);
    printf("%cCu%cntos productos o servicios facturar%c%c: ", 168, 160, 160, 63);
    scanf("%d", &datos[j].cantS_P);
    for (i = 0; i < datos[j].cantS_P; i++) {
        printf(" ");
        scanf("%d", &busqueda);
        x = buscarProductos(busqueda);
        if (x >= 0) {
            datos[j].SP[i].claveSP = productoServicio[x].folio;
            strcpy(datos[j].SP[i].descripcion, productoServicio[x].descripcion);
            datos[j].SP[i].costo = productoServicio[x].precio;
            printf("Ingresa la cantidad de productos y/o servicios: ");
            scanf("%d", &datos[j].SP[i].cantidad);
            datos[j].SP[i].subtotal = datos[j].SP[i].costo * datos[j].SP[i].cantidad;
        }
    }
    for (i = 0; i < datos[j].cantS_P; i++) {
        printf("\n%d\n", datos[j].SP[i].claveSP);
        puts(datos[j].SP[i].descripcion);
        printf("%d\n", datos[j].SP[i].cantidad);
        printf("%.2f", datos[j].SP[i].subtotal);
    }

    printf("%cFactura creada exitosamente%c", 173, 33);
    j++;
    folio++;
}

int buscarProductos(long int clave) {
    int i;
    for (i = 0; i < 30; i++) {
        if (clave == productoServicio[i].folio)
            return i;
    }
}

int buscarFolio(long int clave){
    int i, a = 1;

    for(i = 0; i < 100; i++)
    {
        if(clave == datos[i].Folio)
        {
            return(i);
            a = 2;
        }
    }
    if(a != 2)
        return(-1);
}

void logo() {
    gotoxy(2, 3);
    printf("________%c%c%c%c%c________\n", 220, 220, 220, 220, 220);
    gotoxy(2, 4);
    printf("______%c%c%c%c%c%c%c%c%c______\n", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(2, 5);
    printf("______%c%c%c%c%c%c%c%c%c______\n", 219, 176, 178, 178, 178, 178, 178, 176, 219);
    gotoxy(2, 6);
    printf("______%c%c%c%c%c%c%c%c%c______\n", 219, 176, 205, 205, 205, 205, 205, 176, 219);
    gotoxy(2, 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 176, 32, 32, 32, 32, 32,
           176, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(2, 8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219,
           219, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 176, 220, 254, 254, 254, 220,
           176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 176, 219, 32, 32, 32, 219,
           176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 176, 219, 220, 220, 220, 219,
           176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(2, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 220, 220, 220, 220, 220, 219, 219, 220, 220, 220, 220,
           220, 219, 219, 220, 220, 220, 220, 220, 219);
    gotoxy(2, 13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220,
           220, 220, 220, 220, 220, 220, 220, 220, 219);
}

void marco_fact() {
    gotoxy(0, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223);
    gotoxy(0, 15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223);
    gotoxy(0, 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(0, 28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 188);
}

void dibujo_principal() {
    gotoxy(1, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223);
    //Izquierda short 1
    gotoxy(1, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Izquierda short 2
    gotoxy(1, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Larga
    gotoxy(1, 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223);
    //printf("????__??_??????_\n_??????????___??????????_\n??????????????????????????????\n????????????___????????????\n??_____________%c??: ", 220);
    //Derecha short 0
    gotoxy(79, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Derecha short 1
    gotoxy(89, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Derecha short 2
    gotoxy(89, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
    //DATOS U & C
    //D Superior
    gotoxy(46, 21);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220,
           220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
    //D Inferior
    gotoxy(46, 26);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220,
           220, 220, 220, 220, 220, 220, 220, 220, 220, 219);
    //D Centro
    gotoxy(46, 22);
    printf("%c", 219);
    //gotoxy(67, 22);
    //printf("%c",219);
    gotoxy(67, 22);
    printf("%c", 219);
    //Relleno centro
    //1111111
    gotoxy(47, 22);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,
           176, 176, 176, 176, 176, 176, 176, 176);
    //2222222
    gotoxy(47, 25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,
           176, 176, 176, 176, 176, 176, 176, 176);
    //Superior
    gotoxy(0, 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 187);
    //Recta Izquierda
    //gotoxy(0, 0);
    printf("\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n",
           186, 186, 186, 186, 186, 219, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186,
           186, 186, 186, 186, 186);
    //Recta derecha
    //gotoxy(1, 30);
    //printf("\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n", 186, 186, 186, 186, 186, 219, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
    //Linea Inferior
    gotoxy(0, 28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 188);
    //Segunda Inferior
    gotoxy(0, 29);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223,
           223, 223, 223, 223, 223, 223, 223, 223, 223);
    //Primer Cuadro
    gotoxy(35, 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(35, 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    gotoxy(35, 2);
    printf("%cSistema De Facturacion  LA PINTOREZCA 2021%c\n ", 186, 186);
    //Segundo Cuadro
    gotoxy(23, 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           187);
    gotoxy(23, 5);
    printf("%c", 186);
    gotoxy(88, 5);
    printf("%c", 186);
    gotoxy(23, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,
           188);
    gotoxy(24, 5);
    printf("Equipos y Suministros para Impresion, Fotografia y Audiovisuales\n ");
    gotoxy(47, 8);
    printf("________%c%c%c%c%c________\n", 220, 220, 220, 220, 220);
    gotoxy(47, 9);
    printf("______%c%c%c%c%c%c%c%c%c______\n", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(47, 10);
    printf("______%c%c%c%c%c%c%c%c%c______\n", 219, 176, 178, 178, 178, 178, 178, 176, 219);
    gotoxy(47, 11);
    printf("______%c%c%c%c%c%c%c%c%c______\n", 219, 176, 205, 205, 205, 205, 205, 176, 219);
    gotoxy(47, 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 176, 32, 32, 32, 32, 32,
           176, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(47, 13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 219, 219, 219, 219, 219, 219,
           219, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 176, 220, 254, 254, 254, 220,
           176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 176, 219, 32, 32, 32, 219,
           176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 176, 32, 32, 32, 176, 219, 176, 219, 220, 220, 220, 219,
           176, 219, 176, 32, 32, 32, 176, 219);
    gotoxy(47, 17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 220, 220, 220, 220, 220, 219, 219, 220, 220, 220, 220,
           220, 219, 219, 220, 220, 220, 220, 220, 219);
    gotoxy(47, 18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220,
           220, 220, 220, 220, 220, 220, 220, 220, 219);
}


void formatoFact(int day, int month, int year) {
    gotoxy(100, 6);
    printf("Folio: ");
    puts(datos[j].folio);
    gotoxy(111, 6);
    printf("%d", datos[j].Folio);
    gotoxy(75, 8);
    printf("Cert CSD: SEJA2178643190000000000000000000");
    gotoxy(89, 7);
    printf("Fecha de emision:\n");
    if (day >= 10 && month >= 10) {
        gotoxy(107, 7);
        printf("%d/%d/%d", day, month, year);
    }

    if (day < 10 && month >= 10) {
        gotoxy(107, 7);
        printf("0%d/%d/%d", day, month, year);
    }

    if (day >= 10 && month < 10) {
        gotoxy(107, 7);
        printf("%d/0%d/%d", day, month, year);
    }

    if (day < 10 && month < 10) {
        gotoxy(107, 7);
        printf("0%d/0%d/%d", day, month, year);
    }

    marco_fact();
    logo();
    gotoxy(45, 4);
    printf("F A C T U R A C I %c N     E L E C T R %c N I C A", 224, 224);
    gotoxy(25, 7);
    printf("Nombre de la empresa: La Pintorezca %c", 169);
    gotoxy(25, 8);
    printf("RFC: JIAS021111RQ6");
    gotoxy(25, 10);
    printf("Domicilio fiscal: Calle Consituci%cn #36  Colonia: Centro 46540, San Marcos, Jalisco, M%cxico.", 162, 130);
    gotoxy(25, 11);
    printf("Persona Fis%cca | R%cgimen Fiscal: 601 - R%cgimen General", 161, 130, 130);
}

void animacion() {
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

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //Adquirir el control de la consola

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
