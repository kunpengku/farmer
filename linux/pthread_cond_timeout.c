
#生成pthread_cond_timedwait()中的 tiemout
void maketimeout(struct timespec *tsp, long minutes)
{
    struct timeval now;

    gettimeofday(&now);

    tsp->tv_sec = now.tv_sec;
    tsp->tv_nsec = new.tv_usec * 1000;
    /* add the offset to get timeout value */
    tsp->tv_sec += minutes * 60; 
}
