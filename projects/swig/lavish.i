%module lavish
%{
  /* Includes the header in the wrapper code */
  #include <lavish/common/color.hpp>
  #include <lavish/math/vector2.hpp>
  #include <lavish/core/keyboard.hpp>
  #include <lavish/core/mouse.hpp>
  #include <lavish/core/eventListener.hpp>
  #include <lavish/core/display.hpp>
%}
 
/* Parse the header file to generate wrappers */

%include "../../include/lavish/common/color.hpp";
%include "../../include/lavish/math/vector2.hpp";
%include "../../include/lavish/core/keyboard.hpp";
%include "../../include/lavish/core/mouse.hpp";
%include "../../include/lavish/core/eventListener.hpp";
%include "../../include/lavish/core/display.hpp";