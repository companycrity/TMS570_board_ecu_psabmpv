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
 *          File:  Rte_Cd_SrlComDriver.h
 *     Workspace:  C:/synergy_projects/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Cd_SrlComDriver
 *  Generated at:  Wed May 18 10:37:27 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Cd_SrlComDriver> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CD_SRLCOMDRIVER_H
# define _RTE_CD_SRLCOMDRIVER_H

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

typedef P2CONST(struct Rte_CDS_Cd_SrlComDriver, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ANGLECOLONNE_Cnt_u16 (0U)
# define Rte_InitValue_AUTORARRETMOTDA_Cnt_u08 (0U)
# define Rte_InitValue_AnneeEcoule_Cnt_u08 (0U)
# define Rte_InitValue_BusOff_Cnt_lgc (FALSE)
# define Rte_InitValue_CAUSEDESACTIVCPK_Cnt_u08 (0U)
# define Rte_InitValue_CODEDEFAUT_Cnt_u08 (0U)
# define Rte_InitValue_CPLEVOLANT_Cnt_u08 (0U)
# define Rte_InitValue_CPLEVOLANTOPTMSE_Cnt_u08 (0U)
# define Rte_InitValue_ColumnAngleSetpoint_Cnt_u16 (0U)
# define Rte_InitValue_CompteurTemporelVehicule_Cnt_u32 (0U)
# define Rte_InitValue_ComputerRazGCT_Cnt_u08 (0U)
# define Rte_InitValue_DDEREDEMDA_Cnt_u08 (0U)
# define Rte_InitValue_DiagIntegraElec_Cnt_u08 (0U)
# define Rte_InitValue_DiagMuxOn_Cnt_u08 (0U)
# define Rte_InitValue_DmdDelestDA_Cnt_u08 (0U)
# define Rte_InitValue_ETATASSISTDA_Cnt_u08 (0U)
# define Rte_InitValue_ETATDA2004_Cnt_u08 (0U)
# define Rte_InitValue_ETATDA2010_Cnt_u08 (0U)
# define Rte_InitValue_ETATDADYN_Cnt_u08 (0U)
# define Rte_InitValue_ETATDAECPK_Cnt_u08 (0U)
# define Rte_InitValue_ETATLIGNEAPC_Cnt_u08 (0U)
# define Rte_InitValue_ETATSECUANGLECOL_Cnt_u08 (0U)
# define Rte_InitValue_EffacDefaultDiag_Cnt_u08 (0U)
# define Rte_InitValue_ElectronicIntegration_Cnt_lgc (FALSE)
# define Rte_InitValue_EtatMT_Cnt_u08 (0U)
# define Rte_InitValue_EtatPrincipSev_Cnt_u08 (0U)
# define Rte_InitValue_EtatReseauElec_Cnt_u08 (0U)
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
# define Rte_InitValue_ISDYNDAEFirstMessageSent_Cnt_lgc (FALSE)
# define Rte_InitValue_ISDYNVOLMsgDLCError_Cnt_u08 (0U)
# define Rte_InitValue_ISDYNVOLMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_ISINTEELECTRONBSIMsgRxTime_MSec_u32 (0U)
# define Rte_InitValue_JourEcoule_Cnt_u16 (0U)
# define Rte_InitValue_Kilometrage_Cnt_u32 (0U)
# define Rte_InitValue_LKAState_Cnt_u08 (0U)
# define Rte_InitValue_LKATrqFactReq_Cnt_u08 (0U)
# define Rte_InitValue_LXAActivation_Cnt_u08 (0U)
# define Rte_InitValue_LXASelected_Cnt_lgc (FALSE)
# define Rte_InitValue_MarcheARBVM_Cnt_u08 (0U)
# define Rte_InitValue_ModeDiag_Cnt_u08 (0U)
# define Rte_InitValue_PowerSupplies_Cnt_u08 (0U)
# define Rte_InitValue_STATUSCONFABSENT_Cnt_u32 (0U)
# define Rte_InitValue_STTdSelected_Cnt_lgc (FALSE)
# define Rte_InitValue_SecondeEcoulee_Cnt_u32 (0U)
# define Rte_InitValue_ShuntPosition_Cnt_u08 (0U)
# define Rte_InitValue_TMFTestComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_TxEnabled_Cnt_lgc (FALSE)
# define Rte_InitValue_VITESSECOLONNE_Cnt_u16 (0U)
# define Rte_InitValue_VitesseVehicleBV_Cnt_u16 (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Cd_SrlComDriver_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Cd_SrlComDriver_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SrlComDriver_Per1_ANGLECOLONNE_Cnt_u16() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ANGLECOLONNE_Cnt_u16->value)

# define Rte_IRead_SrlComDriver_Per1_AUTORARRETMOTDA_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_AUTORARRETMOTDA_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_CAUSEDESACTIVCPK_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_CAUSEDESACTIVCPK_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_CODEDEFAUT_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_CODEDEFAUT_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_CPLEVOLANTOPTMSE_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_CPLEVOLANTOPTMSE_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_CPLEVOLANT_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_CPLEVOLANT_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_DDEREDEMDA_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DDEREDEMDA_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATASSISTDA_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATASSISTDA_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATDA2004_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATDA2004_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATDA2010_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATDA2010_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATDADYN_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATDADYN_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATDAECPK_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATDAECPK_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATLIGNEAPC_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATLIGNEAPC_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ETATSECUANGLECOL_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ETATSECUANGLECOL_Cnt_u08->value)

# define Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Per1_LXASelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LXASelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Per1_STATUSCONFABSENT_Cnt_u32() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_STATUSCONFABSENT_Cnt_u32->value)

# define Rte_IRead_SrlComDriver_Per1_STTdSelected_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_STTdSelected_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_TMFTestComplete_Cnt_lgc->value)

# define Rte_IRead_SrlComDriver_Per1_VITESSECOLONNE_Cnt_u16() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_VITESSECOLONNE_Cnt_u16->value)

# define Rte_IWrite_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_AnneeEcoule_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_AnneeEcoule_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_AnneeEcoule_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_BusOff_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_BusOff_Cnt_lgc->value)

# define Rte_IWrite_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16->value)

# define Rte_IWrite_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ComputerRazGCT_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ComputerRazGCT_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DiagIntegraElec_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DiagIntegraElec_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DiagMuxOn_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_DiagMuxOn_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DiagMuxOn_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DmdDelestDA_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_DmdDelestDA_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_DmdDelestDA_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_EtatMT_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EtatMT_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_EtatMT_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EtatMT_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EtatPrincipSev_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EtatPrincipSev_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EtatReseauElec_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_EtatReseauElec_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_EtatReseauElec_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32->value)

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA)) (data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08->value; \
    uint16 i; \
    for (i = 0; i < sizeof(CanMsgType) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# else
#  define Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA)) *(data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08->value; \
    uint16 i; \
    for (i = 0; i < sizeof(CanMsgType) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08->value)
# else
#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08->value)
# endif

# define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32->value)

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA)) (data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08->value; \
    uint16 i; \
    for (i = 0; i < sizeof(CanMsgType) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# else
#  define Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA)) *(data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08->value; \
    uint16 i; \
    for (i = 0; i < sizeof(CanMsgType) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08->value)
# else
#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08->value)
# endif

# define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32->value)

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA)) (data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08->value; \
    uint16 i; \
    for (i = 0; i < sizeof(CanMsgType) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# else
#  define Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_DATA)) *(data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08->value; \
    uint16 i; \
    for (i = 0; i < sizeof(CanMsgType) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08() \
  (Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08->value)
# else
#  define Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08->value)
# endif

# define Rte_IWrite_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_JourEcoule_Cnt_u16(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_JourEcoule_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_JourEcoule_Cnt_u16() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_JourEcoule_Cnt_u16->value)

# define Rte_IWrite_SrlComDriver_Per1_Kilometrage_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_Kilometrage_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_Kilometrage_Cnt_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_Kilometrage_Cnt_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_LKAState_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LKAState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_LKAState_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LKAState_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LKATrqFactReq_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LKATrqFactReq_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_LXAActivation_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LXAActivation_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_LXAActivation_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_LXAActivation_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_MarcheARBVM_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_MarcheARBVM_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_MarcheARBVM_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_MarcheARBVM_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_ModeDiag_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ModeDiag_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ModeDiag_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ModeDiag_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_PowerSupplies_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_PowerSupplies_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_PowerSupplies_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_PowerSupplies_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_SecondeEcoulee_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_SecondeEcoulee_Cnt_u32->value)

# define Rte_IWrite_SrlComDriver_Per1_ShuntPosition_Cnt_u08(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ShuntPosition_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_ShuntPosition_Cnt_u08() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_ShuntPosition_Cnt_u08->value)

# define Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_TxEnabled_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_TxEnabled_Cnt_lgc->value)

# define Rte_IWrite_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(data) \
  ( \
  Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16() \
  (&Rte_Inst_Cd_SrlComDriver->SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Cd_SrlComDriver_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Cd_SrlComDriver_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Cd_SrlComDriver_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Cd_SrlComDriver_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Init1
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

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Per1
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
 *   UInt16 Rte_IRead_SrlComDriver_Per1_ANGLECOLONNE_Cnt_u16(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_AUTORARRETMOTDA_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CAUSEDESACTIVCPK_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CODEDEFAUT_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CPLEVOLANTOPTMSE_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_CPLEVOLANT_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_DDEREDEMDA_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATASSISTDA_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDA2004_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDA2010_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDADYN_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATDAECPK_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATLIGNEAPC_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComDriver_Per1_ETATSECUANGLECOL_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_ElectronicIntegration_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_LXASelected_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComDriver_Per1_STATUSCONFABSENT_Cnt_u32(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_STTdSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComDriver_Per1_TMFTestComplete_Cnt_lgc(void)
 *   UInt16 Rte_IRead_SrlComDriver_Per1_VITESSECOLONNE_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_AnneeEcoule_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_BusOff_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_BusOff_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_ColumnAngleSetpoint_Cnt_u16(void)
 *   void Rte_IWrite_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_CompteurTemporelVehicule_Cnt_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ComputerRazGCT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_DiagIntegraElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_DiagMuxOn_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_DmdDelestDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EffacDefaultDiag_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EtatMT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EtatMT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EtatPrincipSev_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_EtatReseauElec_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI412MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATBSI432MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDATDIRAMsgTxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYN2CMMMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsgRxTime_MSec_u32(void)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(const UInt8 *data)
# else
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(const CanMsgType *data)
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(void)
# else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_ISDYNAASMsg_Cnt_u08(void)
# endif
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsgRxTime_MSec_u32(void)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(const UInt8 *data)
# else
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(const CanMsgType *data)
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(void)
# else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_ISDYNABRMsg_Cnt_u08(void)
# endif
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM208MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNCMM388MsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgDLCError_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsgRxTime_MSec_u32(void)
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(const UInt8 *data)
# else
 *   void Rte_IWrite_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(const CanMsgType *data)
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(void)
# else
 *   CanMsgType *Rte_IWriteRef_SrlComDriver_Per1_ISDYNVOLMsg_Cnt_u08(void)
# endif
 *   void Rte_IWrite_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_JourEcoule_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_JourEcoule_Cnt_u16(void)
 *   void Rte_IWrite_SrlComDriver_Per1_Kilometrage_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_Kilometrage_Cnt_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_LKAState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_LKAState_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_LKATrqFactReq_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_LXAActivation_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_LXAActivation_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_MarcheARBVM_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_MarcheARBVM_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ModeDiag_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ModeDiag_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_PowerSupplies_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_PowerSupplies_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComDriver_Per1_SecondeEcoulee_Cnt_u32(void)
 *   void Rte_IWrite_SrlComDriver_Per1_ShuntPosition_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComDriver_Per1_ShuntPosition_Cnt_u08(void)
 *   void Rte_IWrite_SrlComDriver_Per1_TxEnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComDriver_Per1_TxEnabled_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComDriver_Per1_VitesseVehicleBV_Cnt_u16(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_ElecIntStart
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStart> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_ElecIntStart(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStart(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_ElecIntStop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ElecIntStop> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_ElecIntStop(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_ElecIntStop(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_SCom_GetBusOffCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetBusOffCounter> of PortPrototype <SrlComDriver_SCom>
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
 *   void SrlComDriver_SCom_GetBusOffCounter(UInt16 *BusOffCounter_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_SCom_GetBusOffCounter(P2VAR(UInt16, AUTOMATIC, RTE_CD_SRLCOMDRIVER_APPL_VAR) BusOffCounter_Cnt_T_u16);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComDriver_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
 *********************************************************************************************************************/

FUNC(void, RTE_CD_SRLCOMDRIVER_APPL_CODE) SrlComDriver_Trns2(void);

# define RTE_STOP_SEC_CD_SRLCOMDRIVER_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1463574024
#    error "The magic number of the generated file <C:/synergy_projects/PSA/PSA_BMPV_EPS_TMS570/SwProject/SrlComDriver/utp/contract/Cd_SrlComDriver/Rte_Cd_SrlComDriver.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1463574024
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CD_SRLCOMDRIVER_H */
