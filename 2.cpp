#include<cstring>
#include<espeak-ng/speak_lib.h>
#include<iostream>
#include<queue>
using namespace std;
void wai(){}

bool mool=false;

int ko(short* sil, int il, espeak_EVENT* til)
{

}
int on=0;
long ing=0;
class kaas
{
};
#define INE 10

void jo()
{	if(!mool)
		if(espeak_Initialize(AUDIO_OUTPUT_SYNCHRONOUS,0,"../espeak-ng/",0)<0)wai();
	on=0;
	ing=0;
}	
void vo(char *par,int ant,short* wor2,int &want,int &cant)
{
	if(espeak_SetVoiceByName("sa")!=EE_OK)wai();
	if(espeak_SetParameter(espeakWORDGAP,0,0)!=EE_OK)wai();
	espeak_SetSynthCallback(&ko);
	if(espeak_Synth("[[a]]",4,0,POS_WORD,0,espeakPHONEMES,0,0)!=EE_OK)wai();

}

int main(int args,char *argv[])
{

}
