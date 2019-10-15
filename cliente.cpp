#include "Solicitud.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
    	cout << "Debe ingresar: ./main_c <puerto> <IP> <num solicitudes>" << endl;
    	return -1;
    }

    int puertoRemoto = atoi(argv[1]), n = atoi(argv[3]);
    char ipRemota[50];
    strcpy(ipRemota, argv[2]);
    const char * cargs = "99 1";
    
    Solicitud solicitud = Solicitud();
    cout << "Se harán " << n << " solicitudes." << endl;
    for (int i = 0; i < n; ++i)
    {
        char * respuesta = solicitud.doOperation(ipRemota, puertoRemoto, suma, cargs);

        if (strlen(respuesta) > 0)
        {
            cout << "Respuesta del servidor: " << respuesta << endl;
        }
        else
        {
            cout << "No se obtuvo respuesta." << endl;   
        }
        
    }

	return 0;
}
