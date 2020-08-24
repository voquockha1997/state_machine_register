///
/// \file 				Led.h
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-04-15
/// \last-modified		2018-03-19
/// \brief 				Contains the Led module.
/// \details
///		See README.md in root dir for more info.

#ifndef LED_H
#define LED_H

void Led_Init();
void starting();
void connecting();
void camera_idle();
void wifi_successful();
void wifi_fail();
void registering();
void time_out();
void disconnect();
void API();
void registering_successful();
void busy();
void done();
#endif // #ifndef LED_H