all:
	g++ 2.cpp -I../espeak-ng/src/include '-Wl,-rpath,$$ORIGIN' ../espeak-ng/src/.libs/libespeak-ng.so -lsonic -lpcaudio -lpthread
