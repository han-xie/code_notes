/* When compiling in linux, the environment needs to support UTF-8:
 * https://perlgeek.de/en/article/set-up-a-clean-utf8-environment
 *
 * Compile with g++ -o 01_hello 01_helloworld_utf8.cpp
 */
#include<iostream>
using namespace std;

int main(int argc, char** argv){
    cout<<"你好，世界！"<<endl;
    cout<<argc<<endl;
    cout<<argv[1]<<endl;
    return 0;
}

