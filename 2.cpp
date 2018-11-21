#include<espeak-ng/speak_lib.h>
int main(int args,char *argv[])
{
    espeak_Initialize(AUDIO_OUTPUT_SYNCHRONOUS,0,"../espeak-ng/",0);
    return 0;
}
