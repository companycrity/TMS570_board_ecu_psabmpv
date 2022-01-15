/* -----------------------------------------------------------------------------
  Filename:    can_par.h
  Description: Toolversion: 05.00.17.01.30.06.60.01.00.00
               
               Serial Number: CBD1300660
               Customer Info: Nexteer Automotive Corporation
                              Package: CBD Psa SLP4
                              Micro: 0812BPGEQQ1
                              Compiler: TexasInstruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__base
               
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

  Generated by , 2016-05-11  14:35:32
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

#if !defined(__CAN_PAR_H__)
#define __CAN_PAR_H__

#include "can_cfg.h"
#include "v_inc.h"
#include "drv_par.h"

/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of callback functions
 ----------------------------------------------------------------------------- */

#if defined(C_MULTIPLE_RECEIVE_CHANNEL) || defined(C_SINGLE_RECEIVE_CHANNEL)
/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreTxISDATDIRA(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreTxISDYNDAE(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

#else
/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreTxISDATDIRA(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreTxISDYNDAE(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

#endif

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreRxISDAT4V2BSI552(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreRxISDATBSI(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpFuncPrecopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 XcpPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpPrecopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreRxISDYNABR(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreRxISDYNVOL(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 SrlComDriver_PreRxISDYNAAS(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */


/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of confirmation functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 1 START */
extern void XcpConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void TpDrvConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_TxISDATDIRA(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_TxISDYNDAE(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */



/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of indication functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 1 START */
extern void FaultLog_RxISACQJDDCANBSI772(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void FaultLog_RxISACQNEWJDD55F(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISDATBSI432(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISDATBSI412(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISDATBSI3F2(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISDYNCMM388(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISDYN2CMM(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISDYNCMM208(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SrlComDriver_RxISINTEELECTRONBSI(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void GliwaT1_MsgProcess_RxT1HostToTarget(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */





/* -----------------------------------------------------------------------------
    &&&~ Handles of send objects
 ----------------------------------------------------------------------------- */

#define CanTxXCP_RES                         0
#define CanTxXCP_REQ                         1
#define CanTxIS_SUPV_DIRA                    2
#define CanTxIS_EMIS_NEW_JDD_CAN_DIRA        3
#define CanTxIS_RES_DIAG_ON_CAN              4
#define CanTxIS_DAT_DIRA                     5
#define CanTxIS_DYN_DAE                      6
#define CanTxIS_VERS_DIRA_115                7


/* -----------------------------------------------------------------------------
    &&&~ Access to confirmation flags
 ----------------------------------------------------------------------------- */

#define IS_SUPV_DIRA_conf_b                  (CanConfirmationFlags.w[0].b0)
#define CanWriteSyncIS_SUPV_DIRA_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  IS_SUPV_DIRA_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define IS_EMIS_NEW_JDD_CAN_DIRA_conf_b      (CanConfirmationFlags.w[0].b1)
#define CanWriteSyncIS_EMIS_NEW_JDD_CAN_DIRA_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  IS_EMIS_NEW_JDD_CAN_DIRA_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define IS_DAT_DIRA_conf_b                   (CanConfirmationFlags.w[0].b2)
#define CanWriteSyncIS_DAT_DIRA_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  IS_DAT_DIRA_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define IS_DYN_DAE_conf_b                    (CanConfirmationFlags.w[0].b3)
#define CanWriteSyncIS_DYN_DAE_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  IS_DYN_DAE_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define IS_VERS_DIRA_115_conf_b              (CanConfirmationFlags.w[0].b4)
#define CanWriteSyncIS_VERS_DIRA_115_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  IS_VERS_DIRA_115_conf_b = (x); \
  CanEndFlagWriteSync(); \
}


/* -----------------------------------------------------------------------------
    &&&~ Handles of receive objects
 ----------------------------------------------------------------------------- */

#define CanRxIS_ACQ_JDD_CAN_BSI_772          0
#define CanRxIS_ACQ_NEW_JDD_55F              1
#define CanRxIS_DAT4_V2_BSI_552              2
#define CanRxIS_DAT_BSI_432                  3
#define CanRxIS_DAT_BSI_412                  4
#define CanRxIS_DAT_BSI_3F2                  5
#define CanRxIS_DYN_CMM_388                  6
#define CanRxIS_DYN2_CMM_348                 7
#define CanRxIS_DYN_CMM_208                  8
#define CanRxIS_INTE_ELECTRON_BSI            9
#define CanRxIS_DIAG_UDS_ON_CAN_7FF          10
#define CanRxXCP_RES                         11
#define CanRxXCP_REQ                         12
#define CanRxIS_REQ_DIAG_ON_CAN              13
#define CanRxIS_DYN_ABR                      14
#define CanRxIS_DYN_VOL                      15
#define CanRxIS_DYN_AAS                      16


/* -----------------------------------------------------------------------------
    &&&~ Access to signals
 ----------------------------------------------------------------------------- */

#define b_VITESSE_VEHICULE_ROUES_0_b         (IS_DYN_ABR.IS_DYN_ABR.VITESSE_VEHICULE_ROUES_0)
#define b_VITESSE_VEHICULE_ROUES_1_b         (IS_DYN_ABR.IS_DYN_ABR.VITESSE_VEHICULE_ROUES_1)
#define b_VITESSE_VEHICULE_ROUES_b           ((vuint16) (((vuint16) b_VITESSE_VEHICULE_ROUES_0_b) | (((vuint16) b_VITESSE_VEHICULE_ROUES_1_b) << 8)))
#define b_CHKSUM_TRME_DYN_UC_FREIN_b         (IS_DYN_ABR.IS_DYN_ABR.CHKSUM_TRME_DYN_UC_FREIN)
#define b_CPT_PROCESS_4B_UC_FREIN_b          (IS_DYN_ABR.IS_DYN_ABR.CPT_PROCESS_4B_UC_FREIN)
#define b_ANGLE_VOLANT_0_b                   (IS_DYN_VOL.IS_DYN_VOL.ANGLE_VOLANT_0)
#define b_ANGLE_VOLANT_1_b                   (IS_DYN_VOL.IS_DYN_VOL.ANGLE_VOLANT_1)
#define b_ANGLE_VOLANT_b                     ((vuint16) (((vuint16) b_ANGLE_VOLANT_0_b) | (((vuint16) b_ANGLE_VOLANT_1_b) << 8)))
#define b_VITESSE_ROT_VOL_c                  (IS_DYN_VOL.IS_DYN_VOL.VITESSE_ROT_VOL)
#define b_SENS_ROT_VOL_b                     (IS_DYN_VOL.IS_DYN_VOL.SENS_ROT_VOL)
#define b_CPT_PROCESS_4B_A_VOL_b             (IS_DYN_VOL.IS_DYN_VOL.CPT_PROCESS_4B_A_VOL)
#define b_CHKSUM_VOL_b                       (IS_DYN_VOL.IS_DYN_VOL.CHKSUM_VOL)
#define b_CONS_ANGLE_CPK_0_b                 (IS_DYN_AAS.IS_DYN_AAS.CONS_ANGLE_CPK_0)
#define b_CONS_ANGLE_CPK_1_b                 (IS_DYN_AAS.IS_DYN_AAS.CONS_ANGLE_CPK_1)
#define b_CONS_ANGLE_CPK_b                   ((vuint16) (((vuint16) b_CONS_ANGLE_CPK_0_b) | (((vuint16) b_CONS_ANGLE_CPK_1_b) << 8)))
#define b_DMD_RELAXE_CPK_b                   (IS_DYN_AAS.IS_DYN_AAS.DMD_RELAXE_CPK)
#define b_DMD_FCT_CPK_b                      (IS_DYN_AAS.IS_DYN_AAS.DMD_FCT_CPK)
#define b_CPT_PROCESS_4B_CPK_b               (IS_DYN_AAS.IS_DYN_AAS.CPT_PROCESS_4B_CPK)
#define b_CHKSUM_TRME_DYN_CPK_b              (IS_DYN_AAS.IS_DYN_AAS.CHKSUM_TRME_DYN_CPK)


/* -----------------------------------------------------------------------------
    &&&~ Access to data bytes of Rx messages
 ----------------------------------------------------------------------------- */

/* ID: 0x00000772, Handle: 0, IS_ACQ_JDD_CAN_BSI_772 [FC] */
#define c1_IS_ACQ_JDD_CAN_BSI_772_c          (IS_ACQ_JDD_CAN_BSI_772._c[0])

/* ID: 0x0000055f, Handle: 1, IS_ACQ_NEW_JDD_55F [FC] */
#define c1_IS_ACQ_NEW_JDD_55F_c              (IS_ACQ_NEW_JDD_55F._c[0])

/* ID: 0x00000552, Handle: 2, IS_DAT4_V2_BSI_552 [FC] */
#define c1_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[0])
#define c2_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[1])
#define c3_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[2])
#define c4_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[3])
#define c5_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[4])
#define c6_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[5])
#define c7_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[6])
#define c8_IS_DAT4_V2_BSI_552_c              (IS_DAT4_V2_BSI_552._c[7])

/* ID: 0x00000432, Handle: 3, IS_DAT_BSI_432 [FC] */
#define c1_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[0])
#define c2_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[1])
#define c3_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[2])
#define c4_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[3])
#define c5_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[4])
#define c6_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[5])
#define c7_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[6])
#define c8_IS_DAT_BSI_432_c                  (IS_DAT_BSI_432._c[7])

/* ID: 0x00000412, Handle: 4, IS_DAT_BSI_412 [FC] */
#define c1_IS_DAT_BSI_412_c                  (IS_DAT_BSI_412._c[0])

/* ID: 0x000003f2, Handle: 5, IS_DAT_BSI_3F2 [FC] */
#define c1_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[0])
#define c2_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[1])
#define c3_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[2])
#define c4_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[3])
#define c5_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[4])
#define c6_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[5])
#define c7_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[6])
#define c8_IS_DAT_BSI_3F2_c                  (IS_DAT_BSI_3F2._c[7])

/* ID: 0x00000388, Handle: 6, IS_DYN_CMM_388 [FC] */
#define c1_IS_DYN_CMM_388_c                  (IS_DYN_CMM_388._c[0])
#define c2_IS_DYN_CMM_388_c                  (IS_DYN_CMM_388._c[1])

/* ID: 0x00000348, Handle: 7, IS_DYN2_CMM_348 [FC] */
#define c1_IS_DYN2_CMM_348_c                 (IS_DYN2_CMM_348._c[0])
#define c2_IS_DYN2_CMM_348_c                 (IS_DYN2_CMM_348._c[1])
#define c3_IS_DYN2_CMM_348_c                 (IS_DYN2_CMM_348._c[2])
#define c4_IS_DYN2_CMM_348_c                 (IS_DYN2_CMM_348._c[3])
#define c5_IS_DYN2_CMM_348_c                 (IS_DYN2_CMM_348._c[4])
#define c6_IS_DYN2_CMM_348_c                 (IS_DYN2_CMM_348._c[5])

/* ID: 0x00000208, Handle: 8, IS_DYN_CMM_208 [FC] */
#define c1_IS_DYN_CMM_208_c                  (IS_DYN_CMM_208._c[0])
#define c2_IS_DYN_CMM_208_c                  (IS_DYN_CMM_208._c[1])
#define c3_IS_DYN_CMM_208_c                  (IS_DYN_CMM_208._c[2])
#define c4_IS_DYN_CMM_208_c                  (IS_DYN_CMM_208._c[3])
#define c5_IS_DYN_CMM_208_c                  (IS_DYN_CMM_208._c[4])

/* ID: 0x00000092, Handle: 9, IS_INTE_ELECTRON_BSI [FC] */
#define c1_IS_INTE_ELECTRON_BSI_c            (IS_INTE_ELECTRON_BSI._c[0])

/* ID: 0x000007b0, Handle: 11, XCP_RES [FC] */
#define c1_XCP_RES_c                         (XCP_RES._c[0])
#define c2_XCP_RES_c                         (XCP_RES._c[1])
#define c3_XCP_RES_c                         (XCP_RES._c[2])
#define c4_XCP_RES_c                         (XCP_RES._c[3])
#define c5_XCP_RES_c                         (XCP_RES._c[4])
#define c6_XCP_RES_c                         (XCP_RES._c[5])
#define c7_XCP_RES_c                         (XCP_RES._c[6])
#define c8_XCP_RES_c                         (XCP_RES._c[7])

/* ID: 0x000007ae, Handle: 12, XCP_REQ [FC] */
#define c1_XCP_REQ_c                         (XCP_REQ._c[0])
#define c2_XCP_REQ_c                         (XCP_REQ._c[1])
#define c3_XCP_REQ_c                         (XCP_REQ._c[2])
#define c4_XCP_REQ_c                         (XCP_REQ._c[3])
#define c5_XCP_REQ_c                         (XCP_REQ._c[4])
#define c6_XCP_REQ_c                         (XCP_REQ._c[5])
#define c7_XCP_REQ_c                         (XCP_REQ._c[6])
#define c8_XCP_REQ_c                         (XCP_REQ._c[7])

/* ID: 0x0000038d, Handle: 14, IS_DYN_ABR [FC] */
#define c1_IS_DYN_ABR_c                      (IS_DYN_ABR._c[0])
#define c2_IS_DYN_ABR_c                      (IS_DYN_ABR._c[1])
#define c3_IS_DYN_ABR_c                      (IS_DYN_ABR._c[2])
#define c4_IS_DYN_ABR_c                      (IS_DYN_ABR._c[3])
#define c5_IS_DYN_ABR_c                      (IS_DYN_ABR._c[4])
#define c6_IS_DYN_ABR_c                      (IS_DYN_ABR._c[5])

/* ID: 0x00000305, Handle: 15, IS_DYN_VOL [FC] */
#define c1_IS_DYN_VOL_c                      (IS_DYN_VOL._c[0])
#define c2_IS_DYN_VOL_c                      (IS_DYN_VOL._c[1])
#define c3_IS_DYN_VOL_c                      (IS_DYN_VOL._c[2])
#define c4_IS_DYN_VOL_c                      (IS_DYN_VOL._c[3])
#define c5_IS_DYN_VOL_c                      (IS_DYN_VOL._c[4])

/* ID: 0x000002eb, Handle: 16, IS_DYN_AAS [FC] */
#define c1_IS_DYN_AAS_c                      (IS_DYN_AAS._c[0])
#define c2_IS_DYN_AAS_c                      (IS_DYN_AAS._c[1])
#define c3_IS_DYN_AAS_c                      (IS_DYN_AAS._c[2])
#define c4_IS_DYN_AAS_c                      (IS_DYN_AAS._c[3])



/* -----------------------------------------------------------------------------
    &&&~ Access to data bytes of Tx messages
 ----------------------------------------------------------------------------- */

/* ID: 0x00000795, Handle: 2, IS_SUPV_DIRA [FC] */
#define c1_IS_SUPV_DIRA_c                    (IS_SUPV_DIRA._c[0])
#define c2_IS_SUPV_DIRA_c                    (IS_SUPV_DIRA._c[1])
#define c3_IS_SUPV_DIRA_c                    (IS_SUPV_DIRA._c[2])
#define c4_IS_SUPV_DIRA_c                    (IS_SUPV_DIRA._c[3])
#define c5_IS_SUPV_DIRA_c                    (IS_SUPV_DIRA._c[4])
#define c6_IS_SUPV_DIRA_c                    (IS_SUPV_DIRA._c[5])

/* ID: 0x00000775, Handle: 3, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */
#define c1_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[0])
#define c2_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[1])
#define c3_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[2])
#define c4_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[3])
#define c5_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[4])
#define c6_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[5])
#define c7_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[6])
#define c8_IS_EMIS_NEW_JDD_CAN_DIRA_c        (IS_EMIS_NEW_JDD_CAN_DIRA._c[7])

/* ID: 0x00000695, Handle: 4, IS_RES_DIAG_ON_CAN [FC] */
#define c1_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[0])
#define c2_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[1])
#define c3_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[2])
#define c4_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[3])
#define c5_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[4])
#define c6_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[5])
#define c7_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[6])
#define c8_IS_RES_DIAG_ON_CAN_c              (IS_RES_DIAG_ON_CAN._c[7])

/* ID: 0x00000495, Handle: 5, IS_DAT_DIRA [FC] */
#define c1_IS_DAT_DIRA_c                     (IS_DAT_DIRA._c[0])
#define c2_IS_DAT_DIRA_c                     (IS_DAT_DIRA._c[1])
#define c3_IS_DAT_DIRA_c                     (IS_DAT_DIRA._c[2])
#define c4_IS_DAT_DIRA_c                     (IS_DAT_DIRA._c[3])

/* ID: 0x000002f5, Handle: 6, IS_DYN_DAE [FC] */
#define c1_IS_DYN_DAE_c                      (IS_DYN_DAE._c[0])
#define c2_IS_DYN_DAE_c                      (IS_DYN_DAE._c[1])
#define c3_IS_DYN_DAE_c                      (IS_DYN_DAE._c[2])
#define c4_IS_DYN_DAE_c                      (IS_DYN_DAE._c[3])
#define c5_IS_DYN_DAE_c                      (IS_DYN_DAE._c[4])
#define c6_IS_DYN_DAE_c                      (IS_DYN_DAE._c[5])
#define c7_IS_DYN_DAE_c                      (IS_DYN_DAE._c[6])

/* ID: 0x00000115, Handle: 7, IS_VERS_DIRA_115 [FC] */
#define c1_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[0])
#define c2_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[1])
#define c3_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[2])
#define c4_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[3])
#define c5_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[4])
#define c6_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[5])
#define c7_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[6])
#define c8_IS_VERS_DIRA_115_c                (IS_VERS_DIRA_115._c[7])



/* -----------------------------------------------------------------------------
    &&&~ RDS Access
 ----------------------------------------------------------------------------- */

typedef struct _c_IS_VERS_DIRA_115_RDS_msgTypeTag
{
  vbittype System_Code : 8;
  vbittype Download_Day : 8;
  vbittype Download_Month : 8;
  vbittype Download_Year : 8;
  vbittype Application_Code : 8;
  vbittype Software_Version : 8;
  vbittype Software_Edition_MSB : 8;
  vbittype Software_Edition_LSB : 8;
} _c_IS_VERS_DIRA_115_RDS_msgType;

typedef struct _c_IS_DYN_DAE_RDS_msgTypeTag
{
  vbittype CHKSUM_TRME_DYN_DAE : 4;
  vbittype CPT_PROCESS_4B_DAE : 4;
  vbittype CPLE_VOLANT_OPTMSE : 8;
  vbittype unused0 : 1;
  vbittype ETAT_DAE_CPK : 2;
  vbittype CAUSE_DESACTIV_CPK : 3;
  vbittype unused1 : 2;
  vbittype ANGLE_COLONNE_1 : 8;
  vbittype ANGLE_COLONNE_0 : 8;
  vbittype VITESSE_COLONNE_1 : 8;
  vbittype VITESSE_COLONNE_0 : 4;
  vbittype unused2 : 3;
  vbittype ETAT_SECU_ANGLE_COL : 1;
} _c_IS_DYN_DAE_RDS_msgType;

typedef struct _c_IS_DAT_DIRA_RDS_msgTypeTag
{
  vbittype CPLE_VOLANT : 8;
  vbittype ETAT_DA_2010 : 2;
  vbittype ETAT_DA_DYN : 2;
  vbittype unused0 : 2;
  vbittype ETAT_DA_2004 : 2;
  vbittype DDE_REDEM_DA : 1;
  vbittype unused1 : 1;
  vbittype AUTOR_ARRET_MOT_DA : 1;
  vbittype EPS_STATE_LKA : 3;
  vbittype STEERWHL_HOLD_BY_DRV : 1;
  vbittype TRQ_LIMIT_STATE : 1;
  vbittype unused2 : 8;
} _c_IS_DAT_DIRA_RDS_msgType;

typedef struct _c_IS_RES_DIAG_ON_CAN_RDS_msgTypeTag
{
  vbittype Diagnostic_Data_Res_7 : 8;
  vbittype Diagnostic_Data_Res_6 : 8;
  vbittype Diagnostic_Data_Res_5 : 8;
  vbittype Diagnostic_Data_Res_4 : 8;
  vbittype Diagnostic_Data_Res_3 : 8;
  vbittype Diagnostic_Data_Res_2 : 8;
  vbittype Diagnostic_Data_Res_1 : 8;
  vbittype Diagnostic_Data_Res_0 : 8;
} _c_IS_RES_DIAG_ON_CAN_RDS_msgType;

typedef struct _c_IS_EMIS_NEW_JDD_CAN_DIRA_RDS_msgTypeTag
{
  vbittype Number_of_Frames : 2;
  vbittype Frame_Number : 2;
  vbittype DTC_State : 1;
  vbittype unused0 : 1;
  vbittype Type_of_Message : 2;
  vbittype JDD_Byte1 : 8;
  vbittype JDD_Byte2 : 8;
  vbittype JDD_Byte3 : 8;
  vbittype JDD_Byte4 : 8;
  vbittype JDD_Byte5 : 8;
  vbittype JDD_Byte6 : 8;
  vbittype JDD_Byte7 : 8;
} _c_IS_EMIS_NEW_JDD_CAN_DIRA_RDS_msgType;

typedef struct _c_IS_SUPV_DIRA_RDS_msgTypeTag
{
  vbittype CODE_DEFAUT : 8;
  vbittype STATUS_CONFABSENT_3 : 8;
  vbittype STATUS_CONFABSENT_2 : 8;
  vbittype STATUS_CONFABSENT_1 : 8;
  vbittype STATUS_CONFABSENT_0 : 8;
  vbittype ETAT_LIGNE_APC : 1;
  vbittype ETAT_ASSIST_DA : 3;
  vbittype unused0 : 4;
} _c_IS_SUPV_DIRA_RDS_msgType;

typedef struct _c_XCP_REQ_RDS_msgTypeTag
{
  vbittype XCP_Data_Req_7 : 8;
  vbittype XCP_Data_Req_6 : 8;
  vbittype XCP_Data_Req_5 : 8;
  vbittype XCP_Data_Req_4 : 8;
  vbittype XCP_Data_Req_3 : 8;
  vbittype XCP_Data_Req_2 : 8;
  vbittype XCP_Data_Req_1 : 8;
  vbittype XCP_Data_Req_0 : 8;
} _c_XCP_REQ_RDS_msgType;

typedef struct _c_XCP_RES_RDS_msgTypeTag
{
  vbittype XCP_Data_Res_7 : 8;
  vbittype XCP_Data_Res_6 : 8;
  vbittype XCP_Data_Res_5 : 8;
  vbittype XCP_Data_Res_4 : 8;
  vbittype XCP_Data_Res_3 : 8;
  vbittype XCP_Data_Res_2 : 8;
  vbittype XCP_Data_Res_1 : 8;
  vbittype XCP_Data_Res_0 : 8;
} _c_XCP_RES_RDS_msgType;

typedef struct _c_IS_DIAG_UDS_ON_CAN_7FF_RDS_msgTypeTag
{
  vbittype Diagnostic_Func_Req_7 : 8;
  vbittype Diagnostic_Func_Req_6 : 8;
  vbittype Diagnostic_Func_Req_5 : 8;
  vbittype Diagnostic_Func_Req_4 : 8;
  vbittype Diagnostic_Func_Req_3 : 8;
  vbittype Diagnostic_Func_Req_2 : 8;
  vbittype Diagnostic_Func_Req_1 : 8;
  vbittype Diagnostic_Func_Req_0 : 8;
} _c_IS_DIAG_UDS_ON_CAN_7FF_RDS_msgType;

typedef struct _c_IS_ACQ_JDD_CAN_BSI_772_RDS_msgTypeTag
{
  vbittype DATA_ACQ_JDD_BSI : 8;
} _c_IS_ACQ_JDD_CAN_BSI_772_RDS_msgType;

typedef struct _c_IS_REQ_DIAG_ON_CAN_RDS_msgTypeTag
{
  vbittype Diagnostic_Data_Req_7 : 8;
  vbittype Diagnostic_Data_Req_6 : 8;
  vbittype Diagnostic_Data_Req_5 : 8;
  vbittype Diagnostic_Data_Req_4 : 8;
  vbittype Diagnostic_Data_Req_3 : 8;
  vbittype Diagnostic_Data_Req_2 : 8;
  vbittype Diagnostic_Data_Req_1 : 8;
  vbittype Diagnostic_Data_Req_0 : 8;
} _c_IS_REQ_DIAG_ON_CAN_RDS_msgType;

typedef struct _c_IS_ACQ_NEW_JDD_55F_RDS_msgTypeTag
{
  vbittype DATA_ACQ_JDD_BSI_2 : 8;
} _c_IS_ACQ_NEW_JDD_55F_RDS_msgType;

typedef struct _c_IS_DAT4_V2_BSI_552_RDS_msgTypeTag
{
  vbittype Msg552_Byte0 : 8;
  vbittype Msg552_Byte1 : 8;
  vbittype Msg552_Byte2 : 8;
  vbittype Msg552_Byte3 : 8;
  vbittype Msg552_Byte4 : 8;
  vbittype Msg552_Byte5 : 8;
  vbittype Msg552_Byte6 : 8;
  vbittype Msg552_Byte7 : 8;
} _c_IS_DAT4_V2_BSI_552_RDS_msgType;

typedef struct _c_IS_DAT_BSI_432_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
  vbittype unused6 : 1;
  vbittype Shunt_Position : 2;
  vbittype Power_Supplies : 3;
  vbittype ETAT_PRINCIP_SEV : 2;
  vbittype ETAT_RESEAU_ELEC : 4;
  vbittype unused7 : 4;
} _c_IS_DAT_BSI_432_RDS_msgType;

typedef struct _c_IS_DAT_BSI_412_RDS_msgTypeTag
{
  vbittype unused0 : 5;
  vbittype MARCHE_AR_BVM : 1;
  vbittype unused1 : 2;
} _c_IS_DAT_BSI_412_RDS_msgType;

typedef struct _c_IS_DAT_BSI_3F2_RDS_msgTypeTag
{
  vbittype unused0 : 5;
  vbittype DMD_DELEST_DA : 1;
  vbittype unused1 : 2;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 3;
  vbittype LKA_STATE : 3;
  vbittype unused6 : 2;
  vbittype LKA_TRQ_FACT_REQ : 7;
  vbittype LXA_ACTIVATION : 1;
  vbittype COLUMN_ANGLE_SETPOINT_1 : 8;
  vbittype COLUMN_ANGLE_SETPOINT_0 : 6;
  vbittype unused7 : 2;
} _c_IS_DAT_BSI_3F2_RDS_msgType;

#define b_CAN_VITESSE_VEHICULE_ROUES_0_b     (RDS23.IS_DYN_ABR.VITESSE_VEHICULE_ROUES_0)
#define b_CAN_VITESSE_VEHICULE_ROUES_1_b     (RDS23.IS_DYN_ABR.VITESSE_VEHICULE_ROUES_1)
#define b_CAN_VITESSE_VEHICULE_ROUES_b       ((vuint16) (((vuint16) b_CAN_VITESSE_VEHICULE_ROUES_0_b) | (((vuint16) b_CAN_VITESSE_VEHICULE_ROUES_1_b) << 8)))
#define b_CAN_CHKSUM_TRME_DYN_UC_FREIN_b     (RDS23.IS_DYN_ABR.CHKSUM_TRME_DYN_UC_FREIN)
#define b_CAN_CPT_PROCESS_4B_UC_FREIN_b      (RDS23.IS_DYN_ABR.CPT_PROCESS_4B_UC_FREIN)

typedef struct _c_IS_DYN_ABR_RDS_msgTypeTag
{
  vbittype VITESSE_VEHICULE_ROUES_1 : 8;
  vbittype VITESSE_VEHICULE_ROUES_0 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype CPT_PROCESS_4B_UC_FREIN : 4;
  vbittype CHKSUM_TRME_DYN_UC_FREIN : 4;
} _c_IS_DYN_ABR_RDS_msgType;

typedef struct _c_IS_DYN_CMM_388_RDS_msgTypeTag
{
  vbittype VITESSE_VEHICLE_BV_1 : 8;
  vbittype VITESSE_VEHICLE_BV_0 : 8;
} _c_IS_DYN_CMM_388_RDS_msgType;

typedef struct _c_IS_DYN2_CMM_348_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 4;
  vbittype ETAT_MT : 4;
} _c_IS_DYN2_CMM_348_RDS_msgType;

#define b_CAN_ANGLE_VOLANT_0_b               (RDS26.IS_DYN_VOL.ANGLE_VOLANT_0)
#define b_CAN_ANGLE_VOLANT_1_b               (RDS26.IS_DYN_VOL.ANGLE_VOLANT_1)
#define b_CAN_ANGLE_VOLANT_b                 ((vuint16) (((vuint16) b_CAN_ANGLE_VOLANT_0_b) | (((vuint16) b_CAN_ANGLE_VOLANT_1_b) << 8)))
#define b_CAN_VITESSE_ROT_VOL_c              (RDS26.IS_DYN_VOL.VITESSE_ROT_VOL)
#define b_CAN_SENS_ROT_VOL_b                 (RDS26.IS_DYN_VOL.SENS_ROT_VOL)
#define b_CAN_CPT_PROCESS_4B_A_VOL_b         (RDS26.IS_DYN_VOL.CPT_PROCESS_4B_A_VOL)
#define b_CAN_CHKSUM_VOL_b                   (RDS26.IS_DYN_VOL.CHKSUM_VOL)

typedef struct _c_IS_DYN_VOL_RDS_msgTypeTag
{
  vbittype ANGLE_VOLANT_1 : 8;
  vbittype ANGLE_VOLANT_0 : 8;
  vbittype VITESSE_ROT_VOL : 8;
  vbittype SENS_ROT_VOL : 1;
  vbittype unused0 : 7;
  vbittype CHKSUM_VOL : 4;
  vbittype CPT_PROCESS_4B_A_VOL : 4;
} _c_IS_DYN_VOL_RDS_msgType;

#define b_CAN_CONS_ANGLE_CPK_0_b             (RDS27.IS_DYN_AAS.CONS_ANGLE_CPK_0)
#define b_CAN_CONS_ANGLE_CPK_1_b             (RDS27.IS_DYN_AAS.CONS_ANGLE_CPK_1)
#define b_CAN_CONS_ANGLE_CPK_b               ((vuint16) (((vuint16) b_CAN_CONS_ANGLE_CPK_0_b) | (((vuint16) b_CAN_CONS_ANGLE_CPK_1_b) << 8)))
#define b_CAN_DMD_RELAXE_CPK_b               (RDS27.IS_DYN_AAS.DMD_RELAXE_CPK)
#define b_CAN_DMD_FCT_CPK_b                  (RDS27.IS_DYN_AAS.DMD_FCT_CPK)
#define b_CAN_CPT_PROCESS_4B_CPK_b           (RDS27.IS_DYN_AAS.CPT_PROCESS_4B_CPK)
#define b_CAN_CHKSUM_TRME_DYN_CPK_b          (RDS27.IS_DYN_AAS.CHKSUM_TRME_DYN_CPK)

typedef struct _c_IS_DYN_AAS_RDS_msgTypeTag
{
  vbittype CONS_ANGLE_CPK_1 : 8;
  vbittype CONS_ANGLE_CPK_0 : 8;
  vbittype DMD_FCT_CPK : 2;
  vbittype DMD_RELAXE_CPK : 2;
  vbittype unused0 : 4;
  vbittype CHKSUM_TRME_DYN_CPK : 4;
  vbittype CPT_PROCESS_4B_CPK : 4;
} _c_IS_DYN_AAS_RDS_msgType;

typedef struct _c_IS_DYN_CMM_208_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 1;
  vbittype DIAG_MUX_ON : 1;
  vbittype unused5 : 6;
} _c_IS_DYN_CMM_208_RDS_msgType;

typedef struct _c_IS_INTE_ELECTRON_BSI_RDS_msgTypeTag
{
  vbittype DIAG_INTEGRA_ELEC : 1;
  vbittype MODE_DIAG : 1;
  vbittype unused0 : 5;
  vbittype EFFAC_DEFAULT_DIAG : 1;
} _c_IS_INTE_ELECTRON_BSI_RDS_msgType;

typedef union _c_RDS0_bufTag
{
  vuint8 _c[8];
  _c_IS_VERS_DIRA_115_RDS_msgType IS_VERS_DIRA_115;
} _c_RDS0_buf;
typedef union _c_RDS1_bufTag
{
  vuint8 _c[7];
  _c_IS_DYN_DAE_RDS_msgType IS_DYN_DAE;
} _c_RDS1_buf;
typedef union _c_RDS2_bufTag
{
  vuint8 _c[4];
  _c_IS_DAT_DIRA_RDS_msgType IS_DAT_DIRA;
} _c_RDS2_buf;
typedef union _c_RDS3_bufTag
{
  vuint8 _c[8];
  _c_IS_RES_DIAG_ON_CAN_RDS_msgType IS_RES_DIAG_ON_CAN;
} _c_RDS3_buf;
typedef union _c_RDS4_bufTag
{
  vuint8 _c[8];
  _c_IS_EMIS_NEW_JDD_CAN_DIRA_RDS_msgType IS_EMIS_NEW_JDD_CAN_DIRA;
} _c_RDS4_buf;
typedef union _c_RDS5_bufTag
{
  vuint8 _c[6];
  _c_IS_SUPV_DIRA_RDS_msgType IS_SUPV_DIRA;
} _c_RDS5_buf;
typedef union _c_RDS6_bufTag
{
  vuint8 _c[8];
  _c_XCP_REQ_RDS_msgType XCP_REQ;
} _c_RDS6_buf;
typedef union _c_RDS7_bufTag
{
  vuint8 _c[8];
  _c_XCP_RES_RDS_msgType XCP_RES;
} _c_RDS7_buf;
typedef union _c_RDS13_bufTag
{
  vuint8 _c[8];
  _c_IS_DIAG_UDS_ON_CAN_7FF_RDS_msgType IS_DIAG_UDS_ON_CAN_7FF;
} _c_RDS13_buf;
typedef union _c_RDS14_bufTag
{
  vuint8 _c[8];
  _c_XCP_RES_RDS_msgType XCP_RES;
} _c_RDS14_buf;
typedef union _c_RDS15_bufTag
{
  vuint8 _c[8];
  _c_XCP_REQ_RDS_msgType XCP_REQ;
} _c_RDS15_buf;
typedef union _c_RDS16_bufTag
{
  vuint8 _c[1];
  _c_IS_ACQ_JDD_CAN_BSI_772_RDS_msgType IS_ACQ_JDD_CAN_BSI_772;
} _c_RDS16_buf;
typedef union _c_RDS17_bufTag
{
  vuint8 _c[8];
  _c_IS_REQ_DIAG_ON_CAN_RDS_msgType IS_REQ_DIAG_ON_CAN;
} _c_RDS17_buf;
typedef union _c_RDS18_bufTag
{
  vuint8 _c[1];
  _c_IS_ACQ_NEW_JDD_55F_RDS_msgType IS_ACQ_NEW_JDD_55F;
} _c_RDS18_buf;
typedef union _c_RDS19_bufTag
{
  vuint8 _c[8];
  _c_IS_DAT4_V2_BSI_552_RDS_msgType IS_DAT4_V2_BSI_552;
} _c_RDS19_buf;
typedef union _c_RDS20_bufTag
{
  vuint8 _c[8];
  _c_IS_DAT_BSI_432_RDS_msgType IS_DAT_BSI_432;
} _c_RDS20_buf;
typedef union _c_RDS21_bufTag
{
  vuint8 _c[1];
  _c_IS_DAT_BSI_412_RDS_msgType IS_DAT_BSI_412;
} _c_RDS21_buf;
typedef union _c_RDS22_bufTag
{
  vuint8 _c[8];
  _c_IS_DAT_BSI_3F2_RDS_msgType IS_DAT_BSI_3F2;
} _c_RDS22_buf;
typedef union _c_RDS23_bufTag
{
  vuint8 _c[6];
  _c_IS_DYN_ABR_RDS_msgType IS_DYN_ABR;
} _c_RDS23_buf;
typedef union _c_RDS24_bufTag
{
  vuint8 _c[2];
  _c_IS_DYN_CMM_388_RDS_msgType IS_DYN_CMM_388;
} _c_RDS24_buf;
typedef union _c_RDS25_bufTag
{
  vuint8 _c[6];
  _c_IS_DYN2_CMM_348_RDS_msgType IS_DYN2_CMM_348;
} _c_RDS25_buf;
typedef union _c_RDS26_bufTag
{
  vuint8 _c[5];
  _c_IS_DYN_VOL_RDS_msgType IS_DYN_VOL;
} _c_RDS26_buf;
typedef union _c_RDS27_bufTag
{
  vuint8 _c[4];
  _c_IS_DYN_AAS_RDS_msgType IS_DYN_AAS;
} _c_RDS27_buf;
typedef union _c_RDS28_bufTag
{
  vuint8 _c[5];
  _c_IS_DYN_CMM_208_RDS_msgType IS_DYN_CMM_208;
} _c_RDS28_buf;
typedef union _c_RDS29_bufTag
{
  vuint8 _c[1];
  _c_IS_INTE_ELECTRON_BSI_RDS_msgType IS_INTE_ELECTRON_BSI;
} _c_RDS29_buf;


#define RDS0                                 ((* ((_c_RDS0_buf MEMORY_NORMAL *)(canRDSTxPtr[0]))))
#define RDS1                                 ((* ((_c_RDS1_buf MEMORY_NORMAL *)(canRDSTxPtr[1]))))
#define RDS2                                 ((* ((_c_RDS2_buf MEMORY_NORMAL *)(canRDSTxPtr[2]))))
#define RDS3                                 ((* ((_c_RDS3_buf MEMORY_NORMAL *)(canRDSTxPtr[3]))))
#define RDS4                                 ((* ((_c_RDS4_buf MEMORY_NORMAL *)(canRDSTxPtr[4]))))
#define RDS5                                 ((* ((_c_RDS5_buf MEMORY_NORMAL *)(canRDSTxPtr[5]))))
#define RDS6                                 ((* ((_c_RDS6_buf MEMORY_NORMAL *)(canRDSTxPtr[6]))))
#define RDS7                                 ((* ((_c_RDS7_buf MEMORY_NORMAL *)(canRDSTxPtr[7]))))
#define RDS13                                ((* ((_c_RDS13_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS14                                ((* ((_c_RDS14_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS15                                ((* ((_c_RDS15_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS16                                ((* ((_c_RDS16_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS17                                ((* ((_c_RDS17_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS18                                ((* ((_c_RDS18_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS19                                ((* ((_c_RDS19_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS20                                ((* ((_c_RDS20_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS21                                ((* ((_c_RDS21_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS22                                ((* ((_c_RDS22_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS23                                ((* ((_c_RDS23_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS24                                ((* ((_c_RDS24_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS25                                ((* ((_c_RDS25_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS26                                ((* ((_c_RDS26_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS27                                ((* ((_c_RDS27_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS28                                ((* ((_c_RDS28_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS29                                ((* ((_c_RDS29_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))



/* -----------------------------------------------------------------------------
    &&&~ Message Hardware Objects
 ----------------------------------------------------------------------------- */

#define CanTxIS_VERS_DIRA_115_HW_OBJ         0
#define CanTxIS_VERS_DIRA_115_HW_CHANNEL     0
#define CanTxIS_DYN_DAE_HW_OBJ               1
#define CanTxIS_DYN_DAE_HW_CHANNEL           0
#define CanTxIS_DAT_DIRA_HW_OBJ              2
#define CanTxIS_DAT_DIRA_HW_CHANNEL          0
#define CanTxIS_RES_DIAG_ON_CAN_HW_OBJ       3
#define CanTxIS_RES_DIAG_ON_CAN_HW_CHANNEL   0
#define CanTxIS_EMIS_NEW_JDD_CAN_DIRA_HW_OBJ 4
#define CanTxIS_EMIS_NEW_JDD_CAN_DIRA_HW_CHANNEL 0
#define CanTxIS_SUPV_DIRA_HW_OBJ             5
#define CanTxIS_SUPV_DIRA_HW_CHANNEL         0
#define CanTxXCP_REQ_HW_OBJ                  6
#define CanTxXCP_REQ_HW_CHANNEL              0
#define CanTxXCP_RES_HW_OBJ                  7
#define CanTxXCP_RES_HW_CHANNEL              0
#define C_TX_NORMAL_HW_OBJ                   8
#define C_TX_NORMAL_HW_CHANNEL               0
#define CanRxIS_DIAG_UDS_ON_CAN_7FF_HW_OBJ   13
#define CanRxIS_DIAG_UDS_ON_CAN_7FF_HW_CHANNEL 0
#define CanRxXCP_RES_HW_OBJ                  14
#define CanRxXCP_RES_HW_CHANNEL              0
#define CanRxXCP_REQ_HW_OBJ                  15
#define CanRxXCP_REQ_HW_CHANNEL              0
#define CanRxIS_ACQ_JDD_CAN_BSI_772_HW_OBJ   16
#define CanRxIS_ACQ_JDD_CAN_BSI_772_HW_CHANNEL 0
#define CanRxIS_REQ_DIAG_ON_CAN_HW_OBJ       17
#define CanRxIS_REQ_DIAG_ON_CAN_HW_CHANNEL   0
#define CanRxIS_ACQ_NEW_JDD_55F_HW_OBJ       18
#define CanRxIS_ACQ_NEW_JDD_55F_HW_CHANNEL   0
#define CanRxIS_DAT4_V2_BSI_552_HW_OBJ       19
#define CanRxIS_DAT4_V2_BSI_552_HW_CHANNEL   0
#define CanRxIS_DAT_BSI_432_HW_OBJ           20
#define CanRxIS_DAT_BSI_432_HW_CHANNEL       0
#define CanRxIS_DAT_BSI_412_HW_OBJ           21
#define CanRxIS_DAT_BSI_412_HW_CHANNEL       0
#define CanRxIS_DAT_BSI_3F2_HW_OBJ           22
#define CanRxIS_DAT_BSI_3F2_HW_CHANNEL       0
#define CanRxIS_DYN_ABR_HW_OBJ               23
#define CanRxIS_DYN_ABR_HW_CHANNEL           0
#define CanRxIS_DYN_CMM_388_HW_OBJ           24
#define CanRxIS_DYN_CMM_388_HW_CHANNEL       0
#define CanRxIS_DYN2_CMM_348_HW_OBJ          25
#define CanRxIS_DYN2_CMM_348_HW_CHANNEL      0
#define CanRxIS_DYN_VOL_HW_OBJ               26
#define CanRxIS_DYN_VOL_HW_CHANNEL           0
#define CanRxIS_DYN_AAS_HW_OBJ               27
#define CanRxIS_DYN_AAS_HW_CHANNEL           0
#define CanRxIS_DYN_CMM_208_HW_OBJ           28
#define CanRxIS_DYN_CMM_208_HW_CHANNEL       0
#define CanRxIS_INTE_ELECTRON_BSI_HW_OBJ     29
#define CanRxIS_INTE_ELECTRON_BSI_HW_CHANNEL 0
#define C_BASIC0_HW_OBJ                      30
#define C_BASIC0_HW_CHANNEL                  0





#endif /* __CAN_PAR_H__ */