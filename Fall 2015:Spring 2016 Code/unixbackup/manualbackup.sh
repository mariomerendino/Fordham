#!/bin/bash
echo "Welcome to the Manual Backup Tool!"
if [ -d "$HOME/backups" ];then
	echo "Welcome Back!"

else
	echo "It appears that you dont have any backups saved"
	mkdir -p ~/backups
	echo "Whats you're email, so you can recieve the results"
	read email
	echo $email> ~/backups/email.txt
fi
sh ./createdirectory.sh
sh ./copy.sh
DAY=$(date -d "$D" '+%d')
MONTH=$(date -d "$D" '+%m')
backupfile=~/backups/Backup$MONTH.$DAY/backup.tar.gz
value=$(<~/backups/email.txt)
if [ -e "$backupfile" ];then
	echo "Backup Successful!" 
        echo "Backup Successful!" | mailx -s "Backup $MONTH/$DAY" $value
	echo "Would you like to unzip the backup?(Y/N)"
	read ans
	if [ $ans == 'Y' ]; then
		sh ./unzip.sh
	fi
else
	echo "BACKUP FAILED"
        echo "Backup Failed, No backup files were created" | mailx -s "Backup $MONTH/$DAY" $value
fi
