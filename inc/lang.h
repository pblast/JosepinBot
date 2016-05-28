/***************************************************************************//**
 *   @file   lang.h
 *   @brief  Este archivo añade soporte al multilenguage. En el se recogen todas
 *           las cadenas que se mostrarán tanto por pantalla como por el bot en
 *           función del lenguaje seleccionado.
 *   @author PBL
*******************************************************************************/

#ifndef LANG_H
#define LANG_H

#ifdef _LANG_AS
    #define INTROTERM "PROGRAMA DE XOSEPIN"
    #define ERRCONEXTERM " Nun se pue conectar con Xosepín\n"
    #define OKCONEXTERM "Pudo crease la coexión con Xosepín\n"
#elif _LANG_ES
    #define INTROTERM "PROGRAMA DE JOSEPIN"
    #define ERRCONEXTERM "No se puede conectar con Josepín\n"
    #define OKCONEXTERM "Se ha podido establecer la conexión con Josepin\n"
#endif


/******************************************************************************/
/*                                  DEFINES                                   */
/******************************************************************************/


/******************************************************************************/
/*                                  PROTOTIPOS                                */
/******************************************************************************/

#endif
/******************************* End of file***********************************/
