#include "Respuesta.h"
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    cout << "Soy servidor" << endl;

    struct mensaje * msj;
    char message[20];
    int a = 0, b = 0;

	Respuesta respuesta = Respuesta(7200);

  while(1)
  {
     msj = respuesta.getRequest();
     // Obtiene números de la cadena:
     sscanf(msj->arguments, "%d %d", &a, &b);

     // Construye una cadena con el resultado de la operación:

     switch (msj->operationId)
     {
     		case suma:
     			sprintf(message, "%d + %d = %d", a, b, a+b);
     			break;
 			  default:
 				  strcpy(message, "operación no soportada\n");
     			break;
     }

     respuesta.sendReply(message);
  }
    
	return 0;
}
