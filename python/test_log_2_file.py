# -*- coding: utf-8 -*-
import web
import random
import logging
import logging.handlers
import json
import sys
import MySQLdb
import string
import redis
import yaml
import logging.config

default_encoding = 'utf-8'
if sys.getdefaultencoding() != default_encoding:
    reload(sys)
    sys.setdefaultencoding(default_encoding)

class LogLevelFilter(logging.Filter): 

    def __init__(self, name='', level=logging.DEBUG): 
        super(LogLevelFilter,self).__init__(name) 
        self.level = level 

    def filter(self, record): 
        return record.levelno == self.level 

if __name__ == "__main__":


    # create logger 
    logger = logging.getLogger(__name__) 
    logger.setLevel(logging.DEBUG) 

    log_dir = "/xdfapp/logs/SUBS/"

    fh_info = logging.FileHandler(log_dir+'logging_info.log') 
    fh_info.setLevel(logging.INFO) 

    fh_error = logging.FileHandler(log_dir+'logging_error.log') 
    fh_error.setLevel(logging.DEBUG) 

    filter_info = LogLevelFilter(level=logging.INFO) 
    filter_error = LogLevelFilter(level=logging.ERROR) 

    fh_info.addFilter(filter_info) 
    fh_error.addFilter(filter_error) 

    logger.addHandler(fh_info) 
    logger.addHandler(fh_error) 

    logger.info('for info') 
    logger.error('for error')
