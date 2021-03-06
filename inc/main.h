/***************************************************************************//**
 *   @file   main.h
 *   @brief  Archivo que contiene las definiciones principales para el proyecto
 *           JosepinBot que controla el bot de telegram Telvina
 *   @author PBL
*******************************************************************************/

#ifndef MAIN_H
#define MAIN_H


/******************************************************************************/
/*                                    DEFINES                                 */
/******************************************************************************/
    #define _DEBUG_
    #define _LANG_AS


/******************************************************************************/
/*                                ESTRUCTURAS                                 */
/******************************************************************************/
    struct bot{
        char token[50];
        long adminId;
        long users[2];
    };
    typedef struct bot bot;

struct dbParam{
	char ipaddr[15];
	char usr[10];
	char pwd[20];
};
typedef struct dbParam dbParam;

/******************************************************************************/
/*                            VARIABLES GLOBALES                              */
/******************************************************************************/

extern bot TelBot;
extern dbParam dbConnection;

/******************************************************************************/
/*                               PROTOTIPOS                                   */
/******************************************************************************/

    int getPid (void);
    void setRunnning(int pid);


#endif
/******************************* End of file***********************************/
