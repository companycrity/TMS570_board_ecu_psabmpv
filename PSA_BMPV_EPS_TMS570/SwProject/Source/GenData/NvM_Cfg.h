/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2010 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  NvM_Cfg.h
 *    Component:  MemService_AsrNvM
 *       Module:  NvM - Submodule Cfg (configuration)
 *    Generator:  -
 *
 *  Description:  Configuration Header File.
 *                Contains Public configuration data, affecting API, and which may be accessed by applications
 *  -------------------------------------------------------------------------------------------------------------------
 *  GENERATION INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *     Project:    EPS.ecuc
 *   Generated:  2016-05-20 04:51 pm
 *    Licensee:   Nexteer Automotive Corporation (2502600608)
 
    This file is generated by DaVinci Configurator Pro - DAVINCICFG.EXE V4.0.67.0.
    Do not modify this file, otherwise the software may behave in unexpected way.
 *********************************************************************************************************************/

/* Do not modify the following parts. */
/* Modification is only allowed in the described parts */

/**********************************************************************************************************************
 * API CFG DEFINES
 *********************************************************************************************************************/

/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * API RELEVANT (PUBLIC) SECTION OF CONFIGURATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (3u)
#define NVM_CFG_MINOR_VERSION    (7u)
#define NVM_CFG_PATCH_VERSION    (1u)

/**********************************************************************************************************************
 * API CFG MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/

#include "Rte_Type.h"
#define NVM_RTE_INCLUDED STD_ON


#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/

/* Type for an the additional published parameter Compiled Configuration ID
 * (see CompiledConfigurationId in NvM.h)
 */
/* Compiled Config Id Type */
typedef union
{
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;


/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/

/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT /*<NVM_DEV_ERROR_DETECT/>*/ (STD_ON)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION        /*<NVM_DYNAMIC_CONFIGURATION/>*/ (STD_ON)

#define NVM_API_CONFIG_CLASS_1  (1u)
#define NVM_API_CONFIG_CLASS_2  (3u)
#define NVM_API_CONFIG_CLASS_3  (7u)

#define NVM_API_CONFIG_CLASS /*<NVM_API_CONFIG_CLASS/>*/ (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION /*<NVM_JOB_PRIORISATION/>*/ STD_OFF


/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID /*<NVM_COMPILED_CONFIG_ID/>*/ (1u)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH    /*<NVM_DRV_MODE_SWITCH/>*/ (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE    /*<NVM_POLLING_MODE/>*/ (STD_ON)

/* switch for enabling the internal buffer for Crc handling */
#define NVM_CRC_INT_BUFFER /*<NVM_CRC_INT_BUFFER/>*/ (STD_ON)

/* switch that is "ON" if dataset blocks are used */
#define NVM_USE_DATASETS    /*<NVM_USE_DATASETS/>*/ (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API   /*<NVM_KILL_WRITEALL_API/>*/ (STD_ON)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS (1u)

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET	0x8000u

/* returns corresponding DCM BlockId of an original NVRAM Block */
#define NvM_GetDcmBlockId(MyApplBlockId)	((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET)

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks
 *       in the NvM_BlockDescriptorTable_at
 */

/* Alignment of the handles of all blocks */
/* Id 0 is reserved for multiblock calls */
#define /*<NVM_MULTIBLOCK_ID>*/MultiBlockRequest/*</NVM_MULTIBLOCK_ID>*/ (0u)
/* Id 1 is reserved for config ID  */

#define ConfigBlock (1u)

/* user defineable blocks */
/*<NVM_BLOCK_ID_CFG>*/
#define NVM_BLOCK_DIAGMGR_NTCSTRG (2)
#define NVM_BLOCK_EPSDEFEATS (3)
#define Deprecated_NVM_BLOCK_DEM_CTCSTRG (4)
#define Rte_NvmBlock_StaMd_TypeHRamBuffer (5)
#define Rte_NvmBlock_Polarity_Polarity_Cnt_Str (6)
#define Rte_NvmBlock_CurrParamComp_EOLNomMtrParam (7)
#define NVM_BLOCK_CMS_NXTRMEC (8)
#define NVM_BLOCK_CMS_ECUSRLNUM (9)
#define NVM_BLOCK_CMS_EPSSRLNUM (10)
#define NVM_BLOCK_CMS_ECUHWPN (11)
#define NVM_BLOCK_CMS_NXTRMANUFSCRATCHPAD (12)
#define NVM_BLOCK_CMS_IGNCNTR (13)
#define Rte_NvmBlock_StaMd_CloseCheckData (14)
#define Rte_NvmBlock_DigMSB_DigMSBEOLData (15)
#define Rte_NvmBlock_AstLmt_SteerAsstDefeat (16)
#define NVM_BLOCK_DIAGMGR_BLACKBOX (17)
#define Rte_NvmBlock_BatteryVoltage_OvervoltageData (18)
#define Rte_NvmBlock_ThrmlDutyCycle_ThrmlDutyCycle_FltStVal (19)
#define NVM_BLOCK_DIAGMGR_LATCHCNTRS (20)
#define NVM_BLOCK_SER_FLASHLOGA (21)
#define NVM_BLOCK_SER_FLASHLOGB (22)
#define NVM_BLOCK_SER_SECURITYVIOLATION (23)
#define Rte_NvmBlock_VehDyn_MotPosReset (24)
#define NVM_BLOCK_SER_AUTHENTICATIONZONE (25)
#define NVM_BLOCK_SER_ECUMANUFACTURINGDATE (26)
#define NVM_BLOCK_SER_EMCSTANDARDIZATIONLABEL (27)
#define NVM_BLOCK_SER_CUSTECUSRLNUM (28)
#define NVM_BLOCK_SER_SECURITYKEY (29)
#define Rte_NvmBlock_SrlComInput_VVHTYPEData (30)
#define Rte_NvmBlock_SrlComInput_ElecIntData (31)
#define NVM_BLOCK_SER_TUNINGSELECT (32)
#define Rte_NvmBlock_DigHwTrqSENT_DigTrqTrim (33)
#define Deprecated_NvmBlock_CmMtrCurr_CurrTempOffset (34)
#define Rte_NvmBlock_CmMtrCurr_ShCurrCal (35)
#define Rte_NvmBlock_TrqCanc_CogTrqCal (36)
#define Rte_NvmBlock_TrqCanc_CogTrqRplComp (37)
#define Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32 (38)
#define Deprecated_NvmBlock_AbsHwPos_EOLVehCntrOffset (39)
#define Rte_NvmBlock_LrnEOT_LearnedEOT (40)
#define Rte_NvmBlock_AvgFricLrn_AvgFricLrnData (41)
#define Rte_NvmBlock_CmMtrCurr_CurrTempOffset (42)
#define Deprecated_Rte_NvmBlock_AbsHwPos_EOLVehCntrOffset (43)
#define Rte_NvmBlock_FaultLog_FaultLog (44)
#define Deprecated_BLOCK_DEM_CTCSTRG1 (45)
#define Rte_NvmBlock_SrlComInput_ShutdownTimeData (46)
#define NVM_BLOCK_DEM_CTCSTRG (47)
#define Rte_NvmBlock_AbsHwPos_EOLVehCntrOffset (48)
/*</NVM_BLOCK_ID_CFG>*/


/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS   /*<NVM_TOTAL_NUM_OF_NVRAM_BLOCKS/>*/ (49u)

/* version info api switch */
#define NVM_VERSION_INFO_API            /*<NVM_VERSION_INFO_API/>*/ (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API    /*<NVM_SET_RAM_BLOCK_STATUS_API/>*/ (STD_ON)


/* if in Development mode, define a macro to enable State Machine checking
 * fall through errors, operating on "NO JOB" (NvM should be IDLE)
 */
#if (STD_ON == NVM_DEV_ERROR_DETECT)
    #define NVM_DEV_DETECT_FSM_ERRORS (STD_ON)    /* just for development */
#else
    #define NVM_DEV_DETECT_FSM_ERRORS (STD_OFF)   /* just for development */
#endif

/* CONST_DESCRIPTOR_TABLE contains all block relevant data,
 * including the compiled config ID
 */
#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

    /* Additional published parameter because e.g. in case of validate all RAM
     * Blocks it is nice to know the number of Blocks. But take care: this number
     * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
     * Configuration Block - user Blocks start wiht index 2!
     */
    extern CONST(uint16, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

    /* Additional published parameter because in case of a clear EEPROM, it is
     * necessary, to write the Configuration Block containing this Compiled
     * Configuration ID to EEPROM
     */
    /* Compiled Configuration ID as defined in NvM_Cfg.c */
    extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t;
#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"


/* ---- end public configuration section ---------------------------------- */

#endif /* NVM_CFG_H_PUBLIC */
/*---- End of File ---------------------------------------------------------*/
