if __name__ == '__main__':
    #

    now = datetime.datetime.now()

    for i in range(15):

        print i

        start_st = now - datetime.timedelta(days=i)
        start = time.strftime("%Y%m%d", start_st.timetuple())

        end_st = start_st + datetime.timedelta(days=1)
        end = time.strftime("%Y%m%d", end_st.timetuple())

        print start, end 
