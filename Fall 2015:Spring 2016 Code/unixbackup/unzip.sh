#!/bin/bash
DAY=$(date -d "$D" '+%d')
MONTH=$(date -d "$D" '+%m')
YEAR=$(date -d "$D" '+%Y')
directory=Backup$MONTH.$DAY
tar -xf ~/backups/$directory/backup.tar.gz -C ~/backups/$directory #unzips backup:
