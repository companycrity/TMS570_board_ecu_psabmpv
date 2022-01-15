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
 *          File:  Rte_Ap_SrlComOutput.h
 *     Workspace:  C:/synergy_projects/PSA3.5.1/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Wed Apr  6 11:35:41 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComOutput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComOutput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ANGLECOLONNE_Cnt_u16 (0U)
# define Rte_InitValue_APAState_Cnt_u08 (0U)
# define Rte_InitValue_APAStateTransitionCause_Cnt_u08 (0U)
# define Rte_InitValue_AUTORARRETMOTDA_Cnt_u08 (0U)
# define Rte_InitValue_AVASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_CAUSEDESACTIVCPK_Cnt_u08 (0U)
# define Rte_InitValue_CODEDEFAUT_Cnt_u08 (0U)
# define Rte_InitValue_CPLEVOLANT_Cnt_u08 (0U)
# define Rte_InitValue_CPLEVOLANTOPTMSE_Cnt_u08 (0U)
# define Rte_InitValue_CTCFailed_Cnt_lgc (FALSE)
# define Rte_InitValue_CityParkSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_DDEREDEMDA_Cnt_u08 (0U)
# define Rte_InitValue_DefaultHwaSCommExportValue_Cnt_lgc (FALSE)
# define Rte_InitValue_ETATASSISTDA_Cnt_u08 (0U)
# define Rte_InitValue_ETATDA2004_Cnt_u08 (0U)
# define Rte_InitValue_ETATDA2010_Cnt_u08 (0U)
# define Rte_InitValue_ETATDADYN_Cnt_u08 (0U)
# define Rte_InitValue_ETATDAECPK_Cnt_u08 (0U)
# define Rte_InitValue_ETATLIGNEAPC_Cnt_u08 (0U)
# define Rte_InitValue_ETATSECUANGLECOL_Cnt_u08 (0U)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
# define Rte_InitValue_HandwheelTorque_HwNm_f32 (0.0F)
# define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
# define Rte_InitValue_ISDYNDAEFirstMessageSent_Cnt_lgc (FALSE)
# define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
# define Rte_InitValue_RampDwnStatusComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_RelHwPos_HwDeg_f32 (0.0F)
# define Rte_InitValue_STATUSCONFABSENT_Cnt_u32 (0U)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComHwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_VITESSECOLONNE_Cnt_u16 (0U)
# define Rte_InitValue_ValidEngineStatus_Cnt_lgc (FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComOutput_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_IndStatusETATDA2_GetIndicatorStatus(P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) IndicatorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_u08() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_APAStateTransitionCause_Cnt_u08->value)

# define Rte_IRead_SrlComOutput_Per1_APAState_Cnt_u08() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_APAState_Cnt_u08->value)

# define Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AVASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CTCFailed_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CityParkSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_EtatMT_Cnt_u08->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelTorque_HwNm_f32->value)

# define Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32->value)

# define Rte_IRead_SrlComOutput_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_RelHwPos_HwDeg_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_RelHwPos_HwDeg_f32->value)

# define Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_STTdSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_SrlComHwTrq_HwNm_f32->value)

# define Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16->value)

# define Rte_IWrite_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CODEDEFAUT_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CODEDEFAUT_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CPLEVOLANT_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_CPLEVOLANT_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_DDEREDEMDA_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_DDEREDEMDA_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATASSISTDA_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATASSISTDA_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATDA2004_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDA2004_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATDA2004_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDA2004_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATDA2010_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDA2010_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATDA2010_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDA2010_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATDADYN_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDADYN_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATDADYN_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDADYN_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDAECPK_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATDAECPK_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATDAECPK_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08->value)

# define Rte_IWrite_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32->value)

# define Rte_IWrite_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16() \
  (&Rte_Inst_Ap_SrlComOutput->SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComOutput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_SrlComOutput_EpsEn_OP_GET
# define Rte_Call_IndStatusETATDA2_GetIndicatorStatus Rte_Call_Ap_SrlComOutput_IndStatusETATDA2_GetIndicatorStatus
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComOutput_Per1_APAState_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_RelHwPos_HwDeg_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(void)
 *   void Rte_IWrite_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDA2004_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDA2004_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDA2010_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDA2010_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDADYN_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDADYN_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(void)
 *   void Rte_IWrite_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(void)
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
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_IndStatusETATDA2_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IndicatorStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_EpsEn_E_NOT_OK (1U)

# define RTE_E_IndicatorStatus_E_NOT_OK (1U)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1459971236
#    error "The magic number of the generated file <C:/synergy_projects/PSA3.5.1/PSA_BMPV_EPS_TMS570/SwProject/SrlComOutput/utp/contract/Ap_SrlComOutput/Rte_Ap_SrlComOutput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1459971236
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
