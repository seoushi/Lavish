%module lavish
%{
  /* Includes the header in the wrapper code */
  #include <lavish/core/display.hpp>
%}
 
/* Parse the header file to generate wrappers */

%include "../../include/lavish/core/display.hpp";