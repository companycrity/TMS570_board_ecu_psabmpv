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
 *          File:  Components/Rte_Ap_SrlComInput.h
 *     Workspace:  C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComDriver_AnneeEcoule_Cnt_u08;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_CompteurTemporelVehicule_Cnt_u32;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComDriver_JourEcoule_Cnt_u16;
extern VAR(UInt32, RTE_VAR_INIT) Rte_SrlComDriver_SecondeEcoulee_Cnt_u32;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_APAAuthn_Cnt_lgc (FALSE)
#  define Rte_InitValue_APARequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_AngleVolant_HwDeg_f32 (0.0F)
#  define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
#  define Rte_InitValue_ApaRelaxReq_Cnt_lgc (FALSE)
#  define Rte_InitValue_BSIDataMissing_Cnt_lgc (TRUE)
#  define Rte_InitValue_Batt_Volt_f32 (0.0F)
#  define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
#  define Rte_InitValue_CAVHCSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CMMDataMissing_Cnt_lgc (TRUE)
#  define Rte_InitValue_CONSANGLECPK_Cnt_u16 (0U)
#  define Rte_InitValue_CPKOK_Cnt_lgc (FALSE)
#  define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
#  define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
#  define Rte_InitValue_DMDFCTCPK_Cnt_u08 (0U)
#  define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
#  define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
#  define Rte_InitValue_DiagRmpToZeroActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
#  define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
#  define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngOn_Cnt_lgc (FALSE)
#  define Rte_InitValue_EtatMT_Cnt_u08 (0U)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_ISDAT4V2BSI552MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDAT4V2BSI552MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI3F2MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI3F2MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI412MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI412MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATBSI432MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDATBSI432MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDATDIRAMsgTxInProgress_Cnt_lgc (FALSE)
#  define Rte_InitValue_ISDATDIRAMsgTxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYN2CMMMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYN2CMMMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNAASMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNAASMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNABRMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNABRMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNCMM208MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNCMM208MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNCMM388MsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNCMM388MsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_IgnTimeOff_Cnt_u32 (0U)
#  define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
#  define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_MarcheARBVM_Cnt_u08 (0U)
#  define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
#  define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
#  define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ReverseGearEngaged_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
#  define Rte_InitValue_SerialComAngleValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehTimeValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_10, RTE_VAR_NOINIT) Rte_Task_Init_10;

extern VAR(Rte_tsTask_10ms_10b, RTE_VAR_NOINIT) Rte_Task_10ms_10b;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_LXASelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc() \
  (Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_STTdSelected_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_ElectronicIntegration_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Init.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_AnneeEcoule_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_AnneeEcoule_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_Batt_Volt_f32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_Batt_Volt_f32.value)

#  define Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_BusOff_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_CAVHCSelected_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CAVHCSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CTermActive_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_CityParkSelected_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CityParkSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_CompteurTemporelVehicule_Cnt_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CompteurTemporelVehicule_Cnt_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ComputerRazGCT_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ComputerRazGCT_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_DefaultVehSpd_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DefaultVehSpd_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_DiagIntegraElec_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DiagIntegraElec_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_DiagMuxOn_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DiagMuxOn_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_DiagRmpToZeroActive_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DiagRmpToZeroActive_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_DmdDelestDA_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DmdDelestDA_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_EffacDefaultDiag_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_EffacDefaultDiag_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_EtatMT_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_EtatMT_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDAT4V2BSI552MsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDAT4V2BSI552MsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATBSI3F2MsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATBSI3F2MsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATBSI412MsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATBSI412MsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATBSI432MsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATBSI432MsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATDIRAMsgTxInProgress_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDATDIRAMsgTxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYN2CMMMsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYN2CMMMsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNAASMsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNAASMsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNAASMsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNAASMsgRxTime_MSec_u32.value)

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08() \
  (&((*RteIRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08())[0]))
#  else
#   define Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08() \
  RteIRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08()
#  endif
#  define RteIRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNAASMsg_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNABRMsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNABRMsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNABRMsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNABRMsgRxTime_MSec_u32.value)

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08() \
  (&((*RteIRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08())[0]))
#  else
#   define Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08() \
  RteIRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08()
#  endif
#  define RteIRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNABRMsg_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNCMM208MsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNCMM208MsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNCMM388MsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNCMM388MsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgDLCError_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNVOLMsgDLCError_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNVOLMsgRxTime_MSec_u32.value)

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08() \
  (&((*RteIRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08())[0]))
#  else
#   define Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08() \
  RteIRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08()
#  endif
#  define RteIRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISDYNVOLMsg_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ISINTEELECTRONBSIMsgRxTime_MSec_u32.value)

#  define Rte_IRead_SrlComInput_Per1_JourEcoule_Cnt_u16() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_JourEcoule_Cnt_u16.value)

#  define Rte_IRead_SrlComInput_Per1_LXASelected_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_LXASelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_MarcheARBVM_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_MarcheARBVM_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_ModeDiag_Cnt_u08() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ModeDiag_Cnt_u08.value)

#  define Rte_IRead_SrlComInput_Per1_OutputRampMult_Uls_f32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_OutputRampMult_Uls_f32.value)

#  define Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_STTdSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_SecondeEcoulee_Cnt_u32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SecondeEcoulee_Cnt_u32.value)

#  define Rte_IRead_SrlComInput_Per1_SrlComHwTrqValid_Cnt_lgc() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SrlComHwTrqValid_Cnt_lgc.value)

#  define Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IRead_SrlComInput_Per1_VitesseVehicleBV_Cnt_u16() \
  (Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VitesseVehicleBV_Cnt_u16.value)

#  define Rte_IWrite_SrlComInput_Per1_APAAuthn_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_APAAuthn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_APAAuthn_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_APAAuthn_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_APARequest_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_APARequest_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_APARequest_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_APARequest_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_AngleVolant_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_AngleVolant_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_AngleVolant_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_AngleVolant_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ApaRelaxReq_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ApaRelaxReq_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_BSIDataMissing_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_BSIDataMissing_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_BSIDataMissing_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CMMDataMissing_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_CMMDataMissing_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CMMDataMissing_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CONSANGLECPK_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_CONSANGLECPK_Cnt_u16() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CONSANGLECPK_Cnt_u16.value)

#  define Rte_IWrite_SrlComInput_Per1_CPKOK_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CPKOK_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_CPKOK_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_CPKOK_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DMDFCTCPK_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_DMDFCTCPK_Cnt_u08() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_DMDFCTCPK_Cnt_u08.value)

#  define Rte_IWrite_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ElectronicIntegration_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_EngOn_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_EngOn_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_EngOn_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_EngOn_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_IgnTimeOff_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_IgnTimeOff_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_IgnTimeOff_Cnt_u32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_IgnTimeOff_Cnt_u32.value)

#  define Rte_IWrite_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value)

#  define Rte_IWrite_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ReverseGearEngaged_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ReverseGearEngaged_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SerialComAngleValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SerialComAngleValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_SrlComVehSpd_Kph_f32(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SrlComVehSpd_Kph_f32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_SrlComVehSpd_Kph_f32() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_SrlComVehSpd_Kph_f32.value)

#  define Rte_IWrite_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ValidEngineStatus_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_ValidEngineStatus_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_VehTimeValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VehTimeValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_VehTimeValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VehTimeValid_Cnt_lgc.value)

#  define Rte_IWrite_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc() \
  (&Rte_Task_10ms_10b.Rte_RB.Rte_Ap_SrlComInput_SrlComInput_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AnneeEcoule_Cnt_u08 Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_AnneeEcoule_Cnt_u08(data) (*(data) = Rte_SrlComDriver_AnneeEcoule_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CompteurTemporelVehicule_Cnt_u32 Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32
#  define Rte_Read_Ap_SrlComInput_CompteurTemporelVehicule_Cnt_u32(data) (*(data) = Rte_SrlComDriver_CompteurTemporelVehicule_Cnt_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32 Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32
#  define Rte_Read_Ap_SrlComInput_ISDAT4V2BSI552MsgRxTime_MSec_u32(data) (*(data) = Rte_SrlComDriver_ISDAT4V2BSI552MsgRxTime_MSec_u32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_JourEcoule_Cnt_u16 Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16
#  define Rte_Read_Ap_SrlComInput_JourEcoule_Cnt_u16(data) (*(data) = Rte_SrlComDriver_JourEcoule_Cnt_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SecondeEcoulee_Cnt_u32 Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32
#  define Rte_Read_Ap_SrlComInput_SecondeEcoulee_Cnt_u32(data) (*(data) = Rte_SrlComDriver_SecondeEcoulee_Cnt_u32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ElecInt_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)20, arg1))
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsEn_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define Rte_Call_ShutdownTime_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)21, arg1))
#  define RTE_START_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStart(void);
#  define RTE_STOP_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SrlComDriver_SCom_ElecIntStart() (NtWrapC_SrlComDriver_SCom_ElecIntStart(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SrlComDriver_SCom_ElecIntStop(void);
#  define RTE_STOP_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SrlComDriver_SCom_ElecIntStop() (NtWrapC_SrlComDriver_SCom_ElecIntStop(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_VHHTYPE_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)19, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_VVHTYPEData;
extern VAR(Boolean, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_ElecIntData;
extern VAR(ShutdownTimeType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_SrlComInput_ShutdownTimeData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_VVHTYPEData() \
  (&Rte_SrlComInput_VVHTYPEData)

#  define Rte_Pim_ElecIntData() \
  (&Rte_SrlComInput_ElecIntData)

#  define Rte_Pim_ShutdownTimeData() \
  (&Rte_SrlComInput_ShutdownTimeData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetNetworkDiagFltAcc(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) MuteFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CAVNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CMMNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ESPNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) AASNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) BSINodeFltAcc_Cnt_T_u16);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EpsEn_E_NOT_OK (1U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_SRLCOMINPUT_H */
