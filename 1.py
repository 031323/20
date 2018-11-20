import io;
import subprocess;

p=[50,58,66,71,82,0,0,0]
lg=0.51
r=22050
w=bytes(0)
M=0
s=0

def x20(n,m,t):
    global p,lg,r,w,M,s
    x1=subprocess.run(["../espeak-ng/src/espeak-ng","-p"+str(p[n]),"--path=../espeak-ng","-z","-vsa","-g0","--stdout","[["+t+"]]"], stdout=subprocess.PIPE)
    f=x1.stdout[44:]
    f=f.lstrip(b'\x00')
    if(m==0):
        s+=len(f)
        w+=f
    else:
        w+=bytes(M*(int(lg*r)+int(lg*r)%2)-s)
        s=len(f)
        w+=f
        M=m
    if(s>M*(int(lg*r)+int(lg*r)%2)):print(t+"   :  "+str(s)+">"+str(M*(int(lg*r)+int(lg*r)%2)))

def ag():
    global lg
    lg=0.48
    x20(0,2,"aagnnn"); x20(2,1,"nII"); x20(3,2,"mI"); x20(0,0,"I:I:"); 
    x20(1,2,"l.eeeeeee"); x20(0,1,"puu"); x20(2,2,"Roooooo");
    x20(3,1,"hI"); x20(0,0,"I"); x20(1,2,"taaV~"); x20(0,2,"jaaJ");
    x20(2,2,"n^aass"); x20(3,1,"ja"); x20(0,0,"a"); x20(1,2,"deeeeee");
    x20(1,1,"vaa"); x20(0,2,"mmRRt"); x20(2,1,"vII"); x20(3,2,"Ja");
    x20(0,0,"am"); x20(1,3,""); x20(2,2,"hooooooo"); x20(3,2,"ta");
    x20(0,0,"a:a:a"); x20(1,2,"RaaV~"); x20(1,2,"Raat"); x20(0,1,"naa");
    x20(2,2,"dha:a:"); x20(3,1,"ta"); x20(0,0,"a"); x20(1,2,"maam")

def om():
    x20(1,4,"oooooouuummmm"); x20(1,2,"bhuuuuuR"); x20(1,1,"bhuu"); x20(1,2,"vaasss"); x20(1,2,"svaaHH");
    x20(1,2,"");
    x20(2,2,"taat");
    x20(3,1,"sa"); x20(0,0,"a");
    x20(1,1,"vII"); x20(1,2,"tuuR"); x20(1,1,"vaa"); x20(1,2,"Reeeeen.");
    x20(0,2,"jaam");
    x20(2,2,"bhaaR");
    x20(3,2,"go"); x20(0,0,"ooooo");
    x20(0,2,"deeeee");
    x20(2,2,"vaas");
    x20(3,1,"ja"); x20(0,0,"a");
    x20(1,2,"dhI:I:I:"); x20(1,1,"maa"); x20(1,1,"HII");
    x20(1,2,"");
    x20(1,1,"dhII");
    x20(0,2,"joooooo");
    x20(2,2,"joooooo");
    x20(3,2,"na"); x20(0,0,"aff");
    x20(1,1,"pRaa");
    x20(0,2,"coooooo");
    x20(2,1,"daa");
    x20(3,2,"ja"); x20(0,0,"a:a:t");
    
    
def tva():
    global lg
    lg=5.1
    x20(0,1,"tvaa"); x20(1,2,"dI:I:I:"); x20(2,1,"jaa"); x20(3,2,"pa:a:a:"); x20(1,1,"daa"); x20(1,2,"paaN"); x20(1,1,"kaa"); x20(1,2,"JaaV~"); x20(1,1,"naa"); x20(1,2,"ma:a:a:"); x20(1,1,"mII"); x20(1,2,"de:e:e:e:"); x20(1,1,"vII"); x20(1,2,"naaR"); x20(1,1,"maa"); x20(1,2,"de:e:e:e:");
    
om()
subprocess.run(["aplay","-fS16_LE","-r"+str(r)],input=w);
