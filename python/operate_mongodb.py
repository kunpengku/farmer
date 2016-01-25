#coding:utf-8

import pymongo



if __name__ == '__main__':
    client = pymongo.MongoClient("12.18.4.1", 27017)
    db = client.resource

    f = open('badid','w')

    print db.name

    all_id=[]
    result = db.mongo_json.find({"question_id":{"$gt" : 1401059}})
    for item in result:
        #print item
        question_id = item['question_id']
        all_id.append(question_id)


    uniq_id = []
    for id in all_id:
        if 1 < all_id.count(id):
            if id: 
                f.write("%s\n" % id) 
