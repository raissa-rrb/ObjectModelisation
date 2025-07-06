# -*- explicit-buffer-name: "CMakeLists.txt<M1-MOBJ/6>" -*-
#
# To display executed commands, use:
#     > cmake -DCMAKE_VERBOSE_MAKEFILE:STRING=YES ../src

 cmake_minimum_required(VERSION 2.8.0)
 project(SCHEMATIC)

# detection de LibXml2
find_package(LibXml2)

# trouver include de LibXml2
include_directories( ${SCHEMATIC_SOURCE_DIR} ${LIBXML2_INCLUDE_DIR})
 
 set (CMAKE_CXX_FLAGS            "-Wall -g" CACHE STRING "C++ Compiler Release options." FORCE)
 set (CMAKE_INSTALL_PREFIX       "../install" )


    include_directories( ${SCHEMATIC_SOURCE_DIR}
                       )

                    set( includes     Indentation.h
                                      Term.h
                                      Net.h
                                      Instance.h
                                      Point.h
                                      Node.h
                                      Cell.h
                       )

                    set( cpps         Indentation.cpp
                                      Term.cpp
                                      Net.cpp
                                      Instance.cpp
                                      Point.cpp
                                      Node.cpp
                                      Cell.cpp
                                      Main.cpp
                       )

        add_executable ( tme6        ${cpps} )
               install ( TARGETS      tme6        DESTINATION bin )
               install ( FILES        ${includes}  DESTINATION include )
         target_link_libraries ( tme6 ${LIBXML2_LIBRARIES} )
