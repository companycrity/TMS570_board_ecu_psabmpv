/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_SrlComInput.h
 *     Workspace:  C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Tue May 17 20:21:32 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComInput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_SrlComInput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_APAAuthn_Cnt_lgc (FALSE)
# define Rte_InitValue_APARequest_Cnt_lgc (FALSE)
# define Rte_InitValue_AngleVolant_HwDeg_f32 (0.0F)
# define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
# define Rte_InitValue_ApaRelaxReq_Cnt_lgc (FALSE)
# define Rte_InitValue_BSIDataMissing_Cnt_lgc (TRUE)
# define Rte_InitValue_Batt_Volt_f32 (0.0F)
# define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
# define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CMMDataMissing_Cnt_lgc (TRUE)
# define Rte_InitValue_CONSANGLECPK_Cnt_u16 (0U)
# define Rte_InitValue_CPKOK_Cnt_lgc (FALSE)
# define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
# define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
# define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
# define Rte_InitValue_DMDFCTCPK_Cnt_u08 (0U)
# define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
# define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
# define Rte_InitValue_DiagRmpToZeroActive_Cnt_lgc (FALSE)
# define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
# define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
# define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
# define Rte_InitValue_EngOn_Cnt_lgc (FALSE)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI3F2MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI3F2MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI412MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI412MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATBSI432MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDATBSI432MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDATDIRAMsgTxInProgress_Cnt_lgc (FALSE)
# define Rte_InitValue_ISDATDIRAMsgTxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYN2CMMMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYN2CMMMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNAASMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNAASMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNABRMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNABRMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNCMM208MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNCMM208MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNCMM388MsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNCMM388MsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_IgnTimeOff_Cnt_u32 (0U)
# define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
# define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_MarcheARBVM_Cnt_u08 (0U)
# define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
# define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
# define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
# define Rte_InitValue_ReverseGearEngaged_Cnt_lgc (FALSE)
# define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
# define Rte_InitValue_SerialComAngleValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
# define Rte_InitValue_VehTimeValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
# define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComInput_SystemState_Mode(void);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ElecInt_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ElecInt_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ShutdownTime_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_ShutdownTime_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStart(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStop(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CurrentTime);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_VHHTYPE_WriteBlock(P2CONST(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_VHHTYPE_WriteBlock(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_DATA) DstPtr);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_LXASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Init_STTdSelected_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ElectronicIntegration_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Init_ElectronicIntegration_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_AnneeEcoule_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_AnneeEcoule_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_Batt_Volt_f32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_Batt_Volt_f32->value)

# define Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_BusOff_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_CAVHCSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CAVHCSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CTermActive_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_CityParkSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CityParkSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_CompteurTemporelVehicule_Cnt_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CompteurTemporelVehicule_Cnt_u32->value)

# define Rte_IRead_SrlComInput_Per1_ComputerRazGCT_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ComputerRazGCT_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_DefaultVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DefaultVehSpd_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_DiagIntegraElec_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DiagIntegraElec_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_DiagMuxOn_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DiagMuxOn_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_DiagRmpToZeroActive_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DiagRmpToZeroActive_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_DmdDelestDA_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DmdDelestDA_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_EffacDefaultDiag_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_EffacDefaultDiag_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_EtatMT_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_EtatMT_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATBSI3F2MsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATBSI412MsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATBSI412MsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATBSI432MsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATBSI432MsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDATDIRAMsgTxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYN2CMMMsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYN2CMMMsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNAASMsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNAASMsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNAASMsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNAASMsgRxTime_MSec_u32->value)

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08() \
  (*&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNAASMsg_Cnt_u08->value)
# else
#  define Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNAASMsg_Cnt_u08->value)
# endif

# define Rte_IRead_SrlComInput_Per1_ISDYNABRMsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNABRMsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNABRMsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNABRMsgRxTime_MSec_u32->value)

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08() \
  (*&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNABRMsg_Cnt_u08->value)
# else
#  define Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNABRMsg_Cnt_u08->value)
# endif

# define Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNCMM208MsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNCMM208MsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNCMM388MsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNCMM388MsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgDLCError_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNVOLMsgDLCError_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNVOLMsgRxTime_MSec_u32->value)

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08() \
  (*&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08->value)
# else
#  define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08->value)
# endif

# define Rte_IRead_SrlComInput_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32->value)

# define Rte_IRead_SrlComInput_Per1_JourEcoule_Cnt_u16() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_JourEcoule_Cnt_u16->value)

# define Rte_IRead_SrlComInput_Per1_LXASelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_LXASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_MarcheARBVM_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_MarcheARBVM_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_ModeDiag_Cnt_u08() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ModeDiag_Cnt_u08->value)

# define Rte_IRead_SrlComInput_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_STTdSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_SecondeEcoulee_Cnt_u32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SecondeEcoulee_Cnt_u32->value)

# define Rte_IRead_SrlComInput_Per1_SrlComHwTrqValid_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SrlComHwTrqValid_Cnt_lgc->value)

# define Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IRead_SrlComInput_Per1_VitesseVehicleBV_Cnt_u16() \
  (Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VitesseVehicleBV_Cnt_u16->value)

# define Rte_IWrite_SrlComInput_Per1_APAAuthn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_APAAuthn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_APAAuthn_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_APAAuthn_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_APARequest_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_APARequest_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_APARequest_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_APARequest_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_AngleVolant_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_AngleVolant_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_AngleVolant_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_AngleVolant_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ApaRelaxReq_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ApaRelaxReq_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_BSIDataMissing_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_BSIDataMissing_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_BSIDataMissing_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CMMDataMissing_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_CMMDataMissing_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CMMDataMissing_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CONSANGLECPK_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_CONSANGLECPK_Cnt_u16() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CONSANGLECPK_Cnt_u16->value)

# define Rte_IWrite_SrlComInput_Per1_CPKOK_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CPKOK_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_CPKOK_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_CPKOK_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DMDFCTCPK_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_DMDFCTCPK_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_DMDFCTCPK_Cnt_u08->value)

# define Rte_IWrite_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ElectronicIntegration_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ElectronicIntegration_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_EngOn_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_EngOn_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_EngOn_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_EngOn_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_IgnTimeOff_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_IgnTimeOff_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_IgnTimeOff_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_IgnTimeOff_Cnt_u32->value)

# define Rte_IWrite_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32->value)

# define Rte_IWrite_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SerialComAngleValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SerialComAngleValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_SrlComVehSpd_Kph_f32(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SrlComVehSpd_Kph_f32->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_SrlComVehSpd_Kph_f32() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_SrlComVehSpd_Kph_f32->value)

# define Rte_IWrite_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ValidEngineStatus_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_ValidEngineStatus_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_VehTimeValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VehTimeValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_VehTimeValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VehTimeValid_Cnt_lgc->value)

# define Rte_IWrite_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SrlComInput->SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AnneeEcoule_Cnt_u08 Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08
# define Rte_Read_CompteurTemporelVehicule_Cnt_u32 Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32
# define Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32
# define Rte_Read_JourEcoule_Cnt_u16 Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16
# define Rte_Read_SecondeEcoulee_Cnt_u32 Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComInput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_ElecInt_WriteBlock Rte_Call_Ap_SrlComInput_ElecInt_WriteBlock
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_SrlComInput_EpsEn_OP_GET
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_ShutdownTime_WriteBlock Rte_Call_Ap_SrlComInput_ShutdownTime_WriteBlock
# define Rte_Call_SrlComDriver_SCom_ElecIntStart Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStart
# define Rte_Call_SrlComDriver_SCom_ElecIntStop Rte_Call_Ap_SrlComInput_SrlComDriver_SCom_ElecIntStop
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32
# define Rte_Call_VHHTYPE_WriteBlock Rte_Call_Ap_SrlComInput_VHHTYPE_WriteBlock


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_VVHTYPEData() (Rte_Inst_Ap_SrlComInput->Pim_VVHTYPEData)

# define Rte_Pim_ElecIntData() (Rte_Inst_Ap_SrlComInput->Pim_ElecIntData)

# define Rte_Pim_ShutdownTimeData() (Rte_Inst_Ap_SrlComInput->Pim_ShutdownTimeData)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt8 *Rte_Pim_VVHTYPEData(void)
 *   Boolean *Rte_Pim_ElecIntData(void)
 *   ShutdownTimeType *Rte_Pim_ShutdownTimeData(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_SrlComInput_Per1_AnneeEcoule_Cnt_u08(void)
 *   Float Rte_IRead_SrlComInput_Per1_Batt_Volt_f32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CityParkSelected_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_CompteurTemporelVehicule_Cnt_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ComputerRazGCT_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_DefaultVehSpd_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_DiagIntegraElec_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_DiagMuxOn_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_DiagRmpToZeroActive_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_DmdDelestDA_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_EffacDefaultDiag_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_EtatMT_Cnt_u08(void)
 *   Float Rte_IRead_SrlComInput_Per1_HandwheelAuthority_Uls_f32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgRxTime_MSec_u32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNAASMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNAASMsgRxTime_MSec_u32(void)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08(void)
# else
 *   CanMsgType *Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08(void)
# endif
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNABRMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNABRMsgRxTime_MSec_u32(void)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08(void)
# else
 *   CanMsgType *Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08(void)
# endif
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgRxTime_MSec_u32(void)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08(void)
# else
 *   CanMsgType *Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08(void)
# endif
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(void)
 *   UInt16 Rte_IRead_SrlComInput_Per1_JourEcoule_Cnt_u16(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_LXASelected_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_MarcheARBVM_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ModeDiag_Cnt_u08(void)
 *   Float Rte_IRead_SrlComInput_Per1_OutputRampMult_Uls_f32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_STTdSelected_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_SecondeEcoulee_Cnt_u32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_SrlComHwTrqValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32(void)
 *   UInt16 Rte_IRead_SrlComInput_Per1_VitesseVehicleBV_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Per1_APAAuthn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_APAAuthn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_APARequest_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_APARequest_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_AngleVolant_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per1_AngleVolant_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(void)
 *   void Rte_IWrite_SrlComInput_Per1_CPKOK_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_CPKOK_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_EngOn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_EngOn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_IgnTimeOff_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Per1_IgnTimeOff_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_SrlComVehSpd_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per1_SrlComVehSpd_Kph_f32(void)
 *   void Rte_IWrite_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_VehTimeValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_VehTimeValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStart(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStop(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_GetNetworkDiagFltAcc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNetworkDiagFltAcc> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_GetNetworkDiagFltAcc(UInt16 *MuteFltAcc_Cnt_T_u16, UInt16 *CAVNodeFltAcc_Cnt_T_u16, UInt16 *CMMNodeFltAcc_Cnt_T_u16, UInt16 *ESPNodeFltAcc_Cnt_T_u16, UInt16 *AASNodeFltAcc_Cnt_T_u16, UInt16 *BSINodeFltAcc_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetNetworkDiagFltAcc(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) MuteFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CAVNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CMMNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ESPNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) AASNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) BSINodeFltAcc_Cnt_T_u16);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ResetTimers
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTimers> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ResetTimers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const UInt8 *DstPtr)
# else
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const NvM_DestPtr *DstPtr)
# endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1463527342
#    error "The magic number of the generated file <C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/SwProject/SrlComInput/utp/contract/Ap_SrlComInput/Rte_Ap_SrlComInput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1463527342
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
