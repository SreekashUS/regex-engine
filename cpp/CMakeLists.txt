cmake_minimum_required(VERSION 3.20)
project("regexEngine")

add_compile_options(-Wall -g)

add_subdirectory(src)

add_executable(
	${PROJECT_NAME}
	src/main.cpp
	src/nfa/regexNfa.cpp
	src/stringUtils/stringUtils.cpp
	)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	nfaLib
	stringLib
	)