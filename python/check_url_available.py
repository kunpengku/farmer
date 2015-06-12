#eg. domain = 'apkdl.m.baidu-mgame.com'  query = 'game/63000/63040/20150611222339_oem_2000058.apk'

def check_url_available(domain,query):
    try: 
        #增加前置/
        if not query.startswith('/'):
            query = "/" + query
        logger.info('%s%s' % (domain,query) )
        conn = httplib.HTTPConnection(domain)
        conn.request("HEAD",query)
        res = conn.getresponse()
        conn.close()
        if 200 == res.status:
            return True 
        else:
            loggger.info('HTTP CODE %d' % res.status)
            return False
    except Exception as e:
        logger.error('%r' % e)  
        return False
