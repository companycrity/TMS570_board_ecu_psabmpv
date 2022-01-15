/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Lnk_Symbols.h
* Module Description: This file contains the declarations of Link Time Symbols
*                     used in the application.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * %version:          3 %
 * %derived_by:       nzx5jd %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  ------------------------------------------------------------------------------  -------
 * 03/07/14   1       OT        Initial version
 * 08/08/14   2       OT        Updates for new bootloader                                                       12250
 * 10/01/14   3       OT        Updates for new customer services                                                12363
 */

#ifndef LNK_SYMBOLS_H
#define LNK_SYMBOLS_H

#include "Std_Types.h"

extern VAR(uint8, AUTOMATIC) Lnk_PSABootSoftIDNumber_Addr[];
extern VAR(uint8, AUTOMATIC) Lnk_BootRelNum_Addr[];

extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_BSS_Start;
extern CONSTP2VAR(void, AUTOMATIC, AUTOMATIC) Lnk_BSS_End;

#endif

