#include "Solicitud.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
    	cout << "Debe ingresar: ./main_c <int 1> <int 2>" << endl;
    	return -1;
    }

    int puertoRemoto;
    char ipRemota[50];
    string args;
    args += argv[1];
    args += " ";
    args += argv[2];
    const char * cargs = args.c_str();

	cout << "Soy cliente" << endl;
    cout << "Ingrese puerto remoto: ";
    cin >> puertoRemoto;
    cout << "Ingrese ip del servidor: ";
    cin >> ipRemota;
    cin.ignore();

    
    Solicitud solicitud = Solicitud();

    char * respuesta = solicitud.doOperation(ipRemota, puertoRemoto, suma, cargs);

    if (strlen(respuesta) > 0)
    {
        cout << "Respuesta del servidor: " << respuesta << endl;
    }
    else
    {
        cout << "No se obtuvo respuesta." << endl;   
    }


	return 0;
}
