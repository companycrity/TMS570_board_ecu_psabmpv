/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DfltConfigData.c
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/* Version Control:
* %version:          EA3#41 %
* %derived_by:       fzh7xw %
*----------------------------------------------------------------------------------------------------------------------
* Date       Rev     Author   Change Description                                                                SCR #
* --------   ------  -------  -------------------------------------------------------------------------------  -------
* 02/14/14    1      OT       Initial Version
* 04/25/14    2      OT       Updated software release number (01.00.01) and boot compatibility number
* 05/21/14    3      OT       Updated software release number (01.01.00) and block version check
* 06/05/14    4      OT       Updated software release number (01.02.00) and block version check
* 06/10/14    5      OT       Updates for QAC errors
* 07/14/14    6      OT       Fix for QAC updates
* 08/13/14    7      OT       Updates for new bootloader                                                        12250
* 08/14/14    8      OT       Updated software release number (02.00.00)                                        12251
* 08/20/14    9      OT       Removed unused memmap section                                                     12249
* 09/10/14   10      OT       Updated software release number (02.00.01) and block version check                12253
* 09/22/14   11      OT       Updated software release number (02.00.02) and block version check                12264
* 10/07/14   12      OT       Added init block for new customer services, updated boot compatibility number     12363
* 10/10/14   13      OT       Updated software release number (02.00.03) and block version check                12268
* 10/23/14   14      OT       Added deprecated blocks for NvM safety update                                     12252
* 10/27/14   15      OT       Updated software release number (02.00.04) and block version check                12269
* 10/31/14   16      OT       Added deprecated blocks for NvM safety update correction                          12654
* 10/31/14   17      OT       Updated software release number (02.00.05) and block version check                12658
* 11/13/14   18      OT       Updated software release number (02.01.00) and block version check                12711
* 01/15/15   19      OT       Added deprecated block for CTC storage size correction                            12907
* 01/20/15   20      OT       Updated software release number (02.02.00) and block version check                12871
* 02/04/15   21      OT       Updated software release number (02.02.01)                                        12989
* 02/05/15   22      OT       Updated software release number (02.02.02) and block version check                12996
* 04/24/15   23      OT       Updated software release number (03.00.00), block version, and boot compatibility 13274
* 06/16/15   24      OT       Updated software release number (03.00.01) and block version check                13433
* 07/22/15   25      OT       Updated software release number (03.01.00) and block version check                13493
* 07/31/15   26      OT       Updated software release number (03.01.01) and block version check                EA3#2218
* 08/18/15   27      OT       Updated software release number (03.02.00) and block version check                EA3#2526
* 11/06/15   28      OT       Updated software release number (03.03.00), block version, and boot compat.       EA3#4396
* 11/24/15   29      OT       Updated software release number (03.03.01) and block version check                EA3#4835
* 12/15/15   30      OT       Updated software release number (03.04.00), block version, and boot compat.       EA3#5275
* 03/17/16   31      WH       Updated software release number (03.05.00), and manufacturing date                EA3#6855
* 04/06/16   32      WH       Updated software release number (03.05.01), and manufacturing date                EA3#7300
* 04/20/16   33      WH       Updated software release number (03.05.02), and manufacturing date                EA3#6639
* 05/23/16   34      WH       Updated software release number (04.00.00), block version and manufacturing date  EA3#8598
* 05/24/16   35      WH       Updated software release number (04.00.01) and manufacturing date                 EA3#8598
* 07/19/16   36      WH       Updated software release number (04.00.02), block version and manufacturing date  EA3#9706
* 07/19/16   37      WH       Updated software release number (04.00.03), block version and manufacturing date  EA3#7355
* 09/02/16   38      WH       Updated software release number (04.01.00), and manufacturing date                EA3#10700
* 09/15/16   39      WH       Updated software release number (04.02.00), and manufacturing date                EA3#10979
* 10/24/16   40      WH       Updated software release number (04.03.00), and manufacturing date                EA3#11902
* 10/25/16   41      WH       Updated software release number (04.03.01), manuf date, fix the ecustatus         EA3#11902
* 11/15/16   42      WH       Updated software release number (04.03.02), manuf date                            EA3#11902
*/


#define RTE_MICROSAR_PIM_EXPORT
#include "Ap_DfltConfigData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "Cd_NvMProxy.h"
#include "DiagSvc.h"


/* Select the release suffix based on the build type*/
#if defined(ENABLE_UTILIZATION_MONITOR)
    #define D_SUFFIX    "_U"
#elif defined(ENABLE_CPUUSE_METRICS)
    #define D_SUFFIX    "_T"
#elif defined(ENABLE_METRICS)
    #define D_SUFFIX    "_O"
#elif defined(SWEEPBUILD)
    #define D_SUFFIX    "_SWP1"
#else
    #define D_SUFFIX
#endif


#define D_BLOCKVERSIONCHECK_CNT_U16     22u
#define D_BOOTCOMPATIBILITY_CNT_U16     8u


/* Current Sw Release Number (from CM Synergy) - multiple strings are combined at compile time */
#pragma DATA_SECTION(k_SWRelNum_Cnt_u8,".SWRelNum");
CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[] = "PSA_BMPV_04.04.00" D_SUFFIX;

CONST(ECUManufacturingDateType_Str, DIAGSVC_CONST) D_MANUFDATEINIT_CNT_STR = { 15u,      /* Day   -> 1 to 31 */
                                                                               11u,     /* Month -> 1 to 12 */
                                                                               16u };   /* Year  -> 0 to 99 */


/* Set up headers for logical blocks */
#pragma DATA_SECTION(T_AppBlockHeader_Cnt_u16,".AppBlockHeader");
CONST(uint16, CDD_PARTNUMBER) T_AppBlockHeader_Cnt_u16[2u] = { D_BLOCKVERSIONCHECK_CNT_U16, D_BOOTCOMPATIBILITY_CNT_U16 };
#pragma DATA_SECTION(T_CalBlockHeader_Cnt_u16,".CalBlockHeader");
CONST(uint16, CDD_PARTNUMBER) T_CalBlockHeader_Cnt_u16[1u] = { D_BLOCKVERSIONCHECK_CNT_U16 };


/* Ecu Status for Bootloader */
#pragma DATA_SECTION(T_EcuStatus_Cnt_u08,".EcuStatus");
CONST(uint8, CDD_PARTNUMBER) T_EcuStatus_Cnt_u08[16u] = { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
                                                          0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu };


/* Initialized locally */
STATIC CONST(uint8, CDD_PARTNUMBER) T_InitNMEC_Cnt_u8 = 0xFEu; /* PRQA S 3218 */
STATIC CONST(uint8, CDD_PARTNUMBER) T_InitSystemPolarity_Cnt_b08[2u] = { 0x30u, 0x00u }; /* PRQA S 3218 */
STATIC CONST(float32, CDD_PARTNUMBER) T_InitTorqueCmdSF_Uls_f32 = 1.0f; /* PRQA S 3218 */


/* Initialized in driver */

CONST(PhaseCurrCal_DataType, AP_DFLTCONFIGDATA_CONST) T_ShCurrCalInit_Cnt_str =
                    { 53200.0f, 2.5f, 100.0f, 100.0f, 2.5f, 0.0f, 0.0f };

CONST(uint16, AP_DFLTCONFIGDATA_CONST) T_CogTrqCalInit_Cnt_u16[512] =
                      { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
                        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u };

CONST(uint16, AP_DFLTCONFIGDATA_CONST) T_CogTrqRplCompInit_Cnt_u16[9] =
                      { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u };

CONST(float32, AP_DFLTCONFIGDATA_CONST) T_TorqueCmdSFInit_Uls_f32 = 1.0f;

CONST(EOTLearned_DataType, AP_DFLTCONFIGDATA_CONST) T_LearnedEOTInit_Cnt_str =
                      { 0.0f, 0.0f, FALSE, FALSE };

CONST(AvgFricLrnType, AP_DFLTCONFIGDATA_CONST) T_AvgFricLrnDataInit_Cnt_str =
                      { 0.0f,
                        0.0f,
                        FALSE,
                        TRUE,
                        1u,
                        { {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u},
                          {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u} },
                        { {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f},
                          {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f},
                          {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f},
                          {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f} },
                        {0.0f, 0.0f, 0.0f, 0.0f} };


/* Deprecated blocks */
#define DFLTCONFIGDATA_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint8, NVM_APPL_DATA) Deprecated_CmMtrCurr_CurrTempOffset[98u];
VAR(uint8, NVM_APPL_DATA) Deprecated_AbsHwPos_EOLVehCntrOffset[10u];
VAR(uint8, NVM_APPL_DATA) Deprecated_Dem_NvData[60u];
#define DFLTCONFIGDATA_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */


/* Processing Functions */
FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void)
{
    VAR(NvM_RequestResultType, AUTOMATIC) BlockStatus = 0u;
    VAR(ManufModeType, AUTOMATIC) NxtrMEC_Uls_T_enum;
    
    /* Nexteer MEC */
    NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_NXTRMEC, &BlockStatus);
    if (BlockStatus != NVM_REQ_OK)
    {
        Nvm_NMEC_Cnt_u8 = T_InitNMEC_Cnt_u8;
    }
    
    EPS_DiagSrvcs_Init();
    
    /* Read MEC */
    NxtrMEC_Uls_T_enum = NxtrMEC_Uls_G_enum;
    
    /* The following section are block checks that require the MEC to be set in Manufacturing Mode */
    if (NxtrMEC_Uls_T_enum == ManufacturingMode )
    {
        
        /* EOL Polarity */
        NvM_GetErrorStatus((NvM_BlockIdType)Rte_NvmBlock_Polarity_Polarity_Cnt_Str, &BlockStatus);
        if (BlockStatus != NVM_REQ_OK)
        {
            NvMP_Rte_Polarity_Polarity_Cnt_Str[0u] = T_InitSystemPolarity_Cnt_b08[0u];
            NvMP_Rte_Polarity_Polarity_Cnt_Str[1u] = T_InitSystemPolarity_Cnt_b08[1u];
            (void)NvM_WriteBlock((NvM_BlockIdType)Rte_NvmBlock_Polarity_Polarity_Cnt_Str, NULL_PTR);
        }
        
        /* Torque Command Scale Factor */
        NvM_GetErrorStatus((NvM_BlockIdType)Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, &BlockStatus);
        if (BlockStatus != NVM_REQ_OK)
        {
            *((float32*)NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32) = T_InitTorqueCmdSF_Uls_f32; /* PRQA S 310 */
            (void)NvM_WriteBlock((NvM_BlockIdType)Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, NULL_PTR);
        }
        
    }
    
}


