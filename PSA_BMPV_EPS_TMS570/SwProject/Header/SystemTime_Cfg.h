/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : SystemTime_Cfg.h
* Module Description: Configuration file for Systemtime.c module
* Product           : Gen II Plus - EA3.0
* 
*****************************************************************************/
/* Version Control:
 * %version:          EA3#2 %
 * %derived_by:       nzx5jd %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/26/14   1       OT        Initial version
 * 08/13/15   2       OT        Changed to 1ms tick
 */

#ifndef SYSTEMTIME_CFG_H
#define SYSTEMTIME_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/


/* Configure the system tick time */
#define D_TickRate_Cnt_u32	 1000UL
   
#endif /* SYSTEMTIME_CFG_H */

/*** End of file **************************************************************/