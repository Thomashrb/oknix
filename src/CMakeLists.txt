add_executable(oknix main.cpp json.cpp validator.cpp)

find_package(LibXml2 REQUIRED)
target_link_libraries(oknix PRIVATE LibXml2::LibXml2 nlohmann_json::nlohmann_json)

add_library(oknix_lib json.cpp validator.cpp)
target_link_libraries(oknix_lib PRIVATE LibXml2::LibXml2 nlohmann_json::nlohmann_json)
# expose library files (used in testing)
target_include_directories(oknix_lib PUBLIC .)
