# TODO
#add_executable(oknix main.cpp json.hpp validator.hpp)
add_executable(oknix main.cpp)

find_package(LibXml2 REQUIRED)
target_link_libraries(oknix PUBLIC LibXml2::LibXml2 nlohmann_json::nlohmann_json)

add_library(oknix_lib json.cpp validator.cpp)
# expose library files (used in testing)
target_include_directories(oknix_lib PUBLIC .)
