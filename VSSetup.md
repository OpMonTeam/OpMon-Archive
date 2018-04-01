My Setup Instructions (using Visual Studio 2017 and Windows 10):

1. Open Visual Studio, then go to File > New > Project from Existing Code...
2. Select Visual C++ from the dropdown and click Next
3. In Project file location, click Browse and then navigate to the directory you cloned the repo into
4. Chose a Project name, whatever you like
5. In the "Add files to the project from these folders" section, REMOVE the folder that is prepopulated there.  We only want to add certain folders.
6. Click Add and then select the src/opmon directory 
7. Click Add and then select the src/utils directory
8. Click Next
9. On the Specify Project Settings screen, don't change anything, and click Next again
10. On the Specify Debug Configuration Settings screen, don't change anything, and click Next again
11. On the Specify Release Configuration Settings screen, don't change anything, and click Finish
12. Go to Project > Retarget Solution and then click OK
13. Follow the instructions in this video to properly include and link SFML: https://www.youtube.com/watch?v=_9yem5dJt2E
	* Note: In one of the final steps, he pastes several dll files.  Note that they should be pasted into your top level repo directory, not next to your main.cpp.
14. Change #include "config.hpp" to #include "../../../config.hpp"
15. Add header #define  _CRT_SECURE_NO_WARNINGS to path.cpp
16. Add "4996" to Debug > Properties > C/C++ > Advanced >"Disable Specific Warning"
17. In Enums.hpp, use VS's Rename functionality to rename #define IN 0 to #define NOT 0 to avoid a conflict with a macro that VS uses.
18. In main.cpp, comment out the WinMain method

(Steps 14-16 adapted from https://github.com/rjphares/OpMon/blob/master/windowsDebugOpMonv0.13.txts)