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
 *          File:  Components/Rte_Ap_SrlComOutput.h
 *     Workspace:  C:/synergy_projects_working/PSA3.5.1/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

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
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ANGLECOLONNE_Cnt_u16 (0U)
#  define Rte_InitValue_APAState_Cnt_u08 (0U)
#  define Rte_InitValue_APAStateTransitionCause_Cnt_u08 (0U)
#  define Rte_InitValue_AUTORARRETMOTDA_Cnt_u08 (0U)
#  define Rte_InitValue_AVASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_CAUSEDESACTIVCPK_Cnt_u08 (0U)
#  define Rte_InitValue_CODEDEFAUT_Cnt_u08 (0U)
#  define Rte_InitValue_CPLEVOLANT_Cnt_u08 (0U)
#  define Rte_InitValue_CPLEVOLANTOPTMSE_Cnt_u08 (0U)
#  define Rte_InitValue_CTCFailed_Cnt_lgc (FALSE)
#  define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_DDEREDEMDA_Cnt_u08 (0U)
#  define Rte_InitValue_DefaultHwaSCommExportValue_Cnt_lgc (FALSE)
#  define Rte_InitValue_ETATASSISTDA_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDA2004_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDA2010_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDADYN_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDAECPK_Cnt_u08 (0U)
#  define Rte_InitValue_ETATLIGNEAPC_Cnt_u08 (0U)
#  define Rte_InitValue_ETATSECUANGLECOL_Cnt_u08 (0U)
#  define Rte_InitValue_EtatMT_Cnt_u08 (0U)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_ISDYNDAEFirstMessageSent_Cnt_lgc (FALSE)
#  define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
#  define Rte_InitValue_RampDwnStatusComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_RelHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_STATUSCONFABSENT_Cnt_u32 (0U)
#  define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComHwTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_VITESSECOLONNE_Cnt_u16 (0U)
#  define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
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

extern VAR(Rte_tsTask_10ms_10a, RTE_VAR_NOINIT) Rte_Task_10ms_10a;

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

#  define Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_u08() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_APAStateTransitionCause_Cnt_u08.value)

#  define Rte_IRead_SrlComOutput_Per1_APAState_Cnt_u08() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_APAState_Cnt_u08.value)

#  define Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AVASelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CTCFailed_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CityParkSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_DefaultHwaSCommExportValue_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_EtatMT_Cnt_u08.value)

#  define Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_HandwheelTorque_HwNm_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ISDYNDAEFirstMessageSent_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_OutputRampMult_Uls_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_RampDwnStatusComplete_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_RelHwPos_HwDeg_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_RelHwPos_HwDeg_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_STTdSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_SrlComHwTrq_HwNm_f32.value)

#  define Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ValidEngineStatus_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ANGLECOLONNE_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ANGLECOLONNE_Cnt_u16.value)

#  define Rte_IWrite_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AUTORARRETMOTDA_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_AUTORARRETMOTDA_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CAUSEDESACTIVCPK_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CAUSEDESACTIVCPK_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CODEDEFAUT_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CODEDEFAUT_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CPLEVOLANTOPTMSE_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CPLEVOLANTOPTMSE_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CPLEVOLANT_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_CPLEVOLANT_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_DDEREDEMDA_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_DDEREDEMDA_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATASSISTDA_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATASSISTDA_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATDA2004_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDA2004_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATDA2004_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDA2004_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATDA2010_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDA2010_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATDA2010_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDA2010_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATDADYN_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDADYN_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATDADYN_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDADYN_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDAECPK_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATDAECPK_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATDAECPK_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATLIGNEAPC_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATLIGNEAPC_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATSECUANGLECOL_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_ETATSECUANGLECOL_Cnt_u08.value)

#  define Rte_IWrite_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_STATUSCONFABSENT_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_STATUSCONFABSENT_Cnt_u32.value)

#  define Rte_IWrite_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_VITESSECOLONNE_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16() \
  (&Rte_Task_10ms_10a.Rte_RB.Rte_Ap_SrlComOutput_SrlComOutput_Per1.Rte_VITESSECOLONNE_Cnt_u16.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsEn_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_GetIndicatorStatus(UInt8 parg0, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_DEM_APPL_VAR) IndicatorStatus);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_IndStatusETATDA2_GetIndicatorStatus(arg1) (Dem_GetIndicatorStatus((UInt8)0, arg1))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
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


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EpsEn_E_NOT_OK (1U)

#  define RTE_E_IndicatorStatus_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_SRLCOMOUTPUT_H */
