#include <io.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <memory.h>
#include <math.h>   
#include <iostream.h>
#include <windows.h>


#ifndef _MYCRYPTOGRAM_
#define _MYCRYPTOGRAM_

#ifdef _MYCRY
extern "C"
{
#endif
//=========================================================================================================
//DES相关函数
	void	myDES_IniPermutation	( BYTE *	data1 , BYTE *	data2 , BYTE function ) ;
	void	myDES_ProduceKey		( BYTE * Key , BYTE KeyN[16][8] ) ;
	void	myDES_myChange		( BYTE thestr[8] , BYTE newstr[8] ) ;
	void	myDES_expand			( BYTE data32[4] , BYTE data48[8] )	;
	void	myDES_myF				( BYTE data[4] , BYTE newdata[4] , BYTE theKey[8] ) ;
	BYTE	myDES_myboxS			( BYTE data6 , BYTE No ) ;

	void	myDES_encrypt64		( BYTE message[8] , BYTE Key[8] , BYTE code[8] ) ; 
	void	myDES_decrypt64		( BYTE code[8] , BYTE Key[8] , BYTE message[8] ) ;

	void	myDES_encrypt64_allKey( BYTE message[8] , BYTE KeyN[16][8] , BYTE code[8] ) ; 
	void	myDES_decrypt64_allKey( BYTE code[8] , BYTE KeyN[16][8] , BYTE message[8] ) ;

	void	myDES_MYencrypt		( BYTE * message , BYTE Key[8] , int Lenmessage , BYTE code[8] )  ;
	void	myDES_MYdecrypt		( BYTE * code , BYTE Key[8] , int Lencode , BYTE * message ) ;
	void	myDES_Rijndael_allKey( BYTE	State[4][4] ,	DWORD	RKey[44]	);
	void	myDES_EqInvRijndael_allKey( BYTE	State[4][4] ,	DWORD	RKey[44]	);

//=========================================================================================================
//ASE相关函数
	BYTE	myAES_FieldMult		( BYTE	a	, BYTE	b );				//在有限域上的变量乘法 a*b
	void	myAES_printInvField();									//制作F2^8上的逆元素表
	BYTE	myAES_SubByte_byte	( BYTE	a );							//单字节代替

	BYTE	myAES_InvSubByte_byte	( BYTE	a );							//单字节代替的逆变换
	void	myAES_DataToState	( BYTE	Data[16]	,	BYTE	State[4][4] ) ;
	void	myAES_StateToData	( BYTE	State[4][4] ,	BYTE	Data[16]	) ;
		
	void	myAES_SubByte		( BYTE	State[4][4] ) ;		//字节代替变换
	void	myAES_ShiftRow	( BYTE	State[4][4] ) ;		//行移位变换
	void	myAES_MixColumn	( BYTE	State[4][4] ) ;		//列混合变换
	void	myAES_KeyExpansion( BYTE	Key[16]	, DWORD	RKey[44] ) ;	//密钥扩展算法
	void	myAES_AddRoundKey	( BYTE	State[4][4] ,	DWORD	RKey[4] ); //加轮密钥
	void	myAES_Round		( BYTE	State[4][4] ,	DWORD	RKey[4] ); //轮变换
	void	myAES_FinalRound	( BYTE	State[4][4] ,	DWORD	RKey[4] ); //最后一轮轮变换
	void	myAES_Rijndael	( BYTE	State[4][4] ,	BYTE	Key[16]	); //加密运算!!!


	void	myAES_InvSubByte	( BYTE	State[4][4] ) ;	//字节代替逆变换
	void	myAES_InvShiftRow	( BYTE	State[4][4] ) ;	//行移位逆变换
	void	myAES_InvMixColumn( BYTE	State[4][4] ) ;		//列混合逆变换
	void	myAES_InvRound	( BYTE	State[4][4] ,	DWORD	RKey[4] ); //轮逆变换
	void	myAES_InvFinalRound	( BYTE	State[4][4] ,	DWORD	RKey[4] );//最后一轮轮逆变换
	void	myAES_InvKeyExpansion( BYTE	Key[16]	, DWORD	RKey[44] ) ;	//解密用密钥扩展算法
	void	myAES_EqInvRijndael	( BYTE	State[4][4] ,	BYTE	Key[16]	); //解密运算!!!
//=========================================================================================================
//MD4相关函数
	void myMD4_SubHASH(DWORD InputData[16],DWORD HashValue[4]);
	void myMD4_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[4] );
	void myMD4_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[32] );
//=========================================================================================================
//MD5相关函数
	void myMD5_SubHASH(DWORD InputData[16],DWORD HashValue[4]);
	void myMD5_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[4] );
	void myMD5_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[32] );
//=========================================================================================================
//SHA1相关函数
	void mySHA1_SubHASH(DWORD InputData[16],DWORD HashValue[5]);
	void mySHA1_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[5] );
	void mySHA1_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[40] );
//=========================================================================================================
//SHA224相关函数
	void mySHA224_SubHASH(DWORD InputData[16],DWORD HashValue[8]);
	void mySHA224_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[7] );
	void mySHA224_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[56] );
//=========================================================================================================
//SHA256相关函数
	void mySHA256_SubHASH(DWORD InputData[16],DWORD HashValue[8]);
	void mySHA256_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[8] );
	void mySHA256_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[64] );
//=========================================================================================================
//SHA384相关函数
	void mySHA384_SubHASH(unsigned _int64 InputData[16],unsigned _int64 HashValue[8]);
	void mySHA384_Run( BYTE *InStr , unsigned _int64 LenData ,  unsigned _int64 OutInt[6] );
	void mySHA384_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[96] );
//=========================================================================================================
//SHA512相关函数
	void mySHA512_SubHASH(unsigned _int64 InputData[16],unsigned _int64 HashValue[8]);
	void mySHA512_Run( BYTE *InStr , unsigned _int64 LenData ,  unsigned _int64 OutInt[8] );
	void mySHA512_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[128] );
//=========================================================================================================
//RIPEMD128相关函数
	void myRIPEMD128_SubHASH(DWORD InputData[16],DWORD HashValue[4]);
	void myRIPEMD128_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[4] );
	void myRIPEMD128_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[32] );
//=========================================================================================================
//RIPEMD160相关函数
	void myRIPEMD160_SubHASH(DWORD InputData[16],DWORD HashValue[5]);
	void myRIPEMD160_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[5] );
	void myRIPEMD160_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[40] );
//=========================================================================================================
//RIPEMD256相关函数
	void myRIPEMD256_SubHASH(DWORD InputData[16],DWORD HashValue[8]);
	void myRIPEMD256_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[8] );
	void myRIPEMD256_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[64] );
//=========================================================================================================
//RIPEMD320相关函数
	void myRIPEMD320_SubHASH(DWORD InputData[16],DWORD HashValue[10]);
	void myRIPEMD320_Run( BYTE *InStr , unsigned _int64 LenData ,  DWORD OutInt[10] );
	void myRIPEMD320_RunStr( BYTE *InStr , unsigned _int64 LenData ,  char OutPutStr[80] );



#ifdef _MYCRY
}
#endif

#endif