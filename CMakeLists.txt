cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(SFINAE VERSION ${PROJECT_VERSION})

#set (BOOST_ROOT "C:/Boost/boost_1_83_0/") # Путь к библиотеке Boost
# 
#set (CMAKE_CXX_STANDARD 14) 
#set (Boost_NO_SYSTEM_PATHS ON)
#set (Boost_USE_MULTITHREADED ON)
#set (Boost_USE_STATIC_LIBS ON)
#set (Boost_USE_STATIC_RUNTIME OFF)
#set (BOOST_ALL_DYN_LINK OFF)
#  
## Подключаем необходимые модули. Для примера подключим program_options
##find_package (Boost REQUIRED COMPONENTS program_options REQUIRED) 
##find_package (Boost COMPONENTS unit_test_framework REQUIRED)
#  
## Если библиотека найдена, то
#if (Boost_FOUND)
#    include_directories (SYSTEM ${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
#    add_executable (Boost_test "main.cpp") # Создаем исполняемый файл для нашего проекта
#    target_link_libraries (Boost_test ${Boost_LIBRARIES}) # подключаем библиотеку
#endif ()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(SFINAE_cli main.cpp)
add_library(SFINAE lib.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(SFINAE_cli SFINAE test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(SFINAE
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(SFINAE_cli PRIVATE
SFINAE
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
    SFINAE
)

if (MSVC)
    target_compile_options(SFINAE_cli PRIVATE
        /W4
    )
    target_compile_options(SFINAE PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(SFINAE_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(SFINAE PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS SFINAE_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
