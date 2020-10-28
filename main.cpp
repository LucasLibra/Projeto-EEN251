/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
#include <string.h>
#include <stdio.h>



// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    50

DigitalOut led(LED1);
PwmOut rodaEsquerda_1(p25);
PwmOut rodaEsquerda_2(p26);

PwmOut rodaDireita_1(p23);
PwmOut rodaDireita_2(p24);

PwmOut motoBomba_1(p21);
PwmOut motoBomba_2(p22);

AnalogIn sensorProfundidade (p15);
Serial bt(p13,p14); //TX, RX
Serial pc(USBTX, USBRX);


int main()
{
    char ch;
    pc.baud(115200);
    bt.baud(9600);
   
    
    char left = 'L';
    char right = 'R';
    char forward = 'F';
    char back = 'B';
    char stop = 'S';
    char squirt = 'Q';

    
    
    float nivelAgua = 0;
    
    while(1)
    {
        
        nivelAgua = (1-sensorProfundidade.read())*100;
        
        if(bt.readable())
        {
            ch=bt.getc();

            pc.printf("%c",ch);
            bt.printf("%c",ch);
            
            if(ch == forward){
                rodaEsquerda_1 = 0.5;
                rodaEsquerda_2 = 0;
                rodaDireita_1 = 0.5;
                rodaDireita_2 = 0;
            }
            else if(ch == back){
                rodaEsquerda_1 = 0;
                rodaEsquerda_2 = 0.5;
                rodaDireita_1 = 0;
                rodaDireita_2 = 0.5;
            }
            else if(ch == right){
                rodaEsquerda_1 = 0.25;
                rodaEsquerda_2 = 0;
                rodaDireita_1 = 0;
                rodaDireita_2 = 0.25;
            }
            else if(ch == left){
                rodaEsquerda_1 = 0;
                rodaEsquerda_2 = 0.25;
                rodaDireita_1 = 0.25;
                rodaDireita_2 = 0;
            }
            else if(ch == stop){
                rodaEsquerda_1 = 0;
                rodaEsquerda_2 = 0;
                rodaDireita_1 = 0;
                rodaDireita_2 = 0;
            }
            else if(ch == squirt){
                rodaEsquerda_1 = 0;
                rodaEsquerda_2 = 0;
                rodaDireita_1 = 0;
                rodaDireita_2 = 0;
                
                motoBomba_1 = 1;
                motoBomba_2 = 0;
                thread_sleep_for(5000);
                motoBomba_1 = 0;
                motoBomba_2 = 0;
            }
            
        }
        
        else if(pc.readable())
        {
            ch=pc.getc();
            bt.printf("%c",ch);
            pc.printf("%c",ch); 
        }
        
        //bt.printf("%.2f %%", nivelAgua);
        //pc.printf("%.2f %%", nivelAgua);
        //bt.printf("\n");
        //pc.printf("\n");
    }
}
