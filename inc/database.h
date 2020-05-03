/***************************************************************************//**
 *   @file databse.h
 *   @brief Contiene los prototipos y definiciones necesarios para
 *          la conexión a una base de datos SQL. Así como para la
 *          lectura y escritura en esta
 *   @author PBL
*******************************************************************************/

#ifndef DATABASE_H
#define DATABASE_H

/******************************************************************************/
/*                                  DEFINES                                   */
/******************************************************************************/
#define SERVER_ADDRESS "192.168.1.200"
#define SERVER_USER "Telvina"
#define USER_PWD "pwdAdminDBHomeAss2020"

/******************************************************************************/
/*                                  PROTOTIPOS                                */
/******************************************************************************/
int ConnectDatabase(MYSQL* connection);



#endif
/******************************* End of file***********************************/
