REV04 Mon Nov 27 17:02:11 WIB 2017
REV02 Wed Nov 15 14:15:48 WIB 2017
REV01 Tue May  2 10:21:45 WIB 2017
START Mon Nov 21 14:39:48 WIB 2016
==================================

A. disk-images

cd disk-images/

==================================
B. fuse-tutorial

1. UBUNTU's deb packages (privilege): 
   sudo apt-get install autoconf automake build-essential fuse libfuse-dev pkg-config sshfs

2. Get the tarball with
   wget http://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial.tgz

3. List and open the tarball with
   tar tfz fuse-tutorial.tgz
   tar xfz fuse-tutorial.tgz

4. Enter the directory (may be different)
   cd fuse-tutorial-2017-10-03/
   ls -al

5. Read the manual with  
   lynx index.html

6. Run
   ./configure
   make

7  cd example

TO TRY:
$ ls -al rootdir
$ ls -al mountdir
$ df
$ ../src/bbfs rootdir/ mountdir/
$ df
$ ls -al rootdir
$ ls -al mountdir

TO PLAY:
$ cd mountdir
$ touch blah-blah-blah.txt
$ ls -al
$ cd ..
$ ls -al rootdir

TO FINISH:
$ fusermount -u mountdir

EXTRA:
# /etc/fstab: configuration of filesystems
# /etc/mtab -->  /proc/mounts: mounted filesystems
# /proc/swaps: swap filesistems
# df: checking diskspace and filesystems
# GUID (Globally Unique IDentifiers) ls -al /dev/disk/by-uuid


RMS
