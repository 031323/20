#include<espeak-ng/speak_lib.h>
#include<iostream>
#include<string>
using namespace std;
void wai(){}

bool mool=false;

int ko(short* sil, int il, espeak_EVENT* til)
{
	return 0;
}

int pint[]={50,58,66,71,82,0,0,0};
float vot=0.45;
int wint=22050;

int on=0;
unsigned long ing=0;
int swint=-1;
void jo()
{	if(!mool)
	{
		if(espeak_Initialize(AUDIO_OUTPUT_SYNCHRONOUS,0,"../espeak-ng/",0)<0)wai();
		mool=true;
	}
	on=0;
	ing=0;
	swint=-1;
}
void co(string *trin,int win)
{
	for(int i=0;i<win;i++)
		cout<<trin[i]+"   ";
	cout<<endl;
}

void vo(const char *par,int ant,short* wor2,int &want,int &cant)
{
	if(espeak_SetVoiceByName("sa")!=EE_OK)wai();
	if(espeak_SetParameter(espeakWORDGAP,0,0)!=EE_OK)wai();
	espeak_SetSynthCallback(&ko);
	//if(espeak_Synth("[[a]]",4,0,POS_WORD,0,espeakPHONEMES,0,0)!=EE_OK)wai();
	want=0;
	int cint=0;
	cant=0;
	while(cint<ant)
	{
		bool ool=false;
		string trin[20];
		int sint[20];
		int win=0;
		int mint=0;
		int qint=cint;
		int sant=0,santu[10];
		while(!ool)
		{
			if(qint>ant-3)
			{
				cant=ant-cint;
				return;
			}
			if(par[qint]>0){qint++;continue;}
			string rin;
			{
				char ar[4];
				ar[0]=par[qint];
				ar[1]=par[qint+1];
				ar[2]=par[qint+2];
				ar[3]='\0';
				rin=ar;
			}
			if(rin=="क"||rin=="ख"||rin=="ग"||rin=="घ"||rin=="च"||rin=="छ"||rin=="ज"||rin=="झ"||rin=="ट"||rin=="ठ"||rin=="ड"||rin=="ढ"||rin=="त"||rin=="थ"||rin=="द"||rin=="ध"||rin=="प"||rin=="फ"||rin=="ब"||rin=="भ"||rin=="ङ"||rin=="ञ"||rin=="ण"||rin=="न"||rin=="म"||rin=="य"||rin=="र"||rin=="ल"||rin=="ळ"||rin=="व"||rin=="श"||rin=="ष"||rin=="स"||rin=="ह")
			{
				if(mint==0||mint==2||mint==3)
				{
					mint=1;
					trin[win]=rin;
					sint[win]=qint;
					win++;
					if(sant==2)ool=true;
				}
				else if(mint==1)
				{
					santu[sant]=win;
					sant++;
					trin[win]="अ";
					trin[win+1]=rin;
					sint[win+1]=qint;
					win+=2;
				}
			}
			else if(rin=="ॐ"||rin=="अ"||rin=="आ"||rin=="इ"||rin=="ई"||rin=="उ"||rin=="ऊ"||rin=="ऋ"||rin=="ॠ"||rin=="ऌ"||rin=="ॡ"||rin=="ए"||rin=="ऐ"||rin=="ओ"||rin=="औ")
			{
				if(mint==0||mint==2)
				{
					santu[sant]=win;
					sant++;
					mint=2;
					trin[win]=rin;
					sint[win]=qint;
					win++;
				}
				else if(mint==1)
				{
					santu[sant]=win;
					santu[sant+1]=win+1;
					sant+=2;
					trin[win]="अ";
					trin[win+1]=rin;
					sint[win+1]=qint;
					win+=2;
					mint=2;
				}
			}
			else if(rin=="ं"||rin=="ः")
			{
				if(mint==1)
				{
					santu[sant]=win;
					sant++;
					trin[win]="अ";
					trin[win+1]=rin;
					win+=2;
					mint=3;
				}
				else if(mint==2)
				{
					trin[win]=rin;
					win++;
					mint=3;
				}
			}
			else if(rin=="ा"||rin=="ि"||rin=="ी"||rin=="ु"||rin=="ू"||rin=="ृ"||rin=="ॄ"||rin=="ॢ"||rin=="ॣ"||rin=="े"||rin=="ै"||rin=="ो"||rin=="ौ")
			{
				if(rin=="ा")rin="आ";
				else if(rin=="ि")rin="इ";
				else if(rin=="ी")rin="ई";
				else if(rin=="ु")rin="उ";
				else if(rin=="ू")rin="ऊ";
				else if(rin=="ृ")rin="ऋ";
				else if(rin=="ॄ")rin="ॠ";
				else if(rin=="ॢ")rin="ऌ";
				else if(rin=="ॣ")rin="ॡ";
				else if(rin=="े")rin="ए";
				else if(rin=="ै")rin="ऐ";
				else if(rin=="ो")rin="ओ";
				else if(rin=="ौ")rin="औ";
				if(mint==1)
				{
					santu[sant]=win;
					sant++;
					trin[win]=rin;
					win++;
					mint=2;
				}
			}
			else if(rin=="ँ"||rin=="॑"||rin=="॒")
			{
				if(mint==1)
				{
					santu[sant]=win;
					sant++;
					trin[win]="अ"+rin;
					win++;
					mint=2;
				}
				else if(mint==2)trin[win-1]+=rin;
				else if(mint==3)trin[win-2]+=rin;
			}
			else if(rin=="्")
			{
				if(mint==1)
					mint=0;
			}
			else if(rin=="।"||rin=="॥")
			{
				if(mint==0||mint==2||mint==3)
				{
					trin[win]=rin;
					sint[win]=qint;
					win++;
					ool=true;
				}
				else if(mint==1)
				{
					santu[sant]=win;
					sant++;
					trin[win]="अ";
					trin[win+1]=rin;
					sint[win+1]=qint;
					win+=2;
					ool=true;
				}
			}
			if(sant>2)ool=true;
			qint+=3;
		}
		int kin;
		int mon=1;
		if(sant==0)
		{
			cint=sint[win-1]+3;
			co(trin,win);
			kin=0;
		}
		else if(sant==1)
		{
			cint=sint[win-1];
			co(trin,win-1);
			kin=win-1;
		}
		else if(sant>=2)
		{
			if(santu[1]-santu[0]==1)
			{
				cint=sint[santu[1]];
				co(trin,santu[1]);
				kin=santu[1];
			}
			else if(santu[1]-santu[0]==2)
			{
				cint=sint[santu[1]-1];
				co(trin,santu[1]-1);
				kin=santu[1]-1;
			}
			else
			{
				cint=sint[santu[0]+2];
				co(trin,santu[0]+2);
				kin=santu[0]+2;
			}
		}
		string crim[2];
		int crint=0;
		bool crool=trin[santu[0]].find("॑")!=std::string::npos;
		for(int i=0;i<kin;i++)
		{
			if(trin[i]=="अ")
			{
				if(!crool)crim[crint]+="aa";
				else {crim[crint]+="a";crint++;crim[crint]+="a";}
			}
			else if(trin[i]=="आ")
			{
				mon=2;
				if(!crool)crim[crint]+="a:a:";
				else {crim[crint]+="a";crint++;crim[crint]+="aa:";}
			}
			else if(trin[i]=="इ")
			{
				if(!crool)crim[crint]+="II";
				else {crim[crint]+="I";crint++;crim[crint]+="I";}
			}
			else if(trin[i]=="ई")
			{
				mon=2;
				if(!crool)crim[crint]+="I:I:";
				else {crim[crint]+="I";crint++;crim[crint]+="II:";}
			}
			else if(trin[i]=="उ")
			{
				if(!crool)crim[crint]+="uu";
				else {crim[crint]+="u";crint++;crim[crint]+="u";}
			}
			else if(trin[i]=="ऊ")
			{
				mon=2;
				if(!crool)crim[crint]+="uuuu";
				else {crim[crint]+="u";crint++;crim[crint]+="uuu";}
			}
			else if(trin[i]=="ऋ")
			{
				if(!crool)crim[crint]+="RR";
				else {crim[crint]+="R";crint++;crim[crint]+="RR";}
			}
			else if(trin[i]=="ऊ")
			{
				mon=2;
				if(!crool)crim[crint]+="uuuu";
				else {crim[crint]+="u";crint++;crim[crint]+="uuu";}
			}
		}
		
		
		if(sant==0)mon=2;
		else if(kin-santu[0]>1)mon=2;
		on+=mon;
	}
}

int main(int args,char *argv[])
{
	int want,cant=0;
	char mar[]="वक्त्रम्।";
	cout<<sizeof(mar)<<endl;
	for(int i=0;i<sizeof(mar)-1;i+=18)
	{
		int ant;
		if(i+18<=sizeof(mar)-1)ant=18;
		else ant=sizeof(mar)-1-i;
		vo(mar+i-cant,ant+cant,NULL,want,cant);
	}
}
