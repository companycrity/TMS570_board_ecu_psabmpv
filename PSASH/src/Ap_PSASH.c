/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PSASH.c
 *     Workspace:  C:/Sankar/New_EA3_Database/Working/PSASH/autosar
 *     SW-C Type:  Ap_PSASH
 *  Generated at:  Thu May 12 13:46:51 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PSASH>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
 * Copyright 2016 Nexteer
 * Nexteer Confidential
 *
 * Module File Name	 : Ap_PSASH.c
 * Module Description: Implementation of CF013B
 * Project           : CBD
 * Author            : Sankardu Varadapureddi
 *****************************************************************************
 * Version Control:
 * %version:          2 %
 * %derived_by:       pznywf %
 *--------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                              SCR #
 * -------   -------  --------  -----------------------------------------------------------------------------  -------
 * 05/02/16  1        SV        Initial Version                                                                EA3#7580
 * 05/20/16  2        SV        Corrected 'PSASH_ApaEnaRgln_Cnt_M_lgc' logic and memmap macros                 EA3#7580
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_PSASH.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "SystemTime.h"
#include "fixmath.h"

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */
/* PRQA S 4395 EOF
* MISRA-C:2004 Rule 10.4: A composite expression of 'essentially floating' type (%1s) is being cast to a different type category, '%2s'. */

#define D_APASTUNAVAIL_CNT_U08			0U
#define D_APASTAVAIL_CNT_U08			1U
#define D_APASTCONTROLPROGRESS_CNT_U08	2U
#define D_APASTDEFECT_CNT_U08			3U

#define D_APATRNOERR_CNT_U08			0U
#define D_APATRDRVACTION_CNT_U08		1U
#define D_APATRVEHSPDHIGH_CNT_U08		2U
#define D_APATRANGULARERR_CNT_U08		3U
#define D_APATRMTRSTALL_CNT_U08			4U
#define D_APATRTHRMLLMT_CNT_U08			6U
#define D_APATROTHERERR_CNT_U08			7U

#define PSASH_START_SEC_VAR_INIT_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_PSASH_VAR) PSASH_APSState_Cnt_M_u08;
STATIC VAR(uint8, AP_PSASH_VAR) PSASH_APSStateTranCause_Cnt_M_u08;
#define PSASH_STOP_SEC_VAR_INIT_8
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_INIT_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_PSASH_VAR) PSASH_DynTimeAcc_Cnt_M_u16;	/* PRQA S 3218 */
STATIC VAR(uint16, AP_PSASH_VAR) PSASH_StaTimeAcc_Cnt_M_u16;	/* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_INIT_16
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_PSASH_VAR) PSASH_PrevHandwheelDiff_HwDeg_M_f32;	/* PRQA S 3218 */
STATIC VAR(float32, AP_PSASH_VAR) PSASH_HwTqFiltered_HwNm_D_f32;	/* PRQA S 3218 */
STATIC VAR(uint32, AP_PSASH_VAR) PSASH_HwTrqFiltStartTime1_mS_M_u32;	/* PRQA S 3218 */
STATIC VAR(uint32, AP_PSASH_VAR) PSASH_HwTrqFiltStartTime2_mS_M_u32;	/* PRQA S 3218 */
STATIC VAR(uint32, AP_PSASH_VAR) PSASH_AvlTime_mS_M_u32;	/* PRQA S 3218 */			
#define PSASH_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_PSASH_VAR) PSASH_ApaEnaRgln_Cnt_M_lgc;   /* PRQA S 3218 */
STATIC VAR(boolean, AP_PSASH_VAR) PSASH_PrevApaEnaRgln_Cnt_M_lgc; 
STATIC VAR(boolean, AP_PSASH_VAR) PSASH_CtrlProgsFlg_Cnt_M_lgc;	/* PRQA S 3218 */
STATIC VAR(boolean, AP_PSASH_VAR) PSASH_TraFirstTime_Cnt_M_lgc; /* PRQA S 3218 */
#define PSASH_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define PSASH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_PSASH_VAR)	PSASH_HwTrqFilterSV_HwNm_M_Str;
#define PSASH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, AP_PSASH_APPL_CODE) Chk_Progs_Exit_Conds(VAR(boolean, AUTOMATIC) FaultActv_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) VehSpdTooHigh_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) HwActionMaxReached_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) HwPosCmdErr_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc);
														   
STATIC FUNC(void, AP_PSASH_APPL_CODE) Chk_Available_Exit_Conds(VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) VehSpdTooHigh_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) HwActionMinReached_Cnt_T_lgc);
															   
STATIC FUNC(void, AP_PSASH_APPL_CODE) Chk_UnAvailableReady_Exit_Conds(VAR(boolean, AUTOMATIC) FaultActv_Cnt_T_lgc,
																	  VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
																	  VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc);
																		 
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) IsVehicleSpeedAbvThd(VAR(float32, AUTOMATIC) Sig_Uls_T_f32,
                                                              VAR(float32, AUTOMATIC) Thd_Uls_T_f32);

STATIC FUNC(boolean, AP_PSASH_APPL_CODE) IsThermLimitAbvThd(VAR(float32, AUTOMATIC) Sig_Uls_T_f32,
                                                            VAR(float32, AUTOMATIC) Thd_Uls_T_f32);

STATIC FUNC(boolean, AP_PSASH_APPL_CODE) IsAssistStallBlwThd(VAR(float32, AUTOMATIC) Sig_Uls_T_f32,
                                                              VAR(float32, AUTOMATIC) Thd_Uls_T_f32);										 													 
													 
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) DtrmnApaAllwd(VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc,
													   VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32,
													   VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32);

STATIC FUNC(boolean, AP_PSASH_APPL_CODE) DtrmnRglnErr(VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
	                                                  VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32);		

STATIC FUNC(void, AP_PSASH_APPL_CODE) HwIntv(VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32,
											 P2VAR(boolean, AUTOMATIC, Psash_VAR) HwActionMinReached_Cnt_T_lgc,
											 P2VAR(boolean, AUTOMATIC, Psash_VAR) HwActionMaxReached_Cnt_T_lgc);	

STATIC FUNC(boolean, AP_PSASH_APPL_CODE) DtrmnSysFlt(VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc,
													 VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc,
													 VAR(boolean, AUTOMATIC) PosSrvoNTC_Cnt_T_lgc,
													 VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc);											 
													   
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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ZERO_ULS_F32 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PSASH_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSASH_Init1
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSASH_Init1
 *********************************************************************************************************************/

	LPF_Init_f32_m(D_ZERO_ULS_F32, k_PSASH_ApaMaxHwTrqFilt_Hz_f32, D_2MS_SEC_F32, &PSASH_HwTrqFilterSV_HwNm_M_Str);
	
	PSASH_PrevApaEnaRgln_Cnt_M_lgc = FALSE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSASH_Per1
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
 *   Boolean Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc(void)
 *   Boolean Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_PosSrvoNTC_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32(void)
 *   Boolean Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSASH_Per1_APAStateTransitionCause_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_PSASH_Per1_APAStateTransitionCause_Cnt_u08(void)
 *   void Rte_IWrite_PSASH_Per1_APAState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_PSASH_Per1_APAState_Cnt_u08(void)
 *   void Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSASH_Per1_PosSrvoEnable_Cnt_lgc(void)
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

FUNC(void, RTE_AP_PSASH_APPL_CODE) PSASH_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSASH_Per1
 *********************************************************************************************************************/

	/* inputs */
	VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PosSrvoNTC_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) AssistStallLimit_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;
	VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) ThermLimitPerc_Uls_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;	
	VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
	
	VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwPosCmdErr_Cnt_T_lgc;
	
	VAR(boolean, AUTOMATIC) HwActionMinReached_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) HwActionMaxReached_Cnt_T_lgc = FALSE;
	
	VAR(boolean, AUTOMATIC) VehSpdTooHigh_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc;
	
	VAR(boolean, AUTOMATIC) FaultActv_Cnt_T_lgc;
	
	/* read inputs */
	ApaAuthn_Cnt_T_lgc = Rte_IRead_PSASH_Per1_ApaAuthn_Cnt_lgc();
	ApaCmdReq_Cnt_T_lgc = Rte_IRead_PSASH_Per1_ApaCmdReq_Cnt_lgc();
	ApaEna_Cnt_T_lgc = Rte_IRead_PSASH_Per1_ApaEna_Cnt_lgc();
	ApaRelaxReq_Cnt_T_lgc = Rte_IRead_PSASH_Per1_ApaRelaxReq_Cnt_lgc();
	AssistStallLimit_MtrNm_T_f32 = Rte_IRead_PSASH_Per1_AssistStallLimit_MtrNm_f32();
	CpkOk_Cnt_T_lgc = Rte_IRead_PSASH_Per1_CpkOk_Cnt_lgc();
	FTermActv_Cnt_T_lgc = Rte_IRead_PSASH_Per1_FTermActv_Cnt_lgc();
	HandwheelAuthority_Uls_T_f32 = Rte_IRead_PSASH_Per1_HandwheelAuthority_Uls_f32();
	HandwheelPosition_HwDeg_T_f32 = Rte_IRead_PSASH_Per1_HandwheelPosition_HwDeg_f32();
	HwTorque_HwNm_T_f32 = Rte_IRead_PSASH_Per1_HwTorque_HwNm_f32();
	OutputRampMult_Uls_T_f32 = Rte_IRead_PSASH_Per1_OutputRampMult_Uls_f32();
	PosSrvoHwAngle_HwDeg_T_f32 = Rte_IRead_PSASH_Per1_PosSrvoHwAngle_HwDeg_f32();
	PosSrvoNTC_Cnt_T_lgc = Rte_IRead_PSASH_Per1_PosSrvoNTC_Cnt_lgc();
	ThermLimitPerc_Uls_T_f32 = Rte_IRead_PSASH_Per1_ThermLimitPerc_Uls_f32();
	VehicleSpeedValid_Cnt_T_lgc = Rte_IRead_PSASH_Per1_VehicleSpeedValid_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_PSASH_Per1_VehicleSpeed_Kph_f32();
	
	/*** Determine Apa Allowed ***/
	ApaAllowed_Cnt_T_lgc = DtrmnApaAllwd(ApaAuthn_Cnt_T_lgc,
	                                     HandwheelAuthority_Uls_T_f32,
										 OutputRampMult_Uls_T_f32);
	
	/*** Determine Regulation Errors ***/
	HwPosCmdErr_Cnt_T_lgc = DtrmnRglnErr(HandwheelPosition_HwDeg_T_f32,
	                                     PosSrvoHwAngle_HwDeg_T_f32);
	
	/*** Handwheel intervention ***/	
	HwIntv(HwTorque_HwNm_T_f32,
		   &HwActionMinReached_Cnt_T_lgc,
		   &HwActionMaxReached_Cnt_T_lgc);
	
	/*** Limits ***/
	VehSpdTooHigh_Cnt_T_lgc = IsVehicleSpeedAbvThd(VehicleSpeed_Kph_T_f32,k_PSASH_ApaVehicleSpeed_Kph_f32);
	ThrmlLmtReached_Cnt_T_lgc = IsThermLimitAbvThd(ThermLimitPerc_Uls_T_f32,k_PSASH_ApaThemLimitPerc_Uls_f32);
	MtrStalled_Cnt_T_lgc = IsAssistStallBlwThd(AssistStallLimit_MtrNm_T_f32,k_PSASH_ApaAssistStallLimit_MtrNm_f32);

	/*** Determine System or COM faults ***/
	FaultActv_Cnt_T_lgc = DtrmnSysFlt(VehicleSpeedValid_Cnt_T_lgc,
									  CpkOk_Cnt_T_lgc,
									  PosSrvoNTC_Cnt_T_lgc,
									  FTermActv_Cnt_T_lgc);

	switch (PSASH_APSState_Cnt_M_u08)
	{
		case(D_APASTUNAVAIL_CNT_U08):
		{
			switch (PSASH_APSStateTranCause_Cnt_M_u08)
			{
				case(D_APATRNOERR_CNT_U08):
				{
					
					Chk_UnAvailableReady_Exit_Conds(FaultActv_Cnt_T_lgc,
					                                ApaEna_Cnt_T_lgc,
													ApaAllowed_Cnt_T_lgc);
				}
				break;
				
				case(D_APATRTHRMLLMT_CNT_U08):
				{
					if(ThrmlLmtReached_Cnt_T_lgc == FALSE)
					{	
						PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;	
					}
				}
				break;
				
				case(D_APATROTHERERR_CNT_U08):
				{
					if(ApaAllowed_Cnt_T_lgc == TRUE)
					{	
						PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;
					}
				}
				break;
				
				default:
				break;
			}
		}

		break;
		
		case(D_APASTAVAIL_CNT_U08):
		{
			if(FaultActv_Cnt_T_lgc == TRUE)
			{
				PSASH_APSState_Cnt_M_u08 = D_APASTDEFECT_CNT_U08;
				PSASH_APSStateTranCause_Cnt_M_u08 = D_APATROTHERERR_CNT_U08;
			}
			else if(ThrmlLmtReached_Cnt_T_lgc == TRUE)
			{
				PSASH_APSState_Cnt_M_u08 = D_APASTUNAVAIL_CNT_U08;
				PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRTHRMLLMT_CNT_U08;
			}
			else 
			{
				Chk_Available_Exit_Conds(ApaAllowed_Cnt_T_lgc,
						                 ApaCmdReq_Cnt_T_lgc,
						                 VehSpdTooHigh_Cnt_T_lgc,
						                 MtrStalled_Cnt_T_lgc,
						                 HwActionMinReached_Cnt_T_lgc);
			}
		}
		break;
		
		case(D_APASTCONTROLPROGRESS_CNT_U08):
		{
			Chk_Progs_Exit_Conds(FaultActv_Cnt_T_lgc,
							     ThrmlLmtReached_Cnt_T_lgc,
							     VehSpdTooHigh_Cnt_T_lgc,
							     HwActionMaxReached_Cnt_T_lgc,
							     ApaCmdReq_Cnt_T_lgc,
							     ApaAllowed_Cnt_T_lgc,
							     ApaRelaxReq_Cnt_T_lgc,
							     HwPosCmdErr_Cnt_T_lgc,
							     MtrStalled_Cnt_T_lgc);
		}
		break;
		
		case(D_APASTDEFECT_CNT_U08):
		{
			if(FaultActv_Cnt_T_lgc == FALSE)
			{
				PSASH_APSState_Cnt_M_u08 = D_APASTUNAVAIL_CNT_U08;
				PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;
			}
		}
		break;
	    
		default:
		break;
	}
	
	/* In case of 'PSASH_CONTROL_PROGRESS entry' , set 'PSASH_ApaEnaRgln_Cnt_M_lgc' to TRUE, otherwise FALSE */ 
	if((PSASH_APSState_Cnt_M_u08 == D_APASTCONTROLPROGRESS_CNT_U08) && (PSASH_CtrlProgsFlg_Cnt_M_lgc == TRUE))
	{
		PSASH_ApaEnaRgln_Cnt_M_lgc = TRUE;
	}
    else
    {
        PSASH_ApaEnaRgln_Cnt_M_lgc = FALSE;
    }
	
	PSASH_PrevApaEnaRgln_Cnt_M_lgc = PSASH_ApaEnaRgln_Cnt_M_lgc;
	
	Rte_IWrite_PSASH_Per1_APAStateTransitionCause_Cnt_u08(PSASH_APSStateTranCause_Cnt_M_u08);
	Rte_IWrite_PSASH_Per1_APAState_Cnt_u08(PSASH_APSState_Cnt_M_u08);
	Rte_IWrite_PSASH_Per1_PosSrvoEnable_Cnt_lgc(PSASH_ApaEnaRgln_Cnt_M_lgc);

	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PSASH_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*******************************************************************************
* Name		    :	Chk_Progs_Exit_Conds
* Description	:	Checks all exit paths from 'PSASH_PROGRESS entry' state. 
* Inputs		:	FaultActv_Cnt_T_lgc, ThrmlLmtReached_Cnt_T_lgc, VehSpdTooHigh_Cnt_T_lgc,
*                   HwActionMaxReached_Cnt_T_lgc, ApaCmdReq_Cnt_T_lgc, ApaAllowed_Cnt_T_lgc,
*                   ApaRelaxReq_Cnt_T_lgc, HwPosCmdErr_Cnt_T_lgc, MtrStalled_Cnt_T_lgc
* Outputs		:	None
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(void, AP_PSASH_APPL_CODE) Chk_Progs_Exit_Conds(VAR(boolean, AUTOMATIC) FaultActv_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ThrmlLmtReached_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) VehSpdTooHigh_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) HwActionMaxReached_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) ApaRelaxReq_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) HwPosCmdErr_Cnt_T_lgc,
														   VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc)
{	
	if(FaultActv_Cnt_T_lgc == TRUE)
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTDEFECT_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATROTHERERR_CNT_U08;
	}
	else if(ThrmlLmtReached_Cnt_T_lgc == TRUE)
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTUNAVAIL_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRTHRMLLMT_CNT_U08;
	}
	else if(VehSpdTooHigh_Cnt_T_lgc == TRUE)
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTAVAIL_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRVEHSPDHIGH_CNT_U08;
	}
	else if(HwActionMaxReached_Cnt_T_lgc == TRUE)
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTAVAIL_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRDRVACTION_CNT_U08;
	}
	else if(ApaCmdReq_Cnt_T_lgc == FALSE)
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTAVAIL_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;
	}
	else if(ApaAllowed_Cnt_T_lgc == FALSE)
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTUNAVAIL_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATROTHERERR_CNT_U08;
	}
	else if((ApaRelaxReq_Cnt_T_lgc == FALSE) && (PSASH_CtrlProgsFlg_Cnt_M_lgc == FALSE))	/* if in 'PSASH_PROGRESS_RELAX' state*/
	{
		PSASH_CtrlProgsFlg_Cnt_M_lgc = TRUE;	
	}
	else if(PSASH_CtrlProgsFlg_Cnt_M_lgc == TRUE) /* in 'PSASH_CONTROL_PROGRESS' state */
	{
		if(HwPosCmdErr_Cnt_T_lgc == TRUE)
		{
			PSASH_APSState_Cnt_M_u08 = D_APASTAVAIL_CNT_U08;
			PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRANGULARERR_CNT_U08;
		}
		else if(MtrStalled_Cnt_T_lgc == TRUE)
		{
			PSASH_APSState_Cnt_M_u08 = D_APASTAVAIL_CNT_U08;
			PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRMTRSTALL_CNT_U08;
		}	
		else if(ApaRelaxReq_Cnt_T_lgc == TRUE)
		{	
			PSASH_CtrlProgsFlg_Cnt_M_lgc = FALSE;
		}
		else
		{
		}
	}
	else
	{	
	}	
	
}
/*******************************************************************************
* Name		    :	Chk_Available_Exit_Conds
* Description	:	Checks all exit paths from 'PSASH_AVAILABLE_READY /
*                   PSASH_AVAILABLE_TRANSITIONCAUSE entry' states. 
* Inputs		:	FaultActv_Cnt_T_lgc, ApaEna_Cnt_T_lgc, ApaAllowed_Cnt_T_lgc
* Outputs		:	None
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(void, AP_PSASH_APPL_CODE) Chk_Available_Exit_Conds(VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) ApaCmdReq_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) VehSpdTooHigh_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) MtrStalled_Cnt_T_lgc,
															   VAR(boolean, AUTOMATIC) HwActionMinReached_Cnt_T_lgc)
{			
	VAR(uint32, AUTOMATIC) AvlTimeElapsed_mS_T_u32;
	
	switch(PSASH_APSStateTranCause_Cnt_M_u08)
	{									  
		case(D_APATRNOERR_CNT_U08):
		{
			if(ApaAllowed_Cnt_T_lgc == FALSE)
			{
				PSASH_APSState_Cnt_M_u08 = D_APASTUNAVAIL_CNT_U08;
				PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;
			}
			else if((ApaCmdReq_Cnt_T_lgc == TRUE) &&
					(VehSpdTooHigh_Cnt_T_lgc == FALSE) &&
					(MtrStalled_Cnt_T_lgc == FALSE) &&
					(HwActionMinReached_Cnt_T_lgc == FALSE))
			{
				PSASH_APSState_Cnt_M_u08 = D_APASTCONTROLPROGRESS_CNT_U08;
				PSASH_TraFirstTime_Cnt_M_lgc = TRUE;
			}
			else
			{
			}

		}
		break;
		
		case(D_APATRVEHSPDHIGH_CNT_U08):
		case(D_APATRDRVACTION_CNT_U08):
		case(D_APATRMTRSTALL_CNT_U08):
		case(D_APATRANGULARERR_CNT_U08):
		{						
			if(PSASH_TraFirstTime_Cnt_M_lgc == TRUE)
			{
				GetSystemTime_mS_u32(&PSASH_AvlTime_mS_M_u32);
				PSASH_TraFirstTime_Cnt_M_lgc = FALSE;
			}
			else
			{
				DtrmnElapsedTime_mS_u32(PSASH_AvlTime_mS_M_u32, &AvlTimeElapsed_mS_T_u32);	
			
				if(AvlTimeElapsed_mS_T_u32 >= (uint32)k_PSASH_ApaExitCpTimer_mS_u16) 
				{
					PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;																		
				}
			}
		}
		break;
		
		default:
		break;					
	}
}			
/*******************************************************************************
* Name		    :	Chk_UnAvailableReady_Exit_Conds
* Description	:	Checks all exit paths from 'PSASH_Unavailable_ready' state. 
* Inputs		:	FaultActv_Cnt_T_lgc, ApaEna_Cnt_T_lgc, ApaAllowed_Cnt_T_lgc
* Outputs		:	None
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(void, AP_PSASH_APPL_CODE) Chk_UnAvailableReady_Exit_Conds(VAR(boolean, AUTOMATIC) FaultActv_Cnt_T_lgc,
																	  VAR(boolean, AUTOMATIC) ApaEna_Cnt_T_lgc,
																	  VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc)
{
	if((FaultActv_Cnt_T_lgc == TRUE) &&
	   (ApaEna_Cnt_T_lgc == TRUE))
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTDEFECT_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATROTHERERR_CNT_U08;
	}
	else if((ApaAllowed_Cnt_T_lgc == TRUE) &&
			(ApaEna_Cnt_T_lgc == TRUE))
	{
		PSASH_APSState_Cnt_M_u08 = D_APASTAVAIL_CNT_U08;
		PSASH_APSStateTranCause_Cnt_M_u08 = D_APATRNOERR_CNT_U08;
	}
	else
	{
	}

}					
/*******************************************************************************
* Name		    :	IsVehicleSpeedAbvThd
* Description	:	If 'Sig_Uls_T_f32' is greater than 'Thd_Uls_T_f32', return TRUE. 
* Inputs		:	Sig_Uls_T_f32, Thd_Uls_T_f32
* Outputs		:	ThdExcdd_Cnt_T_lgc
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) IsVehicleSpeedAbvThd(VAR(float32, AUTOMATIC) Sig_Uls_T_f32,
                                                              VAR(float32, AUTOMATIC) Thd_Uls_T_f32)
{
	VAR(boolean, AUTOMATIC) ThdExcdd_Cnt_T_lgc = FALSE;
	
	if(Sig_Uls_T_f32 > Thd_Uls_T_f32)
    {
		ThdExcdd_Cnt_T_lgc = TRUE;
    }
	
	return ThdExcdd_Cnt_T_lgc;	
} 
/*******************************************************************************
* Name		    :	IsThermLimitAbvThd
* Description	:	If 'Sig_Uls_T_f32' is greater than or equal to 'Thd_Uls_T_f32', return TRUE. 
* Inputs		:	Sig_Uls_T_f32, Thd_Uls_T_f32
* Outputs		:	ThdExcdd_Cnt_T_lgc
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) IsThermLimitAbvThd(VAR(float32, AUTOMATIC) Sig_Uls_T_f32,
                                                            VAR(float32, AUTOMATIC) Thd_Uls_T_f32)
{
	VAR(boolean, AUTOMATIC) ThdExcdd_Cnt_T_lgc = FALSE;
	
	if(Sig_Uls_T_f32 >= Thd_Uls_T_f32)
    {
		ThdExcdd_Cnt_T_lgc = TRUE;
    }
	
	return ThdExcdd_Cnt_T_lgc;	
}
/*******************************************************************************
* Name		    :	IsAssistStallBlwThd
* Description	:	If 'Sig_Uls_T_f32' is less than or equal to 'Thd_Uls_T_f32', return TRUE. 
* Inputs		:	Sig_Uls_T_f32, Thd_Uls_T_f32
* Outputs		:	ThdExcdd_Cnt_T_lgc
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) IsAssistStallBlwThd(VAR(float32, AUTOMATIC) Sig_Uls_T_f32,
                                                             VAR(float32, AUTOMATIC) Thd_Uls_T_f32)
{
	VAR(boolean, AUTOMATIC) ThdExcdd_Cnt_T_lgc = FALSE;
	
	if(Sig_Uls_T_f32 <= Thd_Uls_T_f32)
    {
		ThdExcdd_Cnt_T_lgc = TRUE;
    }
	
	return ThdExcdd_Cnt_T_lgc;	
}
/*******************************************************************************
* Name		    :	DtrmnApaAllwd
* Description	:	Implementation of "Determine Apa Allowed" block. 
* Inputs		:	ApaAuthn_Cnt_T_lgc, HandwheelAuthority_Uls_T_f32, OutputRampMult_Uls_T_f32
* Outputs		:	ApaAllowed_Cnt_T_lgc
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) DtrmnApaAllwd(VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc,
													   VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32,
													   VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32)
{
	VAR(boolean, AUTOMATIC) ApaAllowed_Cnt_T_lgc = FALSE;
	
	if((ApaAuthn_Cnt_T_lgc == TRUE) &&
	   (HandwheelAuthority_Uls_T_f32 >= k_PSASH_ApaHwAuthority_Uls_f32) &&
	   (Rte_Mode_SystemState_Mode() == RTE_MODE_StaMd_Mode_OPERATE) &&
	   (FPM_FloatToFixed_m(OutputRampMult_Uls_T_f32, u16p0_T) == D_ONE_CNT_U16))
    {
		ApaAllowed_Cnt_T_lgc = TRUE;
    }
	
	return ApaAllowed_Cnt_T_lgc;
}
/*******************************************************************************
* Name		    :	DtrmnRglnErr
* Description	:	Implementation of "Determine Regulation Errors" block. 
* Inputs		:	HandwheelPosition_HwDeg_T_f32, PosSrvoHwAngle_HwDeg_T_f32
* Outputs		:	HwPosCmdErr_Cnt_T_lgc
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) DtrmnRglnErr(VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
	                                                  VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32)
{	
	VAR(float32, AUTOMATIC) HandwheelDiff_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) DynamicError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) StaticError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwPosCmdErr_Cnt_T_lgc = FALSE;
	
	/* Dynamic Time */
	HandwheelDiff_HwDeg_T_f32 = Abs_f32_m(HandwheelPosition_HwDeg_T_f32 - PosSrvoHwAngle_HwDeg_T_f32);
	
	if((PSASH_PrevApaEnaRgln_Cnt_M_lgc == TRUE) &&
	   (FPM_FloatToFixed_m(Max_m((HandwheelDiff_HwDeg_T_f32 - PSASH_PrevHandwheelDiff_HwDeg_M_f32),0.0F),u16p0_T) >= k_PSASH_ApaDynamicHwThreshold_HwDeg_u16))
    {
		PSASH_DynTimeAcc_Cnt_M_u16 = DiagPStep_m(PSASH_DynTimeAcc_Cnt_M_u16, k_PSASH_ApaDynErr_Cnt_str);
    }
	else
	{
		PSASH_DynTimeAcc_Cnt_M_u16 = DiagNStep_m(PSASH_DynTimeAcc_Cnt_M_u16, k_PSASH_ApaDynErr_Cnt_str);
	}
    
	DynamicError_Cnt_T_lgc = DiagFailed_m(PSASH_DynTimeAcc_Cnt_M_u16, k_PSASH_ApaDynErr_Cnt_str);
	
	PSASH_PrevHandwheelDiff_HwDeg_M_f32 = HandwheelDiff_HwDeg_T_f32;
	
	/* Static Time */
	if((PSASH_PrevApaEnaRgln_Cnt_M_lgc == TRUE) &&
	   (FPM_FloatToFixed_m(HandwheelDiff_HwDeg_T_f32, u16p0_T) >= k_PSASH_ApaStaticHwThreshold_HwDeg_u16))
    {
		PSASH_StaTimeAcc_Cnt_M_u16 = DiagPStep_m(PSASH_StaTimeAcc_Cnt_M_u16, k_PSASH_ApaStaticErr_Cnt_str);
    }
	else
	{
		PSASH_StaTimeAcc_Cnt_M_u16 = DiagNStep_m(PSASH_StaTimeAcc_Cnt_M_u16, k_PSASH_ApaStaticErr_Cnt_str);
	}
    
	StaticError_Cnt_T_lgc = DiagFailed_m(PSASH_StaTimeAcc_Cnt_M_u16, k_PSASH_ApaStaticErr_Cnt_str);
	
	if((DynamicError_Cnt_T_lgc == TRUE) ||
	   (StaticError_Cnt_T_lgc == TRUE))
	{
		HwPosCmdErr_Cnt_T_lgc = TRUE;
	}
	
	return HwPosCmdErr_Cnt_T_lgc;
}
/*******************************************************************************
* Name		    :	HwIntv
* Description	:	Implementation of "Handwheel intervention" block. 
* Inputs		:	HwTorque_HwNm_T_f32, *HwActionMinReached_Cnt_T_lgc, *HwActionMaxReached_Cnt_T_lgc
* Outputs		:	None
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(void, AP_PSASH_APPL_CODE) HwIntv(VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32,
											 P2VAR(boolean, AUTOMATIC, Psash_VAR) HwActionMinReached_Cnt_T_lgc,
											 P2VAR(boolean, AUTOMATIC, Psash_VAR) HwActionMaxReached_Cnt_T_lgc)
{
	VAR(float32, AUTOMATIC) HwTrqFilt_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwTrqAbsFilt_HwNm_T_f32;
	VAR(uint32, AUTOMATIC) HwTrqFiltTimer1Elapsed_mS_T_u32;
	VAR(uint32, AUTOMATIC) HwTrqFiltTimer2Elapsed_mS_T_u32;
	
	HwTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &PSASH_HwTrqFilterSV_HwNm_M_Str);
	PSASH_HwTqFiltered_HwNm_D_f32 = HwTrqFilt_HwNm_T_f32;
	
	HwTrqAbsFilt_HwNm_T_f32 = Abs_f32_m(HwTrqFilt_HwNm_T_f32);
	
	if (HwTrqAbsFilt_HwNm_T_f32 > k_PSASH_ApaHwTrqMin_HwNm_f32)													
	{
		DtrmnElapsedTime_mS_u32(PSASH_HwTrqFiltStartTime1_mS_M_u32, &HwTrqFiltTimer1Elapsed_mS_T_u32);	
		
		if(HwTrqFiltTimer1Elapsed_mS_T_u32 >= (uint32)k_PSASH_ApaHwTrqMinTi_mS_u16) 
		{
			*HwActionMinReached_Cnt_T_lgc = TRUE;																		
		}
	}
	else
	{
		GetSystemTime_mS_u32(&PSASH_HwTrqFiltStartTime1_mS_M_u32);											
	}
	
	if (HwTrqAbsFilt_HwNm_T_f32 > k_PSASH_ApaHwTrqMax_HwNm_f32)													
	{
		DtrmnElapsedTime_mS_u32(PSASH_HwTrqFiltStartTime2_mS_M_u32, &HwTrqFiltTimer2Elapsed_mS_T_u32);	
		
		if(HwTrqFiltTimer2Elapsed_mS_T_u32 >= (uint32)k_PSASH_ApaHwTrqMaxTi_mS_u16) 
		{
			*HwActionMaxReached_Cnt_T_lgc = TRUE;																		
		}
	}
	else
	{
		GetSystemTime_mS_u32(&PSASH_HwTrqFiltStartTime2_mS_M_u32);											
	}
}
/*******************************************************************************
* Name		    :	DtrmnSysFlt
* Description	:	Implementation of "Determine Regulation Errors" block. 
* Inputs		:	HandwheelPosition_HwDeg_T_f32, PosSrvoHwAngle_HwDeg_T_f32
* Outputs		:	FaultActv_Cnt_T_lgc
* Usage Notes   :   None
*****************************************************************************/
STATIC FUNC(boolean, AP_PSASH_APPL_CODE) DtrmnSysFlt(VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc,
													 VAR(boolean, AUTOMATIC) CpkOk_Cnt_T_lgc,
													 VAR(boolean, AUTOMATIC) PosSrvoNTC_Cnt_T_lgc,
													 VAR(boolean, AUTOMATIC) FTermActv_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) FaultActv_Cnt_T_lgc = FALSE;
	
	if((VehicleSpeedValid_Cnt_T_lgc == FALSE) ||
	   (CpkOk_Cnt_T_lgc == FALSE) ||
	   (PosSrvoNTC_Cnt_T_lgc == TRUE) ||
	   (FTermActv_Cnt_T_lgc == TRUE))
    {
		FaultActv_Cnt_T_lgc = TRUE;
    }
	
	return FaultActv_Cnt_T_lgc;
}	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
