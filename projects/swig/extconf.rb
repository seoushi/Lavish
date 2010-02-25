require 'mkmf'

$LIBS << " -lstdc++ -lc -framework lavish"
$CC = "g++"
create_makefile('lavish')