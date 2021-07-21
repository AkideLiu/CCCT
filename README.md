# Cmake Clion Conan Template

## Author : [Akide Liu](https://github.com/AkideLiu)

### This template integrated Cmake Clion Conan for University of Adelaide C++ direction course educational purpose only

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

   ![image-20210722005302655](https://minio.llycloud.com/image/uPic/image-20210722uzEuBk.png)

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

   ```shell
   brew update
   brew install conan
   ```

   Linux :

   make sure python3 is installed on the system ( if not `sudo apt install python3`)

   ```shell
   pip install conan
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

7. 

