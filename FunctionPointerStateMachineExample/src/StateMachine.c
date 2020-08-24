///
/// \file 				StateMachine.c
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-04-15
/// \last-modified		2018-03-19
/// \brief 				Contains the StateMachine module.
/// \details
///		See README.md in root dir for more info.

// System includes
#include <stdio.h>

// Local includes
#include "Led.h"
#include "main.h"
#include "StateMachine.h"
#include <unistd.h>

typedef struct {
    const char * name;
    void (*func)(void);
} stateFunctionRow_t;

/// \brief  Maps a state to it's state transition function, which should be called
///         when the state transitions into this state.
/// \warning    This has to stay in sync with the state_t enum!
static stateFunctionRow_t stateFunctionA[] = {
      // NAME                   // FUNC
    { "ST_CAMERA_IDLE",      &camera_idle },      // ST_error
    { "ST_CAMERA_STARTING",  &starting },        // ST_start
    { "ST_CAMERA_CONNECTING",       &connecting },
    { "ST_CAMERA_REGISTERING", &registering},
    { "ST_CAMERA_PUBLISH", &API},
    { "ST_CAMERA_SUCCESSFUL", &done},

};

typedef struct {
    state_t currState;
    event_t event;
    state_t nextState;
} stateTransMatrixRow_t;

static stateTransMatrixRow_t stateTransMatrix[] = {
    // CURR STATE           // EVENT              // NEXT STATE
    { ST_CAMERA_IDLE,     EV_BUTTON_PUSHED,     ST_CAMERA_STARTING  }, //start
    { ST_CAMERA_STARTING,   EV_SCAN_QR,          ST_CAMERA_CONNECTING },//connect
    { ST_CAMERA_CONNECTING,   EV_WIFI_SUCCESSFUL, ST_CAMERA_REGISTERING },//register
    { ST_CAMERA_REGISTERING, EV_CALL_API, ST_CAMERA_PUBLISH},
    { ST_CAMERA_PUBLISH, EV_PUBLISH_REGISTER_SUCCESSFUL, ST_CAMERA_SUCCESSFUL},
    { ST_CAMERA_SUCCESSFUL, EV_NONE, ST_CAMERA_IDLE},
    { ST_CAMERA_CONNECTING, EV_WIFI_FAIL, ST_CAMERA_STARTING},
    //PARING BUTTON
    { ST_CAMERA_STARTING, EV_BUTTON_PUSHED, ST_CAMERA_STARTING},
    { ST_CAMERA_CONNECTING, EV_BUTTON_PUSHED, ST_CAMERA_CONNECTING},
    { ST_CAMERA_REGISTERING, EV_BUTTON_PUSHED, ST_CAMERA_REGISTERING}

};

void StateMachine_Init(stateMachine_t * stateMachine) {
    //printf("Initialising state machine.\r\n");
    stateMachine->currState = ST_CAMERA_IDLE;
}

void StateMachine_RunIteration(stateMachine_t *stateMachine, event_t event) {

    // Iterate through the state transition matrix, checking if there is both a match with the current state
    // and the event
    for(int i = 0; i < sizeof(stateTransMatrix)/sizeof(stateTransMatrix[0]); i++) {
        if(stateTransMatrix[i].currState == stateMachine->currState) {
            if((stateTransMatrix[i].event == event) || (stateTransMatrix[i].event == EV_NONE)) {

                // Transition to the next state
                stateMachine->currState =  stateTransMatrix[i].nextState;

                // Call the function associated with transition
                (stateFunctionA[stateMachine->currState].func)();
                break;
            }
        }
    }
}

const char * StateMachine_GetStateName(state_t state) {
    return stateFunctionA[state].name;
}