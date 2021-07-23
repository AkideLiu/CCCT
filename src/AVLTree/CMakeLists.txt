include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
) # including .h header in current directory (sub directory) (do not modify)

conan_basic_setup() # conan support

add_executable(AVLTree # your sub-project name

        # add your source file (cpp file only)
        
        ../Test/AVLTree-Test.cpp
        Node.cpp
        binarySearchTree.cpp
        binarySearchTree.h
        AVLTree.cpp
        )



target_link_libraries(AVLTree # must identical to sub-project name
        ${CONAN_LIBS} # include CONAN libs which defined in root level Cmake
        )
