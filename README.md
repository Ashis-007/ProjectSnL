# ProjectSnL
## A casual game of Snakes n Ladders(with GUI) made in C++

### Things you will need:
* CodeBlocks IDE. You can download it [here](http://www.codeblocks.org/downloads/26).
* graphics.h header file should be included in CodeBlocks. _(Dont't worry. The steps to do so are given below.)_

### How to include graphics.h header file in CodeBlocks?
1. First setup WinBGIm library. Download WinBGIm from (http://winbgim.codecutter.org/). 
2. Extract the downloaded file. There will be three files:
* graphics.h
* winbgim.h
* libbgi.a
3. Copy and paste graphics.h and winbgim.h files into the include folder of compiler directory. (If you have Code::Blocks installed in C drive of your computer, go through: Disk C >> Program Files >> CodeBlocks >> MinGW >> include. Paste these two files there.)
4. Copy and paste libbgi.a to the lib folder (inside MinGW folder) of compiler directory.
5. Open CodeBlocks. Go to Settings >> Compiler >> Linker settings.
6. In that window, click the Add button under the “Link libraries” part, and browse. Select the libbgi.a file copied to the lib folder in step 4.
7. In right part (ie. other linker options) paste the following commands:
    -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
8. Click OK.
9. Open graphics.h file (pasted in include folder in step 3) with Notepad++. Go to line number **302**, and replace that line with this line : **int left=0, int top=0, int right=INT_MAX, int bottom=INT_MAX,**
10. Save the file. Done!

Try running this demo code to see if it is working.

        #include<graphics.h>
        int main()
        {
            initwindow(500, 500);
            outtext("This is working!");
            getch();

            return 0;
        }
        
    



### Some screenshots:

![](https://github.com/Ashis-007/ProjectSnL/blob/master/Screenshots/Capture.JPG "Surprised ?")

***

![](https://github.com/Ashis-007/ProjectSnL/blob/master/Screenshots/Capture2.JPG "Just amazing! Isn't it ?")

***

![](https://github.com/Ashis-007/ProjectSnL/blob/master/Screenshots/Capture3.JPG "Now that's innovation")

***


### This masterpiece is created by none other than
[Subhransu Dash](https://github.com/Ashis-007)

[Sanket KN](https://github.com/SanketKN)


