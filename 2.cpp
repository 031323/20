#include<cstring>
#include<espeak-ng/speak_lib.h>
#include<iostream>
using namespace std;
void wai(int i)
{
}
//if(espeak_Synth("[[ja]]",4,0,POS_WORD,0,espeakPHONEMES,0,0)!=EE_OK)x1(4);

bool mool=false;

int ko(short* sil, int il, espeak_EVENT* til)
{

}
typedef enum
{
	a=1,aa=2,i=3,ii=4,u=5,uu=6,r=7,rr=8,l=9,ll=10,e=12,o=14,E=16,O=18,
	H=19,M=20,

} manam;
void vo(char* sar, int ir, int(*)(short*,int,int) )
{
	if(!mool)
		if(espeak_Initialize(AUDIO_OUTPUT_SYNCHRONOUS,0,"../espeak-ng/",0)<0)wai(1);
	if(espeak_SetVoiceByName("sa")!=EE_OK)wai(2);
	if(espeak_SetParameter(espeakWORDGAP,0,0)!=EE_OK)wai(3);
	espeak_SetSynthCallback(&ko);
}

int im(short *art, int irt, int ist)
{
	return 0;
}
int main(int args,char *argv[])
{
	vo(NULL,0,&im);
}
