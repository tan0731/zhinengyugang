#include "key.h"
#include "delay.h"	 
 	   
		 
void KEY_IO_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
 	
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15;				 //�̵������ �˿�����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
   GPIO_Init(GPIOB, &GPIO_InitStructure);	
}

void fengmingqi_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTA,PORTCʱ��

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				//PORTA0 �������
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
} 
void BEEP_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_10);	 // turn off all led
	GPIO_ResetBits(GPIOB, GPIO_Pin_11);	 // turn off all led
	
}
void RELAY_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
 	
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PB,PA�˿�ʱ��
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//GPIO���ù���ʱ��ʹ��
   GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); //��A15,B3,B4��Щ�������ó���ͨIO��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 //�̵������ �˿�����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	 GPIO_ResetBits(GPIOA,GPIO_Pin_15); 						
}



