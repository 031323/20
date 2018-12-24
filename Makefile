all:
data:
	cp -r ../espeak-ng/espeak-ng-data ./
	rm espeak-ng-data/phondata-manifest
exe:	
	g++ -g 2.cpp -I../espeak-ng/src/include '-Wl,-rpath,$$ORIGIN' ../espeak-ng/src/.libs/libespeak-ng.so -lsonic -lpcaudio -lpthread
web:
	emcc 2.cpp -I../espeak-ng/src/include ../espeak-ng-2/espeak-ng/src/.libs/libespeak-ng.so -o 2.js --preload-file espeak-ng-data -s EXPORTED_FUNCTIONS='["_no","_so","_main"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -s USE_SDL=2
