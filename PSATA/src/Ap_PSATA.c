/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PSATA.c
 *     Workspace:  C:/Sankar/Synergy/Working/PSATA-pznywf/PSATA/autosar
 *     SW-C Type:  Ap_PSATA
 *  Generated at:  Wed Mar 18 13:24:41 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PSATA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
 * Copyright 2014 Nexteer
 * Nexteer Confidential
 *
 * Module File Name	 : Ap_PSATA.c
 * Module Description: Implementation of CF14
 * Project           : CBD
 * Author            : Sankardu Varadapureddi
 *****************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       pznywf %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                              SCR #
 * -------   -------  --------  ------------------------------------------------------------------------------  -------
 * 03/11/15  1        SV        Initial Version                                                                 13099
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_PSATA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "fixmath.h"
#include "Interpolation.h"
#include "GlobalMacro.h"

/* PRQA S 4395 EOF
* MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

#define	D_NTCHIGH_CNT_LGC					TRUE
#define	D_NTCLOW_CNT_LGC					FALSE
#define D_POSSRVONTCENABLE_MTRNM_F32		0.0F
#define D_POSSRVOTRANSITION_ULS_F32			0.01999999955F
#define	D_SMOOTHINGHIGH_CNT_F32				1.0F
#define	D_SMOOTHINGLOW_CNT_F32				0.0F

#define PSATA_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) PSATA_PosSrvoNTC_Cnt_M_lgc;
#define PSATA_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


#define PSATA_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) PSATA_PNAccumulator_Cnt_M_u16; /* PRQA S 3218 */
STATIC volatile VAR(uint16, AUTOMATIC) PSATA_PNAccumulator_Cnt_D_u16;  /* PRQA S 3218 */
#define PSATA_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define PSATA_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_PSATA_VAR) PSATA_PosServoSmoothing_Uls_M_f32;
STATIC VAR(float32, AP_PSATA_VAR) PSATA_PrevIntermPosSrvoCmd_MtrNm_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_PSATA_VAR) PSATA_PrevSlewRateLmt_Uls_M_f32; /* PRQA S 3218 */
#define PSATA_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define PSATA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_PSATA_VAR)	PSATA_FilterdTrqSV_HwNm_M_Str;
#define PSATA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Function Prototypes */

STATIC FUNC(void, AP_PSATA_APPL_CODE) Cal_PosSrvoNTC(VAR(float32,AUTOMATIC) PosSrvoCmd_MtrNm_T_f32,
													 VAR(boolean,AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
													 VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32);

STATIC FUNC(void, AP_PSATA_APPL_CODE) Cal_PosServoSmoothingFactor(VAR(float32,AUTOMATIC) HwTorque_HwNm_T_f32,
		                                                          VAR(boolean,AUTOMATIC) PosSrvoEnable_Cnt_T_lgc);


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
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PeripheralStartupFlt (55u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_GateDrvFltInProcess (76u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_BattTransOverVolt (182u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_InvalidMsg_AJ (472u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_InvalidMsg_AK (480u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ZERO_ULS_F32 = 0
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PSATA_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSATA_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSATA_APPL_CODE) PSATA_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSATA_Init1
 *********************************************************************************************************************/

	LPF_Init_f32_m(D_ZERO_ULS_F32, k_PSATA_FilterCutOff_Hz_f32, D_2MS_SEC_F32, &PSATA_FilterdTrqSV_HwNm_M_Str);

	(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SigPath5CrossChk, D_ZERO_CNT_U8, NTC_STATUS_PASSED);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSATA_Per1
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
 *   Float Rte_IRead_PSATA_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PSATA_Per1_PosSrvoCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_PSATA_Per1_PosSrvoEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PSATA_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PSATA_Per1_OpTrqOv_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_PSATA_Per1_OpTrqOv_MtrNm_f32(void)
 *   void Rte_IWrite_PSATA_Per1_PosSrvoNTC_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PSATA_Per1_PosSrvoNTC_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PSATA_APPL_CODE) PSATA_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSATA_Per1
 *********************************************************************************************************************/
	/* Temporary variables for inputs */
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) PosSrvoCmd_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) PosSrvoEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;

	/* Temporary variables for intermediate calculations */
	VAR(boolean, AUTOMATIC) Smoothing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PosSrvoEnableSmoothing_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) IntermPosSrvoCmd_MtrNm_T_f32;

	/* Temporary variables for outputs */
	VAR(float32, AUTOMATIC) OpTrqOv_MtrNm_T_f32;

	/* read Inputs */
	HwTorque_HwNm_T_f32 = Rte_IRead_PSATA_Per1_HwTorque_HwNm_f32();			/* REQ: CF14 #12 I */
	PosSrvoCmd_MtrNm_T_f32 = Rte_IRead_PSATA_Per1_PosSrvoCmd_MtrNm_f32();	/* REQ: CF14 #11 I */
	PosSrvoEnable_Cnt_T_lgc = Rte_IRead_PSATA_Per1_PosSrvoEnable_Cnt_lgc();	/* REQ: CF14 #10 I */
	VehicleSpeed_Kph_T_f32 = Rte_IRead_PSATA_Per1_VehicleSpeed_Kph_f32();	/* REQ: CF14 #13 I */

	/* Determine 'PSATA_PosSrvoNTC_Cnt_M_lgc' */
	Cal_PosSrvoNTC(PosSrvoCmd_MtrNm_T_f32,PosSrvoEnable_Cnt_T_lgc,VehicleSpeed_Kph_T_f32);

	/* REQ: CF14 #31 I */
	/* REQ: CF14 #37 I */
	/* REQ: CF14 #38 I */
	/* calculate  Smoothing factor 'PSATA_PosServoSmoothing_Uls_M_f32' */
	Cal_PosServoSmoothingFactor (HwTorque_HwNm_T_f32,PosSrvoEnable_Cnt_T_lgc);
	/* ENDREQ: CF14 #31 */

	if(D_POSSRVOTRANSITION_ULS_F32 <= PSATA_PosServoSmoothing_Uls_M_f32)
	{
		Smoothing_Cnt_T_lgc = TRUE;
	}
	else
	{
		Smoothing_Cnt_T_lgc = FALSE;
	}

	if ((PosSrvoEnable_Cnt_T_lgc == TRUE) && (Smoothing_Cnt_T_lgc == TRUE))
	{
		PosSrvoEnableSmoothing_Cnt_T_lgc = TRUE;
	}
	else
	{
		PosSrvoEnableSmoothing_Cnt_T_lgc = FALSE;
	}

	if(PosSrvoEnableSmoothing_Cnt_T_lgc == TRUE)
	{
		IntermPosSrvoCmd_MtrNm_T_f32 = PosSrvoCmd_MtrNm_T_f32;
	}
	else
	{
		IntermPosSrvoCmd_MtrNm_T_f32 = PSATA_PrevIntermPosSrvoCmd_MtrNm_M_f32;
	}
	PSATA_PrevIntermPosSrvoCmd_MtrNm_M_f32 = IntermPosSrvoCmd_MtrNm_T_f32;
	/* ENDREQ: CF14 #37 */
	/* ENDREQ: CF14 #38 */

	/* REQ: CF14 #28 I */
	/* REQ: CF14 #29 I */
	if (PSATA_PosSrvoNTC_Cnt_M_lgc >= D_TRUE_CNT_LGC)
	{
		OpTrqOv_MtrNm_T_f32 = D_POSSRVONTCENABLE_MTRNM_F32;
	}
	else
	{
		OpTrqOv_MtrNm_T_f32 = IntermPosSrvoCmd_MtrNm_T_f32 * PSATA_PosServoSmoothing_Uls_M_f32;
	}
	/* ENDREQ: CF14 #28 */
	/* ENDREQ: CF14 #29 */

	/* limit 'OpTrqOv_MtrNm_T_f32' */
	OpTrqOv_MtrNm_T_f32 = Limit_m(OpTrqOv_MtrNm_T_f32, D_MTRTRQCMDLOLMT_MTRNM_F32, D_MTRTRQCMDHILMT_MTRNM_F32);

	/* write outputs */
	Rte_IWrite_PSATA_Per1_OpTrqOv_MtrNm_f32(OpTrqOv_MtrNm_T_f32);			/* REQ: CF14 #16 I */
	Rte_IWrite_PSATA_Per1_PosSrvoNTC_Cnt_lgc(PSATA_PosSrvoNTC_Cnt_M_lgc);	/* REQ: CF14 #15 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PSATA_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_PSATA_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/* Sub Functions */
/*****************************************************************************************************************
  * Name		:	Cal_PosSrvoNTC_Cnt_T_lgc
  * Description	:	This function monitors 'State Handler' and 'PosServo' for errors. Sets 'PosSrvoNTC_Cnt_lgc'
  *                 signal accordingly.
  *                 Note: This implementation corresponds to lower half of 'PSATA_Per1' block.
  * Inputs		:	PosSrvoCmd_MtrNm_T_f32, PosSrvoEnable_Cnt_T_lgc
  * Outputs		:	None
  * Usage Notes :   None
  ****************************************************************************************************************/

STATIC FUNC(void, AP_PSATA_APPL_CODE) Cal_PosSrvoNTC(VAR(float32,AUTOMATIC) PosSrvoCmd_MtrNm_T_f32,
													 VAR(boolean,AUTOMATIC) PosSrvoEnable_Cnt_T_lgc,
													 VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32)
{
	VAR(boolean, AUTOMATIC) CmdOvrThresh_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpeedOvrThresh_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PreDiagCondition_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagCondition_Cnt_T_lgc;

	/* REQ: CF14 #25 I */
	if((Abs_f32_m(PosSrvoCmd_MtrNm_T_f32)) > k_PSATA_MaxPosServoCmdSafety_MtrNm_f32)
	{
		CmdOvrThresh_Cnt_T_lgc = TRUE;
	}
	else
	{
		CmdOvrThresh_Cnt_T_lgc = FALSE;
	}
	/* ENDREQ: CF14 #25 */

	/* REQ: CF14 #26 I */
	if(VehicleSpeed_Kph_T_f32 > k_PSATA_MaxVehicleSpeedSafety_Kph_f32)
	{
		SpeedOvrThresh_Cnt_T_lgc = TRUE;
	}
	else
	{
		SpeedOvrThresh_Cnt_T_lgc = FALSE;
	}

	if ((SpeedOvrThresh_Cnt_T_lgc == TRUE)||
	   (PosSrvoEnable_Cnt_T_lgc == FALSE))
	{
		PreDiagCondition_Cnt_T_lgc = TRUE;
	}
	else
	{
		PreDiagCondition_Cnt_T_lgc = FALSE;
	}
	/* ENDREQ: CF14 #26 */

	if ((CmdOvrThresh_Cnt_T_lgc == TRUE)&&
		(PreDiagCondition_Cnt_T_lgc == TRUE))
	{
		DiagCondition_Cnt_T_lgc = TRUE;
	}
	else
	{
		DiagCondition_Cnt_T_lgc = FALSE;
	}

	/* REQ: CF14 #27 I */
	if(DiagCondition_Cnt_T_lgc == TRUE)   /* when fault condition is active */
	{
		/* Increment fault accumulator */
		PSATA_PNAccumulator_Cnt_M_u16 =  DiagPStep_m(PSATA_PNAccumulator_Cnt_M_u16, k_PSATA_NTCPosServFltMode_Cnt_Str);
	}
	else	/* when fault condition is not active */
	{
		/* Decrement fault accumulator */
		PSATA_PNAccumulator_Cnt_M_u16 =  DiagNStep_m(PSATA_PNAccumulator_Cnt_M_u16, k_PSATA_NTCPosServFltMode_Cnt_Str);
	}
	PSATA_PNAccumulator_Cnt_D_u16 = PSATA_PNAccumulator_Cnt_M_u16;
	/* ENDREQ: CF14 #27 */

	if( DiagFailed_m(PSATA_PNAccumulator_Cnt_M_u16, k_PSATA_NTCPosServFltMode_Cnt_Str) == TRUE ) /* Check accumulator for NTC failed condition. */
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SigPath5CrossChk, D_ZERO_CNT_U8, NTC_STATUS_FAILED); /* NTC latched for the Ignition cycle */

		/* REQ: CF14 #24 I */
		PSATA_PosSrvoNTC_Cnt_M_lgc = D_NTCHIGH_CNT_LGC;
	}
	else
	{
		/* This NTC is ignition latched.*/
	}
}

/*****************************************************************************************************************
  * Name		:	Cal_PosServoSmoothingFactor
  * Description	:	Implementation of 'PosServoSmoothing' block.
  *                 PosServoCmd changes instantly from zero when disabled to non-zero when enabled, and vice-versa.
  *					This routine calculates a scale factor for the PosServoCmd to smoothly ramp it in and out.
  *					First, it produces a linear scale factor, then feeds the linear factor into a lookup table to
  *					non-linearize it.This produces softer transitions when scale factor is near zero or near unity.
  *					The scale factor can decrease more rapidly when driver hand wheel torque is present.
  * Inputs		:	HwTorque_HwNm_T_f32, PosSrvoEnable_Cnt_T_lgc
  * Outputs		:	None
  * Usage Notes :   None
  ****************************************************************************************************************/
STATIC FUNC(void, AP_PSATA_APPL_CODE) Cal_PosServoSmoothingFactor(VAR(float32,AUTOMATIC) HwTorque_HwNm_T_f32,
		                                                          VAR(boolean,AUTOMATIC) PosSrvoEnable_Cnt_T_lgc)
{
	VAR(float32, AP_PSATA_VAR) HwTorqueFilt_HwNm_T_f32;
	VAR(uint16, AP_PSATA_VAR) HwTorqueFilt_HwNm_T_u11p5;
	VAR(uint16, AP_PSATA_VAR) DisableRate_UlspS_T_u11p5;
	VAR(float32, AP_PSATA_VAR) DisableRate_UlspS_T_f32;
	VAR(float32, AP_PSATA_VAR) RateLimitLo_UlspS_T_f32;

	VAR(float32, AP_PSATA_VAR) SmoothingConst_Uls_T_f32;
	VAR(float32, AP_PSATA_VAR) SlewRateLmt_Uls_T_f32;
	VAR(uint16, AP_PSATA_VAR) SlewRateLmt_Uls_T_u6p10;
	VAR(uint16, AP_PSATA_VAR) SmoothingFactor_Uls_u6p10;

	HwTorqueFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32,&PSATA_FilterdTrqSV_HwNm_M_Str);	/* REQ: CF14 #35 I */

	HwTorqueFilt_HwNm_T_u11p5 = FPM_FloatToFixed_m((Abs_f32_m(HwTorqueFilt_HwNm_T_f32)), u11p5_T);

	DisableRate_UlspS_T_u11p5 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PSATA_DisableRateX_HwNm_u11p5,
															t_PSATA_DisableRateY_UlspS_u11p5,
                      										TableSize_m(t_PSATA_DisableRateX_HwNm_u11p5),
                      										HwTorqueFilt_HwNm_T_u11p5);
	DisableRate_UlspS_T_f32 = FPM_FixedToFloat_m(DisableRate_UlspS_T_u11p5,u11p5_T);
	RateLimitLo_UlspS_T_f32 = -(Max_m(DisableRate_UlspS_T_f32,k_PSATA_DisableRate_UlspS_f32));  /* REQ: CF14 #35 I */

	/* REQ: CF14 #32 I */
	/* REQ: CF14 #33 I */
	if(PosSrvoEnable_Cnt_T_lgc != FALSE)
	{
		SmoothingConst_Uls_T_f32 = D_SMOOTHINGHIGH_CNT_F32;
	}
	else
	{
		SmoothingConst_Uls_T_f32 = D_SMOOTHINGLOW_CNT_F32;
	}
	/* ENDREQ: CF14 #32 */
	/* ENDREQ: CF14 #33 */

	SlewRateLmt_Uls_T_f32 = Limit_m(SmoothingConst_Uls_T_f32,
			                        (PSATA_PrevSlewRateLmt_Uls_M_f32+(RateLimitLo_UlspS_T_f32*D_2MS_SEC_F32)),
			                        (PSATA_PrevSlewRateLmt_Uls_M_f32+(k_PSATA_APAEnableRate_UlspS_f32*D_2MS_SEC_F32)));   /* REQ: CF14 #34 I */
	PSATA_PrevSlewRateLmt_Uls_M_f32 = SlewRateLmt_Uls_T_f32;

	SlewRateLmt_Uls_T_u6p10 = FPM_FloatToFixed_m(SlewRateLmt_Uls_T_f32, u6p10_T);
	SmoothingFactor_Uls_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt(t_PSATA_SmoothingX_Uls_u6p10,
			                                                t_PSATA_SmoothingY_Uls_u6p10,
			                                                TableSize_m(t_PSATA_SmoothingX_Uls_u6p10),
			                                                SlewRateLmt_Uls_T_u6p10);
	PSATA_PosServoSmoothing_Uls_M_f32 = FPM_FixedToFloat_m(SmoothingFactor_Uls_u6p10, u6p10_T);
}

#define RTE_STOP_SEC_AP_PSATA_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
