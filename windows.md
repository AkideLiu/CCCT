## There is a instruction for windows users, based on WSL

1. Setup WSL with Ubuntu 20.04.x LTS

   ```sh
   Distributor ID:	Ubuntu
   Description:	Ubuntu 20.04.2 LTS
   Release:	20.04
   Codename:	focal
   ```

   [https://docs.microsoft.com/en-us/windows/wsl/install-win10](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
   

2. Install missing package on WSL

   ```sh
   sudo apt update
   sudo apt-get -y install build-essential curl unzip tar pkg-config cmake python3-pip gdb
   ```

   ![image-20210806153347987](https://minio.llycloud.com/image/uPic/image-202108063dmcEx.png)

3. Install conan by pip

   ```sh
   sudo pip install conan
   ```

4. Enable WSL Toolchain in Clion and set it as default
   ![image-20210806153550014](https://minio.llycloud.com/image/uPic/image-20210806hfddZp.png)

5. Create a new profile use WSL
   ![image-20210806153630377](https://minio.llycloud.com/image/uPic/image-20210806iMBdfg.png)

6. Run the Sample Test

   ![image-20210806153826475](https://minio.llycloud.com/image/uPic/image-20210806TtKKS0.png)



[Get Started a new Sub-project](/README.md/#get-stated-a-new-sub-project)

 
