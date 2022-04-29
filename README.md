# downloader

## how to use
### download predefined links
1. add the download links to the array, comma seperated
2. change download location to wherever

### download remote links
1. add your download links to a gist or pastebin
2. change remoteLinks with the raw paste

example:  
```cpp
char *links[] = {
    "https://launcher.mojang.com/download/MinecraftInstaller.exe",
};
char *installFolder = "%temp%\\";
char *remoteLink = "https://pastebin.com/raw/Jpgu3w8G";
```

no builder, you need visual studio installed to compile this  
compile using `cl main.cpp /Os`