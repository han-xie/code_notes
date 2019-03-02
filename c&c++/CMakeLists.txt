cmake_minimum_required(VERSION 3.5)
project(02_sndinfo)

add_executable(
  02_sndinfo
  02_sndinfo.cpp
)

target_link_libraries(02_sndinfo sndfile FLAC ogg vorbis vorbisenc)
