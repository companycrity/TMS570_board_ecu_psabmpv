/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComOutput.c
 *     Workspace:  C:/synergy_projects_working/PSA3.5.1/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Tue Apr  5 17:17:12 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComOutput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          EA3#17 %
 * %derived_by:       fzh7xw %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author   Change Description                                                               SCR #
 * --------   -------  -------  ------------------------------------------------------------------------------  -------
 * 02/06/14    1       OT       Initial Version
 * 04/24/14    2       OT       Anomaly 6580 - fixed message length on CRC calculation
 *                              Anomaly 6559 - ramp down complete and vehicle speed valid inputs not connected
 * 05/13/14    3       OT       Anomaly 6713 - wait for TMF to complete before enabling Tx
 * 05/20/14    4       OT       Anomaly 6795 - send HwPos signal centered on first transmitted message position
 * 06/03/14    5       OT       Removed CanXcp references for production SIP integration
 * 06/10/14    6       OT       Updates for QAC errors
 * 09/02/14    7       OT       Updates for new MPU configuration                                                12249
 * 09/19/14    8       OT       Updates for added PosServo messages                                              12259
 * 10/14/14    9       OT       Updates for remaining customer messages                                          12539
 * 01/13/15   10       OT       Correct HwVel scaling                                                            12858
 * 06/08/15   11       OT       Added 2004 functionality                                                         13302
 * 07/09/15   12       OT       Corrected CODE_DEFAUT logic                                                      13470
 * 07/31/15   13       OT       Implemented CityPark output signals                                           EA3#2218
 * 09/17/15   14       OT       Added rounding factors                                                        EA3#2929
 * 10/02/15   15       OT       Corrected ETAT_SECU_ANGLE_COL disable criteria                                EA3#3501
 * 04/05/16   16       WH       Updated to use relhwpos for angle_colonne calculation                         EA3#7240
 * 05/16/16   17       WH       Update CF013B interfaces							                          EA3#8384
 * 07/19/16   18       WH       Update Handwheel Authority to a cal									          EA3#9021
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComOutput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "il_inc.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "fixmath.h"


#define D_CPLEVOLANTOPTMSELOLMT_HWNM_F32		(-10.0f)
#define D_CPLEVOLANTOPTMSEHILMT_HWNM_F32		10.0f
#define D_CPLEVOLANTOPTMSESCALE_HWNMPCNT_F32	0.1f
#define D_ANGLECOLONNELOLMT_HWDEG_F32			(-1630.0f)
#define D_ANGLECOLONNEHILMT_HWDEG_F32			1630.0f
#define D_ANGLECOLONNESCALE_HWDEGPCNT_F32		0.1f
#define D_VITESSECOLONNELOLMT_HWDEGPS_F32		(-2000.0f)
#define D_VITESSECOLONNEHILMT_HWDEGPS_F32		2000.0f
#define D_CPLEVOLANTLOLMT_HWNM_F32				(-32.0f)
#define D_CPLEVOLANTHILMT_HWNM_F32				31.5f
#define D_CPLEVOLANTSCALE_HWNMPCNT_F32			0.25f

#define ApplyRounding_f32(x)	( ((x) < 0.0f) ? ((x) - 0.5f) : ((x) + 0.5f) ) /* PRQA S 3453 */


#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32,  AP_SRLCOMOUTPUT_VAR) ETATSECUANGLECOLSigTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMOUTPUT_VAR) DDEREDEMDASigValidTimer_mS_M_u32;
STATIC VAR(float32, AP_SRLCOMOUTPUT_VAR) InitialHandwheelPosition_HwDeg_M_f32; /* PRQA S 3218 */
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


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
 * IoHwAb_BoolType: Integer in interval [0...1]
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_IndicatorStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DEM_INDICATOR_OFF (0U)
 *   DEM_INDICATOR_CONTINUOUS (1U)
 *   DEM_INDICATOR_BLINKING (2U)
 *   DEM_INDICATOR_BLINK_CONT (3U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PeripheralStartupFlt (55U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
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
 * UInt16: D_FIFTEEN_CNT_U16 = 15U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_SEVEN_CNT_U16 = 7U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_FOUR_CNT_U08 = 4U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_THREE_CNT_U08 = 3U
 * UInt8: D_TWO_CNT_U08 = 2U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Init
 *********************************************************************************************************************/
	
	
	VAR(uint32, AUTOMATIC) SystemTime_mS_T_u32;
	
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3200 */
	ETATSECUANGLECOLSigTimer_mS_M_u32 = SystemTime_mS_T_u32;
	DDEREDEMDASigValidTimer_mS_M_u32 = SystemTime_mS_T_u32;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComOutput_Per1_APAState_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32(void)
 *   Float Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_RelHwPos_HwDeg_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(void)
 *   void Rte_IWrite_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDA2004_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDA2004_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDA2010_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDA2010_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDADYN_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDADYN_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(void)
 *   void Rte_IWrite_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(void)
 *   void Rte_IWrite_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_IndStatusETATDA2_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IndicatorStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint8,   AUTOMATIC) APAStateTransitionCause_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) APAState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) AVASelected_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CTCFailed_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CityParkSelected_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DefaultHwaSCommExportValue_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) EtatMT_Cnt_T_u08;
	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
	VAR(boolean, AUTOMATIC) ISDYNDAEFirstMessageSent_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;
	VAR(boolean, AUTOMATIC) RampDwnStatusComplete_T_lgc;
	VAR(boolean, AUTOMATIC) STTdSelected_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComHwTrq_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) ValidEngineStatus_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(boolean, AUTOMATIC) EPSEn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T1vsT2_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T1OutofRange_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) T2OutofRange_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ReducedAsstLowVoltage_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DutyCycleExceeded_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) AbsTempThermLimit_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LowVoltageStopMode_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) IgnitionFailure_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffCh1_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffCh1NodeMute_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Node1AAbsent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Node1BAbsent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Node1CAbsent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Node1DAbsent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Node1EAbsent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) InvalidMsgQ_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgQ_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataOtherFltMsgQ_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TrqSensorNotTrimmed_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ETATDA2_Cnt_T_lgc;
	
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) CPLEVOLANTOPTMSE_Cnt_T_f32;
	VAR(float32, AUTOMATIC) ANGLECOLONNE_Cnt_T_f32;
	VAR(float32, AUTOMATIC) VITESSECOLONNE_HwDegpS_T_f32;
	VAR(sint16,  AUTOMATIC) VITESSECOLONNE_HwDegpS_T_s16;
	VAR(float32, AUTOMATIC) CPLEVOLANT_Cnt_T_f32;
	VAR(float32, AUTOMATIC) AbsHandwheelTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsHandwheelVelocity_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsHandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) RelHandwheelPosition_HwDeg_T_f32;
	
	VAR(uint8,  AUTOMATIC) CPLEVOLANTOPTMSE_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ETATDAECPK_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) CAUSEDESACTIVCPK_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ANGLECOLONNE_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) VITESSECOLONNE_Cnt_T_u16;
	VAR(uint8,  AUTOMATIC) ETATSECUANGLECOL_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) CPLEVOLANT_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ETATDA2004_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ETATDA2010_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ETATDADYN_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) DDEREDEMDA_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) AUTORARRETMOTDA_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) CODEDEFAUT_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) STATUSCONFABSENT_Cnt_T_u32;
	VAR(uint8,  AUTOMATIC) ETATLIGNEAPC_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) ETATASSISTDA_Cnt_T_u08;
	
	
	
	APAStateTransitionCause_Cnt_T_u08 = Rte_IRead_SrlComOutput_Per1_APAStateTransitionCause_Cnt_u08();
	APAState_Cnt_T_u08 = Rte_IRead_SrlComOutput_Per1_APAState_Cnt_u08();
	AVASelected_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_AVASelected_Cnt_lgc();
	CTCFailed_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_CTCFailed_Cnt_lgc();
	CityParkSelected_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_CityParkSelected_Cnt_lgc();
	DefaultHwaSCommExportValue_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_DefaultHwaSCommExportValue_Cnt_lgc();
	EtatMT_Cnt_T_u08 = Rte_IRead_SrlComOutput_Per1_EtatMT_Cnt_u08();
	HandwheelAuthority_Uls_T_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelAuthority_Uls_f32();
	HandwheelPosition_HwDeg_T_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelPosition_HwDeg_f32();
	HandwheelTorque_HwNm_T_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelTorque_HwNm_f32();
	HandwheelVelocity_HwRadpS_T_f32 = Rte_IRead_SrlComOutput_Per1_HandwheelVelocity_HwRadpS_f32();
    RelHandwheelPosition_HwDeg_T_f32 = Rte_IRead_SrlComOutput_Per1_RelHwPos_HwDeg_f32();
	ISDYNDAEFirstMessageSent_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_ISDYNDAEFirstMessageSent_Cnt_lgc();
	OutputRampMult_Uls_T_f32 = Rte_IRead_SrlComOutput_Per1_OutputRampMult_Uls_f32();
	RampDwnStatusComplete_T_lgc = Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc();
	STTdSelected_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_STTdSelected_Cnt_lgc();
	SrlComHwTrq_HwNm_T_f32 = Rte_IRead_SrlComOutput_Per1_SrlComHwTrq_HwNm_f32();
	ValidEngineStatus_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_ValidEngineStatus_Cnt_lgc();
	VehicleSpeedValid_Cnt_T_lgc = Rte_IRead_SrlComOutput_Per1_VehicleSpeedValid_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_SrlComOutput_Per1_VehicleSpeed_Kph_f32();
	Rte_Call_EpsEn_OP_GET(&EPSEn_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T1vsT2, &T1vsT2_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T1OutofRange, &T1OutofRange_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_T2OutofRange, &T2OutofRange_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_ReducedAsstLowVoltage, &ReducedAsstLowVoltage_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DutyCycleExceeded, &DutyCycleExceeded_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_AbsTempThermLimit, &AbsTempThermLimit_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_06, &LowVoltageStopMode_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_08, &IgnitionFailure_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_BusOffCh1, &BusOffCh1_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_BusOffCh1NodeMute, &BusOffCh1NodeMute_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Node1AAbsent, &Node1AAbsent_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Node1BAbsent, &Node1BAbsent_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Node1CAbsent, &Node1CAbsent_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Node1DAbsent, &Node1DAbsent_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Node1EAbsent, &Node1EAbsent_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_Q, &InvalidMsgQ_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_Q, &MissingMsgQ_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_Q, &DataOtherFltMsgQ_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_TrqSensorNotTrimmed, &TrqSensorNotTrimmed_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_IndStatusETATDA2_GetIndicatorStatus(&ETATDA2_Cnt_T_lgc); /* PRQA S 3200 */
	
	
	
	/*** IS_DYN_DAE (Msg ID 2F5) ***/
	
	/* CPLE_VOLANT_OPTMSE */
	if( CityParkSelected_Cnt_T_lgc == FALSE )
	{
		CPLEVOLANTOPTMSE_Cnt_T_u08 = (uint8)kCPLE_VOLANT_OPTMSE_Invalid;
	}
	else
	{
		CPLEVOLANTOPTMSE_Cnt_T_f32 = Limit_m(HandwheelTorque_HwNm_T_f32, D_CPLEVOLANTOPTMSELOLMT_HWNM_F32, D_CPLEVOLANTOPTMSEHILMT_HWNM_F32) / D_CPLEVOLANTOPTMSESCALE_HWNMPCNT_F32;
		CPLEVOLANTOPTMSE_Cnt_T_f32 = ApplyRounding_f32(CPLEVOLANTOPTMSE_Cnt_T_f32);
		CPLEVOLANTOPTMSE_Cnt_T_u08 = (uint8)((sint8)CPLEVOLANTOPTMSE_Cnt_T_f32);
	}
	
	/* ETAT_DAE_CPK */
	
	ETATDAECPK_Cnt_T_u08 = APAState_Cnt_T_u08;

	/* CAUSE_DESACTIV_CPK */
	
	CAUSEDESACTIVCPK_Cnt_T_u08 = APAStateTransitionCause_Cnt_T_u08;

	/* ANGLE_COLONNE */
	if( ISDYNDAEFirstMessageSent_Cnt_T_lgc == FALSE )
	{
		InitialHandwheelPosition_HwDeg_M_f32 = RelHandwheelPosition_HwDeg_T_f32;
	}
	
	if( (DefaultHwaSCommExportValue_Cnt_T_lgc == TRUE) ||
		(AVASelected_Cnt_T_lgc == FALSE) ||
		((uint8)kETAT_DAE_CPK_Control_In_Progress == APAState_Cnt_T_u08) )
	{
		ANGLECOLONNE_Cnt_T_u16 = (uint16)kANGLE_COLONNE_Invalid;
	}
	else
	{
		ANGLECOLONNE_Cnt_T_f32 = Limit_m((RelHandwheelPosition_HwDeg_T_f32 - InitialHandwheelPosition_HwDeg_M_f32) * (-1.0f), D_ANGLECOLONNELOLMT_HWDEG_F32, D_ANGLECOLONNEHILMT_HWDEG_F32) / D_ANGLECOLONNESCALE_HWDEGPCNT_F32;
		ANGLECOLONNE_Cnt_T_f32 = ApplyRounding_f32(ANGLECOLONNE_Cnt_T_f32);
		ANGLECOLONNE_Cnt_T_u16 = (uint16)((sint16)ANGLECOLONNE_Cnt_T_f32);
	}
	
	/* VITESSE_COLONNE */
	if( (DefaultHwaSCommExportValue_Cnt_T_lgc == TRUE) ||
		(AVASelected_Cnt_T_lgc == FALSE) )
	{
		VITESSECOLONNE_Cnt_T_u16 = (uint16)kVITESSE_COLONNE_Invalid;
	}
	else
	{
		VITESSECOLONNE_HwDegpS_T_f32 = Limit_m(HandwheelVelocity_HwRadpS_T_f32 * D_180OVRPI_ULS_F32 * (-1.0f), D_VITESSECOLONNELOLMT_HWDEGPS_F32, D_VITESSECOLONNEHILMT_HWDEGPS_F32);
		VITESSECOLONNE_HwDegpS_T_f32 = ApplyRounding_f32(VITESSECOLONNE_HwDegpS_T_f32);
		VITESSECOLONNE_HwDegpS_T_s16 = (sint16)VITESSECOLONNE_HwDegpS_T_f32;
		VITESSECOLONNE_Cnt_T_u16 = ((uint16)VITESSECOLONNE_HwDegpS_T_s16) & 0x0FFFu;
	}
	
	/* ETAT_SECU_ANGLE_COL */
	if( (DefaultHwaSCommExportValue_Cnt_T_lgc == TRUE) ||
		(ISDYNDAEFirstMessageSent_Cnt_T_lgc == FALSE) ||
		(AVASelected_Cnt_T_lgc == FALSE) )
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&ETATSECUANGLECOLSigTimer_mS_M_u32); /* PRQA S 3200 */
		ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Not_Secure;
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ETATSECUANGLECOLSigTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		if( ElapsedTime_mS_T_u16 >= k_ETATSECUANGLECOLSigTimeout_mS_u16 )
		{
			ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Secure;
		}
		else
		{
			ETATSECUANGLECOL_Cnt_T_u08 = (uint8)kETAT_SECU_ANGLE_COL_Not_Secure;
		}
	}
	
	
	
	/*** IS_DAT_DIRA (Msg ID 495) ***/
	
	/* CPLE_VOLANT */
	if( (T1vsT2_Cnt_T_lgc == TRUE) ||
		(T1OutofRange_Cnt_T_lgc == TRUE) ||
		(T2OutofRange_Cnt_T_lgc == TRUE) ||
		(TrqSensorNotTrimmed_Cnt_T_lgc == TRUE) )
	{
		CPLEVOLANT_Cnt_T_u08 = (uint8)kCPLE_VOLANT_Invalid;
	}
	else
	{
		CPLEVOLANT_Cnt_T_f32 = Limit_m(SrlComHwTrq_HwNm_T_f32, D_CPLEVOLANTLOLMT_HWNM_F32, D_CPLEVOLANTHILMT_HWNM_F32) / D_CPLEVOLANTSCALE_HWNMPCNT_F32;
		CPLEVOLANT_Cnt_T_f32 = ApplyRounding_f32(CPLEVOLANT_Cnt_T_f32);
		CPLEVOLANT_Cnt_T_u08 = (uint8)((sint8)CPLEVOLANT_Cnt_T_f32);
	}
	
	/* ETAT_DA_2004 */
	if( (k_JDD2010Selected_Cnt_lgc == TRUE) ||
		(ETATDA2_Cnt_T_lgc == TRUE) )
	{
		ETATDA2004_Cnt_T_u08 = (uint8)kETAT_DA_2004_Orange_LED;
	}
	else
	{
		ETATDA2004_Cnt_T_u08 = (uint8)kETAT_DA_2004_No_Demand;
	}
	
	/* ETAT_DA_2010 */
	if( (k_JDD2010Selected_Cnt_lgc == FALSE) ||
		(ETATDA2_Cnt_T_lgc == TRUE) )
	{
		ETATDA2010_Cnt_T_u08 = (uint8)kETAT_DA_2010_Orange_LED;
	}
	else
	{
		ETATDA2010_Cnt_T_u08 = (uint8)kETAT_DA_2010_No_Demand;
	}
	
	/* ETAT_DA_DYN */
	ETATDADYN_Cnt_T_u08 = (uint8)kETAT_DA_DYN_Normal_Mode;
	
	/* DDE_REDEM_DA and AUTOR_ARRET_MOT_DA */
	if( STTdSelected_Cnt_T_lgc == FALSE )
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&DDEREDEMDASigValidTimer_mS_M_u32); /* PRQA S 3200 */
		
		if( (DutyCycleExceeded_Cnt_T_lgc == TRUE) ||
			(AbsTempThermLimit_Cnt_T_lgc == TRUE) ||
			(LowVoltageStopMode_Cnt_T_lgc == TRUE) ||
			(ValidEngineStatus_Cnt_T_lgc == FALSE) )
		{
			DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_Request_Reboot;
			AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;
		}
		else
		{
			DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_No_Reboot_Required;
			AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
		}
	}
	else
	{
		AbsHandwheelTorque_HwNm_T_f32 = Abs_f32_m(HandwheelTorque_HwNm_T_f32);
		AbsHandwheelVelocity_HwRadpS_T_f32 = Abs_f32_m(HandwheelVelocity_HwRadpS_T_f32);
		AbsHandwheelPosition_HwDeg_T_f32 = Abs_f32_m(HandwheelPosition_HwDeg_T_f32);
		
		if( OutputRampMult_Uls_T_f32 > 0.0001f )
		{
			
			if( ( (T1vsT2_Cnt_T_lgc == TRUE) ||
				  (T1OutofRange_Cnt_T_lgc == TRUE) ||
				  (T2OutofRange_Cnt_T_lgc == TRUE) ||
				  (TrqSensorNotTrimmed_Cnt_T_lgc == TRUE) ||
				  (AbsHandwheelTorque_HwNm_T_f32 < k_DDEREDEMDAHwTrqActiveThresh_HwNm_f32) ) &&
				(DefaultHwaSCommExportValue_Cnt_T_lgc == FALSE) &&
				(AbsHandwheelVelocity_HwRadpS_T_f32 < k_DDEREDEMDAHwVelActiveThresh_HwRadpS_f32) &&
				( (AbsHandwheelPosition_HwDeg_T_f32 < k_DDEREDEMDAHwPosActiveThresh_HwDeg_f32) ||
				  (HandwheelAuthority_Uls_T_f32 < k_STTdMinHwAuthority_Uls_f32) ) )
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DDEREDEMDASigValidTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
			}
			else
			{
				Rte_Call_SystemTime_GetSystemTime_mS_u32(&DDEREDEMDASigValidTimer_mS_M_u32); /* PRQA S 3200 */
				ElapsedTime_mS_T_u16 = 0u;
			}
			
			if( (VehicleSpeedValid_Cnt_T_lgc == TRUE) &&
				(InvalidMsgQ_Cnt_T_lgc == FALSE) &&
				(MissingMsgQ_Cnt_T_lgc == FALSE) &&
				(DataOtherFltMsgQ_Cnt_T_lgc == FALSE) &&
				(BusOffCh1_Cnt_T_lgc == FALSE) &&
				(BusOffCh1NodeMute_Cnt_T_lgc == FALSE) &&
				(IgnitionFailure_Cnt_T_lgc == FALSE) &&
				(ElapsedTime_mS_T_u16 >= k_DDEREDEMDAValidThresh_mS_u16) &&
				(EPSEn_Cnt_T_lgc == TRUE) )
			{
				DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_No_Reboot_Required;
				AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
			}
			else
			{
				DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_Request_Reboot;
				AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;
			}
			
		}
		else
		{
			
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&DDEREDEMDASigValidTimer_mS_M_u32); /* PRQA S 3200 */
			
			if( ( (T1vsT2_Cnt_T_lgc == TRUE) ||
				  (T1OutofRange_Cnt_T_lgc == TRUE) ||
				  (T2OutofRange_Cnt_T_lgc == TRUE) ||
				  (TrqSensorNotTrimmed_Cnt_T_lgc == TRUE) ||
				  (AbsHandwheelTorque_HwNm_T_f32 < k_DDEREDEMDAHwTrqInactiveThresh_HwNm_f32) ) &&
				(DefaultHwaSCommExportValue_Cnt_T_lgc == FALSE) &&
				(VehicleSpeedValid_Cnt_T_lgc == TRUE) &&
				(VehicleSpeed_Kph_T_f32 < k_DDEREDEMDAVehSpdInactiveThresh_Kph_f32) &&
				(AbsHandwheelVelocity_HwRadpS_T_f32 < k_DDEREDEMDAHwVelInactiveThresh_HwRadpS_f32) &&
				( (AbsHandwheelPosition_HwDeg_T_f32 < k_DDEREDEMDAHwPosInactiveThresh_HwDeg_f32) ||
				  (HandwheelAuthority_Uls_T_f32 < k_STTdMinHwAuthority_Uls_f32) ) &&
				(InvalidMsgQ_Cnt_T_lgc == FALSE) &&
				(MissingMsgQ_Cnt_T_lgc == FALSE) &&
				(DataOtherFltMsgQ_Cnt_T_lgc == FALSE) &&
				(BusOffCh1_Cnt_T_lgc == FALSE) &&
				(BusOffCh1NodeMute_Cnt_T_lgc == FALSE) &&
				(IgnitionFailure_Cnt_T_lgc == FALSE) )
			{
				DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_No_Reboot_Required;
				AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_Permission_to_Stop;
			}
			else
			{
				DDEREDEMDA_Cnt_T_u08 = (uint8)kDDE_REDEM_DA_Request_Reboot;
				AUTORARRETMOTDA_Cnt_T_u08 = (uint8)kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop;
			}
			
		}
	}
	
	
	
	/*** IS_SUPV_DIRA (Msg ID 795) ***/
	
	/* CODE_DEFAUT */
	if( CTCFailed_Cnt_T_lgc == TRUE )
	{
		CODEDEFAUT_Cnt_T_u08 = 1u;
	}
	else
	{
		CODEDEFAUT_Cnt_T_u08 = 0u;
	}
	
	/* STATUS_CONFABSENT */
	STATUSCONFABSENT_Cnt_T_u32 = 0ul;
	if( Node1AAbsent_Cnt_T_lgc == TRUE )
	{
		STATUSCONFABSENT_Cnt_T_u32 |= 1ul << 24;
	}
	if( Node1BAbsent_Cnt_T_lgc == TRUE )
	{
		STATUSCONFABSENT_Cnt_T_u32 |= 1ul << 27;
	}
	if( Node1CAbsent_Cnt_T_lgc == TRUE )
	{
		STATUSCONFABSENT_Cnt_T_u32 |= 1ul << 25;
	}
	if( Node1DAbsent_Cnt_T_lgc == TRUE )
	{
		STATUSCONFABSENT_Cnt_T_u32 |= 1ul << 29;
	}
	if( Node1EAbsent_Cnt_T_lgc == TRUE )
	{
		STATUSCONFABSENT_Cnt_T_u32 |= 1ul << 11;
	}
	
	/* ETAT_LIGNE_APC */
	if( EPSEn_Cnt_T_lgc == TRUE )
	{
		ETATLIGNEAPC_Cnt_T_u08 = (uint8)kETAT_LIGNE_APC_Ignition_On;
	}
	else
	{
		ETATLIGNEAPC_Cnt_T_u08 = (uint8)kETAT_LIGNE_APC_Ignition_Off;
	}
	
	/* ETAT_ASSIST_DA */
	if( RampDwnStatusComplete_T_lgc == TRUE )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_Assist_Not_Active;
	}
	else if( (VehicleSpeedValid_Cnt_T_lgc == FALSE) ||
			 (ReducedAsstLowVoltage_Cnt_T_lgc == TRUE) ||
			 (DutyCycleExceeded_Cnt_T_lgc == TRUE) ||
			 (AbsTempThermLimit_Cnt_T_lgc == TRUE) )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_Dmg_Assist_Active;
	}
	else if( (STTdSelected_Cnt_T_lgc == FALSE) &&
			 (EtatMT_Cnt_T_u08 == (uint8)kETAT_MT_Stopped) )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_STTa_Assist_Active;
	}
	else if( (STTdSelected_Cnt_T_lgc == TRUE) &&
			 (OutputRampMult_Uls_T_f32 <= 0.0001f) )
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_STTd_Assist_Active;
	}
	else
	{
		ETATASSISTDA_Cnt_T_u08 = (uint8)kETAT_ASSIST_DA_Nominal_Assist_Active;
	}
	
	
	
	Rte_IWrite_SrlComOutput_Per1_ANGLECOLONNE_Cnt_u16(ANGLECOLONNE_Cnt_T_u16);
	Rte_IWrite_SrlComOutput_Per1_AUTORARRETMOTDA_Cnt_u08(AUTORARRETMOTDA_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_CAUSEDESACTIVCPK_Cnt_u08(CAUSEDESACTIVCPK_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_CODEDEFAUT_Cnt_u08(CODEDEFAUT_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_CPLEVOLANTOPTMSE_Cnt_u08(CPLEVOLANTOPTMSE_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_CPLEVOLANT_Cnt_u08(CPLEVOLANT_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_DDEREDEMDA_Cnt_u08(DDEREDEMDA_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATASSISTDA_Cnt_u08(ETATASSISTDA_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATDA2004_Cnt_u08(ETATDA2004_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATDA2010_Cnt_u08(ETATDA2010_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATDADYN_Cnt_u08(ETATDADYN_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATDAECPK_Cnt_u08(ETATDAECPK_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATLIGNEAPC_Cnt_u08(ETATLIGNEAPC_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_ETATSECUANGLECOL_Cnt_u08(ETATSECUANGLECOL_Cnt_T_u08);
	Rte_IWrite_SrlComOutput_Per1_STATUSCONFABSENT_Cnt_u32(STATUSCONFABSENT_Cnt_T_u32);
	Rte_IWrite_SrlComOutput_Per1_VITESSECOLONNE_Cnt_u16(VITESSECOLONNE_Cnt_T_u16);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
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
