    start='20150922'
    end = '20150923'
    start_st = time.strptime(start,"%Y%m%d")
    start_str = time.strftime("%Y-%m-%d %H:%M:%S",start_st)


    end_st = time.strptime(end,"%Y%m%d")
    end_str = time.strftime("%Y-%m-%d %H:%M:%S",end_st)


    #下面两个时间是，向后移动 delta 天
    s1 = time.mktime(start_st) + 24*3600*delta
    retention_1_str = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(s1))
    s2 = time.mktime(start_st) + 24*3600*(delta+1)
    retention_2_str = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(s2))

    print start_str
    print end_str 
    print  retention_1_str
    print  retention_2_str
