# REV01 Thu Feb 16 15:25:32 WIB 2017
# START Mon Sep  5 15:18:07 WIB 2016
BEGIN           { FS=":" 
                  print ""
                  print "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" }
END             { print "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" }
                { printf " %-20s  %5s  %5s \n", $1,  $3,  $4 }
