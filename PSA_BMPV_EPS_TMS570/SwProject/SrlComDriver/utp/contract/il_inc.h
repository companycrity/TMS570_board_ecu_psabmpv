
#ifndef IL_INC_H
#define IL_INC_H

#define kEFFAC_DEFAULT_DIAG_Default_Memory_Erase 1
#define CanRxIS_DAT4_V2_BSI_552              0
#define CanRxIS_DAT_BSI_432                  1
#define CanRxIS_DAT_BSI_412                  2
#define CanRxIS_DAT_BSI_3F2                  3
#define CanRxIS_DYN_CMM_388                  4
#define CanRxIS_DYN2_CMM_348                 5
#define CanRxIS_DYN_CMM_208                  6
#define CanRxIS_DYN_ABR                      12
#define CanRxIS_DYN_VOL                      13
#define CanRxIS_DYN_AAS                      14
#define kCanInitObj1                         0
# define kCanNoCopyData                      ((vuint8)0x00)
# define kCanCopyData                        ((vuint8)0x01)
# define CanRxActualDLC(rxStruct)            ((*(rxStruct->pChipMsgObj+5)) & 0x000F)
# define CanResetBusOffEnd(a)

typedef uint8              vuint8;
typedef uint16             vuint16;
typedef uint32             vuint32;
typedef unsigned int       vbittype;

typedef vuint16            CanInitHandle;
typedef vuint16            CanChannelHandle;
typedef volatile vuint8 *  CanChipMsgPtr;
typedef volatile vuint8 *  CanChipDataPtr;
typedef vuint16            CanReceiveHandle;
typedef vuint16            CanTransmitHandle;

typedef struct 
{
  CanChannelHandle  Channel;
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanReceiveHandle  Handle;
/* CPU-specific part */
} tCanRxInfoStruct;

typedef tCanRxInfoStruct * CanRxInfoStructPtr;

typedef struct 
{
  CanChipDataPtr     pChipData;
  CanTransmitHandle  Handle;
/* CPU-specific part */
} tCanTxInfoStruct;

typedef tCanTxInfoStruct   CanTxInfoStruct;

typedef struct _c_IS_DYN_DAE_msgTypeTag
{
  vbittype CHKSUM_TRME_DYN_DAE : 4;
  vbittype CPT_PROCESS_4B_DAE : 4;
  vbittype CPLE_VOLANT_OPTMSE : 8;
  vbittype unused0 : 1;
  vbittype ETAT_DAE_CPK : 2;
  vbittype CAUSE_DESACTIV_CPK : 3;
  vbittype unused1 : 2;
  vbittype ANGLE_COLONNE_1 : 8;
  vbittype ANGLE_COLONNE_0 : 8;
  vbittype VITESSE_COLONNE_1 : 8;
  vbittype VITESSE_COLONNE_0 : 4;
  vbittype unused2 : 3;
  vbittype ETAT_SECU_ANGLE_COL : 1;
} _c_IS_DYN_DAE_msgType;

typedef union _c_IS_DYN_DAE_bufTag
{
  vuint8 _c[7];
  _c_IS_DYN_DAE_msgType IS_DYN_DAE;
} _c_IS_DYN_DAE_buf;

extern _c_IS_DYN_DAE_buf IS_DYN_DAE;

extern void CanTask(void);
extern void IlRxTask(void);
extern void IlTxTask(void);
extern void IlRxStart(void);
extern void IlTxStart(void);
extern void IlTxStop(void);
extern uint8 IlGetRxLXA_ACTIVATION(void);
extern uint8 IlGetRxLKA_STATE(void);
extern uint8 IlGetRxLKA_TRQ_FACT_REQ(void);
extern uint8 IlGetRxMsg552_Byte0(void);
extern uint8 IlGetRxMsg552_Byte1(void);
extern uint8 IlGetRxMsg552_Byte2(void);
extern uint8 IlGetRxMsg552_Byte3(void);
extern uint8 IlGetRxMsg552_Byte4(void);
extern uint8 IlGetRxMsg552_Byte5(void);
extern uint8 IlGetRxMsg552_Byte6(void);
extern uint8 IlGetRxMsg552_Byte7(void);
extern uint8 IlGetRxETAT_PRINCIP_SEV(void);
extern uint8 IlGetRxPower_Supplies(void);
extern uint8 IlGetRxShunt_Position(void);
extern uint8 IlGetRxETAT_RESEAU_ELEC(void);
extern uint8 IlGetRxMARCHE_AR_BVM(void);
extern uint8 IlGetRxDMD_DELEST_DA(void);
extern uint8 IlGetRxETAT_MT(void);
extern uint8 IlGetRxDIAG_MUX_ON(void);
extern uint8 IlGetRxEFFAC_DEFAULT_DIAG(void);
extern uint8 IlGetRxMODE_DIAG(void);
extern uint8 IlGetRxDIAG_INTEGRA_ELEC(void);
extern uint16 IlGetRxVITESSE_VEHICLE_BV(void);
extern uint16 IlGetRxCOLUMN_ANGLE_SETPOINT(void);
extern void IlPutTxSystem_Code(vuint8 sigData);
extern void IlPutTxDownload_Day(vuint8 sigData);
extern void IlPutTxDownload_Month(vuint8 sigData);
extern void IlPutTxDownload_Year(vuint8 sigData);
extern void IlPutTxApplication_Code(vuint8 sigData);
extern void IlPutTxSoftware_Version(vuint8 sigData);
extern void IlPutTxSoftware_Edition_MSB(vuint8 sigData);
extern void IlPutTxSoftware_Edition_LSB(vuint8 sigData);
extern void IlPutTxCODE_DEFAUT(vuint8 sigData);
extern void IlPutTxSTATUS_CONFABSENT(vuint32 sigData);
extern void IlPutTxETAT_ASSIST_DA(vuint8 sigData);
extern void IlPutTxETAT_LIGNE_APC(vuint8 sigData);
extern void IlPutTxANGLE_COLONNE(vuint16 sigData);
extern void IlPutTxVITESSE_COLONNE(vuint16 sigData);
extern void IlPutTxCPLE_VOLANT(vuint8 sigData);
extern void IlPutTxETAT_DA_DYN(vuint8 sigData);
extern void IlPutTxETAT_DA_2004(vuint8 sigData);
extern void IlPutTxETAT_DA_2010(vuint8 sigData);
extern void IlPutTxAUTOR_ARRET_MOT_DA(vuint8 sigData);
extern void IlPutTxDDE_REDEM_DA(vuint8 sigData);
extern void IlPutTxCPT_PROCESS_4B_DAE(vuint8 sigData);
extern void IlPutTxCHKSUM_TRME_DYN_DAE(vuint8 sigData);
extern void IlPutTxCPLE_VOLANT_OPTMSE(vuint8 sigData);
extern void IlPutTxCAUSE_DESACTIV_CPK(vuint8 sigData);
extern void IlPutTxETAT_DAE_CPK(vuint8 sigData);
extern void IlPutTxETAT_SECU_ANGLE_COL(vuint8 sigData);

extern vuint8 SrlComDriver_PreRxISDATBSI(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreTxISDATDIRA(CanTxInfoStruct ctis);
extern vuint8 SrlComDriver_PreTxISDYNDAE(CanTxInfoStruct ctis);
extern vuint8 SrlComDriver_PreRxISDAT4V2BSI552(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxISDYNAAS(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxISDYNABR(CanRxInfoStructPtr rxStruct);
extern vuint8 SrlComDriver_PreRxISDYNVOL(CanRxInfoStructPtr rxStruct);
extern void SrlComDriver_TxISDATDIRA(CanTransmitHandle txObject);
extern void SrlComDriver_TxISDYNDAE(CanTransmitHandle txObject);
extern void SrlComDriver_RxISDATBSI432(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDATBSI412(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDATBSI3F2(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYNCMM388(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYN2CMM(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISDYNCMM208(CanReceiveHandle rcvObject);
extern void SrlComDriver_RxISINTEELECTRONBSI(CanReceiveHandle rcvObject);
extern void CanStart(void);
extern void CanStop(void);
extern void CanOnline(void);
extern void CanOffline(void);
extern void ApplCanBusOff(void);
extern void ApplCanMsgDlcFailed( CanRxInfoStructPtr rxStruct );
extern void CanResetBusOffStart( CanInitHandle initObject );

#endif
