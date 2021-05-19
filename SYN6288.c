#include "syn6288.h"
#include "stdio.h"
/***********************************************************
* ��    �ƣ� YS-SYN6288 �ı��ϳɺ���
UART_WORDLENGTH_8B!!��������Ϊ8λ
UART_PARITY_NONE    ��У��λ
SYN6288����ģ��
**********************************************************/

void SYN_FrameInfo(void)
{
  uint8_t   Voice[] ="�Ҳ�����Ƭ��";
	unsigned  char  HZ_Length=sizeof(Voice);//������sizeof��
	unsigned  char  ecc  = 0;  			//����У���ֽ�
	unsigned  int i=0; 
	unsigned  char  Frame_Info[5]={0xfd,0x00,10+3,0x01,0x00}; 
   Frame_Info[2]=3+HZ_Length;//������������
	/*******************У�������***************************************/		 
	for(i = 0; i<5; i++)   			//���η��͹���õ�5��֡ͷ�ֽ�
	{  
		ecc=ecc^(Frame_Info[i]);		//���У��	
	}
	
	for(i= 0; i<HZ_Length; i++)   		//���η��ʹ��ϳɵ��ı�����
	{  
		ecc=ecc^(Voice[i]); 				//���У��		
	}
	//�����ڽ����ô��ڣ���HAL���ȷ���5�����ٷ������֣��ٸ���ecc(У��λ)
	 HAL_UART_Transmit(&UartHandle, (uint8_t *)Frame_Info,5, 0xFFFF);
   HAL_UART_Transmit(&UartHandle,                 Voice, HZ_Length, 0xFFFF);
	 HAL_UART_Transmit(&UartHandle, (uint8_t *)&ecc,1, 0xFFFF);
}
void SYN_FrameInfo2(void)
{
/****************��Ҫ���͵��ı�**********************************/
  uint8_t   Voice[] ="����";
	unsigned  char  HZ_Length=sizeof(Voice);
	unsigned  char  ecc  = 0;  			//����У���ֽ�
	unsigned  int i=0; 
	unsigned  char  Frame_Info[5]={0xfd,0x00,10+3,0x01,0x00};         
  Frame_Info[2]=3+HZ_Length;
	/*******************У�������***************************************/		 
	for(i = 0; i<5; i++)   			//���η��͹���õ�5��֡ͷ�ֽ�
	{  
		ecc=ecc^(Frame_Info[i]);		//�Է��͵��ֽڽ������У��	
	}
	
	for(i= 0; i<HZ_Length; i++)   		//���η��ʹ��ϳɵ��ı�����
	{  
		ecc=ecc^(Voice[i]); 				//�Է��͵��ֽڽ������У��		
	}
	 //�����ڽ����ô��ڣ���
	 HAL_UART_Transmit(&UartHandle, (uint8_t *)Frame_Info,5, 0xFFFF);
   HAL_UART_Transmit(&UartHandle,                 Voice, HZ_Length, 0xFFFF);
	 HAL_UART_Transmit(&UartHandle, (uint8_t *)&ecc,1, 0xFFFF);
}



