#-*- encoding: gbk -*-  
from HTMLParser import HTMLParser
import urllib
import sys 
import sys 

#sys.setdefaultencoding('utf8')
reload(sys)
sys.setdefaultencoding('GBK')

class parselinks(HTMLParser):
  def __init__(self):
      self.data=[]
      self.href=0

      self.href_value=''
      self.target_value=''

      HTMLParser.__init__(self)
  def handle_starttag(self,tag,attrs):
      if tag =='a':
          for name,value in attrs:
              if name == 'href':
                  self.href=1
                  self.href_value = value
              if name == 'target':
                  self.target_value = value

  def handle_data(self,data):
      pass

  def handle_endtag(self,tag):
      if tag=='a' and self.target_value == '_blank':

          if  self.href_value.find('view') != -1: 
              self.data.append(self.href_value)

          self.href=0
          self.href_value=''
          self.target_value=''
  def getresult(self):
      self.data = set(self.data)
      for value in self.data:
          print value




if __name__=="__main__":
  IParser = parselinks()
  webcontent = urllib.urlopen("http://wenku.baidu.com/o/koolearn?tab=1&od=1&view=0&pay=0&cid=0&pn=1").read()

  IParser.feed(webcontent)
  IParser.getresult()
  IParser.close()
~                                                                                                                                                                                                                                        
~                                                                                                                                                                                                                                        
~                       
