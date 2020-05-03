/***************************************************************************//**
 *   @file   config.c
 *   @brief  Este archivo contiene las funciones necesarias para configurar el
 *           funcionamiento del bot. Tanto en su arranque como en la interacción
 *           con los usuarios. Esta configuración se basará en la carga de un
 *           fichero que definirá las caracteristicas del bot. En el se
 *           contendrá el TOKEN, el ID del usuario administrador y de los demas
 *           usuarios que tienene permiso de uso del bot, así como sus
 *           preferencias de uso.
 *   @author PBL
*******************************************************************************/

/******************************************************************************/
/*                                  INCLUDES                                  */
/******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

#include "config.h"
#include "botTelegram.h"
#include "main.h"

/******************************************************************************/
/*                                  FUNCIONES                                 */
/******************************************************************************/

/**
 * Función para leer los datos guardados en el archivo de configuración del
 * bot y poder así inicializar el bot. Los datos que se leeen son el token,
 * el id del administrador y los ids de los usuarios con acceso. Estos
 * parámetros se guardan en una estructura
 * @return  Devuelve un 0 si todo ha ido bien y un entero positivo en caso
 *          contrario.
 */
    int CargaConfig(const char* archivo){
        FILE *configFile;
        char linea[50];

        /* TODO: Se debe acabar la carga de los parámetros de configuración.
        Faltaría la lista de usuarios permitidos */
        configFile=fopen(archivo,"r");

        if(configFile==NULL)
            return 1;

        while(fscanf(configFile,"%s",linea)!=EOF){
					/* Se cargan los datos referentes al bot */
					if(!strcmp(linea,"[TOKEN]")){
                fscanf(configFile,"%s",linea);
                memcpy(TelBot.token,linea,strlen(linea));

                fprintf(stdout, "TOKEN: %s\n", TelBot.token);
            }
            if(!strcmp(linea,"[ADMIN_ID]")){
                fscanf(configFile,"%s",linea);
                TelBot.adminId=atol(linea);

                fprintf(stdout, "ADMIN_ID: %ld\n", TelBot.adminId);
            }

						/* Se cargan los datos de la conexión con la base
							 de datos */
						if(!strcmp(linea,"[DB]")){
							printf ("************ DATOS DE DB ************\n");
							fscanf(configFile,"%s",linea);
							memcpy(dbConnection.ipaddr,linea,strlen(linea));

							fscanf(configFile,"%s",linea);
							memcpy(dbConnection.usr,linea,strlen(linea));

							fscanf(configFile,"%s",linea);
							memcpy(dbConnection.pwd,linea,strlen(linea));

#ifdef _DEBUG_
							fprintf(stdout,"IP: %s\n",dbConnection.ipaddr);
							fprintf(stdout,"User: %s\n",dbConnection.usr);
							fprintf(stdout,"Pass: %s\n",dbConnection.pwd);
#endif
            }

        }

        fprintf(stdout, "Se ha leido todo el archivo\n");

        return 0;
    }



/**
 * Función para inicializar un bot. Se parte de los datos almacenados
 * en una base de datos SQL y a partir de ella se cargan los distintos
 * parámetros del robot.
 * Los parámetros que se deben cargar son el token,el usuario
 * administraodr y puede que una lista de usuarios a los que el bot
 * contestará ignorando al resto
 *
 * @param SQLServerAddr Corresponde a la dirección IP donde se
 *        encuentra alojado el servidor de la base de datos SQL
 * @param strNombreBot Corrseponde al nombre del bot que se debe tener
 *        almacenado en la base de datos para inicializar
 *
 * @return Devuelve 1 valor 0 si todo ha ido bien y un entero positivo
 *         en caso de eror
 */
int initBot(char* strSQLServerAdrr,char* strNombreBot,bot* robot){
	// Se hace llamada a alguna función para leer de la base de datos

	// Se accede ala base de datos de bots (con un define)

	// Se carga en la estructura bot los datos correspondientes al bot

	// Si se ha llegado hasta aqui se sale devolviendo un 0 porque todo
	// ha ido correcto
	return 0;
}

/******************************* End of file***********************************/
