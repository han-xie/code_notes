%module mod_cal
/* put the following line at the end of this file will introduce a
 * TypeError: in method 'cpp_print', argument 1 of type 'std::string'
 *
 * Reference:
 * https://github.com/smukherj1/swigpython.git
 */
%include "std_string.i"
%{
#define SWIG_WITH_INIT
#include "mod_cal.h"
%}

%include "mod_cal.h"
