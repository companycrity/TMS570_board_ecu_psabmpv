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
 *          File:  Rte_Sa_CDDInterface10.h
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface10
 *  Generated at:  Wed Feb  4 10:03:47 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Sa_CDDInterface10> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE10_H
# define _RTE_SA_CDDINTERFACE10_H

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

typedef P2CONST(struct Rte_CDS_Sa_CDDInterface10, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CommOffset_Cnt_u16 (0U)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
# define Rte_InitValue_MtrCurr1TempOffset_Volt_f32 (0.0F)
# define Rte_InitValue_MtrCurr2TempOffset_Volt_f32 (0.0F)
# define Rte_InitValue_MtrPosPolarity_Cnt_s08 (0)
# define Rte_InitValue_MtrTrqCmdSign_Cnt_s16 (0)
# define Rte_InitValue_Vecu_Volt_f32 (5.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Sa_CDDInterface10_SystemState_Mode(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CDDInterface10_Init1_MtrPosPolarity_Cnt_s08() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Init1_MtrPosPolarity_Cnt_s08->value)

# define Rte_IRead_CDDInterface10_Per1_CommOffset_Cnt_u16() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_CommOffset_Cnt_u16->value)

# define Rte_IRead_CDDInterface10_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_CDDInterface10_Per1_MtrCurr1TempOffset_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MtrCurr1TempOffset_Volt_f32->value)

# define Rte_IRead_CDDInterface10_Per1_MtrCurr2TempOffset_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MtrCurr2TempOffset_Volt_f32->value)

# define Rte_IRead_CDDInterface10_Per1_MtrPosPolarity_Cnt_s08() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MtrPosPolarity_Cnt_s08->value)

# define Rte_IRead_CDDInterface10_Per1_MtrTrqCmdSign_Cnt_s16() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MtrTrqCmdSign_Cnt_s16->value)

# define Rte_IRead_CDDInterface10_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_Vecu_Volt_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Sa_CDDInterface10_SystemState_Mode




# define RTE_START_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CDDInterface10_Init1_MtrPosPolarity_Cnt_s08(void)
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

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_CDDInterface10_Per1_CommOffset_Cnt_u16(void)
 *   Float Rte_IRead_CDDInterface10_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_CDDInterface10_Per1_MtrCurr1TempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface10_Per1_MtrCurr2TempOffset_Volt_f32(void)
 *   SInt8 Rte_IRead_CDDInterface10_Per1_MtrPosPolarity_Cnt_s08(void)
 *   SInt16 Rte_IRead_CDDInterface10_Per1_MtrTrqCmdSign_Cnt_s16(void)
 *   Float Rte_IRead_CDDInterface10_Per1_Vecu_Volt_f32(void)
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

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per1(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1423060974
#    error "The magic number of the generated file <C:/Users/nzx5jd/Desktop/DVOutput/Sa_CDDInterface10/Rte_Sa_CDDInterface10.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1423060974
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE10_H */
