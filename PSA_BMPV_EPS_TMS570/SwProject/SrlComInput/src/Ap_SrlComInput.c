/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComInput.c
 *     Workspace:  C:/synergy_projects_working/PSA/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Tue May 17 20:21:52 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComInput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          EA3#42 %
 * %derived_by:       fzh7xw %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author   Change Description                                                               SCR #
 * --------   -------  -------  ------------------------------------------------------------------------------  -------
 * 02/07/14    1       OT       Initial Version
 * 04/25/14    2       OT       Anomaly 6590 - include 7th byte in CRC calculation
 * 05/13/14    3       OT       Anomaly 6715 - include 8th byte in CRC calculation
 * 06/04/14    4       OT       Anomaly 6843 - fix EngOnInvalid counter
 * 06/04/14    5       OT       Anomaly 6843 - fix EngOn assignment
 * 06/10/14    6       OT       Updates for QAC errors
 * 07/24/14    7       OT       Anomaly 7018 - fully implemented SrlCom defeat service
 * 09/03/14    8       OT       Updates for new MPU configuration                                                12249
 * 09/18/14    9       OT       Updates for added PosServo messages                                              12259
 * 09/19/14   10       OT       Fixes after further review                                                       12259
 * 09/29/14   11       OT       Updates for added customer messages                                              12260
 * 10/02/14   12       OT       Updates for new customer services                                                12363
 * 10/20/14   13       OT       Updates for STTa/d                                                               12539
 * 10/23/14   14       OT       Anomaly fix for handwheel torque comparison in city park enable                  12573
 * 10/30/14   15       OT       Anomaly fixes for EngOn, DiagOn, and VVH_TYPE                        12651,12652,12653
 * 11/10/14   16       OT       Added outputs for FaultLog                                                       12365
 * 01/13/15   17       OT       Updates to electronic life integration logic                                     12865
 * 01/15/15   18       OT       Anomaly fixes for City Park and fault step logic                     12857,12864,12866
 * 02/03/15   19       OT       Updates to electronic life integration logic                                     12988
 * 02/05/15   20       OT       Corrections to electronic life integration logic                                 12995
 * 04/28/15   21       OT       Implemented JDD 2004                                                             13302
 * 07/07/15   22       OT       Corrected checksum logic for message 305                                         13468
 * 07/10/15   23       OT       Added logic to VehicleSpeedValid                                                 13466
 * 07/16/15   24       OT       Updates for SCIR 003B                                                            13475
 * 07/31/15   25       OT       Corrected CPK_OK conditions                                                   EA3#2226
 * 08/13/15   26       OT       Changed periodic timing                                                       EA3#2149
 * 08/14/15   27       OT       Updates for SCIR 003C                                                         EA3#2497
 * 09/22/15   28       OT       Corrected permanent/temporary control vehicle speed logic                     EA3#2931
 * 10/02/15   29       OT       Corrected reset conditions for ValidEngineStatusCount_Cnt_M_u08               EA3#3504
 * 10/05/15   30       OT       Corrected reset conditions for NTCs                                           EA3#3496
 * 10/23/15   31       OT       Updates for SCIR for ignition time validity                                   EA3#3806
 * 11/23/15   32       OT       Updates for SCIR 003E, NTC failure conditions                                 EA3#4618
 * 12/14/15   33       OT       Corrected NTC inhibit criteria from BusOff condition                          EA3#5248
 * 04/02/15   34       OT       Corrected vehicle time scaling factor                                         EA3#7163
 * 05/03/16   35       WH       Updated for SCIR 4C changes to NTCs 150-155 & 16d                             EA3#7994
 * 05/12/16   36       WH       Updated for SCIR 4C changes to NTCs 164,165,166,140,141,146, 138,139          EA3#7994
 * 05/16/16   37       WH       Update CF013B interfaces							                          EA3#8384
 * 05/17/16   38       WH       Update to output apaauthn							                          EA3#8384
 * 05/17/16   39       WH       Fix 164,165,166,140,141,146, 138,139, 130-134						          EA3#7994
 * 05/23/16   40       WH       Update aparequest logic												          EA3#8384
 * 07/19/16   41       WH       Update ConsAngle logic												          EA3#9677
 * 09/02/16   42       WH       Update for update to apacmdreq logic								          EA3#10700
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks


 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComInput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "il_inc.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "Dem.h"
#include "NtWrap.h"
#include "float.h"



#define D_ISDYNVOLMSGTIMEOUT_MS_U16					11u
#define D_ISDYNABRMSGTIMEOUT_MS_U16					44u
#define D_ISDYNCMMMSGTIMEOUT_MS_U16					44u
#define D_ISDYNAASMSGTIMEOUT_MS_U16					22u
#define D_ISDYNCMM208MSGTIMEOUT_MS_U16				11u
#define D_ISDYN2CMMMSGTIMEOUT_MS_U16				22u
#define D_ISDATBSI3F2MSGTIMEOUT_MS_U16				55u
#define D_ISDATBSI412MSGTIMEOUT_MS_U16				55u
#define D_ISDATBSI432MSGTIMEOUT_MS_U16				55u
#define D_ISDAT4V2BSI552MSGTIMEOUT_MS_U16			1100u
#define D_TESTFAILED_CNT_U08						0u
#define D_TESTPASSED_CNT_U08						1u
#define D_TESTDEADBAND_CNT_U08                      2u
#define D_ANGLEVOLANTSCALE_HWDEGPCNT_F32			0.1f
#define D_ANGLEVOLANTPOL_CNT_F32					(-1.0f)
#define D_ANGLEVOLANTVALIDLO_CNT_U16				0x1E78u
#define D_ANGLEVOLANTVALIDHI_CNT_U16				0xE188u
#define D_VEHSPDSCALE_CNT_F32						0.01f
#define D_CONSANGLECPKSCALE_CNT_F32					0.1f
#define D_CONSANGLECPKPOL_CNT_F32					(-1.0f)
#define D_CONSANGLECPKVALIDLO_CNT_U16				0x1E78u
#define D_CONSANGLECPKVALIDHI_CNT_U16				0xE188u
#define D_ELECINTCONSECMSGS_CNT_U08					2u
#define D_ELECINTCONSECTIMEOUT_MS_U16				1000u
#define D_COMPUTERRAZGCTINVALID_CNT_U08				0xFFu
#define D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32	0xFFFFFFFFul
#define D_COMPTEURTEMPORELVEHICULESCALE_SECPCNT_U32	10ul
#define D_ANNEEECOULEINVALID_CNT_U08				0xFFu
#define D_JOURECOULEINVALID_CNT_U16					0x0FFFu
#define D_SECONDEECOULEEINVALID_CNT_U32				0x000FFFFFul
#define D_SECONDSPERYEAR_CNT_U32					31536000ul
#define D_SECONDSPERDAY_CNT_U32						86400ul


#define IncToThresh(Counter, Thresh)	( ((Counter) < (Thresh)) ? ((Counter) + 1u) : (Counter) ) /* PRQA S 3453 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI3F2MsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI412MsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATBSI432MsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYN2CMMMsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNAASMsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNABRMsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNCMM208MsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNCMM388MsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDYNVOLMsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISINTEELECTRONBSIMsgRxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) PrevISDATDIRAMsgTxTime_MSec_M_u32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) VitesseVehiculeRoues_Kph_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) VitesseVehicleBV_Kph_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) CONSANGLECPK_HwDeg_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) AngleVolant_HwDeg_M_f32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) IgnTimeOff_Sec_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ElecIntTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08]; /* PRQA S 3218 */
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) EffacDefaultDiagTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08]; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) PrevSrlComVehSpd_Kph_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR) ManVehSpd_Kph_M_f32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) IgnOnTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CMMNTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CMM388NTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ESPNTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) BSI412NTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) BSI552NTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) BSI3F2NTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) BSI432NTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CAVNTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) AASNTCEnableTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CMMNodeAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ESPNodeAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) BSINodeAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CAVNodeAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) AASNodeAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNVOLMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNAASMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDYNABRMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI412MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATBSI432MsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ISDATDIRASentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) EngOnAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DmdDelestDATimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) ComputerRazGCTSigInvalidTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DateInvalidTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) DiagMuxOnAbsentTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CPKVehicleSpeedMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) AngleVolantMsgTimer_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR) CityParkInputMsgTimer_mS_M_u32;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CMMNodeAbsentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ESPNodeAbsentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) BSINodeAbsentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CAVNodeAbsentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AASNodeAbsentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATDIRASentFltAcc_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI412MsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI432MsgTimeValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM208MsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNCMM388MsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYN2CMMMsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI3F2MsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI412MsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI412MsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI432MsgLenInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDATBSI432MsgLenValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) EtatMTSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) EtatMTSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CONSANGLECPKSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CONSANGLECPKSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDFCTCPKSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDRelaxeConsistentCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDFCTCPKSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDRELAXECPKSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DMDRELAXECPKSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVRampValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehicleBVRampInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VitesseVehiculeRouesSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CPKVehicleSpeedValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CPKVehicleSpeedInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ANGLEVOLANTSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ANGLEVOLANTSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VITESSEROTVOLANTSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CompteurTemporelVehiculeSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ComputerRazGCTSigValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) DateValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLChkSumInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLChkSumValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASChkSumInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASChkSumValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRChkSumInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRChkSumValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgCountInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgCountValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgCountInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNAASMsgCountValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgCountInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) ISDYNABRMsgCountValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AngleVolantValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) AngleVolantInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CityParkInputConsistentCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CityParkInputValidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CityParkInputInvalidCount_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) CONSANGLECPK_Cnt_M_u16; /* PRQA S 3218 */
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI3F2MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI412MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDATBSI432MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYN2CMMMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNAASMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNABRMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNCMM208MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNCMM388MsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevISDYNVOLMsgDLCError_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevEtatMT_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) CountEtatMT_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ISDYNAASMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) DMDFCTCPK_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) DMDRELAXECPK_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ISDYNABRMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ISDYNVOLMsgCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDiagIntegraElec_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevModeDiag_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ElecIntCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) EffacDefaultDiagCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) VVHTYPE1Count_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) VVHTYPE2Count_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) ValidEngineStatusCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) EngOnDLCInvalidCount_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDMDFCTCPK_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR) PrevDMDRELAXECPK_Cnt_M_u08; /* PRQA S 3218 */
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ResetTimers_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) DiagOn_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) NetOn_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) BattOk_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) EngOn_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) PrevVitesseVehicleBVValid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ClearDTCs_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CMMNTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CMM388NTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ESPNTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) BSI412NTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) BSI552NTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) BSI3F2NTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) BSI432NTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CAVNTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) AASNTCsEnabled_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ElectronicIntegrationCmd_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) CPKOK_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehSpdControl_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) Msg348Valid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) Msg432Valid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) Msg552Valid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) StartupTimeCalculated_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehTimeValid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehSpdSync_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) APARequest_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) AngleVolantValid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) VehicleSpeedValid_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR) ApaRelaxReq_Cnt_M_lgc; /* PRQA S 3218 */
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) NodeAbsentNTCProcessing( VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgTimer_mS_T_u32,
																P2VAR(uint16, AUTOMATIC, AUTOMATIC) FltAcc_Cnt_T_u16,
																VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																VAR(DiagSettings_Str, AUTOMATIC) MsgDiag_Cnt_T_str,
																VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MissingMessageNTCProcessing( VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgTimer_mS_T_u32,
																	P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ValidityNTCProcessing( VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
															  P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
															  P2VAR(uint16, AUTOMATIC, AUTOMATIC) InvalidCount_Cnt_T_u16,
															  VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
															  VAR(uint16, AUTOMATIC) InvalidThresh_Cnt_T_u16,
															  VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MixedTimeValidityNTCProcessing( VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
																	   VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	   VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	   P2VAR(uint32, AUTOMATIC, AUTOMATIC) SigTimer_mS_T_u32,
																	   P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	   VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	   VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	   VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ResetFltAcc( P2VAR(uint16, AUTOMATIC, AUTOMATIC) FltAcc_Cnt_T_u16,
													VAR(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
													VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 );


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
 *   NTC_Num_LimpHomeIgnitionCounter (161U)
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
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 *
 * Array Types:
 * ============
 * CanMsgType: Array with 8 element(s) of type UInt8
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * ShutdownTimeType: Record with elements
 *   Time_Sec_u32 of type UInt32
 *   Valid_Cnt_lgc of type Boolean
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
 * Float: D_CCWEOTINIT_HWDEG_F32 = -360.0F
 * Float: D_CWEOTINIT_HWDEG_F32 = 360.0F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRRAMPRATEFALL_MTRNMPS_F32 = -4400.0F
 * Float: D_MTRRAMPRATERISE_MTRNMPS_F32 = 4400.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_TRQOSCFREQINIT_F32 = 50.0F
 * Float: D_TRQOSCFREQINIT_HZ_F32 = 50.0F
 * Float: D_TRQOVLFREQINIT_HZ_F32 = 3.0F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_VEHWHLBASEINIT_MM_F32 = 3000.0F
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
 * UInt16: D_CMPVEHLATAINIT_CNT_U16 = 1022U
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt8 *Rte_Pim_VVHTYPEData(void)
 *   Boolean *Rte_Pim_ElecIntData(void)
 *   ShutdownTimeType *Rte_Pim_ShutdownTimeData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
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
 *   Boolean Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Init
 *********************************************************************************************************************/
	
	VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32;
	VAR(boolean, AUTOMATIC) STTdSelected_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LXASelected_Cnt_T_lgc;
	
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3200 */
	

	EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	PrevEtatMT_Cnt_M_u08 = (uint8)kETAT_MT_Cut;
	CMMNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	CMM388NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ESPNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BSI412NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BSI552NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BSI3F2NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BSI432NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	CAVNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	AASNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);
	CMMNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ResetFltAcc(&CMMNodeAbsentFltAcc_Cnt_M_u16, k_CMMNodeAbsentDiag_Cnt_str, NTC_Num_Node1AAbsent);
	ESPNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ResetFltAcc(&ESPNodeAbsentFltAcc_Cnt_M_u16, k_ESPNodeAbsentDiag_Cnt_str, NTC_Num_Node1BAbsent);
	BSINodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ResetFltAcc(&BSINodeAbsentFltAcc_Cnt_M_u16, k_BSINodeAbsentDiag_Cnt_str, NTC_Num_Node1CAbsent);
	CAVNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ResetFltAcc(&CAVNodeAbsentFltAcc_Cnt_M_u16, k_CAVNodeAbsentDiag_Cnt_str, NTC_Num_Node1DAbsent);
	AASNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ResetFltAcc(&AASNodeAbsentFltAcc_Cnt_M_u16, k_AASNodeAbsentDiag_Cnt_str, NTC_Num_Node1EAbsent);
	ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	DmdDelestDATimer_mS_M_u32 = SystemTime_mS_T_u32;
	CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
	ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
	DateInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
	DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
	CPKVehicleSpeedMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	AngleVolantMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
	
	IgnOnTimer_mS_M_u32 = SystemTime_mS_T_u32;
	BattOk_Cnt_M_lgc = TRUE;
	
	ElectronicIntegrationCmd_Cnt_M_lgc = *Rte_Pim_ElecIntData();

	LXASelected_Cnt_T_lgc = Rte_IRead_SrlComInput_Init_LXASelected_Cnt_lgc();
	STTdSelected_Cnt_T_lgc = Rte_IRead_SrlComInput_Init_STTdSelected_Cnt_lgc();

	if(2u == (*Rte_Pim_VVHTYPEData()))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
	}
	else if(1u == (*Rte_Pim_VVHTYPEData()))
    {
   		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_O, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_O, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_O, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_O, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_O, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
    }
    else
    {
        
    }
	
	/*NTC 164,165, 166, 138 and 139 configuration based status*/
	if (FALSE == k_JDD2010Selected_Cnt_lgc)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_U, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_U, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_U, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
	}

	/*NTC 140,141,146 configuration based status*/
	if (FALSE == STTdSelected_Cnt_T_lgc)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Q, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
	}

	if ( (FALSE == LXASelected_Cnt_T_lgc) && (FALSE == STTdSelected_Cnt_T_lgc) )
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
	}

	Rte_IWrite_SrlComInput_Init_ElectronicIntegration_Cnt_lgc(*Rte_Pim_ElecIntData());
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_SrlComInput_Per1_AnneeEcoule_Cnt_u08(void)
 *   Float Rte_IRead_SrlComInput_Per1_Batt_Volt_f32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CAVHCSelected_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_CityParkSelected_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_CompteurTemporelVehicule_Cnt_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ComputerRazGCT_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_DefaultVehSpd_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_DiagIntegraElec_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_DiagMuxOn_Cnt_u08(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_DiagRmpToZeroActive_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_DmdDelestDA_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_EffacDefaultDiag_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_EtatMT_Cnt_u08(void)
 *   Float Rte_IRead_SrlComInput_Per1_HandwheelAuthority_Uls_f32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgRxTime_MSec_u32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNAASMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNAASMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08(void)
#endif
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNABRMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNABRMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08(void)
#endif
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgRxTime_MSec_u32(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgDLCError_Cnt_u08(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgRxTime_MSec_u32(void)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   UInt8 *Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08(void)
#else
 *   CanMsgType *Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08(void)
#endif
 *   UInt32 Rte_IRead_SrlComInput_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32(void)
 *   UInt16 Rte_IRead_SrlComInput_Per1_JourEcoule_Cnt_u16(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_LXASelected_Cnt_lgc(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_MarcheARBVM_Cnt_u08(void)
 *   UInt8 Rte_IRead_SrlComInput_Per1_ModeDiag_Cnt_u08(void)
 *   Float Rte_IRead_SrlComInput_Per1_OutputRampMult_Uls_f32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_STTdSelected_Cnt_lgc(void)
 *   UInt32 Rte_IRead_SrlComInput_Per1_SecondeEcoulee_Cnt_u32(void)
 *   Boolean Rte_IRead_SrlComInput_Per1_SrlComHwTrqValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32(void)
 *   UInt16 Rte_IRead_SrlComInput_Per1_VitesseVehicleBV_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SrlComInput_Per1_APAAuthn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_APAAuthn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_APARequest_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_APARequest_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_AngleVolant_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per1_AngleVolant_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(void)
 *   void Rte_IWrite_SrlComInput_Per1_CPKOK_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_CPKOK_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(void)
 *   void Rte_IWrite_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_EngOn_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_EngOn_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_IgnTimeOff_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_SrlComInput_Per1_IgnTimeOff_Cnt_u32(void)
 *   void Rte_IWrite_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_SrlComVehSpd_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SrlComInput_Per1_SrlComVehSpd_Kph_f32(void)
 *   void Rte_IWrite_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_VehTimeValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_VehTimeValid_Cnt_lgc(void)
 *   void Rte_IWrite_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStart(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SrlComDriver_SCom_ElecIntStop(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_ElecInt_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_VHHTYPE_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint8,   AUTOMATIC) AnneeEcoule_Cnt_T_u08;
	VAR(float32, AUTOMATIC) Batt_Volt_T_f32;
	VAR(boolean, AUTOMATIC) BusOffCh1_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CAVHCSelected_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CTermActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CityParkSelected_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) ComputerRazGCT_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) DefaultVehSpd_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) DiagIntegraElec_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DiagMuxOn_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DiagRmpToZeroActive_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) DmdDelestDA_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) EffacDefaultDiag_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) EtatMT_Cnt_T_u08;
	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(uint8,   AUTOMATIC) ISDAT4V2BSI552MsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDAT4V2BSI552MsgRxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDATBSI3F2MsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDATBSI3F2MsgRxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDATBSI412MsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDATBSI412MsgRxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDATBSI432MsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDATBSI432MsgRxTime_MSec_T_u32;
	VAR(boolean, AUTOMATIC) ISDATDIRAMsgTxInProgress_Cnt_T_lgc;
	VAR(uint32,  AUTOMATIC) ISDATDIRAMsgTxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDYN2CMMMsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDYN2CMMMsgRxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDYNAASMsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDYNAASMsgRxTime_MSec_T_u32;
	VAR(CanMsgType, AUTOMATIC) ISDYNAASMsg_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ISDYNABRMsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDYNABRMsgRxTime_MSec_T_u32;
	VAR(CanMsgType, AUTOMATIC) ISDYNABRMsg_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ISDYNCMM208MsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDYNCMM208MsgRxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDYNCMM388MsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDYNCMM388MsgRxTime_MSec_T_u32;
	VAR(uint8,   AUTOMATIC) ISDYNVOLMsgDLCError_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISDYNVOLMsgRxTime_MSec_T_u32;
	VAR(CanMsgType, AUTOMATIC) ISDYNVOLMsg_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) ISINTEELECTRONBSIMsgRxTime_MSec_T_u32;
	VAR(uint16,  AUTOMATIC) JourEcoule_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) MarcheARBVM_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ModeDiag_Cnt_T_u08;
	VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;
	VAR(boolean, AUTOMATIC) RxMsgsSrlComSvcDft_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) STTdSelected_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LXASelected_Cnt_T_lgc;
	VAR(uint32,  AUTOMATIC) SecondeEcoulee_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) SrlComHwTrqValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(uint16,  AUTOMATIC) VitesseVehicleBV_Cnt_T_u16;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) ElectronicIntegration_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) VVHTYPE_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) EpsEn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EEPROMCloseFailed_Cnt_T_lgc;
	VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32;
	
	VAR(uint16,  AUTOMATIC) i;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	
	VAR(uint8,   AUTOMATIC) DLCTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) Checksum_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCount_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ChkSumTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) MsgCountTestStatus_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) ANGLEVOLANT_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) ANGLEVOLANTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) VITESSEROTVOLANT_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) VITESSEROTVOLANTTestStatus_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) VitesseVehiculeRoues_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) VitesseVehiculeRouesTestStatus_Cnt_T_u08;
	VAR(float32, AUTOMATIC) VitesseVehicleBV_Kph_T_f32;
	VAR(uint8,   AUTOMATIC) VitesseVehicleBVInvalidTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) VitesseVehicleBVRampTestStatus_Cnt_T_u08;
	VAR(uint16,  AUTOMATIC) CONSANGLECPK_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) CONSANGLECPKTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDFCTCPK_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDFCTCPKTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDRELAXECPK_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DMDRELAXECPKTestStatus_Cnt_T_u08;
	VAR(Dem_ReturnClearDTCType, AUTOMATIC) ClearDTCRetVal_Cnt_T_enum;
	VAR(uint8,   AUTOMATIC) EtatMTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) CompteurTemporelVehiculeTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ComputerRazGCTTestStatus_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) DateTestStatus_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) StartupTime_Sec_T_u32;
	
	VAR(boolean, AUTOMATIC) InvalidMsgO_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgO_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CRCFltMsgO_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PgrsCntFltMsgO_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRngFltMsgO_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) InvalidMsgV_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgV_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRngFltMsgV_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRateFltMsgV_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffCh1NodeMute_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) InvalidMsgR_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataOtherFltMsgR_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) InvalidMsgS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CRCFltMsgS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PgrsCntFltMsgS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRngFltMsgS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRateFltMsgS_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HandwheelAngleError_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) Node1AAbsent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) InvalidMsgN_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgN_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRngFltMsgN_Cnt_T_lgc;
	
	VAR(float32, AUTOMATIC) ANGLEVOLANT_HwDeg_T_f32;
	VAR(uint8,   AUTOMATIC) ETATDAECPK_Cnt_T_u08;
	VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) SrlComVehSpd_Kph_T_f32;
	VAR(boolean, AUTOMATIC) ValidEngineStatus_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SerialComAngleValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) AbsVehSpdDelta_Kph_T_f32;
	VAR(boolean, AUTOMATIC) CMMDataMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BSIDataMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ApaAuthn_Cnt_T_lgc;
	
	
	
	AnneeEcoule_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_AnneeEcoule_Cnt_u08();
	Batt_Volt_T_f32 = Rte_IRead_SrlComInput_Per1_Batt_Volt_f32();
	BusOffCh1_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_BusOff_Cnt_lgc();
	CAVHCSelected_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_CAVHCSelected_Cnt_lgc();
	CTermActive_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_CTermActive_Cnt_lgc();
	CityParkSelected_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_CityParkSelected_Cnt_lgc();
	CompteurTemporelVehicule_Cnt_T_u32 = Rte_IRead_SrlComInput_Per1_CompteurTemporelVehicule_Cnt_u32();
	ComputerRazGCT_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ComputerRazGCT_Cnt_u08();
	DefaultVehSpd_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_DefaultVehSpd_Cnt_lgc();
	DiagIntegraElec_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_DiagIntegraElec_Cnt_u08();
	DiagMuxOn_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_DiagMuxOn_Cnt_u08();
	DiagRmpToZeroActive_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_DiagRmpToZeroActive_Cnt_lgc();
	DmdDelestDA_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_DmdDelestDA_Cnt_u08();
	EffacDefaultDiag_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_EffacDefaultDiag_Cnt_u08();
	EtatMT_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_EtatMT_Cnt_u08();
	HandwheelAuthority_Uls_T_f32 = Rte_IRead_SrlComInput_Per1_HandwheelAuthority_Uls_f32();
	ISDAT4V2BSI552MsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgDLCError_Cnt_u08();
	ISDAT4V2BSI552MsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDAT4V2BSI552MsgRxTime_MSec_u32();
	ISDATBSI3F2MsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgDLCError_Cnt_u08();
	ISDATBSI3F2MsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDATBSI3F2MsgRxTime_MSec_u32();
	ISDATBSI412MsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgDLCError_Cnt_u08();
	ISDATBSI412MsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDATBSI412MsgRxTime_MSec_u32();
	ISDATBSI432MsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgDLCError_Cnt_u08();
	ISDATBSI432MsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDATBSI432MsgRxTime_MSec_u32();
	ISDATDIRAMsgTxInProgress_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxInProgress_Cnt_lgc();
	ISDATDIRAMsgTxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDATDIRAMsgTxTime_MSec_u32();
	ISDYN2CMMMsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgDLCError_Cnt_u08();
	ISDYN2CMMMsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDYN2CMMMsgRxTime_MSec_u32();
	ISDYNAASMsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDYNAASMsgDLCError_Cnt_u08();
	ISDYNAASMsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDYNAASMsgRxTime_MSec_u32();
	for( i = 0u; i < 8u; i++ )
	{
		ISDYNAASMsg_Cnt_T_u08[i] = (*Rte_IRead_SrlComInput_Per1_ISDYNAASMsg_Cnt_u08())[i];
	}
	ISDYNABRMsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDYNABRMsgDLCError_Cnt_u08();
	ISDYNABRMsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDYNABRMsgRxTime_MSec_u32();
	for( i = 0u; i < 8u; i++ )
	{
		ISDYNABRMsg_Cnt_T_u08[i] = (*Rte_IRead_SrlComInput_Per1_ISDYNABRMsg_Cnt_u08())[i];
	}
	ISDYNCMM208MsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgDLCError_Cnt_u08();
	ISDYNCMM208MsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDYNCMM208MsgRxTime_MSec_u32();
	ISDYNCMM388MsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgDLCError_Cnt_u08();
	ISDYNCMM388MsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDYNCMM388MsgRxTime_MSec_u32();
	ISDYNVOLMsgDLCError_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgDLCError_Cnt_u08();
	ISDYNVOLMsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISDYNVOLMsgRxTime_MSec_u32();
	for( i = 0u; i < 8u; i++ )
	{
		ISDYNVOLMsg_Cnt_T_u08[i] = (*Rte_IRead_SrlComInput_Per1_ISDYNVOLMsg_Cnt_u08())[i];
	}
	ISINTEELECTRONBSIMsgRxTime_MSec_T_u32 = Rte_IRead_SrlComInput_Per1_ISINTEELECTRONBSIMsgRxTime_MSec_u32();
	JourEcoule_Cnt_T_u16 = Rte_IRead_SrlComInput_Per1_JourEcoule_Cnt_u16();
	MarcheARBVM_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_MarcheARBVM_Cnt_u08();
	ModeDiag_Cnt_T_u08 = Rte_IRead_SrlComInput_Per1_ModeDiag_Cnt_u08();
	OutputRampMult_Uls_T_f32 = Rte_IRead_SrlComInput_Per1_OutputRampMult_Uls_f32();
	RxMsgsSrlComSvcDft_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_RxMsgsSrlComSvcDft_Cnt_lgc();
	STTdSelected_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_STTdSelected_Cnt_lgc();
	LXASelected_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_LXASelected_Cnt_lgc();
	SecondeEcoulee_Cnt_T_u32 = Rte_IRead_SrlComInput_Per1_SecondeEcoulee_Cnt_u32();
	SrlComHwTrqValid_Cnt_T_lgc = Rte_IRead_SrlComInput_Per1_SrlComHwTrqValid_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_SrlComInput_Per1_VehicleSpeed_Kph_f32();
	VitesseVehicleBV_Cnt_T_u16 = Rte_IRead_SrlComInput_Per1_VitesseVehicleBV_Cnt_u16();
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	ElectronicIntegration_Cnt_T_lgc = *Rte_Pim_ElecIntData();
	VVHTYPE_Cnt_T_u08 = *Rte_Pim_VVHTYPEData();
	Rte_Call_EpsEn_OP_GET(&EpsEn_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_EEPROMCloseFailed, &EEPROMCloseFailed_Cnt_T_lgc); /* PRQA S 3200 */    
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32); /* PRQA S 3200 */
	
	
	
	if( ResetTimers_Cnt_M_lgc == TRUE )
	{
		ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CMMNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ESPNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BSINodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CAVNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		AASNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgCountInvalidCount_Cnt_M_u16 = 0u;
		ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
		ANGLEVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
		VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNAASChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgCountInvalidCount_Cnt_M_u16 = 0u;
		CONSANGLECPKSigInvalidCount_Cnt_M_u16 = 0u;
		CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
		DMDFCTCPKSigInvalidCount_Cnt_M_u16 = 0u;
		DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
		DMDRELAXECPKSigInvalidCount_Cnt_M_u16 = 0u;
		DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
		AngleVolantMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		AngleVolantValidCount_Cnt_M_u16 = 0u;
		AngleVolantInvalidCount_Cnt_M_u16 = 0u;
		CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CityParkInputConsistentCount_Cnt_M_u16 = 0u;
		DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
		CityParkInputValidCount_Cnt_M_u16 = 0u;
		CityParkInputInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNABRChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgCountInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
		VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16 = 0u;
		CPKVehicleSpeedMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
		CPKVehicleSpeedInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVSigInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVRampInvalidCount_Cnt_M_u16 = 0u;
		ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 = 0u;
		EtatMTSigValidCount_Cnt_M_u16 = 0u;
		EtatMTSigInvalidCount_Cnt_M_u16 = 0u;
		ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16 = 0u;
		CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
		ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
		ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16 = 0u;
		DmdDelestDATimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI412MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI432MsgLenInvalidCount_Cnt_M_u16 = 0u;
		DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		DateInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
        DateValidCount_Cnt_M_u16 = 0u;
		
		ResetTimers_Cnt_M_lgc = FALSE;
	}
	
	
	
	if( RxMsgsSrlComSvcDft_Cnt_T_lgc == FALSE )
	{
		
		/* NetOn */
		if( EpsEn_Cnt_T_lgc == TRUE )
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(IgnOnTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
			if( ElapsedTime_mS_T_u16 >= k_IgnOnTimeout_mS_u16 )
			{
				NetOn_Cnt_M_lgc = TRUE;
			}
		}
		else
		{
			NetOn_Cnt_M_lgc = FALSE;
			IgnOnTimer_mS_M_u32 = SystemTime_mS_T_u32;
		}
		
		
		/* BattOk */
		if( BattOk_Cnt_M_lgc == TRUE )
		{
			if( (Batt_Volt_T_f32 >= k_BattOvHi_Volt_f32) ||
				(Batt_Volt_T_f32 <= k_BattUvLo_Volt_f32) )
			{
				BattOk_Cnt_M_lgc = FALSE;
			}
		}
		else
		{
			if( (Batt_Volt_T_f32 >= k_BattUvHi_Volt_f32) &&
				(Batt_Volt_T_f32 <= k_BattOvLo_Volt_f32) )
			{
				BattOk_Cnt_M_lgc = TRUE;
			}
		}
		
		
		/* DiagOn */
		if( ISDYNCMM208MsgRxTime_MSec_T_u32 != PrevISDYNCMM208MsgRxTime_MSec_M_u32 )
		{
			DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ElapsedTime_mS_T_u16 = 0u;
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DiagMuxOnAbsentTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		}
		
		if( (NetOn_Cnt_M_lgc == TRUE) &&
			(DiagMuxOn_Cnt_T_u08 == (uint8)kDIAG_MUX_ON_Enable_SCom_Diagnostics) &&
			(ElapsedTime_mS_T_u16 <= k_DiagMuxOnAbsentTimeout_mS_u16) &&
			(BattOk_Cnt_M_lgc == TRUE) &&
			(BusOffCh1_Cnt_T_lgc == FALSE) )
		{
			DiagOn_Cnt_M_lgc = TRUE;
		}
		else
		{
			DiagOn_Cnt_M_lgc = FALSE;
		}
		
		
		/* EngOn */
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EngOnAbsentTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		if( ElapsedTime_mS_T_u16 >= 60u )
		{
			EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			CountEtatMT_Cnt_M_u08 = 0u;
			EngOn_Cnt_M_lgc = FALSE;
		}
		
		
		/* NTC Enable Criteria */
		if( (ElectronicIntegration_Cnt_T_lgc == FALSE) &&
			(VehSpdControl_Cnt_M_lgc == FALSE) &&
			(BusOffCh1_Cnt_T_lgc == FALSE) )
		{
			
			if( (SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_WARMINIT) ||
				(SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE) ||
				( (SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE) &&
				  (EpsEn_Cnt_T_lgc == TRUE) ) )
			{
				
				/* Test Enable Criteria for NTCs 120, 121, 128, 129, and 12C */
				if( (Batt_Volt_T_f32 >= k_VBattMinCMM_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxCMM_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CMMNTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_CMMNTCEnableTimeout_mS_u16 )
					{
						CMMNTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					CMMNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					CMMNTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
				/* Test Enable Criteria for NTCs 130, 131, 132, 133, and 134 */
				if( (VVHTYPE_Cnt_T_u08 == 2u) &&
					(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Starting) &&
					(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Autonomous_Starting) &&
					(Batt_Volt_T_f32 >= k_VBattMinESP_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxESP_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESPNTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_ESPNTCEnableTimeout_mS_u16 )
					{
						ESPNTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					ESPNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					ESPNTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
				/* Test Enable Criteria for NTCs 158 and 159 */
				if( (CityParkSelected_Cnt_T_lgc == TRUE) &&
					(Batt_Volt_T_f32 >= k_VBattMinBSI_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxBSI_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BSI412NTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_BSINTCEnableTimeout_mS_u16 )
					{
						BSI412NTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					BSI412NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					BSI412NTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
				/* Test Enable Criteria for NTCs 160, 161, 164, 165 and 166 */
				if( (Batt_Volt_T_f32 >= k_VBattMinBSI_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxBSI_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BSI552NTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_BSINTCEnableTimeout_mS_u16 )
					{
						BSI552NTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					BSI552NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					BSI552NTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
				/* Test Enable Criteria for NTC 138 and 139 */
				if( (TRUE == k_JDD2010Selected_Cnt_lgc) &&
					(Batt_Volt_T_f32 >= k_VBattMinBSI_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxBSI_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BSI432NTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_BSINTCEnableTimeout_mS_u16 )
					{
						BSI432NTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					BSI432NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					BSI432NTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
				/* Test Enable Criteria for NTCs 140, 141, and 146 */
				if( (Batt_Volt_T_f32 >= k_VBattMinBSI_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxBSI_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BSI3F2NTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_BSINTCEnableTimeout_mS_u16 )
					{
						BSI3F2NTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					BSI3F2NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					BSI3F2NTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
				/* Test Enable Criteria for NTCs 168, 169, 16C, and 16D */
				if( (VVHTYPE_Cnt_T_u08 == 1u) &&
					(Batt_Volt_T_f32 >= k_VBattMinCMM388_Volt_f32) &&
					(Batt_Volt_T_f32 <= k_VBattMaxCMM388_Volt_f32) )
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CMM388NTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
					if( ElapsedTime_mS_T_u16 >= k_CMM388NTCEnableTimeout_mS_u16 )
					{
						CMM388NTCsEnabled_Cnt_M_lgc = TRUE;
					}
				}
				else
				{
					CMM388NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
					CMM388NTCsEnabled_Cnt_M_lgc = FALSE;
				}
				
			}
			else
			{
				CMMNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				CMMNTCsEnabled_Cnt_M_lgc = FALSE;
				ESPNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				ESPNTCsEnabled_Cnt_M_lgc = FALSE;
				BSI412NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				BSI412NTCsEnabled_Cnt_M_lgc = FALSE;
				BSI552NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				BSI552NTCsEnabled_Cnt_M_lgc = FALSE;
				BSI432NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				BSI432NTCsEnabled_Cnt_M_lgc = FALSE;
				BSI3F2NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				BSI3F2NTCsEnabled_Cnt_M_lgc = FALSE;
				CMM388NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				CMM388NTCsEnabled_Cnt_M_lgc = FALSE;
			}
			
			/* Test Enable Criteria for NTCs 148, 149, 14A, 14B, 14C, 14D, and 14E */
			if( (CityParkSelected_Cnt_T_lgc == TRUE) &&
				(EpsEn_Cnt_T_lgc == TRUE) &&
				(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Starting) &&
				(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Autonomous_Starting) &&
				(Batt_Volt_T_f32 >= k_VBattMinAAS_Volt_f32) &&
				(Batt_Volt_T_f32 <= k_VBattMaxAAS_Volt_f32) )
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(AASNTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
				if( ElapsedTime_mS_T_u16 >= k_AASNTCEnableTimeout_mS_u16 )
				{
					AASNTCsEnabled_Cnt_M_lgc = TRUE;
				}
			}
			else
			{
				AASNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				AASNTCsEnabled_Cnt_M_lgc = FALSE;
			}
			
			/* Test Enable Criteria for NTCs 150, 151, 152, 153, 154, and 155 */
			if( (CAVHCSelected_Cnt_T_lgc == TRUE) &&
				(EpsEn_Cnt_T_lgc == TRUE) &&
				(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Starting) &&
				(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Autonomous_Starting) &&
				(Batt_Volt_T_f32 >= k_VBattMinCAV_Volt_f32) &&
				(Batt_Volt_T_f32 <= k_VBattMaxCAV_Volt_f32) )
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CAVNTCEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
				if( ElapsedTime_mS_T_u16 >= k_CAVNTCEnableTimeout_mS_u16 )
				{
					CAVNTCsEnabled_Cnt_M_lgc = TRUE;
				}
			}
			else
			{
				CAVNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
				CAVNTCsEnabled_Cnt_M_lgc = FALSE;
			}
			
		}
		else
		{
			CMMNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			CMMNTCsEnabled_Cnt_M_lgc = FALSE;
			ESPNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ESPNTCsEnabled_Cnt_M_lgc = FALSE;
			BSI412NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			BSI412NTCsEnabled_Cnt_M_lgc = FALSE;
			BSI552NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			BSI552NTCsEnabled_Cnt_M_lgc = FALSE;
			BSI432NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			BSI432NTCsEnabled_Cnt_M_lgc = FALSE;
			BSI3F2NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			BSI3F2NTCsEnabled_Cnt_M_lgc = FALSE;
			CMM388NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			CMM388NTCsEnabled_Cnt_M_lgc = FALSE;
			AASNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			AASNTCsEnabled_Cnt_M_lgc = FALSE;
			CAVNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
			CAVNTCsEnabled_Cnt_M_lgc = FALSE;
		}
		
		
		
		if( (DiagOn_Cnt_M_lgc == TRUE) &&
			(ElectronicIntegration_Cnt_T_lgc == FALSE) &&
			(VehSpdControl_Cnt_M_lgc == FALSE) )
		{
			
			/* NTC 101 - EPS Mute */
			if( ISDATDIRAMsgTxInProgress_Cnt_T_lgc == FALSE )
			{
				ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_T_u32;
				if( ISDATDIRAMsgTxTime_MSec_T_u32 != PrevISDATDIRAMsgTxTime_MSec_M_u32 )
				{
					ISDATDIRASentFltAcc_Cnt_M_u16 = DiagNStep_m(ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str);
					if( ISDATDIRASentFltAcc_Cnt_M_u16 == 0u )
					{
						Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1NodeMute, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
					}
					PrevISDATDIRAMsgTxTime_MSec_M_u32 = ISDATDIRAMsgTxTime_MSec_T_u32;
				}
			}
			else
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATDIRASentTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
				if( ElapsedTime_mS_T_u16 >= k_ISDATDIRASentTimeout_mS_u16 )
				{
					ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_T_u32;
					ISDATDIRASentFltAcc_Cnt_M_u16 = DiagPStep_m(ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str);
					if( DiagFailed_m(ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str) == TRUE)
					{
						Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1NodeMute, 0u, NTC_STATUS_FAILED); /* PRQA S 3200 */
					}
				}
			}
			
			
			/* NTC 106 - BSI Node Absent */
			NodeAbsentNTCProcessing(ISDATBSI432MsgRxTime_MSec_T_u32,
									PrevISDATBSI432MsgRxTime_MSec_M_u32,
									&BSINodeAbsentTimer_mS_M_u32,
									&BSINodeAbsentFltAcc_Cnt_M_u16,
									k_BSINodeAbsentTimeout_mS_u16,
									k_BSINodeAbsentDiag_Cnt_str,
									NTC_Num_Node1CAbsent);
			
		}
		else
		{
			ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);
			BSINodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ResetFltAcc(&BSINodeAbsentFltAcc_Cnt_M_u16, k_BSINodeAbsentDiag_Cnt_str, NTC_Num_Node1CAbsent);
		}
		
		
		if( (NetOn_Cnt_M_lgc == TRUE) &&
			(ElectronicIntegration_Cnt_T_lgc == FALSE) &&
			(VehSpdControl_Cnt_M_lgc == FALSE) &&
			(BusOffCh1_Cnt_T_lgc == FALSE) )
		{
			
			/* NTC 102 - CMM Node Absent */
			NodeAbsentNTCProcessing(ISDYN2CMMMsgRxTime_MSec_T_u32,
									PrevISDYN2CMMMsgRxTime_MSec_M_u32,
									&CMMNodeAbsentTimer_mS_M_u32,
									&CMMNodeAbsentFltAcc_Cnt_M_u16,
									k_CMMNodeAbsentTimeout_mS_u16,
									k_CMMNodeAbsentDiag_Cnt_str,
									NTC_Num_Node1AAbsent);
			
			if( DiagFailed_m(CMMNodeAbsentFltAcc_Cnt_M_u16, k_CMMNodeAbsentDiag_Cnt_str) == TRUE )
			{
				ValidEngineStatusCount_Cnt_M_u08 = 0u;
				EngOnDLCInvalidCount_Cnt_M_u08 = 0u;
			}
			
		}
		else
		{
			CMMNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ResetFltAcc(&CMMNodeAbsentFltAcc_Cnt_M_u16, k_CMMNodeAbsentDiag_Cnt_str, NTC_Num_Node1AAbsent);
		}
		
		
		if( (VVHTYPE_Cnt_T_u08 == 2u) &&
			(DiagOn_Cnt_M_lgc == TRUE) &&
			(ElectronicIntegration_Cnt_T_lgc == FALSE) &&
			(VehSpdControl_Cnt_M_lgc == FALSE) )
		{
			
			/* NTC 104 - ESP Node Absent */
			NodeAbsentNTCProcessing(ISDYNABRMsgRxTime_MSec_T_u32,
									PrevISDYNABRMsgRxTime_MSec_M_u32,
									&ESPNodeAbsentTimer_mS_M_u32,
									&ESPNodeAbsentFltAcc_Cnt_M_u16,
									k_ESPNodeAbsentTimeout_mS_u16,
									k_ESPNodeAbsentDiag_Cnt_str,
									NTC_Num_Node1BAbsent);
			
		}
		else
		{
			ESPNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ResetFltAcc(&ESPNodeAbsentFltAcc_Cnt_M_u16, k_ESPNodeAbsentDiag_Cnt_str, NTC_Num_Node1BAbsent);
		}
		
		
		if( (CAVHCSelected_Cnt_T_lgc == TRUE) &&
			(DiagOn_Cnt_M_lgc == TRUE) &&
			(ElectronicIntegration_Cnt_T_lgc == FALSE) &&
			(VehSpdControl_Cnt_M_lgc == FALSE) )
		{
			
			/* NTC 108 - CAV Node Absent */
			NodeAbsentNTCProcessing(ISDYNVOLMsgRxTime_MSec_T_u32,
									PrevISDYNVOLMsgRxTime_MSec_M_u32,
									&CAVNodeAbsentTimer_mS_M_u32,
									&CAVNodeAbsentFltAcc_Cnt_M_u16,
									k_CAVNodeAbsentTimeout_mS_u16,
									k_CAVNodeAbsentDiag_Cnt_str,
									NTC_Num_Node1DAbsent);
			
		}
		else
		{
			CAVNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ResetFltAcc(&CAVNodeAbsentFltAcc_Cnt_M_u16, k_CAVNodeAbsentDiag_Cnt_str, NTC_Num_Node1DAbsent);
		}
		
		
		if( (CityParkSelected_Cnt_T_lgc == TRUE) &&
			(DiagOn_Cnt_M_lgc == TRUE) &&
			(ElectronicIntegration_Cnt_T_lgc == FALSE) &&
			(VehSpdControl_Cnt_M_lgc == FALSE) )
		{
			
			/* NTC 110 - AAS Node Absent */
			NodeAbsentNTCProcessing(ISDYNAASMsgRxTime_MSec_T_u32,
									PrevISDYNAASMsgRxTime_MSec_M_u32,
									&AASNodeAbsentTimer_mS_M_u32,
									&AASNodeAbsentFltAcc_Cnt_M_u16,
									k_AASNodeAbsentTimeout_mS_u16,
									k_AASNodeAbsentDiag_Cnt_str,
									NTC_Num_Node1EAbsent);
			
		}
		else
		{
			AASNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ResetFltAcc(&AASNodeAbsentFltAcc_Cnt_M_u16, k_AASNodeAbsentDiag_Cnt_str, NTC_Num_Node1EAbsent);
		}
		
		
		
		/*** IS_DYN_VOL Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNVOLMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 <= D_ISDYNVOLMSGTIMEOUT_MS_U16 )
		{
			AngleVolantMsgTimer_mS_M_u32 = ISDYNVOLMsgRxTime_MSec_T_u32;
		}
		
		if( CAVNTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 151 - Missing IS_DYN_VOL Message (Msg ID 305) */
			MissingMessageNTCProcessing(ISDYNVOLMsgRxTime_MSec_T_u32,
										PrevISDYNVOLMsgRxTime_MSec_M_u32,
										&ISDYNVOLMsgTimer_mS_M_u32,
										&ISDYNVOLMsgTimeValidCount_Cnt_M_u16,
										k_CAVNodeTimeout_mS_u16,
										k_ISDYNVOLMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_S);
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNVOLMSGTIMEOUT_MS_U16 )
			{
				ISDYNVOLMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
				ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
				ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
				ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
				VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDYNVOLMsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
			ISDYNVOLMsgLenInvalidCount_Cnt_M_u16 = 0u;
			ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
			ISDYNVOLChkSumInvalidCount_Cnt_M_u16 = 0u;
			ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
			ISDYNVOLMsgCountInvalidCount_Cnt_M_u16 = 0u;
			ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
			ANGLEVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
			VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
			VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		}
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(AngleVolantMsgTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 > D_ISDYNVOLMSGTIMEOUT_MS_U16 )
		{
			AngleVolantValidCount_Cnt_M_u16 = 0u;
			AngleVolantInvalidCount_Cnt_M_u16 = IncToThresh(AngleVolantInvalidCount_Cnt_M_u16, k_AngleVolantInvalidThresh_Cnt_u16);
			AngleVolantMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		}
		
		if( ISDYNVOLMsgRxTime_MSec_T_u32 != PrevISDYNVOLMsgRxTime_MSec_M_u32 )
		{
			
			if( ISDYNVOLMsgDLCError_Cnt_T_u08 == PrevISDYNVOLMsgDLCError_Cnt_M_u08 )
			{
				
				/* Checksum */
				
				Checksum_Cnt_T_u08 = (uint8)( (ISDYNVOLMsg_Cnt_T_u08[0] & 0x0Fu) ^ ((ISDYNVOLMsg_Cnt_T_u08[0] >> 4) & 0x0Fu) ^
											  (ISDYNVOLMsg_Cnt_T_u08[1] & 0x0Fu) ^ ((ISDYNVOLMsg_Cnt_T_u08[1] >> 4) & 0x0Fu) ^
											  (ISDYNVOLMsg_Cnt_T_u08[2] & 0x0Fu) ^ ((ISDYNVOLMsg_Cnt_T_u08[2] >> 4) & 0x0Fu) ^
											  (ISDYNVOLMsg_Cnt_T_u08[3] & 0x0Fu) ^ ((ISDYNVOLMsg_Cnt_T_u08[3] >> 4) & 0x0Fu) ^
											  (ISDYNVOLMsg_Cnt_T_u08[4] & 0x0Fu) ^ ((ISDYNVOLMsg_Cnt_T_u08[4] >> 4) & 0x0Fu) );
				
				if( (Checksum_Cnt_T_u08 & 0x0Fu) != 0u )
				{
					ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				/* Message Progress Counter */
				
				MsgCount_Cnt_T_u08 = ISDYNVOLMsg_Cnt_T_u08[4] & 0x0Fu;
				
				if( MsgCount_Cnt_T_u08 != ISDYNVOLMsgCount_Cnt_M_u08 )
				{
					MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				ISDYNVOLMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;
				
				
				/* Handwheel Angle */
				
				ANGLEVOLANT_Cnt_T_u16 = (((uint16)ISDYNVOLMsg_Cnt_T_u08[0]) << 8) + ISDYNVOLMsg_Cnt_T_u08[1];
				
				if( (ANGLEVOLANT_Cnt_T_u16 > D_ANGLEVOLANTVALIDLO_CNT_U16) &&
					(ANGLEVOLANT_Cnt_T_u16 < D_ANGLEVOLANTVALIDHI_CNT_U16) )
				{
					ANGLEVOLANTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					ANGLEVOLANTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				/* Handwheel Speed */
				
				VITESSEROTVOLANT_Cnt_T_u08 = ISDYNVOLMsg_Cnt_T_u08[2];
				
				if( VITESSEROTVOLANT_Cnt_T_u08 == (uint8)kVITESSE_ROT_VOL_Invalid )
				{
					VITESSEROTVOLANTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					VITESSEROTVOLANTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				if( CAVNTCsEnabled_Cnt_M_lgc == TRUE )
				{
					
					/* NTC 152 - IS_DYN_CAV Checksum Failure (Msg ID 305) */
					ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
										  &ISDYNVOLChkSumValidCount_Cnt_M_u16,
										  &ISDYNVOLChkSumInvalidCount_Cnt_M_u16,
										  k_ISDYNVOLChkSumValidThresh_Cnt_u16,
										  k_ISDYNVOLChkSumInvalidThresh_Cnt_u16,
										  NTC_Num_CRCFltMsg_S);
					
					/* NTC 153 - IS_DYN_CAV Process Counter Failure (Msg ID 305) */
					ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
										  &ISDYNVOLMsgCountValidCount_Cnt_M_u16,
										  &ISDYNVOLMsgCountInvalidCount_Cnt_M_u16,
										  k_ISDYNVOLMsgCountValidThresh_Cnt_u16,
										  k_ISDYNVOLMsgCountInvalidThresh_Cnt_u16,
										  NTC_Num_PgrsCntFltMsg_S);
					
					/* NTC 154 - ANGLE_VOLANT Invalid (Msg ID 305) */
					ValidityNTCProcessing(ANGLEVOLANTTestStatus_Cnt_T_u08,
										  &ANGLEVOLANTSigValidCount_Cnt_M_u16,
										  &ANGLEVOLANTSigInvalidCount_Cnt_M_u16,
										  k_ANGLEVOLANTSigValidThresh_Cnt_u16,
										  k_ANGLEVOLANTSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRngFltMsg_S);
					
					/* NTC 155 - VITESSE_ROT_VOLANT Invalid (Msg ID 305) */
					ValidityNTCProcessing(VITESSEROTVOLANTTestStatus_Cnt_T_u08,
										  &VITESSEROTVOLANTSigValidCount_Cnt_M_u16,
										  &VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16,
										  k_VITESSEROTVOLANTSigValidThresh_Cnt_u16,
										  k_VITESSEROTVOLANTSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRateFltMsg_S);
					
				}
				
				if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(ANGLEVOLANTTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
				{
					AngleVolant_HwDeg_M_f32 = ((float32)((sint16)ANGLEVOLANT_Cnt_T_u16)) * D_ANGLEVOLANTSCALE_HWDEGPCNT_F32 * D_ANGLEVOLANTPOL_CNT_F32;
					
					AngleVolantValid_Cnt_M_lgc = TRUE;
					AngleVolantValidCount_Cnt_M_u16 = IncToThresh(AngleVolantValidCount_Cnt_M_u16, k_AngleVolantValidThresh_Cnt_u16);
					AngleVolantInvalidCount_Cnt_M_u16 = 0u;
				}
				else
				{
					AngleVolantValid_Cnt_M_lgc = FALSE;
					AngleVolantValidCount_Cnt_M_u16 = 0u;
					AngleVolantInvalidCount_Cnt_M_u16 = IncToThresh(AngleVolantInvalidCount_Cnt_M_u16, k_AngleVolantInvalidThresh_Cnt_u16);
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				
			}
			else
			{
				ISDYNVOLMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
				ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
				ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
				ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
				VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
				
				AngleVolantValidCount_Cnt_M_u16 = 0u;
				AngleVolantInvalidCount_Cnt_M_u16 = IncToThresh(AngleVolantInvalidCount_Cnt_M_u16, k_AngleVolantInvalidThresh_Cnt_u16);
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			
			
			if( CAVNTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 150 - Invalid Message (too short) (Msg ID 305) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDYNVOLMsgLenValidCount_Cnt_M_u16,
									  &ISDYNVOLMsgLenInvalidCount_Cnt_M_u16,
									  k_ISDYNVOLMsgLenValidThresh_Cnt_u16,
									  k_ISDYNVOLMsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_S);
			}
			
		}
		
		
		
		/*** IS_DYN_ABR Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNABRMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( VVHTYPE_Cnt_T_u08 == 2u )
		{
			if( ElapsedTime_mS_T_u16 <= D_ISDYNABRMSGTIMEOUT_MS_U16 )
			{
				CPKVehicleSpeedMsgTimer_mS_M_u32 = ISDYNABRMsgRxTime_MSec_T_u32;
			}
		}
		
		if( ESPNTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 131 - Missing IS_DYN_ABR Message (Msg ID 38D) */
			MissingMessageNTCProcessing(ISDYNABRMsgRxTime_MSec_T_u32,
										PrevISDYNABRMsgRxTime_MSec_M_u32,
										&ISDYNABRMsgTimer_mS_M_u32,
										&ISDYNABRMsgTimeValidCount_Cnt_M_u16,
										k_ABSNodeTimeout_mS_u16,
										k_ISDYNABRMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_O);
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNABRMSGTIMEOUT_MS_U16 )
			{
				ISDYNABRMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
				ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
				ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
				VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDYNABRMsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
			ISDYNABRMsgLenInvalidCount_Cnt_M_u16 = 0u;
			ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
			ISDYNABRChkSumInvalidCount_Cnt_M_u16 = 0u;
			ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
			ISDYNABRMsgCountInvalidCount_Cnt_M_u16 = 0u;
			VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
			VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if( VVHTYPE_Cnt_T_u08 == 2u )
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CPKVehicleSpeedMsgTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNABRMSGTIMEOUT_MS_U16 )
			{
				CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
				CPKVehicleSpeedInvalidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedInvalidCount_Cnt_M_u16, k_CPKVehicleSpeedInvalidThresh_Cnt_u16);
				CPKVehicleSpeedMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			}
		}
		
		if( ISDYNABRMsgRxTime_MSec_T_u32 != PrevISDYNABRMsgRxTime_MSec_M_u32 )
		{
			
			if( ISDYNABRMsgDLCError_Cnt_T_u08 == PrevISDYNABRMsgDLCError_Cnt_M_u08 )
			{
				
				/* Checksum */
				
				Checksum_Cnt_T_u08 = (uint8)( (ISDYNABRMsg_Cnt_T_u08[0] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[0] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[1] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[1] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[2] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[2] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[3] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[3] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[4] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[4] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[5] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[5] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[6] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[6] >> 4) & 0x0Fu) +
											  (ISDYNABRMsg_Cnt_T_u08[7] & 0x0Fu) + ((ISDYNABRMsg_Cnt_T_u08[7] >> 4) & 0x0Fu) +
											  8u );
				
				if( (Checksum_Cnt_T_u08 & 0x0Fu) != 0x0Fu )
				{
					ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				/* Message Progress Counter */
				
				MsgCount_Cnt_T_u08 = (ISDYNABRMsg_Cnt_T_u08[5] >> 4u) & 0x0Fu;
				
				if( MsgCount_Cnt_T_u08 != ISDYNABRMsgCount_Cnt_M_u08 )
				{
					MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				ISDYNABRMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;
				
				
				/* Vehicle Speed */
				
				VitesseVehiculeRoues_Cnt_T_u16 = (((uint16)ISDYNABRMsg_Cnt_T_u08[0]) << 8) + ISDYNABRMsg_Cnt_T_u08[1];
				
				if( VitesseVehiculeRoues_Cnt_T_u16 == (uint16)kVITESSE_VEHICULE_ROUES_Invalid )
				{
					VitesseVehiculeRouesTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					VitesseVehiculeRouesTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				if( ESPNTCsEnabled_Cnt_M_lgc == TRUE )
				{
					
					/* NTC 132 - Vehicle Speed Message Checksum Failure (Msg ID 38D) */
					ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
										  &ISDYNABRChkSumValidCount_Cnt_M_u16,
										  &ISDYNABRChkSumInvalidCount_Cnt_M_u16,
										  k_ISDYNABRChkSumValidThresh_Cnt_u16,
										  k_ISDYNABRChkSumInvalidThresh_Cnt_u16,
										  NTC_Num_CRCFltMsg_O);
					
					/* NTC 133 - Vehicle Speed Message Progress Counter Failure (Msg ID 38D) */
					ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
										  &ISDYNABRMsgCountValidCount_Cnt_M_u16,
										  &ISDYNABRMsgCountInvalidCount_Cnt_M_u16,
										  k_ISDYNABRMsgCountValidThresh_Cnt_u16,
										  k_ISDYNABRMsgCountInvalidThresh_Cnt_u16,
										  NTC_Num_PgrsCntFltMsg_O);
					
					/* NTC 134 - Invalid Vehicle Speed Data (Msg ID 38D) */
					ValidityNTCProcessing(VitesseVehiculeRouesTestStatus_Cnt_T_u08,
										  &VitesseVehiculeRouesSigValidCount_Cnt_M_u16,
										  &VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16,
										  k_VitesseVehiculeRouesSigValidThresh_Cnt_u16,
										  k_VitesseVehiculeRouesSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRngFltMsg_O);
					
				}
				
				if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(VitesseVehiculeRouesTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
				{
					VitesseVehiculeRoues_Kph_M_f32 = ((float32)VitesseVehiculeRoues_Cnt_T_u16) * D_VEHSPDSCALE_CNT_F32;
					
					if( VVHTYPE_Cnt_T_u08 < 2u )
					{
						if( VVHTYPE2Count_Cnt_M_u08 < 10u )
						{
							VVHTYPE2Count_Cnt_M_u08++;
						}
						else
						{
							VVHTYPE_Cnt_T_u08 = 2u;
							*Rte_Pim_VVHTYPEData() = 2u;
							Rte_Call_VHHTYPE_WriteBlock(NULL_PTR); /* PRQA S 3200 */
							
							Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
							Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
							Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
							Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_V, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
						}
					}
					else
					{
						CPKVehicleSpeedValidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedValidCount_Cnt_M_u16, k_CPKVehicleSpeedValidThresh_Cnt_u16);
						CPKVehicleSpeedInvalidCount_Cnt_M_u16 = 0u;
						
					}
					
				}
				else
				{
					
					if( VVHTYPE_Cnt_T_u08 == 2u )
					{
						CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
						CPKVehicleSpeedInvalidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedInvalidCount_Cnt_M_u16, k_CPKVehicleSpeedInvalidThresh_Cnt_u16);
					}
					
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				
			}
			else
			{
				ISDYNABRMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
				ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
				ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
				VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
				
				if( VVHTYPE_Cnt_T_u08 == 2u )
				{
					CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
					CPKVehicleSpeedInvalidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedInvalidCount_Cnt_M_u16, k_CPKVehicleSpeedInvalidThresh_Cnt_u16);
				}

				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			
			
			if( ESPNTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 130 - Invalid Message (too short) (Msg ID 38D) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDYNABRMsgLenValidCount_Cnt_M_u16,
									  &ISDYNABRMsgLenInvalidCount_Cnt_M_u16,
									  k_ISDYNABRMsgLenValidThresh_Cnt_u16,
									  k_ISDYNABRMsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_O);
			}
			
		}
		
		
		
		/*** IS_DYN_CMM_388 Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNCMM388MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( VVHTYPE_Cnt_T_u08 == 1u )
		{
			if( ElapsedTime_mS_T_u16 <= D_ISDYNCMMMSGTIMEOUT_MS_U16 )
			{
				CPKVehicleSpeedMsgTimer_mS_M_u32 = ISDYNCMM388MsgRxTime_MSec_T_u32;
			}
		}

		if( CMM388NTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 169 - Missing IS_DYN_CMM Message (Msg ID 388) */
			MissingMessageNTCProcessing(ISDYNCMM388MsgRxTime_MSec_T_u32,
										PrevISDYNCMM388MsgRxTime_MSec_M_u32,
										&ISDYNCMM388MsgTimer_mS_M_u32,
										&ISDYNCMM388MsgTimeValidCount_Cnt_M_u16,
										k_CMM388MsgTimeout_mS_u16,
										k_ISDYNCMM388MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_V);
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNCMMMSGTIMEOUT_MS_U16 )
			{
				ISDYNCMM388MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
				VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
				VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDYNCMM388MsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
			ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16 = 0u;
			VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
			VitesseVehicleBVSigInvalidCount_Cnt_M_u16 = 0u;
			VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
			VitesseVehicleBVRampInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if( VVHTYPE_Cnt_T_u08 == 1u )
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CPKVehicleSpeedMsgTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNCMMMSGTIMEOUT_MS_U16 )
			{
				CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
				CPKVehicleSpeedInvalidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedInvalidCount_Cnt_M_u16, k_CPKVehicleSpeedInvalidThresh_Cnt_u16);
				CPKVehicleSpeedMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			}
		}
		
		if( ISDYNCMM388MsgRxTime_MSec_T_u32 != PrevISDYNCMM388MsgRxTime_MSec_M_u32 )
		{
			
			if( ISDYNCMM388MsgDLCError_Cnt_T_u08 == PrevISDYNCMM388MsgDLCError_Cnt_M_u08 )
			{
				
				if( VitesseVehicleBV_Cnt_T_u16 == (uint16)kVITESSE_VEHICLE_BV_Invalid )
				{
					VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				VitesseVehicleBV_Kph_T_f32 = ((float32)VitesseVehicleBV_Cnt_T_u16) * D_VEHSPDSCALE_CNT_F32;
				
				if( (VVHTYPE_Cnt_T_u08 < 1u) &&
					(VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
				{
					if( VVHTYPE1Count_Cnt_M_u08 < 10u )
					{
						VVHTYPE1Count_Cnt_M_u08++;
					}
					else
					{
						VVHTYPE_Cnt_T_u08 = 1u;
						*Rte_Pim_VVHTYPEData() = 1u;
						Rte_Call_VHHTYPE_WriteBlock(NULL_PTR); /* PRQA S 3200 */
					}
				}
				
				if( CMM388NTCsEnabled_Cnt_M_lgc == TRUE )
				{
					
					/* NTC 16C - IS_DYN_CMM Vehicle Speed Invalid (Msg ID 388) */
					ValidityNTCProcessing(VitesseVehicleBVInvalidTestStatus_Cnt_T_u08,
										  &VitesseVehicleBVSigValidCount_Cnt_M_u16,
										  &VitesseVehicleBVSigInvalidCount_Cnt_M_u16,
										  k_VitesseVehicleBVSigValidThresh_Cnt_u16,
										  k_VitesseVehicleBVSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRngFltMsg_V);
					
					/* NTC 16D - IS_DYN_CMM Vehicle Speed Invalid Rate (Msg ID 388) */
					if( (PrevVitesseVehicleBVValid_Cnt_M_lgc == TRUE) &&
						(VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
					{
						if( ((VitesseVehicleBV_Kph_M_f32 - VitesseVehicleBV_Kph_T_f32) > 14.0f) &&
							(VitesseVehicleBV_Kph_T_f32 < 5.0f) )
						{
							VitesseVehicleBVRampTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
						}
						else if (VitesseVehicleBV_Kph_M_f32 > k_VitesseVehicleBVSpeedPassThresh_kph_f32)
						{
							VitesseVehicleBVRampTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
						}
                        else
                        {
                           VitesseVehicleBVRampTestStatus_Cnt_T_u08 = D_TESTDEADBAND_CNT_U08;                            
                        }
						
						ValidityNTCProcessing(VitesseVehicleBVRampTestStatus_Cnt_T_u08,
											  &VitesseVehicleBVRampValidCount_Cnt_M_u16,
											  &VitesseVehicleBVRampInvalidCount_Cnt_M_u16,
											  k_VitesseVehicleBVRampValidThresh_Cnt_u16,
											  1u,
											  NTC_Num_DataRateFltMsg_V);
					}
					
				}
				
				if( VitesseVehicleBVInvalidTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
				{
					VitesseVehicleBV_Kph_M_f32 = VitesseVehicleBV_Kph_T_f32;
					PrevVitesseVehicleBVValid_Cnt_M_lgc = TRUE;
					
					if( VVHTYPE_Cnt_T_u08 == 1u )
					{
						CPKVehicleSpeedValidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedValidCount_Cnt_M_u16, k_CPKVehicleSpeedValidThresh_Cnt_u16);
						CPKVehicleSpeedInvalidCount_Cnt_M_u16 = 0u;
					}
				}
				else
				{
					PrevVitesseVehicleBVValid_Cnt_M_lgc = FALSE;
					
					if( VVHTYPE_Cnt_T_u08 == 1u )
					{
						CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
						CPKVehicleSpeedInvalidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedInvalidCount_Cnt_M_u16, k_CPKVehicleSpeedInvalidThresh_Cnt_u16);
					}
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				
			}
			else
			{
				ISDYNCMM388MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
				VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
				VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
				
				if( VVHTYPE_Cnt_T_u08 == 1u )
				{
					CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
					CPKVehicleSpeedInvalidCount_Cnt_M_u16 = IncToThresh(CPKVehicleSpeedInvalidCount_Cnt_M_u16, k_CPKVehicleSpeedInvalidThresh_Cnt_u16);
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			
			
			if( CMM388NTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 168 - Invalid Message (too short) (Msg ID 388) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDYNCMM388MsgLenValidCount_Cnt_M_u16,
									  &ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16,
									  k_ISDYNCMM388MsgLenValidThresh_Cnt_u16,
									  k_ISDYNCMM388MsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_V);
			}
			
		}
		
		
		
		/*** IS_DYN_AAS Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNAASMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 <= D_ISDYNAASMSGTIMEOUT_MS_U16 )
		{
			CityParkInputMsgTimer_mS_M_u32 = ISDYNAASMsgRxTime_MSec_T_u32;
		}
		
		if( AASNTCsEnabled_Cnt_M_lgc == TRUE )
		{
			
			/* NTC 149 - Missing IS_DYN_AAS Message (Msg ID 2EB) */
			MissingMessageNTCProcessing(ISDYNAASMsgRxTime_MSec_T_u32,
										PrevISDYNAASMsgRxTime_MSec_M_u32,
										&ISDYNAASMsgTimer_mS_M_u32,
										&ISDYNAASMsgTimeValidCount_Cnt_M_u16,
										k_AASNodeTimeout_mS_u16,
										k_ISDYNAASMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_R);
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNAASMSGTIMEOUT_MS_U16 )
			{
				ISDYNAASMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
				ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
				ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
				CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
				DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
				DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDYNAASMsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
			ISDYNAASMsgLenInvalidCount_Cnt_M_u16 = 0u;
			ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
			ISDYNAASChkSumInvalidCount_Cnt_M_u16 = 0u;
			ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
			ISDYNAASMsgCountInvalidCount_Cnt_M_u16 = 0u;
			CONSANGLECPKSigInvalidCount_Cnt_M_u16 = 0u;
			CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
			DMDFCTCPKSigInvalidCount_Cnt_M_u16 = 0u;
			DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
			DMDRELAXECPKSigInvalidCount_Cnt_M_u16 = 0u;
			DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
		}
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CityParkInputMsgTimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 > D_ISDYNAASMSGTIMEOUT_MS_U16 )
		{
			DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
			CityParkInputValidCount_Cnt_M_u16 = 0u;
			CityParkInputInvalidCount_Cnt_M_u16 = IncToThresh(CityParkInputInvalidCount_Cnt_M_u16, k_CityParkInputInvalidThresh_Cnt_u16);
			CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		}
		
		if( ISDYNAASMsgRxTime_MSec_T_u32 != PrevISDYNAASMsgRxTime_MSec_M_u32 )
		{
			
			if( ISDYNAASMsgDLCError_Cnt_T_u08 == PrevISDYNAASMsgDLCError_Cnt_M_u08 )
			{
				
				/* Checksum */
				
				Checksum_Cnt_T_u08 = (uint8)( (ISDYNAASMsg_Cnt_T_u08[0] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[0] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[1] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[1] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[2] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[2] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[3] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[3] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[4] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[4] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[5] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[5] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[6] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[6] >> 4) & 0x0Fu) +
											  (ISDYNAASMsg_Cnt_T_u08[7] & 0x0Fu) + ((ISDYNAASMsg_Cnt_T_u08[7] >> 4) & 0x0Fu) +
											  11u );
				
				if( (Checksum_Cnt_T_u08 & 0x0Fu) != 0x0Fu )
				{
					ChkSumTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					ChkSumTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				/* Message Progress Counter */
				
				MsgCount_Cnt_T_u08 = ISDYNAASMsg_Cnt_T_u08[3] & 0x0Fu;
				
				if( MsgCount_Cnt_T_u08 != ISDYNAASMsgCount_Cnt_M_u08 )
				{
					MsgCountTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					MsgCountTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				ISDYNAASMsgCount_Cnt_M_u08 = (MsgCount_Cnt_T_u08 + 1u) & 0x0Fu;
				
				
				/* City Park Commanded Angle */
				
				CONSANGLECPK_Cnt_T_u16 = (((uint16)ISDYNAASMsg_Cnt_T_u08[0]) << 8) + ISDYNAASMsg_Cnt_T_u08[1];
				
				if( (CONSANGLECPK_Cnt_T_u16 > D_CONSANGLECPKVALIDLO_CNT_U16) &&
					(CONSANGLECPK_Cnt_T_u16 < D_CONSANGLECPKVALIDHI_CNT_U16) )
				{
					CONSANGLECPKTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					CONSANGLECPKTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				/* City Park Command Request */
				
				DMDFCTCPK_Cnt_T_u08 = (ISDYNAASMsg_Cnt_T_u08[2] >> 6) & 0x03u;
				
				if( DMDFCTCPK_Cnt_T_u08 == (uint8)kDMD_FCT_CPK_Invalid )
				{
					DMDFCTCPKTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					DMDFCTCPKTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				/* City Park Relaxe Request */
				
				DMDRELAXECPK_Cnt_T_u08 = (ISDYNAASMsg_Cnt_T_u08[2] >> 4) & 0x03u;
				
				if( (DMDRELAXECPK_Cnt_T_u08 == (uint8)kDMD_RELAXE_CPK_Reserved) ||
					(DMDRELAXECPK_Cnt_T_u08 == (uint8)kDMD_RELAXE_CPK_Invalid) )
				{
					DMDRELAXECPKTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					DMDRELAXECPKTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				if( AASNTCsEnabled_Cnt_M_lgc == TRUE )
				{
					
					/* NTC 14A - IS_DYN_AAS Checksum Failure (Msg ID 2EB) */
					ValidityNTCProcessing(ChkSumTestStatus_Cnt_T_u08,
										  &ISDYNAASChkSumValidCount_Cnt_M_u16,
										  &ISDYNAASChkSumInvalidCount_Cnt_M_u16,
										  k_ISDYNAASChkSumValidThresh_Cnt_u16,
										  k_ISDYNAASChkSumInvalidThresh_Cnt_u16,
										  NTC_Num_CRCFltMsg_R);
					
					/* NTC 14B - IS_DYN_AAS Process Counter Failure (Msg ID 2EB) */
					ValidityNTCProcessing(MsgCountTestStatus_Cnt_T_u08,
										  &ISDYNAASMsgCountValidCount_Cnt_M_u16,
										  &ISDYNAASMsgCountInvalidCount_Cnt_M_u16,
										  k_ISDYNAASMsgCountValidThresh_Cnt_u16,
										  k_ISDYNAASMsgCountInvalidThresh_Cnt_u16,
										  NTC_Num_PgrsCntFltMsg_R);
					
					/* NTC 14C - CONS_ANGLE_CPK Invalid (Msg ID 2EB) */
					ValidityNTCProcessing(CONSANGLECPKTestStatus_Cnt_T_u08,
										  &CONSANGLECPKSigValidCount_Cnt_M_u16,
										  &CONSANGLECPKSigInvalidCount_Cnt_M_u16,
										  k_CONSANGLECPKSigValidThresh_Cnt_u16,
										  k_CONSANGLECPKSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRngFltMsg_R);
					
					/* NTC 14D - DMD_FCT_CPK Invalid (Msg ID 2EB) */
					ValidityNTCProcessing(DMDFCTCPKTestStatus_Cnt_T_u08,
										  &DMDFCTCPKSigValidCount_Cnt_M_u16,
										  &DMDFCTCPKSigInvalidCount_Cnt_M_u16,
										  k_DMDFCTCPKSigValidThresh_Cnt_u16,
										  k_DMDFCTCPKSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRateFltMsg_R);
					
					/* NTC 14E - DMD_RELAXE_CPK Invalid (Msg ID 2EB) */
					ValidityNTCProcessing(DMDRELAXECPKTestStatus_Cnt_T_u08,
										  &DMDRELAXECPKSigValidCount_Cnt_M_u16,
										  &DMDRELAXECPKSigInvalidCount_Cnt_M_u16,
										  k_DMDRELAXECPKSigValidThresh_Cnt_u16,
										  k_DMDRELAXECPKSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataOtherFltMsg_R);
					
				}				
				
				if( (ChkSumTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(MsgCountTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
				{
                    if (CONSANGLECPKTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) 
                    {
                        CONSANGLECPK_Cnt_M_u16 = CONSANGLECPK_Cnt_T_u16;
                        CONSANGLECPK_HwDeg_M_f32 = ((float32)((sint16)CONSANGLECPK_Cnt_T_u16)) * D_CONSANGLECPKSCALE_CNT_F32 * D_CONSANGLECPKPOL_CNT_F32;
                        CONSANGLECPK_HwDeg_M_f32 = Limit_m(CONSANGLECPK_HwDeg_M_f32, k_CONSANGLECPKMin_HwDeg_f32, k_CONSANGLECPKMax_HwDeg_f32);
                    }
                    
                    if ( (CONSANGLECPKTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(DMDFCTCPKTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) &&
					(DMDRELAXECPKTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08) )
                    {
                        CityParkInputValidCount_Cnt_M_u16 = IncToThresh(CityParkInputValidCount_Cnt_M_u16, k_CityParkInputValidThresh_Cnt_u16);
                        CityParkInputInvalidCount_Cnt_M_u16 = 0u;					
                    }
                    else
                    {
                        CityParkInputValidCount_Cnt_M_u16 = 0u;
                        CityParkInputInvalidCount_Cnt_M_u16 = IncToThresh(CityParkInputInvalidCount_Cnt_M_u16, k_CityParkInputInvalidThresh_Cnt_u16);
                    }
                    
					DMDFCTCPK_Cnt_M_u08 = DMDFCTCPK_Cnt_T_u08;
					DMDRELAXECPK_Cnt_M_u08 = DMDRELAXECPK_Cnt_T_u08;

					if (DMDRELAXECPK_Cnt_M_u08 == PrevDMDRELAXECPK_Cnt_M_u08)
					{
						DMDRelaxeConsistentCount_Cnt_M_u16 = IncToThresh(DMDRelaxeConsistentCount_Cnt_M_u16, k_DMDRelaxeConsistentThresh_Cnt_u16);
					}
					else
					{
						DMDRelaxeConsistentCount_Cnt_M_u16 = 1u;
                        PrevDMDRELAXECPK_Cnt_M_u08 = DMDRELAXECPK_Cnt_M_u08;
					}
                    
                    if(DMDFCTCPK_Cnt_T_u08 == PrevDMDFCTCPK_Cnt_M_u08) 
					{
						CityParkInputConsistentCount_Cnt_M_u16 = IncToThresh(CityParkInputConsistentCount_Cnt_M_u16, k_DMDFCTCPKValidCount_Cnt_u16);
					}
					else
					{
						CityParkInputConsistentCount_Cnt_M_u16 = 1u;
                        PrevDMDFCTCPK_Cnt_M_u08 = DMDFCTCPK_Cnt_T_u08;
					}
                    
				}
				else
				{
					DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
                    CityParkInputValidCount_Cnt_M_u16 = 0u;
                    CityParkInputInvalidCount_Cnt_M_u16 = IncToThresh(CityParkInputInvalidCount_Cnt_M_u16, k_CityParkInputInvalidThresh_Cnt_u16);
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				
			}
			else
			{
				ISDYNAASMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
				ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
				ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
				CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
				DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
				DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
				
				CityParkInputValidCount_Cnt_M_u16 = 0u;
				CityParkInputInvalidCount_Cnt_M_u16 = IncToThresh(CityParkInputInvalidCount_Cnt_M_u16, k_CityParkInputInvalidThresh_Cnt_u16);
				DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			
			
			if( AASNTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 148 - IS_DYN_AAS (too short) (Msg ID 2EB) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDYNAASMsgLenValidCount_Cnt_M_u16,
									  &ISDYNAASMsgLenInvalidCount_Cnt_M_u16,
									  k_ISDYNAASMsgLenValidThresh_Cnt_u16,
									  k_ISDYNAASMsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_R);
			}
			
		}
		
		
		
		/*** IS_INTE_ELECTRON_BSI Message Handling ***/
		
		if( ISINTEELECTRONBSIMsgRxTime_MSec_T_u32 != PrevISINTEELECTRONBSIMsgRxTime_MSec_M_u32 )
		{
			if( (DiagOn_Cnt_M_lgc == TRUE) ||
				(SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE) )
			{
				ElecIntCount_Cnt_M_u08 = 0u;
				EffacDefaultDiagCount_Cnt_M_u08 = 0u;
			}
			else
			{
				
				if( (DiagIntegraElec_Cnt_T_u08 == PrevDiagIntegraElec_Cnt_M_u08) &&
					(ModeDiag_Cnt_T_u08 == PrevModeDiag_Cnt_M_u08) )
				{
					if( ElecIntCount_Cnt_M_u08 < D_ELECINTCONSECMSGS_CNT_U08 )
					{
						ElecIntTimer_mS_M_u32[ElecIntCount_Cnt_M_u08] = SystemTime_mS_T_u32;
						ElecIntCount_Cnt_M_u08++;
					}
					else
					{
						Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ElecIntTimer_mS_M_u32[0u], &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
						
						if( ElapsedTime_mS_T_u16 > D_ELECINTCONSECTIMEOUT_MS_U16 )
						{
							for( i = 0u; i < (D_ELECINTCONSECMSGS_CNT_U08 - 1u); i++ )
							{
								ElecIntTimer_mS_M_u32[i] = ElecIntTimer_mS_M_u32[i + 1u];
							}
							
							ElecIntTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08 - 1u] = SystemTime_mS_T_u32;
						}
						else if( (ModeDiag_Cnt_T_u08 == (uint8)kMODE_DIAG_Operation_and_Comm_Inhibited) &&
								 (DiagIntegraElec_Cnt_T_u08 == (uint8)kDIAG_INTEGRA_ELEC_No_Frame_Transmission) )
						{
							ElectronicIntegrationCmd_Cnt_M_lgc = TRUE;
						}
						else if( (ModeDiag_Cnt_T_u08 == (uint8)kMODE_DIAG_No_Particular_Operation) &&
								 (DiagIntegraElec_Cnt_T_u08 == (uint8)kDIAG_INTEGRA_ELEC_No_Particular_Operation) )
						{
							ElectronicIntegrationCmd_Cnt_M_lgc = FALSE;
						}
						else
						{
							/* do nothing */
						}
					}
				}
				else
				{
					ElecIntTimer_mS_M_u32[0u] = SystemTime_mS_T_u32;
					ElecIntCount_Cnt_M_u08 = 1u;
					
					PrevDiagIntegraElec_Cnt_M_u08 = DiagIntegraElec_Cnt_T_u08;
					PrevModeDiag_Cnt_M_u08 = ModeDiag_Cnt_T_u08;
				}
				
				if( EffacDefaultDiag_Cnt_T_u08 == (uint8)kEFFAC_DEFAULT_DIAG_Default_Memory_Erase )
				{
					if( EffacDefaultDiagCount_Cnt_M_u08 < D_ELECINTCONSECMSGS_CNT_U08 )
					{
						EffacDefaultDiagTimer_mS_M_u32[EffacDefaultDiagCount_Cnt_M_u08] = SystemTime_mS_T_u32;
						EffacDefaultDiagCount_Cnt_M_u08++;
					}
					else
					{
						Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EffacDefaultDiagTimer_mS_M_u32[0u], &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
						
						if( ElapsedTime_mS_T_u16 > D_ELECINTCONSECTIMEOUT_MS_U16 )
						{
							for( i = 0u; i < (D_ELECINTCONSECMSGS_CNT_U08 - 1u); i++ )
							{
								EffacDefaultDiagTimer_mS_M_u32[i] = EffacDefaultDiagTimer_mS_M_u32[i + 1u];
							}
							
							EffacDefaultDiagTimer_mS_M_u32[D_ELECINTCONSECMSGS_CNT_U08 - 1u] = SystemTime_mS_T_u32;
						}
						else
						{
							EffacDefaultDiagCount_Cnt_M_u08 = 0u;
							ClearDTCs_Cnt_M_lgc = TRUE;
						}
					}
				}
				else
				{
					EffacDefaultDiagCount_Cnt_M_u08 = 0u;
				}
				
			}
			
		}
		
		if( ElectronicIntegration_Cnt_T_lgc == TRUE )
		{
			if( (DiagOn_Cnt_M_lgc == TRUE) ||
				(ElectronicIntegrationCmd_Cnt_M_lgc == FALSE) ||
				(CTermActive_Cnt_T_lgc == TRUE) ||
				(EpsEn_Cnt_T_lgc == FALSE) )
			{
				ElecIntCount_Cnt_M_u08 = 0u;
				ElectronicIntegrationCmd_Cnt_M_lgc = FALSE;
				*Rte_Pim_ElecIntData() = FALSE;
				Rte_Call_ElecInt_WriteBlock(NULL_PTR); /* PRQA S 3200 */
				
				Rte_Call_SrlComDriver_SCom_ElecIntStop(); /* PRQA S 3200 */
			}
		}
		else
		{
			if( (ElectronicIntegrationCmd_Cnt_M_lgc == TRUE) &&
				(DiagOn_Cnt_M_lgc == FALSE) &&
				(CTermActive_Cnt_T_lgc == FALSE) &&
				(SystemState_Cnt_T_enum != RTE_MODE_StaMd_Mode_OPERATE) )
			{
				ElecIntCount_Cnt_M_u08 = 0u;
				*Rte_Pim_ElecIntData() = TRUE;
				Rte_Call_ElecInt_WriteBlock(NULL_PTR); /* PRQA S 3200 */
				
				Rte_Call_SrlComDriver_SCom_ElecIntStart(); /* PRQA S 3200 */
			}
		}
		
		if( ClearDTCs_Cnt_M_lgc == TRUE )
		{
			ClearDTCRetVal_Cnt_T_enum = NtWrapC_Dem_ClearDTC(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS, (Dem_DTCOriginType)DEM_DTC_ORIGIN_PRIMARY_MEMORY);
			
			if( ClearDTCRetVal_Cnt_T_enum != (Dem_ReturnClearDTCType)DEM_DTC_PENDING )
			{
				ClearDTCs_Cnt_M_lgc = FALSE;
			}
		}
		
		
		
		/*** IS_DYN_CMM_208 Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYNCMM208MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( CMMNTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 121 - Missing IS_DYN_CMM Message (Msg ID 208) */
			MissingMessageNTCProcessing(ISDYNCMM208MsgRxTime_MSec_T_u32,
										PrevISDYNCMM208MsgRxTime_MSec_M_u32,
										&ISDYNCMM208MsgTimer_mS_M_u32,
										&ISDYNCMM208MsgTimeValidCount_Cnt_M_u16,
										k_EMNodeTimeout_mS_u16,
										k_ISDYNCMM208MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_M);
			
			if( ElapsedTime_mS_T_u16 > D_ISDYNCMM208MSGTIMEOUT_MS_U16 )
			{
				ISDYNCMM208MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDYNCMM208MsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
			ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if( ISDYNCMM208MsgRxTime_MSec_T_u32 != PrevISDYNCMM208MsgRxTime_MSec_M_u32 )
		{
			
			if( ISDYNCMM208MsgDLCError_Cnt_T_u08 == PrevISDYNCMM208MsgDLCError_Cnt_M_u08 )
			{
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			}
			else
			{
				ISDYNCMM208MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			
			
			if( CMMNTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 120 - Invalid Message (too short) (Msg ID 208) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDYNCMM208MsgLenValidCount_Cnt_M_u16,
									  &ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16,
									  k_ISDYNCMM208MsgLenValidThresh_Cnt_u16,
									  k_ISDYNCMM208MsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_M);
			}
			
		}
		
		
		
		/*** IS_DYN2_CMM Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDYN2CMMMsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 > D_ISDYN2CMMMSGTIMEOUT_MS_U16 )
		{
			EngOnDLCInvalidCount_Cnt_M_u08 = 0u;
			Msg348Valid_Cnt_M_lgc = FALSE;
		}
		
		if( CMMNTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 129 - Missing IS_DYN2_CMM Message (Msg ID 348) */
			MissingMessageNTCProcessing(ISDYN2CMMMsgRxTime_MSec_T_u32,
										PrevISDYN2CMMMsgRxTime_MSec_M_u32,
										&ISDYN2CMMMsgTimer_mS_M_u32,
										&ISDYN2CMMMsgTimeValidCount_Cnt_M_u16,
										k_EMNodeTimeout_mS_u16,
										k_ISDYN2CMMMsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_N);
			
			if( ElapsedTime_mS_T_u16 > D_ISDYN2CMMMSGTIMEOUT_MS_U16 )
			{
				ValidEngineStatusCount_Cnt_M_u08 = 0u;
				ISDYN2CMMMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
				EtatMTSigValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDYN2CMMMsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
			ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 = 0u;
			EtatMTSigValidCount_Cnt_M_u16 = 0u;
			EtatMTSigInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if( ISDYN2CMMMsgRxTime_MSec_T_u32 != PrevISDYN2CMMMsgRxTime_MSec_M_u32 )
		{
			
			if( ISDYN2CMMMsgDLCError_Cnt_T_u08 == PrevISDYN2CMMMsgDLCError_Cnt_M_u08 )
			{
			
				/* Engine Status */
				
				EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
				
				if( EtatMT_Cnt_T_u08 == PrevEtatMT_Cnt_M_u08 )
				{
					if( CountEtatMT_Cnt_M_u08 < 3u )
					{
						CountEtatMT_Cnt_M_u08++;
						
						if( CountEtatMT_Cnt_M_u08 >= 3u )
						{
							if( (EtatMT_Cnt_T_u08 == (uint8)kETAT_MT_Engine_Running) ||
								(EtatMT_Cnt_T_u08 == (uint8)kETAT_MT_Stopped) ||
								(EtatMT_Cnt_T_u08 == (uint8)kETAT_MT_Driven_Restart) ||
								(EtatMT_Cnt_T_u08 == (uint8)kETAT_MT_Autonomous_Restart) ||
								(EtatMT_Cnt_T_u08 == (uint8)kETAT_MT_Degraded_Restart) )
							{
								EngOn_Cnt_M_lgc = TRUE;
							}
							else
							{
								EngOn_Cnt_M_lgc = FALSE;
							}
						}
					}
				}
				else
				{
					CountEtatMT_Cnt_M_u08 = 1u;
					PrevEtatMT_Cnt_M_u08 = EtatMT_Cnt_T_u08;
				}
				
				
				if( (EtatMT_Cnt_T_u08 > (uint8)kETAT_MT_Engine_Preparing) &&
					(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Autonomous_Starting) &&
					(EtatMT_Cnt_T_u08 != (uint8)kETAT_MT_Autonomous_Restart) )
				{
					EtatMTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					EtatMTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}
				
				
				if( CMMNTCsEnabled_Cnt_M_lgc == TRUE )
				{
					
					/* NTC 12C - Engine State Invalid (Msg ID 348) */
					ValidityNTCProcessing(EtatMTTestStatus_Cnt_T_u08,
										  &EtatMTSigValidCount_Cnt_M_u16,
										  &EtatMTSigInvalidCount_Cnt_M_u16,
										  k_EtatMTSigValidThresh_Cnt_u16,
										  k_EtatMTSigInvalidThresh_Cnt_u16,
										  NTC_Num_DataRngFltMsg_N);
					
					if( EtatMTSigInvalidCount_Cnt_M_u16 >= k_EtatMTSigInvalidThresh_Cnt_u16 )
					{
						ValidEngineStatusCount_Cnt_M_u08 = 0u;
					}
				}
				
				if( EtatMTTestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
				{
					ValidEngineStatusCount_Cnt_M_u08 = IncToThresh(ValidEngineStatusCount_Cnt_M_u08, 3u);
				}
				
				EngOnDLCInvalidCount_Cnt_M_u08 = 0u;
				
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				
				Msg348Valid_Cnt_M_lgc = TRUE;
				
			}
			else
			{
				CountEtatMT_Cnt_M_u08 = 0u;
				
				ISDYN2CMMMsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
				EtatMTSigValidCount_Cnt_M_u16 = 0u;
				
				if( EngOnDLCInvalidCount_Cnt_M_u08 < 3u )
				{
					EngOnDLCInvalidCount_Cnt_M_u08++;
					
					if( EngOnDLCInvalidCount_Cnt_M_u08 >= 3u )
					{
						EngOn_Cnt_M_lgc = FALSE;
					}
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				
				Msg348Valid_Cnt_M_lgc = FALSE;
			}
			
			
			if( CMMNTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 128 - Invalid Message (too short) (Msg ID 348) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDYN2CMMMsgLenValidCount_Cnt_M_u16,
									  &ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16,
									  k_ISDYN2CMMMsgLenValidThresh_Cnt_u16,
									  k_ISDYN2CMMMsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_N);
				
				if( ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 >= k_ISDYN2CMMMsgLenInvalidThresh_Cnt_u16 )
				{
					ValidEngineStatusCount_Cnt_M_u08 = 0u;
				}
			}
			
		}
		
		
		
		/*** IS_DAT_BSI_3F2 Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI3F2MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( BSI3F2NTCsEnabled_Cnt_M_lgc == TRUE )
		{
			
			/* NTC 141 - Missing IS_DAT_BSI_3F2 (Msg ID 3F2) */
            
            if (TRUE == STTdSelected_Cnt_T_lgc)
            {
                MissingMessageNTCProcessing(ISDATBSI3F2MsgRxTime_MSec_T_u32,
                                            PrevISDATBSI3F2MsgRxTime_MSec_M_u32,
                                            &ISDATBSI3F2MsgTimer_mS_M_u32,
                                            &ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16,
                                            k_BSINodeTimeout_mS_u16,
                                            k_ISDATBSI3F2MsgTimeValidThresh_Cnt_u16,
                                            NTC_Num_MissingMsg_Q);
                
                if( ElapsedTime_mS_T_u16 > D_ISDATBSI3F2MSGTIMEOUT_MS_U16 )
                {
                    ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16 = 0u;
                    ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
                }


				/* NTC 146 - Invalid Power Cut Request (Msg ID 3F2) */
				if( (DmdDelestDA_Cnt_T_u08 != (uint8)kDMD_DELEST_DA_Power_Cut_Request) ||
					(VehicleSpeed_Kph_T_f32 < k_PowerCutVehSpdLowThresh_Kph_f32) ||
					(VehicleSpeedValid_Cnt_M_lgc == FALSE) )
				{
					DmdDelestDATimer_mS_M_u32 = SystemTime_mS_T_u32;
				}

				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DmdDelestDATimer_mS_M_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */

				if( (DmdDelestDA_Cnt_T_u08 == (uint8)kDMD_DELEST_DA_Power_Cut_Request) &&
						( (ElapsedTime_mS_T_u16 >= k_PowerCutVehSpdLowTimeout_mS_u16) ||
						  ( (VehicleSpeed_Kph_T_f32 >= k_PowerCutVehSpdHighThresh_Kph_f32) &&
							(VehicleSpeedValid_Cnt_M_lgc == TRUE) ) ) )
				{
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_FAILED); /* PRQA S 3200 */
				}
				else
				{
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Q, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
				}
            }
			
		}
		else
		{
			ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			DmdDelestDATimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
			ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if(ISDATBSI3F2MsgRxTime_MSec_T_u32 != PrevISDATBSI3F2MsgRxTime_MSec_M_u32)
		{
			if( ISDATBSI3F2MsgDLCError_Cnt_T_u08 == PrevISDATBSI3F2MsgDLCError_Cnt_M_u08 )
			{
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			}
			else
			{
				ISDATBSI3F2MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}

			
			
			if( (BSI3F2NTCsEnabled_Cnt_M_lgc == TRUE)  &&
			    ( (STTdSelected_Cnt_T_lgc == TRUE) || (LXASelected_Cnt_T_lgc == TRUE) ) )
			{
				/* NTC 140 - IS_DAT_BSI_3F2 Invalid Message (too short) (Msg ID 3F2) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDATBSI3F2MsgLenValidCount_Cnt_M_u16,
									  &ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16,
									  k_ISDATBSI3F2MsgLenValidThresh_Cnt_u16,
									  k_ISDATBSI3F2MsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_Q);
			}
			
		}
		
		
		
		/*** IS_DAT_BSI_412 Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI412MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( BSI412NTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 159 - Missing IS_DAT_BSI_412 Message (Msg ID 412) */
			MissingMessageNTCProcessing(ISDATBSI412MsgRxTime_MSec_T_u32,
										PrevISDATBSI412MsgRxTime_MSec_M_u32,
										&ISDATBSI412MsgTimer_mS_M_u32,
										&ISDATBSI412MsgTimeValidCount_Cnt_M_u16,
										k_BSINodeTimeout_mS_u16,
										k_ISDATBSI412MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_T);
			
			if( ElapsedTime_mS_T_u16 > D_ISDATBSI412MSGTIMEOUT_MS_U16 )
			{
				ISDATBSI412MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDATBSI412MsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
			ISDATBSI412MsgLenInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if( ISDATBSI412MsgRxTime_MSec_T_u32 != PrevISDATBSI412MsgRxTime_MSec_M_u32 )
		{
			
			if( ISDATBSI412MsgDLCError_Cnt_T_u08 == PrevISDATBSI412MsgDLCError_Cnt_M_u08 )
			{
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
			}
			else
			{
				ISDATBSI412MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
			}
			
			
			if( BSI412NTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 158 - IS_DAT_BSI_412 Invalid Message (too short) (Msg ID 412) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDATBSI412MsgLenValidCount_Cnt_M_u16,
									  &ISDATBSI412MsgLenInvalidCount_Cnt_M_u16,
									  k_ISDATBSI412MsgLenValidThresh_Cnt_u16,
									  k_ISDATBSI412MsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_T);
			}
			
		}
		
		
		
		/*** IS_DAT_BSI_432 Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDATBSI432MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 > D_ISDATBSI432MSGTIMEOUT_MS_U16 )
		{
			Msg432Valid_Cnt_M_lgc = FALSE;
		}
		
		if( BSI432NTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 139 - Missing IS_DAT_BSI Message (Msg ID 432) */
			MissingMessageNTCProcessing(ISDATBSI432MsgRxTime_MSec_T_u32,
										PrevISDATBSI432MsgRxTime_MSec_M_u32,
										&ISDATBSI432MsgTimer_mS_M_u32,
										&ISDATBSI432MsgTimeValidCount_Cnt_M_u16,
										k_BSINodeTimeout_mS_u16,
										k_ISDATBSI432MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_P);
			
			if( ElapsedTime_mS_T_u16 > D_ISDATBSI432MSGTIMEOUT_MS_U16 )
			{
				ISDATBSI432MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
			}
		}
		else
		{
			ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDATBSI432MsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
			ISDATBSI432MsgLenInvalidCount_Cnt_M_u16 = 0u;
		}
		
		if( ISDATBSI432MsgRxTime_MSec_T_u32 != PrevISDATBSI432MsgRxTime_MSec_M_u32 )
		{
			
			if( ISDATBSI432MsgDLCError_Cnt_T_u08 == PrevISDATBSI432MsgDLCError_Cnt_M_u08 )
			{
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;

				Msg432Valid_Cnt_M_lgc = TRUE;
			}
			else
			{
				ISDATBSI432MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
				
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				
				Msg432Valid_Cnt_M_lgc = FALSE;
			}

			
			if( BSI432NTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 138 - Invalid Message (too short) (Msg ID 432) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDATBSI432MsgLenValidCount_Cnt_M_u16,
									  &ISDATBSI432MsgLenInvalidCount_Cnt_M_u16,
									  k_ISDATBSI432MsgLenValidThresh_Cnt_u16,
									  k_ISDATBSI432MsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_P);
			}
			
		}
		
		
		
		/*** IS_DAT4_V2_BSI_552 Message Handling ***/
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ISDAT4V2BSI552MsgRxTime_MSec_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 > D_ISDAT4V2BSI552MSGTIMEOUT_MS_U16 )
		{
			Msg552Valid_Cnt_M_lgc = FALSE;
		}
		
		if( BSI552NTCsEnabled_Cnt_M_lgc == TRUE )
		{
			/* NTC 161 - Missing IS_DAT4_BSI_552 Message (Msg ID 552) */
			MissingMessageNTCProcessing(ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
										PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
										&ISDAT4V2BSI552MsgTimer_mS_M_u32,
										&ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16,
										k_BSI552MsgTimeout_mS_u16,
										k_ISDAT4V2BSI552MsgTimeValidThresh_Cnt_u16,
										NTC_Num_MissingMsg_U);
			
			if( ElapsedTime_mS_T_u16 > D_ISDAT4V2BSI552MSGTIMEOUT_MS_U16 )
			{
				ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
				CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
				ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
                DateValidCount_Cnt_M_u16 = 0u;
			}

			if( k_JDD2010Selected_Cnt_lgc == TRUE )
			{
				/* NTC 164 - CPT_TEMPOREL Invalid (Msg ID 552) */
				if( CompteurTemporelVehicule_Cnt_T_u32 == D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32 )
				{
					CompteurTemporelVehiculeTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					CompteurTemporelVehiculeTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}

				MixedTimeValidityNTCProcessing(CompteurTemporelVehiculeTestStatus_Cnt_T_u08,
											   ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
											   PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
											   &CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32,
											   &CompteurTemporelVehiculeSigValidCount_Cnt_M_u16,
											   k_BSI552MsgTimeout_mS_u16,
											   k_CptTemporelSigValidThresh_Cnt_u16,
											   NTC_Num_DataRngFltMsg_U);

				/* NTC 165 - COMPUTER_RAZ_GCT Invalid (Msg ID 552) */
				if( ComputerRazGCT_Cnt_T_u08 == D_COMPUTERRAZGCTINVALID_CNT_U08 )
				{
					ComputerRazGCTTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					ComputerRazGCTTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}

				MixedTimeValidityNTCProcessing(ComputerRazGCTTestStatus_Cnt_T_u08,
											   ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
											   PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
											   &ComputerRazGCTSigInvalidTimer_mS_M_u32,
											   &ComputerRazGCTSigValidCount_Cnt_M_u16,
											   k_BSI552MsgTimeout_mS_u16,
											   k_ComputerRazGCTSigValidThresh_Cnt_u16,
											   NTC_Num_DataRateFltMsg_U);
			}
			else
			{
				/* NTC 166 - Date 2004 invalid (Msg ID 552) */
				if( (AnneeEcoule_Cnt_T_u08 == D_ANNEEECOULEINVALID_CNT_U08) ||
					(JourEcoule_Cnt_T_u16 == D_JOURECOULEINVALID_CNT_U16) ||
					(SecondeEcoulee_Cnt_T_u32 == D_SECONDEECOULEEINVALID_CNT_U32) )
				{
					DateTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				}
				else
				{
					DateTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				}

				MixedTimeValidityNTCProcessing(DateTestStatus_Cnt_T_u08,
											   ISDAT4V2BSI552MsgRxTime_MSec_T_u32,
											   PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32,
											   &DateInvalidTimer_mS_M_u32,
											   &DateValidCount_Cnt_M_u16,
											   k_BSI552MsgTimeout_mS_u16,
											   k_DateValidThresh_Cnt_u16,
											   NTC_Num_DataOtherFltMsg_U);
			}
		}
		else
		{
			ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16 = 0u;
			ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
			ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16 = 0u;
			CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
			CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
			ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
			ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
			DateValidCount_Cnt_M_u16 = 0u;
			DateInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
		}
		
		if( ISDAT4V2BSI552MsgRxTime_MSec_T_u32 != PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32 )
		{
			
			if( ISDAT4V2BSI552MsgDLCError_Cnt_T_u08 == PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08 )
			{
				
				if( (StartupTimeCalculated_Cnt_M_lgc == FALSE) &&
					(EEPROMCloseFailed_Cnt_T_lgc == FALSE) &&
					((Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc == TRUE) &&
					(Msg552Valid_Cnt_M_lgc == TRUE) )
				{
					if( k_JDD2010Selected_Cnt_lgc == TRUE )
					{
						if( CompteurTemporelVehicule_Cnt_T_u32 != D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32 )
						{
							StartupTime_Sec_T_u32 = CompteurTemporelVehicule_Cnt_T_u32 / D_COMPTEURTEMPORELVEHICULESCALE_SECPCNT_U32;
							
							StartupTimeCalculated_Cnt_M_lgc = TRUE;
						}
					}
					else
					{
						if( (AnneeEcoule_Cnt_T_u08 != D_ANNEEECOULEINVALID_CNT_U08) &&
							(JourEcoule_Cnt_T_u16 != D_JOURECOULEINVALID_CNT_U16) &&
							(SecondeEcoulee_Cnt_T_u32 != D_SECONDEECOULEEINVALID_CNT_U32) )
						{
							StartupTime_Sec_T_u32 = (((uint32)AnneeEcoule_Cnt_T_u08) * D_SECONDSPERYEAR_CNT_U32) +
													(((uint32)JourEcoule_Cnt_T_u16) * D_SECONDSPERDAY_CNT_U32) +
													SecondeEcoulee_Cnt_T_u32;
							
							StartupTimeCalculated_Cnt_M_lgc = TRUE;
						}
					}
					
					if( (StartupTimeCalculated_Cnt_M_lgc == TRUE) &&
						(StartupTime_Sec_T_u32 > (Rte_Pim_ShutdownTimeData())->Time_Sec_u32) )
					{
						IgnTimeOff_Sec_M_u32 = StartupTime_Sec_T_u32 - (Rte_Pim_ShutdownTimeData())->Time_Sec_u32;
						VehTimeValid_Cnt_M_lgc = TRUE;
					}
				}
				
				DLCTestStatus_Cnt_T_u08 = D_TESTPASSED_CNT_U08;
				
				Msg552Valid_Cnt_M_lgc = TRUE;
				
			}
			else
			{
				ISDAT4V2BSI552MsgTimeValidCount_Cnt_M_u16 = 0u;
				ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
				CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
				ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
				DateValidCount_Cnt_M_u16 = 0u;
                
				DLCTestStatus_Cnt_T_u08 = D_TESTFAILED_CNT_U08;
				
				Msg552Valid_Cnt_M_lgc = FALSE;
			}
			
			
			if( BSI552NTCsEnabled_Cnt_M_lgc == TRUE )
			{
				/* NTC 160 - Invalid Message (too short) (Msg ID 552) */
				ValidityNTCProcessing(DLCTestStatus_Cnt_T_u08,
									  &ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16,
									  &ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16,
									  k_ISDAT4V2BSI552MsgLenValidThresh_Cnt_u16,
									  k_ISDAT4V2BSI552MsgLenInvalidThresh_Cnt_u16,
									  NTC_Num_InvalidMsg_U);
			}
			
		}
		
		
		
		/* Serial Com Angle Validity */
		
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_S, &InvalidMsgS_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_S, &MissingMsgS_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_CRCFltMsg_S, &CRCFltMsgS_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PgrsCntFltMsg_S, &PgrsCntFltMsgS_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_S, &DataRngFltMsgS_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRateFltMsg_S, &DataRateFltMsgS_Cnt_T_lgc); /* PRQA S 3200 */
		
		if( (CAVHCSelected_Cnt_T_lgc == FALSE) ||
			(BusOffCh1_Cnt_T_lgc == TRUE) ||
			(InvalidMsgS_Cnt_T_lgc == TRUE) ||
			(MissingMsgS_Cnt_T_lgc == TRUE) ||
			(CRCFltMsgS_Cnt_T_lgc == TRUE) ||
			(PgrsCntFltMsgS_Cnt_T_lgc == TRUE) ||
			(DataRngFltMsgS_Cnt_T_lgc == TRUE) ||
			(DataRateFltMsgS_Cnt_T_lgc == TRUE) ||
			(AngleVolantValid_Cnt_M_lgc == FALSE) )
		{
			SerialComAngleValid_Cnt_T_lgc = FALSE;
		}
		else
		{
			SerialComAngleValid_Cnt_T_lgc = TRUE;
		}
		
		
		
		/* Vehicle Speed and Validity */
		
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_O, &InvalidMsgO_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_O, &MissingMsgO_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_CRCFltMsg_O, &CRCFltMsgO_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_PgrsCntFltMsg_O, &PgrsCntFltMsgO_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_O, &DataRngFltMsgO_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_V, &InvalidMsgV_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_V, &MissingMsgV_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_V, &DataRngFltMsgV_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRateFltMsg_V, &DataRateFltMsgV_Cnt_T_lgc); /* PRQA S 3200 */
		
		AbsVehSpdDelta_Kph_T_f32 = Abs_f32_m(VehicleSpeed_Kph_T_f32 - PrevSrlComVehSpd_Kph_M_f32);
		
		if( (DefaultVehSpd_Cnt_T_lgc == TRUE) ||
			(InvalidMsgO_Cnt_T_lgc == TRUE) ||
			(MissingMsgO_Cnt_T_lgc == TRUE) ||
			(CRCFltMsgO_Cnt_T_lgc == TRUE) ||
			(PgrsCntFltMsgO_Cnt_T_lgc == TRUE) ||
			(DataRngFltMsgO_Cnt_T_lgc == TRUE) ||
			(InvalidMsgV_Cnt_T_lgc == TRUE) ||
			(MissingMsgV_Cnt_T_lgc == TRUE) ||
			(DataRngFltMsgV_Cnt_T_lgc == TRUE) ||
			(DataRateFltMsgV_Cnt_T_lgc == TRUE) )
		{
			SrlComVehSpd_Kph_T_f32 = k_DefaultVehSpd_Kph_f32;
			VehicleSpeedValid_Cnt_M_lgc = FALSE;
			VehSpdSync_Cnt_M_lgc = FALSE;
		}
		else if( VVHTYPE_Cnt_T_u08 == 2u )
		{
			SrlComVehSpd_Kph_T_f32 = VitesseVehiculeRoues_Kph_M_f32;
			
			if( (VehSpdSync_Cnt_M_lgc == TRUE) ||
				(AbsVehSpdDelta_Kph_T_f32 < FLT_EPSILON) )
			{
				VehicleSpeedValid_Cnt_M_lgc = TRUE;
				VehSpdSync_Cnt_M_lgc = TRUE;
			}
			else
			{
				VehicleSpeedValid_Cnt_M_lgc = FALSE;
			}
			
			PrevSrlComVehSpd_Kph_M_f32 = VitesseVehiculeRoues_Kph_M_f32;
		}
		else if( VVHTYPE_Cnt_T_u08 == 1u )
		{
			SrlComVehSpd_Kph_T_f32 = VitesseVehicleBV_Kph_M_f32;
			
			if( (VehSpdSync_Cnt_M_lgc == TRUE) ||
				(AbsVehSpdDelta_Kph_T_f32 < FLT_EPSILON) )
			{
				VehicleSpeedValid_Cnt_M_lgc = TRUE;
				VehSpdSync_Cnt_M_lgc = TRUE;
			}
			else
			{
				VehicleSpeedValid_Cnt_M_lgc = FALSE;
			}
			
			PrevSrlComVehSpd_Kph_M_f32 = VitesseVehicleBV_Kph_M_f32;
		}
		else
		{
			SrlComVehSpd_Kph_T_f32 = k_DefaultVehSpd_Kph_f32;
			VehicleSpeedValid_Cnt_M_lgc = FALSE;
			VehSpdSync_Cnt_M_lgc = FALSE;
		}
		
		
		
		/* APA Request */
		
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_BusOffCh1NodeMute, &BusOffCh1NodeMute_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_N, &InvalidMsgN_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_N, &MissingMsgN_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_N, &DataRngFltMsgN_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_R, &InvalidMsgR_Cnt_T_lgc); /* PRQA S 3200 */
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_R, &DataOtherFltMsgR_Cnt_T_lgc); /* PRQA S 3200 */
		
		if ( (CityParkInputConsistentCount_Cnt_M_u16 >= k_DMDFCTCPKValidCount_Cnt_u16) &&
			 ( (DMDFCTCPK_Cnt_M_u08 == (uint8)kDMD_FCT_CPK_SCP9_Control_Request) ||
               (DMDFCTCPK_Cnt_M_u08 == (uint8)kDMD_FCT_CPK_SCP6_Control_Request) ) )
		{
			APARequest_Cnt_M_lgc = TRUE;
		}
		else if ( (CityParkInputConsistentCount_Cnt_M_u16 >= k_DMDFCTCPKValidCount_Cnt_u16) &&
                  (DMDFCTCPK_Cnt_M_u08 == (uint8)kDMD_FCT_CPK_No_Request) )
		{
			APARequest_Cnt_M_lgc = FALSE;
		}
        else
        {            
        }


		if( CPKOK_Cnt_M_lgc == FALSE )
		{
			if( (CityParkInputValidCount_Cnt_M_u16 >= k_CityParkInputValidThresh_Cnt_u16) &&
				(SerialComAngleValid_Cnt_T_lgc == TRUE) &&
				(BusOffCh1_Cnt_T_lgc == FALSE) &&
				(BusOffCh1NodeMute_Cnt_T_lgc == FALSE) &&
				(DataOtherFltMsgR_Cnt_T_lgc == FALSE) &&
				(InvalidMsgR_Cnt_T_lgc == FALSE) )
			{
				CPKOK_Cnt_M_lgc = TRUE;
			}
		}
		else
		{
			if( (SerialComAngleValid_Cnt_T_lgc == FALSE) ||
				(CityParkInputInvalidCount_Cnt_M_u16 >= k_CityParkInputInvalidThresh_Cnt_u16) ||
				(BusOffCh1_Cnt_T_lgc == TRUE) ||
				(BusOffCh1NodeMute_Cnt_T_lgc == TRUE) ||
				(DataOtherFltMsgR_Cnt_T_lgc == TRUE) ||
				(InvalidMsgR_Cnt_T_lgc == TRUE) )
			{
				CPKOK_Cnt_M_lgc = FALSE;
			}
		}
		
		/* Demande Relaxe CityPark */
		if ( (DMDRelaxeConsistentCount_Cnt_M_u16 >= k_DMDRelaxeConsistentThresh_Cnt_u16) &&
			 (DMDRELAXECPK_Cnt_M_u08 == (uint8)kDMD_RELAXE_CPK_No_Request) )

		{
			ApaRelaxReq_Cnt_M_lgc = FALSE;
		}
		else
		{
			if(DMDRELAXECPK_Cnt_M_u08 == (uint8)kDMD_RELAXE_CPK_Relaxe_Request)
			{
				ApaRelaxReq_Cnt_M_lgc = TRUE;
			}
		}
		
        /* City Park Authorization */
        if( ((uint8)kETAT_MT_Engine_Running == EtatMT_Cnt_T_u08) &&
            (TRUE == EngOn_Cnt_M_lgc) )
        {
            ApaAuthn_Cnt_T_lgc = TRUE;
        }
        else
        {
            ApaAuthn_Cnt_T_lgc = FALSE;            
        }
        
		/* STTa Determination */
		
		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Node1AAbsent, &Node1AAbsent_Cnt_T_lgc); /* PRQA S 3200 */
		
		if( ( (Node1AAbsent_Cnt_T_lgc == TRUE) ||
			  (InvalidMsgN_Cnt_T_lgc == TRUE) ||
			  (MissingMsgN_Cnt_T_lgc == TRUE) ||
			  (DataRngFltMsgN_Cnt_T_lgc == TRUE) ) &&
			(ValidEngineStatusCount_Cnt_M_u08 < 3u) )
		{
			ValidEngineStatus_Cnt_T_lgc = FALSE;
		}
		else
		{
			ValidEngineStatus_Cnt_T_lgc = TRUE;
		}
		
		
		/* CMM Info Pertinence */
		
		if( Msg348Valid_Cnt_M_lgc == TRUE )
		{
			CMMDataMissing_Cnt_T_lgc = FALSE;
		}
		else
		{
			CMMDataMissing_Cnt_T_lgc = TRUE;
		}
		
		
		/* BSI Info Pertinence */
		
		if( (Msg432Valid_Cnt_M_lgc == TRUE) &&
			(Msg552Valid_Cnt_M_lgc == TRUE) )
		{
			BSIDataMissing_Cnt_T_lgc = FALSE;
		}
		else
		{
			BSIDataMissing_Cnt_T_lgc = TRUE;
		}
		
		
	}
	else
	{
		EngOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CountEtatMT_Cnt_M_u08 = 0u;
		PrevEtatMT_Cnt_M_u08 = (uint8)kETAT_MT_Cut;
		CMMNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CMMNTCsEnabled_Cnt_M_lgc = FALSE;
		CMM388NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CMM388NTCsEnabled_Cnt_M_lgc = FALSE;
		ESPNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ESPNTCsEnabled_Cnt_M_lgc = FALSE;
		BSI412NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BSI412NTCsEnabled_Cnt_M_lgc = FALSE;
		BSI552NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BSI552NTCsEnabled_Cnt_M_lgc = FALSE;
		BSI3F2NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BSI3F2NTCsEnabled_Cnt_M_lgc = FALSE;
		BSI432NTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		BSI432NTCsEnabled_Cnt_M_lgc = FALSE;
		CAVNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CAVNTCsEnabled_Cnt_M_lgc = FALSE;
		AASNTCEnableTimer_mS_M_u32 = SystemTime_mS_T_u32;
		AASNTCsEnabled_Cnt_M_lgc = FALSE;
		ISDATDIRASentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ResetFltAcc(&ISDATDIRASentFltAcc_Cnt_M_u16, k_ISDATDIRASentDiag_Cnt_str, NTC_Num_BusOffCh1NodeMute);
		CMMNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ResetFltAcc(&CMMNodeAbsentFltAcc_Cnt_M_u16, k_CMMNodeAbsentDiag_Cnt_str, NTC_Num_Node1AAbsent);
		ESPNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ResetFltAcc(&ESPNodeAbsentFltAcc_Cnt_M_u16, k_ESPNodeAbsentDiag_Cnt_str, NTC_Num_Node1BAbsent);
		BSINodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ResetFltAcc(&BSINodeAbsentFltAcc_Cnt_M_u16, k_BSINodeAbsentDiag_Cnt_str, NTC_Num_Node1CAbsent);
		CAVNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ResetFltAcc(&CAVNodeAbsentFltAcc_Cnt_M_u16, k_CAVNodeAbsentDiag_Cnt_str, NTC_Num_Node1DAbsent);
		AASNodeAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ResetFltAcc(&AASNodeAbsentFltAcc_Cnt_M_u16, k_AASNodeAbsentDiag_Cnt_str, NTC_Num_Node1EAbsent);
		ISDYNVOLMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNVOLMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNVOLChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNVOLMsgCountInvalidCount_Cnt_M_u16 = 0u;
		ANGLEVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		ANGLEVOLANTSigValidCount_Cnt_M_u16 = 0u;
		VITESSEROTVOLANTSigInvalidCount_Cnt_M_u16 = 0u;
		VITESSEROTVOLANTSigValidCount_Cnt_M_u16 = 0u;
		AngleVolantMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNAASMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNAASMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNAASChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNAASMsgCountInvalidCount_Cnt_M_u16 = 0u;
		CONSANGLECPKSigInvalidCount_Cnt_M_u16 = 0u;
		CONSANGLECPKSigValidCount_Cnt_M_u16 = 0u;
		DMDFCTCPKSigInvalidCount_Cnt_M_u16 = 0u;
		DMDFCTCPKSigValidCount_Cnt_M_u16 = 0u;
		DMDRELAXECPKSigInvalidCount_Cnt_M_u16 = 0u;
		DMDRELAXECPKSigValidCount_Cnt_M_u16 = 0u;
		AngleVolantValidCount_Cnt_M_u16 = 0u;
		AngleVolantInvalidCount_Cnt_M_u16 = 0u;
		CityParkInputMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CityParkInputValidCount_Cnt_M_u16 = 0u;
		CityParkInputInvalidCount_Cnt_M_u16 = 0u;
		CityParkInputConsistentCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNABRMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRChkSumValidCount_Cnt_M_u16 = 0u;
		ISDYNABRChkSumInvalidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgCountValidCount_Cnt_M_u16 = 0u;
		ISDYNABRMsgCountInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehiculeRouesSigValidCount_Cnt_M_u16 = 0u;
		VitesseVehiculeRouesSigInvalidCount_Cnt_M_u16 = 0u;
		CPKVehicleSpeedMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CPKVehicleSpeedValidCount_Cnt_M_u16 = 0u;
		CPKVehicleSpeedInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCMM208MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNCMM208MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNCMM208MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDYNCMM388MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYNCMM388MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYNCMM388MsgLenInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVSigValidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVSigInvalidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVRampValidCount_Cnt_M_u16 = 0u;
		VitesseVehicleBVRampInvalidCount_Cnt_M_u16 = 0u;
		ISDYN2CMMMsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDYN2CMMMsgLenValidCount_Cnt_M_u16 = 0u;
		ISDYN2CMMMsgLenInvalidCount_Cnt_M_u16 = 0u;
		EtatMTSigValidCount_Cnt_M_u16 = 0u;
		EtatMTSigInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI3F2MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		DmdDelestDATimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI3F2MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI3F2MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI412MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI412MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI412MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDATBSI432MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDATBSI432MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDATBSI432MsgLenInvalidCount_Cnt_M_u16 = 0u;
		ISDAT4V2BSI552MsgTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ISDAT4V2BSI552MsgLenValidCount_Cnt_M_u16 = 0u;
		ISDAT4V2BSI552MsgLenInvalidCount_Cnt_M_u16 = 0u;
		CompteurTemporelVehiculeSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
		ComputerRazGCTSigInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
		CompteurTemporelVehiculeSigValidCount_Cnt_M_u16 = 0u;
		ComputerRazGCTSigValidCount_Cnt_M_u16 = 0u;
		DiagMuxOnAbsentTimer_mS_M_u32 = SystemTime_mS_T_u32;
		DateInvalidTimer_mS_M_u32 = SystemTime_mS_T_u32;
        DateValidCount_Cnt_M_u16 = 0u;
        ApaAuthn_Cnt_T_lgc = FALSE;            

		
		SerialComAngleValid_Cnt_T_lgc = FALSE;
		SrlComVehSpd_Kph_T_f32 = ManVehSpd_Kph_M_f32;
		ValidEngineStatus_Cnt_T_lgc = TRUE;
		VehicleSpeedValid_Cnt_M_lgc = TRUE;
		CMMDataMissing_Cnt_T_lgc = FALSE;
		BSIDataMissing_Cnt_T_lgc = FALSE;
		DMDRelaxeConsistentCount_Cnt_M_u16 = 0u;
        CityParkInputConsistentCount_Cnt_M_u16 = 0u;
	}
	
	if( VehicleSpeedValid_Cnt_M_lgc == TRUE )
	{
		CDD_SrlComVehSpd_Kph_G_f32 = SrlComVehSpd_Kph_T_f32;
	}
	else
	{
		CDD_SrlComVehSpd_Kph_G_f32 = 0.0f;
	}

	if( VehSpdControl_Cnt_M_lgc == TRUE )
	{
		SrlComVehSpd_Kph_T_f32 = 0.0f;
		VehicleSpeedValid_Cnt_M_lgc = TRUE;
	}
	
	
	
	PrevISDAT4V2BSI552MsgRxTime_MSec_M_u32 = ISDAT4V2BSI552MsgRxTime_MSec_T_u32;
	PrevISDATBSI3F2MsgRxTime_MSec_M_u32 = ISDATBSI3F2MsgRxTime_MSec_T_u32;
	PrevISDATBSI412MsgRxTime_MSec_M_u32 = ISDATBSI412MsgRxTime_MSec_T_u32;
	PrevISDATBSI432MsgRxTime_MSec_M_u32 = ISDATBSI432MsgRxTime_MSec_T_u32;
	PrevISDYN2CMMMsgRxTime_MSec_M_u32 = ISDYN2CMMMsgRxTime_MSec_T_u32;
	PrevISDYNAASMsgRxTime_MSec_M_u32 = ISDYNAASMsgRxTime_MSec_T_u32;
	PrevISDYNABRMsgRxTime_MSec_M_u32 = ISDYNABRMsgRxTime_MSec_T_u32;
	PrevISDYNCMM208MsgRxTime_MSec_M_u32 = ISDYNCMM208MsgRxTime_MSec_T_u32;
	PrevISDYNCMM388MsgRxTime_MSec_M_u32 = ISDYNCMM388MsgRxTime_MSec_T_u32;
	PrevISDYNVOLMsgRxTime_MSec_M_u32 = ISDYNVOLMsgRxTime_MSec_T_u32;
	PrevISINTEELECTRONBSIMsgRxTime_MSec_M_u32 = ISINTEELECTRONBSIMsgRxTime_MSec_T_u32;
	
	PrevISDAT4V2BSI552MsgDLCError_Cnt_M_u08 = ISDAT4V2BSI552MsgDLCError_Cnt_T_u08;
	PrevISDATBSI3F2MsgDLCError_Cnt_M_u08 = ISDATBSI3F2MsgDLCError_Cnt_T_u08;
	PrevISDATBSI412MsgDLCError_Cnt_M_u08 = ISDATBSI412MsgDLCError_Cnt_T_u08;
	PrevISDATBSI432MsgDLCError_Cnt_M_u08 = ISDATBSI432MsgDLCError_Cnt_T_u08;
	PrevISDYN2CMMMsgDLCError_Cnt_M_u08 = ISDYN2CMMMsgDLCError_Cnt_T_u08;
	PrevISDYNAASMsgDLCError_Cnt_M_u08 = ISDYNAASMsgDLCError_Cnt_T_u08;
	PrevISDYNABRMsgDLCError_Cnt_M_u08 = ISDYNABRMsgDLCError_Cnt_T_u08;
	PrevISDYNCMM208MsgDLCError_Cnt_M_u08 = ISDYNCMM208MsgDLCError_Cnt_T_u08;
	PrevISDYNCMM388MsgDLCError_Cnt_M_u08 = ISDYNCMM388MsgDLCError_Cnt_T_u08;
	PrevISDYNVOLMsgDLCError_Cnt_M_u08 = ISDYNVOLMsgDLCError_Cnt_T_u08;
	
	Rte_IWrite_SrlComInput_Per1_APARequest_Cnt_lgc(APARequest_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per1_ApaRelaxReq_Cnt_lgc(ApaRelaxReq_Cnt_M_lgc);
    Rte_IWrite_SrlComInput_Per1_APAAuthn_Cnt_lgc(ApaAuthn_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per1_AngleVolant_HwDeg_f32(AngleVolant_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per1_BSIDataMissing_Cnt_lgc(BSIDataMissing_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per1_CMMDataMissing_Cnt_lgc(CMMDataMissing_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per1_CONSANGLECPK_Cnt_u16(CONSANGLECPK_Cnt_M_u16);
	Rte_IWrite_SrlComInput_Per1_CPKOK_Cnt_lgc(CPKOK_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per1_DMDFCTCPK_Cnt_u08(DMDFCTCPK_Cnt_M_u08);
	Rte_IWrite_SrlComInput_Per1_ElectronicIntegration_Cnt_lgc(*Rte_Pim_ElecIntData());
	Rte_IWrite_SrlComInput_Per1_EngOn_Cnt_lgc(EngOn_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per1_IgnTimeOff_Cnt_u32(IgnTimeOff_Sec_M_u32);
	Rte_IWrite_SrlComInput_Per1_PosSrvoHwAngle_HwDeg_f32(CONSANGLECPK_HwDeg_M_f32);
	Rte_IWrite_SrlComInput_Per1_ReverseGearEngaged_Cnt_lgc(TRUE);
	Rte_IWrite_SrlComInput_Per1_SerialComAngleValid_Cnt_lgc(SerialComAngleValid_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per1_SrlComVehSpd_Kph_f32(SrlComVehSpd_Kph_T_f32);
	Rte_IWrite_SrlComInput_Per1_ValidEngineStatus_Cnt_lgc(ValidEngineStatus_Cnt_T_lgc);
	Rte_IWrite_SrlComInput_Per1_VehTimeValid_Cnt_lgc(VehTimeValid_Cnt_M_lgc);
	Rte_IWrite_SrlComInput_Per1_VehicleSpeedValid_Cnt_lgc(VehicleSpeedValid_Cnt_M_lgc);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_GetNetworkDiagFltAcc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNetworkDiagFltAcc> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_GetNetworkDiagFltAcc(UInt16 *MuteFltAcc_Cnt_T_u16, UInt16 *CAVNodeFltAcc_Cnt_T_u16, UInt16 *CMMNodeFltAcc_Cnt_T_u16, UInt16 *ESPNodeFltAcc_Cnt_T_u16, UInt16 *AASNodeFltAcc_Cnt_T_u16, UInt16 *BSINodeFltAcc_Cnt_T_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetNetworkDiagFltAcc(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) MuteFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CAVNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CMMNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ESPNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) AASNodeFltAcc_Cnt_T_u16, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) BSINodeFltAcc_Cnt_T_u16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_GetNetworkDiagFltAcc
 *********************************************************************************************************************/
	
	*MuteFltAcc_Cnt_T_u16 = ISDATDIRASentFltAcc_Cnt_M_u16;
	*CAVNodeFltAcc_Cnt_T_u16 = CAVNodeAbsentFltAcc_Cnt_M_u16;
	*CMMNodeFltAcc_Cnt_T_u16 = CMMNodeAbsentFltAcc_Cnt_M_u16;
	*ESPNodeFltAcc_Cnt_T_u16 = ESPNodeAbsentFltAcc_Cnt_M_u16;
	*AASNodeFltAcc_Cnt_T_u16 = AASNodeAbsentFltAcc_Cnt_M_u16;
	*BSINodeFltAcc_Cnt_T_u16 = BSINodeAbsentFltAcc_Cnt_M_u16;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_T_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ManualVehSpd
 *********************************************************************************************************************/
	
	ManVehSpd_Kph_M_f32 = VehSpd_Kph_T_f32;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ResetTimers
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetTimers> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ResetTimers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetTimers(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ResetTimers
 *********************************************************************************************************************/
	
	ResetTimers_Cnt_M_lgc = TRUE;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_VehSpdControl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VehSpdControl> of PortPrototype <SrlComInput_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_VehSpdControl(Boolean Enable_Cnt_T_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_VehSpdControl
 *********************************************************************************************************************/
	
	VehSpdControl_Cnt_M_lgc = Enable_Cnt_T_lgc;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnneeEcoule_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_CompteurTemporelVehicule_Cnt_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(UInt32 *data)
 *   Std_ReturnType Rte_Read_JourEcoule_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_SecondeEcoulee_Cnt_u32(UInt32 *data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_ShutdownTime_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Trns1
 *********************************************************************************************************************/
	
	
	VAR(uint8,   AUTOMATIC) AnneeEcoule_Cnt_T_u08;
	VAR(uint32,  AUTOMATIC) CompteurTemporelVehicule_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) ISDAT4V2BSI552MsgRxTime_MSec_T_u32;
	VAR(uint16,  AUTOMATIC) JourEcoule_Cnt_T_u16;
	VAR(uint32,  AUTOMATIC) SecondeEcoulee_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) InvalidMsgU_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MissingMsgU_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRngFltMsgU_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DataRateFltMsgU_Cnt_T_lgc;
	
	
	Rte_Read_AnneeEcoule_Cnt_u08(&AnneeEcoule_Cnt_T_u08); /* PRQA S 3200 */
	Rte_Read_CompteurTemporelVehicule_Cnt_u32(&CompteurTemporelVehicule_Cnt_T_u32); /* PRQA S 3200 */
	Rte_Read_ISDAT4V2BSI552MsgRxTime_MSec_u32(&ISDAT4V2BSI552MsgRxTime_MSec_T_u32); /* PRQA S 3200 */
	Rte_Read_JourEcoule_Cnt_u16(&JourEcoule_Cnt_T_u16); /* PRQA S 3200 */
	Rte_Read_SecondeEcoulee_Cnt_u32(&SecondeEcoulee_Cnt_T_u32); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_U, &InvalidMsgU_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_U, &MissingMsgU_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_U, &DataRngFltMsgU_Cnt_T_lgc); /* PRQA S 3200 */
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRateFltMsg_U, &DataRateFltMsgU_Cnt_T_lgc); /* PRQA S 3200 */
	
	
	if( k_JDD2010Selected_Cnt_lgc == TRUE )
	{
		if( (CompteurTemporelVehicule_Cnt_T_u32 != D_COMPTEURTEMPORELVEHICULEINVALID_CNT_U32) &&
			(ISDAT4V2BSI552MsgRxTime_MSec_T_u32 > 0ul) &&
			(InvalidMsgU_Cnt_T_lgc == FALSE) &&
			(MissingMsgU_Cnt_T_lgc == FALSE) &&
			(DataRngFltMsgU_Cnt_T_lgc == FALSE) &&
			(DataRateFltMsgU_Cnt_T_lgc == FALSE) )
		{
			(Rte_Pim_ShutdownTimeData())->Time_Sec_u32 = CompteurTemporelVehicule_Cnt_T_u32 / D_COMPTEURTEMPORELVEHICULESCALE_SECPCNT_U32;
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = TRUE;
		}
		else
		{
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = FALSE;
		}
	}
	else
	{
		if( (AnneeEcoule_Cnt_T_u08 != D_ANNEEECOULEINVALID_CNT_U08) &&
			(JourEcoule_Cnt_T_u16 != D_JOURECOULEINVALID_CNT_U16) &&
			(SecondeEcoulee_Cnt_T_u32 != D_SECONDEECOULEEINVALID_CNT_U32) &&
			(ISDAT4V2BSI552MsgRxTime_MSec_T_u32 > 0ul) &&
			(InvalidMsgU_Cnt_T_lgc == FALSE) &&
			(MissingMsgU_Cnt_T_lgc == FALSE) )
		{
			(Rte_Pim_ShutdownTimeData())->Time_Sec_u32 = (((uint32)AnneeEcoule_Cnt_T_u08) * D_SECONDSPERYEAR_CNT_U32) +
														 (((uint32)JourEcoule_Cnt_T_u16) * D_SECONDSPERDAY_CNT_U32) +
														 SecondeEcoulee_Cnt_T_u32;
			
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = TRUE;
		}
		else
		{
			(Rte_Pim_ShutdownTimeData())->Valid_Cnt_lgc = FALSE;
		}
	}
	
	Rte_Call_ShutdownTime_WriteBlock(NULL_PTR); /* PRQA S 3200 */
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) NodeAbsentNTCProcessing( VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgTimer_mS_T_u32,
																P2VAR(uint16, AUTOMATIC, AUTOMATIC) FltAcc_Cnt_T_u16,
																VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																VAR(DiagSettings_Str, AUTOMATIC) MsgDiag_Cnt_T_str,
																VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	
	if( PrevMsgRxTime_MSec_T_u32 != MsgRxTime_MSec_T_u32 )
	{
		*MsgTimer_mS_T_u32 = MsgRxTime_MSec_T_u32;
		*FltAcc_Cnt_T_u16 = DiagNStep_m(*FltAcc_Cnt_T_u16, MsgDiag_Cnt_T_str);
		if( *FltAcc_Cnt_T_u16 == 0u )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		}
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*MsgTimer_mS_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		if( ElapsedTime_mS_T_u16 >= Timeout_mS_T_u16 )
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(MsgTimer_mS_T_u32); /* PRQA S 3200 */
			*FltAcc_Cnt_T_u16 = DiagPStep_m(*FltAcc_Cnt_T_u16, MsgDiag_Cnt_T_str);
			if( DiagFailed_m(*FltAcc_Cnt_T_u16, MsgDiag_Cnt_T_str) == TRUE )
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED); /* PRQA S 3200 */
			}
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MissingMessageNTCProcessing( VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgTimer_mS_T_u32,
																	P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	
	if( PrevMsgRxTime_MSec_T_u32 != MsgRxTime_MSec_T_u32 )
	{
		*MsgTimer_mS_T_u32 = MsgRxTime_MSec_T_u32;
		
		*ValidCount_Cnt_T_u16 = IncToThresh(*ValidCount_Cnt_T_u16, ValidThresh_Cnt_T_u16);
		
		if( *ValidCount_Cnt_T_u16 >= ValidThresh_Cnt_T_u16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		}
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*MsgTimer_mS_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		
		if( ElapsedTime_mS_T_u16 >= Timeout_mS_T_u16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED); /* PRQA S 3200 */
			Rte_Call_SystemTime_GetSystemTime_mS_u32(MsgTimer_mS_T_u32); /* PRQA S 3200 */
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ValidityNTCProcessing( VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
															  P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
															  P2VAR(uint16, AUTOMATIC, AUTOMATIC) InvalidCount_Cnt_T_u16,
															  VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
															  VAR(uint16, AUTOMATIC) InvalidThresh_Cnt_T_u16,
															  VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	if( TestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
	{
		*InvalidCount_Cnt_T_u16 = 0u;
		
		*ValidCount_Cnt_T_u16 = IncToThresh(*ValidCount_Cnt_T_u16, ValidThresh_Cnt_T_u16);
		
		if( *ValidCount_Cnt_T_u16 >= ValidThresh_Cnt_T_u16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
		}
	}
    else if ( TestStatus_Cnt_T_u08 == D_TESTDEADBAND_CNT_U08 )
    {
        *InvalidCount_Cnt_T_u16 = 0u;
		
		*ValidCount_Cnt_T_u16 = 0u;				
    }
	else
	{
		*ValidCount_Cnt_T_u16 = 0u;
		
		*InvalidCount_Cnt_T_u16 = IncToThresh(*InvalidCount_Cnt_T_u16, InvalidThresh_Cnt_T_u16);
		
		if( *InvalidCount_Cnt_T_u16 >= InvalidThresh_Cnt_T_u16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED); /* PRQA S 3200 */
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) MixedTimeValidityNTCProcessing( VAR(uint8, AUTOMATIC) TestStatus_Cnt_T_u08,
																	   VAR(uint32, AUTOMATIC) MsgRxTime_MSec_T_u32,
																	   VAR(uint32, AUTOMATIC) PrevMsgRxTime_MSec_T_u32,
																	   P2VAR(uint32, AUTOMATIC, AUTOMATIC) SigTimer_mS_T_u32,
																	   P2VAR(uint16, AUTOMATIC, AUTOMATIC) ValidCount_Cnt_T_u16,
																	   VAR(uint16, AUTOMATIC) Timeout_mS_T_u16,
																	   VAR(uint16, AUTOMATIC) ValidThresh_Cnt_T_u16,
																	   VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	
	if( TestStatus_Cnt_T_u08 == D_TESTPASSED_CNT_U08 )
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(SigTimer_mS_T_u32); /* PRQA S 3200 */
		if( MsgRxTime_MSec_T_u32 != PrevMsgRxTime_MSec_T_u32 )
		{
			*ValidCount_Cnt_T_u16 = IncToThresh(*ValidCount_Cnt_T_u16, ValidThresh_Cnt_T_u16);
			
			if( *ValidCount_Cnt_T_u16 >= ValidThresh_Cnt_T_u16 )
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_PASSED); /* PRQA S 3200 */
			}
		}
	}
	else
	{
		*ValidCount_Cnt_T_u16 = 0u;
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*SigTimer_mS_T_u32, &ElapsedTime_mS_T_u16); /* PRQA S 3200 */
		if( ElapsedTime_mS_T_u16 >= Timeout_mS_T_u16 )
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0u, NTC_STATUS_FAILED); /* PRQA S 3200 */
		}
	}
}


STATIC FUNC(void, AP_SRLCOMINPUT_CODE) ResetFltAcc( P2VAR(uint16, AUTOMATIC, AUTOMATIC) FltAcc_Cnt_T_u16,
													VAR(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
													VAR(NTCNumber, AUTOMATIC) NTCNum_Cnt_T_u16 )
{
	VAR(boolean, AUTOMATIC) NTCFailed_Cnt_T_lgc;
	
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNum_Cnt_T_u16, &NTCFailed_Cnt_T_lgc); /* PRQA S 3200 */
	
	if( NTCFailed_Cnt_T_lgc == TRUE )
	{
		*FltAcc_Cnt_T_u16 = DiagSettings_Cnt_T_str.Threshold;
	}
	else
	{
		*FltAcc_Cnt_T_u16 = 0u;
	}
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
