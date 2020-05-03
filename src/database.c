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
#include "main.h"

/******************************************************************************/
/*                               FUNCIONES                                    */
/******************************************************************************/

/**
 * Función para conectarse a una base de datos. Se llama a una serie
 * de funciones de la libreria libmysql-client en las que se abre
 * la conexión y se estavlece el canal de comunicación con la base
 * de datos
 * @param  Se pasa una estructura con la IP, el usuario y el pass
 *         que se utilizará para hacer la conexión
 * @return  Devuelve un 0 si todo ha ido bien y un entero positivo en caso
 *          contrario.
 */

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
  if (mysql_real_connect(connection, dbConnection.ipaddr,dbConnection.usr, dbConnection.pwd,
          NULL, 0, NULL, 0) == NULL){
      fprintf(stderr, "%s\n", mysql_error(connection));
      mysql_close(connection);
      return 1;
  }
#ifdef _DEBUG_
	printf("Conexión establecida con la base de datos\n");
#endif
	return 0;

}



/**
 * Función para obtener la versión del cliente de base de datos
 * SQL utilizado
 * @return  None
 */

void ClientVersion(void){
	/* Comprobamos la versión del cliente mysql que tenemos instalado */
	printf("MySQL client version: %s\n", mysql_get_client_info());
}

/******************************* End of file***********************************/
