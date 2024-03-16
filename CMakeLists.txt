cmake_minimum_required(VERSION 3.14)

set(CMAKE_CONFIGURE_DEPENDS TRUE)

project(liblapin)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(SFML REQUIRED COMPONENTS graphics)
find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(libudev REQUIRED IMPORTED_TARGET libudev)
pkg_check_modules(libusb REQUIRED IMPORTED_TARGET libusb)

add_library(lapin)
file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HEADERS include/lapin/*.h)
file(GLOB_RECURSE PRIV_HEADERS include/private/*.h)
file(GLOB_RECURSE DEPS_HEADERS include/deps/*.h)
target_sources(lapin 
    PRIVATE ${SRCS}
    PRIVATE FILE_SET private_headers TYPE HEADERS BASE_DIRS include/private FILES ${PRIV_HEADERS}
    PRIVATE FILE_SET deps_headers TYPE HEADERS BASE_DIRS include/deps FILES ${DEPS_HEADERS}
    PUBLIC FILE_SET public_headers TYPE HEADERS BASE_DIRS include FILES ${HEADERS})
target_link_libraries(lapin PUBLIC sfml-graphics opencv_video PkgConfig::libudev PkgConfig::libusb)
target_compile_options(lapin PRIVATE -W -Wall)
target_compile_definitions(lapin PRIVATE BUNNY_COMPILATION)

configure_package_config_file(cmake/lapin-config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/lapin-config.cmake 
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/)

install(TARGETS lapin
    EXPORT lapin-targets
    FILE_SET public_headers)
install(EXPORT lapin-targets 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lapin-config.cmake 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/)
