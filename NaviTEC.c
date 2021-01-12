//#include <locale.h>
#include <stdio.h> 
#include <windows.h>   /* Obtener informacion de la consola y cambiar atributos */

void menuPrincipal();
void tituloPrincipal();

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
    SetConsoleTextAttribute(hConsole, 11);
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