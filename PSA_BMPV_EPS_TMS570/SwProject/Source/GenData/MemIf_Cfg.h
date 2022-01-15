/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MemIf_Cfg.h
 *    Component:  If_AsrIfMem
 *       Module:  MemIf
 *    Generator:  EAD
 *
 *  Description:  The Memory Abstraction Interface provides uniform access to services of underlying
 *                Memory Hardware abstraction (MemHwA) modules, i.e. EEPROM Abstraction (EA) and
 *                Flash EEPROM Emulation (FEE). The appropriate MemHwA module is selected by a device index.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
    Project:    EPS.ecuc
    Generated:  2014-01-31 04:28 pm
    Licensee:   Vector AUTOSAR Basic Software (MICROSAR)
 
    This file is generated by DaVinci Configurator Base - DAVINCICFG.EXE V4.0.67.0.
    Do not modify this file, otherwise the software may behave in unexpected way.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Tobias Schmid                 Tsd           Vector Informatik GmbH
 *  Roland Suess                  Rsu           Vector Informatik GmbH
 *  Manfred Duschinger            Du            Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.02.00  -           Tsd     -             first production release
 *  02.00.00  2008-04-09  Tsd     -             update for AUTOSAR Release 3.0
 *  02.01.00  2008-09-15  Rsu     -             Supporting 2 Fee instances in NvM
 *  02.01.01  2009-10-20  Tsd     ESCAN00037330 Corrected Fee/Ea calls in macro API
 *  02.01.02  2011-01-20  Du      -             Updated Cfg version to xml files
 *********************************************************************************************************************/

/* ---- API relevant (public) section of configuration ---------------------*/

/* there is just a public section  -------------------------------*/
#if (!defined _MEMIF_CFG_H_)    /* Multiple inclusion protection viewed from MemIf.h */
#define _MEMIF_CFG_H_


/*---- Version identification -------------*/

#define MEMIF_CFG_MAJOR_VERSION      ( 2U )
#define MEMIF_CFG_MINOR_VERSION      ( 1U )
#define MEMIF_CFG_PATCH_VERSION      ( 2U )

/*---- API CFG Defines -----------------------------------------------------*/

#define MEMIF_NUMBER_OF_DEVICES     (1u)

/* Logical Device Names */
#define MEMIF_Fee (0u)

#define MEMIF_VERSION_INFO_API  (STD_ON)
#define MEMIF_CFG_USE_FCT_API   (STD_ON)

/* ------------------------------------------------------------------------ */
/*              Configurations for Development mode                         */
/* 													 						*/
/* ------------------------------------------------------------------------ */
/* preprocessor switch for DET */
#define MEMIF_DEV_ERROR_DETECT (STD_ON)

#if (STD_ON == MEMIF_DEV_ERROR_DETECT)
    /* en-/disable development error reporting */
    #define MEMIF_DEBUG_REPORTING            (STD_ON)

    /* en-/disable checking of the device index parameter */
    #define MEMIF_CFG_CHK_PARAM_DEV_INDEX    (STD_ON)

    /* en-/disable checking of null pointer parameter in MemIf_GetVersionInfo */
    #define MEMIF_CFG_CHK_PARAM_VINFO       (STD_ON)

#else
    /* development error detection is disabled, so no checks are performed */
    #define MEMIF_CFG_CHK_PARAM_DEV_INDEX    STD_OFF
    #define MEMIF_DEBUG_REPORTING            STD_OFF
    #define MEMIF_CFG_CHK_PARAM_VINFO        STD_OFF
#endif

#if (MEMIF_DEBUG_REPORTING == STD_ON)
    /* Include-File, which contains Errorhook-Function */
    #include "Det.h"

    /* implementation of the Errorhook call - user defineable Errorhook */
    #define MemIf_Errorhook(MemIf_FunctionId, MemIf_ErrorCode)      \
        Det_ReportError                 \
        (MEMIF_MODULE_ID, (0u), MemIf_FunctionId, MemIf_ErrorCode)
#else
    /* development error reporting is disabled, do not
     * implement an Errorhook
     */
    #define MemIf_Errorhook(MemIf_FunctionId, MemIf_ErrorCode)
#endif


/*---- API CFG Macros ------------------------------------------------------*/

/*---- API CFG Type definitions --------------------------------------------*/
/* type definitions for referencing APIs of underlying
 * memory hardware abstraction modules
 */
typedef P2FUNC (void, MEMIF_CODE, MemIf_ApiSetModeType)
            (
                MemIf_ModeType      Mode
            );
typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiReadType)
            (
                uint16              BlockNumber,
                uint16              BlockOffset,
                MemIf_DataPtr_pu8   DataBufferPtr,
                uint16              Length
            );
typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiWriteType)
            (
                uint16              BlockNumber,
                MemIf_DataPtr_pu8   DataBufferPtr
            );

typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiEraseImmediateBlockType)
            (
                uint16              BlockNumber
            );

typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiInvalidateBlockType)
            (
                uint16              BlockNumber
            );

typedef P2FUNC (void, MEMIF_CODE, MemIf_ApiCancelType)
            (
                void
            );
typedef P2FUNC (MemIf_StatusType, MEMIF_CODE, MemIf_ApiGetStatusType)
            (
                void
            );
typedef P2FUNC (MemIf_JobResultType, MEMIF_CODE, MemIf_ApiGetJobResultType)
            (
                void
            );

/* configuration structure, handles the API mapping */
typedef struct
{
    MemIf_ApiSetModeType                SetMode;
    MemIf_ApiReadType                   Read;
    MemIf_ApiWriteType                  Write;
    MemIf_ApiEraseImmediateBlockType    EraseImmediateBlock;
    MemIf_ApiInvalidateBlockType        InvalidateBlock;
    MemIf_ApiCancelType                 Cancel;
    MemIf_ApiGetStatusType              GetStatus;
    MemIf_ApiGetJobResultType           GetJobResult;
} MemIf_MemHwAApi_Type;

/*---- Include of the MemHwAs ---------------------------*/
#include "Fee.h"

/*---- API CFG Structures --------------------------------------------------*/

/*---- API CFG Constants ---------------------------------------------------*/
#define MEMIF_START_SEC_CONST_8BIT
#include "MemMap.h"

    extern CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices_u8;

#define MEMIF_STOP_SEC_CONST_8BIT
#include "MemMap.h"
#define MEMIF_START_SEC_CONST_32BIT
#include "MemMap.h"

    extern CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) \
                            MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES];

#define MEMIF_STOP_SEC_CONST_32BIT
#include "MemMap.h"


#if (MEMIF_CFG_USE_FCT_API == STD_OFF)
    /* mapping of MemIf_Read() */
    #define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
                    MemIf_MemHwaApis_at[DeviceIndex].Read( \
                        (BlockNumber), \
                        (BlockOffset), \
                        (DataBufferPtr), \
                        (Length))

    /* mapping of MemIf_EraseImmediateBlock() */
    #define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
                MemIf_MemHwaApis_at[DeviceIndex].EraseImmediateBlock(BlockNumber)

    /* mapping of MemIf_InvalidateBlock() */
    #define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) \
                MemIf_MemHwaApis_at[DeviceIndex].InvalidateBlock(BlockNumber)

    /* mapping of MemIf_Write() */
    #define MemIf_Write(DeviceIndex, BlockNumber, DataBufferPtr) \
                MemIf_MemHwaApis_at[DeviceIndex].Write(BlockNumber, DataBufferPtr)

    /* mapping of MemIf_Cancel() */
    #define MemIf_Cancel(DeviceIndex) \
                MemIf_MemHwaApis_at[DeviceIndex].Cancel()

    /* mapping of MemIf_GetJobResult() */
    #define MemIf_GetJobResult(DeviceIndex) \
                MemIf_MemHwaApis_at[DeviceIndex].GetJobResult()
#endif /* #if (MEMIF_CFG_USE_FCT_API == STD_OFF) */


#endif /* _MEMIF_CFG_H_ */
/*---- End of File ---------------------------------------------------------*/

