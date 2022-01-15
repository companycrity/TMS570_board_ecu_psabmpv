/* -----------------------------------------------------------------------------
  Filename:    drv_par.c
  Description: Toolversion: 05.00.17.01.30.06.60.01.00.00
               
               Serial Number: CBD1300660
               Customer Info: Nexteer Automotive Corporation
                              Package: CBD Psa SLP4
                              Micro: 0812BPGEQQ1
                              Compiler: TexasInstruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyDriverBase
               
               Configuration   : C:\SynergyProjects\PSA_BMPV_EPS_TMS570-nzx5jd\PSA_BMPV_EPS_TMS570\Tools\AsrProject\Config\System\EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS0322
               
               Channel "Channel0":
                       Databasefile: C:\SynergyProjects\PSA_BMPV_EPS_TMS570-nzx5jd\PSA_BMPV_EPS_TMS570\Tools\AsrProject\Config\System\PSA_BMPV.dbc
                       Bussystem:    CAN
                       Manufacturer: PSA
                       Node:         PSCM

  Generated by , 2015-04-28  13:37:56
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

#include "v_inc.h"
#include "can_inc.h"

#include "drv_par.h"
/* -----------------------------------------------------------------------------
    &&&~ Message Buffers
 ----------------------------------------------------------------------------- */

/* RAM CATEGORY 2 START */
V_MEMRAM0 V_MEMRAM1 _c_IS_DAT_BSI_432_buf V_MEMRAM2 IS_DAT_BSI_432;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN2_CMM_348_buf V_MEMRAM2 IS_DYN2_CMM_348;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_CMM_208_buf V_MEMRAM2 IS_DYN_CMM_208;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_ABR_buf V_MEMRAM2 IS_DYN_ABR;
V_MEMRAM0 V_MEMRAM1 _c_IS_SUPV_DIRA_buf V_MEMRAM2 IS_SUPV_DIRA;
V_MEMRAM0 V_MEMRAM1 _c_IS_DAT_DIRA_buf V_MEMRAM2 IS_DAT_DIRA;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_DAE_buf V_MEMRAM2 IS_DYN_DAE;
V_MEMRAM0 V_MEMRAM1 _c_IS_VERS_DIRA_115_buf V_MEMRAM2 IS_VERS_DIRA_115;
V_MEMRAM0 V_MEMRAM1 _c_IS_RES_DIAG_ON_CAN_buf V_MEMRAM2 IS_RES_DIAG_ON_CAN;
V_MEMRAM0 V_MEMRAM1 _c_XCP_RES_buf V_MEMRAM2 XCP_RES;
V_MEMRAM0 V_MEMRAM1 _c_XCP_REQ_buf V_MEMRAM2 XCP_REQ;
V_MEMRAM0 V_MEMRAM1 _c_IS_DAT_BSI_412_buf V_MEMRAM2 IS_DAT_BSI_412;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_AAS_buf V_MEMRAM2 IS_DYN_AAS;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_VOL_buf V_MEMRAM2 IS_DYN_VOL;
V_MEMRAM0 V_MEMRAM1 _c_IS_DAT4_V2_BSI_552_buf V_MEMRAM2 IS_DAT4_V2_BSI_552;
V_MEMRAM0 V_MEMRAM1 _c_IS_DAT_BSI_3F2_buf V_MEMRAM2 IS_DAT_BSI_3F2;
V_MEMRAM0 V_MEMRAM1 _c_IS_INTE_ELECTRON_BSI_buf V_MEMRAM2 IS_INTE_ELECTRON_BSI;
V_MEMRAM0 V_MEMRAM1 _c_IS_DYN_CMM_388_buf V_MEMRAM2 IS_DYN_CMM_388;
V_MEMRAM0 V_MEMRAM1 _c_IS_ACQ_NEW_JDD_55F_buf V_MEMRAM2 IS_ACQ_NEW_JDD_55F;
V_MEMRAM0 V_MEMRAM1 _c_IS_EMIS_NEW_JDD_CAN_DIRA_buf V_MEMRAM2 IS_EMIS_NEW_JDD_CAN_DIRA;
V_MEMRAM0 V_MEMRAM1 _c_IS_ACQ_JDD_CAN_BSI_772_buf V_MEMRAM2 IS_ACQ_JDD_CAN_BSI_772;
/* RAM CATEGORY 2 END */





