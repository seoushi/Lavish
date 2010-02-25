require 'mkmf'

$LIBS << " -lstdc++ -lc"
$CC = "g++"
create_makefile('lavish')