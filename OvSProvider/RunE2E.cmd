@echo off

echo - copying files to %systemdrive%\Eventing\OvS

md %systemdrive%\Eventing\OvS >NUL 2>&1
copy ..\Debug\OvSProvider.exe %systemdrive%\Eventing\OvS
copy OvSProvider.man %systemdrive%\Eventing\OvS
pushd %systemdrive%\Eventing\OvS

echo - Install the provider using Windows commandline tool wevtutil.exe

wevtutil im OvSProvider.man

echo - Start the logging session for OvSProvider.exe using Windows commandline tool logman.exe

rem
logman start -ets OvSProvider -p "Linux Foundation-Open vSwitch-Userspace" 0 0 -o OvSProvider.etl
logman start -ets OvSProvider -p "Linux Foundation-Open vSwitch-Datapath" 0 0 -o OvSProvider.etl
pause 

echo - Execute the provider

OvSProvider.exe

pause

echo - Stop the provider session 

rem
logman stop OvSProvider -ets

pause 

echo - Generate a dumpfile using Windows commandline tool tracerpt.exe

tracerpt -y OvSProvider.etl 

pause

echo - Uninstall the provider

wevtutil um OvSProvider.man

pause

echo - open dumpfile.xml

notepad dumpfile.xml
popd

echo - open event viewer and verify some events for this provider have been logged.
