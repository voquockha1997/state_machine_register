///
/// \file 				Led.c
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-04-15
/// \last-modified		2018-03-19
/// \brief 				Contains the Led module.
/// \details
///		See README.md in root dir for more info.

#include <stdio.h>
#include <unistd.h>
void Led_Init() {
    printf("Led_Init() called.\r\n");
}

void starting() {
    printf("\"Chuan bi ket noi\"\r\n");
    //sleep(1);
    printf("\"Dat QR truoc Camera\"\n");
    //sleep(1);
}

void connecting() {
    printf("\"Dang ket noi vui long doi.\"\r\n");
    //sleep(1);
}

void camera_idle() {
    printf("camera in idle state.\r\n");
    //sleep(1);
}
void wifi_successful(){
	printf("ssid,paswork successful\n");
	//sleep(1);
}
void wifi_fail(){
	printf("ssid,paswork fail\n");
	sleep(1);
}
void registering(){
	printf("\"Thiet bi dang duoc tai len\"\n");
    //sleep(1);
}
void time_out(){
	printf("time out\n");
}
void disconnect(){
	printf("disconnect/kiem tra ssid, pw\n");
}
void API(){
    printf("API register\n");
}
void busy(){
    printf("He thong ban\n");
}
void done(){
    printf("Dang ky thanh cong\n");
}