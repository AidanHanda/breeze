file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${Breeze_SOURCE_DIR}/include/breeze/ContentManager/*.hpp")

add_library(ContentManager contentmanager.cpp ${HEADER_LIST})
target_include_directories(ContentManager PUBLIC ${PROJECT_SOURCE_DIR}/include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
