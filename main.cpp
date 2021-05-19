#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <windows.h>
#include <iostream>
#include <commdlg.h>
#include <winuser.h>
const wchar_t *GetWC(const char *c)
{
    const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);

    return wc;
}
bool openBox(LPCTSTR lpText,LPCTSTR lpCaption){
    (MessageBox(NULL,lpText,lpCaption,MB_OK)) ? true: false;
}
int WINAPI WinMain(HINSTANCE hinstance,HINSTANCE hph,LPSTR arg,int showcmd)
{
    OPENFILENAME ofn = {0};
    TCHAR szFile[260]={0};
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = GetWC(".JPEG;.JPG;.JFIF;.EXIF;.TIFF;.GIF;.BMP;.PNG;.PPM;.PGM;.PBM;.PNM;.WEBP;.HEIF;.BAT");
    ofn.nFilterIndex = 0;
    ofn.lpstrTitle = GetWC("Choose an image file...");
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if(GetOpenFileName(&ofn))(SystemParametersInfo(SPI_SETDESKWALLPAPER, 0,(PVOID)ofn.lpstrFile, SPIF_UPDATEINIFILE) ? openBox(GetWC("Wallpaper Set"),GetWC("Success")) : openBox(GetWC("Wallpaper Not set"),GetWC("Failure")));
    else{openBox(GetWC("Failed to open the image"),GetWC("Failure"));}
    return 0;
}

