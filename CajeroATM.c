//Librerias//
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<string.h>
#include"prefijos.h"                //Libreria con cuadros de prefijos Claro y Tigo//

#define ENTER 13
#define ESPACIO 32

//Funciones//
void Inicio();
void Presentacion();                //Presentación del Proyecto//
void Credenciales();                //Pantalla de inicio de Sesion + Estetica "Verificación"//
void Cargando();                    //Estetica//                     
void FuncionIngresoATM();           //Deposito de saldo en el cajero//
void FuncionRetiroATM();            //Retiro de saldo en el cajero//
void FuncionRecarga();              //Recarga Electronica//
char *VerificacionPrefijos(int);    //Verificación de prefijos con retorno de telefonia//
void PantallaSalida();

//Variable Global//
int contador = 3;
int saldo = 0;  

int main()
{
    int Opc, Caso1, Caso2, Decision;
    int OpcValid, Caso1Valid, Caso2Valid, DecisionValid = 0; 

    Inicio();
    Reset:
    Credenciales();
    Cargando();
    system("cls");

    MenuPrincipal:
    Opc = 0;
    fflush(stdin);
    system("color a");
    system("cls");
    printf("\t\t\t\t\t_________________________________\n");
    printf("\n\t\t\t\t\t*        Menu principal         *");
    printf("\n\t\t\t\t\t_________________________________\n");
    printf("\n\t\t\t\t   Seleccione una de las siguientes opciones: \n");
    printf("\n\t\t1. Presentacion\n");
    printf("\n\t\t2. Cajero ATM-UNI\n");
    printf("\n\t\t3. Recarga Electronica\n");
    printf("\n\t\t4. Salir\n");
    printf("\n\t\t\t-> Opcion: ");
    Opc = getch();
    system("cls");
    if (Opc > 48 && Opc < 58)
    {
        switch (Opc)
        {
        case 49:
            OpcValid = 1;
            break;
        case 50:
            OpcValid = 2;
            break;
        case 51:
            OpcValid = 3;
            break;
        case 52:
            OpcValid = 4;
            break;
        }
    switch (OpcValid)
    {
    case 1:
        Presentacion();
        goto MenuPrincipal;

    case 2:
        CajeroATM:
        system("cls");
        printf("\t\t\t\t   _________________________________\n");
        printf("\n\t\t\t\t   *        Cajero ATM-UNI         *");
        printf("\n\t\t\t\t   _________________________________\n");
        printf("\n\t\t\t\t\tSeleccione una opcion: \n");
        printf("\n\t\t1. Ingresar saldo\n");
        printf("\n\t\t2. Ver saldo\n");
        printf("\n\t\t3. Retirar saldo\n");
        printf("\n\t\t4. Cancelar\n");
        printf("\n\t\t\t-> Opcion: ");
        Caso1 = getch();
        system("cls");
        if (Caso1 > 48 &&  Caso1 < 58)
        {
            switch (Caso1)
            {
            case 49:
                Caso1Valid = 1;
                break;
            case 50:
                Caso1Valid = 2;
                break;
            case 51:
                Caso1Valid = 3;
                break;
            case 52:
                Caso1Valid = 4;
                break;
            }
            switch (Caso1Valid)
            {
            case 1:
                FuncionIngresoATM();
                system("cls");
                goto CajeroATM;

            case 2: 
                printf("\n\t\t\t\t\t\t* Ver saldo *\n");
                printf("\n\t\t\t\t-> Su saldo actual es: C$ %i.", saldo);
                getch();
                system("cls");
                goto CajeroATM;

            case 3: 
                Credenciales();
                system("cls");
                FuncionRetiroATM();
                system("cls");
                goto CajeroATM;
            
            case 4:
                goto Decision;

            default:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   (!)Opcion incorrecta.");
                printf("\n\t\t\t\t\t   -> Digite una opcion valida.");
                sleep(1);
                goto CajeroATM;
            }
        }
        else
        {   
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   (!)Opcion incorrecta.");
            printf("\n\t\t\t\t\t   -> Digite una opcion valida.");
            sleep(1);
            goto CajeroATM;
        }
    case 3:
        Recarga:
        system("cls");
        printf("\n\t\t\t\t   _________________________________\n");
        printf("\n\t\t\t\t   *      Recarga Electronica      *\n");
        printf("\t\t\t\t   _________________________________\n");
        printf("\n\t\t\t\tSeleccione una opcion: \n");
        printf("\n\t\t1. Ingresar numero telefonico\n");
        printf("\n\t\t2. Cancelar\n");
        printf("\n\t\t\t-> Opcion: ");
        Caso2 = getch();
        system("cls");
        if(Caso2 > 48 && Caso2 < 58)
        {
            switch (Caso2)
            {
            case 49:
                Caso2Valid = 1;
                break;
            case 50:
                Caso2Valid = 2;
                break;
            }
            switch (Caso2Valid)
            {
            case 1: 
                FuncionRecarga();
                system("cls");
                goto Recarga;

            case 2:
                goto Decision;
                
            default:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   (!)Opcion incorrecta.");
                printf("\n\t\t\t\t\t   -> Digite una opcion valida.");
                sleep(1);
                goto Recarga;
            }
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   (!)Opcion incorrecta.");
            printf("\n\t\t\t\t\t   -> Digite una opcion valida.");
            sleep(1);
            goto Recarga;
        }

    case 4: 
        PantallaSalida();
        system("cls");
        main();

    default:
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   (!)Opcion incorrecta.");
        printf("\n\t\t\t\t\t   -> Digite una opcion valida.");
        sleep(1);
        goto MenuPrincipal;
    }
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   (!)Opcion incorrecta.");
        printf("\n\t\t\t\t\t   -> Digite una opcion valida.");
        sleep(1);
        goto MenuPrincipal;
    }
    //Pantalla Pregunta//
    Decision:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Desea realizar otra transaccion?\n");
    printf("\n\t\t\t\t\t 1. Si\n");
    printf("\n\t\t\t\t\t 2. No\n");
    printf("\n\t\t\t\t\t\t -> Opcion: ");
    Decision = getch();
    if(Decision > 48 && Decision < 58)
    {
        switch (Decision)
        {
        case 49:
            DecisionValid = 1;
            break;
        case 50:
            DecisionValid = 2;
            break;
        }
        switch (DecisionValid)
        {
        case 1:
            system("cls");
            goto MenuPrincipal;
        case 2:
            system("cls");
            PantallaSalida();
            exit(EXIT_SUCCESS);
                    
        default:
            printf("\n\n\t\t\t\t\t      (!)Opcion incorrecta.");
            printf("\n\t\t\t\t\t  -> Digite una opcion valida.");
            sleep(1);
            goto Decision;
        }
    }
    else
    {
        printf("\n\n\t\t\t\t\t      (!)Opcion incorrecta.");
        printf("\n\t\t\t\t\t  -> Digite una opcion valida.");
        sleep(1);
        goto Decision;  
    }  

}

void Presentacion()
{
    system("color 1f");
    printf("\n\t\t\t\t        Universidad Nacional De Ingenieria\n");
    printf("\n\t\t\t\t     &&&&&&  &&&&&&&&&&&&&&&&&&&&&&&  &&&&&&\n");
    printf("\t\t\t\t     &&&&&&  &&&&&&&&&&&&&&&&&&&&&&&  &&&&&&\n");
    printf("\t\t\t\t     &&&&&&  &&&&&&#         #&&&&&&        \n");
    printf("\t\t\t\t     &&&&&&  &&&&&&# &&&&&&& #&&&&&&  &&&&&&\n");
    printf("\t\t\t\t     &&&&&&  &&&&&&# &&&&&&& #&&&&&&  &&&&&&\n");
    printf("\t\t\t\t     &&&&&&  &&&&&&# &&&&&&& #&&&&&&  &&&&&&\n");
    printf("\t\t\t\t     &&&&&&          &&&&&&& #&&&&&&  &&&&&&\n");
    printf("\t\t\t\t     &&&&&&&&&&&&&&&&&&&&&&& #&&&&&&&&&&&&&&\n");
    printf("\t\t\t\t     &&&&&&&&&&&&&&&&&&&&&&& #&&&&&&&&&&&&&&\n");
    printf("\n\t\t\t\t\t       -C A J E R O  A T M-\n");
    printf("\n\t\t\t      Proyecto de Introduccion a la Ingenieria en Computacion\n");
    printf("\n\t\t\t\t           Docente: Ing. Nelson Barrios\n");
    printf("\n\t\t\t\t     Presentado por: Jose Luis Lovo Rodriguez\n");
    printf("\n\t\t\t\t\t       Carnet: 2021-0103U\n");
    printf("\n\t\t\t\t\t        Grupo: 1M1 - CO");
    getch();

}

void Inicio()
{
    FILE * archivo;
    system("color a");
    archivo = fopen( "inicio.txt", "r");
    FILE * ASCII;
    ASCII = fopen("inicio.txt", "r");
    char abrir;
    while (feof(ASCII)==0)
    {
        abrir = fgetc(ASCII);
        printf("%c",abrir);
        fflush(stdout);
    }
    getch();
}

void Credenciales()
{
    char name[5];
    char validador[5] = "admin";
    char pass[5];
    char validador2[4] = "1234";
    bool valid = false;  
    bool validUser = false;
    bool validPass = false;
    int cantidad, cantidad2;
    do
    {  
        cantidad = 0;
        cantidad2 = 0;
        system("cls");
        fflush(stdin);
        system("color a");
        printf("\t\t\t\t\t_________________________________\n");
        printf("\n\t\t\t\t\t*\t   CREDENCIALES   \t*\n");
        printf("\t\t\t\t\t_________________________________\n");
        printf("\n\t\t\t\t\t    Ingrese sus credenciales\n");
        printf("\n\t\t\t\t\t     Intentos permitidos: %i", contador);
        printf("\n\n\t\t Usuario: ");
            switch (getch())
            {
             case ENTER:
                 goto intento;
             case ESPACIO:
                 goto intento;
             default:
                 scanf("%s", &name);
             break;
            }
        cantidad = strlen(name);
        if(cantidad > 5)
        {
            printf("\n\t\t\t\t(!) El usuario es incorrecto.\n");
            getch();
            goto intento;
        }
        printf("\n\t\t Ingrese la clave: ");
            switch (getch())
            {
             case ENTER:
                 goto intento;
             case ESPACIO:
                 goto intento;
             default:
                 scanf("%s", &pass);
             break;
            }
        cantidad2 = strlen(pass);
        if(cantidad2 > 4)
        {
            printf("\n\t\t\t\t(!) La clave es incorrecta.\n");
            getch();
            goto intento;
            
        }else
        {  
            for (int i = 0; i < 5; i++)
        {
            char x = validador[i];
            char y = name[i];
            if (x != y)
            {
                validUser = false;
            }
            else
            {
                if (i == 4)
                    validUser = true;
            }
        }

            for (int j = 0; j < 4; j++)
        {
            int a = validador2[j];
            int b = pass[j];
            if (a != b)
            {
                validPass = false;
            }
            else
            {
                if (j == 3)
                    validPass = true;
            }
        }
            if (validUser != true || validPass != true)
            {   
                if(validUser == false)
                {
                    printf("\n\t\t(!) El usuario es incorrecto.\n");
                    getch();
                }
                if(validPass == false)
                {
                    printf("\n\t\t(!) La clave es incorrecta.\n");
                    getch();
                }
                    intento:
                    contador--;
                if (contador == 0)
                {
                    printf("\n\n\t\t\t\t(!)Fallaste: Credenciales incorrectas.");
                    printf("\n\t\t\t\t\t(!)Bloqueando acceso.");
                    getch();
                    system("cls");
                    PantallaSalida();
                    exit(EXIT_SUCCESS);
                }
                system("cls");
            }else
            {
                if (validUser == true && validPass == true)
                {
                    valid = true;
                    system("cls");
                }
            }
        }
    } while (valid != true); 
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Verificando credenciales");
    sleep(0.99);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Verificando credenciales .");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Verificando credenciales . .");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Verificando credenciales . . .");
    sleep(1);
    system("cls");  
}

void Cargando()
{ 
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [||                                   ]");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [||||||                               ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||                            ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [||||||||||||                         ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||||||||                      ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [||||||||||||||||||                   ]");
    sleep(0.9);
    system("cls"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||||||||||||||                ]");
    sleep(1);
    system("cls"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [||||||||||||||||||||||||             ]");
    sleep(0.9);
    system("cls"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||||||||||||||||||||          ]");
    sleep(0.9);
    system("cls"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [||||||||||||||||||||||||||||||       ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||||||||||||||||||||||||||    ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||||||||||||||||||||||||||||| ]");
    sleep(0.9);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Cargando [|||||||||||||||||||||||||||||||||||||]");
    sleep(1);
    system("cls");
}

void FuncionIngresoATM()
{
    int deposito, Opc;
    int limite = 10000;

    system("cls");
    printf("\n\t\t\t\t\t\t* Ingreso de Saldo *\n");
    printf("\n\t\t\tIngrese la cantidad a depositar: C$ ");

    switch (getch())
    {
    case ENTER:
        printf("\n\n\t\t\t\t(!)El campo se encuentra vacio.\n");
        printf("\t\t\t->  Presiona cualquier tecla para volver al menu!");
        getch();
        goto Fin;
    case ESPACIO:
        printf("\n\n\t\t\t(!)Tecla invalida.\n");
        printf("\t\t\t->  Presiona cualquier tecla para volver al menu!");
        getch();
        goto Fin;
    default:
        scanf("%i", &deposito);
        break;
    }

    if (deposito > limite || saldo > limite)
    {
        printf("\n\t\t\t(!) El deposito sobrepasa el limite de saldo.\n");
        printf("\n\t\t\t\t-> Presiona cualquier tecla para volver a intentarlo!");
        getch();
        goto Fin;
    }
    if (deposito <= 0)
    {
        Error1:
        printf("\n\t\t\t(!) El deposito no puede ser menor o igual que cero.\n");
        printf("\t\t\t\t-> Presiona cualquier tecla para volver a intentarlo!");
        getch();
        goto Fin;
    }
    if(saldo + deposito > limite)
    {
        printf("\n\t\t\t(!) Su transaccion sobrepasa el limite de saldo.\n");
        printf("\t\t\t\t-> Presiona cualquier tecla para volver a intentarlo!");
        getch();
        goto Fin;
    }else
    {
        saldo = saldo + deposito;
        printf("\n\t\t\t\t   -> El deposito se llevo acabo con exito.\n");
        printf("\t\t\t\t\t   -> Tu saldo actual es: C$ %i.", saldo);
        getch();
        Fin:
        sleep(0.1);
    }
}

void FuncionRetiroATM()
{
    int retiro;

    printf("\n\t\t\t\t\t\t* Retirar saldo *\n");
    printf("\n\t\t\tingrese la cantidad a retirar: C$ ");
    
    switch (getch())
    {
    case ENTER:
        printf("\n\n\t\t\t\t(!)El campo se encuentra vacio.\n");
        printf("\t\t\t->  Presiona cualquier tecla para volver al menu!");
        getch();
        goto Fin;
    case ESPACIO:
        printf("\n\n\t\t\t\t(!)Tecla invalida.\n");
        printf("\t\t\t->  Presiona cualquier tecla para volver al menu!");
        getch();
        goto Fin;
    default:
        scanf("%i", &retiro);
        break;
    }

    if (retiro > saldo)
    {
        printf("\n\t\t\t(!) El retiro sobrepasa a su saldo disponible.\n");
        printf("\n\t\t\t\t-> Presione cualquier tecla para volver a intentarlo!");
        getch();
        goto Fin;
    }
    if (retiro <= 0)
    {
        printf("\n\t\t\t(!) El retiro no puede ser menor o igual a cero.\n");
        printf("\n\t\t\t\t-> Presione cualquier tecla para volver a intentarlo!");
        getch();
        goto Fin;
    }
    else
    {
        saldo = saldo - retiro;
        printf("\n\t\t\t\t   -> La transaccion se llevo acabo con exito.");
        printf("\n\t\t\t\t\t   ->Tu saldo actual es: C$ %i.", saldo);
        getch();
        Fin:
        sleep(0.1);
    }
}

void FuncionRecarga()
{
    int numero, copia[8], prefijo, copianum, recarga;
    int limiterecarga = 100;
    int i = 0;

    printf("\n\t\t\t\t* Recarga Electronica *\n");
    printf("\n\t\tIngrese su numero telefonico: ");

    switch (getch())
    {
    case ENTER:
        printf("\n\n\t\t\t\t(!)El campo se encuentra vacio.\n");
        printf("\t\t\t->  Presiona cualquier tecla para volver al menu!");
        getch();
        goto Fin;
    case ESPACIO:
        printf("\n\n\t\t\t\t(!)Tecla invalida.\n");
        printf("\t\t\t->  Presiona cualquier tecla para volver al menu!");
        getch();
        goto Fin;
    default:
        scanf("%i", &numero);
        break;
    }
    copianum = numero;

    do
    {
        copia[i] = numero % 10;
        numero /= 10;
        i++;

    } while (numero != 0);
    
    prefijo = copia[7] * 1000 + copia[6] * 100 + copia[5] * 10 + copia[4];

    char *funcion = VerificacionPrefijos(prefijo);

    if (strcmp(funcion, "(!)") == 0)
    {
        printf("\n\t\t\t\t(!)Numero invalido");
        printf("\n\t\t\t->  Presione cualquier tecla para volver a intentarlo!");
        getch();
        system("cls");
        goto Fin;
    
    }
    else
    {
        printf("\n\t\tCantidad a recargar: C$ ");
        scanf("%i", &recarga);

        if(recarga > saldo) 
        {
            printf("\n\t\t\t\t(!)La recarga sobrepasa a su saldo disponible.");
            printf("\n\t\t\t-> Le recomendamos depositar saldo para intentarlo nuevamente!");
            getch();
            goto Fin;
        }

        if(recarga > limiterecarga)
        {
            printf("\n\t\t\t\t(!)Sobrepasa el limite de transaccion.");
            printf("\n\t\t\t-> Presione cualquier tecla para volver a intentarlo!");
            getch();
            goto Fin;
        }

        if(recarga <= 0)
        {
            printf("\n\t\t\t\t(!)La recarga no puede ser menor o igual a cero.");
            printf("\n\t\t\t-> Presione cualquier tecla para volver a intentarlo!");
            getch();
            goto Fin;

        }else
            saldo = saldo - recarga;
            printf("\n\t\t\tDetector de Telefonia: %s\n", funcion);
            printf("\n\t\t\tTu recarga ha sido aplicada al numero: %i.", copianum);
            getch();
        }
    Fin:
    sleep(0.1);
}

char *VerificacionPrefijos(int prefijoNumero)
{   
    for (int i = 0; i < claroLongi; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if ((prefijoNumero >= arregloClaro[i][j]) && (prefijoNumero <= arregloClaro[i][j + 1]))
                return "Claro";
        }
    }
    for (int i = 0; i < tigoLongi; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if ((prefijoNumero >= arregloTigo[i][j]) && (prefijoNumero <= arregloTigo[i][j + 1]))
                return "Tigo";            
        }
    }
    
    return "(!)";
}

void PantallaSalida()
{
    printf("\t\t\t\t\t ________________________________\n");
    printf("\n\t\t\t\t\t |\t  G R A C I A S\t\t|\n");
    printf("\n\t\t\t\t\t |\t   P O R   S U\t\t|\n");
    printf("\n\t\t\t\t\t |     P R E F E R E N C I A\t|\n");
    printf("\t\t\t\t\t ________________________________\n");

    FILE * archivo;
    system("color a");
    archivo = fopen( "Salida.txt", "r");
    FILE * ASCII;
    ASCII = fopen("Salida.txt", "r");
    char abrir;
    while (feof(ASCII)==0)
    {
        abrir = fgetc(ASCII);
        printf("%c",abrir);
        fflush(stdout);
    }
    getch();
}