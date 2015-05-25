import redis

redis_handle = redis.Redis(host='10.11.0.1', port=6384, db=0)
while True:
  line= redis_handle.lpop('f_pa')
  if not line:
    break
