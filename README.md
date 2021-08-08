# Cmake Clion Conan Template

## Author : [Akide Liu](https://github.com/AkideLiu)

### The template integration of Cmake Clion Conan for University of Adelaide C++ direction course educational purpose only


- [Cmake Clion Conan Template](#cmake-clion-conan-template)
  * [Template Structure](#template-structure)
  * [What is Conan](#what-is-conan-)
  * [What is Clion](#what-is-clion-)
  * [What is Cmake](#what-is-cmake)
  * [Setup Instructions](#setup-instructions)
  * [Get Stated a new sub-project](#get-stated-a-new-sub-project)
  * [Featured Plugin](#featured-plugin)
  * [Licensed Under GPL-v3](#licensed-under-gpl-v3)

This template use cmake as build and complie support, conan build external framework (e.g. GTest), Clion integrated them together.

This template design for multiple sub-projects architecture and optimized conan with once build unlimited reuse.

## Github Actions Continue Integration [Example](https://github.com/AkideLiu/CCCT/actions/runs/1059040010/workflow)

Linux : [![CI](https://github.com/AkideLiu/CCCT/actions/workflows/CI.yaml/badge.svg?branch=master)](https://github.com/AkideLiu/CCCT/actions/workflows/CI.yaml)

Macos : [![CI](https://github.com/AkideLiu/CCCT/actions/workflows/CI.yaml/badge.svg?branch=master)](https://github.com/AkideLiu/CCCT/actions/workflows/CI.yaml)

## Template Structure

```shell
├── CMakeLists.txt // top layer cmake setup
├── LICENSE
├── README.md
├── example_sub // example source code
│   ├── AVLTree
│   │   ├── AVLTree.cpp
│   │   ├── AVLTree.h
│   │   ├── CMakeLists.txt // sub dir cmake setup
│   │   ├── Node.cpp
│   │   ├── binarySearchTree.cpp
│   │   └── binarySearchTree.h
│   └── Test
│       └── AVLTree-Test.cpp // test file maintained in test folder
└── main.cpp

```

## What is [Cmake](https://cmake.org/)？

Long Description - CMake is an open-source, cross-platform family of tools designed to build, test and package software. CMake is used to control the software compilation process using simple platform and compiler independent configuration files, and generate native makefiles and workspaces that can be used in the compiler environment of your choice. The suite of CMake tools were created by Kitware in response to the need for a powerful, cross-platform build environment for open-source projects such as ITK and VTK.

Short answer - **build and complie tools for C++**

## What is [Conan](https://conan.io/) ? 

The open source, decentralized and multi-platform package manager to create and share all your native binaries. 

**Build third party dependency, such as Google Test**

## What is [Clion](https://www.jetbrains.com/clion/?rss) ?

 A cross-platform IDE for C and C++

![img](https://minio.llycloud.com/image/uPic/image-20210722XaUz5z.png)

## Setup Instructions

Notice : The Setup instructions below is for **MacOS** and **Linux** Users.

Looking for Windows Instructions? [Windows setup Instructions](./windows.md) 

```shell
Distributor ID:	Ubuntu
Description:	Ubuntu 20.04.2 LTS
Release:	20.04
Codename:	focal
```

1. Register Jetbrains Account and generate Educational License

   Note : Use Your School Email

   https://www.jetbrains.com/community/education/#students
   
2. Download and install Clion (Select corresponding system platform)

   https://www.jetbrains.com/clion/download/#section=mac

   Note : For Mac Users, M1 Series Chips have been supported by native Arm version 

   Ubuntu User Could use Snap package manager

   ```shell
   sudo snap install clion --classic
   ```

   

3.  Enter the Jetbrains Account to active the Clion

   ![image-20210722012221711](https://minio.llycloud.com/image/uPic/image-20210722yOgOK6.png)

4. Install gcc / clang compiler

   MacOS : 

   ```shell
   xcode-select --install
   ```

   Linux : 

   ```shell
   sudo apt-get update
   sudo apt-get install build-essential
   ```

5. Install Conan

   MacOS :

   Install homebrew if missing

   ```sh
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

   ```shell
   brew update
   brew install conan
   ```

   Linux :

   make sure python3 is installed on the system ( if not `sudo apt install python3-pip`)

   ```shell
   sudo pip install conan
   ```

6. Install Cmake (Optional, due to clion bundled a cmake)

   MacOS :

   ```shell
   brew install cmake
   ```

   Linux :

   ```shell
   sudo apt install cmake
   ```

7. Fork and Clone this template from github


   ![image-20210722012344739](https://minio.llycloud.com/image/uPic/image-20210722UQfLJ0.png)

   

   Note : Replace following url by your fork
   https://github.com/AkideLiu/CCCT.git

   

   ![image-20210722012130454](https://minio.llycloud.com/image/uPic/image-20210722GTIbuB.png)

8. Try the sample test file, make sure it runs properly

   ```shell
   example_sub/Test/AVLTree-Test.cpp
   ```

   ![image-20210722012641755](https://minio.llycloud.com/image/uPic/image-20210722zSz72a.png)

Happy Coding : )

## Get Stated a new sub-project

1. create a new directory under `example_sub` 

2. create a test file in the `Test` Folder

3. create your sub_cmake
   ![image-20210722014725344](https://minio.llycloud.com/image/uPic/image-202107228LiAsI.png)

4. Add following configuration

   ```cmake
   include_directories(
           ${CMAKE_CURRENT_SOURCE_DIR}/
   ) # including current .h header (do not modify)
   
   conan_basic_setup() # conan support
   
   add_executable(new_project # your sub-project name
           # add your source file (cpp file only)
           ../Test/new_project_test.cpp
           )
   
   target_link_libraries(new_project # must identical to sub-project name
           ${CONAN_LIBS}
           )
   ```

5. In your **ROOT** Level Cmake file add following configuration

   ```cmake
   add_subdirectory(src/new_project)
   ```

   ![image-20210722015313467](https://minio.llycloud.com/image/uPic/image-20210722pJv7bB.png)

6. Create your Class file

   Select Add to target and select sub project's cmake file

   ![image-20210722015732666](https://minio.llycloud.com/image/uPic/image-202107221K7aZh.png)



## Featured Plugin 

1. **AceJump** ⭐️ -- AceJump allows you to quickly navigate the caret to any position visible in the editor. See a demo of [AceJump in action](https://www.youtube.com/watch?v=8cgy8ITtsJE)! Simply hit "ctrl+;", type a character, then type the matching character to Ace Jump.

   https://plugins.jetbrains.com/plugin/7086-acejump

2. **Atom Material Icons** -- Custom File and IDE Icons for improved visual grepping

   https://plugins.jetbrains.com/plugin/10044-atom-material-icons

3. **BashSupport Pro** -- BashSupport Pro is **a plugin for advanced Bash and shell script development** — debugger, test runner, code completion, find usages, rename, ShellCheck, shfmt, and more.

   https://plugins.jetbrains.com/plugin/13841-bashsupport-pro

4. **C/C++ Single File Execution** -- When you want to build and run single c/cpp file in CLion, `CMakeLists.txt` needs to be configured to declare `add_executable()`. It is troublesome when you want to run many of the files independently within the same project.

   https://plugins.jetbrains.com/plugin/8352-c-c--single-file-execution

5. **CMake Plus** -- Ultimate Cmake support

   https://plugins.jetbrains.com/plugin/12869-cmake-plus

6. **IDE Eval Reset** ⭐️ -- Discover Jetbrains Marketplace Paid Plugins 

   https://zhile.io/2020/11/18/jetbrains-eval-reset-da33a93d.html

7. **Key Promoter X** -- The Key Promoter X helps you to learn essential shortcuts while you are working. 

   https://plugins.jetbrains.com/plugin/9792-key-promoter-x

8. **Material Theme UI** -- Material Theme UI Plugin

   https://plugins.jetbrains.com/plugin/8006-material-theme-ui

9. **Nyan Progress Bar** -- Pretty progress bars with nyan cat for IJ based IDEs.

   https://plugins.jetbrains.com/plugin/8575-nyan-progress-bar

10. **Rainbow Brackets** -- 🌈Rainbow Brackets for IntelliJ based IDEs/Android Studio/HUAWEI DevEco Studio

    https://plugins.jetbrains.com/plugin/10080-rainbow-brackets

11. **Tabnine** ⭐️ -- Tabnine - AI Code Completion

    https://plugins.jetbrains.com/plugin/12798-tabnine-ai-code-completion-js-java-python-ts-rust-go-php--more

    https://www.tabnine.com/students

## Licensed Under GPL-v3

```shell
Authors: Akide Liu

CCCT (Cmake Clion Conan Template)
Copyright (C) <2021>  Akide Liu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```

