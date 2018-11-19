import io;
import subprocess;
p=[40,50,60,70]
lg=0.4
r=22050
w=bytes(0)
M=0
s=0

def x20(n,m,t):
    x1=subprocess.run(["../espeak-ng/src/espeak-ng","--path=../espeak-ng","-z","-vsa","-g0","--stdout","[["+t+"]]"], stdout=subprocess.PIPE)
    global p,lg,r,w,M,s
    f=x1.stdout[44:]
    if(m==0):
        s+=len(f)
        w+=f
    else:
        w+=bytes(M*int(lg*r)-s)
        s=len(f)
        w+=f
        M=m
    if(s>M*int(lg*r)):print(t+"   :  "+str(s)+">"+str(M*int(lg*r)) )

def ag():
    x20(1,2,"ag"); x20(1,1,"nI"); x20(1,2,"mI:I:"); x20(1,2,"l.eeee"); x20(1,1,"pu"); x20(1,2,"roooo"); x20(1,1,"hI"); x20(1,2,"tam"); x20(1,3,""); x20(1,2,"jaJ"); x20(1,2,"n^as"); x20(1,1,"ja"); x20(1,2,"deeee"); x20(1,1,"va"); x20(1,2,"mmRR   t"); x20(1,1,"vi"); x20(1,2,"Jam"); x20(1,3,""); x20(1,2,"hoooo"); x20(1,2,"ta:a:"); x20(1,2,"RaV~"); x20(1,2,"Rat"); x20(1,1,"na"); x20(1,2,"dha:a:"); x20(1,1,"ta"); x20(1,2,"mam")
    subprocess.run(["aplay","-fS16_LE","-r"+str(r)],input=w);
    


ag()
