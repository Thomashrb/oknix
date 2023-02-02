cmake_minimum_required(VERSION 3.5)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -pedantic) # -Werror

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  oknix
  VERSION 0.01
  LANGUAGES CXX)

# add dependencies using (maximum) CPM
include(cmake/CPM.cmake)
CPMAddPackage("gh:catchorg/Catch2@3.2.0")
CPMAddPackage("gh:nlohmann/json@3.11.2")

# copy schema files to build directory
configure_file(resources/Onix3sample_refnames.xml Onix3sample_refnames.xml  COPYONLY)
configure_file(resources/ONIX_BookProduct_3.0_reference.xsd ONIX_BookProduct_3.0_reference.xsd COPYONLY)
configure_file(resources/ONIX_BookProduct_CodeLists.xsd ONIX_BookProduct_CodeLists.xsd COPYONLY)
configure_file(resources/ONIX_XHTML_Subset.xsd ONIX_XHTML_Subset.xsd COPYONLY)

# allow tests to be ran/picked up by (c)make/test -- has to be called before any setup of tests
enable_testing()
# include CMakeList from test and src directory
add_subdirectory(src)
add_subdirectory(test)
