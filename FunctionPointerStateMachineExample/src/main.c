///
/// \file 				main.c
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-04-15
/// \last-modified		2018-03-19
/// \brief 				Contains the main entry point to the state machine example.
/// \details
///		See README.md in root dir for more info.

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "StateMachine.h"

int input;

void nhap(){
    printf("nhap: ");
    scanf("%d",&input);
}
// Create new state machine object
        stateMachine_t stateMachine;

void case_1(){
    StateMachine_Init(&stateMachine);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        //sleep(1);

        // Push button to start flasher
        printf("Even -> Button pushed.\r\n");
        StateMachine_RunIteration(&stateMachine, EV_BUTTON_PUSHED);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        //sleep(1);
        // Scan QR code
        printf("Even -> Scan QR code.\r\n");
        StateMachine_RunIteration(&stateMachine, EV_SCAN_QR);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        //sleep(1);
        
        printf("Even -> check wifi\n");
        StateMachine_RunIteration(&stateMachine, EV_WIFI_SUCCESSFUL);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);

        printf("Even -> Call API\n");
        StateMachine_RunIteration(&stateMachine, EV_CALL_API);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);

        printf("Even -> Publish register successful\n");
        StateMachine_RunIteration(&stateMachine, EV_PUBLISH_REGISTER_SUCCESSFUL);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);      

        StateMachine_RunIteration(&stateMachine, EV_NONE);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);  
}
void case_2(){
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        sleep(1);

        // Push button to start flasher
        printf("Even -> Button pushed.\r\n");
        StateMachine_RunIteration(&stateMachine, EV_BUTTON_PUSHED);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        sleep(1);
        // Scan QR code
        printf("Even -> Scan QR code.\r\n");
        StateMachine_RunIteration(&stateMachine, EV_SCAN_QR);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        sleep(1);

        //SSID, PW FALSE
        printf("Even -> wifi fail.\r\n");
        StateMachine_RunIteration(&stateMachine, EV_WIFI_FAIL);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

        printf("Even -> Scan QR code.\r\n");
        StateMachine_RunIteration(&stateMachine, EV_SCAN_QR);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        sleep(1);

        printf("Even -> check wifi\n");
        StateMachine_RunIteration(&stateMachine, EV_WIFI_SUCCESSFUL);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);

        printf("Even -> Call API\n");
        StateMachine_RunIteration(&stateMachine, EV_CALL_API);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);

        printf("Even -> Publish register successful\n");
        StateMachine_RunIteration(&stateMachine, EV_PUBLISH_REGISTER_SUCCESSFUL);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1);      

        StateMachine_RunIteration(&stateMachine, EV_NONE);
        printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));
        // //sleep(1); 
}
int main() {
   // printf("main() called.\r\n");
    while(1){
    nhap();
    

    switch(input){
        case 1: case_1();
        break;
        case 2: case_2();
        break;
    }
        
        
    }
    return 0;
}