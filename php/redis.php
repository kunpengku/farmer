            $redis = new Redis();
            $redis->connect('10.10.1.1', 6355);
            $redis->select(3);
            $bind_id = $redis->get('rollback');
