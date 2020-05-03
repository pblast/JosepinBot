/***************************************************************************//**
 *   @file   main.c
 *   @brief  Archivo principal del proyecto JosepinBot que se encargar de
 *           controlar el bot de Telegram Josepin
 *   @author PBL
*******************************************************************************/

/******************************************************************************/
/*                                  INCLUDES                                  */
/******************************************************************************/
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <curl/curl.h>

//#include <myglobal.h>
#include <mysql/mysql.h>

#include "main.h"
#include "lang.h"
#include "botTelegram.h"
#include "daemon.h"
#include "config.h"
#include "database.h"

/******************************************************************************/
/*                                  VARIABLES                                 */
/******************************************************************************/

bot TelBot; /* SE crea la estrcutra para controlar al robot1 */
bot JosBot; /* Se crea la estrucuta para ocntrola al robot2 */
dbParam dbConnection; /* Se crea la estructura para almacenar los
												 datos de la conexió con la base de datos */
/******************************************************************************/
/*                               FUNCIONES                                    */
/******************************************************************************/

int main (int argc, char const *argv[]) {
	MYSQL *con=mysql_init(NULL);
	int status=0;

	/* Si se está en modo depuración no se lanzará el demonio, si no que se
    mostrará por pantalla el contenido de log */
    #ifndef _DEBUG_
        if(startDaemon()){
            return 1;
        }
    #else
        system ("clear");
        fprintf (stdout, "******************* %s *******************\n", INTROTERM);
    #endif


    CargaConfig("TVB.cfg");

	/* Tratamos de conectarnos a la base de datos */
	status=ConnectDatabase(con);

	fprintf("Status:%i\n",status);

    sendMSG(TelBot.adminId,"Acabo de despertar");

    /* En el bucle principal se consulta constantemente el estado del servidor
    para ver si se recibe un nuevo mensaje */
    while (1) {
        getMSG (1);

				/* TODO: hay que coger este mensaje y ver que se hace con él */
        printf("%s\n", s.ptr);
        free (s.ptr);
        sleep (5);
    }


    return 0;
}



/******************************* End of file***********************************/
