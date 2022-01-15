/* -----------------------------------------------------------------------------
  Filename:    il_par.h
  Description: Toolversion: 05.00.17.01.30.06.60.01.00.00
               
               Serial Number: CBD1300660
               Customer Info: Nexteer Automotive Corporation
                              Package: CBD Psa SLP4
                              Micro: 0812BPGEQQ1
                              Compiler: TexasInstruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: Il_Vector
               
               Configuration   : C:\synergy_projects_working\PSA\PSA_BMPV_EPS_TMS570\Tools\AsrProject\Config\System\EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS0322
               
               Channel "Channel0":
                       Databasefile: C:\synergy_projects_working\PSA\PSA_BMPV_EPS_TMS570\Tools\AsrProject\Config\System\PSA_BMPV.dbc
                       Bussystem:    CAN
                       Manufacturer: PSA
                       Node:         PSCM

  Generated by , 2016-05-11  13:17:06
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__IL_PAR_H__)
#define __IL_PAR_H__

/* -----------------------------------------------------------------------------
    &&&~ Typedefs
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
typedef vuint8 IltTxCounter;
#endif

#if defined(IL_ENABLE_TX)
typedef vuint8 IltTxUpdateCounter;
#endif

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
typedef vuint8 IltTxTimeoutCounter;
#endif

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
typedef vuint8 IltRxTimeoutCounter;
#endif

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_SECURE_EVENT)
typedef vuint8 IltTxRepetitionCounter;
#endif



/* -----------------------------------------------------------------------------
    &&&~ Message Handles
 ----------------------------------------------------------------------------- */

#define IlRxMsgHndIS_ACQ_JDD_CAN_BSI_772     0
#define IlRxMsgHndIS_ACQ_NEW_JDD_55F         1
#define IlRxMsgHndIS_DAT4_V2_BSI_552         2
#define IlRxMsgHndIS_DAT_BSI_432             3
#define IlRxMsgHndIS_DAT_BSI_412             4
#define IlRxMsgHndIS_DAT_BSI_3F2             5
#define IlRxMsgHndIS_DYN_CMM_388             6
#define IlRxMsgHndIS_DYN2_CMM_348            7
#define IlRxMsgHndIS_DYN_CMM_208             8
#define IlRxMsgHndIS_INTE_ELECTRON_BSI       9
#define IlTxMsgHndIS_SUPV_DIRA               0
#define IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA   1
#define IlTxMsgHndIS_DAT_DIRA                2
#define IlTxMsgHndIS_DYN_DAE                 3
#define IlTxMsgHndIS_VERS_DIRA_115           4


/* -----------------------------------------------------------------------------
    &&&~ Signal Handles
 ----------------------------------------------------------------------------- */

#define IlRxSigHndDATA_ACQ_JDD_BSI           IlRxMsgHndIS_ACQ_JDD_CAN_BSI_772
#define IlRxSigHndDATA_ACQ_JDD_BSI_2         IlRxMsgHndIS_ACQ_NEW_JDD_55F
#define IlRxSigHndMsg552_Byte0               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte1               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte2               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte3               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte4               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte5               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte6               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndMsg552_Byte7               IlRxMsgHndIS_DAT4_V2_BSI_552
#define IlRxSigHndETAT_PRINCIP_SEV           IlRxMsgHndIS_DAT_BSI_432
#define IlRxSigHndPower_Supplies             IlRxMsgHndIS_DAT_BSI_432
#define IlRxSigHndShunt_Position             IlRxMsgHndIS_DAT_BSI_432
#define IlRxSigHndETAT_RESEAU_ELEC           IlRxMsgHndIS_DAT_BSI_432
#define IlRxSigHndMARCHE_AR_BVM              IlRxMsgHndIS_DAT_BSI_412
#define IlRxSigHndDMD_DELEST_DA              IlRxMsgHndIS_DAT_BSI_3F2
#define IlRxSigHndLKA_STATE                  IlRxMsgHndIS_DAT_BSI_3F2
#define IlRxSigHndLXA_ACTIVATION             IlRxMsgHndIS_DAT_BSI_3F2
#define IlRxSigHndLKA_TRQ_FACT_REQ           IlRxMsgHndIS_DAT_BSI_3F2
#define IlRxSigHndCOLUMN_ANGLE_SETPOINT      IlRxMsgHndIS_DAT_BSI_3F2
#define IlRxSigHndVITESSE_VEHICLE_BV         IlRxMsgHndIS_DYN_CMM_388
#define IlRxSigHndETAT_MT                    IlRxMsgHndIS_DYN2_CMM_348
#define IlRxSigHndDIAG_MUX_ON                IlRxMsgHndIS_DYN_CMM_208
#define IlRxSigHndEFFAC_DEFAULT_DIAG         IlRxMsgHndIS_INTE_ELECTRON_BSI
#define IlRxSigHndMODE_DIAG                  IlRxMsgHndIS_INTE_ELECTRON_BSI
#define IlRxSigHndDIAG_INTEGRA_ELEC          IlRxMsgHndIS_INTE_ELECTRON_BSI
#define IlTxSigHndCODE_DEFAUT                IlTxMsgHndIS_SUPV_DIRA
#define IlTxSigHndSTATUS_CONFABSENT          IlTxMsgHndIS_SUPV_DIRA
#define IlTxSigHndETAT_ASSIST_DA             IlTxMsgHndIS_SUPV_DIRA
#define IlTxSigHndETAT_LIGNE_APC             IlTxMsgHndIS_SUPV_DIRA
#define IlTxSigHndType_of_Message            IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndDTC_State                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndFrame_Number               IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndNumber_of_Frames           IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte1                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte2                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte3                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte4                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte5                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte6                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndJDD_Byte7                  IlTxMsgHndIS_EMIS_NEW_JDD_CAN_DIRA
#define IlTxSigHndCPLE_VOLANT                IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndETAT_DA_2004               IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndETAT_DA_DYN                IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndETAT_DA_2010               IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndTRQ_LIMIT_STATE            IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndSTEERWHL_HOLD_BY_DRV       IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndEPS_STATE_LKA              IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndAUTOR_ARRET_MOT_DA         IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndDDE_REDEM_DA               IlTxMsgHndIS_DAT_DIRA
#define IlTxSigHndCPT_PROCESS_4B_DAE         IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndCHKSUM_TRME_DYN_DAE        IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndCPLE_VOLANT_OPTMSE         IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndCAUSE_DESACTIV_CPK         IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndETAT_DAE_CPK               IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndANGLE_COLONNE              IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndVITESSE_COLONNE            IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndETAT_SECU_ANGLE_COL        IlTxMsgHndIS_DYN_DAE
#define IlTxSigHndSystem_Code                IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndDownload_Day               IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndDownload_Month             IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndDownload_Year              IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndApplication_Code           IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndSoftware_Version           IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndSoftware_Edition_MSB       IlTxMsgHndIS_VERS_DIRA_115
#define IlTxSigHndSoftware_Edition_LSB       IlTxMsgHndIS_VERS_DIRA_115


/* -----------------------------------------------------------------------------
    &&&~ Critical section macros for signals
 ----------------------------------------------------------------------------- */

#define IlEnterCriticalCODE_DEFAUT()         CanGlobalInterruptDisable()
#define IlLeaveCriticalCODE_DEFAUT()         CanGlobalInterruptRestore()
#define IlEnterCriticalSTATUS_CONFABSENT()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSTATUS_CONFABSENT()   CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_ASSIST_DA()      CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_ASSIST_DA()      CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_LIGNE_APC()      CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_LIGNE_APC()      CanGlobalInterruptRestore()
#define IlEnterCriticalType_of_Message()     CanGlobalInterruptDisable()
#define IlLeaveCriticalType_of_Message()     CanGlobalInterruptRestore()
#define IlEnterCriticalDTC_State()           CanGlobalInterruptDisable()
#define IlLeaveCriticalDTC_State()           CanGlobalInterruptRestore()
#define IlEnterCriticalFrame_Number()        CanGlobalInterruptDisable()
#define IlLeaveCriticalFrame_Number()        CanGlobalInterruptRestore()
#define IlEnterCriticalNumber_of_Frames()    CanGlobalInterruptDisable()
#define IlLeaveCriticalNumber_of_Frames()    CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte1()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte1()           CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte2()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte2()           CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte3()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte3()           CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte4()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte4()           CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte5()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte5()           CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte6()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte6()           CanGlobalInterruptRestore()
#define IlEnterCriticalJDD_Byte7()           CanGlobalInterruptDisable()
#define IlLeaveCriticalJDD_Byte7()           CanGlobalInterruptRestore()
#define IlEnterCriticalCPLE_VOLANT()         CanGlobalInterruptDisable()
#define IlLeaveCriticalCPLE_VOLANT()         CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_DA_2004()        CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_DA_2004()        CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_DA_DYN()         CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_DA_DYN()         CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_DA_2010()        CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_DA_2010()        CanGlobalInterruptRestore()
#define IlEnterCriticalTRQ_LIMIT_STATE()     CanGlobalInterruptDisable()
#define IlLeaveCriticalTRQ_LIMIT_STATE()     CanGlobalInterruptRestore()
#define IlEnterCriticalSTEERWHL_HOLD_BY_DRV() CanGlobalInterruptDisable()
#define IlLeaveCriticalSTEERWHL_HOLD_BY_DRV() CanGlobalInterruptRestore()
#define IlEnterCriticalEPS_STATE_LKA()       CanGlobalInterruptDisable()
#define IlLeaveCriticalEPS_STATE_LKA()       CanGlobalInterruptRestore()
#define IlEnterCriticalAUTOR_ARRET_MOT_DA()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAUTOR_ARRET_MOT_DA()  CanGlobalInterruptRestore()
#define IlEnterCriticalDDE_REDEM_DA()        CanGlobalInterruptDisable()
#define IlLeaveCriticalDDE_REDEM_DA()        CanGlobalInterruptRestore()
#define IlEnterCriticalCPT_PROCESS_4B_DAE()  CanGlobalInterruptDisable()
#define IlLeaveCriticalCPT_PROCESS_4B_DAE()  CanGlobalInterruptRestore()
#define IlEnterCriticalCHKSUM_TRME_DYN_DAE() CanGlobalInterruptDisable()
#define IlLeaveCriticalCHKSUM_TRME_DYN_DAE() CanGlobalInterruptRestore()
#define IlEnterCriticalCPLE_VOLANT_OPTMSE()  CanGlobalInterruptDisable()
#define IlLeaveCriticalCPLE_VOLANT_OPTMSE()  CanGlobalInterruptRestore()
#define IlEnterCriticalCAUSE_DESACTIV_CPK()  CanGlobalInterruptDisable()
#define IlLeaveCriticalCAUSE_DESACTIV_CPK()  CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_DAE_CPK()        CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_DAE_CPK()        CanGlobalInterruptRestore()
#define IlEnterCriticalANGLE_COLONNE()       CanGlobalInterruptDisable()
#define IlLeaveCriticalANGLE_COLONNE()       CanGlobalInterruptRestore()
#define IlEnterCriticalVITESSE_COLONNE()     CanGlobalInterruptDisable()
#define IlLeaveCriticalVITESSE_COLONNE()     CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_SECU_ANGLE_COL() CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_SECU_ANGLE_COL() CanGlobalInterruptRestore()
#define IlEnterCriticalSystem_Code()         CanGlobalInterruptDisable()
#define IlLeaveCriticalSystem_Code()         CanGlobalInterruptRestore()
#define IlEnterCriticalDownload_Day()        CanGlobalInterruptDisable()
#define IlLeaveCriticalDownload_Day()        CanGlobalInterruptRestore()
#define IlEnterCriticalDownload_Month()      CanGlobalInterruptDisable()
#define IlLeaveCriticalDownload_Month()      CanGlobalInterruptRestore()
#define IlEnterCriticalDownload_Year()       CanGlobalInterruptDisable()
#define IlLeaveCriticalDownload_Year()       CanGlobalInterruptRestore()
#define IlEnterCriticalApplication_Code()    CanGlobalInterruptDisable()
#define IlLeaveCriticalApplication_Code()    CanGlobalInterruptRestore()
#define IlEnterCriticalSoftware_Version()    CanGlobalInterruptDisable()
#define IlLeaveCriticalSoftware_Version()    CanGlobalInterruptRestore()
#define IlEnterCriticalSoftware_Edition_MSB() CanGlobalInterruptDisable()
#define IlLeaveCriticalSoftware_Edition_MSB() CanGlobalInterruptRestore()
#define IlEnterCriticalSoftware_Edition_LSB() CanGlobalInterruptDisable()
#define IlLeaveCriticalSoftware_Edition_LSB() CanGlobalInterruptRestore()
#define IlEnterCriticalDATA_ACQ_JDD_BSI()    CanGlobalInterruptDisable()
#define IlLeaveCriticalDATA_ACQ_JDD_BSI()    CanGlobalInterruptRestore()
#define IlEnterCriticalDATA_ACQ_JDD_BSI_2()  CanGlobalInterruptDisable()
#define IlLeaveCriticalDATA_ACQ_JDD_BSI_2()  CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte0()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte0()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte1()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte1()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte2()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte2()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte3()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte3()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte4()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte4()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte5()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte5()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte6()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte6()        CanGlobalInterruptRestore()
#define IlEnterCriticalMsg552_Byte7()        CanGlobalInterruptDisable()
#define IlLeaveCriticalMsg552_Byte7()        CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_PRINCIP_SEV()    CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_PRINCIP_SEV()    CanGlobalInterruptRestore()
#define IlEnterCriticalPower_Supplies()      CanGlobalInterruptDisable()
#define IlLeaveCriticalPower_Supplies()      CanGlobalInterruptRestore()
#define IlEnterCriticalShunt_Position()      CanGlobalInterruptDisable()
#define IlLeaveCriticalShunt_Position()      CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_RESEAU_ELEC()    CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_RESEAU_ELEC()    CanGlobalInterruptRestore()
#define IlEnterCriticalMARCHE_AR_BVM()       CanGlobalInterruptDisable()
#define IlLeaveCriticalMARCHE_AR_BVM()       CanGlobalInterruptRestore()
#define IlEnterCriticalDMD_DELEST_DA()       CanGlobalInterruptDisable()
#define IlLeaveCriticalDMD_DELEST_DA()       CanGlobalInterruptRestore()
#define IlEnterCriticalLKA_STATE()           CanGlobalInterruptDisable()
#define IlLeaveCriticalLKA_STATE()           CanGlobalInterruptRestore()
#define IlEnterCriticalLXA_ACTIVATION()      CanGlobalInterruptDisable()
#define IlLeaveCriticalLXA_ACTIVATION()      CanGlobalInterruptRestore()
#define IlEnterCriticalLKA_TRQ_FACT_REQ()    CanGlobalInterruptDisable()
#define IlLeaveCriticalLKA_TRQ_FACT_REQ()    CanGlobalInterruptRestore()
#define IlEnterCriticalCOLUMN_ANGLE_SETPOINT() CanGlobalInterruptDisable()
#define IlLeaveCriticalCOLUMN_ANGLE_SETPOINT() CanGlobalInterruptRestore()
#define IlEnterCriticalVITESSE_VEHICLE_BV()  CanGlobalInterruptDisable()
#define IlLeaveCriticalVITESSE_VEHICLE_BV()  CanGlobalInterruptRestore()
#define IlEnterCriticalETAT_MT()             CanGlobalInterruptDisable()
#define IlLeaveCriticalETAT_MT()             CanGlobalInterruptRestore()
#define IlEnterCriticalDIAG_MUX_ON()         CanGlobalInterruptDisable()
#define IlLeaveCriticalDIAG_MUX_ON()         CanGlobalInterruptRestore()
#define IlEnterCriticalEFFAC_DEFAULT_DIAG()  CanGlobalInterruptDisable()
#define IlLeaveCriticalEFFAC_DEFAULT_DIAG()  CanGlobalInterruptRestore()
#define IlEnterCriticalMODE_DIAG()           CanGlobalInterruptDisable()
#define IlLeaveCriticalMODE_DIAG()           CanGlobalInterruptRestore()
#define IlEnterCriticalDIAG_INTEGRA_ELEC()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDIAG_INTEGRA_ELEC()   CanGlobalInterruptRestore()


/* -----------------------------------------------------------------------------
    &&&~ Declaration Confirmation Functions
 ----------------------------------------------------------------------------- */

/* Application signal confirmation callback functions */


/* -----------------------------------------------------------------------------
    &&&~ Declaration Indication Functions
 ----------------------------------------------------------------------------- */

/* Application signal indication callback functions */


/* -----------------------------------------------------------------------------
    &&&~ Declaration User Timeout Functions
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
#endif



/* -----------------------------------------------------------------------------
    &&&~ ExternDecl Internal Get Tx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:    1,Name:              STATUS_CONFABSENT,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint32 IlPrivateGetTxSTATUS_CONFABSENT(void);
#endif



/* -----------------------------------------------------------------------------
    &&&~ Get Rx Signal Access for signals smaller or equal 8bit
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:               DATA_ACQ_JDD_BSI,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDATA_ACQ_JDD_BSI()            (IS_ACQ_JDD_CAN_BSI_772.IS_ACQ_JDD_CAN_BSI_772.DATA_ACQ_JDD_BSI)
#endif

/* Handle:    1,Name:             DATA_ACQ_JDD_BSI_2,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDATA_ACQ_JDD_BSI_2()          (IS_ACQ_NEW_JDD_55F.IS_ACQ_NEW_JDD_55F.DATA_ACQ_JDD_BSI_2)
#endif

/* Handle:    2,Name:                   Msg552_Byte0,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte0()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte0)
#endif

/* Handle:    3,Name:                   Msg552_Byte1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte1()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte1)
#endif

/* Handle:    4,Name:                   Msg552_Byte2,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte2()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte2)
#endif

/* Handle:    5,Name:                   Msg552_Byte3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte3()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte3)
#endif

/* Handle:    6,Name:                   Msg552_Byte4,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte4()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte4)
#endif

/* Handle:    7,Name:                   Msg552_Byte5,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte5()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte5)
#endif

/* Handle:    8,Name:                   Msg552_Byte6,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte6()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte6)
#endif

/* Handle:    9,Name:                   Msg552_Byte7,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMsg552_Byte7()                (IS_DAT4_V2_BSI_552.IS_DAT4_V2_BSI_552.Msg552_Byte7)
#endif

/* Handle:   10,Name:               ETAT_PRINCIP_SEV,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxETAT_PRINCIP_SEV()            (IS_DAT_BSI_432.IS_DAT_BSI_432.ETAT_PRINCIP_SEV)
#endif

/* Handle:   11,Name:                 Power_Supplies,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxPower_Supplies()              (IS_DAT_BSI_432.IS_DAT_BSI_432.Power_Supplies)
#endif

/* Handle:   12,Name:                 Shunt_Position,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxShunt_Position()              (IS_DAT_BSI_432.IS_DAT_BSI_432.Shunt_Position)
#endif

/* Handle:   13,Name:               ETAT_RESEAU_ELEC,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxETAT_RESEAU_ELEC()            (IS_DAT_BSI_432.IS_DAT_BSI_432.ETAT_RESEAU_ELEC)
#endif

/* Handle:   14,Name:                  MARCHE_AR_BVM,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMARCHE_AR_BVM()               (IS_DAT_BSI_412.IS_DAT_BSI_412.MARCHE_AR_BVM)
#endif

/* Handle:   15,Name:                  DMD_DELEST_DA,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDMD_DELEST_DA()               (IS_DAT_BSI_3F2.IS_DAT_BSI_3F2.DMD_DELEST_DA)
#endif

/* Handle:   16,Name:                      LKA_STATE,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLKA_STATE()                   (IS_DAT_BSI_3F2.IS_DAT_BSI_3F2.LKA_STATE)
#endif

/* Handle:   17,Name:                 LXA_ACTIVATION,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLXA_ACTIVATION()              (IS_DAT_BSI_3F2.IS_DAT_BSI_3F2.LXA_ACTIVATION)
#endif

/* Handle:   18,Name:               LKA_TRQ_FACT_REQ,Size:  7,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLKA_TRQ_FACT_REQ()            (IS_DAT_BSI_3F2.IS_DAT_BSI_3F2.LKA_TRQ_FACT_REQ)
#endif

/* Handle:   21,Name:                        ETAT_MT,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxETAT_MT()                     (IS_DYN2_CMM_348.IS_DYN2_CMM_348.ETAT_MT)
#endif

/* Handle:   22,Name:                    DIAG_MUX_ON,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDIAG_MUX_ON()                 (IS_DYN_CMM_208.IS_DYN_CMM_208.DIAG_MUX_ON)
#endif

/* Handle:   23,Name:             EFFAC_DEFAULT_DIAG,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxEFFAC_DEFAULT_DIAG()          (IS_INTE_ELECTRON_BSI.IS_INTE_ELECTRON_BSI.EFFAC_DEFAULT_DIAG)
#endif

/* Handle:   24,Name:                      MODE_DIAG,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMODE_DIAG()                   (IS_INTE_ELECTRON_BSI.IS_INTE_ELECTRON_BSI.MODE_DIAG)
#endif

/* Handle:   25,Name:              DIAG_INTEGRA_ELEC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDIAG_INTEGRA_ELEC()           (IS_INTE_ELECTRON_BSI.IS_INTE_ELECTRON_BSI.DIAG_INTEGRA_ELEC)
#endif



/* -----------------------------------------------------------------------------
    &&&~ Get Rx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:   19,Name:          COLUMN_ANGLE_SETPOINT,Size: 14,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxCOLUMN_ANGLE_SETPOINT(void);
#endif

/* Handle:   20,Name:             VITESSE_VEHICLE_BV,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxVITESSE_VEHICLE_BV(void);
#endif



/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Access for signals smaller or equal 8bit, SendType cyclic or none
 ----------------------------------------------------------------------------- */

/* Handle:    4,Name:                Type_of_Message,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxType_of_Message(c) \
{ \
  IlEnterCriticalType_of_Message(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.Type_of_Message = (c); \
  IlLeaveCriticalType_of_Message(); \
}
#endif

/* Handle:    5,Name:                      DTC_State,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxDTC_State(c) \
{ \
  IlEnterCriticalDTC_State(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.DTC_State = (c); \
  IlLeaveCriticalDTC_State(); \
}
#endif

/* Handle:    7,Name:               Number_of_Frames,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxNumber_of_Frames(c) \
{ \
  IlEnterCriticalNumber_of_Frames(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.Number_of_Frames = (c); \
  IlLeaveCriticalNumber_of_Frames(); \
}
#endif

/* Handle:    8,Name:                      JDD_Byte1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte1(c) \
{ \
  IlEnterCriticalJDD_Byte1(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte1 = (c); \
  IlLeaveCriticalJDD_Byte1(); \
}
#endif

/* Handle:    9,Name:                      JDD_Byte2,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte2(c) \
{ \
  IlEnterCriticalJDD_Byte2(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte2 = (c); \
  IlLeaveCriticalJDD_Byte2(); \
}
#endif

/* Handle:   10,Name:                      JDD_Byte3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte3(c) \
{ \
  IlEnterCriticalJDD_Byte3(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte3 = (c); \
  IlLeaveCriticalJDD_Byte3(); \
}
#endif

/* Handle:   11,Name:                      JDD_Byte4,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte4(c) \
{ \
  IlEnterCriticalJDD_Byte4(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte4 = (c); \
  IlLeaveCriticalJDD_Byte4(); \
}
#endif

/* Handle:   12,Name:                      JDD_Byte5,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte5(c) \
{ \
  IlEnterCriticalJDD_Byte5(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte5 = (c); \
  IlLeaveCriticalJDD_Byte5(); \
}
#endif

/* Handle:   13,Name:                      JDD_Byte6,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte6(c) \
{ \
  IlEnterCriticalJDD_Byte6(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte6 = (c); \
  IlLeaveCriticalJDD_Byte6(); \
}
#endif

/* Handle:   14,Name:                      JDD_Byte7,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxJDD_Byte7(c) \
{ \
  IlEnterCriticalJDD_Byte7(); \
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.JDD_Byte7 = (c); \
  IlLeaveCriticalJDD_Byte7(); \
}
#endif

/* Handle:   15,Name:                    CPLE_VOLANT,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxCPLE_VOLANT(c) \
{ \
  IlEnterCriticalCPLE_VOLANT(); \
  IS_DAT_DIRA.IS_DAT_DIRA.CPLE_VOLANT = (c); \
  IlLeaveCriticalCPLE_VOLANT(); \
}
#endif

/* Handle:   16,Name:                   ETAT_DA_2004,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxETAT_DA_2004(c) \
{ \
  IlEnterCriticalETAT_DA_2004(); \
  IS_DAT_DIRA.IS_DAT_DIRA.ETAT_DA_2004 = (c); \
  IlLeaveCriticalETAT_DA_2004(); \
}
#endif

/* Handle:   17,Name:                    ETAT_DA_DYN,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxETAT_DA_DYN(c) \
{ \
  IlEnterCriticalETAT_DA_DYN(); \
  IS_DAT_DIRA.IS_DAT_DIRA.ETAT_DA_DYN = (c); \
  IlLeaveCriticalETAT_DA_DYN(); \
}
#endif

/* Handle:   18,Name:                   ETAT_DA_2010,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxETAT_DA_2010(c) \
{ \
  IlEnterCriticalETAT_DA_2010(); \
  IS_DAT_DIRA.IS_DAT_DIRA.ETAT_DA_2010 = (c); \
  IlLeaveCriticalETAT_DA_2010(); \
}
#endif

/* Handle:   19,Name:                TRQ_LIMIT_STATE,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTRQ_LIMIT_STATE(c) \
{ \
  IlEnterCriticalTRQ_LIMIT_STATE(); \
  IS_DAT_DIRA.IS_DAT_DIRA.TRQ_LIMIT_STATE = (c); \
  IlLeaveCriticalTRQ_LIMIT_STATE(); \
}
#endif

/* Handle:   20,Name:           STEERWHL_HOLD_BY_DRV,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSTEERWHL_HOLD_BY_DRV(c) \
{ \
  IlEnterCriticalSTEERWHL_HOLD_BY_DRV(); \
  IS_DAT_DIRA.IS_DAT_DIRA.STEERWHL_HOLD_BY_DRV = (c); \
  IlLeaveCriticalSTEERWHL_HOLD_BY_DRV(); \
}
#endif

/* Handle:   21,Name:                  EPS_STATE_LKA,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxEPS_STATE_LKA(c) \
{ \
  IlEnterCriticalEPS_STATE_LKA(); \
  IS_DAT_DIRA.IS_DAT_DIRA.EPS_STATE_LKA = (c); \
  IlLeaveCriticalEPS_STATE_LKA(); \
}
#endif

/* Handle:   22,Name:             AUTOR_ARRET_MOT_DA,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAUTOR_ARRET_MOT_DA(c) \
{ \
  IlEnterCriticalAUTOR_ARRET_MOT_DA(); \
  IS_DAT_DIRA.IS_DAT_DIRA.AUTOR_ARRET_MOT_DA = (c); \
  IlLeaveCriticalAUTOR_ARRET_MOT_DA(); \
}
#endif

/* Handle:   23,Name:                   DDE_REDEM_DA,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxDDE_REDEM_DA(c) \
{ \
  IlEnterCriticalDDE_REDEM_DA(); \
  IS_DAT_DIRA.IS_DAT_DIRA.DDE_REDEM_DA = (c); \
  IlLeaveCriticalDDE_REDEM_DA(); \
}
#endif

/* Handle:   24,Name:             CPT_PROCESS_4B_DAE,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxCPT_PROCESS_4B_DAE(c) \
{ \
  IlEnterCriticalCPT_PROCESS_4B_DAE(); \
  IS_DYN_DAE.IS_DYN_DAE.CPT_PROCESS_4B_DAE = (c); \
  IlLeaveCriticalCPT_PROCESS_4B_DAE(); \
}
#endif

/* Handle:   25,Name:            CHKSUM_TRME_DYN_DAE,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxCHKSUM_TRME_DYN_DAE(c) \
{ \
  IlEnterCriticalCHKSUM_TRME_DYN_DAE(); \
  IS_DYN_DAE.IS_DYN_DAE.CHKSUM_TRME_DYN_DAE = (c); \
  IlLeaveCriticalCHKSUM_TRME_DYN_DAE(); \
}
#endif

/* Handle:   26,Name:             CPLE_VOLANT_OPTMSE,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxCPLE_VOLANT_OPTMSE(c) \
{ \
  IlEnterCriticalCPLE_VOLANT_OPTMSE(); \
  IS_DYN_DAE.IS_DYN_DAE.CPLE_VOLANT_OPTMSE = (c); \
  IlLeaveCriticalCPLE_VOLANT_OPTMSE(); \
}
#endif

/* Handle:   27,Name:             CAUSE_DESACTIV_CPK,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxCAUSE_DESACTIV_CPK(c) \
{ \
  IlEnterCriticalCAUSE_DESACTIV_CPK(); \
  IS_DYN_DAE.IS_DYN_DAE.CAUSE_DESACTIV_CPK = (c); \
  IlLeaveCriticalCAUSE_DESACTIV_CPK(); \
}
#endif

/* Handle:   28,Name:                   ETAT_DAE_CPK,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxETAT_DAE_CPK(c) \
{ \
  IlEnterCriticalETAT_DAE_CPK(); \
  IS_DYN_DAE.IS_DYN_DAE.ETAT_DAE_CPK = (c); \
  IlLeaveCriticalETAT_DAE_CPK(); \
}
#endif

/* Handle:   31,Name:            ETAT_SECU_ANGLE_COL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxETAT_SECU_ANGLE_COL(c) \
{ \
  IlEnterCriticalETAT_SECU_ANGLE_COL(); \
  IS_DYN_DAE.IS_DYN_DAE.ETAT_SECU_ANGLE_COL = (c); \
  IlLeaveCriticalETAT_SECU_ANGLE_COL(); \
}
#endif



/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Access extern decl
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:                    CODE_DEFAUT,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxCODE_DEFAUT(vuint8 sigData);
#endif

/* Handle:    1,Name:              STATUS_CONFABSENT,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSTATUS_CONFABSENT(vuint32 sigData);
#endif

/* Handle:    2,Name:                 ETAT_ASSIST_DA,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxETAT_ASSIST_DA(vuint8 sigData);
#endif

/* Handle:    3,Name:                 ETAT_LIGNE_APC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxETAT_LIGNE_APC(vuint8 sigData);
#endif

/* Handle:    6,Name:                   Frame_Number,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFrame_Number(vuint8 sigData);
#endif

/* Handle:   29,Name:                  ANGLE_COLONNE,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxANGLE_COLONNE(vuint16 sigData);
#endif

/* Handle:   30,Name:                VITESSE_COLONNE,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxVITESSE_COLONNE(vuint16 sigData);
#endif

/* Handle:   32,Name:                    System_Code,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSystem_Code(vuint8 sigData);
#endif

/* Handle:   33,Name:                   Download_Day,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDownload_Day(vuint8 sigData);
#endif

/* Handle:   34,Name:                 Download_Month,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDownload_Month(vuint8 sigData);
#endif

/* Handle:   35,Name:                  Download_Year,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDownload_Year(vuint8 sigData);
#endif

/* Handle:   36,Name:               Application_Code,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxApplication_Code(vuint8 sigData);
#endif

/* Handle:   37,Name:               Software_Version,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSoftware_Version(vuint8 sigData);
#endif

/* Handle:   38,Name:           Software_Edition_MSB,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSoftware_Edition_MSB(vuint8 sigData);
#endif

/* Handle:   39,Name:           Software_Edition_LSB,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSoftware_Edition_LSB(vuint8 sigData);
#endif




#endif /* __IL_PAR_H__ */
