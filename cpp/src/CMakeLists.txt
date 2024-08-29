add_library(
	stringLib
	SHARED
	stringUtils/stringUtils.cpp
	)

target_include_directories(
	stringLib 
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/../include/stringUtils"
	)
# -----------------------------------------------------------------


add_library(
	nfaLib
	SHARED
	nfa/regexNfa.cpp
	)

target_include_directories(
	nfaLib
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/../include"
	)
target_link_libraries(
	nfaLib
	PRIVATE
	stringLib
	)
# -----------------------------------------------------------------

# target_link_directories(
#     objectLib PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/../dep/lib
#     )

# -----------------------------------------------------------------