cmake_minimum_required(VERSION 3.5)

project(qsql LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
link_directories(/opt/local/lib/postgresql13/ /opt/local/lib/)
include_directories(. /opt/local/include/)

add_executable(qql
    example/main.cpp
)
target_link_libraries(qql pqxx pq)

include(GNUInstallDirs)

install(TARGETS qql
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
