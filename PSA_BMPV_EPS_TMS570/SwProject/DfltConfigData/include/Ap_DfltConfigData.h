/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DfltConfigData.h
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/* Version Control:
* %version:          5 %
* %derived_by:       nzx5jd %
*---------------------------------------------------------------------------------------------------------------------
* Date       Rev     Author   Change Description                                                                SCR #
* --------   ------  -------  -------------------------------------------------------------------------------  -------
* 03/07/14    1      OT       Initial Version
* 10/08/14    2      OT       Added init block for new customer services                                        12363
* 10/23/14    3      OT       Added initialization constants for NvM safety update                              12252
* 10/31/14    4      OT       Added deprecated blocks for NvM safety update correction                          12654
* 01/15/15    5      OT       Added deprecated block for CTC storage size correction                            12907
* 10/26/16    5      WH       Added external linkage for block headers (QAC)                                    EA3#11902
*/


#ifndef RTE_AP_DFLTCONFIGDATA_H
#define RTE_AP_DFLTCONFIGDATA_H


#include "Std_Types.h"
#include "Rte_Type.h"
#include "DiagSvc.h"


extern CONST(PhaseCurrCal_DataType, AP_DFLTCONFIGDATA_CONST) T_ShCurrCalInit_Cnt_str;
extern CONST(uint16,                AP_DFLTCONFIGDATA_CONST) T_CogTrqCalInit_Cnt_u16[512];
extern CONST(uint16,                AP_DFLTCONFIGDATA_CONST) T_CogTrqRplCompInit_Cnt_u16[9];
extern CONST(float32,               AP_DFLTCONFIGDATA_CONST) T_TorqueCmdSFInit_Uls_f32;
extern CONST(EOTLearned_DataType,   AP_DFLTCONFIGDATA_CONST) T_LearnedEOTInit_Cnt_str;
extern CONST(AvgFricLrnType,        AP_DFLTCONFIGDATA_CONST) T_AvgFricLrnDataInit_Cnt_str;


extern CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[50];

extern CONST(ECUManufacturingDateType_Str, DIAGSVC_CONST) D_MANUFDATEINIT_CNT_STR;


extern VAR(uint8, NVM_APPL_DATA) Deprecated_CmMtrCurr_CurrTempOffset[98u];
extern VAR(uint8, NVM_APPL_DATA) Deprecated_AbsHwPos_EOLVehCntrOffset[10u];
extern VAR(uint8, NVM_APPL_DATA) Deprecated_Dem_NvData[60u];

extern CONST(uint16, CDD_PARTNUMBER) T_CalBlockHeader_Cnt_u16[1u];
extern CONST(uint16, CDD_PARTNUMBER) T_AppBlockHeader_Cnt_u16[2u];
extern CONST(uint8, CDD_PARTNUMBER) T_EcuStatus_Cnt_u08[16u];


extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void);


#endif /* RTE_AP_DFLTCONFIGDATA_H */
