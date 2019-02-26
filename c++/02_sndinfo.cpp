/* apt install -y libogg-dev libflac-dev libvorbis-dev
 * install libsndfile from github (https://github.com/erikd/libsndfile.git)
 * g++ -o 02_sndinfo 02_sndinfo.cpp -lsndfile -logg -lFLAC -lvorbis -lvorbisenc
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sndfile.h>

#define BUFFER_LEN (1 << 16)

const char *
program_name (const char * argv0)
{ const char * tmp ;

  tmp = strrchr (argv0, '/') ;
  argv0 = tmp ? tmp + 1 : argv0 ;
  return argv0;
} /* program_name: libsndfile -> common.c */

int main(int argc, char** argv){
  if(argc != 2 || strcmp(argv[1], "--help")==0 || strcmp(argv[1], "-h")==0) {
    std::cout<<"Usage: "<<program_name(argv[0])<<" <audio_file_name>"<<std::endl;
    exit(1);
  }
  static char strbuffer[BUFFER_LEN];
  SNDFILE* file;
  SF_INFO info;
  info.format = 0;
  if (!(file = sf_open(argv[1], SFM_READ, &info))) {
    std::cout<<"sndfile: unknown format or could not open file - "
             << argv[1]<<std::endl;
    exit(1);
  }
  std::cout<<"========================================"<<std::endl;
  sf_command(file, SFC_GET_LOG_INFO, strbuffer, BUFFER_LEN);
  std::cout<<strbuffer;
  std::cout<<"----------------------------------------"<<std::endl;
  std::cout<<"Sample Rate : "<<info.samplerate<<std::endl;
  std::cout<<"Frames      : "<<info.frames<<std::endl;
  std::cout<<"Channels    : "<<info.channels<<std::endl;
  return 0;
}
