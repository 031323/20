all:
	g++ 2.cpp -I../espeak-ng/src/include ../espeak-ng/src/.libs/libespeak-ng.a -lsonic -lpcaudio -lpthread
