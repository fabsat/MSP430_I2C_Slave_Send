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
    WDTCTL = WDTPW | WDTHOLD;	/* ウォッチドッグタイマを無効 */
	TI_USCI_I2C_slaveinit(start_cb, transmit_cb, receive_cb, 0x50); /* スレーブとして初期化 */
	_EINT();					/* 割り込み有効 */
	BCSCTL1 = CALBC1_16MHZ;
	DCOCTL = CALDCO_16MHZ;
	LPM0;						/* 低消費電力モードLPM0に設定 */
}

void start_cb(){
    RXData = 0;
    flag = 0;
}

void receive_cb(unsigned char receive){
    RXData = receive;
}

/* 多バイト送信時は以下のコールバック関数が複数回呼び出される */
void transmit_cb(unsigned char volatile *byte){
    if (flag == 0) TXData = 0x04;    /* 上位バイト送信か否か */
    else TXData = 0xD2;
    flag = ~flag;

    *byte = TXData;
}

