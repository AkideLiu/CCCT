include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

conan_basic_setup()

add_executable(AVLTree
        ../Test/AVLTree-Test.cpp
        Node.cpp
        binarySearchTree.cpp
        binarySearchTree.h
        AVLTree.cpp
        )



target_link_libraries(AVLTree
        ${CONAN_LIBS}
        )