f = open('column')

content = f.read().split('\n')

content.pop(-1)

content = [ row.strip() for row in content ]

line1 = ','.join(content)


content2 = ["'%%(%s)s'" % row for row in content  ]


line2 = ','.join(content2)

length = len(content2)


content3 = []
for i in range(length):
    if content[i] == 'id':
        continue
    tmp =  "%s =  %s" % (content[i], content2[i])
    content3.append(tmp)

line3 = ','.join(content3)


print content

print line1

print content2

print line2

print line3

sql = "insert into xs_entity_simul_exercise ( %s ) values (%s) on duplicate key update %s" % (line1, line2 ,line3)
print 

print sql 
