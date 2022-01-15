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
 *          File:  Components/Rte_Cd_SrlComDriver.h
 *     Workspace:  C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_SRLCOMDRIVER_H
# define _RTE_CD_SRLCOMDRIVER_H

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

#  define RTE_START_SEC_CODE
#  include "MemMap.h"

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16 num);

#  define RTE_STOP_SEC_CODE
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ANGLECOLONNE_Cnt_u16 (0U)
#  define Rte_InitValue_AUTORARRETMOTDA_Cnt_u08 (0U)
#  define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
#  define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
#  define Rte_InitValue_CAUSEDESACTIVCPK_Cnt_u08 (0U)
#  define Rte_InitValue_CODEDEFAUT_Cnt_u08 (0U)
#  define Rte_InitValue_CPLEVOLANT_Cnt_u08 (0U)
#  define Rte_InitValue_CPLEVOLANTOPTMSE_Cnt_u08 (0U)
#  define Rte_InitValue_ColumnAngleSetpoint_Cnt_u16 (0U)
#  define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
#  define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
#  define Rte_InitValue_DDEREDEMDA_Cnt_u08 (0U)
#  define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
#  define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
#  define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
#  define Rte_InitValue_ETATASSISTDA_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDA2004_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDA2010_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDADYN_Cnt_u08 (0U)
#  define Rte_InitValue_ETATDAECPK_Cnt_u08 (0U)
#  define Rte_InitValue_ETATLIGNEAPC_Cnt_u08 (0U)
#  define Rte_InitValue_ETATSECUANGLECOL_Cnt_u08 (0U)
#  define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
#  define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
#  define Rte_InitValue_EtatMT_Cnt_u08 (0U)
#  define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
#  define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
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
#  define Rte_InitValue_ISDYNDAEFirstMessageSent_Cnt_lgc (FALSE)
#  define Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08 (0U)
#  define Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32 (0U)
#  define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
#  define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
#  define Rte_InitValue_LKAState_Cnt_u08 (0U)
#  define Rte_InitValue_LKATrqFactReq_Cnt_u08 (0U)
#  define Rte_InitValue_LXAActivation_Cnt_u08 (0U)
#  define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_MarcheARBVM_Cnt_u08 (0U)
#  define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
#  define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
#  define Rte_InitValue_STATUSCONFABSENT_Cnt_u32 (0U)
#  define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
#  define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
#  define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
#  define Rte_InitValue_TMFTestComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
#  define Rte_InitValue_VITESSECOLONNE_Cnt_u16 (0U)
#  define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd6_SystemState6_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10ms_6, RTE_VAR_NOINIT) Rte_Task_10ms_6;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_SrlComDriver_Per1_ANGLECOLONNE_Cnt_u16() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ANGLECOLONNE_Cnt_u16.value)

#  define Rte_IRead_SrlComDriver_Per1_AUTORARRETMOTDA_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_AUTORARRETMOTDA_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_CAUSEDESACTIVCPK_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_CAUSEDESACTIVCPK_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_CODEDEFAUT_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_CODEDEFAUT_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_CPLEVOLANTOPTMSE_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_CPLEVOLANTOPTMSE_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_CPLEVOLANT_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_CPLEVOLANT_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_DDEREDEMDA_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DDEREDEMDA_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATASSISTDA_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATASSISTDA_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATDA2004_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATDA2004_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATDA2010_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATDA2010_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATDADYN_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATDADYN_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATDAECPK_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATDAECPK_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATLIGNEAPC_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATLIGNEAPC_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ETATSECUANGLECOL_Cnt_u08() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ETATSECUANGLECOL_Cnt_u08.value)

#  define Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ElectronicIntegration_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Per1_LXASelected_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LXASelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Per1_STATUSCONFABSENT_Cnt_u32() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_STATUSCONFABSENT_Cnt_u32.value)

#  define Rte_IRead_SrlComDriver_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_STTdSelected_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_TMFTestComplete_Cnt_lgc.value)

#  define Rte_IRead_SrlComDriver_Per1_VITESSECOLONNE_Cnt_u16() \
  (Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_VITESSECOLONNE_Cnt_u16.value)

#  define Rte_IWrite_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_AnneeEcoule_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_AnneeEcoule_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_AnneeEcoule_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_BusOff_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_BusOff_Cnt_lgc.value)

#  define Rte_IWrite_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ColumnAngleSetpoint_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ColumnAngleSetpoint_Cnt_u16.value)

#  define Rte_IWrite_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_CompteurTemporelVehicule_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_CompteurTemporelVehicule_Cnt_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ComputerRazGCT_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ComputerRazGCT_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DiagIntegraElec_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DiagIntegraElec_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DiagMuxOn_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_DiagMuxOn_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DiagMuxOn_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DmdDelestDA_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_DmdDelestDA_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_DmdDelestDA_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EffacDefaultDiag_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EffacDefaultDiag_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_EtatMT_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EtatMT_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_EtatMT_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EtatMT_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EtatPrincipSev_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EtatPrincipSev_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EtatReseauElec_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_EtatReseauElec_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_EtatReseauElec_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDAT4V2BSI552MsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDAT4V2BSI552MsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDAT4V2BSI552MsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDAT4V2BSI552MsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI3F2MsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI3F2MsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI3F2MsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI3F2MsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI412MsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI412MsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI412MsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI412MsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI432MsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI432MsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI432MsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATBSI432MsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATDIRAMsgTxInProgress_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATDIRAMsgTxInProgress_Cnt_lgc.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATDIRAMsgTxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDATDIRAMsgTxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYN2CMMMsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYN2CMMMsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYN2CMMMsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYN2CMMMsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNAASMsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNAASMsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNAASMsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNAASMsgRxTime_MSec_u32.value)

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(data) \
  RteIWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(&(data))
#  else
#   define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(data) \
  RteIWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(data)
#  endif
#  define RteIWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(data) \
  ( \
    Rte_MemCpy(Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNAASMsg_Cnt_u08.value, *(data), sizeof(CanMsgType)) \
  )

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08() \
  (&((*RteIWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08()))[0])
#  else
#   define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08() \
  RteIWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08()
#  endif
#  define RteIWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNAASMsg_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNABRMsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNABRMsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNABRMsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNABRMsgRxTime_MSec_u32.value)

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(data) \
  RteIWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(&(data))
#  else
#   define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(data) \
  RteIWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(data)
#  endif
#  define RteIWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(data) \
  ( \
    Rte_MemCpy(Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNABRMsg_Cnt_u08.value, *(data), sizeof(CanMsgType)) \
  )

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08() \
  (&((*RteIWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08()))[0])
#  else
#   define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08() \
  RteIWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08()
#  endif
#  define RteIWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNABRMsg_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM208MsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM208MsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM208MsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM208MsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM388MsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM388MsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM388MsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNCMM388MsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNDAEFirstMessageSent_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNDAEFirstMessageSent_Cnt_lgc.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNVOLMsgDLCError_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNVOLMsgDLCError_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNVOLMsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNVOLMsgRxTime_MSec_u32.value)

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(data) \
  RteIWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(&(data))
#  else
#   define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(data) \
  RteIWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(data)
#  endif
#  define RteIWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(data) \
  ( \
    Rte_MemCpy(Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNVOLMsg_Cnt_u08.value, *(data), sizeof(CanMsgType)) \
  )

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08() \
  (&((*RteIWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08()))[0])
#  else
#   define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08() \
  RteIWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08()
#  endif
#  define RteIWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISDYNVOLMsg_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISINTEELECTRONBSIMsgRxTime_MSec_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ISINTEELECTRONBSIMsgRxTime_MSec_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_JourEcoule_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_JourEcoule_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_JourEcoule_Cnt_u16() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_JourEcoule_Cnt_u16.value)

#  define Rte_IWrite_SrlComDriver_Per1_Kilometrage_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_Kilometrage_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_Kilometrage_Cnt_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_Kilometrage_Cnt_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_LKAState_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LKAState_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_LKAState_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LKAState_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LKATrqFactReq_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LKATrqFactReq_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_LXAActivation_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LXAActivation_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_LXAActivation_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_LXAActivation_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_MarcheARBVM_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_MarcheARBVM_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_MarcheARBVM_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_MarcheARBVM_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_ModeDiag_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ModeDiag_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ModeDiag_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ModeDiag_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_PowerSupplies_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_PowerSupplies_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_PowerSupplies_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_PowerSupplies_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_SecondeEcoulee_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_SecondeEcoulee_Cnt_u32.value)

#  define Rte_IWrite_SrlComDriver_Per1_ShuntPosition_Cnt_u08(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ShuntPosition_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_ShuntPosition_Cnt_u08() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_ShuntPosition_Cnt_u08.value)

#  define Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_TxEnabled_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_TxEnabled_Cnt_lgc.value)

#  define Rte_IWrite_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(data) \
  ( \
    Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_VitesseVehicleBV_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16() \
  (&Rte_Task_10ms_6.Rte_RB.Rte_Cd_SrlComDriver_SrlComDriver_Per1.Rte_VitesseVehicleBV_Cnt_u16.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd6_SystemState6_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR6_APPL_CODE) NxtrDiagMgr6_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR6_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr6_SetNTCStatus
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


# define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Init1(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Per1(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStart(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStop(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) BusOffCounter_Cnt_T_u16);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns1(void);

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns2(void);

# define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_CD_SRLCOMDRIVER_H */
