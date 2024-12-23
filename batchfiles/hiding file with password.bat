Quote:
Quote:cls
@ECHO OFF
title Folder Private
if EXIST "hidden folder" goto UNLOCK
if NOT EXIST Private goto MDLOCKER
:CONFIRM
echo Are U Sure U Want To Lock The Folder(Y/N)
set/p"cho=>"
if %cho%==Y goto LOCK
if %cho%==y goto LOCK
if %cho%==N goto END
if %cho%==n goto END
echo Invalid choice.
goto CONFIRM
:LOCK
ren Private "hidden folder"
attrib +h +s "hidden folder"
echo folder locked
goto End
:UNLOCK
echo ENTER password to unlock folder password:mob no
set/p "pass=>"
if NOT %pass%==7353054905 goto FAIL
attrib -h -s "hidden folder"
ren "hidden foldersss"Private
echo Folder Unlocked Successfully
goto END
:FAIL
echo invalid password
goto end
:MDLOCKER
md Private
echo Private created successfully
goto end