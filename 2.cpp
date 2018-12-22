#include<espeak-ng/speak_lib.h>
#include<iostream>
#include<string>
#include<cstring>
#ifdef EMSCRIPTEN
#include<emscripten.h>
#include<SDL2/SDL.h>
#include<cstdlib>
#endif
using namespace std;
void wai(){*((char*)12)=0;}

bool bol=false;

bool mool=false;

bool tool=false;

void (*lo)(short*,int);

long ing=0;
int ko(short* sil, int il, espeak_EVENT* til)
{
	if(il)
	{
		(*lo)(sil,il);
		ing+=il;
	}
	return 0;
}

int pint[]={50,58,66,71,82,0,0,0};
float vot=0.23;
int wint=22050.0;

int on=0;
int swint=-1;
void jo()
{	if(!mool)
	{
		if(espeak_Initialize(AUDIO_OUTPUT_SYNCHRONOUS,0,"./",0)<0)wai();
		if(espeak_SetVoiceByName("sa")!=EE_OK)wai();
		if(espeak_SetParameter(espeakWORDGAP,0,0)!=EE_OK)wai();
		espeak_SetSynthCallback(&ko);
		mool=true;
	}
	on=0;
	ing=0;
	swint=0;
}
void co(string *trin,int win)
{
	if(!bol)return;
	for(int i=0;i<win;i++)
		cout<<trin[i]+"   ";
	cout<<endl;
}

void vo(const char *par,int ant,int &cant)
{
	if(!mool)return;
	if(bol)cout<<"aya: "<<par<<endl;
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
			if(par[qint]>=0){qint++;continue;}
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
				if(mint==0||mint==2||mint==3)
				{
					santu[sant]=win;
					sant++;
					mint=2;
					trin[win]=rin;
					sint[win]=qint;
					win++;
					if(rin=="ॐ")ool=true;
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
					if(rin=="ॐ")ool=true;
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
		int kin=0;
		int mon=1;
		if(sant==0)
		{
			cint=sint[win-1]+3;
			co(trin,win);
			kin=0;
			swint=-1;
		}
		else if(sant==1)
		{
			if(trin[win-1]=="ॐ")
			{
				kin=win;
				co(trin,kin);
				cint=sint[kin-1]+3;
			}
			else kin=win-1;
		}
		else if(sant>=2)
		{
			if(santu[1]-santu[0]==1)
			{
				kin=santu[1];
			}
			else if(santu[1]-santu[0]==2)
			{
				if(trin[santu[1]]=="ॐ")kin=santu[1];
				else kin=santu[1]-1;
			}
			else
			{
				if(trin[santu[1]]=="ॐ")kin=santu[1];
				else if(
					(trin[santu[0]+1]=="क"&&(trin[santu[0]+2]=="क"||trin[santu[0]+2]=="ख"))||
					(trin[santu[0]+1]=="ग"&&(trin[santu[0]+2]=="ग"||trin[santu[0]+2]=="घ"))||
					(trin[santu[0]+1]=="च"&&(trin[santu[0]+2]=="च"||trin[santu[0]+2]=="छ"))||
					(trin[santu[0]+1]=="ज"&&(trin[santu[0]+2]=="ज"||trin[santu[0]+2]=="झ"))||
					(trin[santu[0]+1]=="ट"&&(trin[santu[0]+2]=="ट"||trin[santu[0]+2]=="ठ"))||
					(trin[santu[0]+1]=="ड"&&(trin[santu[0]+2]=="ड"||trin[santu[0]+2]=="ढ"))||
					(trin[santu[0]+1]=="त"&&(trin[santu[0]+2]=="त"||trin[santu[0]+2]=="थ"))||
					(trin[santu[0]+1]=="द"&&(trin[santu[0]+2]=="द"||trin[santu[0]+2]=="ध"))||
					(trin[santu[0]+1]=="प"&&(trin[santu[0]+2]=="प"||trin[santu[0]+2]=="फ"))||
					(trin[santu[0]+1]=="ब"&&(trin[santu[0]+2]=="ब"||trin[santu[0]+2]=="भ"))
					)
				{
					kin=santu[0]+1;
					mon=2;
				}
				else kin=santu[0]+2;
			}
		}

		if(sant==0)mon=2;
		else if(kin-santu[0]>1)mon=2;
		if(trin[santu[0]]=="ॐ")mon=3;
		if(kin)co(trin,kin);
		if(kin&&trin[kin-1]!="ॐ")
			cint=sint[kin];

		string crim[2];
		int crint=0;
		bool crool=trin[santu[0]].find("॑")!=std::string::npos;
		for(int i=0;i<kin;i++)
		{
			if(i==santu[0])
			{
				string fin;
				int lint=1;
				bool nool=trin[i].find("ँ")!=std::string::npos;
				if(trin[i].find("अ")!=std::string::npos){fin="a";lint=1;}
				else if(trin[i].find("आ")!=std::string::npos){fin="A";lint=2;}
				else if(trin[i].find("इ")!=std::string::npos){fin="i";lint=1;}
				else if(trin[i].find("ई")!=std::string::npos){fin="i";lint=2;}
				else if(trin[i].find("उ")!=std::string::npos){fin="u";lint=1;}
				else if(trin[i].find("ऊ")!=std::string::npos){fin="u";lint=2;}
				else if(trin[i].find("ऋ")!=std::string::npos){fin="r";lint=1;}
				else if(trin[i].find("ॠ")!=std::string::npos){fin="r";lint=2;}
				else if(trin[i].find("ऌ")!=std::string::npos){fin="l";lint=1;}
				else if(trin[i].find("ॡ")!=std::string::npos){fin="l";lint=2;}
				else if(trin[i].find("ए")!=std::string::npos){fin="e";lint=2;}
				else if(trin[i].find("ऐ")!=std::string::npos){fin="E";lint=2;}
				else if(trin[i].find("ओ")!=std::string::npos){fin="o";lint=2;}
				else if(trin[i].find("औ")!=std::string::npos){fin="O";lint=2;}
				if(mon<2&&lint==2)mon=2;
				if(trin[i]=="ॐ")crim[crint]+="oooooommmmm";
				
				else for(int j=0;j<2*lint;j++)
				{
					if(crool&&j==1)
						crint=1;
					crim[crint]+=fin;
					if(nool)crim[crint]+="~";
				}
			}
			else if(trin[i]=="ं")crim[crint]+="M";
			else if(trin[i]=="ः")crim[crint]+="HH";
			else if(trin[i]=="य")crim[crint]+="j";
			else if(trin[i]=="र")crim[crint]+="R";
			else if(trin[i]=="ल")crim[crint]+="L";
			else if(trin[i]=="ळ")crim[crint]+="l.";
			else if(trin[i]=="व")crim[crint]+="v";
			else if(trin[i]=="श")crim[crint]+="S";
			else if(trin[i]=="ष")crim[crint]+="s.";
			else if(trin[i]=="स")crim[crint]+="s";
			else if(trin[i]=="ह")crim[crint]+="HH";
			else if(trin[i]=="ङ")crim[crint]+="N";
			else if(trin[i]=="ञ")crim[crint]+="n^";
			else if(trin[i]=="ण")crim[crint]+="n.";
			else if(trin[i]=="न")crim[crint]+="n";
			else if(trin[i]=="म")crim[crint]+="m";
			else if(trin[i]=="क")
			{
				string gin1="क";
				string gin2="ख";
				string bin="k";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ख")
			{
				string gin1="क";
				string gin2="ख";
				string bin="k#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ग")
			{
				string gin1="ग";
				string gin2="घ";
				string bin="g";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="घ")
			{
				string gin1="ग";
				string gin2="घ";
				string bin="g#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="च")
			{
				string gin1="च";
				string gin2="छ";
				string bin="c";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="छ")
			{
				string gin1="च";
				string gin2="छ";
				string bin="c#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ज")
			{
				string gin1="ज";
				string gin2="झ";
				string bin="J";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="झ")
			{
				string gin1="ज";
				string gin2="झ";
				string bin="J#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ट")
			{
				string gin1="ट";
				string gin2="ठ";
				string bin="t.";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ठ")
			{
				string gin1="ट";
				string gin2="ठ";
				string bin="t.#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ड")
			{
				string gin1="ड";
				string gin2="ढ";
				string bin="d.";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ढ")
			{
				string gin1="ड";
				string gin2="ढ";
				string bin="d.#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}

			else if(trin[i]=="त")
			{
				string gin1="त";
				string gin2="थ";
				string bin="t";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="थ")
			{
				string gin1="त";
				string gin2="थ";
				string bin="t#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="द")
			{
				string gin1="द";
				string gin2="ध";
				string bin="d";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ध")
			{
				string gin1="द";
				string gin2="ध";
				string bin="d#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="प")
			{
				string gin1="प";
				string gin2="फ";
				string bin="p";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="फ")
			{
				string gin1="प";
				string gin2="फ";
				string bin="p#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="ब")
			{
				string gin1="ब";
				string gin2="भ";
				string bin="b";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			else if(trin[i]=="भ")
			{
				string gin1="ब";
				string gin2="भ";
				string bin="b#";
				if(i<kin-1){if(trin[i+1]==gin1||trin[i+1]==gin2)bin="";}
				if(i>0){if(trin[i-1]==gin1)bin+=":";}
				crim[crint]+=bin;
			}
			if(crim[crint][crim[crint].length()-1]=='#'||crim[crint][crim[crint].length()-2]=='#')crim[crint]+="H";
			
		}
		if(santu[1]-santu[0]>2)crim[crint]+="_::";
		if(kin)for(int i=0;i<=crint;i++)
		{
			int fint=-1;
			if(crool)
			{
				if(i==0)fint=3;
				else fint=0;
				swint=1;
			}
			else
			{
				if(trin[santu[0]].find("॒")!=string::npos)
				{
					fint=0;
					if(sant>1){if(trin[santu[1]].find("॒")!=string::npos)fint=1;}
					swint=2;
				}
				else if(sant>1)
				{
					if(trin[santu[1]].find("॑")!=string::npos)fint=2;
				}
				if(fint==-1&&swint==2){fint=2;}
				if(fint==-1){fint=1;}
			}
			crim[i]="[["+crim[i]+"]]";
			if(bol)cout<<"P: "<<fint<<" ";
			if(espeak_SetParameter(espeakPITCH,pint[fint],0)!=EE_OK)wai();
			if(espeak_Synth(crim[i].c_str(),0,0,POS_WORD,0,espeakPHONEMES,0,0)!=EE_OK)wai();
			if(bol)cout<<crim[i]<<endl;
		}
		on+=mon;
		long wong=vot*wint;
		wong+=wong%2;
		if(!tool&&sant==0)
		{
			short* mort=new short(mon*wong);
			memset(mort,0,sizeof(short)*(mon*wong));
			ko(mort,mon*wong,NULL);
			delete(mort);
		}
		if(tool&&ing<on*wong)
		{
			short* mort=new short(on*wong-ing);
			memset(mort,0,sizeof(short)*(on*wong-ing));
			ko(mort,on*wong-ing,NULL);
			delete(mort);
		}
		else if(bol&&tool)cout<<">"<<(float)(ing-on*wong)/(float)wong*100.0<<endl;
		if(bol&&tool)cout<<"tool"<<endl;
		if(bol)cout<<"hua"<<endl;
	}
}
void so(short *sil,int il)
{
	if(!bol)fwrite(sil,sizeof(short),il,stdout);
}

int cant=0;
string king="";
void mo(string sing)
{
	king+=sing;
	vo((king).c_str(),king.length(),cant);
	if(bol)cout<<"cant"<<cant<<endl;
	king=king.substr(king.length()-cant,cant);
}
#ifndef EMSCRIPTEN
int main(int args,char *argv[])
{
	lo=&so;
	string ring="";
	if(args>1)ring=argv[1];
	if(ring.find("v")!=string::npos)bol=true;
	if(ring.find("t")!=string::npos)tool=true;
	string sing="";
	jo();
	while(sing!="0")
	{
		cin>>sing;
		mo(sing);
	}
}
#else
short bort[22050*60];
long mong=0;
void to(short *sil,int il)
{
	if(!il)return;
	memcpy(&bort[mong/2],sil,il*2);
	mong+=il*2;	
}
long fong=0;
SDL_AudioDeviceID dev;
void ho(void* userdata,Uint8* stream,int len)
{
	//EM_ASM({alert('mong:' + $0);},mong);
	if(fong>=mong){SDL_CloseAudioDevice(dev);return;}
	if(len>mong-fong)len=mong-fong;
	memcpy(stream,(char*)bort+fong,len);
	fong+=len;
}
extern "C" {
int no(char* lar)
{mo(lar);SDL_PauseAudioDevice(dev, 0);return strlen(lar);}
int main(int args,char *argv[])
{
	lo=&to;
	jo();
	
	
	if(SDL_Init(SDL_INIT_AUDIO)<0)return 1;
	SDL_AudioSpec wav_spec,have;
	SDL_zero(wav_spec);
	wav_spec.freq=22050;
	wav_spec.format=AUDIO_S16LSB;
	wav_spec.channels=1;
	wav_spec.samples=1024*4;
	wav_spec.callback=&ho;
	
	
	dev = SDL_OpenAudioDevice(NULL, 0, &wav_spec,&have,0);
	if(dev==0)return 1;
	EM_ASM(
		go();
	);
}
}
#endif
