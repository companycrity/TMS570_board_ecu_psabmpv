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
 *          File:  Components/Rte_Ap_PSASH.h
 *     Workspace:  C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PSASH_H
# define _RTE_AP_PSASH_H

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

#  define Rte_InitValue_APAState_Cnt_u08 (0U)
#  define Rte_InitValue_APAStateTransitionCause_Cnt_u08 (0U)
#  define Rte_InitValue_ApaAuthn_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaCmdReq_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaEna_Cnt_lgc (FALSE)
#  define Rte_InitValue_ApaRelaxReq_Cnt_lgc (FALSE)
#  define Rte_InitValue_AssistStallLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_CpkOk_Cnt_lgc (FALSE)
#  define Rte_InitValue_FTermActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
#  define Rte_InitValue_PosSrvoEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PosSrvoNTC_Cnt_lgc (FALSE)
#  define Rte_InitValue_ThermLimitPerc_Uls_f32 (0.0F)
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
#  define RTE_START_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

#  define RTE_STOP_SEC_VAR_Ap_9_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaAuthn_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaCmdReq_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaEna_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ApaRelaxReq_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_AssistStallLimit_MtrNm_f32.value)

#  define Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_CpkOk_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_FTermActv_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_StOpCtrl_OutputRampMult_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value)

#  define Rte_IRead_PSASH_Per1_PosSrvoNTC_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_PosSrvoNTC_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_ThermLimitPerc_Uls_f32.value)

#  define Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_SrlComInput_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_PSASH_Per1_APAStateTransitionCause_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_APAStateTransitionCause_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_APAStateTransitionCause_Cnt_u08() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_APAStateTransitionCause_Cnt_u08.value)

#  define Rte_IWrite_PSASH_Per1_APAState_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_APAState_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_APAState_Cnt_u08() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_APAState_Cnt_u08.value)

#  define Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_PosSrvoEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PSASH_Per1_PosSrvoEnable_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_PSASH_PSASH_Per1.Rte_PosSrvoEnable_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_PSASH_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Init1(void);

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Per1(void);

# define RTE_STOP_SEC_AP_PSASH_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_AP_PSASH_H */
