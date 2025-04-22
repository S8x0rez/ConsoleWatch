#include "watch.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

int main(void)
{
    // Œ»İ‚ğæ“¾‚µ‚½‚¢
    Watch watch;
    get_time(&watch);
    
    printf("\n");
    init_watch(&watch);

    int n_countup;

    while (1) {
#ifdef _WIN32
        Sleep(1000);
#elif __linux__
        sleep(3);
#endif
        
        get_time(&watch);
        n_countup = get_countup(&watch);

        set_watch(&watch, n_countup);      
    }

    return 0;
}
