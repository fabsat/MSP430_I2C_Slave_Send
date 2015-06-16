#include <msp430.h> 
#include "TI_USCI_I2C_slave.h"

void receive_cb(unsigned char receive);
void transmit_cb(unsigned char volatile *receive);
void start_cb();
unsigned char TXData = 0 ;
unsigned char  RXData = 0 ;
unsigned char flag = 0;

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	/* �E�H�b�`�h�b�O�^�C�}�𖳌� */
	TI_USCI_I2C_slaveinit(start_cb, transmit_cb, receive_cb, 0x50); /* �X���[�u�Ƃ��ď����� */
	_EINT();					/* ���荞�ݗL�� */
	BCSCTL1 = CALBC1_16MHZ;
	DCOCTL = CALDCO_16MHZ;
	LPM0;						/* �����d�̓��[�hLPM0�ɐݒ� */
}

void start_cb(){
    RXData = 0;
    flag = 0;
}

void receive_cb(unsigned char receive){
    RXData = receive;
}

/* ���o�C�g���M���͈ȉ��̃R�[���o�b�N�֐���������Ăяo����� */
void transmit_cb(unsigned char volatile *byte){
    if (flag == 0) TXData = 0x04;    /* ��ʃo�C�g���M���ۂ� */
    else TXData = 0xD2;
    flag = ~flag;

    *byte = TXData;
}

