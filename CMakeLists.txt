cmake_minimum_required(VERSION 3.12.4)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION 1.1.1)
endif()

project(OTUS_CPP_05 VERSION ${VERSION})

find_package(Doxygen COMPONENTS dot REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(OTUS_CPP_05
               main.cpp
               src/Graphic.h
               src/Document.h
               src/FileManager.h
               src/GraphicFactory.h
               src/DocBuilder.h
               src/Global.h
               src/Document.cpp)

target_include_directories(OTUS_CPP_05 PRIVATE ${CMAKE_SOURCE_DIR}/src)

configure_file(Doxyfile.in Doxyfile)
add_custom_target(
        doc
        ${DOXYGEN_EXECUTABLE} Doxyfile
        COMMENT "Creating documentation"
)

install(TARGETS OTUS_CPP_05 RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT masteryilerki@yandex.ru)

include(CPack)