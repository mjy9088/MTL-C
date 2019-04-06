PROJECT ( MTL-C )
ADD_EXECUTABLE( mtl ../mtl/main.c )

enable_testing()
ADD_EXECUTABLE( test4cases ../test/test4cases.c )
add_test( NAME test4cases COMMAND test4cases )
