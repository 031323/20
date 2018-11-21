#include<cstring>
#include<espeak-ng/speak_lib.h>
#include<iostream>
using namespace std;
short w[1024*1024];
long p=0;
int SynthCallback(short *wav, int numsamples, espeak_EVENT *events)
{
	memcpy(&w[p],wav,numsamples*2);
    p+=numsamples;
    return 0;
}
int main(int args,char *argv[])
{
    espeak_Initialize(AUDIO_OUTPUT_SYNCHRONOUS,0,"../espeak-ng/",0);
    if(espeak_SetVoiceByName("sa")!=EE_OK)cout<<"e1";
    if(espeak_SetParameter(espeakWORDGAP,0,0)!=EE_OK)cout<<"e2";
    espeak_SetSynthCallback(&SynthCallback);
    if(espeak_Synth("[[ja]]",4,0,POS_WORD,0,espeakPHONEMES,0,0)!=EE_OK)cout<<"e3";
    long wr=0;
    while(wr<p)
    	wr+=fwrite(&w[wr],2,p-wr,stdout);
    return 0;
}
