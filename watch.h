#ifndef _WATCH_H_
#define _WATCH_H_

typedef struct {
    int hour;
    int min;
    int sec;
} Watch;

void init_watch(Watch *);

void get_time(Watch *);
int get_countup(Watch *);

void back_cursol(Watch *, int);
void set_counter(int);
void set_watch(Watch *, int);

#endif  // _WATCH_H_
