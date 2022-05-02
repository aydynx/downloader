# downloader

## how to use
### download predefined links
1. add the download links to the array, comma seperated
2. change download location to wherever

### download remote links
1. add your download links to a gist or pastebin (one per line)
2. change remoteLinks to the raw paste

example:  
```cpp
char *links[] = {
    "https://www.7-zip.org/a/7z2107.exe",
    "https://www.rarlab.com/rar/winrar-x32-611.exe",
    "https://the.earth.li/~sgtatham/putty/latest/w32/putty.exe"
};
char *remoteLink = "https://pastebin.com/raw/vx9qPFm9";
char *installFolder = "%temp%\\";
```

no builder, you need to use visual studio  
compile using `cl main.cpp /Os`