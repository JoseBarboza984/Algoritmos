//#include <locale.h>
#include <stdio.h> 
#include <windows.h>   /* Obtener informacion de la consola y cambiar atributos */

#define MIN 15
#define MED 30
#define MAX 50


typedef struct SLugar Lugar;
typedef struct SRuta Ruta;
typedef struct SListaL ListaL;
typedef struct SPersona Persona;
typedef struct SListaP ListaP;
typedef struct SAyudante Ayudante;
typedef struct SListaA ListaA;

struct SLugar{
	char Nombre[MIN];
	int CodigoP;
	Ruta *rutas;
	Lugar *siguiente;
};

struct SRuta{
	int Tiempo;
	int Distancia;
	char Tipo[MIN];
	Lugar *oringen;
	Lugar *destino;
	Ruta *siguiente;
};

struct SListaL{
	Lugar *Inicio;
};

struct SPersona
{
	int ID;
	int Edad;
	char Nombre[MED];
	char Usuario[MED];
	char Residencia[MED];
	char Correo[MED];
	char Fecha[MIN];
	char Extra[MED];
	Persona *siguiente;
};

struct SListaP
{
	Persona *Inicio;
};

struct SAyudante
{
	int ID;
	char Nombre[MED];
	char Puesto[MED];
	char Funciones[MAX];
	char Fecha[MIN];
	Persona *siguiente;
};

struct SListaA
{
	Ayudante *Inicio;
};

void menuDomicilio();
void menuDomicilio_01();
void menuDomicilio_02();
void menuDomicilio_03();
void menuDomicilio_04();
void menuDomicilio_05();
void menuDomicilio_06();

void menuPrincipal();
void tituloPrincipal();

/*==============================================================================================================================*/

Persona *CrearPersona(char *nombre, char *usuario, char *residencia, char *correo, char *fecha, char *extra, int id, int edad)
{	// Funcion para copiar todos los elementos a un nodo  
	Persona *nodo = (Persona *) malloc(sizeof(Persona));
	strcpy(nodo->Nombre, nombre);
	strcpy(nodo->Usuario, usuario);
	strcpy(nodo->Residencia, residencia);
	strcpy(nodo->Correo, correo);
	strcpy(nodo->Fecha, fecha);
	strcpy(nodo->Extra, extra);
	nodo->ID = id;
	nodo->Edad = edad;
	return nodo;
}

void InsertarPersona(ListaP *Lista, char *nombre, char *usuario, char *residencia, char *correo, char *fecha, char *extra, int id, int edad)
{	// Funcion para insertar el nodo en la lista   
	Persona *puntero = Lista->Inicio;	// Puntero para recorrer la lista
	Persona *nuevo = CrearPersona(nombre, usuario, residencia,correo, fecha, extra, id, edad);	// Se crea el nuevo nodo
	nuevo->siguiente = NULL;
	if (puntero == NULL)
	{	// Validacion de lista vacia
		Lista->Inicio = nuevo;	// Se copia el nodo
	}
	else
	{
		while (puntero->siguiente != NULL)
		{	// Se recorre toda la lista
			puntero = puntero->siguiente;
		}
		puntero->siguiente = nuevo;	 // Se copia el nodo
	}
	printf("\tSe realizo la operacion de forma existosa");
	return;
}

void ModificarPersona(ListaP *Lista, char *nombre, char *usuario, char *residencia, char *correo, char *fecha, char *extra, int id, int edad)
{
	Persona *puntero = Lista->Inicio; 	// Puntero para recorrer la lista
	if (puntero == NULL)
	{	// Validacion de lista vacia
		printf("\tError, la lista se encuetra vacia");
		return;
	}
	while (puntero != NULL)
	{ 	// Se recorre la lista hasta encontar el id o llegar al final de esta
		if (puntero->ID == id)
			break;
		puntero = puntero->siguiente;
	}
	if (puntero != NULL)
	{ 	// Se rescriben las variables del nodo
		strcpy(puntero->Nombre, nombre);
		strcpy(puntero->Usuario, usuario);
		strcpy(puntero->Residencia, residencia);
		strcpy(puntero->Correo, correo);
		strcpy(puntero->Fecha, fecha);
		strcpy(puntero->Extra, extra);
		puntero->Edad = edad;
		printf("\tSe realizo la operacion de forma existosa");
		return;
	}
	else
	{ 	// Validacion al no encontrar el id en la lista
		printf("\tError, el ID ingresado no se encuentra en la lista");
		return;
	}	
}

void EliminarPersona(ListaP *Lista, int id)
{
	Persona *puntero = Lista->Inicio;
	Persona *anterior = NULL;
	if(puntero == NULL)
	{	// Validacion de lista vacia
		printf("\tError, la lista se encuetra vacia");
		return;
	}
	while (puntero->siguiente == NULL)
	{
		if(puntero->ID == id)
		{
			if (anterior == NULL)
			{
				Lista->Inicio = puntero->siguiente;
				free(puntero);
			}
			else
			{
				anterior->siguiente = puntero->siguiente;
				free(puntero);
			}
			printf("\tSe realizo la operacion de forma existosa");
			return;
		}
		anterior = puntero;
		puntero = puntero->siguiente;
	}
	printf("\tError, el ID ingresado no se encuentra en la lista");
	return;
}

int ValidacionID(ListaP *Lista, int id)
{	// Recibe lista de personas y un id, retorna 1 si el id se encuentra en la lista y 0 si no.
	Persona *puntero = Lista->Inicio;
	if(puntero == NULL)
		return 0;
	while (puntero->siguiente == NULL)
	{
		if(puntero->ID == id)
			return 1;
		puntero = puntero->siguiente;
	}
	return 0;
}

Ayudante *CrearAyudante(char *nombre, char *puesto, char *funciones, char *fecha, int id)
{
	Ayudante *nodo = (Ayudante *) malloc(sizeof(Ayudante));
	strcpy(nodo->Nombre, nombre);
	strcpy(nodo->Puesto, puesto);
	strcpy(nodo->Funciones, funciones);
	strcpy(nodo->Fecha, fecha);
	nodo->ID = id;
	return nodo;
}

void InsertarAyudante(ListaA *Lista, char *nombre, char *puesto, char *funciones, char *fecha, int id)
{	// Funcion para insertar el nodo en la lista 
	Ayudante *puntero = Lista->Inicio;	 // Puntero para recorrer la lista
	Ayudante *nuevo = CrearAyudante(nombre, puesto, funciones, fecha, id); 	// Se crea el nuevo nodo
	nuevo->siguiente = NULL;
	if (puntero == NULL)
	{ 	// Validacion de lista vacia
		Lista->Inicio = nuevo; 	// Se copia el nodo
	}
	else
	{
		while (puntero->siguiente != NULL)
		{ 	// Se recorre toda la lista
			puntero = puntero->siguiente;
		}
		puntero->siguiente = nuevo;  // Se copia el nodo
	}
	printf("\tSe realizo la operacion de forma existosa");
	return;
}

void ModificarAyudante(ListaA *Lista, char *nombre, char *puesto, char *funciones, char *fecha, int id)
{	// Funcion para rescribir la informacion de un nodo
	Ayudante *puntero = Lista->Inicio;	 // Puntero para recorrer la lista
	if (puntero == NULL)
	{	// Validacion de lista vacia
		printf("\tError, la lista se encuetra vacia");
		return;
	}
	while (puntero != NULL)
	{ 	// Se recorre la lista hasta encontar el id o llegar al final de esta
		if (puntero->ID == id)
			break;
		puntero = puntero->siguiente;
	}
	if (puntero != NULL)
	{ 	// Se rescriben las variables del nodo
		strcpy(puntero->Nombre, nombre);
		strcpy(puntero->Puesto, puesto);
		strcpy(puntero->Funciones, funciones);
		strcpy(puntero->Fecha, fecha);
		printf("\tSe realizo la operacion de forma existosa");
		return;
	}
	else
	{ 	// Validacion al no encontrar el id en la lista
		printf("\tError, el ID ingresado no se encuentra en la lista");
		return;
	}	
}

/*==============================================================================================================================*/

void menuPersona(ListaP *Lista)
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tMENU PERSONA\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

		printf("\t\t[01]. Registro de ni%co/ni%ca\n", -92, -92);
		printf("\t\t[02]. Modificar informacion de ni%co/ni%ca\n", -92, -92);
		printf("\t\t[03]. Eliminar informacion de ni%co/ni%ca\n", -92, -92);
        printf("\t\t[04]. Salir al menu principal\n");

			SetConsoleTextAttribute(hConsole, 14);

		printf("\n\t\tIngrese su opcion: [  ]\b\b\b");
 
			SetConsoleTextAttribute(hConsole, saved_attributes);

		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				repite = 0;
                break;
			default:
				printf("Error: Favor ingresar uno de los numeros que se muestran en la consola!");
		}
	} while (repite);
}

void menuPersona_01(ListaP *Lista)
{
	char repite = 1; // Se define variable para validaciones 
	int id, edad;    // Se definen las variables para la obtencion de datos
	char nombre[MED], usuario[MED], residencia[MED], correo[MED], fecha[MIN], extra[MED];

	printf("\tIngrese la identificacion: ");
	sscanf("%i", id);
	printf("\tIngrese el nombre completo: ");
	sscanf("%s", &nombre);
	do	// Validacion de la residencia
	{
		printf("\tIngrese el lugar de residencia: ");
		sscanf("%s", &residencia); //Falta validacion
		if (repite)
			repite = 0;
	} while (repite);
	repite = 1;
	printf("\tIngrese el  correo electronico: ");
	sscanf("%s", &correo);
	printf("\tIngrese la fecha de nacimiento: ");
	sscanf("%s", &fecha);
	printf("\tIngrese la edad: ");
	sscanf("%s", &edad);
	printf("\tIngrese necesidades especiales: ");
	sscanf("%s", &extra);
	InsertarPersona(Lista, nombre, usuario, residencia, correo, fecha, extra, id, edad);
	printf("\nPresione ENTER para continuar...");
    system("pause>nul");
}

void menuPersona_02(ListaP *Lista)
{
	char repite = 1, respuesta[5]; // Se define variable para validaciones 
	int id, edad;    // Se definen las variables para la obtencion de datos
	char nombre[MED], usuario[MED], residencia[MED], correo[MED], fecha[MIN], extra[MED];
	do
	{
		printf("\tIngrese la identificacion: ");
		sscanf("%i", id);
		if (ValidacionID(Lista, id) == 0)
		{
			printf("\tError: el numero de identificacion ingresado es incorrecto");
			printf("\n\tDesea seguir intentando? [S/N]: ");
			scanf("%s", respuesta);
			if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
				repite = 0;
			}
		}
		else
			repite = 0;
	} while (repite);
	repite = 1;
	printf("\tIngrese el nombre completo: ");
	sscanf("%s", &nombre);
	do	// Validacion de la residencia
	{
		printf("\tIngrese el lugar de residencia: ");
		sscanf("%s", &residencia); //Falta validacion
		if (repite)
			repite = 0;
	} while (repite);
	repite = 1;
	printf("\tIngrese el  correo electronico: ");
	sscanf("%s", &correo);
	printf("\tIngrese la fecha de nacimiento: ");
	sscanf("%s", &fecha);
	printf("\tIngrese la edad: ");
	sscanf("%s", &edad);
	printf("\tIngrese necesidades especiales: ");
	sscanf("%s", &extra);
	ModificarPersona(Lista, nombre, usuario, residencia, correo, fecha, extra, id, edad);
	printf("\nPresione ENTER para continuar...");
    system("pause>nul");
}

void menuPersona_03(ListaP *Lista)
{
	char repite = 1, respuesta[5]; // Se define variable para validaciones
	int id;
	do
	{
		printf("\tIngrese la identificacion: ");
		sscanf("%i", id);
		if (ValidacionID(Lista, id) == 0)
		{
			printf("\tError: el numero de identificacion ingresado es incorrecto");
			printf("\n\tDesea seguir intentando? [S/N]: ");
			scanf("%s", respuesta);
			if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
				repite = 0;
			}
		}
		else
			repite = 0;
	} while (repite);
	EliminarPersona(Lista, id);
	printf("\nPresione ENTER para continuar...");
    system("pause>nul");
}



void menuDomicilio()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tMENU DOMICILIO\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

		printf("\t\t[01]. Registro de domicilio\n");
		printf("\t\t[02]. Registro de ruta\n");
		printf("\t\t[03]. Modificar domicilio\n");
		printf("\t\t[04]. Modificar ruta\n");
		printf("\t\t[05]. Eliminar domicilio\n");
		printf("\t\t[06]. Eliminar ruta\n");
        printf("\t\t[07]. Salir al menu principal\n");

			SetConsoleTextAttribute(hConsole, 14);

		printf("\n\t\tIngrese su opcion: [  ]\b\b\b");
 
			SetConsoleTextAttribute(hConsole, saved_attributes);

		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
            case 7:
				repite = 0;
                break;
			default:
				printf("Error: Favor ingresar uno de los numeros que se muestran en la consola!");
		}
	} while (repite);
}

void menuDomicilio_01()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tREGISTRAR DOMICILIO\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

	} while (repite);
}

void menuDomicilio_02()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tREGISTRAR RUTA\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

	} while (repite);
}

void menuDomicilio_03()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tMODIFICAR DOMICILIO\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

	} while (repite);
}

void menuDomicilio_04()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tMODIFICAR RUTA\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

	} while (repite);
}

void menuDomicilio_05()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tELIMINAR DOMICILIO\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

	} while (repite);
}

void menuDomicilio_06()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tELIMINAR RUTA\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

	} while (repite);
}

/*==============================================================================================================================*/

void menuPrincipal()
{
	char repite = 1;
	int opcion = 0;
	do {
		system("cls");
 
		tituloPrincipal();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    		WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
 
		printf("\n\t\t\t\tMENU PRINCIPAL\n\n");

			SetConsoleTextAttribute(hConsole, saved_attributes);

		printf("\t\t[01]. Registro de ni%co/ni%ca\n", -92, -92);
		printf("\t\t[02]. Registro de ayudante de santa\n");
		printf("\t\t[03]. Registro de jugetes\n");
		printf("\t\t[04]. Catalogos para lugares de domicilio\n");
		printf("\t\t[05]. Registro de comportamiento de ni%co/ni%ca\n", -92, -92);
		printf("\t\t[06]. Carta para santa\n");
        printf("\t\t[07]. Procesar cartas para Santa\n");
        printf("\t\t[08]. Entrega de juguetes\n");
        printf("\t\t[09]. Analisis de datos\n");
        printf("\t\t[10]. Salir\n");

			SetConsoleTextAttribute(hConsole, 14);

		printf("\n\t\tIngrese su opcion: [  ]\b\b\b");
 
			SetConsoleTextAttribute(hConsole, saved_attributes);

		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				menuDomicilio();
				break;
			case 5:
				break;
			case 6:
				break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                repite = 0;
                break;
			default:
				printf("Error: Favor ingresar uno de los numeros que se muestran en la consola!");
		}
	} while (repite);
}

void tituloPrincipal()
{
	int i;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //11
	printf("\n     ======================================================================\n");
	printf("\t\t\t\t     NAVI-TEC\n");
	printf("\t\t  Proyecto Programado II - Segundo Semestre 2020\n");
	printf("\t\t    Jose Barboza | Joshua Ramirez | Axel Lopez\n");
	printf("     ======================================================================");
	i = 0;
	putchar('\n');
	for (; i < 80; i++) {
		putchar('_');
	}
	SetConsoleTextAttribute(hConsole, saved_attributes);
}

void main()
{
    menuPrincipal();
    //printf("%c",-99);
    //printf("\xA5"); 
    //printf("\xA4");
}
