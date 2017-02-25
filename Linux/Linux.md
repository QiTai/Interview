# xargs
 + sudo find /tmp -name "*.pyc" | xargs rm -rf


# diff & patch
 + diff A.txt B.txt > AB.patch
 + patch A.txt -i AB.patch -o Anew.txt

# Valgrind
 + valgrind --log-file=filename.debug ./acotsp -i d198.tsp

# Compile C++
 + [Linux GCC常用命令](http://www.cnblogs.com/ggjucheng/archive/2011/12/14/2287738.html)
 + gcc -c main.cpp Node.cpp (其中main.cpp和Node.cpp中含有#include)
 + gcc -o main main.o Node.o
 + ./main

# Compile C++ 11
 + g++ -std=c++0x your_file.cpp -o your_program
 + g++ -std=c++11 your_file.cpp -o your_program

# Tar command
 + tar -jxv -f filename.tar.bz2 -C 欲解压缩的目录
 + tar -jtv -f filename.tar.bz2
 + tar -jcv -f filename.tar.bz2 要被压缩的档案目录
 
# Copy gvim to/from command line
 + 在Vim中，可以使用 "+y 将内容复制到剪贴板，再粘贴到其它程序中;没有指定寄存器时，Vim使用“无名寄存器”存储内容
 + 在command line中，直接复制，在Vim中，用"+p即可粘贴
 
# Linux Software Setup
 + For .bz2 or .gz 
  * tar -jxvf 包名 或 tar -zxvf 包名
  * 配置:  ./configure
  * 编译:  make
  * 安装: make install
  * 卸载:  make uninstall或手动卸载
 + For RPM
  * 直接 rpm -ivh *.rpm即可安装
 + For .bin
  * 直接./文件名.bin
 + For .c 
  * 直接gcc编译

# uninstall software which installed from apt-get install
  + sudo apt-get purge *
  + sudo apt-get uninstall *

# Check Linux version
 + cat /etc/issue

# Check Linux's bit 
 + getconf LONG_BITG

# Check Ubuntu is amd64 or i386
 + uname -a

# Miscellany
 + nautilus --> open "Home" directory in Xwindow.
 

  
