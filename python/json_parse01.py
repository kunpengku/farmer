import pymongo

def parse_list(alist):
    for item in alist:
        if isinstance(item, dict):
            parse_dic(item)
        elif isinstance(item, list) :
            list_str = parse_list(item)

def parse_dic(adict):
    for key,val in adict.items():
        if isinstance(val, list) :
            list_str = parse_list(val)
                
        elif isinstance(val, dict) :
            parse_dic(val)

        else:

            if key == 'type' and val == 'text':
                print  adict['value']
                    


if __name__ == '__main__':
    client = pymongo.MongoClient("172.18.4.181", 27017)
    db = client.resource



    result = db.mongo_question_json.find({"question_id":1413040})
    for item in result:
        print item
        all_test = []
        parse_dic(item)
