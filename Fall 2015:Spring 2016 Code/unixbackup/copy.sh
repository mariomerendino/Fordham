#!/bin/bash
DAY=$(date -d "$D" '+%d')
MONTH=$(date -d "$D" '+%m')
YEAR=$(date -d "$D" '+%Y')
dir=Backup$MONTH.$DAY
echo "Would you like to proceed with the copy?" 
read ans
if [ "Y" == $ans ]; then
	tar -cZf ~/backups/$dir/backup.tar.gz ~/ &> /dev/null
fi
