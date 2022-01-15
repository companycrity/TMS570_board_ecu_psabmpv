/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface10.c
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface10
 *  Generated at:  Wed Feb  4 10:03:33 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface10>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          3 %
 * %derived_by:       nzx5jd %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/29/14   1       OT        Initial Version - based on Sa_CDDInterface.c v5                                12249
 * 10/08/14   2       OT        Split to Sa_CDDInterface6.c for new customer services                          12363
 * 02/04/15   3       OT        Added MtrPosPolarity to Init1 function for accurate CumMtrPos on startup       12985
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface10.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "CDD_Data.h"
#include "Interrupts.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_CDDINTERFACE10_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

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

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface10_Init1
 *********************************************************************************************************************/
	
	
	VAR(sint8,   AUTOMATIC) MtrPosPolarity_Cnt_T_s08;
	
	
	MtrPosPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface10_Init1_MtrPosPolarity_Cnt_s08();
	
	
	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = 0U;
	
	CDD_Vecu_Volt_G_f32[0U] = D_VECUMIN_VOLTS_F32;
	CDD_Vecu_Volt_G_f32[1U] = D_VECUMIN_VOLTS_F32;
	
	CDD_MtrPosPolarity_Cnt_G_s08[0U] = MtrPosPolarity_Cnt_T_s08;
	CDD_MtrPosPolarity_Cnt_G_s08[1U] = MtrPosPolarity_Cnt_T_s08;
	
	
	EnableMtrCtlInterrupt();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface10_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint16,  AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) CommOffset_Cnt_T_u16;
	VAR(float32, AUTOMATIC) MRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr1TempOffset_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr2TempOffset_Volt_T_f32;
	VAR(sint8,   AUTOMATIC) MtrPosPolarity_Cnt_T_s08;
	VAR(sint16,  AUTOMATIC) MtrTrqCmdSign_Cnt_T_s16;
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_Enum;
	
	
	WriteBuffer_Cnt_T_u16 = (CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 & 1u) ^ 1u;
	
	
	CommOffset_Cnt_T_u16 = Rte_IRead_CDDInterface10_Per1_CommOffset_Cnt_u16();
	MRFMtrVel_MtrRadpS_T_f32 = Rte_IRead_CDDInterface10_Per1_MRFMtrVel_MtrRadpS_f32();
	MtrCurr1TempOffset_Volt_T_f32 = Rte_IRead_CDDInterface10_Per1_MtrCurr1TempOffset_Volt_f32();
	MtrCurr2TempOffset_Volt_T_f32 = Rte_IRead_CDDInterface10_Per1_MtrCurr2TempOffset_Volt_f32();
	MtrPosPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface10_Per1_MtrPosPolarity_Cnt_s08();
	MtrTrqCmdSign_Cnt_T_s16 = Rte_IRead_CDDInterface10_Per1_MtrTrqCmdSign_Cnt_s16();
	SysState_Cnt_T_Enum = Rte_Mode_SystemState_Mode();
	Vecu_Volt_T_f32 = Rte_IRead_CDDInterface10_Per1_Vecu_Volt_f32();
	
	
	CDD_MtrCurrOffComOffset_Cnt_G_u16[WriteBuffer_Cnt_T_u16] = CommOffset_Cnt_T_u16;
	CDD_MRFMtrVel_MtrRadpS_G_f32[WriteBuffer_Cnt_T_u16] = MRFMtrVel_MtrRadpS_T_f32;
	CDD_MtrCurr1TempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16] = MtrCurr1TempOffset_Volt_T_f32;
	CDD_MtrCurr2TempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16] = MtrCurr2TempOffset_Volt_T_f32;
	CDD_MtrPosPolarity_Cnt_G_s08[WriteBuffer_Cnt_T_u16] = MtrPosPolarity_Cnt_T_s08;
	CDD_MtrTrqCmdSign_Cnt_G_s16[WriteBuffer_Cnt_T_u16] = MtrTrqCmdSign_Cnt_T_s16;
	CDD_SysState_Cnt_G_Enum[WriteBuffer_Cnt_T_u16] = SysState_Cnt_T_Enum;
	CDD_Vecu_Volt_G_f32[WriteBuffer_Cnt_T_u16] = Vecu_Volt_T_f32;
	
	
	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE10_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
