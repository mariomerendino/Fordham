#!/bin/bash

DAY=$(date -d "$D" '+%d')
MONTH=$(date -d "$D" '+%m')
YEAR=$(date -d "$D" '+%Y')
dir=Backup$MONTH.$DAY #Creates a variable named BackupMM.DD
if [ -d "$HOME/backups/$dir" ]; then #if the folder named backupMM.DD exists
	echo "Would you like to overwrite the backup that already exists(Y/N)?"
	read ans #asks user if they want to overwrite the backup that exists
	if [ $ans == 'Y' ]; then
		rm -rf ~/backups/$dir
		mkdir -p ~/backups/$dir
		echo "File Overwritten"
	fi
else
	mkdir -p ~/backups/$dir
fi


