/***************************************************************************//**
 *   @file   database.c
 *   @brief  Archivo que recoge funciones simplificadas para el manejo de una
 *           base de datos SQL
 *   @author PBL
*******************************************************************************/



/******************************************************************************/
/*                                  INCLUDES                                  */
/******************************************************************************/
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

#include "database.h"


/******************************************************************************/
/*                               FUNCIONES                                    */
/******************************************************************************/
int ConnectDatabase(MYSQL* connection){
	// Se crea la conexión
	connection = mysql_init(NULL);

	/* Si no se ha podido crear el handler para la conexion se
		 indica el error y se sale devolviendo un 1 */
  if (connection == NULL) {
      fprintf(stderr, "%s\n", mysql_error(connection));
      return 1;
  }

	/* Una vez creado el handler se abre la conexión con los datos
		 definidos mediante los defines. Si falla se devuelve mensaje
		 de error y se sale devolviendo 1*/
  if (mysql_real_connect(connection, SERVER_ADDRESS, SERVER_USER, USER_PWD,
          NULL, 0, NULL, 0) == NULL){
      fprintf(stderr, "%s\n", mysql_error(connection));
      mysql_close(connection);
      return 1;
  }

	printf("ha ido todo bien\n");
	return 0;

}
/******************************* End of file***********************************/
